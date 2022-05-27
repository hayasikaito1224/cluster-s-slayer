//========================================
// ���Ԃ�\��/�����鏈��
// Author:��
//========================================
#ifndef _GAMETIMER_H_
#define _GAMETIMER_H_
#include "scene.h"
#define SECONDNUMBERS_MAX (2)
#define MINUTENUMBERS_MAX (2)
class CPolygon;
class C2DNumber;

class CGametimer : public CScene
{
public:
	//------------------------------------
	// �R���X�g���N�^�A�f�X�g���N�^
	//------------------------------------
	CGametimer(OBJTYPE nPriority = CScene::OBJTYPE_TIME);
	~CGametimer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void TimeNumbers();
	void TimeCount();
	int GetSecond() { return m_nSecondCnt; }
	int GetMinute() { return m_nMinuteCnt; }
	void AddMinute(int nMinute);
	static CGametimer *Create(const D3DXVECTOR3 pos,const D3DXCOLOR col,const bool& CanCount = true);
private:
	C2DNumber *m_pSecond[SECONDNUMBERS_MAX];//�b
	C2DNumber *m_pMinute[MINUTENUMBERS_MAX];//��
	CPolygon *pPolygon[SECONDNUMBERS_MAX];
	D3DXVECTOR3 m_pos;
	D3DXCOLOR m_col;
	int m_nSecondCnt;//�b���𐔂�����
	int m_nMinuteCnt;//�����𐔂�����
	int m_nCommaCnt;//����܂𐔂�����
	bool m_bUninit;
	bool m_bCanCount;
};
#endif _GAMETIMER_H_