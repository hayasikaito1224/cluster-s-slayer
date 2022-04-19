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
class CModel_Spawner;
class CScore;
class CField;
class CMeshSphere;
class CParticle;
class CPolygon;
class CStage;
class CCamera;
class CEnemySpawnManager;

class CGame
{
public:
	typedef enum
	{
		LEVEL_EASY=0,
		LEVEL_NORMAL,
		LEVEL_HARD,
		LEVEL_MAX
	}LEVEL;

	CGame();
	~CGame();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(LPD3DXMATRIX mtrix);

	static CPlayer *GetPlayer(void) { return m_Player; }
	static CModel_Spawner	*GetModel(void) { return m_pModel; }
	static CScore			*GetScore(void) { return m_pScore; }
	static CMeshSphere		*GetMeshSphere(void) { return m_pMeshSphere; }
	static CPolygon			*GetCursol(void) { return m_Cursol; }
	static CParticle		*GetParticle(void) { return m_Particle; }

private:
	static std::vector<CPolygon*> m_pCStock;
	static CEnemySpawnManager		*m_pEnemySpawnManager;
	static CScore		*m_pScore;
	static CBg			*m_pBg;
	static CPlayer		*m_Player;
	static CModel_Spawner *m_pModel;
	static CField		*m_pField;//床
	static CField		*m_pSea;//床
	static CPolygon		*m_Polygon;
	static CPolygon		*m_Cursol;
	static CMeshSphere	*m_pMeshSphere;
	static CStage		*m_pStage;
	static CParticle	*m_Particle;
	bool m_bPush;
	bool m_bEnd;
	int m_nCntDelay;//ディレイのカウンタ
	float				m_fAlpha;
	bool				m_bNextMode;//二重押し防止変数
	int					m_nTimer;//カウンター
	CScene3D			*m_pFlore;//床
};


#endif //_RESULT_H