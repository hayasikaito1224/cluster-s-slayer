#ifndef _MISSILE_H
#define _MISSILE_H
#include "scene.h"
class CModel;
class C3DPolygon;
class CMissile : public CScene
{
public:
	CMissile(OBJTYPE nPriority = CScene::OBJTYPE_EFFECT);
	~CMissile();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetMaxTime(float fTime) { m_fMaxTime = fTime; }
	void LaunchMissile();
	void SearchEnemy(const D3DXVECTOR3 EnemyPos,const float fRadius);
	static CMissile *Create();//インスタンス生成処理

private:
	D3DXVECTOR3	m_Scale;//敵の大きさ
	D3DXVECTOR3 *m_pEnemyPos;
	float m_fIntervalTimer;//ミサイル発射まで数える
	float m_fMaxTime;
	float m_SearchRange;//ミサイルを打つ範囲
	int m_nCntSearch;//サーチ回数
	int m_nCntSearchMax;//最大サーチ数
	bool m_bCanSearch;
	bool m_bCanShotMissile;
	bool						m_bUninit;
	bool m_bDraw;
};


#endif // !_MISSILE_H

