//#include "Main.h"
//#include "particle.h"
//#include "input.h"
//#include "sound.h"
//#include "effect.h"
//#include "player.h"
//#include "billboard.h"
//#define MAX_RADIUS (1)
////グローバル変数
//LPDIRECT3DTEXTURE9 g_pTextureParticle = NULL;//テクスチャへのポインタ
//LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffParticle = NULL;//	頂点バッファへのポインタ
//Particle g_aParticle[MAX_PARTICLE];
//int g_nParticleTimer;
//int g_nMaxParticle=10;
//bool bLicense;							//particleが出る許可の変数
//////////////////////////////////////////
////初期化処理
//////////////////////////////////////////
//void InitParticle(void)
//{
//	srand((unsigned int)time(NULL));
//
//	for (int nCnt = 0; nCnt < MAX_PARTICLE; nCnt++)
//	{
//		g_aParticle[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//		g_aParticle[nCnt].size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//		g_aParticle[nCnt].nRand = 0;
//		g_aParticle[nCnt].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//		g_aParticle[nCnt].nControl = 0;
//		g_aParticle[nCnt].fAngle = 0.0f;
//		g_aParticle[nCnt].fSpeed = 3.0f;
//		g_aParticle[nCnt].bUse = false;
//		g_aParticle[nCnt].SetEffectType = SET_EFFECT;
//		g_aParticle[nCnt].nParticleTimer = 0;
//	}
//	g_nParticleTimer = 0;
//	bLicense = false;
//}
////////////////////////////////////////
////終了処理
/////////////////////////////////////
//void UninitParticle(void)
//{
//	//テクスチャの破棄
//	if (g_pTextureParticle != NULL)
//	{
//		g_pTextureParticle->Release();
//		g_pTextureParticle = NULL;
//	}
//	//頂点バッファの破棄
//	if (g_pVtxBuffParticle != NULL)
//	{
//		g_pVtxBuffParticle->Release();
//		g_pVtxBuffParticle = NULL;
//	}
//}
///////////////////////////////////////////
////更新処理
//////////////////////////////////////////
//void UpdateParticle(void)
//{
//
//}
///////////////////////////////////////////////
////描画処理
//////////////////////////////////////////////
//void DrawParticle(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ
//	D3DXMATRIX mtxView;//ビューマトリックス取得用
//	D3DXMATRIX mtxTrans;//計算用マトリックス
//	pDevice = GetDevice();
//
//	for (int nCnt = 0; nCnt < MAX_PARTICLE; nCnt++)
//	{
//		if (g_aParticle[nCnt].bUse == true)
//		{
//			//ライティングを無効にする
//			pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
//			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
//			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
//
//			//ワールドマトリックスの初期化
//			D3DXMatrixIdentity(&g_aParticle[nCnt].mtxWorld);
//			//ビューマトリックスの取得
//			pDevice->GetTransform(D3DTS_VIEW, &mtxView);
//			////ポリゴンをカメラに対して正面に向ける
//			//D3DXMatrixInverse(&g_aBillboard[nCnt].mtxWorld, NULL, &mtxView);
//			g_aParticle[nCnt].mtxWorld._41 = 0.0f;
//			g_aParticle[nCnt].mtxWorld._42 = 0.0f;
//			g_aParticle[nCnt].mtxWorld._43 = 0.0f;
//
//			g_aParticle[nCnt].mtxWorld._11 = mtxView._11;
//			g_aParticle[nCnt].mtxWorld._12 = mtxView._21;
//			g_aParticle[nCnt].mtxWorld._13 = mtxView._31;
//
//			g_aParticle[nCnt].mtxWorld._21 = mtxView._12;
//			g_aParticle[nCnt].mtxWorld._22 = mtxView._22;
//			g_aParticle[nCnt].mtxWorld._23 = mtxView._32;
//
//			g_aParticle[nCnt].mtxWorld._31 = mtxView._13;
//			g_aParticle[nCnt].mtxWorld._32 = mtxView._32;
//			g_aParticle[nCnt].mtxWorld._33 = mtxView._33;
//
//			//位置を反映
//			D3DXMatrixTranslation(&mtxTrans, g_aParticle[nCnt].pos.x, g_aParticle[nCnt].pos.y, g_aParticle[nCnt].pos.z);
//
//			D3DXMatrixMultiply(&g_aParticle[nCnt].mtxWorld, &g_aParticle[nCnt].mtxWorld, &mtxTrans);
//			//ワールドマトリックスの設定
//			pDevice->SetTransform(D3DTS_WORLD, &g_aParticle[nCnt].mtxWorld);
//			//頂点バッファをでバスのでーたすとりーむに設定
//			pDevice->SetStreamSource(0, g_pVtxBuffParticle, 0, sizeof(VERTEX_3D));
//			pDevice->SetFVF(FVF_VERTEX_3D);//頂点フォーマットの設定
//			pDevice->SetTexture(0, g_pTextureParticle);
//
//			//ライティングを有効にする
//
//			pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
//			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
//			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
//
//		}
//	}
//
//}
//void SetParticle(D3DXVECTOR3 pos,SetEffectType SetEffectType)
//{
//	Player *pPlayer;
//	pPlayer = GetPlayer();
//
//	Effect *pEffect;
//	pEffect = GetEffect();
//
//
//	switch (SetEffectType)
//	{
//	case SET_EFFECT:
//		g_nParticleTimer++;
//		for (int nCnt = 0; nCnt < g_nMaxParticle; nCnt++)
//		{
//			g_aParticle[nCnt].fSpeed = float(rand() % 10 + 4);
//	/*		g_aParticle[nCnt].fSpeed = 6;*/
//			g_aParticle[nCnt].fAngle = float(rand() % MAX_RADIUS) - float(rand() % MAX_RADIUS);
//			float radion = D3DXToRadian(g_aParticle[nCnt].fAngle);
//			g_aParticle[nCnt].move = D3DXVECTOR3(sinf(radion)*g_aParticle[nCnt].fSpeed,
//				cosf(radion)*g_aParticle[nCnt].fSpeed,
//				0.0f);
//			SetEffect(pos, g_aParticle[nCnt].move, D3DXVECTOR3(0.0f, 0.0f, g_aParticle[nCnt].fAngle), SET_EFFECT);
//		}		
//		break;
//	case SET_WORKEFFECT:
//
//		for (int nCnt = 0; nCnt < 1; nCnt++, pEffect++)
//		{
//
//			if (g_nParticleTimer >= 10)
//			{
//				g_nParticleTimer = 0;
//				g_aParticle[nCnt].bUse = g_aParticle[nCnt].bUse ? false : true;
//			}
//
//			if (g_aParticle[nCnt].bUse == true)
//			{
//				float fAnglez = float(rand() % 314) / 100.0f - float(rand() % 314) / 60.0f;
//
//				g_aParticle[nCnt].fAngle = pPlayer->rot.y;
//				g_aParticle[nCnt].move = D3DXVECTOR3(0.0f, 0.8f,0.0f);
//				SetEffect(pos, g_aParticle[nCnt].move, D3DXVECTOR3(g_aParticle[nCnt].fAngle, 0.0f, fAnglez), SET_WORKEFFECT);
//				g_aParticle[nCnt].bUse = false;
//			}
//
//		}
//		break;
//	case SET_CIRCLE:
//
//		for (int nCnt = 0; nCnt < g_nMaxParticle; nCnt++)
//		{
//			g_aParticle[nCnt].fSpeed =3.0f;
//			g_aParticle[nCnt].fAngle = float(rand() % 314) / 100.0f - float(rand() % 314) / 60.0f;
//			g_aParticle[nCnt].move = D3DXVECTOR3(sinf(g_aParticle[nCnt].fAngle)*g_aParticle[nCnt].fSpeed,
//												 cosf(g_aParticle[nCnt].fAngle)*g_aParticle[nCnt].fSpeed,
//				(float(rand() % 314) / 100.0f - float(rand() % 314) / 100.0f)*1.5f);
//			SetEffect(pos, g_aParticle[nCnt].move, D3DXVECTOR3(0.0f, 0.0f, g_aParticle[nCnt].fAngle), SET_CIRCLE);
//		}
//		break;
//	case SET_HITDAMEGE:
//		for (int nCnt = 0; nCnt < g_nMaxParticle; nCnt++)
//		{
//			g_aParticle[nCnt].fSpeed = 3.0f;
//			g_aParticle[nCnt].fAngle = float(rand() % 314) / 100.0f - float(rand() % 314) / 60.0f;
//			g_aParticle[nCnt].move = D3DXVECTOR3(sinf(g_aParticle[nCnt].fAngle)*g_aParticle[nCnt].fSpeed,
//												 cosf(g_aParticle[nCnt].fAngle)*g_aParticle[nCnt].fSpeed,
//												(float(rand() % 314) / 100.0f - float(rand() % 314) / 100.0f)*1.5f);
//			SetEffect(pos, g_aParticle[nCnt].move, D3DXVECTOR3(0.0f, 0.0f, g_aParticle[nCnt].fAngle), SET_HITDAMEGE);
//
//		}
//		break;
//	case SET_DESS:
//		for (int nCnt = 0; nCnt < g_nMaxParticle; nCnt++)
//		{
//			g_aParticle[nCnt].fSpeed = 3.0f;
//			g_aParticle[nCnt].fAngle = float(rand() % 314) / 100.0f - float(rand() % 314) / 60.0f;
//			g_aParticle[nCnt].move = D3DXVECTOR3(sinf(g_aParticle[nCnt].fAngle)*g_aParticle[nCnt].fSpeed,
//				cosf(g_aParticle[nCnt].fAngle)*g_aParticle[nCnt].fSpeed,
//				(float(rand() % 314) / 100.0f - float(rand() % 314) / 100.0f)*1.5f);
//			SetEffect(pos, g_aParticle[nCnt].move, D3DXVECTOR3(0.0f, 0.0f, g_aParticle[nCnt].fAngle), SET_DESS);
//		}
//		break;
//	}
//}
//void SetWorkParticle(int nPlayer, D3DXVECTOR3 pos)
//{
//	Player *pPlayer;
//	pPlayer = GetPlayer();
//
//	Effect *pEffect;
//	pEffect = GetEffect();
//	
//	g_aParticle[nPlayer].nParticleTimer++;
//		float fAnglez = float(rand() % 314) / 100.0f - float(rand() % 314) / 60.0f;
//
//		g_aParticle[nPlayer].fAngle = pPlayer->rot.y;
//		g_aParticle[nPlayer].move = D3DXVECTOR3(0.0f, 0.8f, 0.0f);
//		if (g_aParticle[nPlayer].nParticleTimer >= 10)
//		{
//			g_aParticle[nPlayer].nParticleTimer = 0;
//			SetEffect(pos, g_aParticle[nPlayer].move, D3DXVECTOR3(g_aParticle[nPlayer].fAngle, 0.0f, fAnglez), SET_WORKEFFECT);
//
//		}
//
//}
//Particle *GetParticle(void)
//{
//	return &g_aParticle[0];
//}