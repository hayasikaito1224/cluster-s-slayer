//--------------------------------------
//ゲーム開始前のメニュー画面
//--------------------------------------
#ifndef _GAMEMENU_H
#define _GAMEMENU_H

#include "main.h"
#include "scene.h"
static const int max_MenuButton = 3;

//前方宣言
class CBg;
class CPolygon;
class CSound;
class CTitleSelectButton;
class CGameMenu
{
public:
	enum POLYGON
	{
		PORYGON_FILEBG,				// 背景
		PORYGON_GAME_START,			// ゲーム開始
		PORYGON_UPGRADE,			// スキル取得
		PORYGON_RETURN_TO_TITLE,	// タイトルへ遷移
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

	bool		m_bNextMode;	// 次のモードに行くための

	CTitleSelectButton *pButton[max_MenuButton];
	int m_nSelectType;//現在選択しているボタンの種類
	int m_nDecisionType;//現在決定しているボタンの種類
};

#endif //_TITLE_H