//========================================
// �X�e�[�W�̉���쐬����
// Author:��
//========================================
#include "stage_preset_data.h"
#include "model.h"
#include "wall.h"
#include "field.h"
#include "texture.h"
#include "model_spawner.h"
std::vector<CStage_Preset_Data::PRESETDATA> CStage_Preset_Data::m_PresetData;
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CStage_Preset_Data::CStage_Preset_Data()
{
	m_PresetData.clear();
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CStage_Preset_Data::~CStage_Preset_Data()
{

}
//------------------------------------
// s�X�e�[�W�v���Z�b�g�t�@�C���̓ǂݍ���
//------------------------------------
void CStage_Preset_Data::StagePresetLoad(const char * cFileName)
{
	char sString[2][255];	// �ǂݍ��ݗp�̕ϐ�
	char sFileName[255];	// �ǂݍ��ݗp�̕ϐ�

	int nType = 0;
	// �t�@�C���ǂݍ���
	FILE *pFile = fopen(cFileName, "r");
	// NULL�`�F�b�N
	if (pFile != NULL)
	{
		// END_SCRIPT���Ă΂��܂Ń��[�v����
		while (1)
		{
			// �P�P���ǂݍ���
			fscanf(pFile, "%s", &sString[0]);
			//�ǂ̓ǂݍ���
			if (strcmp(sString[0], "STAGE_PRESET_FILE") == 0)
			{
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sString[0]);
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sFileName);
				PRESETDATA hoge = {};
				m_PresetData.push_back(hoge);
				//�X�e�[�W�v���Z�b�g����ǂݍ���
				StagePresetDataLoad(sFileName, nType);
				//�X�e�[�W�v���Z�b�g�������Z
				nType++;
			}
			if (strcmp(sString[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

}
//------------------------------------
// �X�e�[�W�v���Z�b�g�̏���ǂݍ���
//------------------------------------
void CStage_Preset_Data::StagePresetDataLoad(const char *cFileName, const int& nType)
{
	char sString[6][255];	// �ǂݍ��ݗp�̕ϐ�
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int nBlockX = 0;
	int nBlockY = 0;
	int nModelType = 0;
	int nWallCnt = 0;
	int nFieldCnt = 0;
	int nModelCnt = 0;

	// �t�@�C���ǂݍ���
	FILE *pFile = fopen(cFileName, "r");
	// NULL�`�F�b�N
	if (pFile != NULL)
	{
		// END_SCRIPT���Ă΂��܂Ń��[�v����
		while (1)
		{
			// �P�P���ǂݍ���
			fscanf(pFile, "%s", &sString[0]);
			//�ǂ̓ǂݍ���
			while (strcmp(sString[0], "WALLSET") == 0)
			{

				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);
				}
				if (strcmp(sString[1], "BLOCK") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%d %d", &nBlockX, &nBlockY);
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f", &size.x, &size.y);
				}
				if (strcmp(sString[1], "END_WALLSET") == 0)
				{
					WALLDATA hoge = {};
					m_PresetData[nType].WallData.push_back(hoge);
					//��œǂݍ��񂾕ǂ̏�����
					m_PresetData[nType].WallData[nWallCnt].pos = pos;
					m_PresetData[nType].WallData[nWallCnt].size = size;
					m_PresetData[nType].WallData[nWallCnt].rot = rot;
					m_PresetData[nType].WallData[nWallCnt].block = { (float)nBlockX ,(float)nBlockY };
					pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					nBlockX = 0;
					nBlockY = 0;

					//�ǂ̌������Z
					nWallCnt++;
					break;
				}
			}

			// ���b�V���t�B�[���h�̓ǂݍ���
			while (strcmp(sString[0], "FIELDSET") == 0)
			{

				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);
				}
				if (strcmp(sString[1], "BLOCK") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%d %d", &nBlockX, &nBlockY);
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f", &size.x, &size.z);
				}
				if (strcmp(sString[1], "END_FIELDSET") == 0)
				{
					FIELDDATA hoge = {};
					m_PresetData[nType].FieldData.push_back(hoge);
					//��œǂݍ��񂾏��̏�����
					m_PresetData[nType].FieldData[nFieldCnt].pos = pos;
					m_PresetData[nType].FieldData[nFieldCnt].size = size;
					m_PresetData[nType].FieldData[nFieldCnt].rot = rot;
					m_PresetData[nType].FieldData[nFieldCnt].block = { (float)nBlockX ,(float)nBlockY };
					pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					nBlockX = 0;
					nBlockY = 0;

					//���̌������Z
					nFieldCnt++;
					break;
				}
			}
			// ���f���̓ǂݍ���
			while (strcmp(sString[0], "MODELSET") == 0)
			{
				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "TYPE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%d", &nModelType);
				}
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f", &size.x, &size.z);
				}
				if (strcmp(sString[1], "END_MODELSET") == 0)
				{
					MODELDATA hoge = {};
					m_PresetData[nType].ModelData.push_back(hoge);
					//��œǂݍ��񂾕ǂ̏�����
					m_PresetData[nType].ModelData[nModelCnt].pos = pos;
					m_PresetData[nType].ModelData[nModelCnt].size = size;
					m_PresetData[nType].ModelData[nModelCnt].rot = rot;
					m_PresetData[nType].ModelData[nModelCnt].nType = nModelType;
					pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					nBlockX = 0;
					nBlockY = 0;

					//�ǂ̌������Z
					nModelCnt++;
					break;
				}
			}
			// �G�̓ǂݍ���
			if (strcmp(sString[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

	// �t�@�C�������
	fclose(pFile);


}

