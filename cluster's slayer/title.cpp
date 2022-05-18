//--------------------------------------
//�}�l�[�W���[�̏���
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
#include "titleselectbutton.h"
#include "savedata.h"
#include "mouse.h"
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CTitle::CTitle()
{
	m_nNowType = TITLE_PRESS_ENTER;
	m_TitleLogo = nullptr;
	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		m_Polygon[nCnt] = nullptr;
	}

	for (int nCnt = 0; nCnt < max_TitleButton; nCnt++)
	{
		pSkillBottom[nCnt] = nullptr;
	}
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CTitle::~CTitle()
{

}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CTitle::Init(void)
{
	m_nNowType = TITLE_PRESS_ENTER;
	m_bNextMode = false;
	m_fAlpha = 0.0f;
	m_nSelectType = 0;
	m_nDecisionType = 0;

	m_TitleLogo = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2 - 100.0f, 0.0f), D3DXVECTOR3(250.0f, 170.0f, 0.0f), CTexture::Title, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CScene::OBJTYPE_BG);	// �^�C�g�����S

	for (int nCnt = 0; nCnt < POLYGON_MAX; nCnt++)
	{
		int i = nCnt - PORYGON_FILE01;
		D3DXVECTOR3 size = D3DXVECTOR3(float(SCREEN_WIDTH / 3 - 50) / 2.0f, 250.0f, 0.0f);

		switch (nCnt)
		{
		case PORYGON_LOGO:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(330.0f, 60.0f, 0.0f), CTexture::GameStart, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CScene::OBJTYPE_BG);	// �^�C�g�����S

			break;

		case PORYGON_FILEBG:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2, 0.0f), CTexture::FADE, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f), CScene::OBJTYPE_BG);	// �t�F�[�h
			m_Polygon[nCnt]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
			break;

		case PORYGON_FILE01:
		case PORYGON_FILE02:
		case PORYGON_FILE03:
			m_Polygon[nCnt] = CPolygon::Create(D3DXVECTOR3(float(SCREEN_WIDTH / 3) * i + size.x + 25.0f, 0.0f - size.y, 0.0f), size, CTexture::Text);

			break;

		case PORYGON_FILEDELETE:
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
	if (m_TitleLogo)
	{
		m_TitleLogo->Uninit();
		m_TitleLogo = nullptr;
	}
	CManager::GetSound()->StopSound(CSound::SOUND_LABEL_BGM_TITLE);
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CTitle::Update(void)
{
	//�}�E�X���̎擾
	CMouse *pMouse = CManager::GetMouse();

	switch (m_nNowType)
	{
	case TITLE_PRESS_ENTER:
		// PressEnter�������

		// �{�^����������
		if (CManager::GetInputKeyboard()->GetTrigger(DIK_RETURN) ||
			CManager::GetInputKeyboard()->GetTrigger(DIK_SPACE) ||
			CManager::GetMouse()->GetTrigger(CMouse::MOUSE_LEFT))
		{
			m_nNowType++;
		}

		break;

	case TITLE_FADE:
		// �t�F�[�h

		m_fAlpha += 0.025f;
		m_Polygon[m_nNowType]->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_fAlpha));

		if (m_fAlpha >= 0.75f)
		{
			m_fAlpha = 0.75f;
			m_nNowType++;
		}

		break;

	case TITLE_SELECT_DOWN:
		for (int nCnt = 0 + PORYGON_FILE01; nCnt < POLYGON_MAX - 1; nCnt++)
		{
			float speed = 15.0f;
			m_Polygon[nCnt]->SetPos(D3DXVECTOR3(m_Polygon[nCnt]->GetPos().x, m_Polygon[nCnt]->GetPos().y + speed, m_Polygon[nCnt]->GetPos().z));

			if (m_Polygon[nCnt]->GetPos().y + m_Polygon[nCnt]->GetScale().y >= SCREEN_WIDTH / 2 - 100)
			{
				m_Polygon[nCnt]->SetPos(D3DXVECTOR3(m_Polygon[nCnt]->GetPos().x, SCREEN_WIDTH / 2 - 100 - m_Polygon[nCnt]->GetScale().y, m_Polygon[nCnt]->GetPos().z));
			}
		}

		if (m_Polygon[PORYGON_FILE03]->GetPos().y + m_Polygon[PORYGON_FILE03]->GetScale().y >= SCREEN_WIDTH / 2 - 100)
		{
			if (!m_Polygon[PORYGON_FILEDELETE])
			{
				m_Polygon[PORYGON_FILEDELETE] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH - 190.0f, SCREEN_HEIGHT - 90.0f, 0.0f), D3DXVECTOR3(160.0f, 40.0f, 0.0f), CTexture::Text);
			}

			for (int nCnt = 0; nCnt < max_TitleButton; nCnt++)
			{
				if (!pSkillBottom[nCnt])
				{
					ButtonCreate(nCnt);
				}
			}

			m_nNowType++;
		}

		break;

	case TITLE_FILE_SELECT:
		if (!m_bNextMode)
		{
			for (int nCnt = 0; nCnt < max_TitleButton; nCnt++)
			{
				if (pSkillBottom[nCnt]->GetDecision())
				{
					m_nDecisionType = nCnt + PORYGON_FILE01;
				}

				if (m_nDecisionType != 0)
				{
					//�ǂꂩ�����肵�Ă����ԂȂ�I��
					if (m_nDecisionType < PORYGON_FILEDELETE)
					{
						// �f�[�^�ǂݍ���

						// �������Đ�
						CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
						CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);

						m_bNextMode = true;

						// ���j���[�V�[���֍s��
						CFade::SetFade(CManager::MODE_MENU);
					}

					else
					{
						pSkillBottom[nCnt]->GetSelectButton()->BindTexture(CTexture::Heal);
						m_nDecisionType = 0;
						m_nNowType++;
					}
				}
			}
		}

		break;

	case TITLE_FILE_DELETE:
		for (int nCnt = 0; nCnt < max_TitleButton; nCnt++)
		{
			if (pSkillBottom[nCnt]->GetDecision())
			{
				m_nDecisionType = nCnt + PORYGON_FILE01;
			}

			if (m_nDecisionType != 0)
			{
				//�ǂꂩ�����肵�Ă����ԂȂ�I��
				if (m_nDecisionType < PORYGON_FILEDELETE)
				{
					string FileName = "data\\SAVE\\data";
					FileName += to_string(nCnt + 1);
					FileName += ".txt";

					// �f�[�^�폜
					CSaveData::ResetFile(FileName);

					// �������Đ�
					CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
					CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);
				}

				else
				{
					pSkillBottom[nCnt]->GetSelectButton()->BindTexture(CTexture::Text);
					m_nNowType--;
				}

				m_nDecisionType = 0;

			}
		}

		break;

	default:
		break;
	}
}
//--------------------------------------------
//�`��
//--------------------------------------------
void CTitle::Draw(void)
{

}

void CTitle::ButtonCreate(int num)
{
	D3DXVECTOR3 size = D3DXVECTOR3(float(SCREEN_WIDTH / 3 - 50) / 2.0f, 250.0f, 0.0f);
	pSkillBottom[num] = CTitleSelectButton::Create(
	m_Polygon[num + PORYGON_FILE01]->GetPos(), m_Polygon[num + PORYGON_FILE01]->GetScale(), CTexture::Text);
}