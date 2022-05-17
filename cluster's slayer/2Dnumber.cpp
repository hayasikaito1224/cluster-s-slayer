//----------------------------------
//�i���o�[�̏���
//-----------------------------------
#include "2Dnumber.h"
#include "main.h"
#include "scene2D.h"
#include "Renderer.h"
#include "manager.h"
#include "texture.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
C2DNumber::C2DNumber()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
C2DNumber::~C2DNumber()
{

}
//---------------------------------------------------------------
//�C���X�^���X��������
//---------------------------------------------------------------
C2DNumber *C2DNumber::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& scale)
{
	//�C���X�^���X����
	C2DNumber *pNumber = new C2DNumber;
	if (pNumber != NULL)
	{
		pNumber->m_pos = pos;
		pNumber->m_Scale = scale;

		pNumber->Init();

	}

	return pNumber;
}

//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT C2DNumber::Init(void)
{

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

																	 // ���_����ݒ�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);
	m_bUninit = false;

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_Scale.x, m_pos.y - m_Scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_Scale.x, m_pos.y - m_Scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_Scale.x, m_pos.y + m_Scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_Scale.x, m_pos.y + m_Scale.y, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

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
void C2DNumber::Uninit(void)
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
void C2DNumber::Update(void)
{

	if (m_bUninit == true)
	{
		Uninit();
	}
}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void C2DNumber::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

																	 // ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, CManager::GetTexture()->GetTexture(CTexture::TIME));

	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		2);

}
//-----------------------------------
//�ԍ����Z�b�g
//-----------------------------------
void C2DNumber::SetNumber(int nNumber)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̍X�V
	pVtx[0].tex = D3DXVECTOR2(0.1*nNumber, 0.0);
	pVtx[1].tex = D3DXVECTOR2(0.1 + 0.1*nNumber, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.1*nNumber, 1.0);
	pVtx[3].tex = D3DXVECTOR2(0.1 + 0.1*nNumber, 1.0);

	m_pVtxBuff->Unlock();

}
//--------------------------
//�ʒu
//----------------------------
void C2DNumber::SetPos(D3DXVECTOR3 pos)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̍X�V
	pVtx[0].pos = D3DXVECTOR3(m_pos.x + pos.x - m_Scale.x, m_pos.y + pos.y - m_Scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + pos.x + m_Scale.x, m_pos.y + pos.y - m_Scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + pos.x - m_Scale.x, m_pos.y + pos.y + m_Scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + pos.x + m_Scale.x, m_pos.y + pos.y + m_Scale.y, 0.0f);

	m_pVtxBuff->Unlock();

}

//=============================================================================
//�J���[�ύX
//=============================================================================
void C2DNumber::SetCol(D3DXCOLOR col)
{

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;

	m_pVtxBuff->Unlock();

}