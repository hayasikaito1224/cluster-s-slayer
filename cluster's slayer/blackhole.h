//-------------------------------------------
//ブラックホールの処理
//------------------------------------------
#ifndef _BLACKHOLE_H_
#define _BLACKHOLE_H_
#include "scene.h"
class CEnemy;

class CBlackHole : public CScene
{
public:
	CBlackHole(OBJTYPE nPriority);
	~CBlackHole();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Suction();//敵を吸い付ける処理
	void Head();
	//静的メンバー関数
	static CBlackHole *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CEnemy *pEnemy);

private:
	D3DXVECTOR3 m_pos;//位置
	D3DXVECTOR3 m_rot;//向き
	D3DXVECTOR3 m_scale;//大きさ
	D3DXMATRIX m_mtxWorld;//ワールドマトリックス
	CEnemy *m_pEnemyData;
	int m_nDeleteTimer;
	float m_fMoveSpeed;
	bool m_bUninit;
	bool m_bHoleExpansion;//ブラックホールの展開フラグ
};

#endif // !_BLACKHOLE_H_

