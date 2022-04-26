//--------------------------------------------
//�X�L���ǌ��̏���
//�쐬�ҁF��
//--------------------------------------------
#ifndef _RASHATTACK_H_
#define _RASHATTACK_H_
#include "scene.h"
class CModel;

class CRushAttack:public CScene
{
public:

	CRushAttack(OBJTYPE nPriority);
	~CRushAttack();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void UpperAttack();
	//�ÓI�����o�[�֐�
	static CRushAttack *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
private:
	CModel *m_pRushSword;
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X

	bool m_bIsDeath;
};


#endif // !_PLAYER_H_

