//----------------------------------
//ポリゴンの処理
//-----------------------------------
#include "camera.h"
#include "input.h"
#include "Renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "mouse.h"
#include "XInput.h"
//=============================================================================
// コンストラクタ
//=============================================================================
CCamera::CCamera()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CCamera::~CCamera()
{

}
//=============================================================================
// ポリゴンの初期化処理
//=============================================================================
HRESULT CCamera::Init(void)
{
	m_fLong = MAX_PLAYER_RANGE;
	m_posV = D3DXVECTOR3(0.0f, 0.0f, - m_fLong);
	m_posR = D3DXVECTOR3(0.0f, 80.0f,0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, -(D3DX_PI / 2.5f), 0.0f);


	return S_OK;
}

//=============================================================================
// ポリゴンの終了処理
//=============================================================================
void CCamera::Uninit(void)
{
}

//=============================================================================
// ポリゴンの更新処理
//=============================================================================
void CCamera::Update(void)
{

}

//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CCamera::Draw(void)
{

}
//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CCamera::SetPlayerCamera(D3DXVECTOR3 pos)
{
	m_posR = D3DXVECTOR3(pos.x, pos.y, pos.z);
}
//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CCamera::SetMapCamera(D3DXVECTOR3 pos)
{
	m_posR = D3DXVECTOR3(pos.x, 100.0f, pos.z);
	m_posV = D3DXVECTOR3(pos.x - sinf(m_rot.x),
		MAP_RANGE, pos.z - cosf(m_rot.x));


}
//設定
void CCamera::SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();
	//ビューポートの設定
	pDevice->SetViewport(&m_Viewport);

	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);
	//プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(m_fAngleView),//カメラの画角
		(float)m_Viewport.Width / (float)m_Viewport.Height,//画面比率!!!ビューポートを使うときビューポートの幅高さを使う
		10.0f,//手前の描画制限
		30000.0f);//奥の描画制限
				  //プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);
	//ビューマトリックスを作成
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);
	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

HRESULT CCamera::SetViewport(DWORD Xpos, DWORD Ypos, DWORD Width, DWORD Height, int nCnt)
{
	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();

	m_Viewport.X = Xpos;
	m_Viewport.Y = Ypos;
	m_Viewport.Width = Width;
	m_Viewport.Height = Height;
	m_Viewport.MinZ = 0.0f;
	m_Viewport.MaxZ = 1.0f;

	pDevice->SetViewport(&m_Viewport);
	return D3D_OK;
}
