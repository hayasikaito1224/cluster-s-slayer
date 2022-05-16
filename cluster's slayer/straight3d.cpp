//=============================================================================
// (直線)3Dエフェクト処理 [Straight3D.cpp]
// Author : 佐藤秀亮
//=============================================================================
#include "Straight3D.h"

#include "renderer.h"
#include "Camera.h"
#include "manager.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CStraight3D::CStraight3D(int nPriority) : CBillEffect(nPriority)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CStraight3D::~CStraight3D()
{

}

//=============================================================================
// 初期化
//=============================================================================
HRESULT CStraight3D::Init(D3DXVECTOR3 pos,
	D3DXVECTOR3 Size,
	D3DXVECTOR3 MinSize,
	D3DXVECTOR3 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	int nType,
	int nLife,
	CStraight3D::MOVE_PATTERN Pattrn,
	D3DXVECTOR3 Target,
	int Synsetic)
{
	m_move = move;

	CBillEffect::Init(Size, MinSize, color, Mincolor, nType, nLife);
	m_nSynthenic = Synsetic;
	m_pCamera = CManager::GetRenderer()->GetCamera();
	m_Pattern = Pattrn;
	m_Target = Target;
	m_MinSize = MinSize;
	m_Size = Size;

	SetPos(pos,m_size);

	return S_OK;
}

//=============================================================================
// 終了
//=============================================================================
void CStraight3D::Uninit()
{
	CBillEffect::Uninit();
}

//=============================================================================
// 更新
//=============================================================================
void CStraight3D::Update()
{
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 v;	//計算
	float r;	//直線距離

	m_Size += m_MinSize;		//サイズ変更
	//サイズが0を下回りそう
	if (m_Size.x <= 0 ||
		m_Size.y <= 0)
	{
		m_bUninit = true;
	}

	if (m_Pattern == STRAIGHT)
	{
		pos += m_move;
	}
	else if(m_Pattern == TARGET)
	{
		v = pos - m_Target;
		r = sqrtf(v.x * v.x + v.z * v.z);
		m_XZr = (float)atan2(v.x, v.z);		//角度ｘｚ
		m_Yr = (float)atan2(v.x, v.y);		//角度ｙ

		pos += D3DXVECTOR3(
			sinf(m_XZr) * -m_move.x,	//X
			-m_move.x * sinf(m_Yr + D3DX_PI / 2),	//ｚ(ｙ)
			cosf(m_XZr) * -m_move.x);	//z

		if (r < 5)
		{
			m_bUninit = true;
		}
	}

	SetPos(pos, m_Size);
	ChangeSize(m_Size);

	CBillEffect::Update();
}

//=============================================================================
// 描画
//=============================================================================
void CStraight3D::Draw()
{
	CBillEffect::Draw();
}

//=============================================================================
// 作成
//=============================================================================
CStraight3D *CStraight3D::Create(D3DXVECTOR3 pos,
	D3DXVECTOR3 Size,
	D3DXVECTOR3 MinSize,
	D3DXVECTOR3 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	int nType,
	int nLife,
	CStraight3D::MOVE_PATTERN Pattrn,
	D3DXVECTOR3 Target,
	int Synsetic)
{
	CStraight3D *pStraight3D = new CStraight3D(OBJTYPE::OBJTYPE_EFFECT);

	if (pStraight3D != NULL)
	{
		pStraight3D->Init(pos, Size, MinSize, move, color, Mincolor, nType, nLife, Pattrn, Target,Synsetic);
	}

	return pStraight3D;
}
