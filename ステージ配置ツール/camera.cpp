//----------------------------------
//�|���S���̏���
//-----------------------------------
#include "camera.h"
#include "input.h"
#include "Renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "mouse.h"
#include "XInput.h"
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCamera::CCamera()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCamera::~CCamera()
{

}
//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT CCamera::Init(void)
{
	m_fLong = MAX_PLAYER_RANGE;
	m_posV = D3DXVECTOR3(0.0f, 0.0f, - m_fLong);
	m_posR = D3DXVECTOR3(0.0f, 80.0f,0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, -(D3DX_PI / 2.5f), 0.0f);


	return S_OK;
}

//=============================================================================
// �|���S���̏I������
//=============================================================================
void CCamera::Uninit(void)
{
}

//=============================================================================
// �|���S���̍X�V����
//=============================================================================
void CCamera::Update(void)
{

}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CCamera::Draw(void)
{

}
//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CCamera::SetPlayerCamera(D3DXVECTOR3 pos)
{
	m_posR = D3DXVECTOR3(pos.x, pos.y, pos.z);
}
//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CCamera::SetMapCamera(D3DXVECTOR3 pos)
{
	m_posR = D3DXVECTOR3(pos.x, 100.0f, pos.z);
	m_posV = D3DXVECTOR3(pos.x - sinf(m_rot.x),
		MAP_RANGE, pos.z - cosf(m_rot.x));


}
//�ݒ�
void CCamera::SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();
	//�r���[�|�[�g�̐ݒ�
	pDevice->SetViewport(&m_Viewport);

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);
	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(m_fAngleView),//�J�����̉�p
		(float)m_Viewport.Width / (float)m_Viewport.Height,//��ʔ䗦!!!�r���[�|�[�g���g���Ƃ��r���[�|�[�g�̕��������g��
		10.0f,//��O�̕`�搧��
		30000.0f);//���̕`�搧��
				  //�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);
	//�r���[�}�g���b�N�X���쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);
	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

HRESULT CCamera::SetViewport(DWORD Xpos, DWORD Ypos, DWORD Width, DWORD Height, int nCnt)
{
	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();

	m_Viewport.X = Xpos;
	m_Viewport.Y = Ypos;
	m_Viewport.Width = Width;
	m_Viewport.Height = Height;
	m_Viewport.MinZ = 0.0f;
	m_Viewport.MaxZ = 1.0f;

	pDevice->SetViewport(&m_Viewport);
	return D3D_OK;
}
