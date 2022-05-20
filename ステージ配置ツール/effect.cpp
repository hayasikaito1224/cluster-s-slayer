#include "main.h"
#include "effect.h"
#include "manager.h"
#include "renderer.h"
#include "Scene3D.h"

CEffect::CEffect(OBJTYPE nPriority) : CScene(nPriority)
{
	m_col = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
}

CEffect::~CEffect()
{

}

//---------------------------------------------------
//�C���X�^���X����
//---------------------------------------------------
CEffect * CEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 m_move, D3DXVECTOR3 size, D3DXCOLOR col, bool bGravity, float fGravity, float ScaleSpeed, CTexture::Type type)
{//	�ʒu, �ړ���, �T�C�Y,�F, �������Ȃ�X�s�[�h
	//�C���X�^���X����
	CEffect *pEffect = new CEffect(OBJTYPE_EFFECT);
	pEffect->m_pos = pos;
	pEffect->m_size = size;
	pEffect->m_fScaleSpeed = ScaleSpeed;
	pEffect->m_move = m_move;
	pEffect->m_col = col;
	pEffect->m_TexType = type;
	pEffect->m_bGravity = bGravity;
	pEffect->m_fGravity = fGravity;
	if (pEffect != NULL)
	{
		//�摜�ǂݍ���
		pEffect->Init();
	}

	return pEffect;
}

//----------------------------------------------------
//����������
//-----------------------------------------------------
HRESULT CEffect::Init(CTexture::Type type)
{
	m_fRand = float(rand() %314/100.0f) - float(rand() % 314 + 314/100.0f);//z�������_���ړ��p
	return S_OK;
}

HRESULT CEffect::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
																	 // ���_����ݒ�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//�e�N�X�`���摜�̐ݒ�
	m_pTexture = CManager::GetTexture()->GetTexture(m_TexType);

	VERTEX_3D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].pos = D3DXVECTOR3(-m_size.x, +m_size.y, +m_size.z);
	pVtx[1].pos = D3DXVECTOR3(+m_size.x, +m_size.y, +m_size.z);
	pVtx[2].pos = D3DXVECTOR3(-m_size.x, -m_size.y, -m_size.z);
	pVtx[3].pos = D3DXVECTOR3(+m_size.x, -m_size.y, -m_size.z);

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
	Setpos(m_pos, m_size);

	return S_OK;
}

//---------------------------------------------------------
//�I������
//---------------------------------------------------------
void CEffect::Uninit()
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	Release();
}

void CEffect::Update()
{
	//Setpos(m_pos, m_size);//���_���̐ݒ�
	SetCol_E(m_col);

	
	//�ړ�����
	m_pos += m_move;

	//�t���[���񃋂��ƂɃT�C�Y���������Ȃ�
	m_size.x -= m_fScaleSpeed;
	m_size.y -= m_fScaleSpeed;

	//���邳��������
	m_col.a -= 0.01;
	//m_col.g += 0.005;
	if (m_pos.y < 0.0f)
	{
		m_move.y *= -1;
		m_move.y /= 1.2f;
	}
	if (m_bGravity == true)
	{
		m_move.y -= m_fGravity;
	}
	//X��Y�̃T�C�Y��0�ɂȂ��������
	if (m_size.x <= 0 && m_size.y <=0)
	{
		Uninit();
	}
	//���l��0�ȉ��ɂȂ����������
	if (m_col.a <= 0.0)
	{
		Uninit();
	}
}

void CEffect::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DXMATRIX mtxTrans;				//�ʒu�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxScale;				//�X�P�[���v�Z�p�}�g���b�N�X
										//���C�g����
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	//���e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//���Z�����ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	D3DXMatrixIdentity(&m_mtxWorld);//���[���h�}�g���b�N�X�̏�����


	pDevice->GetTransform(D3DTS_VIEW, &m_mtxView);//�r���[�}�g���b�N�X���擾


												  //�|���S�����J�����ɑ΂��Đ��ʂɌ�����
												  //�t�s������߂�	
	m_mtxWorld._11 = m_mtxView._11 * m_size.x;
	m_mtxWorld._12 = m_mtxView._21 * m_size.x;
	m_mtxWorld._13 = m_mtxView._31 * m_size.x;
	m_mtxWorld._21 = m_mtxView._12 * m_size.y;
	m_mtxWorld._22 = m_mtxView._22 * m_size.y;
	m_mtxWorld._23 = m_mtxView._32 * m_size.y;
	//m_mtxWorld._31 = m_mtxView._13;
	//m_mtxWorld._32 = m_mtxView._23;
	//m_mtxWorld._33 = m_mtxView._33;

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);


	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	pDevice->SetFVF(FVF_VERTEX_3D);			//���_�t�H�[�}�b�g�̐ݒ�

	pDevice->SetTexture(0, m_pTexture);	//�e�N�X�`���̐ݒ�

										//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
		0,					//�J�n���钸�_�̃C���f�b�N�X
		2);					//�`�悷��v���~�e�B�u��

	//���e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);

	//�ʏ퍇���ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);


}

void CEffect::SetCol_E(D3DXCOLOR col)
{
	VERTEX_3D *pVtx;
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);

	m_pVtxBuff->Unlock();

}

void CEffect::Setpos(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	CScene::SetPos(pos);
	CScene::SetScale(scale);
	m_pos = pos;
	m_size = scale;

	VERTEX_3D *pVtx;
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
	//�o�b�t�@�̐���
	pVtx[0].pos = D3DXVECTOR3(-m_size.x, m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_size.x, m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(-m_size.x, -m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_size.x, -m_size.y, 0.0f);

	m_pVtxBuff->Unlock();

}

