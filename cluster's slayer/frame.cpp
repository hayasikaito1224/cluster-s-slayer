//--------------------------------------
//�QD�|���S���̉����̏���
//--------------------------------------
#include "frame.h"
#include "Polygon.h"
#include "input.h"
#include "keyboard.h"
#include "manager.h"
#include "mouse.h"
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CFrame::CFrame(OBJTYPE nPriority) :CScene(nPriority)
{
	pPolygonFrame = nullptr;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CFrame::~CFrame()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CFrame::Init(void)
{
	
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CFrame::Uninit(void)
{
	if (pPolygonFrame)
	{
		pPolygonFrame->Uninit();
		pPolygonFrame = nullptr;
	}

	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CFrame::Update(void)
{
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
void CFrame::Draw()
{
}
//-----------------------------------------------
//�C���X�^���X����
//---------------------------------------------
CFrame *CFrame::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const D3DXCOLOR& col)
{
	CFrame *pFrame = new CFrame(OBJTYPE_FRAME);
	if (pFrame)
	{
		if (!pFrame->pPolygonFrame)
		{
			//�g���p�̉摜����
			pFrame->pPolygonFrame = CPolygon::Create(pos, {size.x + 10.0f,size.y + 10.0f,0.0f}, CTexture::None, col, OBJTYPE_FRAME);
		}
		pFrame->Init();
	}

	return pFrame;
}
