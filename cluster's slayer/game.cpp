//--------------------------------------
//ゲーム画面の処理
//--------------------------------------
#include "game.h"
#include "Renderer.h"//後で消す
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "fade.h"
#include "Scene3D.h"
#include "time.h"
#include "model_spawner.h"
#include "collision.h"
#include "score.h"
#include "field.h"
#include "meshsphere.h"
#include "stage.h"
#include "Enemy.h"
#include "Polygon.h"
#include "pause.h"
#include "XInput.h"
#include "camera.h"
#include "Particle.h"
#include "gauge.h"
#include "directinput.h"
#define BOSS_LIFE (100)		//生命力
#define PLAYER_LIFE (100)		//生命力
#define PLAYER_MP (100)		//マナの多さ
#define MAX_DELAY (30)//ディレイの最大
//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CModel_Spawner *CGame::m_pModel = nullptr;
CScore	*CGame::m_pScore = nullptr;
CField	*CGame::m_pField = nullptr;
CField	*CGame::m_pSea = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CPolygon *CGame::m_Cursol = nullptr;
CMeshSphere *CGame::m_pMeshSphere = nullptr;
CStage  *CGame::m_pStage = nullptr;
CParticle   *CGame::m_Particle = nullptr;

std::vector<CPolygon*>   CGame::m_pCStock = {};
static float s_texrotx = 0.0f;
static float s_texseax = 0.0f;
static int s_nTime = 0;
static bool s_bTime = false;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CGame::CGame()
{
	m_pCStock.clear();
	m_Player = nullptr;
	m_pFlore = nullptr;
	m_pBg = nullptr;
	m_pModel = nullptr;
	m_pScore = nullptr;
	m_pField = nullptr;
	m_pMeshSphere = nullptr;
	m_pSea = nullptr;
	m_Particle = nullptr;
	m_pStage = nullptr;
	m_Polygon = nullptr;
	m_nCntDelay = 0;
	m_bPush = false;
	m_bEnd = false;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CGame::~CGame()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CGame::Init(void)
{
	//マウスの表示をなくす
	//ShowCursor(false);

	//プレイヤーの生成
	if (!m_Player)
	{
		m_Player = CPlayer::Create();
	}

	//パーティクルシステムの生成
	if (m_Particle == nullptr)
	{
		m_Particle = new CParticle;
	}
	//空の生成
	if (m_pMeshSphere == NULL)
	{
		m_pMeshSphere = CMeshSphere::Create(D3DXVECTOR3(0.0f, -1000.0f, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),
			8, 4, 40000.0f, 1.0f, CTexture::FADE);
	}
	//ステージの生成
	if (m_pStage == NULL)
	{
		m_pStage = new CStage;
		m_pStage->Load("data/TEXT/StageData002.txt");
	}

	////目的表示
	//CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 40.0f, 0.0f),
	//	D3DXVECTOR3(210.0f, 20.0f, 0.0f), CTexture::TargetText);
	////操作方法
	//CPolygon::Create(D3DXVECTOR3(140.0f, SCREEN_HEIGHT-130.0f, 0.0f),
	//	D3DXVECTOR3(140.0f, 90.0f, 0.0f), CTexture::Operation);

	m_fAlpha = 1.0f;
	m_bNextMode = false;
	m_nTimer = 0;
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CGame::Uninit(void)
{

	if (m_Player != nullptr)
	{
		m_Player->Uninit();
		m_Player = nullptr;
	}
	if (m_pModel != nullptr)
	{
		m_pModel->Uninit();
		delete m_pModel;
		m_pModel = nullptr;
	}
	if (m_pScore != nullptr)
	{
		m_pScore->Uninit();
		delete m_pScore;
		m_pScore = nullptr;
	}
	if (m_pMeshSphere != nullptr)
	{
		m_pMeshSphere->Uninit();
		delete m_pMeshSphere;
		m_pMeshSphere = nullptr;
	}
	if (m_Cursol != nullptr)
	{
		m_Cursol->Uninit();
		m_Cursol = nullptr;
	}
	if (m_Polygon != nullptr)
	{
		m_Polygon->Uninit();
		m_Polygon = nullptr;
	}
}
//--------------------------------------------
//更新
//--------------------------------------------
void CGame::Update(void)
{
	//DirectInputのゲームパッドの取得
	CDirectInput *pGamePad = CManager::GetDirectInput();
	//ゲームが続いていたら
	if (m_bEnd == false)
	{
	}

}

//--------------------------------------------
//描画
//--------------------------------------------
void CGame::Draw(LPD3DXMATRIX mtrix)
{
}

