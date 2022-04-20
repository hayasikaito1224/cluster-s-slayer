#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"


class CSound;

#define MAX_KEYSET (10) //最大キーセット数
#define MAX_DRAWRADIUS (1000.0f)
#define MAX_COLRADIUS (400.0f)
#define MAX_ATTACKSTART_RADIUS (150.0f)//攻撃開始範囲
#define ENEMY_ADD_SPEED (0.2)//ゲージを増やす量
#define INVINCIBLE_TIME (30)//無敵時間
class CEnemy : public CCharacter
{
public:

	typedef enum
	{
		NEUTRAL = 0,
		MOVE,
		ATTACKWAIT,
		ATTACK,
		DETH,
		MAX
	}MOTION;

	typedef enum
	{
		NORMAL = 0,
		TYPE_MAX
	}ENEMY_TYPE;

	CEnemy(OBJTYPE nPriority = CScene::OBJTYPE_ENEMY);
	virtual ~CEnemy();
	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();
	virtual void Colision();
	virtual void AIAttack();
	virtual void AIMove();
	virtual void AddLife(int nPower, int nType);
	virtual void AddLife(int nLife);//体力の増減
	//静的メンバー関数
	static CEnemy *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void AIBehavior();//敵AIの挙動の処理
	void SetbDamage(bool bDamage) { m_bDamage = bDamage; }//ダメージを受けた状態にする
	bool GetbDamage(void) { return m_bDamage; }//ダメージを受けている状態か取得
	bool GetAIMove() { return m_bAIMove; }
	bool GetAIMoveStop() { return m_bAIMoveStop; }
	void SetHit(const bool& bHit) { m_bHit = bHit; }
	bool bHitAttack();//攻撃が当たってもいいかの判定
	bool GetHit() { return m_bHit; }
	bool GetbInvincible() { return m_bInvincible; }
	void Knockback(D3DXVECTOR3& Playerpos);
	void SetbHitCollision(bool bHitCollision) { m_bHitCollision = bHitCollision; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
private:
protected:
	std::random_device s_random;	// 非決定的な乱数生成器
	bool  m_bKnockback;//ノックバックするかどうかの判定
	bool m_bOnMissile;
	bool m_bDraw;
	bool m_bHit;//攻撃を受けたかどうか
	int  m_nTimer;
	float	m_fMovingRange;//敵が自動で動く距離
	int	m_nDefense;
	bool	m_bNeutral;
	bool	m_bMotionStop;//モーションが止まったかどうか
	bool	m_bDamage;//今攻撃を受けているか
	bool	m_bInvincible;//無敵時間の判定
	bool    m_bEffect;
	bool m_bHitCollision;//プレイヤーからの攻撃が当たるようにする判定
	D3DXVECTOR3 m_MoveSpeed; //位置
	float m_fAng;
	float s_CntTimer;//カウンター
	float s_MaxTimer;//カウンター
	float s_MovingCnt;//カウンター
	float s_MoveRandAng;//ランダムな向き
	float m_fWalkSoundInterval;
	bool  s_bCntStop;//ランダムな向き
	bool	m_bAIMoveStop;//敵が追従するときにAI動作を止める判定
	int	 m_nCntHitInterval;//プレイヤーからの攻撃が当たれるようになるまでカウンター
	float m_fSoundInterval;
	bool	m_bAttack;//今攻撃してるかどうか
	int		m_nAttackStartCnt;//攻撃開始までのカウント
	bool	m_bAIMove;	//敵が自動的に動く判定
	bool m_bMove;//移動判定
	D3DXVECTOR3 m_pos, m_rot, m_lastPos, m_Lotrot;
	float m_fPlayerVecLength;
	float m_fMoveSpeed;//移動量
	int	 m_MotionType,	m_MotionLastType;
	int					m_nPower;//攻撃力
	int	m_nType;//敵の種類
};


#endif // !_PLAYER_H_

