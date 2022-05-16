//--------------------------------------
//åoå±ílã ÇÃèàóùÇÃèàóù
//êßçÏé“ÅFó—
//--------------------------------------
#ifndef _EXP_BALL_H_
#define _EXP_BALL_H_
#include "item.h"

class CSound;

class CExp_Ball : public CItem
{
public:

	CExp_Ball(OBJTYPE nPriority = CScene::OBJTYPE_ITEM);
	~CExp_Ball();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CExp_Ball *Create(const D3DXVECTOR3& pos);

private:

};


#endif // !_PLAYER_H_

