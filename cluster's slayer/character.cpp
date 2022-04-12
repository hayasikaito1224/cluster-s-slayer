//=============================================-
//�L�����N�^�[���ʂ̏���
//=============================================
#include "character.h"
#include "model.h"
#include "manager.h"
#include "Renderer.h"

//---------------------------------------------
//�R���X�g���N�^
//---------------------------------------------
CCharacter::CCharacter(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pParts.clear();
	m_IsCharacterDraw = true;
	m_pLayer = nullptr;
	m_nPartsMax = 0;
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
	int nPartsSize = m_pParts.size();
	for (int nCntParts = 0; nCntParts < nPartsSize; nCntParts++)
	{
		if (m_pParts[nCntParts] != NULL)
		{
			m_pParts[nCntParts]->Uninit();
			m_pParts[nCntParts] = NULL;
		}
	}
	m_pMotion.clear();

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
bool CCharacter::IsCollision(const D3DXVECTOR3 pos, float fRadius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	vec = pos - m_pos;
	float fLength = 0.0f;
	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	float fCollisionRadius = m_fRadius + fRadius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		//�����߂�
		D3DXVECTOR3 returnpos = m_pos - m_lastpos;
		m_pos.x += returnpos.x;
		m_pos.z += returnpos.z;
		return true;
	}
	return false;
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
