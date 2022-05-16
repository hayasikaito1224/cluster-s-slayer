//--------------------------------------
//�X�L�������\���p�̏���
//--------------------------------------
#include "selectbottom.h"
#include "Polygon.h"
#include "input.h"
#include "keyboard.h"
#include "manager.h"
#include "mouse.h"
#include "frame.h"
#include "skillselect.h"
#include "player.h"
static const float IconSize = 50.0f;//�A�C�R���̑傫��
static const D3DXVECTOR3 IconPos = {10.0f,-50.0f,0.0f};//�A�C�R���̈ʒu

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CSkillSelectBottom::CSkillSelectBottom(OBJTYPE nPriority) :CScene(nPriority)
{
	pSelectBottom = nullptr;
	m_bPopSelectBottom = true;
	m_bIsSelect = false;
	pSkillIcon = nullptr;
	pFrame = nullptr;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CSkillSelectBottom::~CSkillSelectBottom()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CSkillSelectBottom::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CSkillSelectBottom::Uninit(void)
{
	if (pSelectBottom)
	{
		pSelectBottom->Uninit();
		pSelectBottom = nullptr;
	}
	if (pFrame)
	{
		pFrame->Uninit();
		pFrame = nullptr;
	}
	if (pSkillIcon)
	{
		pSkillIcon->Uninit();
		pSkillIcon = nullptr;
	}
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CSkillSelectBottom::Update(void)
{
	if (m_bPopSelectBottom)
	{
		//�Z���N�g�E�B���h�E�̏o��
		PopSelectBottom();
	}
	else
	{
		SelectBottom();
	}
	//�I�����肪�I���Ȃ�
	if (m_bEnd)
	{
		//�I���������Ă�
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CSkillSelectBottom::Draw()
{

}
//-----------------------------------------------
//�C���X�^���X����
//---------------------------------------------
CSkillSelectBottom *CSkillSelectBottom::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const int& tex, const int& SkillType)
{
	CSkillSelectBottom *pSkillSelect = new CSkillSelectBottom(OBJTYPE_UI);
	if (pSkillSelect)
	{
		if (!pSkillSelect->pSelectBottom)
		{
			//�X�L���I����ʉ摜�̐���
			pSkillSelect->pSelectBottom = CPolygon::Create(pos, size, (CTexture::Type)tex, { 1.0,1.0,1.0,0.0f });
		}
		int nTex = 0;
		pSkillSelect->m_nSkillNo = SkillType;
		switch (SkillType)
		{
		case CPlayer::ATKup:
			nTex = CTexture::ATKup;
			break;
		case CPlayer::Eye:
			nTex = CTexture::Eye;
			break;
		case CPlayer::Heal:
			nTex = CTexture::Heal;
			break;
		case CPlayer::OverHeal:
			nTex = CTexture::OverHeal;
			break;
		case CPlayer::Sheild:
			nTex = CTexture::Sheild;
			break;
		case CPlayer::Beam:
			nTex = CTexture::Beam;
			break;
		case CPlayer::BlackHole:
			nTex = CTexture::BlackHole;
			break;
		case CPlayer::Rocket:
			nTex = CTexture::Rocket;
			break;
		case CPlayer::RushAttack:
			nTex = CTexture::RushAttack;
			break;
		}
		if (!pSkillSelect->pSkillIcon)
		{
			//�X�L���I����ʉ摜�̐���
			pSkillSelect->pSkillIcon = CPolygon::Create({ pos.x + IconPos.x,pos.y + IconPos.y,0.0f }, { IconSize ,IconSize ,0.0f}, (CTexture::Type)nTex, { 1.0,1.0,1.0,0.0f });

		}
		pSkillSelect->Init();
	}

	return pSkillSelect;
}
//-----------------------------------------------
//�Z���N�g�E�B���h�E�̏o��
//---------------------------------------------
void CSkillSelectBottom::PopSelectBottom()
{

	if (pSelectBottom)
	{
		D3DXCOLOR col = pSelectBottom->GetColor();
		D3DXVECTOR3 pos = pSelectBottom->GetPos();
		//��������s�����ɂȂ鏈��
		if (col.a <= 1.0f)
		{
			col.a += 0.05f;
			pSelectBottom->SetCol(col);
		}
		//�w��̈ʒu�Ɉړ������鏈��
		if (pos.y <= SCREEN_HEIGHT / 2.0f)
		{
			pos.y += 2.0f;
			pSelectBottom->SetPos(pos);
		}
		else
		{
			m_bPopSelectBottom = false;
		}
	}
	if (pSkillIcon)
	{
		D3DXCOLOR col = pSkillIcon->GetColor();
		D3DXVECTOR3 pos = pSkillIcon->GetPos();
		//��������s�����ɂȂ鏈��
		if (col.a <= 1.0f)
		{
			col.a += 0.05f;
			pSkillIcon->SetCol(col);
		}
		//�w��̈ʒu�Ɉړ������鏈��
		pos.y += 2.0f;
		pSkillIcon->SetPos(pos);
	}
}
//-----------------------------------------------
//�X�L���I���{�^���̑I������
//---------------------------------------------
void CSkillSelectBottom::SelectBottom()
{
	//�}�E�X���̎擾
	CMouse *pMouse = CManager::GetMouse();

	POINT po;
	//�}�E�X�̃X�N���[�����W�̈ʒu�̎擾
	GetCursorPos(&po);
	D3DXVECTOR3 pos = pSelectBottom->GetPos();
	D3DXVECTOR3 scale = pSelectBottom->GetScale();
	HWND hWnd = GetForegroundWindow();

	//�X�N���[�����W����N���C�A���g���W�̕ϊ�
	ScreenToClient(hWnd, &po);

	float MousePos_X = (float)po.x;
	float MousePos_Y = (float)po.y;
	//�z�u���Ă���|���S���͈̔͂ɃJ�[�\������������
	if (MousePos_X > pos.x- scale.x&&
		MousePos_X < pos.x + scale.x&&
		MousePos_Y > pos.y - scale.y&&
		MousePos_Y < pos.y + scale.y)
	{
		//�I����Ԃɂ���
		m_bIsSelect = true;
		//�I�����ꂽ�|���S���ɘg��\��
		if (!pFrame)
		{
			pFrame = CFrame::Create(pos, scale, { 1.0,1.0,0.0,1.0 });
		}
		//�I�����Ă����Ԃō��N���b�N������ƌ����Ԃɂ���
		if (pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
		{
			m_bIsDecision = true;
		}
	}
	else
	{
		//�I����Ԃ�����
		m_bIsSelect = false;
		if (pFrame)
		{
			pFrame->Uninit();
			pFrame = nullptr;
		}
	}
}
//-----------------------------------------------
//�F�̐ݒ�
//---------------------------------------------
void CSkillSelectBottom::SetCol(D3DXCOLOR col)
{
	if (pSelectBottom)
	{
		pSelectBottom->SetCol(col);
	}
}

