//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#ifndef _CHARACTER_PARTSDATA_H_
#define _CHARACTER_PARTSDATA_H_
#include "main.h"
class CModel;

class CCharacterPartsData
{
public:
	struct ModelData
	{
		int nIndex;
		int nParent;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
	};
	struct PartsData
	{
		int nMaxModelNum;
		int nLoadModelType;
		std::vector<ModelData*> pModelData;
	};
	CCharacterPartsData();
	~CCharacterPartsData();
	HRESULT Init();
	void Uninit();
	//�ÓI�����o�[�֐�
	static CCharacterPartsData *Create();
	static PartsData GetPartsData() { return m_EnemyPartsData; }
	static void SetParts(std::vector<CModel*> *Parts);//�p�[�c�̐ݒ�
private:
	static PartsData m_EnemyPartsData;
};


#endif // !_PLAYER_H_

