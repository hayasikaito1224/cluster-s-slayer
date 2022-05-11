//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#include "enemy_spawn_manager.h"
#include "enemy001.h"
static const int SpawnTime = 600;
static const float SpawnLength = 200.0f;
static const int SpawnMax = 20;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CEnemySpawnManager::CEnemySpawnManager()
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

}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CEnemySpawnManager::Update(void)
{
	//�X�|�[������܂ł̎��Ԃ��J�E���g
	m_nSpawnCnt++;
	if (m_nSpawnCnt >= m_nSpawnTime)
	{

		//�ő�l�s���܂œG�𐶐�
		for (int nCnt = 0; nCnt < SpawnMax; nCnt++)
		{
			static std::random_device random;	// �񌈒�I�ȗ���������
			std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
			std::uniform_real_distribution<> randAng(0.0f, D3DX_PI);
			std::uniform_real_distribution<> randAng2(0.0f, D3DX_PI);
			float fAng = randAng(mt) - randAng2(mt);
			//�X�|�[���n�_���v�Z
			D3DXVECTOR3 SpawnPos =
			{ sinf(fAng)*SpawnLength ,0.0f,cosf(fAng)*SpawnLength };
			CEnemy001::Create(SpawnPos, { 0.0f,0.0f,0.0f });
		}
		m_nSpawnCnt = 0;
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
CEnemySpawnManager *CEnemySpawnManager::Create()
{
	CEnemySpawnManager *pEnemy = NULL;
	pEnemy = new CEnemySpawnManager;
	pEnemy->Init();
	return pEnemy;
}