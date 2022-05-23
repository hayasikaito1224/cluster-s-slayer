//-----------------------------------------
//プレイヤーの操作
//-----------------------------------------
#include "player_controller.h"
#include "camera.h"
#include "manager.h"
#include "keyboard.h"
#include "game.h"
#include "Renderer.h"
#include "XInput.h"

#include "scene.h"
#include "billboard.h"
#include "mouse.h"
#define PUSH_ONTIME (15)//長押し状態にするまでの時間

//--------------------------
//コンストラクト
//----------------------------
CPlayer_Controller::CPlayer_Controller()
{
	m_fAddSpeed[0] = 1.0f;
	m_fAddSpeed[1] = 5.0f;
	m_fAddSpeed[2] = 10.0f;
	m_fAddRotSpeed[0] = D3DXToRadian(10.0f);
	m_fAddRotSpeed[1] = D3DXToRadian(45.0);
	m_fAddRotSpeed[2] = D3DXToRadian(90.0f);
	m_nAddRotType = 1;
	m_nAddType = 1;
}
//--------------------------
//デストラクト
//----------------------------
CPlayer_Controller::~CPlayer_Controller()
{
}
//==================================
//長押しができるかを返す
//==================================

bool CPlayer_Controller::bLongOn()
{
	bool bLongOnPush = false;

	if (m_nCntPushTime >= PUSH_ONTIME)
	{
		bLongOnPush = true;
	}
	return bLongOnPush;

}
//==================================
//長押しの処理
//==================================

bool CPlayer_Controller::bLongKey(int nKey)
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	bool bLongOnKey = false;
	if (Key->GetPress(nKey) == true)
	{
		m_bPush = true;
		//長押しができるようになったら
		if (bLongOn() == true)
		{
			bLongOnKey = true;
		}
	}
	return bLongOnKey;
}
//==================================
//Shift,Alt,Ctrlを押すときの処理
//==================================
void CPlayer_Controller::LongPush()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	if (Key->GetPress(DIK_LSHIFT) == true)
	{
		m_bShiftLock = true;
	}
	else
	{
		m_bShiftLock = false;
	}
	if (Key->GetPress(DIK_LALT) == true)
	{
		m_bAltLock = true;
	}
	else
	{
		m_bAltLock = false;
	}
	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		m_bCtrlLock = true;
	}
	else
	{
		m_bCtrlLock = false;
	}
}
//----------------------------
//移動
//----------------------------
void CPlayer_Controller::TestMove(D3DXVECTOR3& pos)
{
	//Xの移動量
	float fvec_x = 0.0f;
	//Zの移動量
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();
	bool bLock = false;

	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		//上に進む
		bLock = true;
		if (Key->GetPress(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		//下に進む
		else if (Key->GetPress(DIK_S) == true)
		{
			pos.y -= m_fAddSpeed[m_nAddType];
		}

	}
	//前に進む
	if (bLock == false)
	{
		if (m_bShiftLock == false && m_bAltLock == false && m_bCtrlLock == false)
		{
			if (Key->GetPress(DIK_W) == true)
			{
				fvec_x += sinf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += cosf(0.0f)*m_fAddSpeed[m_nAddType];

			}
			//後ろに進む
			else if (Key->GetPress(DIK_S) == true)
			{
				fvec_x += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
			}
			//右に進む
			if (Key->GetPress(DIK_D) == true)
			{
				fvec_x += cosf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
			}
			//左に進む
			else if (Key->GetPress(DIK_A) == true)
			{
				fvec_x += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += sinf(0.0f)*m_fAddSpeed[m_nAddType];
			}

		}

	}


	//移動量があれば位置に移動量を加算する
	if (fvec_x != 0.0f || fvec_z != 0.0f)
	{
		//移動の長さを求める
		fLength = sqrt(fvec_x * fvec_x + fvec_z * fvec_z);

		float fnormal_x = fvec_x / fLength;
		float fnormal_z = fvec_z / fLength;

		fnormal_x *= m_fAddSpeed[m_nAddType];
		fnormal_z *= m_fAddSpeed[m_nAddType];

		pos.x += fnormal_x;
		pos.z += fnormal_z;
	}
	//X軸を初期化
	if (Key->GetPress(DIK_RIGHT) == true ||
		Key->GetPress(DIK_LEFT) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { 0.0f, pos.y, pos.z };

		}

	}
	//Y軸を初期化
	else if (Key->GetPress(DIK_DOWN) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, 0.0f, pos.z };

		}

	}
	//Z軸を初期化
	else if (Key->GetPress(DIK_UP) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, pos.y, 0.0f };

		}

	}
	//全ての軸を初期化
	else if (Key->GetTrigger(DIK_RETURN) == true)
	{
		pos = { 0.0f,0.0f,0.0f };

	}

}
//----------------------------
//移動
//----------------------------

void CPlayer_Controller::FieldMove(D3DXVECTOR3 & pos, const D3DXVECTOR3 size)
{
	//Xの移動量
	float fvec_x = 0.0f;
	//Zの移動量
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;

	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();
	bool bLock = false;

	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		//上に進む
		bLock = true;
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		//下に進む
		else if (Key->GetTrigger(DIK_S) == true)
		{
			pos.y -= m_fAddSpeed[m_nAddType];
		}
		if (bLongKey(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		else if (bLongKey(DIK_S) == true)
		{
			pos.y -= m_fAddSpeed[m_nAddType];
		}
	}
	if (bLock == false&& m_bShiftLock==false)
	{
		//前に進む
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*size.x;
			pos.z += cosf(0.0f)*size.z;

		}
		//後ろに進む
		else if (Key->GetTrigger(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*size.x;
			pos.z += -cosf(0.0f)*size.z;
		}
		//右に進む
		if (Key->GetTrigger(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*size.x;
			pos.z += -sinf(0.0f)*size.z;
		}
		//左に進む
		else if (Key->GetTrigger(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*size.x;
			pos.z += sinf(0.0f)*size.z;
		}
		//長押し
		//前に進む
		if (bLongKey(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*size.x;
			pos.z += cosf(0.0f)*size.z;
		}
		//後ろに進む
		else if (bLongKey(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*size.x;
			pos.z += -cosf(0.0f)*size.z;
		}
		//右に進む
		if (bLongKey(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*size.x;
			pos.z += -sinf(0.0f)*size.z;
		}
		//左に進む
		else if (bLongKey(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*size.x;
			pos.z += sinf(0.0f)*size.z;
		}

	}


	//X軸を初期化
	if (Key->GetPress(DIK_RIGHT) == true||
		Key->GetPress(DIK_LEFT) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = {0.0f, pos.y, pos.z };
		}

	}
	//Y軸を初期化
	else if (Key->GetPress(DIK_DOWN) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, 0.0f, pos.z };
		}

	}
	//Z軸を初期化
	else if (Key->GetPress(DIK_UP) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, pos.y, 0.0f };
		}

	}
	//全ての軸を初期化
	else if (Key->GetTrigger(DIK_RETURN) == true)
	{
		pos = { 0.0f,0.0f,0.0f };
	}

	if (Key->GetPress(DIK_W) == false &&
		Key->GetPress(DIK_A) == false &&
		Key->GetPress(DIK_S) == false &&
		Key->GetPress(DIK_D) == false)
	{
		m_bPush = false;
	}
	if (m_bPush == true)
	{
		m_nCntPushTime++;
	}
	else
	{
		m_nCntPushTime = 0;
	}

}
//========================================================
//壁の移動
//========================================================
void CPlayer_Controller::WallMove(D3DXVECTOR3 & pos, const D3DXVECTOR3 size)
{
	//Xの移動量
	float fvec_x = 0.0f;
	//Zの移動量
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;

	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();
	bool bLock = false;

	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		//上に進む
		bLock = true;
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		//下に進む
		else if (Key->GetTrigger(DIK_S) == true)
		{
			pos.y -= m_fAddSpeed[m_nAddType];
		}
		if (bLongKey(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		else if (bLongKey(DIK_S) == true)
		{
			pos.y -= m_fAddSpeed[m_nAddType];
		}
	}
	if (bLock == false && m_bShiftLock == false)
	{
		//前に進む
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += cosf(0.0f)*m_fAddSpeed[m_nAddType];

		}
		//後ろに進む
		else if (Key->GetTrigger(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//右に進む
		if (Key->GetTrigger(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//左に進む
		else if (Key->GetTrigger(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//長押し
		//前に進む
		if (bLongKey(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += cosf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//後ろに進む
		else if (bLongKey(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//右に進む
		if (bLongKey(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//左に進む
		else if (bLongKey(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}

	}


	//X軸を初期化
	if (Key->GetPress(DIK_RIGHT) == true ||
		Key->GetPress(DIK_LEFT) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { 0.0f, pos.y, pos.z };
		}

	}
	//Y軸を初期化
	else if (Key->GetPress(DIK_DOWN) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, 0.0f, pos.z };
		}

	}
	//Z軸を初期化
	else if (Key->GetPress(DIK_UP) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, pos.y, 0.0f };
		}

	}
	//全ての軸を初期化
	else if (Key->GetTrigger(DIK_RETURN) == true)
	{
		pos = { 0.0f,0.0f,0.0f };
	}

	if (Key->GetPress(DIK_W) == false &&
		Key->GetPress(DIK_A) == false &&
		Key->GetPress(DIK_S) == false &&
		Key->GetPress(DIK_D) == false)
	{
		m_bPush = false;
	}
	if (m_bPush == true)
	{
		m_nCntPushTime++;
	}
	else
	{
		m_nCntPushTime = 0;
	}

}
void CPlayer_Controller::MouseMove(D3DXVECTOR3 & pos)
{
	//Xの移動量
	float fvec_x = 0.0f;
	//Zの移動量
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();
	CMouse *pMouse = CManager::GetMouse();
	if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true)
	{
		//クリックした位置のマウス座標を取得
		GetCursorPos(&m_Cursol);

	}
	if (pMouse->GetPress(CMouse::MOUSE_WHEEL) == true)
	{
		SetCursorPos(m_Cursol.x, m_Cursol.y);

		//スティックの傾きの長さを求める
		fLength = (float)sqrt(pMouse->GetMousePos().lX * pMouse->GetMousePos().lX + pMouse->GetMousePos().lY * pMouse->GetMousePos().lY);
		fLength = fLength / 10.0f;
		float fRot = atan2f((float)pMouse->GetMousePos().lX, (float)pMouse->GetMousePos().lY);
		pos.x -= (sinf(-(fRot - pCamera->GetRot().x))*m_fAddSpeed[m_nAddType])*fLength;
		pos.z -= (cosf(-(fRot - pCamera->GetRot().x))*m_fAddSpeed[m_nAddType])*fLength;

	}
	//if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true)
	//{
	//	//クリックした位置のマウス座標を取得
	//	GetCursorPos(&m_Cursol);

	//}
	//if (pMouse->GetPress(CMouse::MOUSE_WHEEL) == true)
	//{
	//	SetCursorPos(m_Cursol.x, m_Cursol.y);

	//	//スティックの傾きの長さを求める
	//	fLength = (float)sqrt(pMouse->GetMousePos().lX * pMouse->GetMousePos().lX + pMouse->GetMousePos().lY * pMouse->GetMousePos().lY);
	//	fLength = fLength / 10.0f;

	//	float fRot = atan2f((float)pMouse->GetMousePos().lX, (float)pMouse->GetMousePos().lY);
	//	pos.y -= (cosf(fRot)*m_fAddSpeed[m_nAddType])*fLength;


	//}
}
void CPlayer_Controller::MouseFieldMove(D3DXVECTOR3 & pos, const D3DXVECTOR3 size)
{
	//Xの移動量
	float fvec_x = 0.0f;
	//Zの移動量
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();
	CMouse *pMouse = CManager::GetMouse();
	if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true)
	{
		//クリックした位置のマウス座標を取得
		GetCursorPos(&m_Cursol);

	}
	if (pMouse->GetPress(CMouse::MOUSE_WHEEL) == true)
	{
		SetCursorPos(m_Cursol.x, m_Cursol.y);
		//前に進む
		if (pMouse->GetMousePos().lX >= 1.0f)
		{
			pos.x += sinf(0.0f)*size.x;
			pos.z += cosf(0.0f)*size.z;

		}
		//後ろに進む
		else if (pMouse->GetMousePos().lX <= -1.0f)
		{
			pos.x += -sinf(0.0f)*size.x;
			pos.z += -cosf(0.0f)*size.z;
		}
		//右に進む
		if (pMouse->GetMousePos().lY >= 1.0f)
		{
			pos.x += cosf(0.0f)*size.x;
			pos.z += -sinf(0.0f)*size.z;
		}
		//左に進む
		else if (pMouse->GetMousePos().lY<= -1.0f)
		{
			pos.x += -cosf(0.0f)*size.x;
			pos.z += sinf(0.0f)*size.z;
		}

		////スティックの傾きの長さを求める
		//fLength = (float)sqrt(pMouse->GetMousePos().lX * pMouse->GetMousePos().lX + pMouse->GetMousePos().lY * pMouse->GetMousePos().lY);
		//fLength = fLength / 1000.0f;
		//float fRot = atan2f((float)pMouse->GetMousePos().lX, (float)pMouse->GetMousePos().lY);
		//pos.x -= (sinf(-(fRot - pCamera->GetRot().x)))*fLength*size.x;
		//pos.z -= (cosf(-(fRot - pCamera->GetRot().x)))*fLength*size.z;

	}

}

void CPlayer_Controller::ModelRot(D3DXVECTOR3 & rot)
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//右に回転
	if (Key->GetTrigger(DIK_E) == true)
	{
		rot.y += m_fAddRotSpeed[m_nAddRotType];
		if (rot.y > D3DX_PI)
		{
			rot.y = -D3DX_PI;
		}
	}
	else if (Key->GetTrigger(DIK_Q) == true)
	{
		rot.y -= m_fAddRotSpeed[m_nAddRotType];
		if (rot.y < -D3DX_PI)
		{
			rot.y = D3DX_PI;
		}
	}
}
//=============================================
//増加量の変更
//============================================
void CPlayer_Controller::AddTypeChange()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//増加量の変更
	if (m_bShiftLock == true)
	{
		if (Key->GetTrigger(DIK_W) == true)
		{
			m_nAddType++;
			if (m_nAddType >= NUM_ADD_SPEED)
			{
				m_nAddType = 0;
			}

		}
		else if (Key->GetTrigger(DIK_S) == true)
		{
			m_nAddType--;
			if (m_nAddType < 0)
			{
				m_nAddType = NUM_ADD_SPEED - 1;
			}

		}
		if (Key->GetTrigger(DIK_E) == true)
		{
			m_nAddRotType++;
			if (m_nAddRotType >= NUM_ADD_SPEED)
			{
				m_nAddRotType = 0;
			}

		}
		else if (Key->GetTrigger(DIK_D) == true)
		{
			m_nAddRotType--;
			if (m_nAddRotType < 0)
			{
				m_nAddRotType = NUM_ADD_SPEED - 1;
			}

		}

	}
}
//============================================
//テキスト描画
//============================================
void CPlayer_Controller::Drawtext(void)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[1200];
	int nNum = 0;
	CXInput *pXInput = CManager::GetXInput();
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();

	nNum = sprintf(&str[0], " \n\nカメラの向き %.5f,%.5f,%.5f  \n", pCamera->GetRot().x, pCamera->GetRot().y, pCamera->GetRot().z);
	nNum += sprintf(&str[nNum], " 視点 %.5f,%.5f,%.5f  \n", pCamera->GetPosV().x, pCamera->GetPosV().y, pCamera->GetPosV().z);
	nNum += sprintf(&str[nNum], " 注視点 %.5f,%.5f,%.5f  \n", pCamera->GetPosR().x, pCamera->GetPosR().y, pCamera->GetPosR().z);
	nNum += sprintf(&str[nNum], " カメラの距離 %.5f \n", pCamera->GetLong());


	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// テキスト描画
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}

//-------------------------------
//プレイヤーのカメラのコントロール
//--------------------------------

void CPlayer_Controller::MouseCameraControl()
{
	//キーボードの取得
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	CMouse *pMouse = CManager::GetMouse();
	//カメラの取得
	CCamera *pCamera = CRenderer::GetCamera();
	D3DXVECTOR3 PosV = pCamera->GetPosV();
	D3DXVECTOR3 PosR = pCamera->GetPosR();
	D3DXVECTOR3 Rot = pCamera->GetRot();
	float fLong = 0.0f;
	float fGetLong = pCamera->GetLong();
	fLong = (float)pMouse->GetMousePos().lZ / 5.0f*-1;


	//カメラの回転
	if (pMouse->GetTrigger(CMouse::MOUSE_RIGHT) == true)
	{
		//クリックした位置のマウス座標を取得
		GetCursorPos(&m_Cursol);

	}
	if (pMouse->GetPress(CMouse::MOUSE_RIGHT) == true)
	{

		SetCursorPos(m_Cursol.x, m_Cursol.y);
		Rot.y += (float)pMouse->GetMousePos().lY / 500.0f;
		Rot.x += (float)pMouse->GetMousePos().lX / 100.0f;
	}
	//カメラを初期化
	if (Key->GetPress(DIK_LSHIFT) == true)
	{
		m_bShiftLock = true;
		if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true&& m_bShiftLock==true)
		{
			Rot.x = 0.0f;
			Rot.y = -(D3DX_PI / 2.5f);
		}
	}
	if (Rot.y > -0.1f)
	{
		Rot.y = -0.1f;
	}
	else if (Rot.y < -2.0f)
	{
		Rot.y = -2.0f;
	}
	if (Rot.x > D3DX_PI)
	{
		Rot.x = -D3DX_PI;
	}
	else if (Rot.x < -D3DX_PI)
	{
		Rot.x = D3DX_PI;
	}

	//else if (pMouse->GetPress(CMouse::MOUSE_RIGHT) == true)
	//{
	//	SetCursorPos(m_Cursol.x, m_Cursol.y);
	//	m_rot.y += pMouse->GetMousePos().lX*0.001f;
	//	if (m_rot.y > D3DX_PI)
	//	{
	//		m_rot.y = -D3DX_PI;
	//	}
	//	m_posR.y += pMouse->GetMousePos().lY*-0.1f;
	//	m_posR.x = m_posV.x + sinf(m_rot.y)* m_fLong;
	//	m_posR.z = m_posV.z + cosf(m_rot.y)* m_fLong;
	//}
	pCamera->SetLong(fLong);
	if (fGetLong <= 10.0f)
	{
		pCamera->SetLong(-fGetLong);
	}

	PosV.x = PosR.x + sinf(Rot.y)* sinf(Rot.x) * pCamera->GetLong();
	PosV.y = PosR.y + cosf(Rot.y)			   * pCamera->GetLong();
	PosV.z = PosR.z + sinf(Rot.y)* cosf(Rot.x) * pCamera->GetLong();

	pCamera->SetPosR(PosR);
	pCamera->SetPosV(PosV);
	pCamera->SetRot(Rot);

}
