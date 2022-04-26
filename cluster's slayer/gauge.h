//----------------------------------------------
//�Q�[�W�̏���
//Author::�ъC�l
//--------------------------------------------

#ifndef _GAUGE_H_
#define _GAUGE_H_
#include "scene.h"

class CPolygon;
class CGaugeBer;

class CGauge : public CScene
{
public:
	typedef enum
	{
		L_ADD=0,//�����Ɍ������ăQ�[�W��������
		R_ADD,//�E���Ɍ������ăQ�[�W��������
	}ADDTYPE;//�Q�[�W�̑�����

	CGauge(OBJTYPE nPriority);
	~CGauge();
	static CGauge*Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& scale, const D3DXCOLOR& col,
		const float& MaxGauge, const int& nValue, const int& type);
	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void ResetGauge(int nGaugeType);//�Q�[�W�̑���
	void SetGauge(float Set, int nGaugeType);//�Q�[�W�̑���
	void SetScalePos(D3DXVECTOR3 pos, D3DXVECTOR3 scale, int AddType, int nGaugeType);
	CGaugeBer *GetGaugeBer(int nGaugeType) { return m_pGaugeBer[nGaugeType]; }
private:
	CPolygon *m_pFrame;//�Q�[�W�̘g
	CGaugeBer *m_pGaugeBer[2];
};

#endif // !_TIME_H_*/#pragma once
