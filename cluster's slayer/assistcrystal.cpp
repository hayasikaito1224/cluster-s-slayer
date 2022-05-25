//-------------------------------------------
//�u���b�N�z�[���̏���
//------------------------------------------
#include "assistcrystal.h"
#include "manager.h"
#include "Renderer.h"
#include "Particle.h"
#include "enemy.h"
#include "PresetSetEffect.h"
#include "assistcrystal_model.h"
#include "player.h"
#include "character.h"
#include "skill_leveldata.h"
static const float MoveSpeedMax = 4.0f;
static const float MoveSpeedMin = 2.0f;
static const float HoleSpeed = 1.5f;
static const float HoleArea = 200.0f;
static const int DeleteTime = 200;
static const int HoleExpansionTime = 60;
static const float FollowingLimit = 10.0f;//�����̐����l
static const float PlayerDistance = 100.0f;//�����̐����l

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CAssistCrystal::CAssistCrystal()
{
	m_CrystalModel = nullptr;

}

//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CAssistCrystal::~CAssistCrystal()
{

}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CAssistCrystal::Init(void)
{
	CAssistCrystal::State LevelState = CSkill_LevelData::GetStateAssistCrystal(m_nLevel);
	if (!m_CrystalModel)
	{
		m_CrystalModel = CAssistCrystal_Model::Create({ 0.0f,0.0f,0.0f }, { 0.0f,0.0f,0.0f }, LevelState.m_fMoveSpeed, LevelState.m_nPower, LevelState.m_nLaunchInterval);
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CAssistCrystal::Uninit(void)
{
	if (m_CrystalModel)
	{
		m_CrystalModel->Uninit();
		m_CrystalModel = nullptr;
	}

}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CAssistCrystal::Update(void)
{
	PlayerFollowing();
	m_rot.y = m_pPlayer->GetRot().y;
	if (m_CrystalModel)
	{
		m_CrystalModel->Update();
	}
	if (m_bUninit)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CAssistCrystal::Draw()
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

	//if (m_pPlayer)
	//{
	//	m_mtxParent = m_pPlayer->GetMtx();
	//}

	////�Z�o�����e�p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���|�����킹��
	//D3DXMatrixMultiply(&m_mtxWorld,
	//	&m_mtxWorld,
	//	&m_mtxParent);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	if (m_CrystalModel)
	{
		m_CrystalModel->SetMtx(m_mtxWorld);
		m_CrystalModel->Draw();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
CAssistCrystal * CAssistCrystal::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CPlayer *pPlayer, const int& nLevel)
{
	CAssistCrystal *pRushAttack = NULL;
	pRushAttack = new CAssistCrystal();
	pRushAttack->m_pos = pos;
	pRushAttack->m_fInstallationAngle = rot.y;
	pRushAttack->m_pPlayer = pPlayer;
	pRushAttack->m_nLevel = nLevel;
	pRushAttack->Init();

	return pRushAttack;
}

void CAssistCrystal::PlayerFollowing()
{
	D3DXVECTOR3 Pos = { m_pPlayer->GetPos().x + (cosf(m_fInstallationAngle-m_pPlayer->GetRot().y)*PlayerDistance),0.0f,
						m_pPlayer->GetPos().z + (sinf(m_fInstallationAngle-m_pPlayer->GetRot().y)*PlayerDistance) };

	{
		//�J�����̒����_�ƃv���C���[�̈ʒu�̍���
		float PosDifference_X = m_pos.x - Pos.x;

		//�v���C���[�̈ʒu�ɖ߂����x
		float RevertSpeed = abs(PosDifference_X / FollowingLimit);
		//RevertSpeed��0.0f�o�͂Ȃ�������
		if (RevertSpeed != 0.0f)
		{
			//���������̐��Ȃ畉�̐��ɖ߂��悤�ɂ���
			if (PosDifference_X > 0)
			{
				m_pos.x -= RevertSpeed;
			}
			else
			{
				m_pos.x += RevertSpeed;
			}
		}
	}
	{
		float PosDifference_Z =  m_pos.z - Pos.z;//�J�����̒����_�ƃv���C���[�̈ʒu�̍���
		float RevertSpeed = abs(PosDifference_Z / FollowingLimit);//�v���C���[�̈ʒu�ɖ߂����x
															   //RevertSpeed��0.0f�o�͂Ȃ�������
		if (RevertSpeed != 0.0f)
		{
			//���������̐��Ȃ畉�̐��ɖ߂��悤�ɂ���
			if (PosDifference_Z > 0)
			{
				m_pos.z -= RevertSpeed;
			}
			else
			{
				m_pos.z += RevertSpeed;
			}

		}

	}

}
