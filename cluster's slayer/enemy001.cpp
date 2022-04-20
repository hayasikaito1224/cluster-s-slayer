//-----------------------------
//敵の処理
//-----------------------------
#include "enemy001.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "layer_structure.h"
#include "game.h"
#include "player.h"
#include "collision.h"
#include "stage.h"
#include "sound.h"
#include "effect.h"
#include "gauge.h"
#include "Particle.h"
#include "wall.h"
#include "map_polygon.h"
#include "shadow.h"
#include "motion.h"
#include "exp_ball.h"
static const float AttackStartNear = 150.0f;//攻撃を始めるまでのプレイヤーとの近さ
static const float AttackStartTime = 20.0f;//攻撃開始までの時間
static const int Power = 20;//攻撃力
static const int Life = 20;//体力
static const float MoveSpeed = 1.0f;//移動速度
static const int MinEXPNum = 3;//経験値を落とす数
static const int MaxEXPNum = 9;//経験値を落とす数

CEnemy001::CEnemy001(OBJTYPE nPriority) : CEnemy(nPriority)
{
	m_nPower = Power;
	m_fHitPoint = (float)Life;
	m_fMoveSpeed = MoveSpeed;
}

CEnemy001::~CEnemy001()
{

}
//----------------------------------
//インスタンス生成
//----------------------------------
CEnemy001 *CEnemy001::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CEnemy001 *pEnemy = NULL;
	pEnemy = new CEnemy001(OBJTYPE_ENEMY);
	pEnemy->m_pos = pos;
	pEnemy->m_rot = rot;
	pEnemy->Init();
	return pEnemy;
}
//----------------------------------
//初期化
//----------------------------------
HRESULT CEnemy001::Init()
{
	CEnemy::Init();
	m_nType = NONE;
	//ファイル読み込み
	CLayer_Structure *pLayer = NULL;
	pLayer = new CLayer_Structure;
	pLayer->SetLayer_Structure("data/TEXT/EnemyParts000.txt", m_pParts, CModel::TYPE_ENEMY);
	CModel *pmodel = new CModel;
	int nSize = m_pParts.size();
	if (!nSize)
	{
		m_fRadius = m_pParts[0]->GetMaxPos().x;
	}

	if (!m_pMotion)
	{
		m_pMotion = new CMotion;
		m_MotionType = 0;
		m_pMotion->MotionLoad("data/TEXT/poyo_motion.txt");
	}

	return S_OK;
}
//----------------------------------
//終了
//----------------------------------
void CEnemy001::Uninit()
{

	static std::random_device random;	// 非決定的な乱数生成器
	std::mt19937_64 mt(random());            // メルセンヌ・ツイスタの64ビット版、引数は初期シード
	std::uniform_real_distribution<> randEXPNum(MinEXPNum, MaxEXPNum);//経験値の数を乱数で決める
	int nExpNum = randEXPNum(mt);
	//経験値を落とす
	for (int nCnt = 0; nCnt < nExpNum; nCnt++)
	{
		CExp_Ball::Create(m_pos);
	}

	CEnemy::Uninit();
	Release();
}
//-----------------------------------------
//更新
//-----------------------------------------
void CEnemy001::Update()
{
	CEnemy::Update();
}
//-----------------------------------------
//描画
//-----------------------------------------
void CEnemy001::Draw()
{
	CEnemy::Draw();
}

//-----------------------------------------
//攻撃処理
//-----------------------------------------
void CEnemy001::AIAttack()
{
	//プレイヤーが攻撃範囲に入ったら
	if (m_fPlayerVecLength < AttackStartNear)
	{
		if (m_bAttack == false)
		{
			m_nAttackStartCnt++;
			//攻撃開始時間になったら
			if (m_nAttackStartCnt >= AttackStartTime)
			{
				m_nAttackStartCnt = 0;
				m_MotionType = ATTACK;
				m_bAttack = true;
				//攻撃音
				CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_SWORD_ATTACK);
				CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_SWORD_ATTACK, 0.7f);

			}

		}
	}
	else
	{
		m_nAttackStartCnt = 0;

	}

}
//-----------------------------------------
//移動処理
//-----------------------------------------
void CEnemy001::AIMove()
{
	if (m_fPlayerVecLength < MAX_COLRADIUS)
	{
		m_bMove = true;
		//自動で動くできるやつをオフにする
		m_bAIMove = false;
		m_bAIMoveStop = true;

	}
	//範囲外の時
	else
	{
		m_bMove = false;
		m_bAIMoveStop = false;

		s_bCntStop = true;
	}
	//自動移動ができるなら
	if (m_bMove)
	{
		m_rot.y = m_fAng + (D3DX_PI);
		//発射する方向を求める
		m_MoveSpeed.x = sinf(m_fAng)*MoveSpeed;
		m_MoveSpeed.z = cosf(m_fAng)*MoveSpeed;
		m_MotionType = MOVE;

		m_fWalkSoundInterval -= 0.1f;

		if (m_fWalkSoundInterval <= 0.0f)
		{
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENEMYWALK);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENEMYWALK, 0.6f);
			m_fWalkSoundInterval = 2.3f;
		}
		m_pos += m_MoveSpeed;

	}
	else
	{
		m_MotionType = NEUTRAL;
		m_MoveSpeed.x = 0.0f;
		m_MoveSpeed.y = 0.0f;
		m_MoveSpeed.z = 0.0f;
	}

}
//----------------------------------------------------------
//体力の増減
//----------------------------------------------------------
void CEnemy001::AddLife(int nLife)
{
	if (m_bDamage == true && m_bHitCollision == true)
	{
		int nDamege = nLife + m_nDefense;
		m_fHitPoint += nDamege;

	}
}

void CEnemy001::AddLife(int nPower, int nType)
{
	if (m_bDamage == true)
	{
		float fDamege = 0;
		switch (nType)
		{
		case FIRE:
			fDamege = (nPower + m_nDefense)*1.5f;

			break;
		case BULLIZAD:
			fDamege = nPower + m_nDefense;

			break;
		}
		m_fHitPoint += fDamege;

	}

}
