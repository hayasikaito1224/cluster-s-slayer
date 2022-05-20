//--------------------------------------
//マネージャーの処理
//--------------------------------------
#include "title.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "XInput.h"
#include "sound.h"

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CTitle::CTitle()
{
	memset(m_Polygon, 0, sizeof(m_Polygon));
	m_bOpra = false;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CTitle::~CTitle()
{

}

//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CTitle::Init(void)
{
	m_bNextMode = false;
	//CBg::Create(CTexture::Title, CScene::OBJTYPE_BG, false);	//背景
	//m_Polygon[0]=CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT / 2 - 280.0f, 0.0f), D3DXVECTOR3(430.0f, 80.0f, 0.0f), CTexture::Titlelogo);	//タイトルロゴ
	//m_Polygon[1]=CPolygon::Create(D3DXVECTOR3(900.0f, SCREEN_HEIGHT / 2 + 50.0f, 0.0f), D3DXVECTOR3(300.0f, 80.0f, 0.0f), CTexture::GameStart);	//ゲームスタート
	//m_Polygon[2]=CPolygon::Create(D3DXVECTOR3(900.0f, SCREEN_HEIGHT / 2 + 250, 0.0f), D3DXVECTOR3(300.0f, 40.0f, 0.0f), CTexture::Operation);	//チュートリアル
	//m_Cursol= CPolygon::Create(D3DXVECTOR3(900.0f, SCREEN_HEIGHT / 2 + 250, 0.0f), D3DXVECTOR3(40.0f, 40.0f, 0.0f), CTexture::Cursol);	//カーソル
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CTitle::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_TITLE_POLYGON; nCnt++)
	{
		if (m_Polygon[nCnt] != NULL)
		{
			m_Polygon[nCnt]->Uninit();
			m_Polygon[nCnt] = NULL;
		}
	}

}
//--------------------------------------------
//更新
//--------------------------------------------
void CTitle::Update(void)
{
}
//--------------------------------------------
//描画
//--------------------------------------------
void CTitle::Draw(void)
{

}

