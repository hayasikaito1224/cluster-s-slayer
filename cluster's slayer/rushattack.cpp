//--------------------------------------------
//�X�L���ǌ��̏���
//�쐬�ҁF��
//--------------------------------------------
#include "rushattack.h"
#include "game.h"
#include "player.h"
#include "model.h"
#include "Renderer.h"
#include "manager.h"
#include "enemy.h"
#include "effect.h"
#include "skill_leveldata.h"
static const int StartTime = 20;
static const int EndTime = 120;
static const float MaxPosY = -10.0f;
static const float MoveSpeed = 20.0f;
static const float MaxScale = 1.0f;
static const float Power = 4.0f;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CRushAttack::CRushAttack(OBJTYPE nPriority): CScene(nPriority)
{
	m_pRushSword = nullptr;
	m_pEnemyData = nullptr;
	m_nStartTimer = 0;
	m_bCanAttackStart = false;
	m_nEndTimer = 0;
	m_scale = { 1.0f,1.0f,1.0f };
	m_State.m_fSizeDiameter = 1.0f;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CRushAttack::~CRushAttack()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CRushAttack::Init(void)
{
	CPlayer *pPlayer = CManager::GetGame()->GetPlayer();
	//���݂̃��x���̃X�e�[�^�X�ɂ���
	m_State = CSkill_LevelData::GetStateRushAttack(pPlayer->GetSkillLevel(CPlayer::RushAttack));
	if (!m_pRushSword)
	{
		m_pRushSword = CModel::Create({0.0f,0.0f,0.0f}, m_rot, 15, CModel::TYPE_PLAYER);
		m_pRushSword->SetScale({ 6.0f*m_State.m_fSizeDiameter,1.8f*m_State.m_fSizeDiameter,2.5f*m_State.m_fSizeDiameter });
	}
	//���̈ʒu�𒲐�
	m_pos.y = -m_pRushSword->GetMaxPos().y*1.8f;
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CRushAttack::Uninit(void)
{
	if (m_pRushSword)
	{
		m_pRushSword->Uninit();
		m_pRushSword = nullptr;
	}
	CScene *pScene_Enemy = CScene::GetScene(CScene::OBJTYPE_ENEMY);
	while (pScene_Enemy != NULL)
	{
		CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
		//���S������擾
		bool bIsDeath = pEnemy->GetDeath();
		//�G�������Ă�����
		if (!bIsDeath)
		{
			pEnemy->SetCanHitRushAttack(true);

		}

		pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
	}

	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CRushAttack::Update(void)
{
	//�������ɉ������ɏo��܂ł̃J�E���g������
	if (!m_bCanAttackStart)
	{
		m_nStartTimer++;
		m_pos.x = m_pEnemyData->GetPos().x;
		m_pos.z = m_pEnemyData->GetPos().z;

		if (m_nStartTimer >= StartTime)
		{
			m_bCanAttackStart = true;
		}
	}
	else
	{

		m_pos.y += MoveSpeed;
		//�����G�ɓ���������
		//�G�Ƃ̓����蔻��
		CScene *pScene_Enemy = CScene::GetScene(CScene::OBJTYPE_ENEMY);
		while (pScene_Enemy != NULL)
		{
			CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
			//���S������擾
			bool bIsDeath = pEnemy->GetDeath();
			bool bLimit = pEnemy->GetNearPlayer();
			//�G�������Ă�����
			if (!bIsDeath&&bLimit)
			{
				D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
				int nSize = pEnemy->GetParts().size();
				if (nSize != 0)
				{
					float fRadius = pEnemy->GetParts(0)->GetMaxPos().x;
					bool bHitAttack = pEnemy->bHitAttack();
					bool bHitRushAttack = pEnemy->GetCanHitRushAttack();
					//�G�ɍU���𓖂Ă���
					if (IsCollision(EnemyPos, fRadius) && bHitRushAttack)
					{
						pEnemy->SetCanHitRushAttack(false);
						pEnemy->AddLifeSkill(-m_State.m_nPower);
						pEnemy->SetGravity(12.0f);
						//�q�b�g�G�t�F�N�g
						std::random_device random;	// �񌈒�I�ȗ���������
						std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
						std::uniform_real_distribution<> randAng(-D3DX_PI, D3DX_PI);
						D3DXVECTOR3 EnemyVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						EnemyVec = EnemyPos - m_pos;			//�G�ƒe�̃x�N�g��
						D3DXVECTOR3 EnemyPosBody = {};
						D3DXVECTOR3 EnemyPosHead = {};
						if (pEnemy->GetParts(0) != nullptr)
						{
							EnemyPosBody = pEnemy->GetParts(0)->GetMaxPos();
							EnemyPosHead = pEnemy->GetParts(1)->GetMaxPos();
						}
						float fEnemyAng = atan2(EnemyVec.x, EnemyVec.z) + D3DX_PI;
						D3DXVECTOR3 Addmove = D3DXVECTOR3(
							sinf(fEnemyAng)*EnemyPosBody.x,
							EnemyPosHead.y / 2.0f,
							cosf(fEnemyAng)*EnemyPosBody.x);

						float fAng = randAng(mt);

						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 1.0f,1.0f,0.0f },
						{ 1.0,1.0,1.0,0.5f }, false, 0.0f, 0.01f, true, CTexture::HitEffect, fAng, true);
						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 0.4f,0.2f,0.0f },
						{ 1.0,1.0,1.0,0.7f }, false, 0.0f, 0.015f, true, CTexture::HitEffect, fAng, true);

						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 1.5f,1.0f,0.0f },
						{ 1.0f,0.5f,0.0f,1.0f }, false, 0.0f, 0.03f, true, CTexture::Effect, fAng, false, true);
						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 1.5f,1.0f,0.0f },
						{ 1.0f,0.5f,0.0f,1.0f }, false, 0.0f, 0.03f, true, CTexture::Effect, fAng, false, true);
						break;
					}

				}

			}

			pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
		}


		m_nEndTimer++;
		if (m_nEndTimer >= EndTime)
		{
			m_nEndTimer = 0;
			m_bIsDeath = true;

		}

	}

	//�������肪�I���Ȃ�
	if (m_bIsDeath)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CRushAttack::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	D3DXMATRIX mtxRotModel, mtxTransModel, mtxScaleModel;//�v�Z�p�}�g���b�N�X

										  //�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�傫����ݒ�
	D3DXMatrixScaling(&mtxScaleModel, m_scale.x*MaxScale, m_scale.y*MaxScale, m_scale.z*MaxScale);
	//�傫���𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScaleModel);

	//������ݒ�
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//�����𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);

	//�ʒu��ݒ�
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	//�ʒu�𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	if (m_pRushSword)
	{
		m_pRushSword->Draw();
	}

}

void CRushAttack::UpperAttack()
{

}

CRushAttack * CRushAttack::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CEnemy *pEnemy)
{
	CRushAttack *pRushAttack = NULL;
	pRushAttack = new CRushAttack(OBJTYPE_MODEL);
	pRushAttack->m_pos = pos;
	pRushAttack->m_rot = rot;
	pRushAttack->m_pEnemyData = pEnemy;
	pRushAttack->Init();

	return pRushAttack;
}
//----------------------------------------------
//�����蔻��
//----------------------------------------------
bool CRushAttack::IsCollision(const D3DXVECTOR3 & Hitpos, const float & fRadius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	vec = m_pos - Hitpos;
	float fLength = 0.0f;
	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	float fHitSize = (m_pRushSword->GetMaxPos().x*6.0f)*m_State.m_fSizeDiameter;
	float fCollisionRadius = fHitSize + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}
