//--------------------------------------
//�Q�[����ʂ̏���
//--------------------------------------
#include "game.h"
#include "Renderer.h"//��ŏ���
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "fade.h"
#include "Scene3D.h"
#include "time.h"
#include "model_spawner.h"
#include "collision.h"
#include "score.h"
#include "field.h"
#include "meshsphere.h"
#include "stage.h"
#include "Enemy.h"
#include "Polygon.h"
#include "pause.h"
#include "XInput.h"
#include "camera.h"
#include "Particle.h"
#include "gauge.h"
#include "directinput.h"
#include "enemy_spawn_manager.h"
#include "gauge.h"
#include "skillselect.h"
#include "character.h"
#include "gaugeber.h"
#include "character_partsdata.h"
#include "enemy001.h"
#include "stage_preset_data.h"
#include <time.h>
#include "gametimer.h"
#include "skill_leveldata.h"
#include "savedata.h"
#include "camera.h"
#define BOSS_LIFE (100)		//������
#define PLAYER_LIFE (100)		//������
#define MAX_DELAY (30)//�f�B���C�̍ő�
//�ÓI�����o�ϐ��錾
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CModel_Spawner *CGame::m_pModel = nullptr;
CScore	*CGame::m_pScore = nullptr;
CField	*CGame::m_pField = nullptr;
CField	*CGame::m_pSea = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CPolygon *CGame::m_Cursol = nullptr;
CMeshSphere *CGame::m_pMeshSphere = nullptr;
CStage  *CGame::m_pStage = nullptr;
CParticle   *CGame::m_Particle = nullptr;
CEnemySpawnManager   *CGame::m_pEnemySpawnManager = nullptr;
CGauge   *CGame::m_pExpGauge = nullptr;
CGauge   *CGame::m_pHPGauge = nullptr;
CGametimer   *CGame::m_pGametimer = nullptr;

static float s_texrotx = 0.0f;
static float s_texseax = 0.0f;
static int s_nTime = 0;
static bool s_bTime = false;
static int ClearTime = 3;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGame::CGame()
{
	m_Player = nullptr;
	m_pFlore = nullptr;
	m_pBg = nullptr;
	m_pModel = nullptr;
	m_pScore = nullptr;
	m_pField = nullptr;
	m_pMeshSphere = nullptr;
	m_pSea = nullptr;
	m_Particle = nullptr;
	m_pStage = nullptr;
	m_Polygon = nullptr;
	m_nCntDelay = 0;
	m_bPush = false;
	m_bEnd = false;
	m_pEnemySpawnManager = nullptr;
	m_pExpGauge = nullptr;
	m_pHPGauge = nullptr;
	m_bIsClear = false;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CGame::~CGame()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CGame::Init(void)
{
	CManager::GetRenderer()->GetCamera()->Init();
	ShowCursor(false);

	//�L�����N�^�[�̃p�[�c��ǂݍ���
	CCharacterPartsData::Create();
	//�v���C���[�̐���
	if (!m_Player)
	{
		m_Player = CPlayer::Create();
	}
	//�o���l�̃Q�[�W�𐶐�
	if (!m_pExpGauge)
	{
		m_pExpGauge = CGauge::Create({ 0.0f,680.0f,0.0f }, { SCREEN_WIDTH,10.0f,0.0f }, { 0.5,0.5,1.0,1.0 }, SCREEN_WIDTH, 2, CGauge::R_ADD);
		m_pExpGauge->ResetGauge(0);
	}
	//�̗̓Q�[�W�̐���
	if (!m_pHPGauge)
	{
		float fHP = m_Player->GetLife();
		m_pHPGauge = CGauge::Create({ 0.0f,100.0f,0.0f }, { 400.0f,15.0f,0.0f }, { 0.5,1.0,0.5,1.0 }, 400, fHP, CGauge::R_ADD);
		//m_pHPGauge->ResetGauge(0);
	}
	//�p�[�e�B�N���V�X�e���̐���
	if (m_Particle == nullptr)
	{
		m_Particle = new CParticle;
	}
	//��̐���
	if (m_pMeshSphere == NULL)
	{
		m_pMeshSphere = CMeshSphere::Create(D3DXVECTOR3(0.0f, -2000.0f, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),
			8, 4, 40000.0f, 1.0f, CTexture::SKY);
	}
	//�X�e�[�W�̐���
	if (m_pStage == NULL)
	{
		m_pStage = new CStage;
		m_pStage->Init();
		m_pStage->SetStage();
	}
	//CField::Create({ 0.0,0.0,0.0 }, {150.0f,0.0,150.0f}, { 0.0f,0.0f,0.0f }, 20, 20, CTexture::FIELD);
	if (!m_pGametimer)
	{
		m_pGametimer = CGametimer::Create({ SCREEN_WIDTH / 2,100.0f,0.0f }, { 1.0,1.0,1.0,1.0 });
	}
	//�X�L���̃X�e�[�^�X�̓ǂݍ���
	CSkill_LevelData::Create();
	////�ړI�\��
	//CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 40.0f, 0.0f),
	//	D3DXVECTOR3(210.0f, 20.0f, 0.0f), CTexture::TargetText);
	////������@
	//CPolygon::Create(D3DXVECTOR3(140.0f, SCREEN_HEIGHT-130.0f, 0.0f),
	//	D3DXVECTOR3(140.0f, 90.0f, 0.0f), CTexture::Operation);
	//CEnemy001::Create({0.0f,0.0f,0.0f}, { 0.0f,0.0f,0.0f });

	m_fAlpha = 1.0f;
	m_bNextMode = false;
	m_nTimer = 0;
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGame::Uninit(void)
{
	if (m_pGametimer)
	{
		m_pGametimer->Uninit();
		m_pGametimer = nullptr;
	}
	if (m_Player)
	{
		m_Player->Uninit();
		m_Player = nullptr;
	}
	if (m_pModel)
	{
		m_pModel->Uninit();
		delete m_pModel;
		m_pModel = nullptr;
	}
	if (m_pScore)
	{
		m_pScore->Uninit();
		delete m_pScore;
		m_pScore = nullptr;
	}
	if (m_pMeshSphere)
	{
		m_pMeshSphere->Uninit();
		delete m_pMeshSphere;
		m_pMeshSphere = nullptr;
	}
	if (m_Cursol)
	{
		m_Cursol->Uninit();
		m_Cursol = nullptr;
	}
	if (m_Polygon)
	{
		m_Polygon->Uninit();
		m_Polygon = nullptr;
	}
	if (m_pExpGauge)
	{
		m_pExpGauge->Uninit();
		m_pExpGauge = nullptr;
	}

	CEnemy::SetMaxEnemy(0);
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CGame::Update(void)
{
	//DirectInput�̃Q�[���p�b�h�̎擾
	CDirectInput *pGamePad = CManager::GetDirectInput();
	//�Q�[���������Ă�����
	if (m_bEnd == false)
	{
		if (!m_bNextMode)
		{

			if (m_pExpGauge)
			{
				float fExp = m_pExpGauge->GetGaugeBer(0)->GetGaugeValue();
				float fMaxExp = m_pExpGauge->GetGaugeBer(0)->GetGaugeValueMax();
				//�o���l�Q�[�W���ő�ɂȂ�����O�ɖ߂�
				if (fExp >= fMaxExp)
				{
					//�Q�[�����~�߂�
					CManager::SetPause(true, false);
					m_pExpGauge->ResetGauge(0);
					CSkillSelect::Create();

				}

			}
			if (m_pGametimer)
			{
				int nTime = m_pGametimer->GetMinute();
				if (nTime >= ClearTime)
				{
					m_bIsClear = true;
				}
			}

			//�N���A���肪�L���Ȃ�N���A��ʂ�\��������
			if (m_bIsClear)
			{
				CSaveData::SaveFile();

				m_bNextMode = true;
				// �^�C�g���V�[���֍s��
				CFade::SetFade(CManager::MODE_TITLE);
			}
		}
	}

}

//--------------------------------------------
//�`��
//--------------------------------------------
void CGame::Draw()
{
}

