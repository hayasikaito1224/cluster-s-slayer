//=============================================================================
//
// �Z�[�u�f�[�^�֘A�̏��� [savedata.cpp]
// Author : �O���B
//
//=============================================================================
#include "savedata.h"

int CSaveData::m_nClearPercent = 0;
int CSaveData::m_nHaveMoney = 0;
bool CSaveData::m_bHaveSkill[] = {};
string CSaveData::m_FileName = "";

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSaveData::CSaveData()
{
	m_nClearPercent = 0;
	m_nHaveMoney = 0;

	for (int SkillNum = 0; SkillNum < CPlayer::Skill_Max; SkillNum++)
	{
		m_bHaveSkill[SkillNum] = false;
	}
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSaveData::~CSaveData()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CSaveData::Init(void)
{
	return S_OK;
}

//=============================================================================
// �X�e�[�W�t�@�C���̃��[�h
//=============================================================================
HRESULT CSaveData::LoadFile(string FileName)
{
	m_FileName = FileName;
	m_nClearPercent = 0;
	m_nHaveMoney = 0;

	for (int SkillNum = 0; SkillNum < CPlayer::Skill_Max; SkillNum++)
	{
		m_bHaveSkill[SkillNum] = false;
	}

	// �t�@�C����ǂݍ���
	ifstream File(m_FileName);

	if (!File)
	{
		return E_FAIL;
	}

	string str = "";

	//=============================================================================
	// �t�@�C���ǂݍ���
	//=============================================================================
	// �t�@�C���̒��g����s���ǂݎ��
	while (getline(File, str))
	{
		if (str == "")
		{
			str = "0";
		}

		// �N���A���擾
		if (str.find("ClearPercent=") == 0)
		{
			// ���̃u���b�N��movex��ύX
			str.erase(0, sizeof("ClearPercent="));
			m_nClearPercent = stoi(str);
		}

		else if (str.find("HaveMoney=") == 0)
		{
			// ���̃u���b�N��movex��ύX
			str.erase(0, sizeof("HaveMoney="));
			m_nHaveMoney = stoi(str);
		}

		else if (str.find("Skill=") == 0)
		{
			// �X�L���ԍ��ɉ������X�L�����擾
			str.erase(0, sizeof("Skill="));
			m_bHaveSkill[stoi(str)] = true;
		}
	}

	if (m_nClearPercent > m_nMaxClearPercent)	m_nClearPercent = m_nMaxClearPercent;
	if (m_nHaveMoney > m_nMaxHaveMoney)	m_nHaveMoney = m_nMaxHaveMoney;

	return S_OK;
}

//=============================================================================
// �X�e�[�W�t�@�C���̃Z�[�u
//=============================================================================
HRESULT CSaveData::SaveFile()
{
	// �t�@�C���ɏ�������
	ofstream File(m_FileName);

	if (!File)
	{
		return E_FAIL;
	}

	File << "ClearPercent=" << m_nClearPercent << "\n";	// �N���A���Z�[�u
	File << "HaveMoney=" << m_nHaveMoney << "\n";		// �������Z�[�u

	for (int SkillNum = 0; SkillNum < CPlayer::Skill_Max; SkillNum++)
	{
		if (m_bHaveSkill[SkillNum])
		{
			File << "Skill=" << SkillNum << ",";		// �����X�L���Z�[�u
		}
	}

	File << endl;

	return S_OK;
}

//=============================================================================
// �X�e�[�W�t�@�C���̏���
//=============================================================================
HRESULT CSaveData::ResetFile(string FileName)
{
	m_FileName = FileName;

	// �t�@�C���ɏ�������
	ofstream File(m_FileName);

	if (!File)
	{
		return E_FAIL;
	}

	File << "ClearPercent=" << 0 << "\n";	// �N���A�����Z�b�g
	File << "HaveMoney=" << 0 << "\n";		// ���������Z�b�g

	File << endl;

	return S_OK;
}