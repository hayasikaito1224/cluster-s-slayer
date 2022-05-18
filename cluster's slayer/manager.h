//--------------------------------------
//�}�l�[�W���[�̏���
//--------------------------------------
#ifndef _MANAGER_H
#define _MANAGER_H
#include "main.h"

//�O���錾
class CInputKeyBoard;
class CRenderer;
class CTexture;
class CLight;
class CModel;
class CPlayer;
class CModel_Spawner;
class CTitle;
class CGame;
class CFade;
class CResult;
class CXInput;
class CDirectInput;
class CMouse;
class CSound;
class CPause;
class CXload;
class CGameMenu;

class CManager
{
public:
	typedef enum
	{
		MODE_TITLE=0,			//�^�C�g�����
		MODE_MENU,				//�Q�[���J�n�O�̃��j���[���
		MODE_GAME,				//�Q�[�����
		MODE_RESULT,			//���U���g���
		MODE_MAX
	}MODE;

	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
	void Uninit();
	void Update();
	void Draw();
	static CXload	 *GetXload() { return m_pXload; }
	static CRenderer *GetRenderer();
	static CInputKeyBoard *GetInputKeyboard();
	static CTexture *GetTexture();
	static CFade *GetFade(){ return m_Fade; }
	static CGame *GetGame(){ return m_pGame; }
	static void SetMode(MODE mode);						//���[�h�̐ݒ�
	static MODE GetMode();
	static bool GetPause() { return m_bPause; }
	static void SetPause(bool bPause, bool bStop = false) {
		m_bPause = bPause;
		m_bStop = bStop;
	}
	static void SetGameStop(bool bStop) { m_bStop = bStop; }

	static void SetEnd(bool bEnd)							{ m_bEnd = bEnd;}
	static CXInput *GetXInput()							{ return m_XInput; }
	static CMouse *GetMouse()							{ return m_Mouse; }
	static CSound *GetSound()							{ return m_pSound; }
	static CDirectInput *GetDirectInput()				{ return m_pDirectInput; }
	static bool GetClear()								{ return m_bClear; }
	static void SetClear(bool bClear)						{ m_bClear = bClear; }
	static HWND GethWnd() { return m_hWnd; }
	static int GetGameTime() { return m_nGameTime; }

private:
	static HWND m_hWnd;//���̃v���O�������g���Ă���E�B���h�E�̃n���h��
	static CRenderer		*m_pRenderer;
	static CInputKeyBoard	*m_pInputKeyboard;
	static CXInput			*m_XInput;
	static CTexture			*m_pTexture;
	static bool				m_bStop;
	static bool				m_bPause;
	static bool				m_bEnd;
	static CLight			*m_pLight[3];
	static CPlayer			*m_pPlayer;
	static CModel_Spawner	*m_pModel;
	static CTitle			*m_pTitle;
	static CGameMenu		*m_pGameMenu;
	static CGame			*m_pGame;
	static CResult			*m_pResult;
	static MODE				m_Mode;				//���݂̃��[�h
	static CFade			*m_Fade;
	static CMouse			*m_Mouse;
	static CDirectInput		*m_pDirectInput;
	static CSound			*m_pSound;
	static CPause			*m_pPause;
	static CXload			*m_pXload;			//X�t�@�C���̓ǂݍ��݃N���X
	static bool	m_bClear;					//�N���A�������̔���
	static float m_fTimer;
	static int m_nGameTime;

};


#endif //_MANAGER_H