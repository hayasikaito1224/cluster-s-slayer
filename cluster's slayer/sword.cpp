//=============================================
//sword�̃N���X
//=============================================
#include "sword.h"
#include "manager.h"
#include "Renderer.h"
#include "model.h"
#include "enemy.h"
#include "effect.h"
#include "game.h"
#include "player.h"
static const D3DXVECTOR3 HitCollisionPos = { 0.0f,50.0f,0.0f };//�U�������蔻��̈ʒu�ݒ�
static const float HitSize = 50.0f;//�U���̓����蔻��̑傫��
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
		CPlayer *pPlayer = CManager::GetGame()->GetPlayer();

		//�G�̏��������Ă��ē����蔻��̏���������
		//�G�Ƃ̓����蔻��
		CScene *pScene_Enemy = CScene::GetScene(CScene::OBJTYPE_ENEMY);
		while (pScene_Enemy != NULL)
		{
			CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
			//���S������擾
			bool bIsDeath = pEnemy->GetDeath();
			bool bNear = pEnemy->GetNearPlayer();
			//�G�������Ă�����
			if (!bIsDeath&& bNear)
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
						bool bRushAttack = pPlayer->GetCanRushAttack();
						if (bRushAttack)
						{
							pEnemy->SetRushAttack(true);
						}
						//�G�𒵂˂�����
						if (m_nCombo == 3)
						{
							pEnemy->SetGravity(14.0f);
							pEnemy->SetbKnockback(true);

						}
						//�G�ɓ������������n��
						pEnemy->SetbDamage(true);
						pEnemy->AddLife((int)-m_fPower);
						//�q�b�g�G�t�F�N�g
						std::random_device random;	// �񌈒�I�ȗ���������
						std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
						std::uniform_real_distribution<> randAng(-D3DX_PI, D3DX_PI);
						D3DXVECTOR3 EnemyVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						EnemyVec = EnemyPos - m_pos;			//�G�ƒe�̃x�N�g��
						D3DXVECTOR3 EnemyPosBody = {};
						D3DXVECTOR3 EnemyPosHead = {};
						if (pEnemy->GetParts(0) != nullptr)
						{
							EnemyPosBody = pEnemy->GetParts(0)->GetMaxPos();
							EnemyPosHead = pEnemy->GetParts(1)->GetMaxPos();
						}
						float fEnemyAng = atan2(EnemyVec.x, EnemyVec.z) + D3DX_PI;
						D3DXVECTOR3 Addmove = D3DXVECTOR3(
							sinf(fEnemyAng)*EnemyPosBody.x,
							EnemyPosHead.y / 2.0f,
							cosf(fEnemyAng)*EnemyPosBody.x);

						float fAng = (float)randAng(mt);

						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 1.0f,1.0f,0.0f },
						{ 1.0,1.0,1.0,0.5f }, false, 0.0f, 0.01f, true, CTexture::HitEffect, fAng, true);
						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 0.4f,0.2f,0.0f },
						{ 1.0,1.0,1.0,0.7f }, false, 0.0f, 0.015f, true, CTexture::HitEffect, fAng, true);

						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 1.5f,1.0f,0.0f },
						{ 1.0f,0.5f,0.0f,1.0f }, false, 0.0f, 0.03f, true, CTexture::Effect, fAng, false, true);
						CEffect::Create(Addmove + EnemyPos, { 0.0f,0.0f,0.0f }, { 1.5f,1.0f,0.0f },
						{ 1.0f,0.5f,0.0f,1.0f }, false, 0.0f, 0.03f, true, CTexture::Effect, fAng, false, true);
					}

				}

			}

			pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
		}
	}
}

//-----------------------------------------------
//�`��
//---------------------------------------------
void CSword::Draw()
{
	m_lastpos = { m_HitCollision.m_mtxWorld._41,m_HitCollision.m_mtxWorld._42 ,m_HitCollision.m_mtxWorld._43 };

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
//----------------------------------------------
//�����蔻��
//----------------------------------------------
bool CSword::IsCollision(const D3DXVECTOR3 & Hitpos, const float & fRadius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	D3DXVECTOR3 lastvec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��

	D3DXVECTOR3 pos = { m_HitCollision.m_mtxWorld._41,m_HitCollision.m_mtxWorld._42 ,m_HitCollision.m_mtxWorld._43 };
	vec = pos - Hitpos;
	lastvec = m_lastpos - Hitpos;
	float fLength = 0.0f;
	float fLastLength = 0.0f;

	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	fLastLength = sqrtf((lastvec.z*lastvec.z) + (lastvec.x*lastvec.x));
	float fCollisionRadius = HitSize + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius &&fLastLength > fCollisionRadius)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}
