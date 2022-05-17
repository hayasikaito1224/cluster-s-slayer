//=============================================================================
// ���󏈗� [Sphere.h]
// Author : �����G��
//=============================================================================
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "main.h"
#include "scene3D.h"

class CSphere : public CScene3D
{
public:
	CSphere(int nPriority);	//�R���X�g���N�^
	~CSphere();	//�f�X�g���N�^

	HRESULT Init(D3DXVECTOR3 pos, float rot, float fSize, int Vertical, int Line, CTexture::Type nTex, int Synthetic, float TexNum);
	void Uninit();
	void Update();
	void Draw();

	D3DXVECTOR3 GetSherePos() { return m_Pos; }

	void SetColor(D3DCOLORVALUE Color);
	void SetSize(D3DXVECTOR3 pos ,float Size);
	void Rotate(float Rotate);

	void SetTexUV(D3DXVECTOR2 TexUV);

protected:
	bool m_bUninit;	//�����t���O
	int m_nLife;	//����
private:
	LPDIRECT3DTEXTURE9 m_pTexture;	//�e�N�X�`��
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;	//���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuff = NULL;	//�C���f�b�N�X�o�b�t�@

	D3DXMATRIX m_mtxWorld;	//���[���h�}�g���b�N�X
	D3DXVECTOR3 m_Pos;	//�ʒu
	D3DXVECTOR2 m_TexUV;	//�e�N�X�`�����W
	D3DXVECTOR2 m_TexMoveUV;	//�e�N�X�`�����W�̈ړ�

	float m_Rot;	//��]
	float m_Rot2;	//��]

	int m_nVertical;	//���̕�����
	int m_nLine;		//�c�̕�����
	int m_nTex;		//�e�N�X�`��

	int m_nVtx;	//���_��
	int m_nIdx;	//�C���f�b�N�X��
	int m_Synthetic;	//����

	float m_fRotate;	//��]

	float m_fRadius;	//���a
	int m_Primithive;	//�v���~�e�B�u

	static int m_nMaxTex;

};

#endif // !_MESHEFFECT_H_
