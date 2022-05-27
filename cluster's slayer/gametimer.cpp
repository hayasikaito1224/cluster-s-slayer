//-------------------
//�w�i�̏���
//---------------------------------------------------
#include "gametimer.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"
#include "2Dnumber.h"
#include <math.h>
#include "Score.h"
#include "Polygon.h"
static const int MaxTime = 20;
static const D3DXVECTOR3 Scale = {20.0f,30.0f,0.0};
//--------------------------
//�R���X�g���N�g
//----------------------------
CGametimer::CGametimer(OBJTYPE nPriority) :CScene(nPriority)
{
	m_nCommaCnt = 0;
	m_nSecondCnt = 0;
	m_nMinuteCnt = 0;
	m_bCanCount = true;
	memset(m_pSecond, NULL, sizeof(m_pSecond));
	memset(m_pMinute, NULL, sizeof(m_pMinute));
	memset(pPolygon, NULL, sizeof(pPolygon));

}

//--------------------------
//�f�X�g���N�g
//----------------------------
CGametimer::~CGametimer()
{

}

//--------------------------
//������
//----------------------------
HRESULT CGametimer::Init()
{
	//�b�𐶐�
	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		//�i���o�[�̌���������
		m_pSecond[nCnt] = C2DNumber::Create(D3DXVECTOR3(((Scale.x * 2)* nCnt)+ m_pos.x, m_pos.y, 0.0f), Scale);
		m_pSecond[nCnt]->SetCol(m_col);

	}
	for (int nCnt = 0; nCnt < MINUTENUMBERS_MAX; nCnt++)
	{
		//�i���o�[�̌���������
		m_pMinute[nCnt] = C2DNumber::Create(D3DXVECTOR3((((Scale.x * 2)* nCnt) + m_pos.x) - (Scale.x*5), m_pos.y, 0.0f), Scale);
		m_pMinute[nCnt]->SetCol(m_col);

	}
	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		//�i���o�[�̌���������
		pPolygon[nCnt] = CPolygon::Create({ m_pos.x - (Scale.x + 8.0f), m_pos.y + (-10.0f + (20.0f*nCnt)), 0.0f }, { 5.0f,5.0f,0.0f }, CTexture::None);
		pPolygon[nCnt]->SetCol({0.0f,0.0f,0.0f,1.0});

	}
	//�X�R�A�̐��l���X�V��������
	TimeNumbers();

	return S_OK;

}

//--------------------------
//�I��
//----------------------------
void CGametimer::Uninit()
{
	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		if (m_pSecond[nCnt])
		{
			m_pSecond[nCnt]->Uninit();
			m_pSecond[nCnt] = nullptr;
		}
		if (m_pMinute[nCnt])
		{
			m_pMinute[nCnt]->Uninit();
			m_pMinute[nCnt] = nullptr;
		}
	}
	Release();
}

//--------------------------
//�X�V
//----------------------------
void CGametimer::Update()
{
	if (m_bCanCount)
	{
		TimeCount();
	}
	TimeNumbers();
	if (m_bUninit)
	{
		Uninit();
	}

}

//--------------------------
//�`��
//----------------------------
void CGametimer::Draw()
{

	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		if (m_pSecond[nCnt] != NULL)
		{
			m_pSecond[nCnt]->Draw();
		}
		if (m_pMinute[nCnt] != NULL)
		{
			m_pMinute[nCnt]->Draw();
		}

	}

}
void CGametimer::TimeNumbers()
{
	int nSecondPoly[SECONDNUMBERS_MAX];
	int nMinutePoly[MINUTENUMBERS_MAX];

	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		if (m_pSecond[nCnt] != NULL)
		{
			//10�̗ݏ�̌v�Z
			int Number = pow(10.0, (SECONDNUMBERS_MAX - (nCnt)));
			int Number2 = pow(10.0, (SECONDNUMBERS_MAX - (nCnt + 1)));
			if (Number2 <= 0)
			{
				Number2 = 1;
			}
			nSecondPoly[nCnt] = m_nSecondCnt % Number / Number2;
			m_pSecond[nCnt]->SetNumber(nSecondPoly[nCnt]);
		}
		if (m_pMinute[nCnt] != NULL)
		{
			//10�̗ݏ�̌v�Z
			int Number = pow(10.0, (MINUTENUMBERS_MAX - (nCnt)));
			int Number2 = pow(10.0, (MINUTENUMBERS_MAX - (nCnt + 1)));
			if (Number2 <= 0)
			{
				Number2 = 1;
			}
			nMinutePoly[nCnt] = m_nMinuteCnt % Number / Number2;
			m_pMinute[nCnt]->SetNumber(nMinutePoly[nCnt]);
		}
	}

}
void CGametimer::TimeCount()
{
	m_nCommaCnt++;
	if (m_nCommaCnt >= 60)
	{
		m_nCommaCnt = 0;
		m_nSecondCnt++;
	}
	if (m_nSecondCnt >= 60)
	{
		m_nSecondCnt = 0;
		m_nMinuteCnt++;
	}
}
void CGametimer::AddMinute(int nMinute)
{
	m_nSecondCnt += nMinute;
	if (m_nSecondCnt >= 60)
	{
		m_nSecondCnt = 0;
		m_nMinuteCnt++;
	}
}
//---------------------------------------------------------------
//�C���X�^���X��������
//---------------------------------------------------------------
CGametimer *CGametimer::Create(const D3DXVECTOR3 pos, const D3DXCOLOR col, const bool& CanCount)
{
	//�C���X�^���X����
	CGametimer *pSmallScore = new CGametimer(OBJTYPE_TIME);
	if (pSmallScore != NULL)
	{
		pSmallScore->m_pos = pos;
		pSmallScore->m_col = col;
		pSmallScore->m_bCanCount = CanCount;
		pSmallScore->Init();
	}

	return pSmallScore;
}
