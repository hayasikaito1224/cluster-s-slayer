//=============================================-
//�L�����N�^�[���ʂ̏���
//=============================================
#include "character.h"
#include "model.h"
#include "manager.h"
#include "Renderer.h"
#include "shadow.h"
#include "model_spawner.h"
static const float fDrawLimit = 2000.0f;
//---------------------------------------------
//�R���X�g���N�^
//---------------------------------------------
CCharacter::CCharacter(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pParts.clear();
	m_IsCharacterDraw = true;
	m_nPartsMax = 0;
	m_pMotion = nullptr;
}
//-----------------------------------------------
//�f�X�g���N�^
//---------------------------------------------
CCharacter::~CCharacter()
{

}
//-----------------------------------------------
//������
//---------------------------------------------
HRESULT CCharacter::Init()
{
	return S_OK;
}
//-----------------------------------------------
//�I��
//---------------------------------------------
void CCharacter::Uninit()
{
	{
		int nPartsSize = m_pParts.size();
		for (int nCntParts = 0; nCntParts < nPartsSize; nCntParts++)
		{
			if (m_pParts[nCntParts] != nullptr)
			{
				m_pParts[nCntParts]->Uninit();
				m_pParts[nCntParts] = nullptr;
			}
		}
	}

	if (m_pShadow != nullptr)
	{
		m_pShadow->Uninit();
		m_pShadow = nullptr;
	}
	Release();
}

//-----------------------------------------------
//�X�V
//---------------------------------------------
void CCharacter::Update()
{
}
//-----------------------------------------------
//�`��
//---------------------------------------------
void CCharacter::Draw()
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

	//���f������
	if (m_IsCharacterDraw)
	{
		int nMaxParts = 0;//�p�[�c�̍ő吔
		nMaxParts = m_pParts.size();
		//�L�����N�^�[�̃p�[�c�����O�ȊO�Ȃ�
		if (nMaxParts != 0)
		{
			//�p�[�c����������
			nMaxParts = m_pParts.size();
		}
		for (int nCntParts = 0; nCntParts < nMaxParts; nCntParts++)
		{
			m_pParts[nCntParts]->Draw();
		}
	}

	//�O��̈ʒu���̕ۑ�
	m_lastpos = m_pos;

}

//-----------------------------------------------
//�����蔻��(����̌��݂̈ʒu�A����̈�O�̈ʒu�A����̓����蔻��̑傫��)
//---------------------------------------------
bool CCharacter::IsCollision(D3DXVECTOR3 *pMyPos, const D3DXVECTOR3& Hitpos, const float& fRadius, const float& MoveSpeed)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	vec = *pMyPos - Hitpos;
	float fLength = 0.0f;
	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	float fCollisionRadius = m_fRadius + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		float fAng = atan2(vec.x, vec.z);
		//�����߂�
		D3DXVECTOR3 returnpos = {sinf(fAng)*MoveSpeed,0.0f,cosf(fAng)*MoveSpeed};
		pMyPos->x += returnpos.x;
		pMyPos->z += returnpos.z;
		return true;
	}
	return false;
}
void CCharacter::IsModelCollision(const bool& bPlayer)
{
	CScene *pSceneModel = CScene::GetScene(OBJTYPE_MODELSPAWNER);

	while (pSceneModel)
	{
		CModel_Spawner *pModel = (CModel_Spawner*)pSceneModel;
		D3DXVECTOR3 ModelPos = pModel->GetPos();
		D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
		vec = m_pos - ModelPos;
		float fRadius = pModel->GetModel()->GetMaxPos().x;
		float fLength = 0.0f;
		//����Ǝ����̋��������߂�
		fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
		float fCollisionRadius = m_fRadius + fRadius;
		if (bPlayer)
		{
			if (fLength >= fDrawLimit)
			{
				pModel->SetDrawLimit(false);
			}
			else
			{
				pModel->SetDrawLimit(true);
			}
		}
		//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
		if (fLength <= fCollisionRadius && pModel->GetDrawLimit())
		{
			float fAng = atan2(vec.x, vec.z);
			//�����߂�
			D3DXVECTOR3 returnpos = { 0.0f,0.0f,0.0f };
			returnpos.x = ModelPos.x + sinf(fAng) * fCollisionRadius;
			returnpos.z = ModelPos.z + cosf(fAng) * fCollisionRadius;

			m_pos.x = returnpos.x;
			m_pos.z = returnpos.z;
		}
		pSceneModel = pSceneModel->GetSceneNext(pSceneModel);

	}
}
//-----------------------------------------------
//HP�̑���
//---------------------------------------------
void CCharacter::HPChange(float fNum)
{
	m_fHitPoint += fNum;
}
//-----------------------------------------------
//��Ԃ̕ύX
//---------------------------------------------
void CCharacter::StateChange(state_type StateType)
{
	m_StateType = StateType;
}
//-----------------------------------------------
//�L�����N�^�[�̃p�[�c�擾����
//---------------------------------------------
CModel * CCharacter::GetParts(int nPartsNum)
{
	int nSize = m_pParts.size();
	if (nSize != 0)
	{
		return  m_pParts[nPartsNum];
	}
	return nullptr;
}
