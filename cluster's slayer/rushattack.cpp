//--------------------------------------------
//スキル追撃の処理
//作成者：林
//--------------------------------------------
#include "rushattack.h"
#include "game.h"
#include "player.h"
#include "model.h"
#include "Renderer.h"
#include "manager.h"
//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CRushAttack::CRushAttack(OBJTYPE nPriority): CScene(nPriority)
{
	m_pRushSword = nullptr;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CRushAttack::~CRushAttack()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CRushAttack::Init(void)
{
	if (!m_pRushSword)
	{
		m_pRushSword = CModel::Create({0.0f,0.0f,0.0f}, m_rot, 15, CModel::TYPE_PLAYER);
	}
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CRushAttack::Uninit(void)
{
	if (m_pRushSword)
	{
		m_pRushSword->Uninit();
		m_pRushSword = nullptr;
	}
	Release();
}
//--------------------------------------------
//更新
//--------------------------------------------
void CRushAttack::Update(void)
{
	//消去判定がオンなら
	if (m_bIsDeath)
	{
		Uninit();
	}
}

//--------------------------------------------
//描画
//--------------------------------------------
void CRushAttack::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ

	D3DXMATRIX mtxRotModel, mtxTransModel;//計算用マトリックス

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
	if (m_pRushSword)
	{
		m_pRushSword->Draw();
	}

}

void CRushAttack::UpperAttack()
{

}

CRushAttack * CRushAttack::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CRushAttack *pRushAttack = NULL;
	pRushAttack = new CRushAttack(OBJTYPE_MODEL);
	pRushAttack->m_pos = pos;
	pRushAttack->m_rot = rot;
	pRushAttack->Init();

	return pRushAttack;
}

