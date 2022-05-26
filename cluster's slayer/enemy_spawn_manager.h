//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#ifndef _ENEMY_SPAWN_MANAGER_H_
#define _ENEMY_SPAWN_MANAGER_H_
#include "scene.h"

class CEnemySpawnManager : public CScene
{
public:
	CEnemySpawnManager(OBJTYPE nPriority = CScene::OBJTYPE_MANAGER);
	~CEnemySpawnManager();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//�ÓI�����o�[�֐�
	static CEnemySpawnManager *Create(const D3DXVECTOR3& pos);

private:
	D3DXVECTOR3 m_pos;
	int m_nSpawnCnt;//�o���̃J�E���^�[
	int m_nSpawnTime;//�o������܂ł̎���
};


#endif // !_PLAYER_H_

