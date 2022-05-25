//-------------------------------------------
//�u���b�N�z�[���̏���
//------------------------------------------
#include "assistcrystal_model.h"
#include "manager.h"
#include "Renderer.h"
#include "Particle.h"
#include "enemy.h"
#include "model.h"
#include "bullet.h"
#include "game.h"	
#include "player.h"

const float MinPos = 10.0f;
const float MaxPos = 13.0f;
const float MoveSpeed = 0.05f;
const int TimerMax = 60;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CAssistCrystal_Model::CAssistCrystal_Model()
{
	m_Crustal = nullptr;
	m_TopFrame = nullptr;
	m_BottomFrame = nullptr;
	m_bUninit = false;
	m_pos = { 0.0f,0.0f,0.0f };
	m_rot = { 0.0f,0.0f,0.0f };
	m_bMoveDirection = true;
	m_nBulletTimer = 0;
	m_nLaunchInterval = TimerMax;
}

//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CAssistCrystal_Model::~CAssistCrystal_Model()
{
}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CAssistCrystal_Model::Init(void)
{
	if (!m_Crustal)
	{
		m_Crustal = CModel::Create({ 0.0f,0.0f,0.0f }, { 0.0f,0.0f,0.0f }, 5, CModel::TYPE_OBJECT);
	}
	if (!m_TopFrame)
	{
		m_TopFrame = CModel::Create({ 0.0f,MinPos,3.0f }, { 0.0f,0.0f,0.0f }, 6, CModel::TYPE_OBJECT);
		m_TopFrame->SetParent(m_Crustal);
	}
	if (!m_BottomFrame)
	{
		m_BottomFrame = CModel::Create({ 0.0f,-MinPos,3.0f }, { 0.0f,0.0f,D3DXToRadian(180) }, 6, CModel::TYPE_OBJECT);
		m_BottomFrame->SetParent(m_Crustal);
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CAssistCrystal_Model::Uninit(void)
{
	if (m_Crustal)
	{
		m_Crustal->Uninit();
		m_Crustal = nullptr;
	}
	if (m_TopFrame)
	{
		m_TopFrame->Uninit();
		m_TopFrame = nullptr;
	}
	if (m_BottomFrame)
	{
		m_BottomFrame->Uninit();
		m_BottomFrame = nullptr;
	}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CAssistCrystal_Model::Update(void)
{
	if (m_Crustal)
	{
		D3DXVECTOR3 rot = m_Crustal->GetRot();
		rot.y += 0.02f;

		m_Crustal->SetRot(rot);
	}
	if (m_TopFrame)
	{
		D3DXVECTOR3 rot = m_TopFrame->GetRot();
		rot.y -= 0.02f;

		m_TopFrame->SetRot(rot);

		D3DXVECTOR3 pos = m_TopFrame->GetPos();
		if (m_bMoveDirection)
		{
			pos.y += MoveSpeed;
		}
		else
		{
			pos.y -= MoveSpeed;
		}
		if (pos.y >= MaxPos)
		{
			m_bMoveDirection = false;
		}
		if (pos.y <= MinPos)
		{
			m_bMoveDirection = true;
		}
		m_TopFrame->SetPos(pos);
	}
	if (m_BottomFrame)
	{
		D3DXVECTOR3 rot = m_BottomFrame->GetRot();
		rot.y -= 0.02f;

		m_BottomFrame->SetRot(rot);

		D3DXVECTOR3 pos = m_BottomFrame->GetPos();
		if (m_bMoveDirection)
		{
			pos.y -= MoveSpeed;
		}
		else
		{
			pos.y += MoveSpeed;
		}

		m_BottomFrame->SetPos(pos);
	}
	m_nBulletTimer++;
	if (m_nBulletTimer >= m_nLaunchInterval)
	{
		m_nBulletTimer = 0;
		D3DXVECTOR3 Enemypos = CManager::GetGame()->GetPlayer()->GetNearEnemyPos();
		D3DXVECTOR3 pos = { m_mtxWorld._41,m_mtxWorld._42 ,m_mtxWorld._43 };
		D3DXVECTOR3 Vec = Enemypos - pos;
		float rot = atan2f(Vec.x, Vec.z);
		CBullet::Create({ m_mtxWorld._41,m_mtxWorld._42 ,m_mtxWorld._43 }, { 0.0,rot ,0.0 },m_fMoveSpeed,m_nPower);
	}
	if (m_bUninit)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CAssistCrystal_Model::Draw()
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

	if (m_Crustal)
	{
		m_Crustal->SetParentMtx(m_mtxWorld);

		m_Crustal->Draw();
	}
	if (m_TopFrame)
	{
		m_TopFrame->Draw();
	}
	if (m_BottomFrame)
	{
		m_BottomFrame->Draw();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
CAssistCrystal_Model * CAssistCrystal_Model::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot,
	const float& fMoveSpeed, const int& nPower, const int& m_nInterval)
{
	CAssistCrystal_Model *pRushAttack = NULL;
	pRushAttack = new CAssistCrystal_Model();
	pRushAttack->m_pos = pos;
	pRushAttack->m_rot = rot;
	pRushAttack->m_fMoveSpeed = fMoveSpeed;
	pRushAttack->m_nPower = nPower;
	pRushAttack->m_nLaunchInterval = m_nInterval;
	pRushAttack->Init();

	return pRushAttack;
}