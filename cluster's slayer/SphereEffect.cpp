//=============================================================================
// ����G�t�F�N�g���� [SphereEffect.cpp]
// Author : �����G��
//=============================================================================
#include "SphereEffect.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSphereEffect::CSphereEffect(OBJTYPE nPriority) : CSphere::CSphere(nPriority)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSphereEffect::~CSphereEffect(void)
{

}

//=============================================================================
// ������
//=============================================================================
HRESULT CSphereEffect::Init(
	D3DXVECTOR3 pos,
	float rot,
	float fSize,
	int nTex,
	D3DCOLORVALUE Color, D3DCOLORVALUE AddColor,
	int nLife, int nSynthetic,
	float fAddSize, int Vtx,
	SPHERE_TYPE SphereType,
	D3DXVECTOR2 TexMove,
	float TexNum,
	int nAnimCounter,
	D3DXVECTOR2 nSplit)
{
	if (SphereType == SPHERE)
	{
		CSphere::Init(pos, rot, fSize, Vtx * 2, Vtx, (CTexture::Type)nTex, nSynthetic, TexNum);
	}
	else if (SphereType == HALF_SPHERE)
	{
		CSphere::Init(pos, rot, fSize, Vtx * 4, Vtx, (CTexture::Type)nTex, nSynthetic, TexNum);
	}
	else
	{
		CSphere::Init(pos, rot, fSize, Vtx * 2, Vtx, (CTexture::Type)nTex, nSynthetic, TexNum);
	}
	m_Color = Color;
	m_AddColor = AddColor;

	m_TexMove = TexMove;

	m_fSize = fSize;
	m_fAddSize = fAddSize;
	m_nLife = nLife;
	m_MaxSplit = nSplit;
	m_PatternSize = D3DXVECTOR2(1.0f / m_MaxSplit.x, 1.0f / m_MaxSplit.y);
	m_nAnimCount = nAnimCounter;
	m_nSetAnimCnt = nAnimCounter;

	SetPos(pos, {});

	return S_OK;
}

//=============================================================================
// �I��
//=============================================================================
void CSphereEffect::Uninit()
{
	CSphere::Uninit();
}

//=============================================================================
// �X�V
//=============================================================================
void CSphereEffect::Update()
{
	D3DXVECTOR3 pos = GetPos();

	m_fSize += m_fAddSize;
	if (m_fSize < 0)
	{
		m_bUninit = true;
	}

	//�J���[�ύX
	m_Color.r += m_AddColor.r;
	m_Color.g += m_AddColor.g;
	m_Color.b += m_AddColor.b;
	m_Color.a += m_AddColor.a;

	//�J���[��0�ȉ��̎�
	if (m_Color.r < 0)
	{
		m_Color.r = 0;
	}
	if (m_Color.g < 0)
	{
		m_Color.g = 0;
	}
	if (m_Color.b < 0)
	{
		m_Color.b = 0;
	}
	if (m_Color.a < 0)
	{
		m_Color.a = 0;
	}

	//�J���[��255�ȏ�̎�
	if (m_Color.r > 255)
	{
		m_Color.r = 255;
	}
	if (m_Color.g > 255)
	{
		m_Color.g = 255;
	}
	if (m_Color.b > 255)
	{
		m_Color.b = 255;
	}
	if (m_Color.a > 255)
	{
		m_Color.a = 255;
	}

	//�K��
	SetSize(pos,m_fSize);
	SetColor(m_Color);
	SetTexUV(m_TexMove);
	CSphere::Update();
}

//=============================================================================
// �`��
//=============================================================================
void CSphereEffect::Draw()
{
	CSphere::Draw();
}

//=============================================================================
// �쐬
//=============================================================================
CSphereEffect *CSphereEffect::Create(
	D3DXVECTOR3 pos,
	float rot,
	float fSize,
	int nTex,
	D3DCOLORVALUE Color, D3DCOLORVALUE AddColor,
	int nLife, int nSynthetic,
	float fAddSize, int Vtx,
	SPHERE_TYPE SphereType,
	D3DXVECTOR2 TexMove,
	float TexNum,
	int nAnimCounter,
	D3DXVECTOR2 nSplit)
{
	CSphereEffect *pSphereEffect = new CSphereEffect(OBJTYPE::OBJTYPE_EFFECT);

	if (pSphereEffect != NULL)
	{
		pSphereEffect->Init(pos, rot, fSize,
			nTex, Color, AddColor,
			nLife, nSynthetic,
			fAddSize, Vtx,
			SphereType,
			TexMove, TexNum,
			nAnimCounter,
			nSplit);
	}

	return pSphereEffect;

}

