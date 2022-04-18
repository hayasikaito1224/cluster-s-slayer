//=============================================
//swordのクラス
//=============================================
#include "sword.h"
#include "manager.h"
#include "Renderer.h"
#include "model.h"
static const D3DXVECTOR3 HitCollisionPos = { 0.0f,50.0f,0.0f };//攻撃当たり判定の位置設定
//---------------------------------------------
//コンストラクタ
//---------------------------------------------
CSword::CSword() 
{
	m_bWeaponDraw = true;
	m_bCanHitCollision = false;
}

//-----------------------------------------------
//デストラクタ
//---------------------------------------------
CSword::~CSword()
{
}

//-----------------------------------------------
//初期化
//---------------------------------------------
HRESULT CSword::Init()
{
	if (!m_pWeapon)
	{
		//武器モデルの生成
		m_pWeapon = CModel::Create(m_pos, m_rot, 15, CModel::TYPE_PLAYER);
		//武器をどこに持たせるかの設定
		m_pWeapon->SetParent(m_pParent);
		//攻撃当たり判定の位置の設定
		m_HitCollision.m_pos = HitCollisionPos;
	}

	return S_OK;
}

//-----------------------------------------------
//終了
//---------------------------------------------
void CSword::Uninit()
{
	CWeapon::Uninit();

}

//-----------------------------------------------
//更新
//---------------------------------------------
void CSword::Update()
{
	CWeapon::Update();
	//攻撃当たり判定がオンなら
	if (m_bCanHitCollision)
	{
		//敵の情報を持ってきて当たり判定の処理をする
	}
}

//-----------------------------------------------
//描画
//---------------------------------------------
void CSword::Draw()
{
	CWeapon::Draw();
}
//----------------------------------------------
//インスタンス生成
//----------------------------------------------

CSword * CSword::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CModel *pParent)
{
	CSword *pSword = nullptr;
	pSword = new CSword;
	pSword->m_pos = pos;
	pSword->m_rot = rot;
	pSword->m_pParent = pParent;
	pSword->Init();

	return pSword;
}
