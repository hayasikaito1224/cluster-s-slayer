//-------------------------------------------
//アシストクリスタルの処理
//------------------------------------------
#ifndef _ASSISTCRYSTAL_H_
#define _ASSISTCRYSTAL_H_
#include "scene.h"
class CPlayer;
class CAssistCrystal_Model;
class CAssistCrystal 
{
public:
	CAssistCrystal();
	~CAssistCrystal();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//静的メンバー関数
	static CAssistCrystal *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CPlayer *pPlayer);
	void PlayerFollowing();
private:
	D3DXVECTOR3 m_pos;//位置
	D3DXVECTOR3 m_rot;//向き
	D3DXVECTOR3 m_scale;//大きさ
	D3DXMATRIX m_mtxWorld;//ワールドマトリックス
	CPlayer *m_pPlayer;
	CAssistCrystal_Model *m_CrystalModel;
	D3DXMATRIX	m_mtxParent;						//ワールドマトリックス
	float m_fInstallationAngle;//アシストクリスタルの設置場所
	int m_nDeleteTimer;
	float m_fMoveSpeed;
	bool m_bUninit;
};

#endif // !_ASSISTCRYSTAL_H_

