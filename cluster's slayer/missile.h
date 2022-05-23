#ifndef _MISSILE_H
#define _MISSILE_H
#include "scene.h"
class CModel;
class C3DPolygon;
class CMissile : public CScene
{
public:
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
	float m_fIntervalTimer;//�~�T�C�����˂܂Ő�����
	float m_fMaxTime;
	float m_SearchRange;//�~�T�C����ł͈�
	int m_nCntSearch;//�T�[�`��
	int m_nCntSearchMax;//�ő�T�[�`��
	bool m_bCanSearch;
	bool m_bCanShotMissile;
	bool						m_bUninit;
	bool m_bDraw;
};


#endif // !_MISSILE_H

