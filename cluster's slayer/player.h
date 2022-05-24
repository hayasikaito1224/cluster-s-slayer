//=============================================-
//�v���C���[�̃N���X
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"
#define MAX_ASSISTCRYSTAL (2)
class CEnemy;
class CSword;
class CGuard;
class CMissile;
class CAssistCrystal;
class CAssistCrystal_Model;

class CPlayer : public CCharacter
{
public:
	enum N_MOTION
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
	};//�ʏ��Ԃ̃��[�V����

	enum COMBO
	{
		COMBOWAIT = 0,
		COMBO_1,
		COMBO_2,
		COMBO_3,
		COMBO_MAX
	};
	enum MOVEARROW
	{
		MOVEUP = 1,
		MOVEDOWN,
		MOVERIGHT,
		MOVELEFT
	};
	enum SkillType
	{
		ATKup,
		Eye,
		Heal,
		OverHeal,
		Sheild,
		Beam,
		BlackHole,
		Rocket,
		RushAttack,
		Skill_Max
	};

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
	void LevelUp(int nType);//���x���A�b�v�̏���
	void HitDamege(int nPower);
	int GetLevel() { return m_nLevel; }
	float GetMaxExp() { return m_fMaxExp; }
	D3DXVECTOR3 GetNearEnemyPos();
	bool IsNearEnemyState();//�����̓G���߂��ɂ��邩���Z�o
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	bool GetCanRushAttack() { return m_bCanRushAttack; }
	int GetSkillLevel(int nSkillType);
private:
	void WeaponSet(const char *pcFileName);//����̃Z�b�g
	void FollowingPlayerCamera();//�J�������v���C���[�ɒǏ]���鏈��
	bool PushDifferentMoveKey(int nKey);//�Ⴄ�����L�[�������Ă��邩�̔���
	void Drawtext();
	bool IsMoveKeyCheck();//�ړ��p�̃L�[�������Ă��邩�̔����Ԃ�����
	bool FixedTimeInterval(float fMaxTime);//��莞�ԊԊu�������鏈��
	void PlayerRushAttack();//�ǌ�
	void EachSkillManager();//�e�X�L���̏����̂܂Ƃ�
	CSword *m_pSword;//��
	CGuard *m_pDamegeGuard;
	CMissile *m_pMissile;
	CAssistCrystal *m_pAssistCrystal[MAX_ASSISTCRYSTAL];

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
	bool m_bCanAutoHeel;//�I�[�g�q�[���\��
	bool m_bCanRushAttack;//�ǌ��\��
	bool m_bCanBlackHole;
	bool m_bCanDamegeGuard;
	bool m_bCanAssistCrystal;
	bool m_bCanDamege;
	bool m_bCanMissile;

	float m_fAttackWaitTime;//�U������ҋ@����
	float m_fAttackMoveTime;//�U���ړ����鎞��
	float m_fSoundInterval;
	float m_fStopTime;//�~�܂��Ă��鎞��
	float m_fMoveSpeed;//�ړ���
	float m_fPower;//�U����
	float m_fPowerDiameter;//�U���͑����{��
	float m_fAutoHeel;//�I�[�g�q�[����
	float m_fMaxExpDiameter;//�ő�o���l�̔{��
	float m_fMaxExp;//�ő�o���l
	int m_BlackHoleLevel;
	int m_nMissileCnt;
	int m_nRushStartCnt;//�ǌ��J�n�܂ł̃J�E���g
	int m_nBlackHoleCnt;
	int m_nComboType;//���ǂ̃R���{���𐔂���
	int m_motionType;//���[�V�����̎��
	int m_motionLastType;//�O�̃��[�V�����̎��
	int m_nNumGuard;//�����Ă�_���[�W�K�[�h�̐�
	int m_nLevel;//���x��
	int m_nTimer;

};

#endif // !_PLAYER_H_

