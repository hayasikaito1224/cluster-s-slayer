//--------------------------------------
//�t�@�C���I��\���p�̏���
//--------------------------------------
#ifndef _TITLESELECTBUTTON_H
#define _TITLESELECTBUTTON_H
#include "scene2D.h"
//�O���錾
class CPolygon;
class CFrame;

class CTitleSelectButton : public CScene2D
{
public:
	CTitleSelectButton(OBJTYPE nPriority = OBJTYPE_UI);
	~CTitleSelectButton();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CTitleSelectButton *Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const int& tex);
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

	CPolygon *GetSelectButton() { return pSelectBottom; }
private:
	CPolygon *pSelectBottom;
	CFrame *pFrame;//�QD�|���S���̉�
	bool m_bIsSelect;//���ݑI�����Ă��邩
	bool m_bIsDecision;//���݌��肵�Ă��邩
	bool m_bPopSelectBottom;
	bool m_bEnd;//�I������
};


#endif //_RESULT_H
