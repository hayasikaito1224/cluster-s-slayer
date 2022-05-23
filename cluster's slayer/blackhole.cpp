//-------------------------------------------
//�u���b�N�z�[���̏���
//------------------------------------------
#include "blackhole.h"
#include "manager.h"
#include "Renderer.h"
#include "Particle.h"
#include "enemy.h"
#include "PresetSetEffect.h"
static const float MoveSpeedMax = 4.0f;
static const float MoveSpeedMin = 2.0f;
static const float HoleSpeed = 1.5f;
static const float HoleArea = 200.0f;
static const int DeleteTime = 200;
static const int HoleExpansionTime = 60;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CBlackHole::CBlackHole(OBJTYPE nPriority):CScene(nPriority)
{
	m_bHoleExpansion = false;
}

//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CBlackHole::~CBlackHole()
{
}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CBlackHole::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CBlackHole::Uninit(void)
{

	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CBlackHole::Update(void)
{
	m_nDeleteTimer++;
	if (m_pEnemyData)
	{
		bool bDeath = m_pEnemyData->GetDeath();
		if (bDeath)
		{
			m_pEnemyData = nullptr;
		}
	}
	if (m_nDeleteTimer >= HoleExpansionTime && !m_bHoleExpansion)
	{
		m_nDeleteTimer = 0;
		m_bHoleExpansion = true;
		CPresetEffect::SetEffect3D(0, m_pos, {}, {});
	}
	else if (m_nDeleteTimer >= DeleteTime && m_bHoleExpansion)
	{
		m_bUninit = true;
	}

	if (m_bHoleExpansion)
	{
		Suction();
	}
	else
	{
		//�W�J�O�̃u���b�N�z�[���̈ړ�
		Head();
	}

	if (m_bUninit)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CBlackHole::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^


	D3DXMATRIX mtxRotModel, mtxTransModel, mtxScaleModel;//�v�Z�p�}�g���b�N�X

														 //�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);


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
}

void CBlackHole::Suction()
{
	//�G�Ƃ̓����蔻��
	CScene *pScene_Enemy = CScene::GetScene(OBJTYPE_ENEMY);
	while (pScene_Enemy != NULL)
	{
		if (pScene_Enemy != NULL)
		{
			CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
			D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
			int nSize = pEnemy->GetParts().size();
			if (nSize != 0)
			{
				pEnemy->HoleAlign(m_pos, HoleArea, HoleSpeed);
			}

		}
		pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
	}

}
//--------------------------------------------
//�u���b�N�z�[�����G�Ɍ���������
//--------------------------------------------
void CBlackHole::Head()
{
	if (m_pEnemyData)
	{
		int nSize = m_pEnemyData->GetParts().size();
		if (nSize != 0)
		{
			D3DXVECTOR3 enemypos = m_pEnemyData->GetPos();
			D3DXVECTOR3 vec = m_pos - enemypos;
			float moveRot = atan2f(vec.x, vec.z);

			m_pos.x += cosf(-moveRot)*m_fMoveSpeed;
			m_pos.z += sinf(-moveRot)*m_fMoveSpeed;
			CParticle *pParticle = new CParticle;
			pParticle->RandomCircleParticle(m_pos, { 1.0,1.0,1.0,1.0 }, false);

		}

	}


}

//--------------------------------------------
//�`��
//--------------------------------------------
CBlackHole * CBlackHole::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CEnemy *pEnemy)
{
	CBlackHole *pRushAttack = NULL;
	pRushAttack = new CBlackHole(OBJTYPE_EFFECT);
	pRushAttack->m_pos = pos;
	pRushAttack->m_pos.y = 30.0f;
	std::random_device random;	// �񌈒�I�ȗ���������

	std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
	std::uniform_real_distribution<> randpeed(MoveSpeedMin, MoveSpeedMax);
	pRushAttack->m_fMoveSpeed = randpeed(mt);
	pRushAttack->m_rot = rot;
	pRushAttack->m_pEnemyData = pEnemy;
	pRushAttack->Init();

	return pRushAttack;
}