#ifndef _EFFECT_H_
#define _EFFECT_H_
#include "scene.h"
#include "texture.h"

class CEffect : public CScene
{
public:
	typedef enum
	{
		VectorDelete = 0,//ベクトルの長さで消える
		TimeDelete		//時間で消える
	}DeleteType;
	CEffect(OBJTYPE nPriority = OBJTYPE_EFFECT);
	~CEffect();
	HRESULT Init(CTexture::Type type);
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void SetCol_E(D3DXCOLOR col);
	void Setpos(D3DXVECTOR3 pos, D3DXVECTOR3 scale);//頂点情報設定

	/*
	 位置の設定,
	 移動量,
	 サイズ,
	 小さくなるスピード
	 Texture
	*/
	static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 m_move, D3DXVECTOR3 size, D3DXCOLOR col,bool bGravity,float fGravity, float ScaleSpeed,CTexture::Type type = CTexture::Test);
	
private:
	float m_fGravity;//重力
	bool m_bGravity;
	DeleteType m_DeleteType;//エフェクトが消えるタイプ
	float		m_fDeleteTime;
	float		m_fDeleteVec;
	float		m_fDeleteMaxTime;
	float		m_fDeleteMaxVec;

protected:
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_size;
	D3DXCOLOR m_col;//色
	float m_fScaleSpeed;//サイズを小さくする変数
	int m_nLife;//寿命
	float m_fRand;
	CTexture::Type m_TexType;
	LPDIRECT3DTEXTURE9		m_pTexture = NULL;				//テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;				//頂点バッファへのポインタ
	D3DXMATRIX m_mtxWorld;									//ワールドマトリックス	
	D3DXMATRIX m_mtxView;									//ビューマトリックス

};


#endif // !_EFFECT_H_

