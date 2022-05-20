#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "main.h"
//マクロ定義

#define PARTICLE_X (30)
#define PARTICLE_Y (30)
#define PARTICLE_Z (0)
typedef enum
{
	SET_EFFECT = 0,//テストタイプ
	SET_WORKEFFECT,		//移動時に出るエフェクト
	SET_CIRCLE,
	SET_HITDAMEGE,		//ダメージが発生した時のエフェクト
	SET_DESS,			//死んだときのエフェクト
} SetEffectType;//出すエフェクトのタイプ
typedef struct
{
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 size;
	D3DXVECTOR3 move;
	SetEffectType SetEffectType;//出すエフェクトのタイプ
	float fAngle;//角度
	float fSpeed;//速さ
	int nRand;
	int nParticleTimer;				//particleを出す間隔
	int nControl;//particleの出現制御
	bool bUse;//使用しているかどうか

} Particle;
//プロトタイプ宣言
void InitParticle(void);//初期化
void UninitParticle(void);//終了処理
void UpdateParticle(void);//更新
void DrawParticle(void);//描画
void SetParticle(D3DXVECTOR3 pos,SetEffectType SetEffectType);
void SetWorkParticle(int nPlayer, D3DXVECTOR3 pos);
Particle *GetParticle(void);

#endif // !_Billboard_H_


