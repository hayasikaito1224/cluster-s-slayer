//-------------------------------------------
//ブラックホールの処理
//------------------------------------------
#include "blackhole.h"
#include "manager.h"
#include "Renderer.h"
#include "Particle.h"
#include "enemy.h"
#include "PresetSetEffect.h"
static const float MoveSpeedMax = 4.0f;
static const float MoveSpeedMin = 2.0f;
static const float HoleSpeed = 1.5f;
static const float HoleArea = 200.0f;
static const int DeleteTime = 200;
static const int HoleExpansionTime = 60;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CBlackHole::CBlackHole(OBJTYPE nPriority):CScene(nPriority)
{
	m_bHoleExpansion = false;
}

//--------------------------------------------
//デストラクタ
//--------------------------------------------
CBlackHole::~CBlackHole()
{
}

//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CBlackHole::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CBlackHole::Uninit(void)
{

	Release();
}
//--------------------------------------------
//更新
//--------------------------------------------
void CBlackHole::Update(void)
{
	m_nDeleteTimer++;
	if (m_pEnemyData)
	{
		bool bDeath = m_pEnemyData->GetDeath();
		if (bDeath)
		{
			m_pEnemyData = nullptr;
		}
	}
	if (m_nDeleteTimer >= HoleExpansionTime && !m_bHoleExpansion)
	{
		m_nDeleteTimer = 0;
		m_bHoleExpansion = true;
		CPresetEffect::SetEffect3D(0, m_pos, {}, {});
	}
	else if (m_nDeleteTimer >= DeleteTime && m_bHoleExpansion)
	{
		m_bUninit = true;
	}

	if (m_bHoleExpansion)
	{
		Suction();
	}
	else
	{
		//展開前のブラックホールの移動
		Head();
	}

	if (m_bUninit)
	{
		Uninit();
	}
}

//--------------------------------------------
//描画
//--------------------------------------------
void CBlackHole::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ


	D3DXMATRIX mtxRotModel, mtxTransModel, mtxScaleModel;//計算用マトリックス

														 //各パーツのワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);


	//向きを設定
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//向きを反映
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);

	//位置を設定
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	//位置を反映
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//各パーツのワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
}

void CBlackHole::Suction()
{
	//敵との当たり判定
	CScene *pScene_Enemy = CScene::GetScene(OBJTYPE_ENEMY);
	while (pScene_Enemy != NULL)
	{
		if (pScene_Enemy != NULL)
		{
			CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
			D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
			int nSize = pEnemy->GetParts().size();
			if (nSize != 0)
			{
				pEnemy->HoleAlign(m_pos, HoleArea, HoleSpeed);
			}

		}
		pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
	}

}
//--------------------------------------------
//ブラックホールが敵に向かう処理
//--------------------------------------------
void CBlackHole::Head()
{
	if (m_pEnemyData)
	{
		int nSize = m_pEnemyData->GetParts().size();
		if (nSize != 0)
		{
			D3DXVECTOR3 enemypos = m_pEnemyData->GetPos();
			D3DXVECTOR3 vec = m_pos - enemypos;
			float moveRot = atan2f(vec.x, vec.z);

			m_pos.x += cosf(-moveRot)*m_fMoveSpeed;
			m_pos.z += sinf(-moveRot)*m_fMoveSpeed;
			CParticle *pParticle = new CParticle;
			pParticle->RandomCircleParticle(m_pos, { 1.0,1.0,1.0,1.0 }, false);

		}

	}


}

//--------------------------------------------
//描画
//--------------------------------------------
CBlackHole * CBlackHole::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CEnemy *pEnemy)
{
	CBlackHole *pRushAttack = NULL;
	pRushAttack = new CBlackHole(OBJTYPE_EFFECT);
	pRushAttack->m_pos = pos;
	pRushAttack->m_pos.y = 30.0f;
	std::random_device random;	// 非決定的な乱数生成器

	std::mt19937_64 mt(random());            // メルセンヌ・ツイスタの64ビット版、引数は初期シード
	std::uniform_real_distribution<> randpeed(MoveSpeedMin, MoveSpeedMax);
	pRushAttack->m_fMoveSpeed = randpeed(mt);
	pRushAttack->m_rot = rot;
	pRushAttack->m_pEnemyData = pEnemy;
	pRushAttack->Init();

	return pRushAttack;
}