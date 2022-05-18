//--------------------------------------
//�Q�[���J�n�O�̃��j���[���
//--------------------------------------
#ifndef _GAMEMENU_H
#define _GAMEMENU_H

#include "main.h"
#include "scene.h"
static const int max_MenuButton = 3;

//�O���錾
class CBg;
class CPolygon;
class CSound;
class CTitleSelectButton;
class CGameMenu
{
public:
	enum POLYGON
	{
		PORYGON_FILEBG,				// �w�i
		PORYGON_GAME_START,			// �Q�[���J�n
		PORYGON_UPGRADE,			// �X�L���擾
		PORYGON_RETURN_TO_TITLE,	// �^�C�g���֑J��
		POLYGON_MAX
	};

	CGameMenu();
	~CGameMenu();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }

private:
	void ButtonCreate(int num);

	CPolygon	*m_Polygon[POLYGON_MAX];

	bool		m_bNextMode;	// ���̃��[�h�ɍs�����߂�

	CTitleSelectButton *pButton[max_MenuButton];
	int m_nSelectType;//���ݑI�����Ă���{�^���̎��
	int m_nDecisionType;//���݌��肵�Ă���{�^���̎��
};

#endif //_TITLE_H