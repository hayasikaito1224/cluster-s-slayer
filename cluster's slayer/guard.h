#ifndef _GUARD_H
#define _GUARD_H
#include "scene.h"
class CModel;
class C3DPolygon;
class CGuard : public CScene
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
		int m_nMaxGuard; //�_���[�W�K�[�h�̌�
	};

	CGuard(OBJTYPE nPriority = CScene::OBJTYPE_EFFECT);
	~CGuard();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetGuardQuantity(int nGuard);
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	void SetHeightPolygon(float Height) { m_fHeight = Height; }
	void SetParent(CModel *pParent);
	int GetMaxGuard() { return m_State.m_nMaxGuard; }
	void SetLevel(int nLevel) { m_nLevel = nLevel; }
	static CGuard *Create(const D3DXVECTOR3& pos,const float& fHeight,const int& nLevel);//�C���X�^���X��������

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//���_�o�b�t�@�ւ̃|�C���^
	D3DXMATRIX	m_mtxWorld;
	D3DXVECTOR3	m_Scale;//�G�̑傫��
	D3DXVECTOR3	m_pos;	//��̈ʒu
	D3DXVECTOR3	m_rot;	//��̈ʒu
	D3DXCOLOR m_col;
	State m_State;
	C3DPolygon **m_pGuardPolygon;
	float m_fHeight;
	int m_nCntGuard; //�_���[�W�K�[�h�̌�
	int m_nLevel;
	bool m_bCanParent;
	bool						m_bUninit;
	bool m_bDraw;
};


#endif // !_GUARD_H

