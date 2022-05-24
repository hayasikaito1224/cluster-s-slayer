//=============================================-
//�L�����N�^�[�̃N���X
//=============================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "scene.h"
class CModel;
class CLayer_Structure;
class CMotion;
class CShadow;
class CCharacter : public CScene
{
public:
	typedef enum
	{
		IDLE = 0,//�A�C�h�����
		MOVE,//�ړ����
		ATTACK,//�U�����
		DAMEGE,//�_���[�W���󂯂���
	}state_type;

	CCharacter(OBJTYPE nPriority);
	~CCharacter();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	bool IsCollision(D3DXVECTOR3 *pMyPos, const D3DXVECTOR3& Hitpos, const float& fRadius, const float& MoveSpeed);//�����蔻��
	void HPChange(float fNum);//�̗͂̑���
	float GetLife() { return m_fHitPoint; }
	void StateChange(state_type StateType);//��Ԃ̕ω�
	void SetDeath(bool Uninit) { m_IsDeath = Uninit; }
	bool GetDeath(void) { return m_IsDeath; }
	D3DXMATRIX GetMtx() { return m_mtxWorld; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	CModel *GetParts(int nPartsNum);//�L�����N�^�[�̃p�[�c�擾����
	std::vector <CModel*> GetParts() { return m_pParts; }
protected:

	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_lastpos;//1�t���[���O�̈ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	state_type m_StateType;//��Ԃ̎��
	CLayer_Structure *m_pLayer;
	CMotion *m_pMotion;//���[�V����
	std::vector <CModel*> m_pParts;//�L�����N�^�[�̃p�[�c
	CShadow *m_pShadow;//�e

	int m_nAttackType;//�U���̎��
	int m_nPartsMax;//�p�[�c�̍ő吔
	float m_fHitPoint;//�̗�
	float m_fRadius;//�����蔻��͈̔�
	bool m_IsDeath;//���S����
	bool m_IsStop;//����̒�~����
	bool m_IsCharacterDraw;//�L�����N�^�[�̕`�攻��
	bool m_IsDelay;//����̒x��
};

#endif // !_CHARACTER_H_