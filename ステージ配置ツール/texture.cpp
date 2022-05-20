//=============================================================================
//
// テクスチャ処理 [texture.cpp]
// Author : 羽鳥太一作
//
//=============================================================================
//=============================================================================
// インクルード
//=============================================================================
#include "texture.h"
#include "Renderer.h"
#include "manager.h"

//=============================================================================
// デフォルトコンストラクタ
//=============================================================================
CTexture::CTexture()
{

}

//=============================================================================
// デフォルトデストラクタ
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// テクスチャの生成
//=============================================================================
void CTexture::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice; //デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();	//デバイスを取得する

	D3DXCreateTextureFromFile(pDevice,
		"",	// 無し
		&m_pTexture[None]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Flor000.png",//仮テクスチャ
		&m_pTexture[Test]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Field000.jpg",//フィールド
		&m_pTexture[FIELD]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Graph-paper.png",//フィールド
		&m_pTexture[FIELD2]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number000.png",//数字
		&m_pTexture[TIME]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/fade.png",//数字
		&m_pTexture[FADE]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/shadow000.jpg",//エフェクト
		&m_pTexture[Effect]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/stagecursor.png",//カーソル
		&m_pTexture[CURSOR]);

}

//=============================================================================
// 終了
//=============================================================================
void CTexture::Uniinit(void)
{
	for (int nCntTexture = 0; nCntTexture < Max; nCntTexture++)
	{
		//テクスチャの破棄
		if (m_pTexture[nCntTexture] != NULL)
		{
			m_pTexture[nCntTexture]->Release();
			m_pTexture[nCntTexture] = NULL;
		}
	}
}