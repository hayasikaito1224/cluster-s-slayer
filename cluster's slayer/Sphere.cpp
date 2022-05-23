//=============================================================================
// ���󏈗� [Sphere.cpp]
// Author : �����G��
//=============================================================================
#include "Sphere.h"
#include "manager.h"
#include "renderer.h"
#include "control.h"

//=============================================================================
// �}�N��
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSphere::CSphere(int nPriority) : CScene3D::CScene3D(OBJTYPE::OBJTYPE_EFFECT)
{
	m_mtxWorld = {};
	m_Pos = {};
	m_Rot = {};
	m_nVertical = {};
	m_nLine = {};
	m_nTex = {};
	m_fRadius = {};
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSphere::~CSphere(void)
{

}

//=============================================================================
// ������
//=============================================================================
HRESULT CSphere::Init(D3DXVECTOR3 pos, float rot, float fSize, int Vertical, int Line, CTexture::Type nTex, int Synthetic, float TexNum)
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();     //�f�o�C�X���擾����

	m_Pos = pos;
	m_Rot = rot;
	m_fRadius = fSize;
	m_nVertical = Vertical;
	m_nLine = Line;
	m_nTex = nTex;
	m_TexUV = D3DXVECTOR2(TexNum, TexNum);

	//�e�N�X�`���摜�̐ݒ�
	m_pTexture = CManager::GetTexture()->GetTexture(nTex);

	m_Synthetic = Synthetic;

	m_nVtx = ((m_nLine + 1) * (m_nVertical + 1));	//���_��
	m_nIdx = ((2 * m_nLine * (m_nVertical * 2)));	//�C���f�b�N�X
	m_Primithive = (2 * m_nLine * m_nVertical + (m_nVertical * 4) - 4);	//�v���~�e�B�u

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * m_nVtx,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx; //���_���ւ̃|�C���^
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);

	int nCntVtx = 0;	//���_�J�E���g

	//�c�̒��_�̍��W�ݒ�
	for (int nVertical = 0; nVertical < m_nVertical + 1; nVertical++)
	{
		//���̒��_�̍��W�ݒ�
		for (int nLine = 0; nLine < m_nLine + 1; nLine++, nCntVtx++)
		{
			//���_���W�p�x
			float fphi = (D3DX_PI * 2) / m_nVertical * nVertical;
			float ftheta = (D3DX_PI * 2) / m_nVertical * nLine;

			//���_���W
			pVtx[nCntVtx].pos = D3DXVECTOR3(
				m_Pos.x + m_fRadius * sinf(ftheta) * cosf(fphi),	//X
				m_Pos.y + m_fRadius * sinf(ftheta + D3DX_PI / 2),	//��(��)
				m_Pos.z + m_fRadius * sinf(ftheta) * sinf(fphi));	//z

			//�@���x�N�g���̐ݒ�
			pVtx[nCntVtx].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			//�e�N�X�`�����W
			pVtx[nCntVtx].tex = D3DXVECTOR2((m_TexUV.x / m_nLine * nLine), (m_TexUV.y / m_nVertical * nVertical));

		}
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD) * m_nIdx,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIdxBuff,
		NULL);

	WORD *pIdx; //�C���f�b�N�X���ւ̃|�C���^
	//�C���f�b�N�X�o�b�t�@�����b�N���A�ԍ��f�[�^�ւ̃|�C���^���擾
	m_pIdxBuff->Lock(0, 0, (void **)&pIdx, 0);

	//�C���f�b�N�X�ݒ�
	for (int nVertical = 0; nVertical < m_nVertical; nVertical++)
	{
		for (int nLine = 0; nLine < m_nLine + 1; nLine++)
		{
			pIdx[(m_nLine * 2 + 4) * nVertical + 0 + (nLine * 2)] = (nLine + (m_nLine + 1) + (m_nLine + 1) * nVertical);
			pIdx[(m_nLine * 2 + 4) * nVertical + 1 + (nLine * 2)] = (nLine + 0 + (m_nLine + 1) * nVertical);
		}
	}
	//�d���C���f�b�N�X
	for (int nDup = 0; nDup < m_nVertical - 1; nDup++)
	{
		pIdx[(m_nLine * 2 + 2) + 0 + nDup * (m_nLine * 2 + 4)] = (m_nLine + (m_nLine + 1) * nDup);
		pIdx[(m_nLine * 2 + 2) + 1 + nDup * (m_nLine * 2 + 4)] = ((m_nLine * 2 + 2)+ (m_nLine + 1) * nDup);
	}

	//�C���f�b�N�X�o�b�t�@���A�����b�N����
	m_pIdxBuff->Unlock();

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=============================================================================
// �I��
//=============================================================================
void CSphere::Uninit()
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	//�C���f�b�N�X�o�b�t�@�̔j��
	if (m_pIdxBuff != NULL)
	{
		m_pIdxBuff->Release();
		m_pIdxBuff = NULL;
	}
	Release();
}

//=============================================================================
// �X�V
//=============================================================================
void CSphere::Update()
{

	m_nLife--;
	if (m_nLife <= 0)
	{
		m_bUninit = true;
	}

	if (m_bUninit == true)
	{
		Uninit();
	}
}

//=============================================================================
// �`��
//=============================================================================
void CSphere::Draw()
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X
	pDevice = CManager::GetRenderer()->GetDevice();     //�f�o�C�X���擾����

	//Z�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	if (m_Synthetic == 0)
	{
		//���Z�����֌W
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}
	else if (m_Synthetic == 1)
	{
		//���Z�����̐ݒ�
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}
	//����ȊO�̐��l�͉��Z������
	else
	{
		//���Z�����֌W
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}

	//�A���t�@�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//�J�����O�I�t
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//�C���f�b�N�X�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(m_pIdxBuff);

	//���_�t�H�[�}�b�g
	pDevice->SetFVF(FVF_VERTEX_3D);
	pDevice->SetTexture(0, m_pTexture);    //�e�N�X�`���̐ݒ�
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		0,
		m_nVtx, //���_�̐�
		0,
		m_Primithive); //�`�悷��v���~�e�B�u��

	//�J�����O�I��
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//Z�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//�A���t�@�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);

	//�ʏ퍇���ɖ߂�(���Z����)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

}

//=============================================================================
// �F�Z�b�g
//=============================================================================
void CSphere::SetColor(D3DCOLORVALUE Color)
{
	VERTEX_3D *pVtx; //���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);

	//���_�̐F
	for (int Vtx = 0; Vtx < m_nVtx; Vtx++)
	{
		pVtx[Vtx].col = D3DCOLOR_RGBA((int)Color.r, (int)Color.g, (int)Color.b, (int)Color.a);
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

}

//=============================================================================
// �T�C�Y�Z�b�g
//=============================================================================
void CSphere::SetSize(D3DXVECTOR3 pos, float Size)
{
	m_fRadius = Size;
	m_Pos = pos;

	VERTEX_3D *pVtx; //���_���ւ̃|�C���^
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);

	int nCntVtx = 0;	//���_�J�E���g

	//�c�̒��_�̍��W�ݒ�
	for (int Vertical = 0; Vertical < m_nVertical + 1; Vertical++)
	{
		//���̒��_�̍��W�ݒ�
		for (int Line = 0; Line < m_nLine + 1; Line++, nCntVtx++)
		{
			//���_���W�p�x
			float fphi = (D3DX_PI * 2) / m_nVertical * Vertical;
			float ftheta = (D3DX_PI * 2) / m_nVertical * Line;

			//���_���W
			pVtx[nCntVtx].pos = D3DXVECTOR3(
				m_Pos.x + m_fRadius * sinf(ftheta) * cosf(fphi),	//X
				m_Pos.y + m_fRadius * sinf(ftheta + D3DX_PI / 2),	//��(��)
				m_Pos.z + m_fRadius * sinf(ftheta) * sinf(fphi));	//z
		}
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

}

//=============================================================================
// �e�N�X�`��UV���W�Z�b�g
//=============================================================================
void CSphere::SetTexUV(D3DXVECTOR2 TexUV)
{
	VERTEX_3D *pVtx; //���_���ւ̃|�C���^

	m_TexMoveUV += TexUV;


	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);

	int nCntVtx = 0;	//���_�J�E���g

						//�c�̒��_�̍��W�ݒ�
	for (int Vertical = 0; Vertical < m_nVertical + 1; Vertical++)
	{
		//���̒��_�̍��W�ݒ�
		for (int Line = 0; Line < m_nLine + 1; Line++, nCntVtx++)
		{
			//�e�N�X�`�����W
			pVtx[nCntVtx].tex = D3DXVECTOR2((m_TexUV.x / m_nLine * Line) + m_TexMoveUV.x,
				(m_TexUV.y / m_nVertical * Vertical) + m_TexMoveUV.y);
		}
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

}

//=============================================================================
// �e�N�X�`��UV���W�Z�b�g
//=============================================================================
void CSphere::SetAnimTexUV(D3DXVECTOR2 TexPattern)
{
	VERTEX_3D *pVtx; //���_���ւ̃|�C���^

	m_PatternUV = TexPattern;

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void **)&pVtx, 0);

	int nCntVtx = 0;	//���_�J�E���g

						//�c�̒��_�̍��W�ݒ�
	for (int Vertical = 0; Vertical < m_nVertical + 1; Vertical++)
	{
		//���̒��_�̍��W�ݒ�
		for (int Line = 0; Line < m_nLine + 1; Line++, nCntVtx++)
		{
			//�e�N�X�`�����W
			pVtx[nCntVtx].tex = D3DXVECTOR2(
				(m_TexUV.x / m_nLine * Line) + m_PatternUV.x + m_TexMoveUV.x,
				(m_TexUV.y / m_nVertical * Vertical) + m_PatternUV.y + m_TexMoveUV.y);
		}
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

}
