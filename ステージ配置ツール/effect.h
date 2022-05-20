#ifndef _EFFECT_H_
#define _EFFECT_H_
#include "scene.h"
#include "texture.h"

class CEffect : public CScene
{
public:
	typedef enum
	{
		VectorDelete = 0,//�x�N�g���̒����ŏ�����
		TimeDelete		//���Ԃŏ�����
	}DeleteType;
	CEffect(OBJTYPE nPriority = OBJTYPE_EFFECT);
	~CEffect();
	HRESULT Init(CTexture::Type type);
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void SetCol_E(D3DXCOLOR col);
	void Setpos(D3DXVECTOR3 pos, D3DXVECTOR3 scale);//���_���ݒ�

	/*
	 �ʒu�̐ݒ�,
	 �ړ���,
	 �T�C�Y,
	 �������Ȃ�X�s�[�h
	 Texture
	*/
	static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 m_move, D3DXVECTOR3 size, D3DXCOLOR col,bool bGravity,float fGravity, float ScaleSpeed,CTexture::Type type = CTexture::Test);
	
private:
	float m_fGravity;//�d��
	bool m_bGravity;
	DeleteType m_DeleteType;//�G�t�F�N�g��������^�C�v
	float		m_fDeleteTime;
	float		m_fDeleteVec;
	float		m_fDeleteMaxTime;
	float		m_fDeleteMaxVec;

protected:
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_size;
	D3DXCOLOR m_col;//�F
	float m_fScaleSpeed;//�T�C�Y������������ϐ�
	int m_nLife;//����
	float m_fRand;
	CTexture::Type m_TexType;
	LPDIRECT3DTEXTURE9		m_pTexture = NULL;				//�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;				//���_�o�b�t�@�ւ̃|�C���^
	D3DXMATRIX m_mtxWorld;									//���[���h�}�g���b�N�X	
	D3DXMATRIX m_mtxView;									//�r���[�}�g���b�N�X

};


#endif // !_EFFECT_H_

