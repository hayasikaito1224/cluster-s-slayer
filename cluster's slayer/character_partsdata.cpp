//--------------------------------------------
//�L�����N�^�[�p�[�c�f�[�^�̕ێ��N���X
//�쐬�ҁF��
//--------------------------------------------
#include "character_partsdata.h"
#include "layer_structure.h"
#include "model.h"
CCharacterPartsData::PartsData CCharacterPartsData::m_EnemyPartsData = {};

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CCharacterPartsData::CCharacterPartsData()
{
	
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CCharacterPartsData::~CCharacterPartsData()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CCharacterPartsData::Init(void)
{
	//�t�@�C���ǂݍ���
	CLayer_Structure *pLayer = new CLayer_Structure;
	pLayer->SetLayer_Structure("data/TEXT/EnemyParts000.txt", &m_EnemyPartsData, CModel::TYPE_ENEMY);

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CCharacterPartsData::Uninit(void)
{

}
//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------
CCharacterPartsData *CCharacterPartsData::Create()
{
	CCharacterPartsData *pCharacterPartsData = NULL;
	pCharacterPartsData = new CCharacterPartsData;
	pCharacterPartsData->Init();
	return pCharacterPartsData;
}
//----------------------------------------------
//�p�[�c�̐ݒ�
//----------------------------------------------
void CCharacterPartsData::SetParts(std::vector<CModel*> *Parts)
{
	for (int nIndex = 0; nIndex < m_EnemyPartsData.nMaxModelNum; nIndex++)
	{
		Parts->push_back(CModel::Create(m_EnemyPartsData.pModelData[nIndex]->pos, m_EnemyPartsData.pModelData[nIndex]->rot, nIndex, m_EnemyPartsData.nLoadModelType));

		//�e�q�֌W��t����
		if (m_EnemyPartsData.pModelData[nIndex]->nParent != -1)
		{
			
			(*Parts)[nIndex]->SetParent((*Parts)[m_EnemyPartsData.pModelData[nIndex]->nParent]);
			(*Parts)[nIndex]->SetNumParent(m_EnemyPartsData.pModelData[nIndex]->nParent);
		}
		else
		{
			(*Parts)[nIndex]->SetParent(NULL);
			(*Parts)[nIndex]->SetNumParent(-1);
		}
	}
}
