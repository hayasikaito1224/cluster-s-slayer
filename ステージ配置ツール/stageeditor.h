//----------------------------------
//ステージエディタの処理
//----------------------------------
#ifndef _STAGEEDITOR_H
#define _STAGEEDITOR_H
#include "scene.h"
#define NUM_SAVE_FILE (3)

class CModel;
class CScene3D;
class CPlayer_Controller;
class CField;
class CWall;

class CStageEditor : public CScene
{
public:
	typedef enum
	{
		TYPE_OBJECT=0,
		TYPE_FIELD,
		TYPE_WALL,
		TYPE_ENEMY,
		TYPE_MAX
	}TYPE;
	typedef enum
	{
		MODE_SET = 0,
		MODE_EDIT,
		MODE_MAX
	}MODE;
	CStageEditor(OBJTYPE nPriority = CScene::OBJTYPE_NONE);
	~CStageEditor();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Drawtext();
	void MeshSizeChange();
	void MeshNumChange();
	void Wall();//壁は位置関係の処理
	void Enemy();//敵の配置関係の処理
	void ShiftLock();
	void CtrlLock();

	void Save();
	void Load();
	void SelectNum(int nKeyAdd,int nKeyDef,int& nSelectData,const int nAddNumber,const int nMax);
private:
	CPlayer_Controller	*m_pController;//操作系のクラス
	static vector<CModel*>		m_pModel;//配置されたモデル
	static vector<CModel*>		m_pAssistModel;//配置されたモデル
	static vector<CModel*>		m_pAssistEnemyModel;//配置されたモデル
	static vector<CField*>		m_pField;//配置されたメッシュフィールド
	static vector<CWall*>		m_pWall;//配置された壁
	static vector<CModel*>		m_pEnemyModel;//配置する敵

	CScene3D *pAssistCursor;//配置場所を分かりやすくする用の板ポリゴン
	CScene3D *pAssistCursorWall;//配置場所を分かりやすくする用の板ポリゴン

	D3DXVECTOR3 m_pos, m_rot,m_size,m_Meshsize;
	D3DXMATRIX m_mtxWorld;											//ワールドマトリックス
	int m_nSetModelType;//設置するモデルのタイプ
	int m_nSetType;//設置するオブジェクトのタイプ
	int m_nCnt;
	int m_nMeshNumX;//メッシュフィールドの横の数
	int m_nMeshNumZ;//メッシュフィールドの縦の数
	int m_nMeshCnt;//メッシュフィールドの数
	int m_nWallCnt;//メッシュフィールドの数
	int m_nEnemyCnt;//敵の数
	int m_nNumSaveFile;//どのセーブファイルを選んでいるか
	int m_nModeType;
	int m_nSelectModel;//どのモデルを選択しているか
	int m_nSelectMeshField;//どのメッシュフィールドを選択しているか
	int m_nSelectWall;//どの壁を選択しているか
	int m_nSelectEnemy;
	bool m_bIsCulling;//カリングのオンオフ
	float m_fMoveSpeed;
	bool m_bShiftLock, m_bCtrlLock;
	char m_sSaveFileName[NUM_SAVE_FILE][100];
	bool m_bTextDraw;
};
#endif