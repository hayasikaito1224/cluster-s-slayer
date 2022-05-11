//-------------------------------------------
//�u���b�N�z�[���̏���
//------------------------------------------
#ifndef _BLACKHOLE_H_
#define _BLACKHOLE_H_
#include "scene.h"
class CEnemy;

class CBlackHole : public CScene
{
public:
	CBlackHole(OBJTYPE nPriority);
	~CBlackHole();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Suction();//�G���z���t���鏈��
	void Head();
	//�ÓI�����o�[�֐�
	static CBlackHole *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CEnemy *pEnemy);

private:
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXVECTOR3 m_scale;//�傫��
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	CEnemy *m_pEnemyData;
	int m_nDeleteTimer;
	float m_fMoveSpeed;
	bool m_bUninit;
	bool m_bHoleExpansion;//�u���b�N�z�[���̓W�J�t���O
};

#endif // !_BLACKHOLE_H_

