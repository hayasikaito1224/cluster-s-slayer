//-----------------------------
//�G�̏���
//-----------------------------
#include "Enemy.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "layer_structure.h"
#include "game.h"
#include "player.h"
#include "collision.h"
#include "stage.h"
#include "sound.h"
#include "effect.h"
#include "gauge.h"
#include "Particle.h"
#include "wall.h"
#include "map_polygon.h"
#include "shadow.h"
#include "motion.h"
#include "smallscore.h"
#define MIN_MOVE (80.0)		//�G�������ŏ��͈̔�
#define MAX_MOVE (100.0)	//�G�������ő�͈̔�
#define MIN_TIME (180.0)		//�G�������܂ł̎��Ԃ̍ŏ��͈̔�
#define MAX_TIME (240.0)	//�G�������܂ł̎��Ԃ̍ő�͈̔�
#define MAX_SPEED (1.8)
#define KNOCK_BACK_SPEED (3.0)
#define MAX_HIT_TIME (30)//�G�̖��G����
#define MAX_ENEMY_LIFE (10)//�G�̖�
#define MAX_ENEMY_DEFENSE (2)//�G�̖h���
#define MAX_ATTACKSTARTTIME (20)//�U���J�n�܂ł̎���
#define ADDCP (10)		//���G����̎���
static const float GravitySpeed = 5.0f;
CEnemy::CEnemy(OBJTYPE nPriority) : CCharacter(nPriority)
{
	m_bAIMove = false;
	m_bAIMoveStop = false;
	s_bCntStop = true;
	m_bHit = false;
	m_bInvincible = false;
	m_pMotion = nullptr;
	m_nAttackStartCnt = MAX_ATTACKSTARTTIME;
	m_bMotionStop = false;
	m_bMove = false;
	m_bHitCollision = true;
	m_bHitRushAttack = false;
	m_pShadow = nullptr;
	m_bCanHitRushAttack = true;
	m_fGravity = 0.0f;
}

CEnemy::~CEnemy()
{

}
//----------------------------------
//�C���X�^���X����
//----------------------------------
CEnemy *CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CEnemy *pEnemy = NULL;
	pEnemy = new CEnemy(OBJTYPE_ENEMY);
	pEnemy->m_pos = pos;
	pEnemy->m_rot = rot;
	pEnemy->Init();
	return pEnemy;
}
//----------------------------------
//������
//----------------------------------
HRESULT CEnemy::Init()
{
	m_nDefense = MAX_ENEMY_DEFENSE;
	m_fWalkSoundInterval = 0.0f;
	m_fSoundInterval = 0.0f;
	m_bDamage = false;

	std::mt19937_64 s_mt(s_random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
	std::uniform_real_distribution<> s_randAng(-3.14, 3.14);
	std::uniform_real_distribution<> s_randMove(MIN_MOVE, MAX_MOVE);
	std::uniform_real_distribution<> s_randTime(MIN_TIME, MAX_TIME);


	s_MaxTimer = (float)s_randTime(s_mt);
	m_fMovingRange = (float)s_randMove(s_mt);
	m_rot.y = (float)s_randAng(s_mt)+(D3DX_PI);
	s_MoveRandAng = (float)s_randAng(s_mt);
	if (!m_pShadow)
	{
		m_pShadow = CShadow::Create({ 0.0f,0.0f,0.0f }, 50.0f, CTexture::Effect);
	}

	return S_OK;
}
//----------------------------------
//�I��
//----------------------------------
void CEnemy::Uninit()
{
	CCharacter::Uninit();

	Release();
}
//-----------------------------------------
//�X�V
//-----------------------------------------
void CEnemy::Update()
{

	//�G��AI�ړ�
	//����ł��Ȃ�������s������
	if (m_fHitPoint <= 0)
	{
		m_IsDeath = true;
		m_MotionType = DETH;
	}
	if (m_IsDeath == false)
	{
		AIBehavior();
		if(m_pShadow != nullptr)
		{
			int nSize = m_pParts.size();
			if (nSize != 0)
			{
				m_pShadow->SetPos(0.0f, 0.0f, { m_pParts[0]->GetMaxPos().x ,0.0,m_pParts[0]->GetMaxPos().z });
				m_pShadow->SetPos(m_pos);

			}

		}
		//�d�͂Ɋւ��鏈��
		m_fGravity--;
		m_pos.y -= m_fGravity;

		if(m_pos.y <= 0.0f)
		{
			m_pos.y = 0.0f;
		}
		if (m_bDraw == true)
		{
			CCollision *pCollision = new CCollision;
			//�_���[�W���󂯂��疳�G��Ԃɂ���
			if (m_bDamage == true)
			{
				if (m_bEffect == false)
				{
					m_bEffect = true;
				}
				//�J�E���^�[�𑝂₷
				m_nTimer++;
			}
			//�J�E���^�[������̎��Ԃɍs������
			if (m_nTimer >= INVINCIBLE_TIME)
			{
				//�ʏ��Ԃɖ߂�
				m_bDamage = false;
				m_bEffect = false;
			}
			CPlayer *pPlayer = CManager::GetGame()->GetPlayer();

			////�v���C���[�ɑ΂��Ă̓����蔻��
			if (pPlayer)
			{
				float fRadius = pPlayer->GetParts(0)->GetMaxPos().x*3.0f;
				IsCollision(&m_pos, pPlayer->GetPos(), fRadius, 5.0f);

			}
			//�m�b�N�o�b�N��ԂȂ�
			if (m_bKnockback == true)
			{
				Knockback(pPlayer->GetPos());
			}

			CScene *pScene_Enemy = CScene::GetScene(OBJTYPE_ENEMY);

			CScene *pScene_Wall = CScene::GetScene(OBJTYPE_WALL);
			//�ǂƂ̓����蔻��
			while (pScene_Wall != nullptr)
			{
				CWall *pWall = (CWall*)pScene_Wall;
				CScene *pNext_Wall = CScene::GetSceneNext(pScene_Wall);
				//�����蔻��
				bool bHit = pWall->TestCollision(&m_pos, &m_lastPos, m_pParts[0]->GetMaxPos().x);
				pScene_Wall = pNext_Wall;

			}

			////�G���m�̓����蔻��
			while (pScene_Enemy != NULL)
			{
				if (pScene_Enemy != NULL && pScene_Enemy != this)
				{
					CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
					bool bIsDeath = pEnemy->GetDeath();
					if (!bIsDeath)
					{
						D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
						int nSize = pEnemy->GetParts().size();
						if (nSize != 0)
						{
							float fRadius = pEnemy->GetParts(0)->GetMaxPos().x;
							if (IsCollision(&m_pos, EnemyPos, fRadius, m_fMoveSpeed*2.0f))
							{
								break;
							}

						}

					}
				}
				pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
			}

			//���[�V�����Đ�
			if (m_pMotion != NULL)
			{
				int nSize = m_pParts.size();
				if (nSize != 0)
				{
					m_pMotion->PlayMotion(m_pParts.size(), &m_pParts[0], m_MotionType, m_MotionLastType, m_bMotionStop, m_bAttack, m_bNeutral, false);
				}
			}

			delete pCollision;
		}

	}
	else
	{
		//���[�V�����Đ�
		if (m_pMotion != NULL)
		{
			m_pMotion->NoLoopPlayMotion(m_pParts.size(), &m_pParts[0], m_MotionType, m_MotionLastType, m_bMotionStop);
		}
		if (m_bMotionStop == true)
		{
			m_IsDeath = true;
			//�����鉹
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENEMY_DEATH);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENEMY_DEATH,0.5f);
			CManager::GetGame()->GetParticle()->PlayRandomCircle({ m_pos.x,m_pos.y + 30.0f,m_pos.z }, CParticle::HEELEFFECT, CTexture::GlitterEffect);
		}
		//�G�̍s���p�^�[�������\��
		if (m_IsDeath == true)
		{
			Uninit();
		}
	}

}
//-----------------------------------------
//�`��
//-----------------------------------------
void CEnemy::Draw()
{

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X
	//�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//�����𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	{
		int nSize = m_pParts.size();
		//���f���`��
		for (int nCnt = 0; nCnt < nSize; nCnt++)
		{
			if (m_pParts[nCnt] != nullptr)
			{
				m_pParts[nCnt]->SetDraw(m_bDraw);
				m_pParts[nCnt]->Draw();
			}
		}
	}
	//�O��̈ʒu���̕ۑ�
	m_lastPos = m_pos;

}
void CEnemy::Colision()
{
}
void CEnemy::AIAttack()
{
}
//-----------------------------------------
//�ړ�����
//-----------------------------------------
void CEnemy::AIMove()
{
	if (m_fPlayerVecLength < MAX_COLRADIUS)
	{
		m_bMove = true;
		//�����œ����ł������I�t�ɂ���
		m_bAIMove = false;
		m_bAIMoveStop = true;

	}
	//�͈͊O�̎�
	else
	{
		m_bMove = false;
		m_bAIMoveStop = false;

		s_bCntStop = true;
	}
	//�����ړ����ł���Ȃ�
	if (m_bMove)
	{
		m_rot.y = m_fAng + (D3DX_PI);
		//���˂�����������߂�
		m_MoveSpeed.x = sinf(m_fAng)*MAX_SPEED;
		m_MoveSpeed.z = cosf(m_fAng)*MAX_SPEED;
		m_MotionType = MOVE;

		m_fWalkSoundInterval -= 0.1f;

		if (m_fWalkSoundInterval <= 0.0f)
		{
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENEMYWALK);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENEMYWALK, 0.6f);
			m_fWalkSoundInterval = 2.3f;
		}
		m_pos += m_MoveSpeed;

	}
	else
	{
		m_MotionType = NEUTRAL;
		m_MoveSpeed.x = 0.0f;
		m_MoveSpeed.y = 0.0f;
		m_MoveSpeed.z = 0.0f;
	}

}
//----------------------------------------------------------
//�̗͂̑���
//----------------------------------------------------------
void CEnemy::AddLife(int nLife)
{
	if (m_bDamage == true && m_bHitCollision == true)
	{
		int nDamege = nLife+ m_nDefense;
		m_fHitPoint += nDamege;

	}
}
//----------------------------------------------------------
//�u���b�N�z�[���Ɉ����񂹂��鏈��
//----------------------------------------------------------
void CEnemy::HoleAlign(D3DXVECTOR3 holePos, float fHitSize, float AlignSpeed)
{
	D3DXVECTOR3 vec = m_pos - holePos;
	float Length = sqrtf(vec.x*vec.x + vec.z*vec.z);
	float Size = fHitSize + m_fRadius;
	float moveRot = atan2f(vec.x, vec.z);
	if (Length <= Size)
	{
		m_pos.x -= sinf(moveRot)*AlignSpeed;
		m_pos.z -= cosf(moveRot)*AlignSpeed;
	}
}
//----------------------------------------------------------
//�̗͂̑���
//----------------------------------------------------------
void CEnemy::AddLifeSkill(int nLife)
{
	int nDamege = nLife + m_nDefense;
	m_fHitPoint += nDamege;
	int nDrawDamage = abs(nDamege);
	CSmallScore::Create({ m_pos.x,m_pos.y + 30.0f,m_pos.z }, { 10.0f,20.0f,0.0f }, nDrawDamage);

}
//----------------------------------------------------------
//�̗͂̑���
//----------------------------------------------------------
void CEnemy::AddLife(int nPower, int nType)
{
	if (m_bDamage)
	{
		float fDamege = 0;
		//�_���[�W�������߂�
		fDamege = nPower + m_nDefense;

		m_fHitPoint += fDamege;

	}

}

//-----------------------------------------
//���G���Ԃ̏���
//-----------------------------------------
bool CEnemy::bHitAttack()
{
	//�q�b�g���ꂽ�疳�G���ԗp�̔�����I���ɂ���
	if (m_bHit == true)
	{
		m_bInvincible = true;
		m_bHit = false;
		//�m�b�N�o�b�N��Ԃɂ���
		m_bKnockback = true;
	}
	//�q�b�g���Ă�����U��������Ȃ��悤�ɂ���
	if (m_bInvincible == true)
	{
		m_MotionType = DETH;
		m_bAttack = false;
		m_nCntHitInterval++;
		if (m_nCntHitInterval >= MAX_HIT_TIME)
		{
			m_nCntHitInterval = 0;

			m_bInvincible = false;
			m_bKnockback = false;


		}
	}
	return m_bInvincible;
}
//-----------------------------------------
//�m�b�N�o�b�N�̏���
//-----------------------------------------
void CEnemy::Knockback(D3DXVECTOR3& Playerpos)
{
	D3DXVECTOR3 PlayerVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	PlayerVec = Playerpos - m_pos;			//�G�ƒe�̃x�N�g��
	m_fAng = atan2(PlayerVec.x, PlayerVec.z);//�G�̌���
	//�����o�����������߂�
	float fSpeed_x = sinf(m_fAng)*KNOCK_BACK_SPEED;
	float fSpeed_z = cosf(m_fAng)*KNOCK_BACK_SPEED;
	//�v���C���[�𓮂���
	m_pos.x -= fSpeed_x;
	m_pos.z -= fSpeed_z;

}


//-----------------------------------------
//�GAI�̋����̏���
//-----------------------------------------
void CEnemy::AIBehavior()
{
	D3DXVECTOR3	pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pos = CManager::GetGame()->GetPlayer()->GetPos();				//�ʒu
	D3DXVECTOR3 PlayerVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	PlayerVec = pos - m_pos;			//�G�ƒe�̃x�N�g��
	float fLengthX = 0.0f;
	m_fPlayerVecLength = sqrtf((PlayerVec.z*PlayerVec.z) + (PlayerVec.x*PlayerVec.x));
	m_fAng = atan2(PlayerVec.x, PlayerVec.z);//�G�̌���
	float fAngle = atan2(PlayerVec.x, PlayerVec.z);//�G�̌���
	//�G�̏o��
	if (m_fPlayerVecLength < MAX_DRAWRADIUS)
	{
		m_bDraw = true;
	}
	else
	{
		m_bDraw = false;
	}

	//�G�̒Ǐ]
	if (!m_bAttack)
	{
		AIMove();
	}
	//�v���C���[���U���͈͂ɓ�������
	AIAttack();

	if (!m_bAIMoveStop&& m_bDraw)
	{
		//�G�������œ������Ԃ�������
		if (m_bAIMove)
		{
			m_MotionType = MOVE;

			//�ǂ��܂œ������J�E���g����
			s_MovingCnt += MAX_SPEED;
			m_rot.y = s_MoveRandAng + (D3DX_PI);

			//�����o�����������߂�
			m_MoveSpeed.x = sinf(s_MoveRandAng)*MAX_SPEED;
			m_MoveSpeed.z = cosf(s_MoveRandAng)*MAX_SPEED;
			m_pos += m_MoveSpeed;

		}
		else
		{
			s_CntTimer += 1.0f;
			//�J�E���^�[���w��͈̔͂܂ŃJ�E���g���ꂽ��G������
			if (s_CntTimer >= s_MaxTimer&&s_bCntStop)
			{
				s_CntTimer = 0.0f;
				//�G�������œ������߂̔�����I���ɂ���
				m_bAIMove = true;

				static std::random_device s_random;	// �񌈒�I�ȗ���������
				std::mt19937_64 s_mt(s_random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
				std::uniform_real_distribution<> s_randMove(MIN_MOVE, MAX_MOVE);

				m_fMovingRange = (float)s_randMove(s_mt);
				//������ݒ�
				m_rot.y = s_MoveRandAng + (D3DX_PI);
				s_bCntStop = false;
			}

			s_MovingCnt = 0.0f;
			m_MoveSpeed.x = 0.0f;
			m_MoveSpeed.z = 0.0f;

		}
		//�ړ�����w��͈̔͂ɗ�����r
		if (s_MovingCnt > m_fMovingRange)
		{
			static std::random_device s_random;	// �񌈒�I�ȗ���������

			std::mt19937_64 s_mt(s_random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
			std::uniform_real_distribution<> s_randAng(-3.14, 3.14);
			std::uniform_real_distribution<> s_randTime(MIN_TIME, MAX_TIME);

			s_MoveRandAng = (float)s_randAng(s_mt);
			s_MaxTimer = (float)s_randTime(s_mt);
			m_fMovingRange = 0.0f;
			s_MovingCnt = 0.0f;
			//�J�E���g���O�ɂ��Ă܂������n�߂�
			s_bCntStop = true;
			s_CntTimer = 0.0f;
			m_MoveSpeed.x = 0.0f;
			m_MoveSpeed.z = 0.0f;
			m_bAIMove = false;
		}

	}
	//�G������ɓ�������

}
