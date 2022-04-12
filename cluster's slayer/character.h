//=============================================-
//�L�����N�^�[�̃N���X
//=============================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "scene.h"
class CModel;
class CLayer_Structure;
class CMotion;
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

	CCharacter(OBJTYPE nPriority = CScene::OBJTYPE_NONE);
	~CCharacter();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	bool IsCollision(const D3DXVECTOR3 pos, float fRadius);//�����蔻��
	void HPChange(float fNum);//�̗͂̑���
	void StateChange(state_type StateType);//��Ԃ̕ω�

protected:
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_lastpos;//1�t���[���O�̈ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	state_type m_StateType;//��Ԃ̎��
	CLayer_Structure *m_pLayer;
	std::vector <CModel*> m_pParts;//�L�����N�^�[�̃p�[�c
	std::vector <CMotion*> m_pMotion;//���[�V����
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