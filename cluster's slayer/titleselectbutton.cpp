//--------------------------------------
//�t�@�C���I��\���p�̏���
//--------------------------------------
#include "titleselectbutton.h"
#include "Polygon.h"
#include "input.h"
#include "keyboard.h"
#include "manager.h"
#include "mouse.h"
#include "frame.h"
#include "skillselect.h"
#include "player.h"
static const float IconSize = 50.0f;//�A�C�R���̑傫��
static const D3DXVECTOR3 IconPos = { 10.0f,-50.0f,0.0f };//�A�C�R���̈ʒu

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CTitleSelectButton::CTitleSelectButton(OBJTYPE nPriority) :CScene2D(nPriority)
{
	pSelectBottom = nullptr;
	m_bPopSelectBottom = true;
	m_bIsSelect = false;
	pFrame = nullptr;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CTitleSelectButton::~CTitleSelectButton()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CTitleSelectButton::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CTitleSelectButton::Uninit(void)
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
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CTitleSelectButton::Update(void)
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
void CTitleSelectButton::Draw()
{

}
//-----------------------------------------------
//�C���X�^���X����
//---------------------------------------------
CTitleSelectButton *CTitleSelectButton::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const int& tex)
{
	CTitleSelectButton *pSkillSelect = new CTitleSelectButton(OBJTYPE_UI);
	if (pSkillSelect)
	{
		if (!pSkillSelect->pSelectBottom)
		{
			//�X�L���I����ʉ摜�̐���
			pSkillSelect->pSelectBottom = CPolygon::Create(pos, size, (CTexture::Type)tex, { 1.0,1.0,1.0,0.0f });
		}
		int nTex = 0;

		pSkillSelect->Init();
	}

	return pSkillSelect;
}
//-----------------------------------------------
//�Z���N�g�E�B���h�E�̏o��
//---------------------------------------------
void CTitleSelectButton::PopSelectBottom()
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
		else
		{
			m_bPopSelectBottom = false;
		}
	}
}
//-----------------------------------------------
//�X�L���I���{�^���̑I������
//---------------------------------------------
void CTitleSelectButton::SelectBottom()
{
	m_bIsDecision = false;

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
	if (MousePos_X > pos.x - scale.x&&
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
void CTitleSelectButton::SetCol(D3DXCOLOR col)
{
	if (pSelectBottom)
	{
		pSelectBottom->SetCol(col);
	}
}

