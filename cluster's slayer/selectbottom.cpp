//--------------------------------------
//スキル説明表示用の処理
//--------------------------------------
#include "selectbottom.h"
#include "Polygon.h"
#include "input.h"
#include "keyboard.h"
#include "manager.h"
#include "mouse.h"
#include "frame.h"
#include "skillselect.h"
#include "player.h"
static const float IconSize = 50.0f;//アイコンの大きさ
static const D3DXVECTOR3 IconPos = {10.0f,-50.0f,0.0f};//アイコンの位置

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CSkillSelectBottom::CSkillSelectBottom(OBJTYPE nPriority) :CScene(nPriority)
{
	pSelectBottom = nullptr;
	m_bPopSelectBottom = true;
	m_bIsSelect = false;
	pSkillIcon = nullptr;
	pFrame = nullptr;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CSkillSelectBottom::~CSkillSelectBottom()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CSkillSelectBottom::Init(void)
{
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CSkillSelectBottom::Uninit(void)
{
	if (pSelectBottom)
	{
		pSelectBottom->Uninit();
		pSelectBottom = nullptr;
	}
	if (pFrame)
	{
		pFrame->Uninit();
		pFrame = nullptr;
	}
	if (pSkillIcon)
	{
		pSkillIcon->Uninit();
		pSkillIcon = nullptr;
	}
	Release();
}
//--------------------------------------------
//更新
//--------------------------------------------
void CSkillSelectBottom::Update(void)
{
	if (m_bPopSelectBottom)
	{
		//セレクトウィンドウの出現
		PopSelectBottom();
	}
	else
	{
		SelectBottom();
	}
	//終了判定がオンなら
	if (m_bEnd)
	{
		//終了処理を呼ぶ
		Uninit();
	}
}

//--------------------------------------------
//描画
//--------------------------------------------
void CSkillSelectBottom::Draw()
{

}
//-----------------------------------------------
//インスタンス生成
//---------------------------------------------
CSkillSelectBottom *CSkillSelectBottom::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const int& tex, const int& SkillType)
{
	CSkillSelectBottom *pSkillSelect = new CSkillSelectBottom(OBJTYPE_UI);
	if (pSkillSelect)
	{
		if (!pSkillSelect->pSelectBottom)
		{
			//スキル選択画面画像の生成
			pSkillSelect->pSelectBottom = CPolygon::Create(pos, size, (CTexture::Type)tex, { 1.0,1.0,1.0,0.0f });
		}
		int nTex = 0;
		pSkillSelect->m_nSkillNo = SkillType;
		switch (SkillType)
		{
		case CPlayer::ATKup:
			nTex = CTexture::ATKup;
			break;
		case CPlayer::Eye:
			nTex = CTexture::Eye;
			break;
		case CPlayer::Heal:
			nTex = CTexture::Heal;
			break;
		case CPlayer::OverHeal:
			nTex = CTexture::OverHeal;
			break;
		case CPlayer::Sheild:
			nTex = CTexture::Sheild;
			break;
		case CPlayer::Beam:
			nTex = CTexture::Beam;
			break;
		case CPlayer::BlackHole:
			nTex = CTexture::BlackHole;
			break;
		case CPlayer::Rocket:
			nTex = CTexture::Rocket;
			break;
		case CPlayer::RushAttack:
			nTex = CTexture::RushAttack;
			break;
		}
		if (!pSkillSelect->pSkillIcon)
		{
			//スキル選択画面画像の生成
			pSkillSelect->pSkillIcon = CPolygon::Create({ pos.x + IconPos.x,pos.y + IconPos.y,0.0f }, { IconSize ,IconSize ,0.0f}, (CTexture::Type)nTex, { 1.0,1.0,1.0,0.0f });

		}
		pSkillSelect->Init();
	}

	return pSkillSelect;
}
//-----------------------------------------------
//セレクトウィンドウの出現
//---------------------------------------------
void CSkillSelectBottom::PopSelectBottom()
{

	if (pSelectBottom)
	{
		D3DXCOLOR col = pSelectBottom->GetColor();
		D3DXVECTOR3 pos = pSelectBottom->GetPos();
		//透明から不透明になる処理
		if (col.a <= 1.0f)
		{
			col.a += 0.05f;
			pSelectBottom->SetCol(col);
		}
		//指定の位置に移動させる処理
		if (pos.y <= SCREEN_HEIGHT / 2.0f)
		{
			pos.y += 2.0f;
			pSelectBottom->SetPos(pos);
		}
		else
		{
			m_bPopSelectBottom = false;
		}
	}
	if (pSkillIcon)
	{
		D3DXCOLOR col = pSkillIcon->GetColor();
		D3DXVECTOR3 pos = pSkillIcon->GetPos();
		//透明から不透明になる処理
		if (col.a <= 1.0f)
		{
			col.a += 0.05f;
			pSkillIcon->SetCol(col);
		}
		//指定の位置に移動させる処理
		pos.y += 2.0f;
		pSkillIcon->SetPos(pos);
	}
}
//-----------------------------------------------
//スキル選択ボタンの選択処理
//---------------------------------------------
void CSkillSelectBottom::SelectBottom()
{
	//マウス情報の取得
	CMouse *pMouse = CManager::GetMouse();

	POINT po;
	//マウスのスクリーン座標の位置の取得
	GetCursorPos(&po);
	D3DXVECTOR3 pos = pSelectBottom->GetPos();
	D3DXVECTOR3 scale = pSelectBottom->GetScale();
	HWND hWnd = GetForegroundWindow();

	//スクリーン座標からクライアント座標の変換
	ScreenToClient(hWnd, &po);

	float MousePos_X = (float)po.x;
	float MousePos_Y = (float)po.y;
	//配置してあるポリゴンの範囲にカーソルが入ったら
	if (MousePos_X > pos.x- scale.x&&
		MousePos_X < pos.x + scale.x&&
		MousePos_Y > pos.y - scale.y&&
		MousePos_Y < pos.y + scale.y)
	{
		//選択状態にする
		m_bIsSelect = true;
		//選択されたポリゴンに枠を表示
		if (!pFrame)
		{
			pFrame = CFrame::Create(pos, scale, { 1.0,1.0,0.0,1.0 });
		}
		//選択している状態で左クリックをすると決定状態にする
		if (pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
		{
			m_bIsDecision = true;
		}
	}
	else
	{
		//選択状態を解除
		m_bIsSelect = false;
		if (pFrame)
		{
			pFrame->Uninit();
			pFrame = nullptr;
		}
	}
}
//-----------------------------------------------
//色の設定
//---------------------------------------------
void CSkillSelectBottom::SetCol(D3DXCOLOR col)
{
	if (pSelectBottom)
	{
		pSelectBottom->SetCol(col);
	}
}

