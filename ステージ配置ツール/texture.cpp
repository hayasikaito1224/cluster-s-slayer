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

	D3DXCreateTextureFromFile(pDevice,
		"",	// ����
		&m_pTexture[None]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Flor000.png",//���e�N�X�`��
		&m_pTexture[Test]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Field000.jpg",//�t�B�[���h
		&m_pTexture[FIELD]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Graph-paper.png",//�t�B�[���h
		&m_pTexture[FIELD2]);

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
		"data/TEXTURE/shadow000.jpg",//�G�t�F�N�g
		&m_pTexture[Effect]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/stagecursor.png",//�J�[�\��
		&m_pTexture[CURSOR]);

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