//=============================================-
//プレイヤーのクラス
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"
class CEnemy;
class CSword;

class CPlayer : public CCharacter
{
public:
	typedef enum
	{
		N_NEUTRAL = 0,
		N_MOVE,
		N_ATTACK_1,
		N_ATTACK_2,
		N_ATTACK_3,
		N_MAGIC_ATTACK,//魔法攻撃
		N_SKILL002,
		N_DETH,
		N_DODGE,
		N_MAX
	}N_MOTION;//通常状態のモーション

	typedef enum
	{
		COMBOWAIT = 0,
		COMBO_1,
		COMBO_2,
		COMBO_3,
		COMBO_MAX
	}COMBO;
	typedef enum
	{
		MOVEUP = 1,
		MOVEDOWN,
		MOVERIGHT,
		MOVELEFT
	}MOVEARROW;

	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_NONE);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CPlayer *Create();
	void KeyboardMove();//移動
	void PadMove();//移動
	void Attack();//通常攻撃
	void AttackCtrl();//通常攻撃の操作
	void MouseCameraCtrl();//マウスのカメラ操作
	void MagicAttack();//魔法攻撃
	void RockOn();//ロックオン
	void Dodge();//回避
	void NearEnemyFace();//近い敵の方向にプレイヤーを向かせる
	bool IsNearEnemyState();//今何の敵が近くにいるかを算出
private:
	void WeaponSet(const char *pcFileName);//武器のセット
	void FollowingPlayerCamera();//カメラがプレイヤーに追従する処理
	bool PushDifferentMoveKey(int nKey);//違う方向キーを押しているかの判定
	void Drawtext();
	bool IsMoveKeyCheck();//移動用のキーを押しているかの判定を返す処理
	bool FixedTimeInterval(float fMaxTime);//一定時間間隔をあける処理
	CSword *m_pSword;//剣
	POINT m_Cursol;
	void AttackMove(float fMoveVolume);
	CEnemy *m_pNearEnemy;//プレイヤーから近い敵の情報
	bool m_bNearEnemy;//敵が近くにいるのかの判定
	bool m_nMovePush;//移動キーを押しているかの判定
	bool m_bCanAttack;//攻撃ができるか？
	bool m_bCanAttackMove;//攻撃ができるか？
	bool m_bRevertCamera;
	bool m_bMoveStop;//移動を制限する
	bool m_bAttackWait;//最大コンボから最初のコンボに戻るときの待機のフラグ
	bool m_bAttackReception;//攻撃操作受付
	float m_fAttackWaitTime;//攻撃操作待機時間
	float m_fAttackMoveTime;//攻撃移動する時間
	float m_fSoundInterval;
	float m_fStopTime;//止まっている時間
	int m_nComboType;//今どのコンボかを数える
	int m_motionType;//モーションの種類
	int m_motionLastType;//前のモーションの種類
};

#endif // !_PLAYER_H_

