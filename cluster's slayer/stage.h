//========================================
// �X�e�[�W�̔z�u����
// Author:��
//========================================
#ifndef _STAGE_H_
#define _STAGE_H_
#include "main.h"
#define STAGEPRESET_MAX (5)

class CStage_Preset;

class CStage
{
public:
	//------------------------------------
	// �R���X�g���N�^�A�f�X�g���N�^
	//------------------------------------
	CStage();
	~CStage();
	HRESULT Init();
	void Uninit();
	void SetStage();//�X�e�[�W�̐ݒ�
	void PresetCreate(const char *cFileName);
private:
	CStage_Preset *m_pStagePreset[STAGEPRESET_MAX];
};
#endif _STAGE_H_