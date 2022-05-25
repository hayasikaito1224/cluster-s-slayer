//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#ifndef _SKILL_LEVELDATA_H_
#define _SKILL_LEVELDATA_H_
#include "main.h"
#include "blackhole.h"
#include "assistcrystal.h"
#include "rushattack.h"
#include "guard.h"
class CModel;

class CSkill_LevelData
{
public:

	CSkill_LevelData();
	~CSkill_LevelData();
	HRESULT Init();
	void Uninit();
	//�ÓI�����o�[�֐�
	static CSkill_LevelData *Create();
	static void RushAttackLoad(const char * sFileName);//�p�[�c�̐ݒ�
	static void AssistCrystalLoad(const char * sFileName);//�p�[�c�̐ݒ�
	static void BlackHoleLoad(const char * sFileName);//�p�[�c�̐ݒ�
	static void GuardLoad(const char * sFileName);//�p�[�c�̐ݒ�

	static CBlackHole::State GetStateBlackHole(int nLevel) { return m_BlackHoleState[nLevel]; }
	static CAssistCrystal::State GetStateAssistCrystal(int nLevel) { return m_AssistCrystalState[nLevel]; }
	static CRushAttack::State GetStateRushAttack(int nLevel) { return m_RushAttackState[nLevel]; }
	static CGuard::State GetStateGuard(int nLevel) {return m_GuardState[nLevel];}
private:
	static CBlackHole::State m_BlackHoleState[CBlackHole::Level_MAX + 1];
	static CAssistCrystal::State m_AssistCrystalState[CAssistCrystal::Level_MAX + 1];
	static CRushAttack::State m_RushAttackState[CRushAttack::Level_MAX + 1];
	static CGuard::State m_GuardState[CGuard::Level_MAX + 1];

};


#endif // !_PLAYER_H_

