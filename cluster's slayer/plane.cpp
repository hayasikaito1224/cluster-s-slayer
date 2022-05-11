//---------------------------
// Author:�����G��
// ����(plane.cpp)
//---------------------------
#include "plane.h"
#include "manager.h"
#include "renderer.h"

CPlane::CPlane(int nPriority) : CScene3D::CScene3D(OBJTYPE::OBJTYPE_EFFECT)
{

}

CPlane::~CPlane()
{

}

//����������
HRESULT CPlane::Init(const int nPolygonType, int nTex)
{
	CScene3D::Init(nPolygonType, (CTexture::Type)nTex);
	return S_OK;
}

//�I������
void CPlane::Uninit()
{
	CScene3D::Uninit();
}

//�X�V����
void CPlane::Update()
{

}

//�`�揈��
void CPlane::Draw()
{
#if 0
	//LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	//D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X
	//pDevice = CManager::GetRenderer()->GetDevice();     //�f�o�C�X���擾����
	//													//���C���e�B���O�𖳎�����
	//pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	////�����ȕ�����`�悵�Ȃ��悤�ɂ���
	//pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	//pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	//pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	////���[���h�}�g���b�N�X�̏�����
	//D3DXMatrixIdentity(&m_mtxWorld);

	////�����𔽉f
	//D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	////�ʒu�𔽉f
	//D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);
	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	////���[���h�}�g���b�N�X�̐ݒ�
	//pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	////���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	//pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	////���_�t�H�[�}�b�g
	//pDevice->SetFVF(FVF_VERTEX_3D);
	//if (m_nTexType != -1)
	//{
	//	pDevice->SetTexture(0, m_pTexture[m_nTexType]);    //�e�N�X�`���̐ݒ�
	//}
	//else
	//{
	//	pDevice->SetTexture(0, NULL);    //�e�N�X�`���̐ݒ�
	//}
	//pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
	//	0,  //�J�n����n�_�̃C���f�b�N�X
	//	2); //�`�悷��v���~�e�B�u��

	////���C���e�B���O��L���ɂ���
	//pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	////�f�t�H���g�ɖ߂�
	//pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	//pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	//pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);
#endif

	CScene3D::Draw();
}

//�쐬
CPlane *CPlane::Create(const int nPolygonType, int nTex)
{
	CPlane *pPlane;
	pPlane = new CPlane(OBJTYPE::OBJTYPE_EFFECT);
	if (pPlane != NULL)
	{
		pPlane->Init(nPolygonType, nTex);
	}
	return pPlane;
}

//���G�t�F�N�g�ύX����
#if 0
void CPlane::SetSize(D3DXVECTOR3 size)
{
	//m_size = size;
	VERTEX_3D *pVtx; //���_���ւ̃|�C���^
					 //���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);
	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-size.x, size.y, size.z);
	pVtx[1].pos = D3DXVECTOR3(size.x, size.y, size.z);
	pVtx[2].pos = D3DXVECTOR3(-size.x, -size.y, -size.z);
	pVtx[3].pos = D3DXVECTOR3(size.x, -size.y, -size.z);
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

void CPlane::ChangeColor(D3DXCOLOR col)
{
	VERTEX_3D *pVtx; //���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);
	//���_���W�̐ݒ�
	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//=============================================================================
//�G�t�F�N�g�J���[�ύX
//=============================================================================
void CPlane::ColorChange(D3DCOLORVALUE color)
{
	VERTEX_3D*pVtx;//���_���ւ̃|�C���^

				   //���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_�̐F
	pVtx[0].col = D3DCOLOR_RGBA((int)color.r, (int)color.g, (int)color.b, (int)color.a);
	pVtx[1].col = D3DCOLOR_RGBA((int)color.r, (int)color.g, (int)color.b, (int)color.a);
	pVtx[2].col = D3DCOLOR_RGBA((int)color.r, (int)color.g, (int)color.b, (int)color.a);
	pVtx[3].col = D3DCOLOR_RGBA((int)color.r, (int)color.g, (int)color.b, (int)color.a);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}

//=============================================================================
//�G�t�F�N�g�T�C�Y�ύX
//=============================================================================
void CPlane::ChangeSize(D3DXVECTOR3 size)
{
	VERTEX_3D*pVtx;//���_���ւ̃|�C���^

				   //���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-size.x, size.y, size.z);
	pVtx[1].pos = D3DXVECTOR3(size.x, size.y, size.z);
	pVtx[2].pos = D3DXVECTOR3(-size.x, -size.y, -size.z);
	pVtx[3].pos = D3DXVECTOR3(size.x, -size.y, -size.z);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}

//=============================================================================
//���ʃG�t�F�N�g�i��]�j
//=============================================================================
void CPlane::SetPosField(D3DXVECTOR3 pos, D3DXVECTOR3 Size, float Rotate, float Rotate2)
{
	VERTEX_3D*pVtx;//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x + (cosf(Rotate2)) * Size.x, Size.y, pos.z + (sinf(Rotate))* Size.x);
	pVtx[1].pos = D3DXVECTOR3(pos.x + (sinf(Rotate))  * Size.x, Size.y, pos.z - (cosf(Rotate2))* Size.x);
	pVtx[2].pos = D3DXVECTOR3(pos.x - (sinf(Rotate))  * Size.x, Size.y, pos.z + (cosf(Rotate2))* Size.x);
	pVtx[3].pos = D3DXVECTOR3(pos.x - (cosf(Rotate2)) * Size.x, Size.y, pos.z - (sinf(Rotate))* Size.x);


	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();

}

//=============================================================================
//�r���{�[�h�T�C�Y�ύX
//=============================================================================
void CPlane::BillboardSize(float size)
{
	VERTEX_3D*pVtx;//���_���ւ̃|�C���^

				   //���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-size, size, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(size, size, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(-size, -size, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(size, -size, 0.0f);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}
#endif