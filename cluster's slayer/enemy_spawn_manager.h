//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#ifndef _ENEMY_SPAWN_MANAGER_H_
#define _ENEMY_SPAWN_MANAGER_H_
#include "main.h"

class CEnemySpawnManager
{
public:
	CEnemySpawnManager();
	~CEnemySpawnManager();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//�ÓI�����o�[�֐�
	static CEnemySpawnManager *Create();

private:
	int m_nSpawnCnt;//�o���̃J�E���^�[
	int m_nSpawnTime;//�o������܂ł̎���
};


#endif // !_PLAYER_H_

