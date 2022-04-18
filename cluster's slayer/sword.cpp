//=============================================
//sword�̃N���X
//=============================================
#include "sword.h"
#include "manager.h"
#include "Renderer.h"
#include "model.h"
static const D3DXVECTOR3 HitCollisionPos = { 0.0f,50.0f,0.0f };//�U�������蔻��̈ʒu�ݒ�
//---------------------------------------------
//�R���X�g���N�^
//---------------------------------------------
CSword::CSword() 
{
	m_bWeaponDraw = true;
	m_bCanHitCollision = false;
}

//-----------------------------------------------
//�f�X�g���N�^
//---------------------------------------------
CSword::~CSword()
{
}

//-----------------------------------------------
//������
//---------------------------------------------
HRESULT CSword::Init()
{
	if (!m_pWeapon)
	{
		//���탂�f���̐���
		m_pWeapon = CModel::Create(m_pos, m_rot, 15, CModel::TYPE_PLAYER);
		//������ǂ��Ɏ������邩�̐ݒ�
		m_pWeapon->SetParent(m_pParent);
		//�U�������蔻��̈ʒu�̐ݒ�
		m_HitCollision.m_pos = HitCollisionPos;
	}

	return S_OK;
}

//-----------------------------------------------
//�I��
//---------------------------------------------
void CSword::Uninit()
{
	CWeapon::Uninit();

}

//-----------------------------------------------
//�X�V
//---------------------------------------------
void CSword::Update()
{
	CWeapon::Update();
	//�U�������蔻�肪�I���Ȃ�
	if (m_bCanHitCollision)
	{
		//�G�̏��������Ă��ē����蔻��̏���������
	}
}

//-----------------------------------------------
//�`��
//---------------------------------------------
void CSword::Draw()
{
	CWeapon::Draw();
}
//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------

CSword * CSword::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CModel *pParent)
{
	CSword *pSword = nullptr;
	pSword = new CSword;
	pSword->m_pos = pos;
	pSword->m_rot = rot;
	pSword->m_pParent = pParent;
	pSword->Init();

	return pSword;
}
