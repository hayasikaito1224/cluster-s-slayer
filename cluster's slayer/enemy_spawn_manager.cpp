//--------------------------------------------
//敵の出現設定処理
//作成者：林
//--------------------------------------------
#include "enemy_spawn_manager.h"
#include "enemy001.h"
static const int SpawnTime = 600;
static const float SpawnLength = 200.0f;
static const int SpawnMax = 20;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CEnemySpawnManager::CEnemySpawnManager()
{
	m_nSpawnTime = SpawnTime;
	m_nSpawnCnt = SpawnTime;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CEnemySpawnManager::~CEnemySpawnManager()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CEnemySpawnManager::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CEnemySpawnManager::Uninit(void)
{

}
//--------------------------------------------
//更新
//--------------------------------------------
void CEnemySpawnManager::Update(void)
{
	//スポーンするまでの時間をカウント
	m_nSpawnCnt++;
	if (m_nSpawnCnt >= m_nSpawnTime)
	{

		//最大値行くまで敵を生成
		for (int nCnt = 0; nCnt < SpawnMax; nCnt++)
		{
			static std::random_device random;	// 非決定的な乱数生成器
			std::mt19937_64 mt(random());            // メルセンヌ・ツイスタの64ビット版、引数は初期シード
			std::uniform_real_distribution<> randAng(0.0f, D3DX_PI);
			std::uniform_real_distribution<> randAng2(0.0f, D3DX_PI);
			float fAng = randAng(mt) - randAng2(mt);
			//スポーン地点を計算
			D3DXVECTOR3 SpawnPos =
			{ sinf(fAng)*SpawnLength ,0.0f,cosf(fAng)*SpawnLength };
			CEnemy001::Create(SpawnPos, { 0.0f,0.0f,0.0f });
		}
		m_nSpawnCnt = 0;
	}
}

//--------------------------------------------
//描画
//--------------------------------------------
void CEnemySpawnManager::Draw()
{
}

//----------------------------------------------
//インスタンス生成
//----------------------------------------------
CEnemySpawnManager *CEnemySpawnManager::Create()
{
	CEnemySpawnManager *pEnemy = NULL;
	pEnemy = new CEnemySpawnManager;
	pEnemy->Init();
	return pEnemy;
}