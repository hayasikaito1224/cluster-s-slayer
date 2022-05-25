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
		int m_nPower;
		int m_nLaunchInterval;//�e�̔��ˊԊu
		float m_fMoveSpeed;
	};
	CAssistCrystal();
	~CAssistCrystal();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//�ÓI�����o�[�֐�
	static CAssistCrystal *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CPlayer *pPlayer,const int& nLevel);
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
	int m_nLevel;
	bool m_bUninit;
};

#endif // !_ASSISTCRYSTAL_H_

