//-------------------------------------------
//�u���b�N�z�[���̏���
//------------------------------------------
#include "bullet.h"
#include "manager.h"
#include "Renderer.h"
#include "Particle.h"
#include "enemy.h"
#include "model.h"
#include "3DPolygon.h"
#include "enemy.h"
const float Size = 10.0f;
const int MaxTime = 90;
const float MoveSpeed = 5.0f;
const int Power = 5;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CBullet::CBullet(OBJTYPE nPriority):CScene(nPriority)
{
	m_bUninit = false;
	m_pos = { 0.0f,0.0f,0.0f };
	m_rot = { 0.0f,0.0f,0.0f };
	m_bMoveDirection = true;
	m_pBullet = nullptr;
}

//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CBullet::~CBullet()
{

}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CBullet::Init(void)
{
	if (!m_pBullet)
	{
		m_pBullet = C3DPolygon::Create(m_pos, { 0.0f,0.0f,0.0f }, { Size, Size, 0.0f }, CTexture::FIRE, {1.0,1.0,1.0,1.0},true);
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CBullet::Uninit(void)
{
	if (m_pBullet)
	{
		m_pBullet->Uninit();
		m_pBullet = nullptr;
	}
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CBullet::Update(void)
{
	m_nTimer++;
	if (m_nTimer >= MaxTime)
	{
		m_bUninit = true;
	}
	m_pos.x += sinf(m_rot.y)*MoveSpeed;
	m_pos.z += cosf(m_rot.y)*MoveSpeed;

	if (m_pBullet)
	{
		m_pBullet->SetPos(m_pos);
	}
	//�G�̏��������Ă��ē����蔻��̏���������
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
					pEnemy->AddLife(-Power);
					m_bUninit = true;
				}

			}

		}

		pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
	}

	if (m_bUninit)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CBullet::Draw()
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


	//�Z�o�����e�p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���|�����킹��
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&m_mtxParent);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	if (m_pBullet)
	{
		m_pBullet->Draw();
	}

}

//--------------------------------------------
//�`��
//--------------------------------------------
CBullet * CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CBullet *pRushAttack = NULL;
	pRushAttack = new CBullet();
	pRushAttack->m_pos = pos;
	pRushAttack->m_rot = rot;
	pRushAttack->Init();

	return pRushAttack;
}
//----------------------------------------------
//�����蔻��
//----------------------------------------------
bool CBullet::IsCollision(const D3DXVECTOR3 & Hitpos, const float & fRadius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	D3DXVECTOR3 lastvec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��

	vec = m_pos - Hitpos;
	float fLength = 0.0f;
	float fLastLength = 0.0f;

	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	fLastLength = sqrtf((lastvec.z*lastvec.z) + (lastvec.x*lastvec.x));
	float fCollisionRadius = Size + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}
