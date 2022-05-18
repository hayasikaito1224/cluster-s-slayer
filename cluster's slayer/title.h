//--------------------------------------
//�^�C�g���̏���
//--------------------------------------
#ifndef _TITLE_H
#define _TITLE_H

#include "main.h"
#include "scene.h"
static const int max_TitleButton = 4;

//�O���錾
class CBg;
class CPolygon;
class CSound;
class CTitleSelectButton;
class CTitle
{
public:
	enum TYPE
	{
		TITLE_PRESS_ENTER,
		TITLE_FADE,
		TITLE_SELECT_DOWN,
		TITLE_FILE_SELECT,
		TITLE_FILE_DELETE,
		TITLE_MAX
	};

	enum POLYGON
	{
		PORYGON_LOGO,	// �^�C�g�����S
		PORYGON_FILEBG,	// �w�i��������ƈÂ�����
		PORYGON_FILE01,	// �t�@�C��1
		PORYGON_FILE02,	// �t�@�C��2
		PORYGON_FILE03,	// �t�@�C��3
		PORYGON_FILEDELETE,	// �t�@�C���폜
		POLYGON_MAX
	};

	CTitle();
	~CTitle();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }

private:
	void ButtonCreate(int num);

	CPolygon	*m_Polygon[POLYGON_MAX];

	int			m_nNowType;		// ���݂̃^�C�g���A�j���[�V����
	bool		m_bNextMode;	// ���̃��[�h�ɍs�����߂�
	float		m_fAlpha;		// ��ʂ̖��邳

	CTitleSelectButton *pSkillBottom[max_TitleButton];
	int m_nSelectType;//���ݑI�����Ă���{�^���̎��
	int m_nDecisionType;//���݌��肵�Ă���{�^���̎��
};

#endif //_TITLE_H