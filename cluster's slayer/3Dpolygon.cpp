//=============================================================================
//
// Polygon����
//
//=============================================================================
#include "3Dpolygon.h"
#include "manager.h"
#include "Renderer.h"
#include "scene3D.h"
#include "model.h"
//=============================================================================
//�R���X�g���N�^
//=============================================================================
C3DPolygon::C3DPolygon()
{
	m_bDraw = true;
	m_bCanCulling = false;
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
C3DPolygon::~C3DPolygon()
{

}

//=============================================================================
//������
//=============================================================================
HRESULT C3DPolygon::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	// ���_����ݒ�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].pos = D3DXVECTOR3(-m_Scale.x, m_Scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_Scale.x, m_Scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(-m_Scale.x, -m_Scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_Scale.x, -m_Scale.y, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	m_pVtxBuff->Unlock();


	return S_OK;

}

//=============================================================================
//�I��
//=============================================================================
void C3DPolygon::Uninit()
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//=============================================================================
//�X�V
//=============================================================================
void C3DPolygon::Update()
{
}

//=============================================================================
//�`��
//=============================================================================
void C3DPolygon::Draw(D3DXMATRIX ParentMtx)
{
	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxParent = ParentMtx;//�e�̃}�g���b�N�X
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);
	//���C�g����
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	//�ォ�珑�����ނ��Ƃ����Ȃ��悤�ɂ���
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	if (m_bCanCulling == true)
	{
		pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// �J�����O������
	}
	////�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//�y�A�����g�ݒ肪�L���Ȃ�y�A�����g����
	if (m_bCanParent)
	{
		if (m_pParentModel)
		{
			mtxParent = m_pParentModel->GetMatrix();
		}

		//�Z�o�����e�p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���|�����킹��
		D3DXMatrixMultiply(&m_mtxWorld,
			&m_mtxWorld,
			&mtxParent);

	}

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���Ńo�X�̂Ł[�����Ƃ�[�ނɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));
	pDevice->SetFVF(FVF_VERTEX_3D);//���_�t�H�[�}�b�g�̐ݒ�

	pDevice->SetTexture(0, m_pTexture);
	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		2);
	//���ɖ߂�
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	//�J�����O���锻��Ȃ�
	if (m_bCanCulling == true)
	{
		// �J�����O������
		pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	}
}

//=============================================================================
//�N���G�C�g
//=============================================================================
C3DPolygon *C3DPolygon::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot, const D3DXVECTOR3& scale, const int& nTexture, const D3DXCOLOR& col)
{
	//�C���X�^���X����
	C3DPolygon *pPolygon = new C3DPolygon;

	pPolygon->m_pos = pos;
	pPolygon->m_Scale = scale;
	pPolygon->m_rot = rot;
	pPolygon->m_pTexture = CManager::GetTexture()->GetTexture((CTexture::Type)nTexture);
	pPolygon->m_col = col;

	if (pPolygon != NULL)
	{
		pPolygon->Init();
	}

	return pPolygon;
}
//=============================================================================
//�J���[�ύX
//=============================================================================
void C3DPolygon::SetCol(D3DXCOLOR col)
{
	m_col = col;
	VERTEX_3D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;

	m_pVtxBuff->Unlock();

}