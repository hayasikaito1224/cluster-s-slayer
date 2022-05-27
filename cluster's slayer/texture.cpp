//=============================================================================
//
// �e�N�X�`������ [texture.cpp]
// Author : �H�������
//
//=============================================================================
//=============================================================================
// �C���N���[�h
//=============================================================================
#include "texture.h"
#include "Renderer.h"
#include "manager.h"

//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CTexture::CTexture()
{

}

//=============================================================================
// �f�t�H���g�f�X�g���N�^
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// �e�N�X�`���̐���
//=============================================================================
void CTexture::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X���擾����

	m_pTexture[None] = nullptr;
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/text_texture.png",//���e�N�X�`��
		&m_pTexture[Text]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Flag.png",//���e�N�X�`��
		&m_pTexture[GOAL]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number000.png",//����
		&m_pTexture[TIME]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/fade.png",//����
		&m_pTexture[FADE]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/sky_loop001.png",//��
		&m_pTexture[SKY]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/shadow000.jpg",//�e
		&m_pTexture[SHADOW]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Fire.png",//��
		&m_pTexture[FIRE]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle_TypeB.png",//���@�w
		&m_pTexture[MagicCircle_TypeB]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Ring001.png",//ring
		&m_pTexture[RingEffect]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/HeelEffect.jpg",//�񕜌n�̉摜
		&m_pTexture[LifeEffect]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/shadow000.jpg",//�G�t�F�N�g
		&m_pTexture[Effect]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/GlitterEffect000.png",//�G�t�F�N�g
		&m_pTexture[GlitterEffect]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/hiteffect000.jpg",//�G�t�F�N�g
		&m_pTexture[HitEffect]);

	//============================================================
	//�G�t�F�N�g�e�N�X�`��
	//============================================================
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/CycleEffect00.png",//������G�t�F�N�g
		&m_pTexture[CycleEffect]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Target0.png",//�~�T�C�����e�\��n�G�t�F�N�g
		&m_pTexture[TrgetLock]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Explosion.png",//�����h�[���G�t�F�N�g
		&m_pTexture[Explosion]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Thunder3.png",//�T���_�[
		&m_pTexture[Thunder]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Crater.png",//�T���_�[
		&m_pTexture[Crater]);



	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Trajectory000.png",//�G�t�F�N�g
		&m_pTexture[SwordEffect]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/GaugeBer.png",//�Q�[�W
		&m_pTexture[GAUGEBER]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/GaugeBG000.png",//�Q�[�W�̘g
		&m_pTexture[GAUGEFRAME]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BG000.png",//�Q�[�W�̘g
		&m_pTexture[COL_AREA]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Field000.jpg",//��	
		&m_pTexture[FIELD]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Map_Player000.png",//��	
		&m_pTexture[Map_Player]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MapEnemy.png",//��	
		&m_pTexture[Map_Enemy]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Purpose000.png",//��	
		&m_pTexture[Map_Purpose]);
	//============================================================
	//�X�L���֌W
	//============================================================
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/ATKup.png",//A�{�^��
		&m_pTexture[ATKup]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/Beam.png",//A�{�^��
		&m_pTexture[Beam]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/BlackHole.png",//A�{�^��
		&m_pTexture[BlackHole]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/Heal.png",//A�{�^��
		&m_pTexture[Heal]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/OverHeal.png",//A�{�^��
		&m_pTexture[OverHeal]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/Rocket.png",//A�{�^��
		&m_pTexture[Rocket]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/RushAttack.png",//A�{�^��
		&m_pTexture[RushAttack]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SKILL/Sheild.png",//A�{�^��
		&m_pTexture[Sheild]);
	//============================================================
	//�{�^��
	//============================================================
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BUTTON/A_button.png",//A�{�^��
		&m_pTexture[A_BUTTON]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BUTTON/B_button.png",//A�{�^��
		&m_pTexture[B_BUTTON]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BUTTON/X_button.png",//A�{�^��
		&m_pTexture[X_BUTTON]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BUTTON/L_button.png",//A�{�^��
		&m_pTexture[L_BUTTON]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BUTTON/SkillGauge000.png",//�Q�[�W
		&m_pTexture[SKILLGAUGE]);

	//============================================================
	//�^�C�g��
	//============================================================
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Title000.png",//�^�C�g���w�i
		&m_pTexture[Title]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Please Enter.png",//�Q�[���X�^�[�g
		&m_pTexture[GameStart]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/operation_method000.png",//�`���[�g���A��(�Q�[�����ɕ\�����鑀����@)
		&m_pTexture[Operation]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Cursor.png",		  //�J�[�\��
		&m_pTexture[Cursol]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title_file01.png",
		&m_pTexture[Title_File1]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title_file02.png",
		&m_pTexture[Title_File2]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title_file03.png",
		&m_pTexture[Title_File3]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/datadelete.png",
		&m_pTexture[Title_Delete]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/databack.png",
		&m_pTexture[Title_Back]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/backtitle.png",
		&m_pTexture[Menu_Back]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/menu_gamestart.png",
		&m_pTexture[Menu_GameStart]);

	//============================================================
	//�Q�[���I�[�o�[
	//============================================================

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/FAILED000.png",//�Q�[���I�[�o�[���S
		&m_pTexture[Gameover000]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Result000.png",//�Q�[���N���A�w�i
		&m_pTexture[GameClear000]);
	
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Retry000.png",//���g���C
		&m_pTexture[Retry]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/titleback.png",//�^�C�g���ɖ߂�
		&m_pTexture[TitleBack001]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Gameback.png",//�Q�[���ɖ߂�
		&m_pTexture[GameBack]);
	//============================================================
	//�Q�[�����
	//============================================================
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Tutorial000.png",//�`���[�g���A�����
		&m_pTexture[Operation01]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/targettext000.png",//�ړI�n�\���p��
		&m_pTexture[TargetText]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/stagecursor.png",//���b�N�I���p
		&m_pTexture[RockOn]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SkillOK000.png",//���b�N�I���p
		&m_pTexture[SkillOk]);

}

//=============================================================================
// �I��
//=============================================================================
void CTexture::Uniinit(void)
{
	for (int nCntTexture = 0; nCntTexture < Max; nCntTexture++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[nCntTexture] != NULL)
		{
			m_pTexture[nCntTexture]->Release();
			m_pTexture[nCntTexture] = NULL;
		}
	}
}