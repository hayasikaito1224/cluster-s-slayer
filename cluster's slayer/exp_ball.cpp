//--------------------------------------
//経験値玉の処理
//--------------------------------------
#include "exp_ball.h"
#include "billboard.h"
#include "gauge.h"
#include "manager.h"
#include "game.h"
#include "gaugeber.h"
static const float BallSize = 7.0f;//経験値玉の大きさ
//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CExp_Ball::CExp_Ball(OBJTYPE nPriority):CItem(nPriority)
{
	pItemObj = nullptr;
	m_fRadius = BallSize;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CExp_Ball::~CExp_Ball()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CExp_Ball::Init(void)
{
	//経験値玉用のビルボードを生成
	if (!pItemObj)
	{
		pItemObj = CBillboard::Create(m_pos, { m_fRadius ,m_fRadius ,0.0f }, CTexture::GlitterEffect);
	}
	CItem::Init();
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CExp_Ball::Uninit(void)
{

	CItem::Uninit();
	Release();
}
//--------------------------------------------
//更新
//--------------------------------------------
void CExp_Ball::Update(void)
{
	CItem::Update();
	if (m_IsDeath)
	{
		CGauge *pGauge = CManager::GetGame()->GetExpGauge();
		if (pGauge)
		{
			pGauge->SetGauge(-1, 0);
		}
	}
}

//--------------------------------------------
//描画
//--------------------------------------------
void CExp_Ball::Draw()
{
	CItem::Draw();
}
//--------------------------------------------
//インスタンス生成
//--------------------------------------------
CExp_Ball * CExp_Ball::Create(const D3DXVECTOR3 & pos)
{
	//インスタンス生成
	CExp_Ball *pExp_Ball = new CExp_Ball(OBJTYPE_ITEM);
	pExp_Ball->m_pos = { pos.x,pos.y+ (pExp_Ball->m_fRadius*2.0f),pos.z};
	if (pExp_Ball)
	{
		pExp_Ball->Init();
	}
	return pExp_Ball;
}


