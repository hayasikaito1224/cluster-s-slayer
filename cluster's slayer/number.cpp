//----------------------------------
//�i���o�[�̏���
//-----------------------------------
#include "number.h"
#include "main.h"
#include "scene3D.h"
#include "Renderer.h"
#include "manager.h"
#include "texture.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CNumber::CNumber()
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_Scale = { 0.0f,0.0f,0.0f };
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
	m_rot = { 0.0f,0.0f,0.0f };
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CNumber::~CNumber()
{

}
//---------------------------------------------------------------
//�C���X�^���X��������
//---------------------------------------------------------------
CNumber *CNumber::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& scale,CSmallScore *pParent)
{
	//�C���X�^���X����
	CNumber *pNumber = new CNumber;
	if (pNumber != NULL)
	{
		pNumber->m_pos = pos;
		pNumber->m_Scale = scale;
		pNumber->m_pParent = pParent;
		//�e�N�X�`���摜�̐ݒ�
		pNumber->m_pTexture = CManager::GetTexture()->GetTexture(CTexture::TIME);

		pNumber->Init();

	}

	return pNumber;
}

//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT CNumber::Init(void)
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

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	m_pVtxBuff->Unlock();


	return S_OK;
}

//=============================================================================
// �|���S���̏I������
//=============================================================================
void CNumber::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//=============================================================================
// �|���S���̍X�V����
//=============================================================================
void CNumber::Update(void)
{

	if (m_bUninit == true)
	{
		Uninit();
	}
}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CNumber::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxParent;//�e�̃}�g���b�N�X

								//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);
	//���C�g����
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//���e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	////�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);
	if (m_pParent)
	{
		mtxParent = m_pParent->GetMatrix();
	}
	else
	{
		//�ŐV�̃}�g���b�N�X���擾
		pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
	}

	//�Z�o�����e�p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���|�����킹��
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&mtxParent);

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
	//���e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

}
//-----------------------------------
//�ԍ����Z�b�g
//-----------------------------------
void CNumber::SetNumber(int nNumber)
{
	VERTEX_3D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̍X�V
	pVtx[0].tex = D3DXVECTOR2(0.1*nNumber, 0.0);
	pVtx[1].tex = D3DXVECTOR2(0.1 + 0.1*nNumber, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.1*nNumber, 1.0);
	pVtx[3].tex = D3DXVECTOR2(0.1 + 0.1*nNumber, 1.0);

	m_pVtxBuff->Unlock();

}


//=============================================================================
//�J���[�ύX
//=============================================================================
void CNumber::SetCol(D3DXCOLOR col)
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