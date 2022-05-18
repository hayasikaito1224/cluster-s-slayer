//========================================
// �X�e�[�W�̉���̕ێ��p
// Author:��
//========================================
#ifndef _STAGE_PRESET_DATA_H_
#define _STAGE_PRESET_DATA_H_
#include "main.h"
//------------------------------------------
// ���[�V�����N���X
//------------------------------------------
class CStage_Preset_Data
{
public:
	struct WALLDATA
	{
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		D3DXVECTOR2 block;
		D3DXVECTOR3 size;
	};
	struct MODELDATA
	{
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		D3DXVECTOR3 size;
		int nType;
	};
	struct FIELDDATA
	{
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		D3DXVECTOR2 block;
		D3DXVECTOR3 size;
	};
	struct PRESETDATA
	{
		std::vector<WALLDATA> WallData;
		std::vector<MODELDATA> ModelData;
		std::vector<FIELDDATA> FieldData;
	};
	//------------------------------------
	// �R���X�g���N�^�A�f�X�g���N�^
	//------------------------------------
	CStage_Preset_Data();
	~CStage_Preset_Data();
	static void StagePresetLoad(const char *cFileName);
	static void StagePresetDataLoad(const char *cFileName, const int& nType);
	static PRESETDATA GetStagePresetData(const int& nType) { return m_PresetData[nType]; }
private:
	static std::vector<PRESETDATA> m_PresetData;
};
#endif _STAGE_PRESET_DATA_H_