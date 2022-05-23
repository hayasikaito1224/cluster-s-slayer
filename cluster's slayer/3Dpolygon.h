//=============================================================================
//
// 3DPOLYGON処理
//
//=============================================================================
#ifndef _3DPOLYGON_H_
#define _3DPOLYGON_H_

#include "main.h"
class CTexture;
class CModel;
class C3DPolygon
{

public:

	C3DPolygon();		//コンストラクタ
	~C3DPolygon();									//デストラクタ

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw(D3DXMATRIX ParentMtx);
	static C3DPolygon *Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot, const D3DXVECTOR3& scale, const int& nTexture, const D3DXCOLOR& col = { 1.0,1.0,1.0,1.0 });
	void SetParent(CModel *pParent) { m_pParentModel = pParent; }
	void SetParentMtx(D3DXMATRIX ParentMtx) { m_ParentMtx = ParentMtx; }
	void SetCanParent(bool bCan) { m_bCanParent = bCan; }
	void SetCanCulling(bool bCan) { m_bCanCulling = bCan; }

	void SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos() { return m_pos; }
	D3DXVECTOR3 GetScale() { return m_Scale; }
	void SetDraw(bool bDraw) { m_bDraw = bDraw; }
	D3DXCOLOR GetColor() { return m_col; }
	void SetCol(D3DXCOLOR col);
private:
	D3DXVECTOR3 m_Scale;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;
	D3DXCOLOR m_col;
	CModel *m_pParentModel;
	D3DXMATRIX m_ParentMtx;

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;				//頂点バッファへのポインタ
	D3DXMATRIX m_mtxWorld;
	LPDIRECT3DTEXTURE9		m_pTexture;				//テクスチャへのポインタ
	bool m_bCanParent;
	bool m_bDraw;
	bool m_bCanCulling;
};

#endif // _3DPOLYGON_H_

