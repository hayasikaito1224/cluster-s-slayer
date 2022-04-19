//--------------------------------------
//�^�C�g���̏���
//--------------------------------------
#ifndef _GAME_H
#define _GAME_H
#include "main.h"
#include "scene.h"

//�O���錾
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
	static CField		*m_pField;//��
	static CField		*m_pSea;//��
	static CPolygon		*m_Polygon;
	static CPolygon		*m_Cursol;
	static CMeshSphere	*m_pMeshSphere;
	static CStage		*m_pStage;
	static CParticle	*m_Particle;
	bool m_bPush;
	bool m_bEnd;
	int m_nCntDelay;//�f�B���C�̃J�E���^
	float				m_fAlpha;
	bool				m_bNextMode;//��d�����h�~�ϐ�
	int					m_nTimer;//�J�E���^�[
	CScene3D			*m_pFlore;//��
};


#endif //_RESULT_H