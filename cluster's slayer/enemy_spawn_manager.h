//--------------------------------------------
//敵の出現設定処理
//作成者：林
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
	//静的メンバー関数
	static CEnemySpawnManager *Create();

private:
	int m_nSpawnCnt;//出現のカウンター
	int m_nSpawnTime;//出現するまでの時間
};


#endif // !_PLAYER_H_

