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
	static CField		*m_pField;//��
	static CPolygon		*m_Polygon;
	static CMeshSphere	*m_pMeshSphere;
	static CStage		*m_pStage;
	bool				m_bNextMode;//��d�����h�~�ϐ�
	int					m_nTimer;//�J�E���^�[
};


#endif //_RESULT_H