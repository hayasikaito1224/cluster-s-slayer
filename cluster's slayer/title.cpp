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
#include "directinput.h"
//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CTitle::CTitle()
{
	m_nNowType = TITLE_PRESS_ENTER;

	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		m_Polygon[nCnt] = nullptr;
	}
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
	m_nNowType = TITLE_PRESS_ENTER;
	m_bNextMode = true;

	CBg::Create(CTexture::Title, CScene::OBJTYPE_BG, false);	//背景

	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		switch (nCnt)
		{
		case PORYGON_LOGO:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2 + 100.0f, 0.0f), D3DXVECTOR3(430.0f, 80.0f, 0.0f), CTexture::GameStart);	// タイトルロゴ

			break;

		case PORYGON_FILEBG:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2, 0.0f), CTexture::FADE);	// フェード
			m_Polygon[nCnt]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
			break;

		case PORYGON_FILE01:
		case PORYGON_FILE02:
		case PORYGON_FILE03:

			int i = nCnt - PORYGON_FILE01;
			D3DXVECTOR3 size = D3DXVECTOR3(float(SCREEN_WIDTH / 3 - 50) / 2.0f, 250.0f, 0.0f);

			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(float(SCREEN_WIDTH / 3) * i + size.x + 25.0f, 0.0f - size.y, 0.0f), size, CTexture::GameStart);

			break;
		}
	}

	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CTitle::Uninit(void)
{
	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		if (m_Polygon[nCnt] != NULL)
		{
			m_Polygon[nCnt]->Uninit();
			m_Polygon[nCnt] = NULL;
		}
	}

	CManager::GetSound()->StopSound(CSound::SOUND_LABEL_BGM_TITLE);
}
//--------------------------------------------
//更新
//--------------------------------------------
void CTitle::Update(void)
{
	switch (m_nNowType)
	{
	case TITLE_PRESS_ENTER:
		// PressEnter押す画面

		// ボタンを押すと
		if (CManager::GetInputKeyboard()->GetTrigger(DIK_RETURN))
		{
			m_nNowType++;
		}

		break;

	case TITLE_FADE:
		// フェード

		m_fAlpha += 0.05f;
		m_Polygon[m_nNowType]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.05f));

		if (m_fAlpha >= 0.5f)
		{
			m_fAlpha = 0.5f;
			m_nNowType++;
		}

		break;

	case TITLE_SELECT_DOWN:

		break;

	case TITLE_FILE_SELECT:
		// ボタンを押すと
		if (CManager::GetInputKeyboard()->GetTrigger(DIK_RETURN))
		{
			if (!m_bNextMode)
			{
				CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
				CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);

				//ゲームモードへ行く
				CFade::SetFade(CManager::MODE_GAME);

				//二回以上通らないようにする
				m_bNextMode = true;
			}
		}

		break;

	default:
		break;
	}
}
//--------------------------------------------
//描画
//--------------------------------------------
void CTitle::Draw(void)
{

}