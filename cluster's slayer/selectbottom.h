//--------------------------------------
//スキル説明表示用の処理
//--------------------------------------
#ifndef _SKILLSELECTBOTTOM_H
#define _SKILLSELECTBOTTOM_H
#include "scene.h"
//前方宣言
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
	//選択状態設定
	void SetSelect(bool bSelect) { m_bIsSelect = bSelect; }
	//決定状態設定
	void SetDecision(bool bDecision) { m_bIsDecision = bDecision; }
	//決定状態取得
	bool GetDecision() { return m_bIsDecision; }
	//選択したスキルの取得
	int GetSkillNo() { return m_nSkillNo; }
private:
	CPolygon *pSelectBottom;
	CPolygon *pSkillIcon;//スキルアイコン
	CFrame *pFrame;//２Dポリゴンの縁
	int m_nSkillNo;//スキルの番号
	bool m_bIsSelect;//現在選択しているか
	bool m_bIsDecision;//現在決定しているか
	bool m_bPopSelectBottom;
	bool m_bEnd;//終了判定
};


#endif //_RESULT_H
