//--------------------------------------
//�X�L���I����ʂ̏���
//--------------------------------------
#ifndef _SKILLSELECT_H
#define _SKILLSELECT_H
#include "scene.h"
static const int max_Bottom = 3;
//�O���錾
class CPolygon;
class CSkillSelectBottom;

class CSkillSelect : public CScene
{
public:
	enum SelectType
	{
		TYPE001 = 0,
		TYPE002,
		TYPE003,
		TYPEMAX
	};
	enum SkillType
	{
		PassiveType = 0,
		ActionType
	};
	CSkillSelect(OBJTYPE nPriority = OBJTYPE_UI);
	~CSkillSelect();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CSkillSelect *Create();
	void PopSelectWindow();
private:
	CPolygon *pSelectWindow;
	CPolygon *pSelectWindowBg;//�I����ʂ̔w�i
	CSkillSelectBottom *pSkillBottom[max_Bottom];
	int m_nSelectType;//���ݑI�����Ă���{�^���̎��
	int m_nDecisionType;//���݌��肵�Ă���{�^���̎��
	bool m_bPopSelectWindow;
	bool m_bEnd;//�I������
};


#endif //_RESULT_H