//*****************************************************************************
// (�ړ�����)�G�t�F�N�g���� [Movement.h]
// Author : �����G��
//*****************************************************************************
#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include "Effect2d.h"

class CMovement : public CEffect2d
{
public:
	CMovement(OBJTYPE nPlyorty = CScene::OBJTYPE_EFFECT);
	~CMovement();

	HRESULT Init(D3DXVECTOR3 pos,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife, int nType,
		D3DXVECTOR3 AddMovement,
		int Synthetic);

	void Uninit();
	void Update();
	void Draw();

	static CMovement*Create(D3DXVECTOR3 pos,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife, int nType,
		D3DXVECTOR3 AddMovement,
		int Synthetic,
		const int& nPriorty = OBJTYPE_EFFECT);
private:
	D3DXVECTOR3 m_move;			//�ړ�
	D3DXVECTOR3 m_Addpos;		//����
};

#endif // !_MOVEMENT_H_
