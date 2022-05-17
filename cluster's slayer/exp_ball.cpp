//--------------------------------------
//�o���l�ʂ̏���
//--------------------------------------
#include "exp_ball.h"
#include "billboard.h"
#include "gauge.h"
#include "manager.h"
#include "game.h"
#include "gaugeber.h"
static const float BallSize = 7.0f;//�o���l�ʂ̑傫��
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CExp_Ball::CExp_Ball(OBJTYPE nPriority):CItem(nPriority)
{
	pItemObj = nullptr;
	m_fRadius = BallSize;
	m_nExp = 0;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CExp_Ball::~CExp_Ball()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CExp_Ball::Init(void)
{
	//�o���l�ʗp�̃r���{�[�h�𐶐�
	if (!pItemObj)
	{
		pItemObj = CBillboard::Create(m_pos, { m_fRadius ,m_fRadius ,0.0f }, CTexture::GlitterEffect);
	}
	CItem::Init();
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CExp_Ball::Uninit(void)
{

	CItem::Uninit();
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CExp_Ball::Update(void)
{
	CItem::Update();
	if (m_IsDeath)
	{
		CGauge *pGauge = CManager::GetGame()->GetExpGauge();
		if (pGauge)
		{
			pGauge->SetGauge(-m_nExp, 0);
		}
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CExp_Ball::Draw()
{
	CItem::Draw();
}
//--------------------------------------------
//�C���X�^���X����
//--------------------------------------------
CExp_Ball * CExp_Ball::Create(const D3DXVECTOR3 & pos, const int& nExp)
{
	//�C���X�^���X����
	CExp_Ball *pExp_Ball = new CExp_Ball(OBJTYPE_ITEM);
	pExp_Ball->m_pos = { pos.x,pos.y+ (pExp_Ball->m_fRadius*2.0f),pos.z};
	pExp_Ball->m_nExp = nExp;
	if (pExp_Ball)
	{
		pExp_Ball->Init();
	}
	return pExp_Ball;
}


