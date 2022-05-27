#ifndef _SCORE_H_
#define _SCORE_H_
#include "scene.h"
class C2DNumber;
#define MAX_SCORE (8)//�ő�`�文��


class CScore : public CScene
{
public:
	CScore(OBJTYPE nPriority = OBJTYPE_UI);
	~CScore();
	static CScore*Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);
	HRESULT Init(D3DXVECTOR3 pos, float fsize);
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void SetScore();//�X�R�A�̕`��ݒ�
	void SetTrussSmallScore();//�����o����
	void CreateNumber(const int& nTruss);
	int GetScore() {return m_nScore;}
	void AddScore(int AddScore) { m_nScore += AddScore; };//�X�R�A�̉��Z
	void SetFitScore(int nScore) { m_nScore = nScore; }
private:
	C2DNumber *m_apNumber[MAX_SCORE];
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_size;

	int m_nAddScore;//�X�R�A���Z�p�ϐ�
	int							m_nMaxTruss;//�ő�̌���
	int m_nScore;//���݂̃X�R�A
};
#endif
