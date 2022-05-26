#ifndef _MISSILE_H
#define _MISSILE_H
#include "scene.h"
class CModel;
class C3DPolygon;
class CMissile : public CScene
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
		float m_SearchRange;//�~�T�C����ł͈�
		int m_nPower;
		int m_nCntSearchMax;//�ő�T�[�`��
	};

	CMissile(OBJTYPE nPriority = CScene::OBJTYPE_EFFECT);
	~CMissile();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetMaxTime(float fTime) { m_fMaxTime = fTime; }
	void LaunchMissile();
	void SearchEnemy(const D3DXVECTOR3 EnemyPos,const float fRadius);
	static CMissile *Create();//�C���X�^���X��������

private:
	D3DXVECTOR3	m_Scale;//�G�̑傫��
	D3DXVECTOR3 *m_pEnemyPos;
	State m_State;
	float m_fIntervalTimer;//�~�T�C�����˂܂Ő�����
	float m_fMaxTime;
	int m_nCntSearch;//�T�[�`��
	bool m_bCanSearch;
	bool m_bCanShotMissile;
	bool						m_bUninit;
	bool m_bDraw;
};


#endif // !_MISSILE_H

