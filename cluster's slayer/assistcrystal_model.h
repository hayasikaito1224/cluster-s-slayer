//-------------------------------------------
//�A�V�X�g�N���X�^���̏���
//------------------------------------------
#ifndef _ASSISTCRYSTAL_MODEL_H_
#define _ASSISTCRYSTAL_MODEL_H_
#include "scene.h"
class CPlayer;
class CModel;
class CAssistCrystal;
class CAssistCrystal_Model
{
public:
	CAssistCrystal_Model();
	~CAssistCrystal_Model();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//�ÓI�����o�[�֐�
	static CAssistCrystal_Model *Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot, const float& fMoveSpeed, const int& nPower, const int& m_nInterval);
	void SetMtx(D3DXMATRIX mtx) { m_mtxParent = mtx; }
private:
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	CAssistCrystal *m_pParent;
	CModel *m_Crustal;
	CModel *m_TopFrame;
	CModel *m_BottomFrame;
	D3DXMATRIX	m_mtxParent;						//���[���h�}�g���b�N�X
	int m_nDeleteTimer;
	int m_nBulletTimer;
	int m_nPower;
	float m_fMoveSpeed;
	int m_nLaunchInterval;
	bool m_bMoveDirection;
	bool m_bUninit;
};

#endif // !_ASSISTCRYSTAL_MODEL_H_

