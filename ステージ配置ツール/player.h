#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene.h"

#include "motion.h"
class CSwordEffect;
class CLayer_Structure;
class CShadow;
class CPlayer_Controller;
class CMap_Polygon;
class CBillboard;
class CModel_Spawner;
//------------------------------------
//�}�N����`
//------------------------------------
#define PLAYER_POS_X (0.0)
#define PLAYER_POS_Y (0.0)
#define PLAYER_POS_Z (0.0)
#define PLAYER_FALL (-100.0)//��������ɓ���܂ł̈ʒu

class CPlayer : public CScene
{
public:
	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_PLAYER);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Drawtext();

	//�ÓI�����o�[�֐�
	static CPlayer *Create();
	D3DXVECTOR3 GetLastPos() { return m_lastpos; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	D3DXVECTOR3 GetModelPos();
private:
	static vector<CModel*>		m_pSModel;//�z�u���ꂽ���f��

	CPlayer_Controller	*m_pController;//����n�̃N���X
	D3DXVECTOR3 m_pos,m_lastpos,m_Swordpos[2],m_LastSwordpos[2]; //�ʒu
	float m_Vec_x, m_Vec_y, m_Vec_z;
	float m_fLength;
	float m_move = 2.0f;
	D3DXVECTOR3 m_rot;												//����
	D3DXMATRIX m_mtxWorld;											//���[���h�}�g���b�N�X
	CModel_Spawner *m_pModel;
	CShadow *pShadow;
	bool	m_bland;												//�n�ʂɂ��Ă邩����
	bool	m_bColloison;											//�����蔻��
	bool	m_bFall;												//��������
	bool	m_bMove;												// �ړ�����
	bool	m_bDelay;												//���̏����ɍs�����߂̊Ԋu
	float	m_fSoundInterval;										//�T�E���h�C���^�[�o��
	int     m_nTimer;
	int		m_nEffectTimer;
};


#endif // !_PLAYER_H_
