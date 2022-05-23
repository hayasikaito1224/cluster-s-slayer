//=============================================================================
// 3D�G�t�F�N�g���� [BillEffect.h]
// Author : �����G��
//=============================================================================
#ifndef _BILLEFFECT_H_
#define _BILLEFFECT_H_

#include "main.h"
#include "plane.h"

class CBillEffect : public CPlane
{
public:
	CBillEffect(int nPriority);
	virtual ~CBillEffect();

	virtual HRESULT Init(D3DXVECTOR3 Size, D3DXVECTOR3 MinSize, D3DCOLORVALUE color, D3DCOLORVALUE Mincolor, int nTex, int nLife, float TexNum);
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();

	void SetTexture(int nTex);		//�w�肳�ꂽ�ԍ��̃e�N�X�`����\���悤��

protected:
	bool m_bUninit;	//�����t���O
	int m_nSynthenic;	//����
	D3DXVECTOR3 m_MinSize;		//�傫���ϓ��l
	D3DXVECTOR3 m_Size;			//�T�C�Y

	D3DXVECTOR2 m_TexMove;
	float m_fTexNum;
private:

	//�J���[
	D3DCOLORVALUE m_Color;

	//�J���[����
	D3DCOLORVALUE m_MinColor;
	D3DXMATRIX m_mtxWorld;	//�}�g���b�N�X
	D3DXVECTOR3 m_rot;

	int m_nLife;	//����
};

#endif