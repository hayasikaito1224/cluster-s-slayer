//=============================================
//sword�̃N���X
//=============================================
#include "damage_collision.h"
#include "manager.h"
#include "Renderer.h"
#include "model.h"
#include "enemy.h"
#include "effect.h"
#include "game.h"
#include "player.h"
#include "Particle.h"
//---------------------------------------------
//�R���X�g���N�^
//---------------------------------------------
CDamage_Collision::CDamage_Collision()
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_lastpos = { 0.0f,0.0f,0.0f };
	m_rot = { 0.0f,0.0f,0.0f };
	m_fSize = 0.0f;
}

//-----------------------------------------------
//�f�X�g���N�^
//---------------------------------------------
CDamage_Collision::~CDamage_Collision()
{
}

//-----------------------------------------------
//������
//---------------------------------------------
HRESULT CDamage_Collision::Init()
{

	return S_OK;
}

//-----------------------------------------------
//�I��
//---------------------------------------------
void CDamage_Collision::Uninit()
{

}

//-----------------------------------------------
//�X�V
//---------------------------------------------
void CDamage_Collision::Update()
{
}

//-----------------------------------------------
//�`��
//---------------------------------------------
void CDamage_Collision::Draw()
{
	//�O��̈ʒu���̕ۑ�
	m_lastpos = { m_mtxWorld._41,m_mtxWorld._42 ,m_mtxWorld._43 };

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxParent;//�e�̃}�g���b�N�X

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

	//�����蔻��ɕ���̃}�g���b�N�X��ݒ�
	if (m_pParent != nullptr)
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


}
//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------
CDamage_Collision * CDamage_Collision::Create(const D3DXVECTOR3 pos,const float fSize,CModel *pParent)
{
	CDamage_Collision *pSword = nullptr;
	pSword = new CDamage_Collision;
	pSword->m_pos = pos;
	pSword->m_fSize = fSize;
	pSword->m_pParent = pParent;
	pSword->Init();

	return pSword;
}
//----------------------------------------------
//�����蔻��
//----------------------------------------------
bool CDamage_Collision::IsCollision(const D3DXVECTOR3 & Hitpos, const float & fRadius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	D3DXVECTOR3 lastvec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��

	D3DXVECTOR3 pos = { m_mtxWorld._41,m_mtxWorld._42 ,m_mtxWorld._43 };
	vec = pos - Hitpos;
	lastvec = m_lastpos - Hitpos;
	float fLength = 0.0f;
	float fLastLength = 0.0f;

	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	fLastLength = sqrtf((lastvec.z*lastvec.z) + (lastvec.x*lastvec.x));
	float fCollisionRadius = m_fSize + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius /*&&fLastLength > fCollisionRadius*/)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}
