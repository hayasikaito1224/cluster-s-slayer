//=============================================
//ïêäÌÇÃÉNÉâÉX
//=============================================
#ifndef _SWORD_H_
#define _SWORD_H_
#include "weapon.h"
class CModel;

class CSword : public CWeapon
{
public:
	CSword();
	~CSword();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CSword *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,CModel *pParent);

private:

};


#endif // !_SWORD_H_
