//=============================================================================
//
// Polygon����
//
//=============================================================================
#include "Polygon.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CPolygon::CPolygon(OBJTYPE nPriority) : CScene2D(nPriority)
{
	m_bDraw = true;
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CPolygon::~CPolygon()
{

}
//------------------------------------------------------------
//���_���W�̐ݒ�
//------------------------------------------------------------

void CPolygon::SetPos(D3DXVECTOR3 pos)
{
	m_Pos = pos;
	CScene::SetPos(pos);
	m_pos = pos;
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].pos = D3DXVECTOR3(pos.x - m_Scale.x, pos.y - m_Scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + m_Scale.x, pos.y - m_Scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - m_Scale.x, pos.y + m_Scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + m_Scale.x, pos.y + m_Scale.y, 0.0f);

	m_pVtxBuff->Unlock();

}
//=============================================================================
//�F�̐ݒ�
//=============================================================================
void CPolygon::SetCol(D3DXCOLOR col)
{
	m_col = col;
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	m_pVtxBuff->Unlock();

}
//=============================================================================
//������
//=============================================================================
HRESULT CPolygon::Init()
{
	CScene2D::BindTexture(m_Tex);
	CScene2D::Init();
	CScene2D::SetPos(m_pos, m_Scale);
	CScene2D::SetCol(m_col);
	return S_OK;
}

//=============================================================================
//�I��
//=============================================================================
void CPolygon::Uninit()
{
	CScene2D::Uninit();
}

//=============================================================================
//�X�V
//=============================================================================
void CPolygon::Update()
{
	CScene2D::Update();
}

//=============================================================================
//�`��
//=============================================================================
void CPolygon::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	if (m_bDraw == true)
	{
		CScene2D::Draw();
	}
}

//=============================================================================
//�N���G�C�g
//=============================================================================
CPolygon *CPolygon::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, D3DXCOLOR col, int nPriority)
{
	//�C���X�^���X����
	CPolygon *pPolygon = new CPolygon((CScene::OBJTYPE)nPriority);

	pPolygon->m_pos = pos;
	pPolygon->m_Scale = scale;
	pPolygon->m_Tex = texture;
	pPolygon->m_col = col;

	if (pPolygon != NULL)
	{
		pPolygon->Init();
	}

	return pPolygon;
}