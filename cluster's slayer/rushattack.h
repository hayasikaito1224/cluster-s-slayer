//--------------------------------------------
//�X�L���ǌ��̏���
//�쐬�ҁF��
//--------------------------------------------
#ifndef _RASHATTACK_H_
#define _RASHATTACK_H_
#include "scene.h"
class CModel;
class CEnemy;

class CRushAttack:public CScene
{
public:
	enum Level
	{
		Level_1 = 0,
		Level_2,
		Level_3,
		Level_4,
		Level_MAX
	};

	struct State
	{
		float m_fSizeDiameter;
		int m_nPower;
	};
	CRushAttack(OBJTYPE nPriority);
	~CRushAttack();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void UpperAttack();
	//�ÓI�����o�[�֐�
	static CRushAttack *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,CEnemy *pEnemy);
	bool IsCollision(const D3DXVECTOR3& Hitpos, const float& fRadius);

private:
	CModel *m_pRushSword;
	CEnemy *m_pEnemyData;
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXVECTOR3 m_scale;//�傫��
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	State m_State;
	int m_nStartTimer;//�ǌ����n�܂�܂ł̃J�E���^�[
	int m_nEndTimer;//�ǌ����I���܂ł̃J�E���^�[
	bool m_bCanAttackStart;//�X�L���̔����\��
	bool m_bIsDeath;
};


#endif // !_PLAYER_H_

