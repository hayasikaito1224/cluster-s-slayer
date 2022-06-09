//*****************************************************************************
// (�ړ�����)�G�t�F�N�g���� [Movement.cpp]
// Author : �����G��
//*****************************************************************************

#include "Movement.h"
#include "scene2D.h"

//*****************************************************************************
//�R���X�g���N�^
//*****************************************************************************
CMovement::CMovement(OBJTYPE nPriority) : CEffect2d(nPriority)
{
	m_move = {};
	m_Addpos = {};
}

//*****************************************************************************
//�f�X�g���N�^
//*****************************************************************************
CMovement::~CMovement()
{

}

//*****************************************************************************
//	������
//*****************************************************************************
HRESULT CMovement::Init(D3DXVECTOR3 pos,
	D3DXVECTOR3 move, 
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife, int nType,
	D3DXVECTOR3 AddMovement,
	int Synthetic)
{
	CEffect2d::Init(pos, color, Mincolor, Size, MinSize, nLife, nType, Synthetic);

	m_Addpos = AddMovement;
	m_move = move;
	return S_OK;
}

//*****************************************************************************
//�I��
//*****************************************************************************
void CMovement::Uninit()
{
	CEffect2d::Uninit();
}

//*****************************************************************************
//�X�V
//*****************************************************************************
void CMovement::Update()
{
	D3DXVECTOR3 pos = GetPos();

	m_move += m_Addpos;	//�ړ��l�Ɋ��������Z

	pos += D3DXVECTOR3(m_move.x, m_move.y, 0.0f);

	m_Size += m_MinSize;

	//�K��
	CScene2D::SetPos(pos, D3DXVECTOR3(m_Size.x, m_Size.y, 0.0f));
	CEffect2d::Update();
}

//*****************************************************************************
//�`��
//*****************************************************************************
void CMovement::Draw()
{
	CEffect2d::Draw();
}

//*****************************************************************************
//�쐬
//*****************************************************************************
CMovement *CMovement::Create(D3DXVECTOR3 pos,
	D3DXVECTOR3 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife, int nType,
	D3DXVECTOR3 AddMovement,
	int Synthetic,
	const int& nPriorty)
{
	CMovement *pMovement = NULL;
	pMovement = new CMovement((CScene::OBJTYPE)nPriorty);		//�������m��

	//NULL�`�F�b�N
	if (pMovement != NULL)
	{
		pMovement->Init(pos, move, color, Mincolor, Size, MinSize, nLife, nType, AddMovement, Synthetic);
	}

	return pMovement;
}
