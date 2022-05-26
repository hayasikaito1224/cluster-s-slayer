//-----------------------------
//�G�̏���
//-----------------------------

#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"
class CSound;

#define MAX_KEYSET (10) //�ő�L�[�Z�b�g��
#define MAX_DRAWRADIUS (1000.0f)
#define MAX_COLRADIUS (400.0f)
#define MAX_ATTACKSTART_RADIUS (150.0f)//�U���J�n�͈�
#define ENEMY_ADD_SPEED (0.2)//�Q�[�W�𑝂₷��
#define INVINCIBLE_TIME (30)//���G����
class CEnemy : public CCharacter
{
public:

	typedef enum
	{
		NEUTRAL = 0,
		MOVE,
		ATTACKWAIT,
		ATTACK,
		DETH,
		MAX
	}MOTION;

	typedef enum
	{
		NORMAL = 0,
		TYPE_MAX
	}ENEMY_TYPE;

	CEnemy(OBJTYPE nPriority = CScene::OBJTYPE_ENEMY);
	virtual ~CEnemy();
	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();
	virtual void Colision();
	virtual void AIAttack();
	virtual void AIMove();
	virtual void AddLife(int nPower, int nType);
	virtual void AddLife(int nLife);//�̗͂̑���
	void HoleAlign(D3DXVECTOR3 holePos, float fHitSize,float AlignSpeed);//�u���b�N�z�[���Ɉ����񂹂��鏈��
	void AddLifeSkill(int nLife);//�X�L���U�����󂯂��Ƃ��̗̑͂̑���

	//�ÓI�����o�[�֐�
	static CEnemy *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void AIBehavior();//�GAI�̋����̏���
	void SetbDamage(bool bDamage) { m_bDamage = bDamage; }//�_���[�W���󂯂���Ԃɂ���
	bool GetbDamage() { return m_bDamage; }//�_���[�W���󂯂Ă����Ԃ��擾
	bool GetAIMove() { return m_bAIMove; }
	bool GetAIMoveStop() { return m_bAIMoveStop; }
	void SetHit(const bool& bHit) { m_bHit = bHit; }
	bool bHitAttack();//�U�����������Ă��������̔���
	bool GetHit() { return m_bHit; }
	bool GetbInvincible() { return m_bInvincible; }
	void Knockback(D3DXVECTOR3& Playerpos);
	void SetbHitCollision(bool bHitCollision) { m_bHitCollision = bHitCollision; }
	D3DXVECTOR3 GetPos() { return m_pos; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	bool GetRushAttack() { return m_bHitRushAttack; }
	void SetRushAttack(bool bRushAttack) { m_bHitRushAttack = bRushAttack; }
	bool GetCanHitRushAttack() { return m_bCanHitRushAttack; }
	void SetCanHitRushAttack(bool bRushAttack) { m_bCanHitRushAttack = bRushAttack; }
	void SetGravity(float fGravity) {m_fGravity = fGravity;}
	void SetbKnockback(bool bKnockBack) { m_bKnockback = bKnockBack; }
	static int GetMaxEnemy() { return m_nMaxEnemy; }
	static void SetMaxEnemy(int nMaxEnemy) { m_nMaxEnemy = nMaxEnemy; }
	void SetIsNear(bool bNear) { m_bNearPlayer = bNear; }
	bool GetNearPlayer() { return m_bNearPlayer; }
private:
	static int m_nMaxEnemy;
protected:
	std::random_device s_random;	// �񌈒�I�ȗ���������
	bool  m_bKnockback;//�m�b�N�o�b�N���邩�ǂ����̔���
	bool m_bOnMissile;
	bool m_bDraw;
	bool m_bHit;//�U�����󂯂����ǂ���
	bool m_bOnAttackCollision;
	bool m_bIsKill;//�v���C���[�ɓ|���ꂽ���ǂ���
	bool m_bNearPlayer;//�v���C���[�ɋ߂����̃t���O
	int  m_nTimer;
	float	m_fMovingRange;//�G�������œ�������
	int	m_nDefense;
	bool	m_bNeutral;
	bool	m_bMotionStop;//���[�V�������~�܂������ǂ���
	bool	m_bDamage;//���U�����󂯂Ă��邩
	bool	m_bInvincible;//���G���Ԃ̔���
	bool    m_bEffect;
	bool m_bHitCollision;//�v���C���[����̍U����������悤�ɂ��锻��
	bool m_bHitRushAttack;//�v���C���[�̍U�����󂯂Ă��邩
	bool m_bCanHitRushAttack;//�ǌ��̍U�����󂯂�邩
	D3DXVECTOR3 m_MoveSpeed; //�ʒu
	float m_fAng;
	float s_CntTimer;//�J�E���^�[
	float s_MaxTimer;//�J�E���^�[
	float s_MovingCnt;//�J�E���^�[
	float s_MoveRandAng;//�����_���Ȍ���
	float m_fWalkSoundInterval;
	bool  s_bCntStop;//�����_���Ȍ���
	bool	m_bAIMoveStop;//�G���Ǐ]����Ƃ���AI������~�߂锻��
	int	 m_nCntHitInterval;//�v���C���[����̍U�����������悤�ɂȂ�܂ŃJ�E���^�[
	float m_fSoundInterval;
	bool	m_bAttack;//���U�����Ă邩�ǂ���
	int		m_nAttackStartCnt;//�U���J�n�܂ł̃J�E���g
	bool	m_bAIMove;	//�G�������I�ɓ�������
	bool m_bMove;//�ړ�����
	D3DXVECTOR3 m_pos, m_rot, m_lastPos, m_Lotrot;
	float m_fPlayerVecLength;
	float m_fMoveSpeed;//�ړ���
	int	 m_MotionType,	m_MotionLastType;
	int					m_nPower;//�U����
	int	m_nType;//�G�̎��
	float m_fGravity;
	
};


#endif // !_PLAYER_H_

