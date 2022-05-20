//--------------------------------------
//�Q�[����ʂ̏���
//--------------------------------------
#include "game.h"
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
#include "Polygon.h"
#include "pause.h"
#include "XInput.h"
#include "camera.h"
#include "goal.h"
#include "stageeditor.h"
#include "model.h"
//�ÓI�����o�ϐ��錾
CBg		*CGame::m_pBg = NULL;
CPlayer	*CGame::m_Player = NULL;
CField	*CGame::m_pField = NULL;
CPolygon *CGame::m_Polygon = NULL;
CMeshSphere *CGame::m_pMeshSphere = NULL;
CStage  *CGame::m_pStage = NULL;

static int s_nTime = 0;
static bool s_bTime = false;


//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGame::CGame()
{
	m_Player = NULL;
	m_pBg = NULL;
	m_pField = NULL;
	m_pMeshSphere = NULL;
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

	//��̐���
	if (m_pMeshSphere == NULL)
	{
		m_pMeshSphere = CMeshSphere::Create(D3DXVECTOR3(0.0f, -1000.0f, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),
			20, 12, 20000.0f, 1.0f, CTexture::FIELD);
	}
	CStageEditor *pStageEditor = new CStageEditor;
	pStageEditor->Init();
	m_bNextMode = false;
	m_nTimer = 0;
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGame::Uninit(void)
{
	if (m_Player != NULL)
	{
		m_Player->Uninit();

		m_Player = NULL;
	}
	if (m_pMeshSphere != NULL)
	{
		m_pMeshSphere->Uninit();
		delete m_pMeshSphere;
		m_pMeshSphere = NULL;
	}


}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CGame::Update(void)
{

}

//--------------------------------------------
//�`��
//--------------------------------------------
void CGame::Draw(LPD3DXMATRIX mtrix)
{

}

