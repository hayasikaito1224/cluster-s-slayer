//-----------------------------------------
//�v���C���[�̑���
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
#define PUSH_ONTIME (15)//��������Ԃɂ���܂ł̎���

//--------------------------
//�R���X�g���N�g
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
//�f�X�g���N�g
//----------------------------
CPlayer_Controller::~CPlayer_Controller()
{
}
//==================================
//���������ł��邩��Ԃ�
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
//�������̏���
//==================================

bool CPlayer_Controller::bLongKey(int nKey)
{
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	bool bLongOnKey = false;
	if (Key->GetPress(nKey) == true)
	{
		m_bPush = true;
		//���������ł���悤�ɂȂ�����
		if (bLongOn() == true)
		{
			bLongOnKey = true;
		}
	}
	return bLongOnKey;
}
//==================================
//Shift,Alt,Ctrl�������Ƃ��̏���
//==================================
void CPlayer_Controller::LongPush()
{
	//�L�[�{�[�h�̎擾
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
//�ړ�
//----------------------------
void CPlayer_Controller::TestMove(D3DXVECTOR3& pos)
{
	//X�̈ړ���
	float fvec_x = 0.0f;
	//Z�̈ړ���
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	bool bLock = false;

	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		//��ɐi��
		bLock = true;
		if (Key->GetPress(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		//���ɐi��
		else if (Key->GetPress(DIK_S) == true)
		{
			pos.y -= m_fAddSpeed[m_nAddType];
		}

	}
	//�O�ɐi��
	if (bLock == false)
	{
		if (m_bShiftLock == false && m_bAltLock == false && m_bCtrlLock == false)
		{
			if (Key->GetPress(DIK_W) == true)
			{
				fvec_x += sinf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += cosf(0.0f)*m_fAddSpeed[m_nAddType];

			}
			//���ɐi��
			else if (Key->GetPress(DIK_S) == true)
			{
				fvec_x += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
			}
			//�E�ɐi��
			if (Key->GetPress(DIK_D) == true)
			{
				fvec_x += cosf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
			}
			//���ɐi��
			else if (Key->GetPress(DIK_A) == true)
			{
				fvec_x += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
				fvec_z += sinf(0.0f)*m_fAddSpeed[m_nAddType];
			}

		}

	}


	//�ړ��ʂ�����Έʒu�Ɉړ��ʂ����Z����
	if (fvec_x != 0.0f || fvec_z != 0.0f)
	{
		//�ړ��̒��������߂�
		fLength = sqrt(fvec_x * fvec_x + fvec_z * fvec_z);

		float fnormal_x = fvec_x / fLength;
		float fnormal_z = fvec_z / fLength;

		fnormal_x *= m_fAddSpeed[m_nAddType];
		fnormal_z *= m_fAddSpeed[m_nAddType];

		pos.x += fnormal_x;
		pos.z += fnormal_z;
	}
	//X����������
	if (Key->GetPress(DIK_RIGHT) == true ||
		Key->GetPress(DIK_LEFT) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { 0.0f, pos.y, pos.z };

		}

	}
	//Y����������
	else if (Key->GetPress(DIK_DOWN) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, 0.0f, pos.z };

		}

	}
	//Z����������
	else if (Key->GetPress(DIK_UP) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, pos.y, 0.0f };

		}

	}
	//�S�Ă̎���������
	else if (Key->GetTrigger(DIK_RETURN) == true)
	{
		pos = { 0.0f,0.0f,0.0f };

	}

}
//----------------------------
//�ړ�
//----------------------------

void CPlayer_Controller::FieldMove(D3DXVECTOR3 & pos, const D3DXVECTOR3 size)
{
	//X�̈ړ���
	float fvec_x = 0.0f;
	//Z�̈ړ���
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;

	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	bool bLock = false;

	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		//��ɐi��
		bLock = true;
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		//���ɐi��
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
		//�O�ɐi��
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*size.x;
			pos.z += cosf(0.0f)*size.z;

		}
		//���ɐi��
		else if (Key->GetTrigger(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*size.x;
			pos.z += -cosf(0.0f)*size.z;
		}
		//�E�ɐi��
		if (Key->GetTrigger(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*size.x;
			pos.z += -sinf(0.0f)*size.z;
		}
		//���ɐi��
		else if (Key->GetTrigger(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*size.x;
			pos.z += sinf(0.0f)*size.z;
		}
		//������
		//�O�ɐi��
		if (bLongKey(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*size.x;
			pos.z += cosf(0.0f)*size.z;
		}
		//���ɐi��
		else if (bLongKey(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*size.x;
			pos.z += -cosf(0.0f)*size.z;
		}
		//�E�ɐi��
		if (bLongKey(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*size.x;
			pos.z += -sinf(0.0f)*size.z;
		}
		//���ɐi��
		else if (bLongKey(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*size.x;
			pos.z += sinf(0.0f)*size.z;
		}

	}


	//X����������
	if (Key->GetPress(DIK_RIGHT) == true||
		Key->GetPress(DIK_LEFT) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = {0.0f, pos.y, pos.z };
		}

	}
	//Y����������
	else if (Key->GetPress(DIK_DOWN) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, 0.0f, pos.z };
		}

	}
	//Z����������
	else if (Key->GetPress(DIK_UP) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, pos.y, 0.0f };
		}

	}
	//�S�Ă̎���������
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
//�ǂ̈ړ�
//========================================================
void CPlayer_Controller::WallMove(D3DXVECTOR3 & pos, const D3DXVECTOR3 size)
{
	//X�̈ړ���
	float fvec_x = 0.0f;
	//Z�̈ړ���
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;

	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	bool bLock = false;

	if (Key->GetPress(DIK_LCONTROL) == true)
	{
		//��ɐi��
		bLock = true;
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.y += m_fAddSpeed[m_nAddType];
		}
		//���ɐi��
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
		//�O�ɐi��
		if (Key->GetTrigger(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += cosf(0.0f)*m_fAddSpeed[m_nAddType];

		}
		//���ɐi��
		else if (Key->GetTrigger(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//�E�ɐi��
		if (Key->GetTrigger(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//���ɐi��
		else if (Key->GetTrigger(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//������
		//�O�ɐi��
		if (bLongKey(DIK_W) == true)
		{
			pos.x += sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += cosf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//���ɐi��
		else if (bLongKey(DIK_S) == true)
		{
			pos.x += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//�E�ɐi��
		if (bLongKey(DIK_D) == true)
		{
			pos.x += cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += -sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}
		//���ɐi��
		else if (bLongKey(DIK_A) == true)
		{
			pos.x += -cosf(0.0f)*m_fAddSpeed[m_nAddType];
			pos.z += sinf(0.0f)*m_fAddSpeed[m_nAddType];
		}

	}


	//X����������
	if (Key->GetPress(DIK_RIGHT) == true ||
		Key->GetPress(DIK_LEFT) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { 0.0f, pos.y, pos.z };
		}

	}
	//Y����������
	else if (Key->GetPress(DIK_DOWN) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, 0.0f, pos.z };
		}

	}
	//Z����������
	else if (Key->GetPress(DIK_UP) == true)
	{
		if (Key->GetTrigger(DIK_RETURN) == true)
		{
			pos = { pos.x, pos.y, 0.0f };
		}

	}
	//�S�Ă̎���������
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
	//X�̈ړ���
	float fvec_x = 0.0f;
	//Z�̈ړ���
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	CMouse *pMouse = CManager::GetMouse();
	if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true)
	{
		//�N���b�N�����ʒu�̃}�E�X���W���擾
		GetCursorPos(&m_Cursol);

	}
	if (pMouse->GetPress(CMouse::MOUSE_WHEEL) == true)
	{
		SetCursorPos(m_Cursol.x, m_Cursol.y);

		//�X�e�B�b�N�̌X���̒��������߂�
		fLength = (float)sqrt(pMouse->GetMousePos().lX * pMouse->GetMousePos().lX + pMouse->GetMousePos().lY * pMouse->GetMousePos().lY);
		fLength = fLength / 10.0f;
		float fRot = atan2f((float)pMouse->GetMousePos().lX, (float)pMouse->GetMousePos().lY);
		pos.x -= (sinf(-(fRot - pCamera->GetRot().x))*m_fAddSpeed[m_nAddType])*fLength;
		pos.z -= (cosf(-(fRot - pCamera->GetRot().x))*m_fAddSpeed[m_nAddType])*fLength;

	}
	//if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true)
	//{
	//	//�N���b�N�����ʒu�̃}�E�X���W���擾
	//	GetCursorPos(&m_Cursol);

	//}
	//if (pMouse->GetPress(CMouse::MOUSE_WHEEL) == true)
	//{
	//	SetCursorPos(m_Cursol.x, m_Cursol.y);

	//	//�X�e�B�b�N�̌X���̒��������߂�
	//	fLength = (float)sqrt(pMouse->GetMousePos().lX * pMouse->GetMousePos().lX + pMouse->GetMousePos().lY * pMouse->GetMousePos().lY);
	//	fLength = fLength / 10.0f;

	//	float fRot = atan2f((float)pMouse->GetMousePos().lX, (float)pMouse->GetMousePos().lY);
	//	pos.y -= (cosf(fRot)*m_fAddSpeed[m_nAddType])*fLength;


	//}
}
void CPlayer_Controller::MouseFieldMove(D3DXVECTOR3 & pos, const D3DXVECTOR3 size)
{
	//X�̈ړ���
	float fvec_x = 0.0f;
	//Z�̈ړ���
	float fvec_z = 0.0f;
	float fLength = 0.0f;
	float fRot_Yx = 0.0f;
	float fRot_Yz = 0.0f;
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	CMouse *pMouse = CManager::GetMouse();
	if (pMouse->GetTrigger(CMouse::MOUSE_WHEEL) == true)
	{
		//�N���b�N�����ʒu�̃}�E�X���W���擾
		GetCursorPos(&m_Cursol);

	}
	if (pMouse->GetPress(CMouse::MOUSE_WHEEL) == true)
	{
		SetCursorPos(m_Cursol.x, m_Cursol.y);
		//�O�ɐi��
		if (pMouse->GetMousePos().lX >= 1.0f)
		{
			pos.x += sinf(0.0f)*size.x;
			pos.z += cosf(0.0f)*size.z;

		}
		//���ɐi��
		else if (pMouse->GetMousePos().lX <= -1.0f)
		{
			pos.x += -sinf(0.0f)*size.x;
			pos.z += -cosf(0.0f)*size.z;
		}
		//�E�ɐi��
		if (pMouse->GetMousePos().lY >= 1.0f)
		{
			pos.x += cosf(0.0f)*size.x;
			pos.z += -sinf(0.0f)*size.z;
		}
		//���ɐi��
		else if (pMouse->GetMousePos().lY<= -1.0f)
		{
			pos.x += -cosf(0.0f)*size.x;
			pos.z += sinf(0.0f)*size.z;
		}

		////�X�e�B�b�N�̌X���̒��������߂�
		//fLength = (float)sqrt(pMouse->GetMousePos().lX * pMouse->GetMousePos().lX + pMouse->GetMousePos().lY * pMouse->GetMousePos().lY);
		//fLength = fLength / 1000.0f;
		//float fRot = atan2f((float)pMouse->GetMousePos().lX, (float)pMouse->GetMousePos().lY);
		//pos.x -= (sinf(-(fRot - pCamera->GetRot().x)))*fLength*size.x;
		//pos.z -= (cosf(-(fRot - pCamera->GetRot().x)))*fLength*size.z;

	}

}

void CPlayer_Controller::ModelRot(D3DXVECTOR3 & rot)
{
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//�E�ɉ�]
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
//�����ʂ̕ύX
//============================================
void CPlayer_Controller::AddTypeChange()
{
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//�����ʂ̕ύX
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
//�e�L�X�g�`��
//============================================
void CPlayer_Controller::Drawtext(void)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[1200];
	int nNum = 0;
	CXInput *pXInput = CManager::GetXInput();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();

	nNum = sprintf(&str[0], " \n\n�J�����̌��� %.5f,%.5f,%.5f  \n", pCamera->GetRot().x, pCamera->GetRot().y, pCamera->GetRot().z);
	nNum += sprintf(&str[nNum], " ���_ %.5f,%.5f,%.5f  \n", pCamera->GetPosV().x, pCamera->GetPosV().y, pCamera->GetPosV().z);
	nNum += sprintf(&str[nNum], " �����_ %.5f,%.5f,%.5f  \n", pCamera->GetPosR().x, pCamera->GetPosR().y, pCamera->GetPosR().z);
	nNum += sprintf(&str[nNum], " �J�����̋��� %.5f \n", pCamera->GetLong());


	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// �e�L�X�g�`��
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}

//-------------------------------
//�v���C���[�̃J�����̃R���g���[��
//--------------------------------

void CPlayer_Controller::MouseCameraControl()
{
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	CMouse *pMouse = CManager::GetMouse();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	D3DXVECTOR3 PosV = pCamera->GetPosV();
	D3DXVECTOR3 PosR = pCamera->GetPosR();
	D3DXVECTOR3 Rot = pCamera->GetRot();
	float fLong = 0.0f;
	float fGetLong = pCamera->GetLong();
	fLong = (float)pMouse->GetMousePos().lZ / 5.0f*-1;


	//�J�����̉�]
	if (pMouse->GetTrigger(CMouse::MOUSE_RIGHT) == true)
	{
		//�N���b�N�����ʒu�̃}�E�X���W���擾
		GetCursorPos(&m_Cursol);

	}
	if (pMouse->GetPress(CMouse::MOUSE_RIGHT) == true)
	{

		SetCursorPos(m_Cursol.x, m_Cursol.y);
		Rot.y += (float)pMouse->GetMousePos().lY / 500.0f;
		Rot.x += (float)pMouse->GetMousePos().lX / 100.0f;
	}
	//�J������������
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
