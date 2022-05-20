#include "main.h"
#include "manager.h"
#include "Renderer.h"
#include "player.h"
#include "model.h"
#include "motion.h"
#include "layer_structure.h"
#include "score.h"
#include "keyboard.h"
#include "game.h"
#include "collision.h"
#include "fade.h"
#include "camera.h"
#include "stage.h"
#include "field.h"
#include "model_spawner.h"
#include "shadow.h"
#include "XInput.h"
#include "sound.h"
#include "keyboard.h"
#include "player_controller.h"
#include "goal.h"
#include "effect.h"
#include "billboard.h"

//------------------------------------
//マクロ定義
//------------------------------------
#define MAX_DELAY_TIME (30)
#define MAX_MAGIC_SHOT_TIME (2.0)
#define MAX_PLAYER_JUMP (1)//最大のジャンプ数
#define MAX_PLAYER_PARTS (16)
#define PLAYER_SIZE (20.0)
#define SWORDEFFECT_LONG (16)
#define PLAYER_RANGE (400.0)//プレイヤーと敵の近さを図る範囲
#define PLAYER_ROCKON_SIZE (5.0)//ロックオン画像のサイズ
std::vector<CModel*> CPlayer::m_pSModel;

//--------------------------
//コンストラクト
//----------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pModel = nullptr;
	m_bDelay = false;

}
//--------------------------
//デストラクト
//----------------------------
CPlayer::~CPlayer()
{

}

CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = NULL;
	pPlayer = new CPlayer;
	pPlayer->Init();
	return pPlayer;
}

D3DXVECTOR3 CPlayer::GetModelPos()
{
	return{ m_pModel->GetModel()->GetMtxWorld()._41,m_pModel->GetModel()->GetMtxWorld()._42,m_pModel->GetModel()->GetMtxWorld()._43 };

}

HRESULT CPlayer::Init()
{
	//プレイヤーのコントローラーの呼び出し
	m_pController = new CPlayer_Controller;
	m_pos = D3DXVECTOR3(PLAYER_POS_X, PLAYER_POS_Y, PLAYER_POS_Z);
	m_move = -2.0f;
	m_fSoundInterval = 1.0f;
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_fGravity = 0.0f;//重力度
	m_bland = true;
	m_bMove = false;
	m_pModel = CModel_Spawner::Create(m_pos, { 0.0f,0.0f,0.0f }, 0, CModel::TYPE_PLAYER);
	pShadow = CShadow::Create(m_pos, PLAYER_SIZE, CTexture::Effect);
	return S_OK;
}

void CPlayer::Uninit()
{
	if (m_pModel != NULL)
	{
		m_pModel->Uninit();
		m_pModel = NULL;
	}

	if (pShadow)
	{
		pShadow->Uninit();
		delete pShadow;
		pShadow = NULL;
	}

	Release();
}

void CPlayer::Update()
{
	CXInput *pGamePad = CManager::GetXInput();

	//前回の位置情報の保存
	m_lastpos = m_pos;

	//プレイヤーの移動処理
	m_pController->TestMove(m_pos);
	if (m_pModel != nullptr)
	{
		m_pModel->SetSPos(m_pos);
	}
	m_pController->MouseMove(m_pos);

	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	m_pController->MouseCameraControl();
	//Enterを押したらモデル生成
	if (Key->GetTrigger(DIK_RETURN) == true)
	{
		CModel *Securement = {};
		m_pSModel.push_back(Securement);
		m_pSModel[0] = CModel::Create(m_pModel->GetSPos(), m_rot, 0, CModel::TYPE_PLAYER);
	}

	if(pShadow!=nullptr)
	{
		pShadow->SetPos(m_pos.x, m_pos.z, D3DXVECTOR3(PLAYER_SIZE, 0.0f, PLAYER_SIZE));
	}


	//m_pCollision->SetPos(m_pos);
	CCamera *pCamera = CRenderer::GetCamera();
	pCamera->SetPlayerCamera(m_pos);
	CScene::SetPos(m_pos);

}

void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ
	D3DXMATRIX mtxRotModel, mtxTransModel;//計算用マトリックス
	//各パーツのワールドマトリックスの初期化gtryg
	D3DXMatrixIdentity(&m_mtxWorld);      
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//向きを反映
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);
	//位置を反映
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//各パーツのワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);


	//モデル生成
	if (m_pModel)
	{
		m_pModel->Draw();

	}

	for (int nCnt = 0; nCnt <(int)m_pSModel.size(); nCnt++)
	{
		if (m_pSModel[nCnt] != nullptr)
		{
			m_pSModel[nCnt]->Draw();
		}
	}

	m_pController->Drawtext();
	Drawtext();
}
void CPlayer::Drawtext()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[1200];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n\n\n\n\n\n プレイヤー情報 \n");
	nNum += sprintf(&str[nNum], " [Pos] X%.2f,Y%.2f,Z%.2f \n", m_pModel->GetSPos().x, m_pModel->GetSPos().y, m_pModel->GetSPos().z);
	nNum += sprintf(&str[nNum], " [rot] X%.2f,Y%.2f,Z%.2f \n", m_rot.x, m_rot.y, m_rot.z);

	//for (int nCnt = 0; nCnt < 2; nCnt++)
	//{
	//	nNum += sprintf(&str[nNum], " [SwordEffectEndPos] X%.2f,Y%.2f,Z%.2f \n", m_pSwordLocus->GetEndPos().x, m_pSwordLocus->GetEndPos().y, m_pSwordLocus->GetEndPos().z);
	//}


	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// テキスト描画
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}

