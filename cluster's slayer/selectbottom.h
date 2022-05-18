//--------------------------------------
//�X�L�������\���p�̏���
//--------------------------------------
#ifndef _SKILLSELECTBOTTOM_H
#define _SKILLSELECTBOTTOM_H
#include "scene.h"
//�O���錾
class CPolygon;
class CFrame;

class CSkillSelectBottom : public CScene
{
public:
	CSkillSelectBottom(OBJTYPE nPriority = OBJTYPE_UI);
	~CSkillSelectBottom();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CSkillSelectBottom *Create(const D3DXVECTOR3& pos,const D3DXVECTOR3& size,const int& tex,const int& SkillType);
	void PopSelectBottom();
	void SelectBottom();
	void SetCol(D3DXCOLOR col);
	void SetEnd(bool bEnd) { m_bEnd = bEnd; }
	//�I����Ԑݒ�
	void SetSelect(bool bSelect) { m_bIsSelect = bSelect; }
	//�����Ԑݒ�
	void SetDecision(bool bDecision) { m_bIsDecision = bDecision; }
	//�����Ԏ擾
	bool GetDecision() { return m_bIsDecision; }
	//�I�������X�L���̎擾
	int GetSkillNo() { return m_nSkillNo; }
private:
	CPolygon *pSelectBottom;
	CPolygon *pSkillIcon;//�X�L���A�C�R��
	CFrame *pFrame;//�QD�|���S���̉�
	int m_nSkillNo;//�X�L���̔ԍ�
	bool m_bIsSelect;//���ݑI�����Ă��邩
	bool m_bIsDecision;//���݌��肵�Ă��邩
	bool m_bPopSelectBottom;
	bool m_bEnd;//�I������
};


#endif //_RESULT_H
