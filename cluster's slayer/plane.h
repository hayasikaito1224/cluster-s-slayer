//=============================================================================
// ���ʏ��� [plane.h]
// Author : �����G��
//=============================================================================
#ifndef _PLANE_H_
#define _PLANE_H_

#include "main.h"
#include "scene3d.h"

//�}�N����`
#define CIRCLE (float(rand() % 324) / 100.0f - float(rand() % 324) / 100.0f) //�~
#define CIRCLE2 (float(rand() % 648) / 100.0f - float(rand() % 648) / 100.0f) //�~

class CPlane : public CScene3D
{
public:
	CPlane(int nPriority);
	~CPlane();
	HRESULT Init(const int nPolygonType, int nTex);
	void Uninit();
	void Update();
	void Draw();

	static CPlane *Create(const int nPolygonType, int nTex);
private:
};

#endif