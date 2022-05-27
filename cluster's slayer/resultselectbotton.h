//--------------------------------------
//�t�@�C���I��\���p�̏���
//--------------------------------------
#ifndef _RESULTSELECTBUTTON_H
#define _RESULTSELECTBUTTON_H
#include "scene2D.h"
//�O���錾
class CPolygon;
class CFrame;

class CResultSelectButton : public CScene
{
public:
	CResultSelectButton(OBJTYPE nPriority = OBJTYPE_UI);
	~CResultSelectButton();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CResultSelectButton *Create(const D3DXVECTOR3& pos,
		const D3DXVECTOR3& size, const int& tex);
	void PopSelectBottom();

	void SelectBottom();
	void SetEnd(bool bEnd) { m_bEnd = bEnd; }
	//�I����Ԑݒ�
	void SetSelect(bool bSelect) { m_bIsSelect = bSelect; }
	//�����Ԑݒ�
	void SetDecision(bool bDecision) { m_bIsDecision = bDecision; }
	//�����Ԏ擾
	bool GetDecision() { return m_bIsDecision; }

	CPolygon *GetSelectButton() { return pSelectBottom; }
private:
	CPolygon *pSelectBottom;
	CFrame *pFrame;//�QD�|���S���̉�
	bool m_bIsSelect;//���ݑI�����Ă��邩
	bool m_bIsDecision;//���݌��肵�Ă��邩
	bool m_bPopSelectBottom;
	bool m_bCanAlphaDown;
	bool m_bEnd;//�I������
};


#endif //_RESULT_H
