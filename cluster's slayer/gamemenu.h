//--------------------------------------
//�Q�[���J�n�O�̃��j���[���
//--------------------------------------
#ifndef _GAMEMENU_H
#define _GAMEMENU_H

#include "main.h"
#include "scene.h"
#include "player.h"
//�O���錾
class CBg;
class CPolygon;
class CSound;
class CTitleSelectButton;

class CGameMenu
{
public:
	enum BUTTON
	{
		// �e�X�L���̃{�^���������ɂ���Ƃ���
		MENUBUTTON_GAME_START = CPlayer::Skill_Max,	// �Q�[���J�n
		MENUBUTTON_RETURN_TO_TITLE,	// �^�C�g���֑J��
		MENUBUTTON_MAX
	};

	CGameMenu();
	~CGameMenu();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }

private:
	bool m_bNextMode;	// ���̃��[�h�ɍs�����߂�

	CTitleSelectButton *pButton[MENUBUTTON_MAX];
	int m_nSelectType;//���ݑI�����Ă���{�^���̎��
	int m_nDecisionType;//���݌��肵�Ă���{�^���̎��
};

#endif //_TITLE_H