//--------------------------------------------
//�G�̏o���ݒ菈��
//�쐬�ҁF��
//--------------------------------------------
#ifndef _SKILL_LEVELDATA_H_
#define _SKILL_LEVELDATA_H_
#include "main.h"
#include "blackhole.h"
#include "assistcrystal.h"
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
	static void BlackHoleLoad(const char * sFileName);//�p�[�c�̐ݒ�
	static CBlackHole::State GetStateBlackHole(int nLevel) { return m_BlackHoleState[nLevel]; }
	static void AssistCrystalLoad(const char * sFileName);//�p�[�c�̐ݒ�
	static CAssistCrystal::State GetStateAssistCrystal(int nLevel) { return m_AssistCrystalState[nLevel]; }

private:
	static CBlackHole::State m_BlackHoleState[CBlackHole::Level_MAX];
	static CAssistCrystal::State m_AssistCrystalState[CAssistCrystal::Level_MAX];
};


#endif // !_PLAYER_H_

