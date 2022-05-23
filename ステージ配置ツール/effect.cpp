#include "main.h"
#include "effect.h"
#include "manager.h"
#include "renderer.h"
#include "Scene3D.h"

CEffect::CEffect(OBJTYPE nPriority) : CScene(nPriority)
{
	m_col = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
}

CEffect::~CEffect()
{

}

//---------------------------------------------------
//インスタンス生成
//---------------------------------------------------
CEffect * CEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 m_move, D3DXVECTOR3 size, D3DXCOLOR col, bool bGravity, float fGravity, float ScaleSpeed, CTexture::Type type)
{//	位置, 移動量, サイズ,色, 小さくなるスピード
	//インスタンス生成
	CEffect *pEffect = new CEffect(OBJTYPE_EFFECT);
	pEffect->m_pos = pos;
	pEffect->m_size = size;
	pEffect->m_fScaleSpeed = ScaleSpeed;
	pEffect->m_move = m_move;
	pEffect->m_col = col;
	pEffect->m_TexType = type;
	pEffect->m_bGravity = bGravity;
	pEffect->m_fGravity = fGravity;
	if (pEffect != NULL)
	{
		//画像読み込み
		pEffect->Init();
	}

	return pEffect;
}

//----------------------------------------------------
//初期化処理
//-----------------------------------------------------
HRESULT CEffect::Init(CTexture::Type type)
{
	m_fRand = float(rand() %314/100.0f) - float(rand() % 314 + 314/100.0f);//z軸ランダム移動用
	return S_OK;
}

HRESULT CEffect::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ
																	 // 頂点情報を設定
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//テクスチャ画像の設定
	m_pTexture = CManager::GetTexture()->GetTexture(m_TexType);

	VERTEX_3D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(-m_size.x, +m_size.y, +m_size.z);
	pVtx[1].pos = D3DXVECTOR3(+m_size.x, +m_size.y, +m_size.z);
	pVtx[2].pos = D3DXVECTOR3(-m_size.x, -m_size.y, -m_size.z);
	pVtx[3].pos = D3DXVECTOR3(+m_size.x, -m_size.y, -m_size.z);

	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	m_pVtxBuff->Unlock();
	Setpos(m_pos, m_size);

	return S_OK;
}

//---------------------------------------------------------
//終了処理
//---------------------------------------------------------
void CEffect::Uninit()
{
	//頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	Release();
}

void CEffect::Update()
{
	//Setpos(m_pos, m_size);//頂点情報の設定
	SetCol_E(m_col);

	
	//移動処理
	m_pos += m_move;

	//フレーム回ルごとにサイズを小さくなる
	m_size.x -= m_fScaleSpeed;
	m_size.y -= m_fScaleSpeed;

	//明るさを下げる
	m_col.a -= 0.01;
	//m_col.g += 0.005;
	if (m_pos.y < 0.0f)
	{
		m_move.y *= -1;
		m_move.y /= 1.2f;
	}
	if (m_bGravity == true)
	{
		m_move.y -= m_fGravity;
	}
	//XとYのサイズが0になったら消す
	if (m_size.x <= 0 && m_size.y <=0)
	{
		Uninit();
	}
	//α値が0以下になったら消える
	if (m_col.a <= 0.0)
	{
		Uninit();
	}
}

void CEffect::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DXMATRIX mtxTrans;				//位置計算用マトリックス
	D3DXMATRIX mtxScale;				//スケール計算用マトリックス
										//ライト無効
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	//αテスト
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	//加算合成に設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	D3DXMatrixIdentity(&m_mtxWorld);//ワールドマトリックスの初期化


	pDevice->GetTransform(D3DTS_VIEW, &m_mtxView);//ビューマトリックスを取得


												  //ポリゴンをカメラに対して正面に向ける
												  //逆行列を求める	
	m_mtxWorld._11 = m_mtxView._11 * m_size.x;
	m_mtxWorld._12 = m_mtxView._21 * m_size.x;
	m_mtxWorld._13 = m_mtxView._31 * m_size.x;
	m_mtxWorld._21 = m_mtxView._12 * m_size.y;
	m_mtxWorld._22 = m_mtxView._22 * m_size.y;
	m_mtxWorld._23 = m_mtxView._32 * m_size.y;
	//m_mtxWorld._31 = m_mtxView._13;
	//m_mtxWorld._32 = m_mtxView._23;
	//m_mtxWorld._33 = m_mtxView._33;

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);


	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	pDevice->SetFVF(FVF_VERTEX_3D);			//頂点フォーマットの設定

	pDevice->SetTexture(0, m_pTexture);	//テクスチャの設定

										//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//プリミティブの種類
		0,					//開始する頂点のインデックス
		2);					//描画するプリミティブ数

	//αテスト
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);

	//通常合成に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);


}

void CEffect::SetCol_E(D3DXCOLOR col)
{
	VERTEX_3D *pVtx;
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);

	m_pVtxBuff->Unlock();

}

void CEffect::Setpos(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	CScene::SetPos(pos);
	CScene::SetScale(scale);
	m_pos = pos;
	m_size = scale;

	VERTEX_3D *pVtx;
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(-m_size.x, m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_size.x, m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(-m_size.x, -m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_size.x, -m_size.y, 0.0f);

	m_pVtxBuff->Unlock();

}

