#ifndef _NUMBER_H
#define _NUMBER_H
#include "main.h"
#include "smallscore.h"
class CSmallScore;
class CNumber
{
public:
	CNumber();
	~CNumber();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetNumber(int nNumber);
	void SetCol(D3DXCOLOR col);//�J���[��ς���
	D3DXCOLOR GetCol() { return m_col; }
	void SetPos(D3DXVECTOR3 pos);//�J���[��ς���
	static CNumber *Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& scale,CSmallScore *pParent,const bool& bCanParent);//�C���X�^���X��������
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;				//���_�o�b�t�@�ւ̃|�C���^
	D3DXMATRIX m_mtxWorld;
	LPDIRECT3DTEXTURE9		m_pTexture;				//�e�N�X�`���ւ̃|�C���^
	CSmallScore *m_pParent;//�e�̏��
	D3DXVECTOR3					m_Scale;				//�G�̑傫��
	D3DXVECTOR3					m_pos;				//��̈ʒu
	D3DXVECTOR3					m_rot;				//��̈ʒu
	D3DXCOLOR m_col;
	bool m_bCanParent;
	bool						m_bUninit;
};


#endif // !_NUMBER_H

