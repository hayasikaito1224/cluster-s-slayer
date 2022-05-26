//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#include "enemy_spawn_manager.h"
#include "enemy001.h"
#include "manager.h"
static const int SpawnTime = 600;
static const float SpawnLengthMax = 1000.0f;
static const float SpawnLengthMin = 50.0f;

static const int SpawnMax = 20;
static const int SpawnLimit = 300;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CEnemySpawnManager::CEnemySpawnManager(OBJTYPE nPriority):CScene(nPriority)
{
	m_nSpawnTime = SpawnTime;
	m_nSpawnCnt = SpawnTime;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CEnemySpawnManager::~CEnemySpawnManager()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CEnemySpawnManager::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CEnemySpawnManager::Uninit(void)
{
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CEnemySpawnManager::Update(void)
{
	//�X�|�[������܂ł̎��Ԃ��J�E���g
	bool bPause = CManager::GetPause();
	if (!bPause)
	{
		m_nSpawnCnt++;
		int nMaxEnemy = CEnemy::GetMaxEnemy();
		if (m_nSpawnCnt >= m_nSpawnTime && nMaxEnemy <= SpawnLimit)
		{

			//�ő�l�s���܂œG�𐶐�
			for (int nCnt = 0; nCnt < SpawnMax; nCnt++)
			{
				static std::random_device random;	// �񌈒�I�ȗ���������
				std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
				std::uniform_real_distribution<> randAng(0.0f, D3DX_PI);
				std::uniform_real_distribution<> randAng2(0.0f, D3DX_PI);
				std::uniform_real_distribution<> randLength(SpawnLengthMin, SpawnLengthMax);
				float fAng = randAng(mt) - randAng2(mt);
				float fLength = randLength(mt);
				//�X�|�[���n�_���v�Z
				D3DXVECTOR3 SpawnPos =
				{ sinf(fAng)*fLength ,0.0f,cosf(fAng)*fLength };
				CEnemy001::Create(m_pos + SpawnPos, { 0.0f,0.0f,0.0f });
			}
			m_nSpawnCnt = 0;
		}

	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CEnemySpawnManager::Draw()
{
}

//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------
CEnemySpawnManager *CEnemySpawnManager::Create(const D3DXVECTOR3& pos)
{
	CEnemySpawnManager *pEnemy = NULL;
	pEnemy = new CEnemySpawnManager;
	pEnemy->m_pos = pos;
	pEnemy->Init();
	return pEnemy;
}