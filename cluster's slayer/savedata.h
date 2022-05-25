//=============================================================================
//
// �Z�[�u�f�[�^�֘A�̏��� [savedata.h]
// Author : �O���B
//
//=============================================================================
#ifndef _SAVEDATA_H_
#define _SAVEDATA_H_
#include "player.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CSaveData
{
public:
	CSaveData();
	~CSaveData();

	HRESULT Init(void);

	static HRESULT LoadFile(string FileName);
	static HRESULT SaveFile();
	static HRESULT ResetFile(string FileName);
	static bool GetHaveSkill(int nSkillType) { return m_bHaveSkill[nSkillType]; }
	static void FetchSetHaveSkill(int nSkillType) { m_bHaveSkill[nSkillType] = true; }

private:
	static int m_nClearPercent;		// �N���A��
	static const int m_nMaxClearPercent = 100;

	static int m_nHaveMoney;		// ������
	static const int m_nMaxHaveMoney = 99999;

	static bool m_bHaveSkill[CPlayer::Skill_Max];	// �����X�L��

	static string m_FileName;
};

#endif