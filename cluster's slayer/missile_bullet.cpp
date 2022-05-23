//-------------------------------------------
//�~�T�C���e�̏���
//------------------------------------------
#include "missile_bullet.h"
#include "manager.h"
#include "Renderer.h"
#include "Particle.h"
#include "enemy.h"
#include "PresetSetEffect.h"
#include "player.h"
#include "model.h"
static const float MoveSpeed = 12.0f;
static const int DeleteTime = 200;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CMissile_Bullet::CMissile_Bullet(OBJTYPE nPriority) :CScene(nPriority)
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_rot = { 0.0f,0.0f,0.0f };
	m_scale = { 0.0f,0.0f,0.0f };
	m_pMissileModel = nullptr;
}

//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CMissile_Bullet::~CMissile_Bullet()
{
}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CMissile_Bullet::Init(void)
{
	if (!m_pMissileModel)
	{
		m_pMissileModel = CModel::Create({0.0f,0.0f,0.0f}, { 0.0f,0.0f,0.0f }, 7, CModel::TYPE_OBJECT);
		m_pMissileModel->SetCanObjParent(false);
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CMissile_Bullet::Uninit(void)
{
	if(m_pMissileModel)
	{
		m_pMissileModel->Uninit();
		m_pMissileModel = nullptr;
	}
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CMissile_Bullet::Update(void)
{
	m_pos.y -= MoveSpeed;
	if (m_pos.y <= 0.0f)
	{
		//�G�Ƃ̓����蔻��
		CScene *pScene_Enemy = CScene::GetScene(CScene::OBJTYPE_ENEMY);
		while (pScene_Enemy != NULL)
		{
			CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
			//���S������擾
			bool bIsDeath = pEnemy->GetDeath();
			//�G�������Ă�����
			if (!bIsDeath)
			{
				D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
				int nSize = pEnemy->GetParts().size();
				if (nSize != 0)
				{
					float fRadius = pEnemy->GetParts(0)->GetMaxPos().x;
					bool bHitAttack = pEnemy->bHitAttack();
					//�G�ɍU���𓖂Ă���
					if (IsCollision(EnemyPos, fRadius) && !bHitAttack)
					{
						//�G�ɓ������������n��
						pEnemy->SetbDamage(true);
						pEnemy->AddLife(-m_nPower);

					}
				}
			}
			pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);

		}
		m_bUninit = true;

	}
	if (m_bUninit)
	{
		CPresetEffect::SetEffect3D(13, m_pos, {},{},{});
		CPresetEffect::SetEffect3D(14, m_pos, {},{},{});
		CPresetEffect::SetEffect3D(15, m_pos, {},{},{});
		CPresetEffect::SetEffect3D(12, m_pos, {}, D3DXVECTOR3(100.0f, 0.0f, 100.0f),true);

		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CMissile_Bullet::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^


	D3DXMATRIX mtxRotModel, mtxTransModel, mtxScaleModel;//�v�Z�p�}�g���b�N�X

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
	if (m_pMissileModel)
	{
		m_pMissileModel->SetParentMtx(m_mtxWorld);
		m_pMissileModel->Draw();
	}
}

//----------------------------------------------
//�����蔻��
//----------------------------------------------
bool CMissile_Bullet::IsCollision(const D3DXVECTOR3 & Hitpos, const float & fRadius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	D3DXVECTOR3 lastvec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��

	vec = m_pos - Hitpos;
	float fLength = 0.0f;
	float fLastLength = 0.0f;

	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	float fCollisionRadius = (m_fRadiusSize*2) + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}

//--------------------------------------------
//�`��
//--------------------------------------------
CMissile_Bullet * CMissile_Bullet::Create(const D3DXVECTOR3& pos, const float& fSize, const int& nPower)
{
	CMissile_Bullet *pRushAttack = NULL;
	pRushAttack = new CMissile_Bullet(OBJTYPE_EFFECT);
	pRushAttack->m_pos = pos;
	pRushAttack->m_nPower = nPower;
	pRushAttack->m_fRadiusSize = fSize;
	pRushAttack->Init();

	return pRushAttack;
}