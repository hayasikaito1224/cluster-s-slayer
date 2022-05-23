//=============================================================================
// 球状処理 [Sphere.h]
// Author : 佐藤秀亮
//=============================================================================
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "main.h"
#include "scene3D.h"

class CSphere : public CScene3D
{
public:
	CSphere(int nPriority);	//コンストラクタ
	~CSphere();	//デストラクタ

	HRESULT Init(D3DXVECTOR3 pos, float rot, float fSize, int Vertical, int Line, CTexture::Type nTex, int Synthetic, float TexNum);
	void Uninit();
	void Update();
	void Draw();

	D3DXVECTOR3 GetSherePos() { return m_Pos; }

	void SetColor(D3DCOLORVALUE Color);
	void SetSize(D3DXVECTOR3 pos ,float Size);
	void Rotate(float Rotate);

	void SetTexUV(D3DXVECTOR2 TexUV);
	void SetAnimTexUV(D3DXVECTOR2 TexPattern);

protected:
	bool m_bUninit;	//抹消フラグ
	int m_nLife;	//寿命

	D3DXVECTOR2 m_PatternSize;
	int m_nAnimCount;
	int m_nSetAnimCnt;
	D3DXVECTOR2 m_nSplit;
	D3DXVECTOR2 m_MaxSplit;
private:
	LPDIRECT3DTEXTURE9 m_pTexture;	//テクスチャ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;	//頂点バッファへのポインタ
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuff = NULL;	//インデックスバッファ

	D3DXMATRIX m_mtxWorld;	//ワールドマトリックス
	D3DXVECTOR3 m_Pos;	//位置
	D3DXVECTOR2 m_TexUV;	//テクスチャ座標
	D3DXVECTOR2 m_TexMoveUV;	//テクスチャ座標の移動

	D3DXVECTOR2 m_PatternUV;

	float m_Rot;	//回転
	float m_Rot2;	//回転

	int m_nVertical;	//横の分割数
	int m_nLine;		//縦の分割数
	int m_nTex;		//テクスチャ

	int m_nVtx;	//頂点数
	int m_nIdx;	//インデックス数
	int m_Synthetic;	//合成

	float m_fRotate;	//回転

	float m_fRadius;	//半径
	int m_Primithive;	//プリミティブ

	static int m_nMaxTex;

};

#endif // !_MESHEFFECT_H_
