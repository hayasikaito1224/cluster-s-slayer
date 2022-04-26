//--------------------------------------------
//スキル追撃の処理
//作成者：林
//--------------------------------------------
#ifndef _RASHATTACK_H_
#define _RASHATTACK_H_
#include "scene.h"
class CModel;

class CRushAttack:public CScene
{
public:

	CRushAttack(OBJTYPE nPriority);
	~CRushAttack();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void UpperAttack();
	//静的メンバー関数
	static CRushAttack *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
private:
	CModel *m_pRushSword;
	D3DXVECTOR3 m_pos;//位置
	D3DXVECTOR3 m_rot;//向き
	D3DXMATRIX m_mtxWorld;//ワールドマトリックス

	bool m_bIsDeath;
};


#endif // !_PLAYER_H_

