#include "main.h"
#include "manager.h"
#include "Renderer.h"
#include "player.h"
#include "model.h"
#include "motion.h"
#include "layer_structure.h"
#include "score.h"
#include "keyboard.h"
#include "game.h"
#include "collision.h"
#include "fade.h"
#include "camera.h"
#include "stage.h"
#include "field.h"
#include "model_spawner.h"
#include "shadow.h"
#include "XInput.h"
#include "sound.h"
#include "keyboard.h"
#include "player_controller.h"
#include "goal.h"
#include "effect.h"
#include "billboard.h"

//------------------------------------
//�}�N����`
//------------------------------------
#define MAX_DELAY_TIME (30)
#define MAX_MAGIC_SHOT_TIME (2.0)
#define MAX_PLAYER_JUMP (1)//�ő�̃W�����v��
#define MAX_PLAYER_PARTS (16)
#define PLAYER_SIZE (20.0)
#define SWORDEFFECT_LONG (16)
#define PLAYER_RANGE (400.0)//�v���C���[�ƓG�̋߂���}��͈�
#define PLAYER_ROCKON_SIZE (5.0)//���b�N�I���摜�̃T�C�Y
std::vector<CModel*> CPlayer::m_pSModel;

//--------------------------
//�R���X�g���N�g
//----------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pModel = nullptr;
	m_bDelay = false;

}
//--------------------------
//�f�X�g���N�g
//----------------------------
CPlayer::~CPlayer()
{

}

CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = NULL;
	pPlayer = new CPlayer;
	pPlayer->Init();
	return pPlayer;
}

D3DXVECTOR3 CPlayer::GetModelPos()
{
	return{ m_pModel->GetModel()->GetMtxWorld()._41,m_pModel->GetModel()->GetMtxWorld()._42,m_pModel->GetModel()->GetMtxWorld()._43 };

}

HRESULT CPlayer::Init()
{
	//�v���C���[�̃R���g���[���[�̌Ăяo��
	m_pController = new CPlayer_Controller;
	m_pos = D3DXVECTOR3(PLAYER_POS_X, PLAYER_POS_Y, PLAYER_POS_Z);
	m_move = -2.0f;
	m_fSoundInterval = 1.0f;
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_fGravity = 0.0f;//�d�͓x
	m_bland = true;
	m_bMove = false;
	m_pModel = CModel_Spawner::Create(m_pos, { 0.0f,0.0f,0.0f }, 0, CModel::TYPE_PLAYER);
	pShadow = CShadow::Create(m_pos, PLAYER_SIZE, CTexture::Effect);
	return S_OK;
}

void CPlayer::Uninit()
{
	if (m_pModel != NULL)
	{
		m_pModel->Uninit();
		m_pModel = NULL;
	}

	if (pShadow)
	{
		pShadow->Uninit();
		delete pShadow;
		pShadow = NULL;
	}

	Release();
}

void CPlayer::Update()
{
	CXInput *pGamePad = CManager::GetXInput();

	//�O��̈ʒu���̕ۑ�
	m_lastpos = m_pos;

	//�v���C���[�̈ړ�����
	m_pController->TestMove(m_pos);
	if (m_pModel != nullptr)
	{
		m_pModel->SetSPos(m_pos);
	}
	m_pController->MouseMove(m_pos);

	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	m_pController->MouseCameraControl();
	//Enter���������烂�f������
	if (Key->GetTrigger(DIK_RETURN) == true)
	{
		CModel *Securement = {};
		m_pSModel.push_back(Securement);
		m_pSModel[0] = CModel::Create(m_pModel->GetSPos(), m_rot, 0, CModel::TYPE_PLAYER);
	}

	if(pShadow!=nullptr)
	{
		pShadow->SetPos(m_pos.x, m_pos.z, D3DXVECTOR3(PLAYER_SIZE, 0.0f, PLAYER_SIZE));
	}


	//m_pCollision->SetPos(m_pos);
	CCamera *pCamera = CRenderer::GetCamera();
	pCamera->SetPlayerCamera(m_pos);
	CScene::SetPos(m_pos);

}

void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X
	//�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����gtryg
	D3DXMatrixIdentity(&m_mtxWorld);      
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//�����𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);


	//���f������
	if (m_pModel)
	{
		m_pModel->Draw();

	}

	for (int nCnt = 0; nCnt <(int)m_pSModel.size(); nCnt++)
	{
		if (m_pSModel[nCnt] != nullptr)
		{
			m_pSModel[nCnt]->Draw();
		}
	}

	m_pController->Drawtext();
	Drawtext();
}
void CPlayer::Drawtext()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[1200];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n\n\n\n\n\n �v���C���[��� \n");
	nNum += sprintf(&str[nNum], " [Pos] X%.2f,Y%.2f,Z%.2f \n", m_pModel->GetSPos().x, m_pModel->GetSPos().y, m_pModel->GetSPos().z);
	nNum += sprintf(&str[nNum], " [rot] X%.2f,Y%.2f,Z%.2f \n", m_rot.x, m_rot.y, m_rot.z);

	//for (int nCnt = 0; nCnt < 2; nCnt++)
	//{
	//	nNum += sprintf(&str[nNum], " [SwordEffectEndPos] X%.2f,Y%.2f,Z%.2f \n", m_pSwordLocus->GetEndPos().x, m_pSwordLocus->GetEndPos().y, m_pSwordLocus->GetEndPos().z);
	//}


	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// �e�L�X�g�`��
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}

