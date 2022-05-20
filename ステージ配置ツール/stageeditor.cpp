//----------------------------------
//ステージエディタの処理
//----------------------------------
#include "stageeditor.h"
#include "model_spawner.h"
#include "keyboard.h"
#include "manager.h"
#include "game.h"
#include "model.h"
#include "Renderer.h"
#include "Scene3D.h"
#include "player_controller.h"
#include "camera.h"
#include "field.h"
#include "mouse.h"
#include "wall.h"
#define INIT_CURSOR_SIZE (150.0)
std::vector<CModel*> CStageEditor::m_pModel;
std::vector<CModel*> CStageEditor::m_pAssistModel;
std::vector<CModel*> CStageEditor::m_pAssistEnemyModel;
std::vector<CModel*> CStageEditor::m_pEnemyModel;
std::vector<CField*> CStageEditor::m_pField;
std::vector<CWall*>	 CStageEditor::m_pWall;

//==================================
//コンストラクタ
//==================================
CStageEditor::CStageEditor(OBJTYPE nPriority) :CScene(nPriority)
{
	memset(&m_sSaveFileName, NULL, sizeof(m_sSaveFileName));
	//セーブファイルの名前の読み込み
	FILE *pfile = fopen("data/TEXT/FileNameSaveData.txt", "r");
	char cSaveFile[255];
	char string[2][255];
	int nSaveFileCnt = 0;
	if (pfile != NULL)
	{
		while (1)
		{
			fscanf(pfile, "%s", &string[0]);

			//セーブファイル
			if (strcmp(string[0], "SAVE_FILENAME") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				fscanf(pfile, "%s", &cSaveFile);
				//セーブファイルのパスの保存
				strcpy(&m_sSaveFileName[nSaveFileCnt][0], &cSaveFile[0]);
				//m_sSaveFileName[nSaveFileCnt] = cSaveFile;
				nSaveFileCnt++;
			}
			if (strcmp(string[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}
	fclose(pfile);

	m_pModel.clear();
	m_pField.clear();
	m_pWall.clear();
	m_pEnemyModel.clear();
	m_pAssistEnemyModel.clear();
	pAssistCursor = nullptr;
	pAssistCursorWall = nullptr;
	m_pController = nullptr;
	m_nNumSaveFile = 0;
	m_nModeType = MODE_SET;
	m_nSetType = TYPE_FIELD;
	m_pAssistModel.clear();
	m_size = { INIT_CURSOR_SIZE ,INIT_CURSOR_SIZE ,INIT_CURSOR_SIZE };
	m_Meshsize = { INIT_CURSOR_SIZE ,INIT_CURSOR_SIZE ,INIT_CURSOR_SIZE };
	m_nSelectModel = 0;
	m_nSelectMeshField = 0;
	m_nSelectWall = 0;
	m_bShiftLock = false;
	m_bCtrlLock = false;
	m_nWallCnt = 0;
	m_bIsCulling = false;
	m_bTextDraw = true;
	m_nEnemyCnt = 0;
	m_nSelectEnemy = 0;
}
//==================================
//デストラクタ
//==================================

CStageEditor::~CStageEditor()
{
}
//==================================
//初期化	
//==================================

HRESULT CStageEditor::Init()
{
	m_nMeshNumX = 1;
	m_nMeshNumZ = 1;
	if (pAssistCursor == nullptr)
	{
		pAssistCursor = CScene3D::Create({ INIT_CURSOR_SIZE,0.0f,INIT_CURSOR_SIZE },CTexture::CURSOR);
	}
	if (pAssistCursorWall == nullptr)
	{
		pAssistCursorWall= CScene3D::Create({ INIT_CURSOR_SIZE,INIT_CURSOR_SIZE,0.0f }, CTexture::CURSOR);
	}
	if (m_pController == nullptr)
	{
		//プレイヤーのコントローラーの呼び出し
		m_pController = new CPlayer_Controller;
	}
	for (int nCnt = 0; nCnt < (int)CManager::GetXload()->NumObjectModel(); nCnt++)
	{
		CModel *Securement = {};
		m_pAssistModel.push_back(Securement);
		m_pAssistModel[nCnt]= CModel::Create(m_pos, m_rot, nCnt, CModel::TYPE_OBJECT);
		m_pAssistModel[nCnt]->SetDiffuse(0.3f);
	}

	CModel *Securement = {};
	m_pAssistEnemyModel.push_back(Securement);
	m_pAssistEnemyModel[0] = CModel::Create(m_pos, m_rot, 4, CModel::TYPE_OBJECT);

	return S_OK;
}
//==================================
//破棄	
//==================================

void CStageEditor::Uninit()
{
	for (int Cnt = 0; Cnt < (int)m_pModel.size(); Cnt++)
	{
		if (m_pModel[Cnt] != nullptr)
		{
			m_pModel[Cnt]->Uninit();
			m_pModel[Cnt] = nullptr;
		}
	}
	for (int Cnt = 0; Cnt < (int)m_pField.size(); Cnt++)
	{
		if (m_pField[Cnt] != nullptr)
		{
			m_pField[Cnt]->Uninit();
			m_pField[Cnt] = nullptr;
		}
	}
	for (int Cnt = 0; Cnt < (int)m_pAssistModel.size(); Cnt++)
	{
		if (m_pAssistModel[Cnt] != nullptr)
		{
			m_pAssistModel[Cnt]->Uninit();
			m_pAssistModel[Cnt] = nullptr;
		}
	}
	for (int Cnt = 0; Cnt < (int)m_pAssistEnemyModel.size(); Cnt++)
	{
		if (m_pAssistEnemyModel[Cnt] != nullptr)
		{
			m_pAssistEnemyModel[Cnt]->Uninit();
			m_pAssistEnemyModel[Cnt] = nullptr;
		}
	}
	for (int Cnt = 0; Cnt < (int)m_pEnemyModel.size(); Cnt++)
	{
		if (m_pEnemyModel[Cnt] != nullptr)
		{
			m_pEnemyModel[Cnt]->Uninit();
			m_pEnemyModel[Cnt] = nullptr;
		}
	}
	for (int nCnt = 0; nCnt < (int)m_pWall.size(); nCnt++)
	{
		if (m_pWall[nCnt] != nullptr)
		{
			m_pWall[nCnt]->Uninit();
			m_pWall[nCnt] = nullptr;
		}
	}
	if (m_pController != nullptr)
	{
		m_pController = nullptr;
	}
	if (pAssistCursor != nullptr)
	{
		pAssistCursor->Uninit();
		pAssistCursor = nullptr;
	}
	if (pAssistCursorWall != nullptr)
	{
		pAssistCursorWall->Uninit();
		pAssistCursorWall = nullptr;
	}
	m_pModel.clear();
	Release();
}
//==================================
//更新
//==================================

void CStageEditor::Update()
{
	CMouse *pMouse = CManager::GetMouse();

	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (m_pController != nullptr)
	{
		m_pController->MouseCameraControl();

	}
	if (m_pController != nullptr)
	{
		m_pController->LongPush();
	}
	ShiftLock();
	CtrlLock();
	//キーを押すと数字が増減する処理
	SelectNum(DIK_F2, DIK_F1, m_nNumSaveFile, 1, NUM_SAVE_FILE);
	//セーブ
	if (Key->GetTrigger(DIK_F3) == true)
	{
		Save();
	}
	//ロード
	else if (Key->GetTrigger(DIK_F4) == true)
	{
		Load();
	}
	//設置モードに切り替え
	if (Key->GetTrigger(DIK_F5) == true)
	{
		m_nModeType = MODE_SET;

	}
	//編集モードに切り替え
	if (Key->GetTrigger(DIK_F6) == true)
	{
		m_nModeType = MODE_EDIT;
		switch (m_nModeType)
		{
		case TYPE_OBJECT:
			//位置を選択したモデルに合わせる
			if ((int)m_pModel.size() != 0)
			{
				m_pos = m_pModel[m_nSelectModel]->GetMPos();
			}

			break;
		case TYPE_FIELD:
			//位置を選択したモデルに合わせる
			if ((int)m_pField.size() != 0)
			{
				m_pos = m_pField[m_nSelectMeshField]->GetPos();
			}
			break;
		case TYPE_WALL:
			//位置を選択したモデルに合わせる
			if ((int)m_pWall.size() != 0)
			{
				m_pos = m_pWall[m_nSelectWall]->GetPos();
			}
			break;
		case TYPE_ENEMY:
			//位置を選択したモデルに合わせる
			if ((int)m_pEnemyModel.size() != 0)
			{
				m_pos = m_pEnemyModel[m_nSelectEnemy]->GetMPos();
			}

			break;
		}

	}
	//設置するものの選択
	if (Key->GetTrigger(DIK_2) == true)
	{
		m_nSetType++;
		if (m_nSetType >= TYPE_MAX)
		{
			m_nSetType = 0;
		}
	}
	else if (Key->GetTrigger(DIK_1) == true)
	{
		m_nSetType--;
		if (m_nSetType < 0)
		{
			m_nSetType = TYPE_MAX - 1;
		}
	}
	m_pController->ModelRot(m_rot);
	//------------------------------
	//配置に関係する処理
	//------------------------------
	switch (m_nSetType)
	{
	case TYPE_OBJECT:
		if (m_pController != nullptr)
		{
			m_pController->MouseMove(m_pos);
			m_pController->TestMove(m_pos);
		}
		//モデルの回転の処理
		m_pController->AddTypeChange();
		switch (m_nModeType)
		{
		case MODE_SET:
			//スペースか右クリックを押したらモデル生成
			if (Key->GetPress(DIK_SPACE) == true || pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
			{
				CModel *Securement = {};
				m_pModel.push_back(Securement);
				m_pModel[m_nCnt] = CModel::Create(m_pos, m_rot, m_nSetModelType, CModel::TYPE_OBJECT);

				m_nCnt++;
			}
			//アシストモデルの位置回転更新
			if (m_pAssistModel[m_nSetModelType] != nullptr)
			{
				m_pAssistModel[m_nSetModelType]->SetPos(m_pos);
				m_pAssistModel[m_nSetModelType]->SetRot(m_rot);
			}

			break;
		case MODE_EDIT:
			//編集するモデルの選択
			if (Key->GetTrigger(DIK_4) == true)
			{
				m_nSelectModel++;
				if (m_nSelectModel >= (int)m_pModel.size())
				{
					m_nSelectModel = 0;
				}
				//位置を選択したモデルに合わせる
				if ((int)m_pModel.size() != 0)
				{
					m_pos = m_pModel[m_nSelectModel]->GetMPos();
				}
			}
			else if (Key->GetTrigger(DIK_3) == true)
			{
				m_nSelectModel --;
				if (m_nSelectModel< 0)
				{
					m_nSelectModel = (int)m_pModel.size() - 1;
				}
				//位置を選択したモデルに合わせる

				if ((int)m_pModel.size() != 0)
				{
					m_pos = m_pModel[m_nSelectModel]->GetMPos();

				}
			}
			//モデルの位置回転更新
			if ((int)m_pModel.size() != 0)
			{
				m_pModel[m_nSelectModel]->SetPos(m_pos);
				m_pModel[m_nSelectModel]->SetRot(m_rot);
				//選択したモデルの消去
				if (Key->GetTrigger(DIK_DELETE) == true)
				{
					m_pModel[m_nSelectModel]->Uninit();
					m_pModel[m_nSelectModel] = nullptr;
					m_pModel.erase(m_pModel.begin() + m_nSelectModel);
					m_nCnt--;
					if ((int)m_pModel.size() != 0)
					{
						m_pos = m_pModel[m_nSelectModel]->GetMPos();

					}
				}

			}
			break;

		}
		//配置するモデルの選択
		if (Key->GetTrigger(DIK_C) == true)
		{
			m_nSetModelType++;
			if (m_nSetModelType >= (int)m_pAssistModel.size())
			{
				m_nSetModelType = 0;
			}
		}
		else if (Key->GetTrigger(DIK_Z) == true)
		{
			m_nSetModelType--;
			if (m_nSetModelType < 0)
			{
				m_nSetModelType = (int)m_pAssistModel.size()-1;
			}
		}
		//ひとつ前のオブジェクトから順に消去する
		if (Key->GetTrigger(DIK_BACKSPACE) == true)
		{
			if ((int)m_pModel.size() > 0)
			{
				m_pModel[m_pModel.size() - 1]->Uninit();
				m_pModel.pop_back();
				m_nCnt--;

			}
		}
		break;
		//床配置の処理
	case TYPE_FIELD:
		//操作系
		if (m_pController != nullptr)
		{
			m_pController->AddTypeChange();

			m_pController->FieldMove(m_pos, m_Meshsize);
		}
		switch (m_nModeType)
		{
		case MODE_SET:
			//設置する用アシストCURSORの位置大きさの更新
			if (pAssistCursor != nullptr)
			{
				pAssistCursor->SetPos({ m_pos.x,m_pos.y + 0.1f,m_pos.z }, { m_size.x / 2.0f,0.0f,m_size.z / 2.0f });

			}
			//スペースか右クリックを押すとメッシュフィールドを生成する
			if (Key->GetTrigger(DIK_SPACE) == true || pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
			{
				CField *Securement = {};
				m_pField.push_back(Securement);
				m_pField[m_nMeshCnt] = CField::Create(m_pos, m_Meshsize, m_rot, m_nMeshNumX, m_nMeshNumZ, CTexture::FIELD);
				//メッシュフィールドの総数を増やす
				m_nMeshCnt++;
			}
			//メッシュフィールドの縦横の数の変更
			MeshNumChange();
			//メッシュフィールドの大きさの変更
			MeshSizeChange();

			break;
		case MODE_EDIT:
			//編集するメッシュフィールドの選択
			if (Key->GetTrigger(DIK_4) == true)
			{
				m_nSelectMeshField++;
				if (m_nSelectMeshField >= (int)m_pField.size())
				{
					m_nSelectMeshField = 0;
				}
				//位置を選択したモデルに合わせる
				if ((int)m_pField.size() != 0)
				{
					m_pos = m_pField[m_nSelectMeshField]->GetPos();

				}
			}
			else if (Key->GetTrigger(DIK_3) == true)
			{
				m_nSelectMeshField--;
				if (m_nSelectMeshField< 0)
				{
					m_nSelectMeshField = (int)m_pField.size() - 1;
				}
				//位置を選択したモデルに合わせる

				if ((int)m_pField.size() != 0)
				{
					m_pos = m_pField[m_nSelectMeshField]->GetPos();
				}
			}
			//モデルの位置回転更新
			if ((int)m_pField.size() != 0)
			{
				m_pField[m_nSelectMeshField]->SetPos(m_pos);
				//選択したモデルの消去
				if (Key->GetTrigger(DIK_DELETE) == true)
				{
					m_pField[m_nSelectMeshField]->Uninit();
					m_pField[m_nSelectMeshField] = nullptr;
					m_pField.erase(m_pField.begin() + m_nSelectMeshField);
					m_nMeshCnt--;
					if ((int)m_pField.size() != 0)
					{
						m_pos = m_pField[m_nSelectMeshField]->GetPos();

					}
				}

			}

			break;

		}

		//ひとつ前のオブジェクトから順に消去する
		if (Key->GetTrigger(DIK_BACKSPACE) == true)
		{
			if ((int)m_pField.size() > 0)
			{
				m_pField[m_pField.size() - 1]->Uninit();
				m_pField.pop_back();
				m_nMeshCnt--;

			}
		}
		break;
		//壁配置の処理
	case TYPE_WALL:
		Wall();
		break;
	case TYPE_ENEMY:
		Enemy();
		break;
	}
	//カーソルの回転更新
	if (pAssistCursor != nullptr)
	{
		pAssistCursor->SetRot(m_rot);
	}
	if (pAssistCursorWall != nullptr)
	{
		pAssistCursorWall->SetRot(m_rot);
	}

	if (Key->GetTrigger(DIK_F10))
	{
		m_bIsCulling = m_bIsCulling ? false : true;
	}
	if (Key->GetTrigger(DIK_F11))
	{
		m_bTextDraw = m_bTextDraw ? false : true;
	}
}
//==================================
//描画
//==================================

void CStageEditor::Draw()
{

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ

	//カリングできる状態なら
	if (m_bIsCulling)
	{
		pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// カリングをしてない
	}
	else
	{
		pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// カリングをしてない
	}
	//現在のマテリアルを取得
	D3DXMATRIX mtxRotModel, mtxTransModel;//計算用マトリックス
	D3DXMATRIX mtxParent;//親のマトリックス

	//各パーツのワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);
	if (m_pAssistModel[m_nSetModelType] != nullptr&&m_nSetType== TYPE_OBJECT&&m_nModeType == MODE_SET)
	{
		m_pAssistModel[m_nSetModelType]->SetDiffuse(0.3f);

		m_pAssistModel[m_nSetModelType]->Draw();

	}
	for (int Cnt = 0; Cnt < (int)m_pAssistEnemyModel.size(); Cnt++)
	{
		if (m_pAssistEnemyModel[Cnt] != nullptr&&m_nSetType == TYPE_ENEMY&&m_nModeType == MODE_SET)
		{
			m_pAssistEnemyModel[Cnt]->SetDiffuse(0.3f);
			m_pAssistEnemyModel[Cnt]->Draw();
		}
	}
	for (int nCnt = 0; nCnt < (int)m_pEnemyModel.size(); nCnt++)
	{
		//各パーツのワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
		switch (m_nModeType)
		{
		case MODE_SET:
			if (m_pEnemyModel[nCnt] != nullptr)
			{
				m_pEnemyModel[nCnt]->SetDiffuse(1.0f);
				m_pEnemyModel[nCnt]->Draw();
			}

			break;
		case MODE_EDIT:
			switch (m_nSetType)
			{
			case TYPE_OBJECT:
				if (m_pEnemyModel[nCnt] != nullptr)
				{
					m_pEnemyModel[nCnt]->SetDiffuse(1.0f);
					m_pEnemyModel[nCnt]->Draw();
				}
				break;
			case TYPE_FIELD:
				if (m_pEnemyModel[nCnt] != nullptr)
				{
					m_pEnemyModel[nCnt]->SetDiffuse(1.0f);
					m_pEnemyModel[nCnt]->Draw();
				}
				break;
			case TYPE_WALL:
				if (m_pEnemyModel[nCnt] != nullptr)
				{
					m_pEnemyModel[nCnt]->SetDiffuse(1.0f);
					m_pEnemyModel[nCnt]->Draw();
				}
				break;
			case TYPE_ENEMY:

				if (m_pEnemyModel[nCnt] != nullptr)
				{
					//選択したモデル以外の透明度をもとに戻す
					if (nCnt != m_nSelectEnemy)
					{
						m_pEnemyModel[nCnt]->SetDiffuse(0.3f);
					}
					else
					{
						m_pEnemyModel[m_nSelectEnemy]->SetDiffuse(1.0f);
					}
					m_pEnemyModel[nCnt]->Draw();
				}
				break;

			}
			break;
		}
		//各パーツのワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	}

	for (int nCnt = 0; nCnt < (int)m_pModel.size(); nCnt++)
	{
		//各パーツのワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
		switch (m_nModeType)
		{
		case MODE_SET:
			if (m_pModel[nCnt] != nullptr)
			{
				m_pModel[nCnt]->SetDiffuse(1.0f);
				m_pModel[nCnt]->Draw();
			}

			break;
		case MODE_EDIT:
			switch (m_nSetType)
			{
			case TYPE_OBJECT:
				if (m_pModel[nCnt] != nullptr)
				{
					//選択したモデル以外の透明度をもとに戻す
					if (nCnt != m_nSelectModel)
					{
						m_pModel[nCnt]->SetDiffuse(0.3f);
					}
					else
					{
						m_pModel[m_nSelectModel]->SetDiffuse(1.0f);
					}
					m_pModel[nCnt]->Draw();
				}
				break;
			case TYPE_FIELD:
				if (m_pModel[nCnt] != nullptr)
				{
					m_pModel[nCnt]->SetDiffuse(1.0f);
					m_pModel[nCnt]->Draw();
				}
				break;
			case TYPE_WALL:
				if (m_pModel[nCnt] != nullptr)
				{
					m_pModel[nCnt]->SetDiffuse(1.0f);
					m_pModel[nCnt]->Draw();
				}
				break;

			}
			break;
		}
		//各パーツのワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	}

	//カーソルにカメラを追従
	CCamera *pCamera = CRenderer::GetCamera();
	switch (m_nModeType)
	{
	case MODE_SET:
		switch (m_nSetType)
		{
		case TYPE_OBJECT:
			pAssistCursor->SetDraw(true);
			pAssistCursorWall->SetDraw(true);
			pCamera->SetPlayerCamera(m_pos);
			break;
		case TYPE_FIELD:
			pAssistCursor->SetDraw(false);
			pAssistCursorWall->SetDraw(true);

			pCamera->SetPlayerCamera(m_pos);
			break;
		case TYPE_WALL:
			pAssistCursor->SetDraw(true);
			pAssistCursorWall->SetDraw(false);

			pCamera->SetPlayerCamera(m_pos);
			break;
		case TYPE_ENEMY:
			pAssistCursor->SetDraw(true);
			pAssistCursorWall->SetDraw(true);
			pCamera->SetPlayerCamera(m_pos);

			break;
		}
		break;
	case MODE_EDIT:
		switch (m_nSetType)
		{
		case TYPE_OBJECT:
			if ((int)m_pModel.size() != 0)
			{
				//カメラを選択したモデルに追従
				pCamera->SetPlayerCamera(m_pModel[m_nSelectModel]->GetMPos());
			}
			break;
		case TYPE_FIELD:
			for (int nCnt = 0; nCnt < (int)m_pField.size(); nCnt++)
			{
				if (m_pField[nCnt] != nullptr)
				{
					if (nCnt != m_nSelectMeshField)
					{
						m_pField[nCnt]->SetCol(0.5f);
					}
					else
					{
						m_pField[nCnt]->SetCol(1.0f);
					}
				}
			}
			if ((int)m_pField.size() != 0)
			{
				pCamera->SetPlayerCamera(m_pField[m_nSelectMeshField]->GetPos());
			}
			break;
		case TYPE_WALL:
			for (int nCnt = 0; nCnt < (int)m_pWall.size(); nCnt++)
			{
				if (m_pWall[nCnt] != nullptr)
				{
					if (nCnt != m_nSelectWall)
					{
						m_pWall[nCnt]->SetCol(0.5f);
					}
					else
					{
						m_pWall[nCnt]->SetCol(1.0f);
					}
				}
			}
			if ((int)m_pWall.size() != 0)
			{
				pCamera->SetPlayerCamera(m_pWall[m_nSelectWall]->GetPos());
			}
			break;
		case TYPE_ENEMY:
			if ((int)m_pEnemyModel.size() != 0)
			{
				//カメラを選択したモデルに追従
				pCamera->SetPlayerCamera(m_pEnemyModel[m_nSelectEnemy]->GetMPos());
			}
			break;
		}
		break;
	}
	if (m_bTextDraw)
	{
		Drawtext();
	}
}
//==================================
//デバッグ文字の描画
//==================================

void CStageEditor::Drawtext()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char *objType[500][TYPE_MAX];
	objType[0][TYPE_OBJECT] = "モデル";
	objType[0][TYPE_FIELD] = "床";
	objType[0][TYPE_WALL] = "壁";
	objType[0][TYPE_ENEMY] = "敵";

	char *ModeType[500][MODE_MAX];
	ModeType[0][MODE_SET] = "ステージに設置";
	ModeType[0][MODE_EDIT] = "ステージを編集";

	char str[5000];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n ステージエディタverAlpha0.1 \n");
	nNum += sprintf(&str[nNum], " [モード切替:(設置)F5.(編集)F6] %s \n", ModeType[0][m_nModeType]);
	nNum += sprintf(&str[nNum], " [オブジェクト選択:4.5] %s \n", ModeType[0][m_nModeType]);
	nNum += sprintf(&str[nNum], " [設置物の配置] 右クリックorスペース \n");
	nNum += sprintf(&str[nNum], " [カメラの回転] 左クリックをドラッグ \n");
	nNum += sprintf(&str[nNum], " [移動] ホイールクリックでドラッグorWASD \n");
	nNum += sprintf(&str[nNum], " [X軸の位置初期化] ←or→+Enter \n");
	nNum += sprintf(&str[nNum], " [Y軸の位置初期化] ↓+Enter \n");
	nNum += sprintf(&str[nNum], " [Z軸の位置初期化] ↑+Enter \n");
	nNum += sprintf(&str[nNum], " [全軸の位置初期化] Enter \n");

	nNum += sprintf(&str[nNum], " [%sを一つ前から消去] バックスペース \n", objType[0][m_nSetType]);
	nNum += sprintf(&str[nNum], " [設置物の種類:1,2] %s \n", objType[0][m_nSetType]);
	nNum += sprintf(&str[nNum], " [増加量(位置):LShift+(W,S)] %.2f \n", m_pController->GetAddSpeed());
	nNum += sprintf(&str[nNum], " [増加量(回転):LShift+(E,D)] %.2f \n", m_pController->GetAddRotSpeed());
	nNum += sprintf(&str[nNum], " [セーブ:F3(ファイル選択:F1.F2)] %s \n", m_sSaveFileName[m_nNumSaveFile]);
	nNum += sprintf(&str[nNum], " [ロード:F4(ファイル選択:F1.F2)] %s \n", m_sSaveFileName[m_nNumSaveFile]);

	switch (m_nSetType)
	{
	case TYPE_OBJECT:
		nNum += sprintf(&str[nNum], " [モデルタイプ:Z,C] %d \n", m_nSetModelType);

		switch (m_nModeType)
		{
		case MODE_SET:
			break;
		case MODE_EDIT:
			nNum += sprintf(&str[nNum], " [モデル選択:3,4] %d \n", m_nSelectModel);
			nNum += sprintf(&str[nNum], " [モデル消去] Deleteキー \n");

			break;
		}
		nNum += sprintf(&str[nNum], " [モデル数] %d \n", m_nCnt);

		nNum += sprintf(&str[nNum], " [Pos] X%.2f,Y%.2f,Z%.2f \n", m_pos.x, m_pos.y, m_pos.z);
		nNum += sprintf(&str[nNum], " [Rot] X%.2f,Y%.2f,Z%.2f \n", m_rot.x, m_rot.y, m_rot.z);

		break;
	case TYPE_FIELD:
		nNum += sprintf(&str[nNum], " [メッシュフィールドの横の数LShift+I,K] %d \n", m_nMeshNumX);
		nNum += sprintf(&str[nNum], " [メッシュフィールドの縦の数LShift+O,L] %d \n", m_nMeshNumZ);
		nNum += sprintf(&str[nNum], " [メッシュフィールド数] %d \n", m_nMeshCnt);
		nNum += sprintf(&str[nNum], " [Pos] X%.2f,Y%.2f,Z%.2f \n", m_pos.x, m_pos.y, m_pos.z);
		nNum += sprintf(&str[nNum], " [Rot] X%.2f,Y%.2f,Z%.2f \n", m_rot.x, m_rot.y, m_rot.z);
		nNum += sprintf(&str[nNum], " [size(xR.F,zT.G)] X%.2f,Y%.2f,Z%.2f \n", m_size.x, m_size.y, m_size.z);
		nNum += sprintf(&str[nNum], " [Meshsize(xI.K,zO.L)] X%.2f,Y%.2f,Z%.2f \n", m_Meshsize.x, m_Meshsize.y, m_Meshsize.z);

		break;
	case TYPE_WALL:
		nNum += sprintf(&str[nNum], " [メッシュフィールドの横の数I,K] %d \n", m_nMeshNumX);
		nNum += sprintf(&str[nNum], " [メッシュフィールドの縦の数O,L] %d \n", m_nMeshNumZ);
		nNum += sprintf(&str[nNum], " [メッシュフィールド数] %d \n", m_nMeshCnt);
		nNum += sprintf(&str[nNum], " [Pos] X%.2f,Y%.2f,Z%.2f \n", m_pos.x, m_pos.y, m_pos.z);
		nNum += sprintf(&str[nNum], " [Rot] X%.2f,Y%.2f,Z%.2f \n", m_rot.x, m_rot.y, m_rot.z);
		nNum += sprintf(&str[nNum], " [size(xR.F,zT.G)] X%.2f,Y%.2f,Z%.2f \n", m_size.x, m_size.y, m_size.z);
		nNum += sprintf(&str[nNum], " [Meshsize(xI.K,zO.L)] X%.2f,Y%.2f,Z%.2f \n", m_Meshsize.x, m_Meshsize.y, m_Meshsize.z);

		break;

	}


	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// テキスト描画
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}
//==================================
//メッシュフィールドの大きさの変更
//==================================

void CStageEditor::MeshSizeChange()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (m_bShiftLock == true)
	{
		//X軸
		if (Key->GetTrigger(DIK_R) == true)
		{
			m_Meshsize.x += m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };

		}
		else if (Key->GetTrigger(DIK_F) == true)
		{
			m_Meshsize.x -= m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };

		}
		//Z軸
		if (Key->GetTrigger(DIK_T) == true)
		{
			m_Meshsize.z += m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };

		}
		else if (Key->GetTrigger(DIK_G) == true)
		{
			m_Meshsize.z -= m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };

		}
	}
	if (m_bCtrlLock == true)
	{
		//Y軸
		if (Key->GetTrigger(DIK_R) == true)
		{
			m_Meshsize.y += m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };

		}
		else if (Key->GetTrigger(DIK_F) == true)
		{
			m_Meshsize.y -= m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };

		}

	}
}
//==================================
//メッシュフィールドの倍率の変更
//==================================

void CStageEditor::MeshNumChange()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (m_bShiftLock == true)
	{
		if (Key->GetTrigger(DIK_I) == true)
		{
			m_nMeshNumX += (int)m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };
		}
		else if (Key->GetTrigger(DIK_K) == true)
		{
			m_nMeshNumX -= (int)m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };
		}
		if (Key->GetTrigger(DIK_O) == true)
		{
			m_nMeshNumZ += (int)m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };
		}
		else if (Key->GetTrigger(DIK_L) == true)
		{
			m_nMeshNumZ -= (int)m_pController->GetAddSpeed();
			m_size = { m_Meshsize.x *m_nMeshNumX ,m_Meshsize.y*m_nMeshNumZ,m_Meshsize.z *m_nMeshNumZ };
		}
	}

}
//==================================
//壁関係の配置処理
//==================================

void CStageEditor::Wall()
{
	CMouse *pMouse = CManager::GetMouse();

	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	//操作系
	if (m_pController != nullptr)
	{
		m_pController->AddTypeChange();

		m_pController->WallMove(m_pos, m_size);
	}
	switch (m_nModeType)
	{
	case MODE_SET:
		//設置する用アシストCURSORの位置大きさの更新
		if (pAssistCursorWall != nullptr)
		{
			pAssistCursorWall->SetPos({ m_pos.x,m_pos.y + 0.1f,m_pos.z }, { m_size.x / 2.0f,m_size.y / 2.0f ,0.0f});

		}
		//スペースか右クリックを押すとメッシュフィールドを生成する
		if (Key->GetTrigger(DIK_SPACE) == true || pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
		{
			CWall *Securement = {};
			m_pWall.push_back(Securement);
			m_pWall[m_nWallCnt] = CWall::Create(m_pos, m_Meshsize, m_rot, m_nMeshNumX, m_nMeshNumZ, CTexture::FIELD);
			//メッシュフィールドの総数を増やす
			m_nWallCnt++;
		}
		//メッシュフィールドの縦横の数の変更
		MeshNumChange();
		//メッシュフィールドの大きさの変更
		MeshSizeChange();

		break;
	case MODE_EDIT:
		//編集するメッシュフィールドの選択
		if (Key->GetTrigger(DIK_4))
		{
			m_nSelectWall++;
			if (m_nSelectWall >= (int)m_pWall.size())
			{
				m_nSelectWall = 0;
			}
			//位置を選択したモデルに合わせる
			if ((int)m_pWall.size() != 0)
			{
				m_pos = m_pWall[m_nSelectWall]->GetPos();
				m_rot = m_pWall[m_nSelectWall]->GetRot();

			}
		}
		else if (Key->GetTrigger(DIK_3) == true)
		{
			m_nSelectWall--;
			if (m_nSelectWall< 0)
			{
				m_nSelectWall = (int)m_pWall.size() - 1;
			}
			//位置を選択したモデルに合わせる

			if ((int)m_pWall.size() != 0)
			{
				m_pos = m_pWall[m_nSelectWall]->GetPos();
				m_rot = m_pWall[m_nSelectWall]->GetRot();

			}
		}
		//モデルの位置回転更新
		if ((int)m_pWall.size() != 0)
		{
			//位置を代入
			m_pWall[m_nSelectWall]->SetPos(m_pos);
			//回転を代入
			m_pWall[m_nSelectWall]->SetRot(m_rot);

			//選択したモデルの消去
			if (Key->GetTrigger(DIK_DELETE) == true)
			{
				m_pWall[m_nSelectWall]->Uninit();
				m_pWall[m_nSelectWall] = nullptr;
				m_pWall.erase(m_pWall.begin() + m_nSelectWall);
				m_nWallCnt--;
				if ((int)m_pWall.size() != 0)
				{
					m_pos = m_pWall[m_nSelectWall]->GetPos();
					m_rot = m_pWall[m_nSelectWall]->GetRot();

				}
			}

		}

		break;

	}

	//ひとつ前のオブジェクトから順に消去する
	if (Key->GetTrigger(DIK_BACKSPACE) == true)
	{
		if ((int)m_pWall.size() > 0)
		{
			m_pWall[m_pWall.size() - 1]->Uninit();
			m_pWall.pop_back();
			m_nWallCnt--;

		}
	}

}
//==================================
//メッシュフィールドの大きさの変更
//==================================
void CStageEditor::Enemy()
{
	CMouse *pMouse = CManager::GetMouse();

	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	if (m_pController != nullptr)
	{
		m_pController->MouseMove(m_pos);
		m_pController->TestMove(m_pos);
	}
	//モデルの回転の処理
	m_pController->AddTypeChange();
	switch (m_nModeType)
	{
	case MODE_SET:
		//スペースか右クリックを押したらモデル生成
		if (Key->GetTrigger(DIK_SPACE) == true || pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
		{
			CModel *Securement = {};
			m_pEnemyModel.push_back(Securement);
			m_pEnemyModel[m_nEnemyCnt] = CModel::Create(m_pos, m_rot, 4, CModel::TYPE_OBJECT);

			m_nEnemyCnt++;
		}
		//アシストモデルの位置回転更新
		if (m_pAssistEnemyModel[0] != nullptr)
		{
			m_pAssistEnemyModel[0]->SetPos(m_pos);
			m_pAssistEnemyModel[0]->SetRot(m_rot);
		}

		break;
	case MODE_EDIT:
		//編集するモデルの選択
		if (Key->GetTrigger(DIK_4) == true)
		{
			m_nSelectEnemy++;
			if (m_nSelectEnemy >= (int)m_pEnemyModel.size())
			{
				m_nSelectEnemy = 0;
			}
			//位置を選択したモデルに合わせる
			if ((int)m_pEnemyModel.size() != 0)
			{
				m_pos = m_pEnemyModel[m_nSelectEnemy]->GetMPos();
			}
		}
		else if (Key->GetTrigger(DIK_3) == true)
		{
			m_nSelectEnemy--;
			if (m_nSelectEnemy< 0)
			{
				m_nSelectEnemy = (int)m_pEnemyModel.size() - 1;
			}
			//位置を選択したモデルに合わせる

			if ((int)m_pEnemyModel.size() != 0)
			{
				m_pos = m_pEnemyModel[m_nSelectEnemy]->GetMPos();

			}
		}
		//モデルの位置回転更新
		if ((int)m_pEnemyModel.size() != 0)
		{
			m_pEnemyModel[m_nSelectEnemy]->SetPos(m_pos);
			m_pEnemyModel[m_nSelectEnemy]->SetRot(m_rot);
			//選択したモデルの消去
			if (Key->GetTrigger(DIK_DELETE) == true)
			{
				m_pEnemyModel[m_nSelectEnemy]->Uninit();
				m_pEnemyModel[m_nSelectEnemy] = nullptr;
				m_pEnemyModel.erase(m_pEnemyModel.begin() + m_nSelectEnemy);
				m_nEnemyCnt--;
				if ((int)m_pEnemyModel.size() != 0)
				{
					m_pos = m_pEnemyModel[m_nSelectEnemy]->GetMPos();

				}
			}

		}
		break;

	}
	////配置するモデルの選択
	//if (Key->GetTrigger(DIK_C) == true)
	//{
	//	m_nSetModelType++;
	//	if (m_nSetModelType >= (int)m_pAssistModel.size())
	//	{
	//		m_nSetModelType = 0;
	//	}
	//}
	//else if (Key->GetTrigger(DIK_Z) == true)
	//{
	//	m_nSetModelType--;
	//	if (m_nSetModelType < 0)
	//	{
	//		m_nSetModelType = (int)m_pAssistModel.size() - 1;
	//	}
	//}
	//ひとつ前のオブジェクトから順に消去する
	if (Key->GetTrigger(DIK_BACKSPACE) == true)
	{
		if ((int)m_pEnemyModel.size() > 0)
		{
			m_pEnemyModel[m_pEnemyModel.size() - 1]->Uninit();
			m_pEnemyModel.pop_back();
			m_nEnemyCnt--;

		}
	}

}
//==================================
//シフトを押した用の判定の処理
//==================================

void CStageEditor::ShiftLock()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (Key->GetPress(DIK_LSHIFT) == true)
	{
		m_bShiftLock = true;
	}
	else if (Key->GetPress(DIK_LSHIFT) == false)
	{
		m_bShiftLock = false;
	}
}
//==================================
//コントロールを押した用の判定の処理
//==================================

void CStageEditor::CtrlLock()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		m_bCtrlLock = true;
	}
	else if (Key->GetPress(DIK_LCONTROL) == false)
	{
		m_bCtrlLock = false;
	}
}
//==================================
//セーブ
//==================================

void CStageEditor::Save()
{

	std::ofstream ofs;//出力ストリーム
	ofs.open(m_sSaveFileName[m_nNumSaveFile]);

	if (ofs)
	{
		ofs << "+===========================+" << std::endl;
		ofs << "+     モデル配置の情報      +" << std::endl;
		ofs << "+===========================+" << std::endl;

		

		for (int nCnt = 0, nModelSize = (int)m_pModel.size(); nCnt < nModelSize; nCnt++)
		{
			//モデルデータの保存
			ofs <<"MODELSET" << std::endl;
			ofs << "	TYPE = " << m_pModel[nCnt]->GetModelType() << std::endl;
			ofs << "	POS = " << std::fixed<<setprecision(2) << m_pModel[nCnt]->GetMPos().x <<" "<<
																  m_pModel[nCnt]->GetMPos().y<<" " << 
																  m_pModel[nCnt]->GetMPos().z<<std::endl;

			ofs << "	ROT = " << std::fixed << setprecision(2) << m_pModel[nCnt]->GetRot().x << " " <<
															m_pModel[nCnt]->GetRot().y << " " <<
															m_pModel[nCnt]->GetRot().z << std::endl;
			ofs << "END_MODELSET" << std::endl;

		}
		ofs << "+===========================+" << std::endl;
		ofs << "+     敵配置の情報      +" << std::endl;
		ofs << "+===========================+" << std::endl;



		for (int nCnt = 0, nModelSize = (int)m_pEnemyModel.size(); nCnt < nModelSize; nCnt++)
		{
			//モデルデータの保存
			ofs << "ENEMYSET" << std::endl;
			ofs << "	POS = " << std::fixed << setprecision(2) << m_pEnemyModel[nCnt]->GetMPos().x << " " <<
				m_pEnemyModel[nCnt]->GetMPos().y << " " <<
				m_pEnemyModel[nCnt]->GetMPos().z << std::endl;
			ofs << "	ROT = " << std::fixed << setprecision(2) << m_pEnemyModel[nCnt]->GetRot().x << " " <<
				m_pEnemyModel[nCnt]->GetRot().y << " " <<
				m_pEnemyModel[nCnt]->GetRot().z << std::endl;
			ofs << "END_ENEMYSET" << std::endl;

		}

		ofs << "+===========================+" << std::endl;
		ofs << "+        壁配置の情報       +" << std::endl;
		ofs << "+===========================+" << std::endl;

		for (int nCnt = 0, nWallSize = (int)m_pWall.size(); nCnt < nWallSize; nCnt++)
		{
			//メッシュフィールドデータの保存
			ofs << "WALLSET" << std::endl;
			ofs << "	POS = " << std::fixed << setprecision(2) << m_pWall[nCnt]->GetPos().x << " " <<
				m_pWall[nCnt]->GetPos().y << " " <<
				m_pWall[nCnt]->GetPos().z << std::endl;
			float rotx = D3DXToDegree(m_pWall[nCnt]->GetRot().x);
			float roty = D3DXToDegree(m_pWall[nCnt]->GetRot().y);
			float rotz = D3DXToDegree(m_pWall[nCnt]->GetRot().z);

			ofs << "	ROT = " << std::fixed << setprecision(2) << rotx << " " <<
				roty << " " <<
				rotz << std::endl;

			ofs << "	SIZE = " << std::fixed << setprecision(2) << m_pWall[nCnt]->GetWallData().m_InitSize.x << " " <<
				m_pWall[nCnt]->GetWallData().m_InitSize.y << std::endl;
			ofs << "	BLOCK = " << m_pWall[nCnt]->GetWallData().m_nMax_Vtx_X << " " <<
				m_pWall[nCnt]->GetWallData().m_nMax_Vtx_Y << std::endl;
			ofs << "END_WALLSET" << std::endl;

		}

		ofs << "+===========================+" << std::endl;
		ofs << "+        床配置の情報       +" << std::endl;
		ofs << "+===========================+" << std::endl;

		for (int nCnt = 0, nFiledSize = (int)m_pField.size(); nCnt < nFiledSize; nCnt++)
		{
			//メッシュフィールドデータの保存
			ofs << "FIELDSET" << std::endl;
			ofs << "	POS = " << std::fixed << setprecision(2) << m_pField[nCnt]->GetPos().x << " " <<
				m_pField[nCnt]->GetPos().y << " " <<
				m_pField[nCnt]->GetPos().z <<  std::endl;
			ofs << "	SIZE = " << std::fixed << setprecision(2) << m_pField[nCnt]->GetFieldData().m_InitSize.x << " " <<
				m_pField[nCnt]->GetFieldData().m_InitSize.z << std::endl;
			ofs << "	BLOCK = " << m_pField[nCnt]->GetFieldData().m_nMax_Vtx_X << " " << 
									m_pField[nCnt]->GetFieldData().m_nMax_Vtx_Z << std::endl;
			ofs << "END_FIELDSET" << std::endl;

		}
		//終了用コマンド
		ofs << "END_SCRIPT" << std::endl;

	}
	ofs.close();

}
//==================================
//ロード
//==================================

void CStageEditor::Load()
{
	//オブジェクトやメッシュフィールドを生成していた場合初期化する
	for (int Cnt = 0; Cnt < (int)m_pModel.size(); Cnt++)
	{
		if (m_pModel[Cnt] != nullptr)
		{
			m_pModel[Cnt]->Uninit();
			m_pModel[Cnt] = nullptr;
		}
	}
	for (int Cnt = 0; Cnt < (int)m_pEnemyModel.size(); Cnt++)
	{
		if (m_pEnemyModel[Cnt] != nullptr)
		{
			m_pEnemyModel[Cnt]->Uninit();
			m_pEnemyModel[Cnt] = nullptr;
		}
	}
	for (int Cnt = 0; Cnt < (int)m_pField.size(); Cnt++)
	{
		if (m_pField[Cnt] != nullptr)
		{
			m_pField[Cnt]->Uninit();
			m_pField[Cnt] = nullptr;

		}
	}
	for (int nCnt = 0; nCnt < (int)m_pWall.size(); nCnt++)
	{
		if (m_pWall[nCnt] != nullptr)
		{
			m_pWall[nCnt]->Uninit();
			m_pWall[nCnt] = nullptr;
		}
	}

	m_pModel.clear();
	m_pField.clear();
	m_pWall.clear();
	m_pEnemyModel.clear();
	m_nCnt = 0;
	m_nMeshCnt = 0;
	m_nWallCnt = 0;
	m_nEnemyCnt = 0;

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
	FILE *pFile = fopen(m_sSaveFileName[m_nNumSaveFile], "r");
	// NULLチェック
	if (pFile != NULL)
	{
		// END_SCRIPTが呼ばれるまでループする
		while (1)
		{
			// １単語を読み込む
			fscanf(pFile, "%s", &sString[0]);
			//壁の読み込み
			while (strcmp(sString[0], "WALLSET") == 0)
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
					fscanf(pFile, "%f %f", &size.x, &size.y);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "END_WALLSET") == 0)
				{
					CWall *Securement = {};
					m_pWall.push_back(Securement);

					m_pWall[m_nWallCnt] = CWall::Create(pos, size, {D3DXToRadian(rot.x),D3DXToRadian(rot.y) ,D3DXToRadian(rot.z) }, nBlockX, nBlockY, CTexture::FIELD);
					m_nWallCnt++;
					break;
				}
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
					CField *Securement = {};
					m_pField.push_back(Securement);

					m_pField[m_nMeshCnt] = CField::Create(pos, size, {0.0f,0.0f,0.0f}, nBlockX, nBlockY, CTexture::FIELD);
					m_nMeshCnt++;
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
					CModel *Securement = {};
					m_pModel.push_back(Securement);
					//モデルの生成（位置、回転、モデルの種類、配置するオブジェクトのタイプ（プレイヤーか配置物かを判断している））
					m_pModel[m_nCnt] = CModel::Create(pos, rot, nType, CModel::TYPE_OBJECT);
					m_nCnt++;
					break;
				}
			}
			// 敵の読み込み
			while (strcmp(sString[0], "ENEMYSET") == 0)
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
				if (strcmp(sString[1], "SIZE") == 0)
				{
					fscanf(pFile, "%s", &sString[2]);	// イコールを噛ませる
					fscanf(pFile, "%f %f", &size.x, &size.z);	// イコールを噛ませる
				}
				if (strcmp(sString[1], "END_ENEMYSET") == 0)
				{
					CModel *Securement = {};
					m_pEnemyModel.push_back(Securement);
					//モデルの生成（位置、回転、モデルの種類、配置するオブジェクトのタイプ（プレイヤーか配置物かを判断している））
					m_pEnemyModel[m_nEnemyCnt] = CModel::Create(pos, rot, 4, CModel::TYPE_OBJECT);
					m_nEnemyCnt++;
					break;
				}
			}

			if (strcmp(sString[0], "END_SCRIPT") == 0)
			{
				break;
			}

		}
	}

	// ファイルを閉じる
	fclose(pFile);

}
//==================================
//キーを押すと数字が増減する処理
//==================================
void CStageEditor::SelectNum(int nKeyAdd, int nKeyDef, int& nSelectData, const int nAddNumber, const int nMax)
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (Key->GetTrigger(nKeyAdd) == true)
	{
		nSelectData += nAddNumber;
		if (nSelectData >= nMax)
		{
			nSelectData = 0;
		}

	}
	else if (Key->GetTrigger(nKeyDef) == true)
	{
		nSelectData -= nAddNumber;
		if (nSelectData< 0)
		{
			nSelectData = nMax - 1;
		}
	}

}

