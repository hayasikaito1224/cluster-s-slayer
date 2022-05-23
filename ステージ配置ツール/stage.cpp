//========================================
// ステージ
// Author:林
//========================================
#include "stage.h"
#include "model.h"
#include "field.h"
#include "texture.h"
#include "model_spawner.h"
//------------------------------------
// コンストラクタ
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
// デストラクタ
//------------------------------------
CStage::~CStage()
{

}

//------------------------------------
// モーション初期化
//------------------------------------
HRESULT CStage::Init(void)
{
	return S_OK;
}

//--------------------------------------------
//終了
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
//終了
//--------------------------------------------
void CStage::Update(void)
{

}
//------------------------------------
// ステージの読み込み設置
//------------------------------------
void CStage::TestStageSet(const char *sStageFileName)
{
	//std::ifstream ifs;//入力ストリーム

}

//------------------------------------
// ステージの読み込み設置
//------------------------------------
void CStage::StageSet(const char *sStageFileName)
{
	char sString[6][255];	// 読み込み用の変数
	int nCntNumModel = 0;
	int nCntModel = 0;
	int nCntField = 0;
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int nBlockX = 0;
	int nBlockY = 0;
	int nType = 0;

							// ファイル読み込み
	FILE *pFile = fopen(sStageFileName, "r");

	// NULLチェック
	if (pFile != NULL)
	{
		// END_SCRIPTが呼ばれるまでループする
		while (1)
		{
			// １単語を読み込む
			fscanf(pFile, "%s", &sString[0]);

			// パーツ数の読み込み
			if (strcmp(sString[0], "NUM_MODEL") == 0)
			{

				fscanf(pFile, "%s", &sString[1]);	// イコールを噛ませる
				fscanf(pFile, "%d", &m_NumModel);	// パーツ数を読み込む
				m_sModelFileName = new char*[m_NumModel];
				for (int nCnt = 0; nCnt < m_NumModel; nCnt++)
				{
					m_sModelFileName[nCnt] = new char[64];
				}
			}

			if (strcmp(sString[0], "MODEL_FILENAME") == 0)
			{
			//モデルファイルのパス読み込み
				fscanf(pFile, "%s", &sString[1]);
				fscanf(pFile, "%s", m_sModelFileName[nCntNumModel]);
				nCntNumModel++;
			}
			if (strcmp(sString[0], "NUM_FIELD") == 0)
			{
				int Num = 0;
				//モデルファイルのパス読み込み
				fscanf(pFile, "%s", &sString[1]);
				fscanf(pFile, "%d", &Num);
				m_pField = new CField*[Num];
				m_NumMaxField = Num;

			}

			// メッシュフィールドの読み込み
			while (strcmp(sString[0], "FIELDSET") == 0)
			{

				fscanf(pFile, "%s", &sString[1]);	// イコールを噛ませる
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "BLOCK") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%d %d", &nBlockX, &nBlockY);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f", &size.x, &size.z);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "END_FIELDSET") == 0)
				{
					m_pField[nCntField] = CField::Create(pos, size, rot, nBlockX, nBlockY, CTexture::FIELD);

					nCntField++;
					break;
				}
			} 
			// モデルの読み込み
			while (strcmp(sString[0], "MODELSET") == 0)
			{
				fscanf(pFile, "%s", &sString[1]);	// イコールを噛ませる
				if (strcmp(sString[1], "TYPE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%d", &nType);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "POS") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "ROT") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f %f", &rot.x, &rot.y, &rot.z);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f", &size.x, &size.z);	// イコールを噛ませる
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
		// エラー出力
		perror("ファイルが開けませんでした");
	}

	// ファイルを閉じる
	fclose(pFile);
}

