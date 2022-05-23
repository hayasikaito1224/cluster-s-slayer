//=============================================================================
// (����)3D�G�t�F�N�g���� [Straight3D.h]
// Author : �����G��
//=============================================================================
#ifndef _STRAIGHT3D_H_
#define _STRAIGHT3D_H_

#include "main.h"
#include "billEffect.h"

//*****************************************************************************
//�O���錾
//*****************************************************************************
class CCamera;

class CStraight3D : public CBillEffect
{
public:
	//����
	typedef enum
	{
		STRAIGHT,	//�܂�����
		TARGET,	//�ڕW�Ɍ�����
		MOVE_MAX,
	} MOVE_PATTERN;

	//�o���ʒu
	typedef enum
	{
		FIELD,	//����
		WALL,	//��
		SPHERE,	//��
		OTHERS,	//���̑��i�������ɐݒ�j
		POS_MAX,
	} POS_PATTERN;

	typedef enum	//�����_��
	{
		RANDNONE,	//�����_������
		RANDPLUS,	//�{�����_��
		RANDMIN,	//�[�����_��
		RANDBOTH,	//����
		RANDSMOKE,	//���p
		RANDMAX,
	} RAND_PATTEN;

	CStraight3D(int nPriority);
	~CStraight3D();

	HRESULT Init(D3DXVECTOR3 pos,
		D3DXVECTOR3 Size,
		D3DXVECTOR3 MinSize,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		int nType,
		int nLife,
		CStraight3D::MOVE_PATTERN Pattrn,
		D3DXVECTOR3 Target,
		int Synsetic,
		float Destance,
		CStraight3D::RAND_PATTEN RandPattern,
		CStraight3D::POS_PATTERN PosPattern,
		D3DXVECTOR2 TexMove,
		float TexNum);

	void Uninit();
	void Update();
	void Draw();

	static CStraight3D *Create(D3DXVECTOR3 pos,
		D3DXVECTOR3 Size,
		D3DXVECTOR3 MinSize,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		int nType,
		int nLife,
		CStraight3D::MOVE_PATTERN Pattrn,
		D3DXVECTOR3 Target,
		int Synsetic,
		float Destance,
		CStraight3D::RAND_PATTEN RandPattern,
		CStraight3D::POS_PATTERN PosPattern,
		D3DXVECTOR2 TexMove,
		float TexNum);
private:

	D3DXVECTOR3 m_move;	//�ړ��l
	D3DXVECTOR3 m_rot;	//�ړ��l

	CCamera *m_pCamera;	//�J����

	MOVE_PATTERN m_Pattern;	//�����̃p�^�[��
	D3DXVECTOR3 m_Target;	//�ڕW�n�_

	float m_XZr;	//�p�xxz
	float m_Yr;	//�p�xy

};

#endif