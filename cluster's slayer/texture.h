//=============================================================================
//
// �e�N�X�`������ [texture.h]
// Author : �H������
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CTexture
{
public:
	CTexture();	// �f�t�H���g�R���X�g���N�^
	~CTexture();// �f�t�H���g�f�X�g���N�^
	typedef enum
	{
		None = -1,		// �e�N�X�`������
		Text,			// ���e�N�X�`��
		TIME,			// �^�C���i���o�[
		FADE,			
		GOAL,
		GAUGEBER,//�Q�[�W
		GAUGEFRAME,//�Q�[�W�̘g
		COL_AREA,
		SKILLGAUGE,//�K�E�Z�悤�̃Q�[�W
		SHADOW,			//�e
		FIELD,			//��
		SKY,			//��
		FIRE,
		ATKup,
		Eye,
		Heal,
		OverHeal,
		Sheild,
		Beam,
		BlackHole,
		Rocket,
		RushAttack,
		A_BUTTON,
		B_BUTTON,
		X_BUTTON,
		L_BUTTON,
		Map_Player,
		Map_Enemy,
		Map_Purpose,	//�ړI�n�Ɏw�����
		Title,			//�^�C�g���w�i
		GameStart,		//�Q�[���X�^�[�g
		Gameover000,	//�Q�[���I�[�o�[���S
		GameClear000,	//�Q�[���N���A�w�i
		Cursol,			//�J�[�\��
		Retry,			//���g���C
		TitleBack001,		//�^�C�g���ɖ߂�
		GameBack,		//�Q�[���ɖ߂�
		Operation,		//�`���[�g���A��
		Operation01,
		Effect,			//�G�t�F�N�g
		GlitterEffect,			//�L���L���G�t�F�N�g
		MagicCircle_TypeB,			//�L���L���G�t�F�N�g
		RingEffect,			//�L���L���G�t�F�N�g
		LifeEffect,
		HitEffect,
		SwordEffect,			//�G�t�F�N�g
		TargetText,//�ړI�n�\���p��
		RockOn,//���b�N�I���p
		SkillOk,//���b�N�I���p
		CycleEffect,	//������G�t�F�N�g
		TrgetLock,	//�~�T�C�����e�n�_�G�t�F�N�g
		Explosion,	//�����h�[��
		Thunder,	//�T���_�[
		Max,			// �e�N�X�`���̍ő吔
	} Type;

	void Init(void);	// �e�N�X�`���̐���
	LPDIRECT3DTEXTURE9 GetTexture(Type Type) { return m_pTexture[Type]; }	// �e�N�X�`���̊��蓖��(�e�N�X�`���̎��) { return �I�񂾃e�N�X�`����Ԃ� }
	void Uniinit(void);	// �I��

private:
	LPDIRECT3DTEXTURE9	m_pTexture[Max];	//�e�N�X�`��
};

#endif