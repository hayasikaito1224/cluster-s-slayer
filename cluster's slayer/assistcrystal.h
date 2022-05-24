//-------------------------------------------
//�A�V�X�g�N���X�^���̏���
//------------------------------------------
#ifndef _ASSISTCRYSTAL_H_
#define _ASSISTCRYSTAL_H_
#include "scene.h"
class CPlayer;
class CAssistCrystal_Model;
class CAssistCrystal 
{
public:
	CAssistCrystal();
	~CAssistCrystal();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//�ÓI�����o�[�֐�
	static CAssistCrystal *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CPlayer *pPlayer);
	void PlayerFollowing();
private:
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXVECTOR3 m_scale;//�傫��
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	CPlayer *m_pPlayer;
	CAssistCrystal_Model *m_CrystalModel;
	D3DXMATRIX	m_mtxParent;						//���[���h�}�g���b�N�X
	float m_fInstallationAngle;//�A�V�X�g�N���X�^���̐ݒu�ꏊ
	int m_nDeleteTimer;
	float m_fMoveSpeed;
	bool m_bUninit;
};

#endif // !_ASSISTCRYSTAL_H_

