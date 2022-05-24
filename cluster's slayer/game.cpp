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
#include "enemy_spawn_manager.h"
#include "gauge.h"
#include "skillselect.h"
#include "character.h"
#include "gaugeber.h"
#include "character_partsdata.h"
#include "enemy001.h"
#include "stage_preset_data.h"
#include <time.h>
#include "gametimer.h"
#include "skill_leveldata.h"
#define BOSS_LIFE (100)		//生命力
#define PLAYER_LIFE (100)		//生命力
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
CEnemySpawnManager   *CGame::m_pEnemySpawnManager = nullptr;
CGauge   *CGame::m_pExpGauge = nullptr;
CGauge   *CGame::m_pHPGauge = nullptr;
CGametimer   *CGame::m_pGametimer = nullptr;

static float s_texrotx = 0.0f;
static float s_texseax = 0.0f;
static int s_nTime = 0;
static bool s_bTime = false;
static int ClearTime = 10;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CGame::CGame()
{
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
	m_pEnemySpawnManager = nullptr;
	m_pExpGauge = nullptr;
	m_pHPGauge = nullptr;
	m_bIsClear = false;
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
	ShowCursor(false);

	//キャラクターのパーツを読み込み
	CCharacterPartsData::Create();
	//プレイヤーの生成
	if (!m_Player)
	{
		m_Player = CPlayer::Create();
	}
	//経験値のゲージを生成
	if (!m_pExpGauge)
	{
		m_pExpGauge = CGauge::Create({ 0.0f,680.0f,0.0f }, { SCREEN_WIDTH,10.0f,0.0f }, { 0.5,0.5,1.0,1.0 }, SCREEN_WIDTH, 2, CGauge::R_ADD);
		m_pExpGauge->ResetGauge(0);
	}
	//体力ゲージの生成
	if (!m_pHPGauge)
	{
		float fHP = m_Player->GetLife();
		m_pHPGauge = CGauge::Create({ 0.0f,100.0f,0.0f }, { 400.0f,15.0f,0.0f }, { 0.5,1.0,0.5,1.0 }, 400, fHP, CGauge::R_ADD);
		//m_pHPGauge->ResetGauge(0);
	}
	//パーティクルシステムの生成
	if (m_Particle == nullptr)
	{
		m_Particle = new CParticle;
	}
	//空の生成
	if (m_pMeshSphere == NULL)
	{
		m_pMeshSphere = CMeshSphere::Create(D3DXVECTOR3(0.0f, -2000.0f, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),
			8, 4, 40000.0f, 1.0f, CTexture::SKY);
	}
	//ステージの生成
	if (m_pStage == NULL)
	{
		m_pStage = new CStage;
		m_pStage->Init();
		m_pStage->SetStage();
	}
	//CField::Create({ 0.0,0.0,0.0 }, {150.0f,0.0,150.0f}, { 0.0f,0.0f,0.0f }, 20, 20, CTexture::FIELD);
	if (!m_pGametimer)
	{
		m_pGametimer = CGametimer::Create({ SCREEN_WIDTH / 2,100.0f,0.0f }, { 1.0,1.0,1.0,1.0 });
	}
	//敵の出現設定の生成
	if (!m_pEnemySpawnManager)
	{
		m_pEnemySpawnManager = CEnemySpawnManager::Create();
	}
	//スキルのステータスの読み込み
	CSkill_LevelData::Create();
	////目的表示
	//CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 40.0f, 0.0f),
	//	D3DXVECTOR3(210.0f, 20.0f, 0.0f), CTexture::TargetText);
	////操作方法
	//CPolygon::Create(D3DXVECTOR3(140.0f, SCREEN_HEIGHT-130.0f, 0.0f),
	//	D3DXVECTOR3(140.0f, 90.0f, 0.0f), CTexture::Operation);
	//CEnemy001::Create({0.0f,0.0f,0.0f}, { 0.0f,0.0f,0.0f });

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
	if (m_pGametimer)
	{
		m_pGametimer->Uninit();
		m_pGametimer = nullptr;
	}
	if (m_Player)
	{
		m_Player->Uninit();
		m_Player = nullptr;
	}
	if (m_pModel)
	{
		m_pModel->Uninit();
		delete m_pModel;
		m_pModel = nullptr;
	}
	if (m_pScore)
	{
		m_pScore->Uninit();
		delete m_pScore;
		m_pScore = nullptr;
	}
	if (m_pMeshSphere)
	{
		m_pMeshSphere->Uninit();
		delete m_pMeshSphere;
		m_pMeshSphere = nullptr;
	}
	if (m_Cursol)
	{
		m_Cursol->Uninit();
		m_Cursol = nullptr;
	}
	if (m_Polygon)
	{
		m_Polygon->Uninit();
		m_Polygon = nullptr;
	}
	if (m_pExpGauge)
	{
		m_pExpGauge->Uninit();
		m_pExpGauge = nullptr;
	}
	if (m_pEnemySpawnManager)
	{
		m_pEnemySpawnManager->Uninit();
		delete m_pEnemySpawnManager;
		m_pEnemySpawnManager = nullptr;
	}
	CEnemy::SetMaxEnemy(0);
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
		if (!m_bNextMode)
		{
			if (m_pEnemySpawnManager && !CManager::GetPause())
			{
				m_pEnemySpawnManager->Update();
			}
			if (m_pExpGauge)
			{
				float fExp = m_pExpGauge->GetGaugeBer(0)->GetGaugeValue();
				float fMaxExp = m_pExpGauge->GetGaugeBer(0)->GetGaugeValueMax();
				//経験値ゲージが最大になったら０に戻す
				if (fExp >= fMaxExp)
				{
					//ゲームを止める
					CManager::SetPause(true, false);
					m_pExpGauge->ResetGauge(0);
					CSkillSelect::Create();

				}

			}
			if (m_pGametimer)
			{
				int nTime = m_pGametimer->GetMinute();
				if (nTime >= ClearTime)
				{
					m_bIsClear = true;
				}
			}

			//クリア判定が有効ならクリア画面を表示させる
			if (m_bIsClear)
			{
				m_bNextMode = true;
				// タイトルシーンへ行く
				CFade::SetFade(CManager::MODE_TITLE);
			}
		}
	}

}

//--------------------------------------------
//描画
//--------------------------------------------
void CGame::Draw()
{
}

