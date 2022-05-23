//=============================================================================
//
//�A�^�b�N�X�L��missile�̏���
//
//=============================================================================
#include "missile.h"
#include "manager.h"
#include "Renderer.h"
#include "scene.h"
#include "model.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "missile_bullet.h"
static const float SearchRange = 100.0f;
static const float IntervalTime = 100.0f;
static const float IntervalShotTime = 20.0f;
static const float MissileSize = 50.0f;

static const int SearchMax = 5;
static const int MissilePower = 5;

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CMissile::CMissile(OBJTYPE nPriority) :CScene(nPriority)
{
	m_bDraw = true;
	m_fIntervalTimer = 0.0f;
	m_SearchRange = SearchRange;
	m_nCntSearch = 0;
	m_nCntSearchMax = SearchMax;
	m_bCanSearch = true;
	m_bCanShotMissile = false;

}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CMissile::~CMissile()
{

}

//=============================================================================
//������
//=============================================================================
HRESULT CMissile::Init()
{
	//���I�m��
	m_pEnemyPos = new D3DXVECTOR3[m_nCntSearchMax];
	return S_OK;

}

//=============================================================================
//�I��
//=============================================================================
void CMissile::Uninit()
{
	Release();
}

//=============================================================================
//�X�V
//=============================================================================
void CMissile::Update()
{
	if (m_bCanSearch)
	{
		//�G�Ƃ̓����蔻��
		CScene *pScene_Enemy = CScene::GetScene(CScene::OBJTYPE_ENEMY);
		while (pScene_Enemy != NULL)
		{
			if (pScene_Enemy != NULL)
			{
				CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
				D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
				int nSize = pEnemy->GetParts().size();
				if (nSize != 0&& pEnemy->GetParts(0))
				{
					//�����蔻��
					float fRadius = pEnemy->GetParts(0)->GetMaxPos().x;
					//�T�[�`�񐔂����E�ɗ���܂œG���T�[�`����
					if (m_nCntSearch < m_nCntSearchMax)
					{
						SearchEnemy(EnemyPos, fRadius);
					}
				}

			}
			pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
		}

	}
	else if(!m_bCanSearch && !m_bCanShotMissile)
	{
		m_fIntervalTimer += 1.0f;
		if (m_fIntervalTimer >= IntervalTime)
		{
			m_fIntervalTimer = 0.0f;
			m_bCanShotMissile = true;
			m_nCntSearch = 0;
		}
	}
	if (m_nCntSearch >= m_nCntSearchMax)
	{
		m_bCanSearch = false;
	}
	if (m_bCanShotMissile)
	{
		m_fIntervalTimer += 1.0f;
		if (m_fIntervalTimer >= IntervalShotTime)
		{
			m_fIntervalTimer = 0.0f;
			//�~�T�C���𔭎�
			CMissile_Bullet::Create({ m_pEnemyPos[m_nCntSearch].x,200.0f,m_pEnemyPos[m_nCntSearch].z}, MissileSize, MissilePower);
			//���̓G�̈ʒu�Ɉڂ�
			m_nCntSearch++;
		}
		if (m_nCntSearch >= m_nCntSearchMax)
		{
			m_bUninit = true;
		}
	}
	if (m_bUninit)
	{
		Uninit();
	}
}

//=============================================================================
//�`��
//=============================================================================
void CMissile::Draw()
{
}
////=============================================================================
//�~�T�C������
//=============================================================================
void CMissile::LaunchMissile()
{
	
}
////=============================================================================
//�v���C���[�ɋ߂��G��T��
//=============================================================================
void CMissile::SearchEnemy(const D3DXVECTOR3 EnemyPos, const float fRadius)
{
	CPlayer *pPlayer = CManager::GetGame()->GetPlayer();

	D3DXVECTOR3 PlayerVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	PlayerVec = EnemyPos - pPlayer->GetPos();			//�G�ƒe�̃x�N�g��
	float fLength = sqrtf((PlayerVec.z*PlayerVec.z) + (PlayerVec.x*PlayerVec.x));
	if (fLength <= m_SearchRange + fRadius)
	{
		//�G�̈ʒu��ۑ�
		m_pEnemyPos[m_nCntSearch] = EnemyPos;
		m_nCntSearch++;
	}
	else
	{
		//�q�b�g�G�t�F�N�g
		std::random_device random;	// �񌈒�I�ȗ���������
		std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
		std::uniform_real_distribution<> randAng(-D3DX_PI, D3DX_PI);

		m_pEnemyPos[m_nCntSearch] = { cosf(randAng(mt))* SearchRange ,0.0f,sinf(randAng(mt))* SearchRange };
		m_nCntSearch++;
	}
}
//=============================================================================
//�N���G�C�g
//=============================================================================
CMissile * CMissile::Create()
{
	CMissile *pMissile = new CMissile;
	if (pMissile)
	{
		pMissile->Init();
	}

	return pMissile;
}

