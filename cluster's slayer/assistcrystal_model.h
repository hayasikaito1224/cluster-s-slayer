//-------------------------------------------
//アシストクリスタルの処理
//------------------------------------------
#ifndef _ASSISTCRYSTAL_MODEL_H_
#define _ASSISTCRYSTAL_MODEL_H_
#include "scene.h"
class CPlayer;
class CModel;
class CAssistCrystal;
class CAssistCrystal_Model
{
public:
	CAssistCrystal_Model();
	~CAssistCrystal_Model();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//静的メンバー関数
	static CAssistCrystal_Model *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void SetMtx(D3DXMATRIX mtx) { m_mtxParent = mtx; }
private:
	D3DXVECTOR3 m_pos;//位置
	D3DXVECTOR3 m_rot;//向き
	D3DXMATRIX m_mtxWorld;//ワールドマトリックス
	CAssistCrystal *m_pParent;
	CModel *m_Crustal;
	CModel *m_TopFrame;
	CModel *m_BottomFrame;
	D3DXMATRIX	m_mtxParent;						//ワールドマトリックス
	int m_nDeleteTimer;
	int m_nBulletTimer;
	float m_fMoveSpeed;

	bool m_bMoveDirection;
	bool m_bUninit;
};

#endif // !_ASSISTCRYSTAL_MODEL_H_

