//---------------------------------------------------
//�K�w�\���̏���
//---------------------------------------------------
#include "layer_structure.h"
#include "model.h"

//--------------------------
//�R���X�g���N�g
//----------------------------

CLayer_Structure::CLayer_Structure()
{
}

//--------------------------
//�f�X�g���N�g
//----------------------------
CLayer_Structure::~CLayer_Structure()
{

}

//-----------------------------------------------------------
//�K�w�\���̓ǂݍ���
//-----------------------------------------------------------
void CLayer_Structure::SetLayer_Structure(const char * sFileName, vector<CModel*>& pModel, int nType)
{
	int nIndex = 0;						//�p�[�c�̔ԍ�
	int nParent = 0;				//�e�q�֌W
	char string[6][255];
	char pPartsFileName[20][255];	//���f���p�[�c�̃t�@�C���l�[��
	memset(&pPartsFileName, NULL, sizeof(pPartsFileName));
	D3DXVECTOR3 PartsPos, PartsRot;	//�e�p�[�c�̈ʒu�ƌ���
	int nCntModel = 0;
	int nNumModel = 0;
	int nTypeMode = 0;
	//text�t�@�C���ǂݍ���
	FILE *pfile = fopen(sFileName, "r");
	//�k���`�F�b�N
	if (pfile != NULL)
	{
		while (1)
		{
			//��P���ǂݍ���
			fscanf(pfile, "%s", &string[0]);
			//���Ɏg�����f�������f
			if (strcmp(string[0], "MODEL_TYPE") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				fscanf(pfile, "%d", &nTypeMode);
			}

			//���f����
			if (strcmp(string[0], "NUM_MODEL") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				fscanf(pfile, "%d", &nNumModel);
				m_MaxParts = nNumModel;
				//���I�m��
				for (int nCnt  = 0; nCnt  < m_MaxParts; nCnt ++)
				{
					CModel *Securement = {};
					pModel.push_back(Securement);

				}
			}

			//���f���̃t�@�C���̂Ȃ܂�
			if (strcmp(string[0], "MODEL_FILENAME") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				fscanf(pfile, "%s", &pPartsFileName[nCntModel]);
				nCntModel++;
			}

			//--------------------------------------
			//���f���̊K�w�\���̐ݒ�
			//--------------------------------------
			while (strcmp(string[0], "CHARACTERSET") == 0)
			{
				fscanf(pfile, "%s", &string[1]);

				//�p�[�c�̐ݒ�
				while (strcmp(string[1], "PARTSSET") == 0)
				{
					fscanf(pfile, "%s", &string[2]);
					//���f���p�[�c�̔ԍ�
					if (strcmp(string[2], "INDEX") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%d", &nIndex);
					}
					//�e�̔ԍ�
					if (strcmp(string[2], "PARENT") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%d", &nParent);
					}
					//�ʒu
					if (strcmp(string[2], "POS") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%f %f %f", &PartsPos.x, &PartsPos.y, &PartsPos.z);
					}
					//����
					if (strcmp(string[2], "ROT") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%f %f %f", &PartsRot.x, &PartsRot.y, &PartsRot.z);
					}
					//���f���̐���
					if (strcmp(string[2], "END_PARTSSET") == 0)
					{
						pModel[nIndex] = CModel::Create(PartsPos, PartsRot, nIndex, nType);

						//�e�q�֌W��t����
						if (nParent != -1)
						{
							pModel[nIndex]->SetParent(pModel[nParent]);
							pModel[nIndex]->SetNumParent(nParent);
						}
						else
						{
							pModel[nIndex]->SetParent(NULL);
							pModel[nIndex]->SetNumParent(-1);
						}
						break;
					}

				}
				//�I��
				if (strcmp(string[1], "END_CHARACTERSET") == 0)
				{
					break;
				}

			}

			//�X�N���v�g�Ǎ��̏I��
			if (strcmp(string[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

}

//-----------------------------------------------------------
//�K�w�\���̓ǂݍ���
//-----------------------------------------------------------
void CLayer_Structure::SetLayer_Structure(const char * sFileName, CCharacterPartsData::PartsData *PartsData, int nType)
{
	int nIndex = 0;						//�p�[�c�̔ԍ�
	int nParent = 0;				//�e�q�֌W
	char string[6][255];
	char pPartsFileName[20][255];	//���f���p�[�c�̃t�@�C���l�[��
	memset(&pPartsFileName, NULL, sizeof(pPartsFileName));
	D3DXVECTOR3 PartsPos, PartsRot;	//�e�p�[�c�̈ʒu�ƌ���
	int nCntModel = 0;
	int nNumModel = 0;
	int nTypeMode = 0;
	//text�t�@�C���ǂݍ���
	FILE *pfile = fopen(sFileName, "r");
	//�k���`�F�b�N
	if (pfile != NULL)
	{
		while (1)
		{
			//��P���ǂݍ���
			fscanf(pfile, "%s", &string[0]);
			//���Ɏg�����f�������f
			if (strcmp(string[0], "MODEL_TYPE") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				fscanf(pfile, "%d", &PartsData->nLoadModelType);
			}

			//���f����
			if (strcmp(string[0], "NUM_MODEL") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				fscanf(pfile, "%d", &PartsData->nMaxModelNum);
				m_MaxParts = PartsData->nMaxModelNum;
				//���I�m��
				for (int nCnt = 0; nCnt < m_MaxParts; nCnt++)
				{
					PartsData->pModelData.push_back(new CCharacterPartsData::ModelData);

				}
			}

			//--------------------------------------
			//���f���̊K�w�\���̐ݒ�
			//--------------------------------------
			while (strcmp(string[0], "CHARACTERSET") == 0)
			{
				fscanf(pfile, "%s", &string[1]);

				//�p�[�c�̐ݒ�
				while (strcmp(string[1], "PARTSSET") == 0)
				{
					fscanf(pfile, "%s", &string[2]);
					//���f���p�[�c�̔ԍ�
					if (strcmp(string[2], "INDEX") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%d", &nIndex);
						PartsData->pModelData[nIndex]->nIndex = nIndex;
					}
					//�e�̔ԍ�
					if (strcmp(string[2], "PARENT") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%d", &nParent);
						PartsData->pModelData[nIndex]->nParent = nParent;

					}
					//�ʒu
					if (strcmp(string[2], "POS") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%f %f %f", &PartsPos.x, &PartsPos.y, &PartsPos.z);
						PartsData->pModelData[nIndex]->pos = PartsPos;
					}
					//����
					if (strcmp(string[2], "ROT") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%f %f %f", &PartsRot.x, &PartsRot.y, &PartsRot.z);
						PartsData->pModelData[nIndex]->rot = PartsRot;
					}
					//���f���̐���
					if (strcmp(string[2], "END_PARTSSET") == 0)
					{
						break;
					}

				}
				//�I��
				if (strcmp(string[1], "END_CHARACTERSET") == 0)
				{
					break;
				}

			}

			//�X�N���v�g�Ǎ��̏I��
			if (strcmp(string[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

}
