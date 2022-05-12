//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _TITLE_H
#define _TITLE_H

#include "main.h"
#include "scene.h"

//前方宣言
class CBg;
class CPolygon;
class CSound;
class CTitle
{
public:
	enum TYPE
	{
		TITLE_PRESS_ENTER,
		TITLE_FADE,
		TITLE_SELECT_DOWN,
		TITLE_FILE_SELECT,
		TITLE_MAX
	};

	enum POLYGON
	{
		PORYGON_LOGO,	// タイトルロゴ
		PORYGON_FILEBG,	// 背景をちょっと暗くする
		PORYGON_FILE01,	// ファイル1
		PORYGON_FILE02,	// ファイル2
		PORYGON_FILE03,	// ファイル3
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
	CPolygon			*m_Polygon[POLYGON_MAX];

	int					m_nNowType;		// 選択したタイプ
	bool				m_bNextMode;	// 次のモードに行くための
	float m_fAlpha;
};

#endif //_TITLE_H