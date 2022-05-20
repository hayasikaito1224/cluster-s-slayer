//========================================
// �X�e�[�W
// Author:��
//========================================
#include "stage.h"
#include "model.h"
#include "field.h"
#include "texture.h"
#include "model_spawner.h"
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CStage::CStage()
{
	for (int nCnt = 0; nCnt < MAX_STAGE_MODEL; nCnt++)
	{
		m_pStageModel[nCnt] = NULL;
	}
	for (int nCnt = 0; nCnt < MAX_STAGE_ENEMY; nCnt++)
	{
		m_pEnemy_baum[nCnt] = NULL;
		m_pEnemy[nCnt] = NULL;

	}
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CStage::~CStage()
{

}

//------------------------------------
// ���[�V����������
//------------------------------------
HRESULT CStage::Init(void)
{
	return S_OK;
}

//--------------------------------------------
//�I��
//--------------------------------------------
void CStage::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_STAGE_MODEL; nCnt++)
	{
		if (m_pStageModel[nCnt] != NULL)
		{
			m_pStageModel[nCnt]->Uninit();
			m_pStageModel[nCnt] = NULL;
		}

	}
	for (int nCnt = 0; nCnt < m_NumMaxField; nCnt++)
	{
		if (m_pField[nCnt] != NULL)
		{
			m_pField[nCnt]->Uninit();
			m_pField[nCnt] = NULL;
		}
	}
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CStage::Update(void)
{

}
//------------------------------------
// �X�e�[�W�̓ǂݍ��ݐݒu
//------------------------------------
void CStage::TestStageSet(const char *sStageFileName)
{
	//std::ifstream ifs;//���̓X�g���[��

}

//------------------------------------
// �X�e�[�W�̓ǂݍ��ݐݒu
//------------------------------------
void CStage::StageSet(const char *sStageFileName)
{
	char sString[6][255];	// �ǂݍ��ݗp�̕ϐ�
	int nCntNumModel = 0;
	int nCntModel = 0;
	int nCntField = 0;
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int nBlockX = 0;
	int nBlockY = 0;
	int nType = 0;

							// �t�@�C���ǂݍ���
	FILE *pFile = fopen(sStageFileName, "r");

	// NULL�`�F�b�N
	if (pFile != NULL)
	{
		// END_SCRIPT���Ă΂��܂Ń��[�v����
		while (1)
		{
			// �P�P���ǂݍ���
			fscanf(pFile, "%s", &sString[0]);

			// �p�[�c���̓ǂݍ���
			if (strcmp(sString[0], "NUM_MODEL") == 0)
			{

				fscanf(pFile, "%s", &sString[1]);	// �C�R�[�������܂���
				fscanf(pFile, "%d", &m_NumModel);	// �p�[�c����ǂݍ���
				m_sModelFileName = new char*[m_NumModel];
				for (int nCnt = 0; nCnt < m_NumModel; nCnt++)
				{
					m_sModelFileName[nCnt] = new char[64];
				}
			}

			if (strcmp(sString[0], "MODEL_FILENAME") == 0)
			{
			//���f���t�@�C���̃p�X�ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				fscanf(pFile, "%s", m_sModelFileName[nCntNumModel]);
				nCntNumModel++;
			}
			if (strcmp(sString[0], "NUM_FIELD") == 0)
			{
				int Num = 0;
				//���f���t�@�C���̃p�X�ǂݍ���
				fscanf(pFile, "%s", &sString[1]);
				fscanf(pFile, "%d", &Num);
				m_pField = new CField*[Num];
				m_NumMaxField = Num;

			}

			// ���b�V���t�B�[���h�̓ǂݍ���
			while (strcmp(sString[0], "FIELDSET") == 0)
			{

				fscanf(pFile, "%s", &sString[1]);	// �C�R�[�������܂���
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "BLOCK") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%d %d", &nBlockX, &nBlockY);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f", &size.x, &size.z);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "END_FIELDSET") == 0)
				{
					m_pField[nCntField] = CField::Create(pos, size, rot, nBlockX, nBlockY, CTexture::FIELD);

					nCntField++;
					break;
				}
			} 
			// ���f���̓ǂݍ���
			while (strcmp(sString[0], "MODELSET") == 0)
			{
				fscanf(pFile, "%s", &sString[1]);	// �C�R�[�������܂���
				if (strcmp(sString[1], "TYPE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%d", &nType);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// �C�R�[�������܂���
					fscanf(pFile, "%f %f", &size.x, &size.z);	// �C�R�[�������܂���
				}
				if (strcmp(sString[1], "END_MODELSET") == 0)
				{
					m_pStageModel[nCntModel] = CModel_Spawner::Create(pos / 2.0f,rot, nType, CModel::TYPE_OBJECT);
					if (nType == 5)
					{
						m_pStageModel[nCntModel]->SetBoolRot(true);
					}
					nCntModel++;
					m_NumMaxModel++;
					break;
				}
			}

			if (strcmp(sString[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

	else
	{
		// �G���[�o��
		perror("�t�@�C�����J���܂���ł���");
	}

	// �t�@�C�������
	fclose(pFile);
}

