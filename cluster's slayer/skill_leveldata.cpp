//--------------------------------------------
//�X�L���̃��x�����Ƃ̃X�e�[�^�X����ێ�����N���X
//�쐬�ҁF��
//--------------------------------------------
#include "skill_leveldata.h"

CBlackHole::State CSkill_LevelData::m_BlackHoleState[CBlackHole::Level_MAX] = {};

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CSkill_LevelData::CSkill_LevelData()
{

}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CSkill_LevelData::~CSkill_LevelData()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CSkill_LevelData::Init(void)
{
	//�t�@�C���ǂݍ���
	BlackHoleLoad("data/TEXT/SKILL_LEVEL/BlackHole.txt");

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CSkill_LevelData::Uninit(void)
{

}

//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------
CSkill_LevelData *CSkill_LevelData::Create()
{
	CSkill_LevelData *pCharacterPartsData = NULL;
	pCharacterPartsData = new CSkill_LevelData;
	pCharacterPartsData->Init();
	return pCharacterPartsData;
}

//----------------------------------------------
//���[�h
//----------------------------------------------
void CSkill_LevelData::BlackHoleLoad(const char * sFileName)
{
	char sString[6][255];	// �ǂݍ��ݗp�̕ϐ�

	int nLevel = 0;
	// �t�@�C���ǂݍ���
	FILE *pFile = fopen(sFileName, "r");
	// NULL�`�F�b�N
	if (pFile != NULL)
	{
		// END_SCRIPT���Ă΂��܂Ń��[�v����
		while (1)
		{
			// �P�P���ǂݍ���
			fscanf(pFile, "%s", &sString[0]);
			//�ǂ̓ǂݍ���
			while (strcmp(sString[0], "BLACKHOLE_LEVEL1") == 0)
			{
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "HOLEEXPANSIONTIME") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%d", &m_BlackHoleState[CBlackHole::Level_1].m_HoleExpansionTime);
				}
				if (strcmp(sString[1], "AREASIZE") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%f", &m_BlackHoleState[CBlackHole::Level_1].m_fArea);

				}
				if (strcmp(sString[1], "END_BLACKHOLE_LEVEL1") == 0)
				{
					break;
				}
			}
			while (strcmp(sString[0], "BLACKHOLE_LEVEL2") == 0)
			{
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "HOLEEXPANSIONTIME") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%d", &m_BlackHoleState[CBlackHole::Level_2].m_HoleExpansionTime);
				}
				if (strcmp(sString[1], "AREASIZE") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%f", &m_BlackHoleState[CBlackHole::Level_2].m_fArea);
				}
				if (strcmp(sString[1], "END_BLACKHOLE_LEVEL2") == 0)
				{
					break;
				}
			}
			while (strcmp(sString[0], "BLACKHOLE_LEVEL3") == 0)
			{
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "HOLEEXPANSIONTIME") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%d", &m_BlackHoleState[CBlackHole::Level_3].m_HoleExpansionTime);
				}
				if (strcmp(sString[1], "AREASIZE") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%f", &m_BlackHoleState[CBlackHole::Level_3].m_fArea);
				}
				if (strcmp(sString[1], "END_BLACKHOLE_LEVEL3") == 0)
				{
					break;
				}
			}
			while (strcmp(sString[0], "BLACKHOLE_LEVEL4") == 0)
			{
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "HOLEEXPANSIONTIME") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%d", &m_BlackHoleState[CBlackHole::Level_4].m_HoleExpansionTime);
				}
				if (strcmp(sString[1], "AREASIZE") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%f", &m_BlackHoleState[CBlackHole::Level_4].m_fArea);
				}
				if (strcmp(sString[1], "END_BLACKHOLE_LEVEL4") == 0)
				{
					break;
				}
			}
			while (strcmp(sString[0], "BLACKHOLE_LEVELMAX") == 0)
			{
				// �P�P���ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				if (strcmp(sString[1], "HOLEEXPANSIONTIME") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%d", &m_BlackHoleState[CBlackHole::Level_MAX].m_HoleExpansionTime);
				}
				if (strcmp(sString[1], "AREASIZE") == 0)
				{
					// �P�P���ǂݍ���
					fscanf(pFile, "%s", &sString[1]);
					fscanf(pFile, "%f", &m_BlackHoleState[CBlackHole::Level_MAX].m_fArea);
				}
				if (strcmp(sString[1], "END_BLACKHOLE_LEVELMAX") == 0)
				{
					break;
				}
			}

			if (strcmp(sString[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

}
