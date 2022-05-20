#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene.h"

#include "motion.h"
class CSwordEffect;
class CLayer_Structure;
class CShadow;
class CPlayer_Controller;
class CMap_Polygon;
class CBillboard;
class CModel_Spawner;
//------------------------------------
//マクロ定義
//------------------------------------
#define PLAYER_POS_X (0.0)
#define PLAYER_POS_Y (0.0)
#define PLAYER_POS_Z (0.0)
#define PLAYER_FALL (-100.0)//落下判定に入るまでの位置

class CPlayer : public CScene
{
public:
	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_PLAYER);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Drawtext();

	//静的メンバー関数
	static CPlayer *Create();
	D3DXVECTOR3 GetLastPos() { return m_lastpos; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	D3DXVECTOR3 GetModelPos();
private:
	static vector<CModel*>		m_pSModel;//配置されたモデル

	CPlayer_Controller	*m_pController;//操作系のクラス
	D3DXVECTOR3 m_pos,m_lastpos,m_Swordpos[2],m_LastSwordpos[2]; //位置
	float m_Vec_x, m_Vec_y, m_Vec_z;
	float m_fLength;
	float m_move = 2.0f;
	D3DXVECTOR3 m_rot;												//向き
	D3DXMATRIX m_mtxWorld;											//ワールドマトリックス
	CModel_Spawner *m_pModel;
	CShadow *pShadow;
	bool	m_bland;												//地面についてるか判定
	bool	m_bColloison;											//当たり判定
	bool	m_bFall;												//落下判定
	bool	m_bMove;												// 移動判定
	bool	m_bDelay;												//次の処理に行くための間隔
	float	m_fSoundInterval;										//サウンドインターバル
	int     m_nTimer;
	int		m_nEffectTimer;
};


#endif // !_PLAYER_H_
