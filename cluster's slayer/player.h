//=============================================-
//�v���C���[�̃N���X
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"
class CEnemy;
class CSword;

class CPlayer : public CCharacter
{
public:
	typedef enum
	{
		N_NEUTRAL = 0,
		N_MOVE,
		N_ATTACK_1,
		N_ATTACK_2,
		N_ATTACK_3,
		N_MAGIC_ATTACK,//���@�U��
		N_SKILL002,
		N_DETH,
		N_DODGE,
		N_MAX
	}N_MOTION;//�ʏ��Ԃ̃��[�V����

	typedef enum
	{
		COMBOWAIT = 0,
		COMBO_1,
		COMBO_2,
		COMBO_3,
		COMBO_MAX
	}COMBO;
	typedef enum
	{
		MOVEUP = 1,
		MOVEDOWN,
		MOVERIGHT,
		MOVELEFT
	}MOVEARROW;

	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_NONE);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CPlayer *Create();
	void KeyboardMove();//�ړ�
	void PadMove();//�ړ�
	void Attack();//�ʏ�U��
	void AttackCtrl();//�ʏ�U���̑���
	void MouseCameraCtrl();//�}�E�X�̃J��������
	void MagicAttack();//���@�U��
	void RockOn();//���b�N�I��
	void Dodge();//���
	void NearEnemyFace();//�߂��G�̕����Ƀv���C���[����������
	bool IsNearEnemyState();//�����̓G���߂��ɂ��邩���Z�o
private:
	void WeaponSet(const char *pcFileName);//����̃Z�b�g
	void FollowingPlayerCamera();//�J�������v���C���[�ɒǏ]���鏈��
	bool PushDifferentMoveKey(int nKey);//�Ⴄ�����L�[�������Ă��邩�̔���
	void Drawtext();
	bool IsMoveKeyCheck();//�ړ��p�̃L�[�������Ă��邩�̔����Ԃ�����
	bool FixedTimeInterval(float fMaxTime);//��莞�ԊԊu�������鏈��
	CSword *m_pSword;//��
	POINT m_Cursol;
	void AttackMove(float fMoveVolume);
	CEnemy *m_pNearEnemy;//�v���C���[����߂��G�̏��
	bool m_bNearEnemy;//�G���߂��ɂ���̂��̔���
	bool m_nMovePush;//�ړ��L�[�������Ă��邩�̔���
	bool m_bCanAttack;//�U�����ł��邩�H
	bool m_bCanAttackMove;//�U�����ł��邩�H
	bool m_bRevertCamera;
	bool m_bMoveStop;//�ړ��𐧌�����
	bool m_bAttackWait;//�ő�R���{����ŏ��̃R���{�ɖ߂�Ƃ��̑ҋ@�̃t���O
	bool m_bAttackReception;//�U�������t
	float m_fAttackWaitTime;//�U������ҋ@����
	float m_fAttackMoveTime;//�U���ړ����鎞��
	float m_fSoundInterval;
	float m_fStopTime;//�~�܂��Ă��鎞��
	int m_nComboType;//���ǂ̃R���{���𐔂���
	int m_motionType;//���[�V�����̎��
	int m_motionLastType;//�O�̃��[�V�����̎��
};

#endif // !_PLAYER_H_

