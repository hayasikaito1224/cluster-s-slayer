//*****************************************************************************
// (��])�G�t�F�N�g���� [Rotate.h]
// Author : �����G��
//*****************************************************************************
#ifndef _ROTATE_H_
#define _ROTATE_H_

#include "Effect2d.h"

class CRotate : public CEffect2d
{
public:
	CRotate(OBJTYPE nPriority);
	~CRotate();

	HRESULT Init(D3DXVECTOR3 pos,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife,
		int nType,
		float AddRotate,
		int Synsthetic);

	void Uninit();
	void Update();
	void Draw();

	static CRotate*Create(D3DXVECTOR3 pos,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife,
		int nType,
		float AddRotate,
		int Synsthetic);
private:
	D3DXVECTOR3 m_move;
	float m_Angle;			//�p�x
	float m_Vectl;	//	��������

	float m_AddAngle;	//��]���Z
};

#endif // !_MOVEMENT_H_
