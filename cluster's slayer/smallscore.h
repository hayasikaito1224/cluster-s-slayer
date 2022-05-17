#ifndef _SMALLSCORE_H
#define _SMALLSCORE_H
//----------------------------------------
//�U����^�����Ƃ��ɏo�鐔�l�̏���
//----------------------------------------
#include "scene2D.h"
#define MAXSMALLSCORE (8)
class CNumber;

class CSmallScore : public CScene
{
public:

	CSmallScore(OBJTYPE nPriority);
	~CSmallScore();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void SetSmallScore(int nSmallScore);
	void AddSmallScore(int nValue);
	void SetTrussSmallScore();//�����o����
	void SetColor(D3DXCOLOR col);//�����o����
	void AddAlpha();
	void DefAlpha();

	D3DXMATRIX GetMatrix() { return m_mtxWorld; }//���[���h�}�g���b�N�X�̎擾

	int CSmallScore::GetSmallScore(void) { return m_nSmallScore; }
	static CSmallScore *Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& scale, const D3DXCOLOR& col, const int& nSmallScore);//�C���X�^���X��������

private:
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	D3DXMATRIX m_mtxView;									//�r���[�}�g���b�N�X
	D3DXCOLOR m_col;
	D3DXVECTOR3					m_Scale;				//�G�̑傫��
	D3DXVECTOR3					m_pos;				//��̈ʒu
	float						m_fMove;
	int							m_nSmallScore;			//���݂̃X�R�A
	CNumber						*m_pNumber[MAXSMALLSCORE];
	int							m_nMaxTruss;//�ő�̌���
	int m_nCounter;
	bool						m_bUninit;
	bool m_bCanAddAlpha;//���l���Z�ł��邩
	bool m_bCanDefAlpha;//���l���Z�ł��邩

};


#endif // !_SMALLSCORE_H

