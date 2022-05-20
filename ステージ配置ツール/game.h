//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _GAME_H
#define _GAME_H
#include "main.h"
#include "scene.h"
//前方宣言
class CBg;
class CPlayer;
class CScene3D;
class CField;
class CMeshSphere;
class CPolygon;
class CStage;
class CCamera;

class CGame
{
public:
	
	CGame();
	~CGame();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(LPD3DXMATRIX mtrix);
	static CPlayer *GetPlayer(void) { return m_Player; }
	static CMeshSphere		*GetMeshSphere(void) { return m_pMeshSphere; }

private:
	static CBg			*m_pBg;
	static CPlayer		*m_Player;
	static CField		*m_pField;//床
	static CPolygon		*m_Polygon;
	static CMeshSphere	*m_pMeshSphere;
	static CStage		*m_pStage;
	bool				m_bNextMode;//二重押し防止変数
	int					m_nTimer;//カウンター
};


#endif //_RESULT_H