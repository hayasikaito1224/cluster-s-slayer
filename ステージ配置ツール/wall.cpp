#include "main.h"
#include "manager.h"
#include "scene.h"
#include "renderer.h"
#include "texture.h"	
#include "Scene3D.h"
#include "wall.h"
//==================================
//�R���X�g���N�^
//==================================

CWall::CWall(OBJTYPE nPriority) :CScene3D(nPriority)
{
	m_WallData.m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_pIdxBuffWall = NULL;
	m_WallData.m_nMax_Vtx_X = 0;
	m_WallData.m_nMax_Vtx_Y = 0;
	m_nVtx_Num_Max = 0;
	m_nIdx_Num_Max = 0;
	m_nPoly_Num_Max = 0;
	m_fHalfWidth = 0.0f;
	m_fHalfDepth = 0.0f;
	m_vtxMax = D3DXVECTOR3(-1000.0f, -1000.0f, -1000.0f);
	m_vtxMin = D3DXVECTOR3(1000.0f, 1000.0f, 1000.0f);

}
//==================================
//�f�X�g���N�^
//==================================

CWall::~CWall()
{

}

//------------------------------------------------------------------------------------------------
//�C���X�^���X��������(�ʒu�A�傫���A�p�x�AX���̃u���b�N���AZ���̃u���b�N���A�\��e�N�X�`���̎��)
//-------------------------------------------------------------------------------------------------
CWall *CWall::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, int nNum_X, int nNum_Y, CTexture::Type Tex)
{
	//�C���X�^���X����
	CWall *pField = new CWall();

	pField->m_pos = pos;
	pField->m_WallData.m_InitSize = size;
	pField->m_WallData.m_size = D3DXVECTOR3(size.x*nNum_X, size.y*nNum_Y, size.z);

	pField->m_rot.y = rot.y;
	pField->m_fHalfWidth = pField->m_WallData.m_size.x / 2.0f;
	pField->m_fHalfDepth = pField->m_WallData.m_size.y / 2.0f;
	pField->m_WallData.m_nMax_Vtx_X = nNum_X;
	pField->m_WallData.m_nMax_Vtx_Y = nNum_Y;
	pField->m_pTexture = CManager::GetTexture()->GetTexture(Tex);

	if (pField != NULL)
	{
		pField->Init();
	}

	return pField;
}
//==================================
//�e�N�X�`���𓮂���
//==================================

void CWall::SetMoveTex(float fSpeedX, float fSpeedY)
{
	m_MoveTexX = fSpeedX;
	m_MoveTexY = fSpeedY;
	//-----------------------------
	//���_���
	//-----------------------------
	VERTEX_3D *pVtx;		//���_���ւ̃|�C���^

							//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nVtxNum = 0;
	for (int nCntY = 0; nCntY < m_WallData.m_nMax_Vtx_Y + 1; nCntY++)
	{
		for (int nCntX = 0; nCntX < m_WallData.m_nMax_Vtx_X + 1; nCntX++, nVtxNum++)
		{
			pVtx[nVtxNum].tex = D3DXVECTOR2(0.0f + (1.0f * nCntX) + m_MoveTexX, 0.0f + (1.0f * nCntY) + m_MoveTexX);
		}
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

}
//==================================
//�F��ݒ�
//==================================

void CWall::SetCol(float fAlpha)
{
	//-----------------------------
	//���_���
	//-----------------------------
	VERTEX_3D *pVtx;		//���_���ւ̃|�C���^

							//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nVtxNum = 0;
	for (int nCntY = 0; nCntY < m_WallData.m_nMax_Vtx_Y + 1; nCntY++)
	{
		for (int nCntX = 0; nCntX < m_WallData.m_nMax_Vtx_X + 1; nCntX++, nVtxNum++)
		{
			pVtx[nVtxNum].col = D3DXCOLOR(1.0, 1.0, 1.0, fAlpha);
		}
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

}
//==================================
//������
//==================================

HRESULT CWall::Init(void)
{
	m_nVtx_Num_Max = (m_WallData.m_nMax_Vtx_X + 1)*(m_WallData.m_nMax_Vtx_Y + 1);
	m_nIdx_Num_Max = (m_WallData.m_nMax_Vtx_X + 1)*(m_WallData.m_nMax_Vtx_Y + 1) + (m_WallData.m_nMax_Vtx_Y - 1)*(m_WallData.m_nMax_Vtx_X + 3);
	m_nPoly_Num_Max = 2 * m_WallData.m_nMax_Vtx_X * m_WallData.m_nMax_Vtx_Y + (m_WallData.m_nMax_Vtx_Y * 4) - 4;

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
																	 //�e�N�X�`���摜�̐ݒ�

																	 //�p�x����~�����ɕϊ�����
																	 //���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * m_nVtx_Num_Max,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);
	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD)* m_nIdx_Num_Max,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIdxBuffWall,
		NULL);
	//-----------------------------
	//���_���
	//-----------------------------
	VERTEX_3D *pVtx;		//���_���ւ̃|�C���^

							//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nVtxNum = 0;
	for (int nCntY = 0; nCntY < m_WallData.m_nMax_Vtx_Y + 1; nCntY++)
	{
		for (int nCntX = 0; nCntX < m_WallData.m_nMax_Vtx_X + 1; nCntX++, nVtxNum++)
		{

			pVtx[nVtxNum].pos = D3DXVECTOR3(
				-m_fHalfWidth + (((m_fHalfWidth * 2) / m_WallData.m_nMax_Vtx_X)*nCntX),
				m_fHalfDepth - (((m_fHalfDepth * 2) / m_WallData.m_nMax_Vtx_Y)*nCntY),
				0.0f);

			pVtx[nVtxNum].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
			pVtx[nVtxNum].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[nVtxNum].tex = D3DXVECTOR2(0.0f + (1.0f * nCntX) + m_MoveTexX, 0.0f + (1.0f * nCntY) + m_MoveTexX);
			if (m_vtxMax.x <= pVtx[nVtxNum].pos.x)
			{
				m_vtxMax.x = pVtx[nVtxNum].pos.x;
			}
			//���̍ŏ��l�̔�r
			else if (m_vtxMin.x >= pVtx[nVtxNum].pos.x)
			{
				m_vtxMin.x = pVtx[nVtxNum].pos.x;
			}
			//y�̍ő�l�̔�r
			if (m_vtxMax.y <= pVtx[nVtxNum].pos.y)
			{
				m_vtxMax.y = pVtx[nVtxNum].pos.y;
			}
			//y�̍ŏ��l�̔�r
			else if (m_vtxMin.y >= pVtx[nVtxNum].pos.y)
			{
				m_vtxMin.y = pVtx[nVtxNum].pos.y;
			}
			//z�̍ő�l�̔�r
			if (m_vtxMax.z <= pVtx[nVtxNum].pos.z)
			{
				m_vtxMax.z = pVtx[nVtxNum].pos.z;
			}
			//z�̍ŏ��l�̔�r
			else if (m_vtxMin.z >= pVtx[nVtxNum].pos.z)
			{
				m_vtxMin.z = pVtx[nVtxNum].pos.z;
			}

		}
	}
	nVtxNum = 0;
	//�����i��ʁj
	m_vtx[0].vtx = D3DXVECTOR3(
		m_vtxMin.x,
		m_vtxMin.y,
		m_vtxMax.z);
	//�E���i��ʁj
	m_vtx[1].vtx = D3DXVECTOR3(
		m_vtxMax.x,
		m_vtxMin.y,
		m_vtxMax.z);
	//���O�i��ʁj
	m_vtx[2].vtx = D3DXVECTOR3(
		m_vtxMin.x,
		m_vtxMin.y,
		m_vtxMin.z);
	//�E�O�i��ʁj
	m_vtx[3].vtx = D3DXVECTOR3(
		m_vtxMax.x,
		m_vtxMin.y,
		m_vtxMin.z);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
	//----------------------------
	//�C���f�b�N�X���
	//----------------------------
	WORD *pIdx;			//�C���f�b�N�X���ւ̃|�C���^

						//�C���f�b�N�X�o�b�t�@�����b�N���A�ԍ��f�[�^�ւ̃|�C���^���擾
	m_pIdxBuffWall->Lock(0, 0, (void**)&pIdx, 0);
	//�p���ȊO�̒��_
	for (int nCntY = 0; nCntY < m_WallData.m_nMax_Vtx_Y; nCntY++)
	{
		for (int nCntX = 0; nCntX < m_WallData.m_nMax_Vtx_X + 1; nCntX++)
		{
			pIdx[(nCntX * 2) + 0 + ((m_WallData.m_nMax_Vtx_X + 2) * 2) * nCntY] = ((m_WallData.m_nMax_Vtx_X + 1) + nCntX) + ((m_WallData.m_nMax_Vtx_X + 1) * nCntY);
			pIdx[(nCntX * 2) + 1 + ((m_WallData.m_nMax_Vtx_X + 2) * 2) * nCntY] = (0 + nCntX) + ((m_WallData.m_nMax_Vtx_X + 1) * nCntY);
		}
	}
	//�p���̒��_
	for (int nCntY = 0; nCntY < m_WallData.m_nMax_Vtx_Y - 1; nCntY++)
	{
		pIdx[(((m_WallData.m_nMax_Vtx_X + 1) * 2 + 0) * (nCntY + 1)) + (2 * nCntY)] = m_WallData.m_nMax_Vtx_X + ((m_WallData.m_nMax_Vtx_X + 1) * nCntY);
		pIdx[(((m_WallData.m_nMax_Vtx_X + 1) * 2 + 1) * (nCntY + 1)) + (1 * nCntY)] = (m_WallData.m_nMax_Vtx_X * 2 + 2) + ((m_WallData.m_nMax_Vtx_X + 1) * nCntY);
	}
	//�C���f�b�N�X�o�b�t�@���A�����b�N����
	m_pIdxBuffWall->Unlock();
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CWall::Uninit(void)
{

	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̔j��
	if (m_pIdxBuffWall != NULL)
	{
		m_pIdxBuffWall->Release();
		m_pIdxBuffWall = NULL;
	}

	Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CWall::Update(void)
{

}
//=======================================================================
//�`�揈��
//=======================================================================
void CWall::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X

								//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	////�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);
	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���Ńo�X�̂Ł[�����Ƃ�[�ނɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));
	//�C���f�b�N�X�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(m_pIdxBuffWall);

	pDevice->SetFVF(FVF_VERTEX_3D);//���_�t�H�[�}�b�g�̐ݒ�

	pDevice->SetTexture(0, m_pTexture);
	//�|���S���̕`��
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,					//�v���~�e�B�u�̎��
		0,									//�C���f�b�N�X�o�b�t�@�̊J�n�n�_����ŏ��̃C���f�b�N�X�܂ł̃I�t�Z�b�g
		m_nVtx_Num_Max,	//�`��Ŏg�p�����ŏ��̒��_�ԍ�
		(m_WallData.m_nMax_Vtx_X + 1)*(m_WallData.m_nMax_Vtx_Y + 1),		//���_�̐�
		0,	//�C���f�b�N�X�z��̓ǂݎ����J�n����ʒu
		m_nPoly_Num_Max);	//�O�p�`�|���S���̐�

}

