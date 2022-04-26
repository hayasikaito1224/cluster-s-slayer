//--------------------------------------------
//�X�L���ǌ��̏���
//�쐬�ҁF��
//--------------------------------------------
#include "rushattack.h"
#include "game.h"
#include "player.h"
#include "model.h"
#include "Renderer.h"
#include "manager.h"
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CRushAttack::CRushAttack(OBJTYPE nPriority): CScene(nPriority)
{
	m_pRushSword = nullptr;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CRushAttack::~CRushAttack()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CRushAttack::Init(void)
{
	if (!m_pRushSword)
	{
		m_pRushSword = CModel::Create({0.0f,0.0f,0.0f}, m_rot, 15, CModel::TYPE_PLAYER);
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CRushAttack::Uninit(void)
{
	if (m_pRushSword)
	{
		m_pRushSword->Uninit();
		m_pRushSword = nullptr;
	}
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CRushAttack::Update(void)
{
	//�������肪�I���Ȃ�
	if (m_bIsDeath)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CRushAttack::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X

										  //�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//������ݒ�
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//�����𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);

	//�ʒu��ݒ�
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	//�ʒu�𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	if (m_pRushSword)
	{
		m_pRushSword->Draw();
	}

}

void CRushAttack::UpperAttack()
{

}

CRushAttack * CRushAttack::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CRushAttack *pRushAttack = NULL;
	pRushAttack = new CRushAttack(OBJTYPE_MODEL);
	pRushAttack->m_pos = pos;
	pRushAttack->m_rot = rot;
	pRushAttack->Init();

	return pRushAttack;
}

