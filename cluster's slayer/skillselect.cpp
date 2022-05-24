//--------------------------------------
//�X�L���I����ʂ̏���
//--------------------------------------
#include "skillselect.h"
#include "Polygon.h"
#include "input.h"
#include "keyboard.h"
#include "manager.h"
#include "selectbottom.h"
#include "player.h"
#include "game.h"
#include "mouse.h"
#include "PresetSetEffect.h"

static const D3DXVECTOR3 SelectWindowSize = { 500.0f,300.f,0.0f };
static const D3DXVECTOR3 SelectBottomSize = { 150.0f,250.f,0.0f };
static const D3DXVECTOR3 SelectBottomPos = { 300.0f,300.f,0.0f };
static const float SelectBottomPosInterval = 200.0f;//�A�N�V�����X�L���̗����̍ŏ��l

static const int ActionSkillMin = 5;//�A�N�V�����X�L���̗����̍ŏ��l
static const int ActionSkillMax = 9;//�A�N�V�����X�L���̗����̍ő�l
static const int PassiveSkillMin = 0;//�p�b�V�u�X�L���̗����̍ŏ��l
static const int PassiveSkillMax = 5;//�p�b�V�u�X�L���̗����̍ő�l

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CSkillSelect::CSkillSelect(OBJTYPE nPriority):CScene(nPriority)
{
	pSelectWindow = nullptr;
	m_bPopSelectWindow = true;
	pSelectWindowBg = nullptr;
	m_nSelectType = 0;
	m_nDecisionType = -1;
	for (int nCnt = 0; nCnt < max_Bottom; nCnt++)
	{
		pSkillBottom[nCnt] = nullptr;
	}
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CSkillSelect::~CSkillSelect()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CSkillSelect::Init(void)
{
	if (!pSelectWindowBg)
	{
		//�X�L���I����ʂ̔w�i�̐���
		pSelectWindowBg = CPolygon::Create({ SCREEN_WIDTH / 2.0f, SCREEN_WIDTH / 2.0f, 0.0f },
		{ SCREEN_WIDTH / 2.0f, SCREEN_WIDTH / 2.0f, 0.0f }, CTexture::FADE, { 1.0f,1.0f,1.0f,0.0f }, OBJTYPE_TIME);

	}
	if (!pSelectWindow)
	{
		//�X�L���I����ʉ摜�̐���
		pSelectWindow = CPolygon::Create({ SCREEN_WIDTH / 2.0f,320.0f,0.0f }, SelectWindowSize, CTexture::FADE, {1.0,1.0,1.0,0.0}, OBJTYPE_TIME);
	}
	ShowCursor(true);

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CSkillSelect::Uninit(void)
{
	//�J�[�\�����݂��Ȃ��悤�ɂ���
	ShowCursor(false);

	if (pSelectWindow)
	{
		pSelectWindow->Uninit();
		pSelectWindow = nullptr;
	}
	if (pSelectWindowBg)
	{
		pSelectWindowBg->Uninit();
		pSelectWindowBg = nullptr;
	}
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CSkillSelect::Update(void)
{
	POINT po;
	//�}�E�X�̃X�N���[�����W�̈ʒu�̎擾
	GetCursorPos(&po);
	HWND hWnd = GetForegroundWindow();

	//�X�N���[�����W����N���C�A���g���W�̕ϊ�
	ScreenToClient(hWnd, &po);

	//�}�E�X���̎擾
	CMouse *pMouse = CManager::GetMouse();

	//�I�����Ă����Ԃō��N���b�N������ƌ����Ԃɂ���
	if (pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
	{
		CPresetEffect::SetEffect2D(0, D3DXVECTOR3(po.x, po.y, 0.0f), {},OBJTYPE_UI);
	}

	if (m_bPopSelectWindow)
	{
		//�Z���N�g�E�B���h�E�̏o��
		PopSelectWindow();
	}
	else
	{

		CInputKeyBoard *Key = CManager::GetInputKeyboard();
		for (int nCnt = 0; nCnt < max_Bottom; nCnt++)
		{
			if (pSkillBottom[nCnt])
			{
				bool bDecision = pSkillBottom[nCnt]->GetDecision();
				//�ǂꂩ�����肵�Ă����ԂȂ�I��
				if (bDecision)
				{
					m_nDecisionType = nCnt;
					//�ǂ̃X�L����I�����������擾
					int nSkillType = pSkillBottom[nCnt]->GetSkillNo();
					CPlayer *pPlayer = CManager::GetGame()->GetPlayer();
					//�I�������X�L���̔��f
					pPlayer->LevelUp(nSkillType);
					m_bEnd = true;
				}
			}
		}
	}
	//�I�����肪�I���Ȃ�
	if (m_bEnd)
	{
		//�Q�[�����~�߂�
		CManager::SetPause(false, false);
		//�X�L���I���{�^��������
		for (int nCnt = 0; nCnt < max_Bottom; nCnt++)
		{
			if (pSkillBottom[nCnt])
			{
				pSkillBottom[nCnt]->SetEnd(true);

			}
		}
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CSkillSelect::Draw()
{
}
//-----------------------------------------------
//�C���X�^���X����
//---------------------------------------------
CSkillSelect *CSkillSelect::Create()
{
	CSkillSelect *pSkillSelect = new CSkillSelect;
	if (pSkillSelect)
	{
		pSkillSelect->Init();
	}

	return pSkillSelect;
}
//-----------------------------------------------
//�Z���N�g�E�B���h�E�̏o��
//---------------------------------------------
void CSkillSelect::PopSelectWindow()
{
	if (pSelectWindowBg)
	{
		D3DXCOLOR col = pSelectWindowBg->GetColor();
		if (col.a <= 0.2f)
		{
			col.a += 0.01f;
			pSelectWindowBg->SetCol(col);
		}
	}
	if (pSelectWindow)
	{
		D3DXVECTOR3 pos = pSelectWindow->GetPos();
		if (pos.y <= SCREEN_HEIGHT / 2.0f)
		{
			pos.y += 2.0f;
			pSelectWindow->SetPos(pos);
		}
		else
		{
			static std::random_device random;	// �񌈒�I�ȗ���������
			std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
			std::uniform_real_distribution<> randPassive(PassiveSkillMin, PassiveSkillMax);
			std::uniform_real_distribution<> randAction(ActionSkillMin, ActionSkillMax);
			//�p�b�V�u�X�L��1�̒��I
			int nPassive01 = (int)randPassive(mt);
			//�p�b�V�u�X�L��2�̒��I
			int nPassive02 = (int)randPassive(mt);
			//�p�b�V�u�X�L��2���P�Ɠ����Ȃ�Ē��I
			while (nPassive01== nPassive02)
			{
				nPassive02 = (int)randPassive(mt);
			}
			//�A�N�V�����X�L���̒��I
			int nAction = (int)randAction(mt);

			//�X�L���{�^���̐���
			if (!pSkillBottom[0])
			{
				pSkillBottom[0] = CSkillSelectBottom::Create(
				{ SelectBottomPos.x + ((SelectBottomSize.x+ SelectBottomPosInterval)*0),SelectBottomPos.y,0.0f },
					SelectBottomSize, CTexture::FADE, nPassive01);
			}
			if (!pSkillBottom[1])
			{
				pSkillBottom[1] = CSkillSelectBottom::Create(
				{ SelectBottomPos.x + ((SelectBottomSize.x + SelectBottomPosInterval) * 1),SelectBottomPos.y,0.0f },
					SelectBottomSize, CTexture::FADE, nPassive02);
			}
			if (!pSkillBottom[2])
			{
				pSkillBottom[2] = CSkillSelectBottom::Create(
				{ SelectBottomPos.x + ((SelectBottomSize.x + SelectBottomPosInterval) * 2),SelectBottomPos.y,0.0f },
					SelectBottomSize, CTexture::FADE, nAction);
			}
			m_bPopSelectWindow = false;
		}
	}
}

