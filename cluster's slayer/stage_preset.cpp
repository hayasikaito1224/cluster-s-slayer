//========================================
// �X�e�[�W�̉���쐬����
// Author:��
//========================================
#include "stage_preset.h"
#include "model.h"
#include "wall.h"
#include "field.h"
#include "texture.h"
#include "model_spawner.h"
#include "stage_preset_data.h"
#include "enemy_spawn_manager.h"
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CStage_Preset::CStage_Preset()
{
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CStage_Preset::~CStage_Preset()
{

}
//------------------------------------
//������
//------------------------------------
HRESULT CStage_Preset::Init()
{

	return S_OK;
}
//------------------------------------
//�I��
//------------------------------------
void CStage_Preset::Uninit()
{
}
//------------------------------------
//�X�V
//------------------------------------
void CStage_Preset::Update()
{
}
//------------------------------------
//�`��
//------------------------------------
void CStage_Preset::Draw()
{
}
//------------------------------------
//����
//------------------------------------
CStage_Preset * CStage_Preset::Create(const D3DXVECTOR3& pos,const int& nType)
{
	CStage_Preset *pStagePreset = new CStage_Preset;
	if (pStagePreset)
	{
		pStagePreset->Init();
		pStagePreset->m_pos = pos;
		pStagePreset->PresetCreate(nType);
	}
	return pStagePreset;
}
//------------------------------------
//�X�e�[�W�v���Z�b�g�̐���
//------------------------------------
void CStage_Preset::PresetCreate(const int& nType)
{
	//�v���Z�b�g���̎擾
	CStage_Preset_Data::PRESETDATA PresetData = CStage_Preset_Data::GetStagePresetData(nType);
	{
		int nWallMax = PresetData.WallData.size();
		for (int nNumWall = 0; nNumWall < nWallMax; nNumWall++)
		{
			//�ǂ̏��
			CStage_Preset_Data::WALLDATA& WallData = PresetData.WallData[nNumWall];
			CWall::Create(m_pos + WallData.pos, WallData.size, WallData.rot, WallData.block.x, WallData.block.y, CTexture::FIELD);
		}
	}
	{
		int nFieldMax = PresetData.FieldData.size();
		for (int nNumField = 0; nNumField < nFieldMax; nNumField++)
		{
			//���̏��
			CStage_Preset_Data::FIELDDATA& FieldData = PresetData.FieldData[nNumField];
			CField::Create(m_pos + FieldData.pos, FieldData.size, FieldData.rot, FieldData.block.x, FieldData.block.y, CTexture::FIELD);
		}
	}
	{
		int nModelMax = PresetData.ModelData.size();
		for (int nNumModel = 0; nNumModel < nModelMax; nNumModel++)
		{
			//���f���̏��
			CStage_Preset_Data::MODELDATA& ModelData = PresetData.ModelData[nNumModel];
			CModel_Spawner::Create(m_pos + ModelData.pos,ModelData.rot, ModelData.nType);
		}
	}
	CEnemySpawnManager::Create(m_pos);
}
