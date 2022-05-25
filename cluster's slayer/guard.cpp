//=============================================================================
//
// Polygon����
//
//=============================================================================
#include "guard.h"
#include "manager.h"
#include "Renderer.h"
#include "scene3D.h"
#include "model.h"
#include "3Dpolygon.h"
#include "skill_leveldata.h"
static const float WidthLenght = 50.0f;
static const float HeightGuard = 100.0f;
static const D3DXVECTOR3 GuardSize = { 20.0f,20.0f,0.0f };
//=============================================================================
//�R���X�g���N�^
//=============================================================================
CGuard::CGuard(OBJTYPE nPriority):CScene (nPriority)
{
	m_bDraw = true;
	m_pGuardPolygon = nullptr;
	m_nCntGuard = 0;
	m_fHeight = HeightGuard;
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CGuard::~CGuard()
{

}

//=============================================================================
//������
//=============================================================================
HRESULT CGuard::Init()
{
	m_State = CSkill_LevelData::GetStateGuard(m_nLevel);

	SetGuardQuantity(m_State.m_nMaxGuard);
	return S_OK;

}

//=============================================================================
//�I��
//=============================================================================
void CGuard::Uninit()
{
	for (int nCnt = 0; nCnt < m_nCntGuard; nCnt++)
	{
		m_pGuardPolygon[nCnt]->Uninit();
		delete m_pGuardPolygon[nCnt];
		m_pGuardPolygon[nCnt] = nullptr;
	}

	Release();
}

//=============================================================================
//�X�V
//=============================================================================
void CGuard::Update()
{
	m_rot.y += 0.01f;
}

//=============================================================================
//�`��
//=============================================================================
void CGuard::Draw()
{

	if (m_bDraw)
	{
		D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X
		D3DXMATRIX mtxParent;//�e�̃}�g���b�N�X
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

																		 //���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxWorld);

		////�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);
		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);
		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

		for (int nCnt = 0; nCnt < m_nCntGuard; nCnt++)
		{
			if (m_pGuardPolygon[nCnt])
			{
				m_pGuardPolygon[nCnt]->Draw(m_mtxWorld);
			}
		}

	}


}
//=============================================================================
//�_���[�W�K�[�h�̌���ύX
//=============================================================================
void CGuard::SetGuardQuantity(int nGuard)
{
	if (m_pGuardPolygon)
	{
		//�|���S���̍폜
		for (int nCnt = 0; nCnt < m_nCntGuard; nCnt++)
		{
			m_pGuardPolygon[nCnt]->Uninit();
			delete m_pGuardPolygon[nCnt];
			m_pGuardPolygon[nCnt] = nullptr;
		}
		delete[] m_pGuardPolygon;
		memset(m_pGuardPolygon, NULL, sizeof(m_pGuardPolygon));
		m_pGuardPolygon = nullptr;

		if (nGuard <= 0)
		{
			m_bDraw = false;
		}
		else
		{
			m_bDraw = true;
		}
	}
	m_nCntGuard = nGuard;
	if (!m_pGuardPolygon&& m_nCntGuard > 0)
	{
		m_pGuardPolygon = new C3DPolygon*[m_nCntGuard];
		for (int nCnt = 0; nCnt < m_nCntGuard; nCnt++)
		{
			float fRot = ((D3DX_PI*2) / m_nCntGuard) * nCnt;
			D3DXVECTOR3 movePos = { cosf(fRot) * WidthLenght ,m_fHeight ,sinf(fRot)*WidthLenght };
			D3DXVECTOR3 PoligonPos = movePos + m_pos;
			D3DXVECTOR3 vec = m_pos - PoligonPos;
			float moveRot = atan2f(vec.x, vec.z);

			//�_���K�p�̃|���S������
			m_pGuardPolygon[nCnt] = C3DPolygon::Create(movePos, {0.0f,moveRot,0.0f},GuardSize, CTexture::Sheild, { 1.0,1.0,1.0,0.5f });
			m_pGuardPolygon[nCnt]->SetCanParent(true);
			m_pGuardPolygon[nCnt]->SetCanCulling(true);
			//m_pGuardPolygon[nCnt]->SetParentMtx(m_mtxWorld);
		}
	}
}
//=============================================================================
//�_���[�W�K�[�h�̃y�A�����g�ݒ�
//=============================================================================
void CGuard::SetParent(CModel * pParent)
{
	for (int nCnt = 0; nCnt < m_nCntGuard; nCnt++)
	{
		m_pGuardPolygon[nCnt]->SetParent(pParent);
	}
}
//=============================================================================
//�N���G�C�g
//=============================================================================
CGuard * CGuard::Create(const D3DXVECTOR3 & pos, const float& fHeight, const int& nLevel)
{
	CGuard *pGuard = new CGuard;
	if (pGuard)
	{
		pGuard->m_pos = pos;
		pGuard->m_fHeight = fHeight;
		pGuard->m_nLevel = nLevel;

		pGuard->Init();
	}

	return pGuard;
}

