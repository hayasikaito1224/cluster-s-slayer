//========================================
// 時間を表示/数える処理
// Author:林
//========================================
#ifndef _GAMETIMER_H_
#define _GAMETIMER_H_
#include "scene.h"
#define SECONDNUMBERS_MAX (2)
#define MINUTENUMBERS_MAX (2)

class C2DNumber;

class CGametimer : public CScene
{
public:
	//------------------------------------
	// コンストラクタ、デストラクタ
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

	static CGametimer *Create(const D3DXVECTOR3 pos,const D3DXCOLOR col);
private:
	C2DNumber *m_pSecond[SECONDNUMBERS_MAX];//秒
	C2DNumber *m_pMinute[MINUTENUMBERS_MAX];//分
	D3DXVECTOR3 m_pos;
	D3DXCOLOR m_col;
	int m_nSecondCnt;//秒数を数えるやつ
	int m_nMinuteCnt;//分数を数えるやつ
	int m_nCommaCnt;//こんまを数えるやつ
	bool m_bUninit;
};
#endif _GAMETIMER_H_