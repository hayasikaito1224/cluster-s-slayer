//--------------------------------------
//�Q�[���J�n�O�̃��j���[���
//--------------------------------------
#include "gamemenu.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "XInput.h"
#include "sound.h"
#include "directinput.h"
#include "titleselectbutton.h"
#include "savedata.h"

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGameMenu::CGameMenu()
{
	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		m_Polygon[nCnt] = nullptr;
	}

	for (int nCnt = 0; nCnt < max_MenuButton; nCnt++)
	{
		pButton[nCnt] = nullptr;
	}
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CGameMenu::~CGameMenu()
{

}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CGameMenu::Init(void)
{
	m_bNextMode = false;
	m_nSelectType = 0;
	m_nDecisionType = 0;

	CBg::Create(CTexture::Title, CScene::OBJTYPE_BG, false);	//�w�i

	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		switch (nCnt)
		{
		case PORYGON_FILEBG:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2, 0.0f), CTexture::FADE, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CScene::OBJTYPE_BG);	// �^�C�g�����S

			break;

		case PORYGON_GAME_START:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(SCREEN_WIDTH / 8.0f, SCREEN_HEIGHT / 8.0f, 0.0f), CTexture::Text, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));	// �t�F�[�h
			break;

		case PORYGON_UPGRADE:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH - m_Polygon[PORYGON_GAME_START]->GetPos().x, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(SCREEN_WIDTH / 12.0f, SCREEN_HEIGHT / 12.0f, 0.0f), CTexture::Text);

			break;

		case PORYGON_RETURN_TO_TITLE:
			break;

		default:
			break;
		}
	}

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGameMenu::Uninit(void)
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
//�X�V
//--------------------------------------------
void CGameMenu::Update(void)
{

}
//--------------------------------------------
//�`��
//--------------------------------------------
void CGameMenu::Draw(void)
{

}

void CGameMenu::ButtonCreate(int num)
{
	D3DXVECTOR3 size = D3DXVECTOR3(float(SCREEN_WIDTH / 3 - 50) / 2.0f, 250.0f, 0.0f);
	pButton[num] = CTitleSelectButton::Create(
		m_Polygon[num + PORYGON_GAME_START]->GetPos(), m_Polygon[num + PORYGON_GAME_START]->GetScale(), CTexture::Text);
}