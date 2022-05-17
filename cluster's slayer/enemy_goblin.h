#ifndef _ENEMY_GOBLIN_H_
#define _ENEMY_GOBLIN_H_
#include "enemy.h"

class CSound;

#define MAX_KEYSET (10) //�ő�L�[�Z�b�g��
#define MAX_DRAWRADIUS (1000.0f)
#define MAX_COLRADIUS (400.0f)
#define MAX_ATTACKSTART_RADIUS (150.0f)//�U���J�n�͈�
#define ENEMY_GOBLIN_ADD_SPEED (0.2)//�Q�[�W�𑝂₷��
#define INVINCIBLE_TIME (30)//���G����
class CEnemy_Goblin : public CEnemy
{
public:

	typedef enum
	{
		NEUTRAL = 0,
		MOVE,
		ATTACKWAIT,
		ATTACK,
		DETH,
		MAX
	}MOTION;

	CEnemy_Goblin(OBJTYPE nPriority = CScene::OBJTYPE_ENEMY);
	~CEnemy_Goblin();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void AIAttack();
	void AIMove();
	void AddLife(int nPower, int nType);
	void AddLife(int nLife);//�̗͂̑���
							//�ÓI�����o�[�֐�
	static CEnemy_Goblin *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

private:


};


#endif // !_PLAYER_H_

