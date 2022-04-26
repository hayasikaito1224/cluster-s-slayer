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
class CGauge;

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
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	static CPlayer *GetPlayer() { return m_Player; }
	static CModel_Spawner	*GetModel() { return m_pModel; }
	static CScore			*GetScore() { return m_pScore; }
	static CMeshSphere		*GetMeshSphere() { return m_pMeshSphere; }
	static CPolygon			*GetCursol() { return m_Cursol; }
	static CParticle		*GetParticle() { return m_Particle; }
	static CGauge		*GetHPGauge() { return m_pHPGauge; }
	static CGauge		*GetExpGauge() { return m_pExpGauge; }

private:
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
	static CGauge	*m_pExpGauge;
	static CGauge	*m_pHPGauge;

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