//-----------------------------
//�G�̏���
//-----------------------------
#include "enemy001.h"
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

static const float AttackStartNear = 150.0f;//�U�����n�߂�܂ł̃v���C���[�Ƃ̋߂�
static const float AttackStartTime = 20.0f;//�U���J�n�܂ł̎���
static const int Power = 20;//�U����
static const int Life = 20;//�̗�
static const float MoveSpeed = 1.0f;//�ړ����x

CEnemy001::CEnemy001(OBJTYPE nPriority) : CEnemy(nPriority)
{
	m_nPower = Power;
	m_fHitPoint = (float)Life;
	m_fMoveSpeed = MoveSpeed;
}

CEnemy001::~CEnemy001()
{

}
//----------------------------------
//�C���X�^���X����
//----------------------------------
CEnemy001 *CEnemy001::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CEnemy001 *pEnemy = NULL;
	pEnemy = new CEnemy001(OBJTYPE_ENEMY);
	pEnemy->m_pos = pos;
	pEnemy->m_rot = rot;
	pEnemy->Init();
	return pEnemy;
}
//----------------------------------
//������
//----------------------------------
HRESULT CEnemy001::Init()
{
	CEnemy::Init();
	m_nType = NONE;
	//�t�@�C���ǂݍ���
	CLayer_Structure *pLayer = NULL;
	pLayer = new CLayer_Structure;
	pLayer->SetLayer_Structure("data/TEXT/EnemyParts000.txt", m_pParts, CModel::TYPE_ENEMY);
	CModel *pmodel = new CModel;
	if (m_pParts[0])
	{
		m_fRadius = m_pParts[0]->GetMaxPos().x;
	}

	if (!m_pMotion)
	{
		m_pMotion = new CMotion;
		m_MotionType = 0;
		m_pMotion->MotionLoad("data/TEXT/poyo_motion.txt");
	}

	return S_OK;
}
//----------------------------------
//�I��
//----------------------------------
void CEnemy001::Uninit()
{
	CEnemy::Uninit();
	Release();
}
//-----------------------------------------
//�X�V
//-----------------------------------------
void CEnemy001::Update()
{
	CEnemy::Update();
}
//-----------------------------------------
//�`��
//-----------------------------------------
void CEnemy001::Draw()
{
	CEnemy::Draw();
}

//-----------------------------------------
//�U������
//-----------------------------------------
void CEnemy001::AIAttack()
{
	//�v���C���[���U���͈͂ɓ�������
	if (m_fPlayerVecLength < AttackStartNear)
	{
		if (m_bAttack == false)
		{
			m_nAttackStartCnt++;
			//�U���J�n���ԂɂȂ�����
			if (m_nAttackStartCnt >= AttackStartTime)
			{
				m_nAttackStartCnt = 0;
				m_MotionType = ATTACK;
				m_bAttack = true;
				//�U����
				CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_SWORD_ATTACK);
				CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_SWORD_ATTACK, 0.7f);

			}

		}
	}
	else
	{
		m_nAttackStartCnt = 0;

	}

}
//-----------------------------------------
//�ړ�����
//-----------------------------------------
void CEnemy001::AIMove()
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
		m_MoveSpeed.x = sinf(m_fAng)*MoveSpeed;
		m_MoveSpeed.z = cosf(m_fAng)*MoveSpeed;
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
void CEnemy001::AddLife(int nLife)
{
	if (m_bDamage == true && m_bHitCollision == true)
	{
		int nDamege = nLife + m_nDefense;
		m_fHitPoint += nDamege;

	}
}

void CEnemy001::AddLife(int nPower, int nType)
{
	if (m_bDamage == true)
	{
		float fDamege = 0;
		switch (nType)
		{
		case FIRE:
			fDamege = (nPower + m_nDefense)*1.5f;

			break;
		case BULLIZAD:
			fDamege = nPower + m_nDefense;

			break;
		}
		m_fHitPoint += fDamege;

	}

}
