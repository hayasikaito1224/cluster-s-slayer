//---------------------------------------------------
//�w�i�̏���
//---------------------------------------------------
#include"smallscore.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"
#include "number.h"
#include <math.h>
#include "Score.h"
static const int MaxTime = 20;
//--------------------------
//�R���X�g���N�g
//----------------------------
CSmallScore::CSmallScore(OBJTYPE nPriority) :CScene(nPriority)
{
	m_fMove = 0.0f;
	m_bCanAddAlpha = true;
	m_bCanDefAlpha = false;
}

//--------------------------
//�f�X�g���N�g
//----------------------------
CSmallScore::~CSmallScore()
{

}

//--------------------------
//������
//----------------------------
HRESULT CSmallScore::Init()
{
	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		//�i���o�[�̌���������
		m_pNumber[nCnt] = CNumber::Create(D3DXVECTOR3(((m_Scale.x * 2)* nCnt), m_pos.y, 0.0f), m_Scale,this,true);
		m_pNumber[nCnt]->SetCol(m_col);

	}
	//�X�R�A�̐��l���X�V��������
	SetSmallScore(m_nSmallScore);
	SetTrussSmallScore();

	return S_OK;

}

//--------------------------
//�I��
//----------------------------
void CSmallScore::Uninit()
{
	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		if (m_pNumber[nCnt])
		{
			m_pNumber[nCnt]->Uninit();
			m_pNumber[nCnt] = nullptr;
		}
	}
	Release();
}

//--------------------------
//�X�V
//----------------------------
void CSmallScore::Update()
{
	m_pos.y += 1.0f;
	if (m_bCanAddAlpha)
	{
		AddAlpha();
	}
	else
	{
		m_bCanDefAlpha = true;
	}
	if (m_bCanDefAlpha)
	{
		m_nCounter++;
		if (m_nCounter >= MaxTime)
		{
			DefAlpha();

		}
	}
	if (m_bUninit)
	{
		Uninit();
	}

}

//--------------------------
//�`��
//----------------------------
void CSmallScore::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X

										  //�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	pDevice->GetTransform(D3DTS_VIEW, &m_mtxView);//�r���[�}�g���b�N�X���擾


	//�|���S�����J�����ɑ΂��Đ��ʂɌ�����
	//�t�s������߂�	
	m_mtxWorld._11 = m_mtxView._11;
	m_mtxWorld._12 = m_mtxView._21;
	m_mtxWorld._13 = m_mtxView._31;
	m_mtxWorld._21 = m_mtxView._12;
	m_mtxWorld._22 = m_mtxView._22;
	m_mtxWorld._23 = m_mtxView._32;
	m_mtxWorld._31 = m_mtxView._13;
	m_mtxWorld._32 = m_mtxView._23;
	m_mtxWorld._33 = m_mtxView._33;

	//�ʒu��ݒ�
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	//�ʒu�𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		if (m_pNumber[nCnt] != NULL)
		{
			m_pNumber[nCnt]->Draw();
		}
	}

}
//---------------------------------------------------------------
//�X�R�A�̉��Z
//---------------------------------------------------------------
void CSmallScore::SetColor(D3DXCOLOR col)
{
	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		m_pNumber[nCnt]->SetCol(D3DXCOLOR(col));
	}
}
//---------------------------------------------------------------
//���l���Z
//---------------------------------------------------------------
void CSmallScore::AddAlpha()
{
	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		D3DXCOLOR col = m_pNumber[nCnt]->GetCol();
		
		if (col.a < 1.0f)
		{
			col.a += 0.1f;
		}
		else
		{
			m_bCanAddAlpha = false;
		}
		//�X�V�����F��ݒ�
		m_pNumber[nCnt]->SetCol(col);
	}
}
//---------------------------------------------------------------
//���l���Z
//---------------------------------------------------------------
void CSmallScore::DefAlpha()
{
	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		D3DXCOLOR col = m_pNumber[nCnt]->GetCol();

		col.a -= 0.1f;

		if(col.a < 0.0f)
		{
			m_bUninit = true;
		}
		//�X�V�����F��ݒ�
		m_pNumber[nCnt]->SetCol(col);
	}

}
//---------------------------------------------------------------
//�C���X�^���X��������
//---------------------------------------------------------------
CSmallScore *CSmallScore::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& scale, const D3DXCOLOR& col, const int& nSmallScore)
{
	//�C���X�^���X����
	CSmallScore *pSmallScore = new CSmallScore(OBJTYPE_UI);
	if (pSmallScore != NULL)
	{
		pSmallScore->m_pos = pos;
		pSmallScore->m_col = col;
		pSmallScore->m_Scale = scale;
		pSmallScore->m_nSmallScore = nSmallScore;
		//�����𐔂���
		pSmallScore->SetTrussSmallScore();

		pSmallScore->Init();
	}

	return pSmallScore;
}
//---------------------------------------------------------------
//�X�R�A�̐ݒ�
//---------------------------------------------------------------

void CSmallScore::SetSmallScore(int nSmallScore)
{
	int nPoly[MAXSMALLSCORE];

	for (int nCnt = 0; nCnt < m_nMaxTruss; nCnt++)
	{
		if (m_pNumber[nCnt] != NULL)
		{
			//10�̗ݏ�̌v�Z
			int Number = pow(10.0, (m_nMaxTruss - (nCnt)));
			int Number2 = pow(10.0, (m_nMaxTruss - (nCnt + 1)));
			if (Number2 <= 0)
			{
				Number2 = 1;
			}
			nPoly[nCnt] = m_nSmallScore % Number / Number2;
			m_pNumber[nCnt]->SetNumber(nPoly[nCnt]);
		}
	}
}
//---------------------------------------------------------------
//�X�R�A�̉��Z
//---------------------------------------------------------------
void CSmallScore::AddSmallScore(int nValue)
{
	m_nSmallScore += nValue;
}

//---------------------------------------------------------------
//�X�R�A�̉��Z
//---------------------------------------------------------------
void CSmallScore::SetTrussSmallScore()
{
	int nNumber = m_nSmallScore;
	m_nMaxTruss = 0;
	while (nNumber != 0)
	{
		nNumber = nNumber / 10;
		m_nMaxTruss++;
	}
	if (m_nMaxTruss > MAXSMALLSCORE)
	{
		m_nMaxTruss = MAXSMALLSCORE;
	}
}