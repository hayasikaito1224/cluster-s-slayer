//=============================================
//����̃N���X
//=============================================
#include "weapon.h"
#include "manager.h"
#include "Renderer.h"
#include "model.h"
#include "Particle.h"

//---------------------------------------------
//�R���X�g���N�^
//---------------------------------------------
CWeapon::CWeapon()
{
	m_bWeaponDraw = true;
	m_bIsHit = false;
	m_bCanHitCollision = false;
	m_pWeapon = nullptr;
}

//-----------------------------------------------
//�f�X�g���N�^
//---------------------------------------------
CWeapon::~CWeapon()
{
}

//-----------------------------------------------
//������
//---------------------------------------------
HRESULT CWeapon::Init()
{
	return S_OK;
}

//-----------------------------------------------
//�I��
//---------------------------------------------
void CWeapon::Uninit()
{
	if (m_pWeapon)
	{
		m_pWeapon->Uninit();
		m_pWeapon = nullptr;
	}
}

//-----------------------------------------------
//�X�V
//---------------------------------------------
void CWeapon::Update()
{
	//�U�������蔻�肪�I���Ȃ�
	if (m_bCanHitCollision)
	{
		//�����蔻��̈ʒu�̊m�F
		CParticle *pParticle = new CParticle;
		pParticle->PlayRandomCircle({ m_HitCollision.m_mtxWorld._41, m_HitCollision.m_mtxWorld._42, m_HitCollision.m_mtxWorld._43 }, CParticle::CIRCLEPARTICLE);

	}
}

//-----------------------------------------------
//�`��
//---------------------------------------------
void CWeapon::Draw()
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

	//���f���̕`��
	if (m_bWeaponDraw)
	{
		m_pWeapon->Draw();
	}

	//�U�������蔻��̏��ݒ�
	if (m_bCanHitCollision)
	{
		HItCollisionSet();
	}

	//�O��̈ʒu���̕ۑ�
	m_lastpos = m_pos;

}
//-----------------------------------------------
//�����蔻��̈ʒu����ݒ�
//--------------------------------------------
void CWeapon::HItCollisionSet()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxParent;//�e�̃}�g���b�N�X

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_HitCollision.m_mtxWorld);

	//������ݒ�
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_HitCollision.m_rot.y, m_HitCollision.m_rot.x, m_HitCollision.m_rot.z);

	//�����𔽉f
	D3DXMatrixMultiply(&m_HitCollision.m_mtxWorld, &m_HitCollision.m_mtxWorld, &mtxRotModel);

	//�ʒu��ݒ�
	D3DXMatrixTranslation(&mtxTransModel, m_HitCollision.m_pos.x, m_HitCollision.m_pos.y, m_HitCollision.m_pos.z);

	//�ʒu�𔽉f
	D3DXMatrixMultiply(&m_HitCollision.m_mtxWorld, &m_HitCollision.m_mtxWorld, &mtxTransModel);

	//�����蔻��ɕ���̃}�g���b�N�X��ݒ�
	if (m_pWeapon != nullptr)
	{
		mtxParent = m_pWeapon->GetMatrix();
	}
	else
	{
		//�ŐV�̃}�g���b�N�X���擾
		pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
	}

	//�Z�o�����e�p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���|�����킹��
	D3DXMatrixMultiply(&m_HitCollision.m_mtxWorld,
		&m_HitCollision.m_mtxWorld,
		&mtxParent);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_HitCollision.m_mtxWorld);
}
//-----------------------------------------------
//�����蔻��̈ʒu����ݒ�i�����������̈ʒu���A�����������̓����蔻��̑傫���j
//--------------------------------------------
bool CWeapon::HitSet(D3DXVECTOR3 * Hitpos, const float& HitSize)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	vec = *Hitpos - m_HitCollision.m_pos;
	float fLength = 0.0f;
	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	//�����蔻��̑傫�������߂�
	float fCollisionRadius = m_fHitSize + HitSize;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}
