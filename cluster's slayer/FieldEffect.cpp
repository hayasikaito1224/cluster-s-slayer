//=============================================================================
// ���ʃG�t�F�N�g���� [FieldEffect.cpp]
// Author : �����G��
//=============================================================================
#include "FieldEffect.h"
#include "manager.h"
#include "renderer.h"
#include "control.h"

#include "straight3d.h"
#include "PresetSetEffect.h"

CFieldEffect::CFieldEffect(int nPriority) : CPlane::CPlane(nPriority)
{

}

CFieldEffect::~CFieldEffect()
{

}

//����������
HRESULT CFieldEffect::Init(D3DXVECTOR3 size,
	D3DXVECTOR3 pos,
	D3DCOLORVALUE FieldColor,
	D3DCOLORVALUE FieldAddColor,
	float Rotate,
	int nTime,
	float MaxSize,
	float AddSize,
	int nSynsetic,
	int nDensity,
	float fDistance,
	D3DCOLORVALUE ParticleColor,
	D3DCOLORVALUE ParticleAddColor,
	int nParticleTex,
	int nParticleLife,
	int nParticleSynthetic,
	float ParticleMove3d,
	float ParticleAddSize,
	float ParticleSize,
	int ParticleTime,
	float ActiveAddSize,
	int FieldTime,
	bool FieldCreate,
	int CreatePreset)
{
	CPlane::Init(0, nParticleTex);
	CScene::SetObjType(OBJTYPE::OBJTYPE_EFFECT);

	nLife = 600;

	EffectTime = START;

	m_pos = pos;
	m_size = sqrtf(size.x * size.x + size.z * size.z);
	SizeY = size.y;
	fRotate = 0;
	fAddRotate = Rotate;
	SetPosField(m_pos, D3DXVECTOR3(m_size, SizeY, {}), fRotate, fRotate);

	m_FieldColor = FieldColor;
	m_FieldAddColor = FieldAddColor;

	m_MaxSize = MaxSize;
	m_AddSize = AddSize;
	m_nTime = nTime;
	m_nSynsetic = nSynsetic;

	m_nDensity = nDensity;
	m_fDistance = fDistance;
	m_ParticleColor = ParticleColor;
	m_ParticleAddColor = ParticleAddColor;
	m_nParticleTex = nParticleTex;
	m_nParticleLife = nParticleLife;
	m_nParticleSynthetic = nParticleSynthetic;
	m_ParticleMove3d = ParticleMove3d;
	m_ParticleAddSize = ParticleAddSize;
	m_ParticleSize = ParticleSize;

	Time = (int)(rand() % ParticleTime) + 1;
	nParticleTime = ParticleTime;
	m_ActiveAddSize = ActiveAddSize;

	m_FieldTime = FieldTime;
	m_FieldCreate = FieldCreate;
	m_CreatePreset = CreatePreset;
	m_FieldTimedelta = FieldTime - 5;
	bUninit = false;
	return S_OK;
}

//�I������
void CFieldEffect::Uninit()
{
	CPlane::Uninit();
}

//�X�V����
void CFieldEffect::Update()
{
	float fAngle;
	float fAngle2;
	int Y = (int)m_fDistance;

	//�J���[�̕ϓ�
	m_FieldColor.r += m_FieldAddColor.r;
	m_FieldColor.g += m_FieldAddColor.g;
	m_FieldColor.b += m_FieldAddColor.b;
	m_FieldColor.a += m_FieldAddColor.a;

	//�J���[��0�ȉ��̎�
	if (m_FieldColor.r < 0)
	{
		m_FieldColor.r = 0;
	}
	if (m_FieldColor.g < 0)
	{
		m_FieldColor.g = 0;
	}
	if (m_FieldColor.b < 0)
	{
		m_FieldColor.b = 0;
	}
	if (m_FieldColor.a < 0)
	{
		m_FieldColor.a = 0;
	}

	//�J���[��255�ȏ�̎�
	if (m_FieldColor.r > 256)
	{
		m_FieldColor.r = 255;
	}
	if (m_FieldColor.g > 256)
	{
		m_FieldColor.g = 255;
	}
	if (m_FieldColor.b > 256)
	{
		m_FieldColor.b = 255;
	}
	if (m_FieldColor.a > 256)
	{
		m_FieldColor.a = 255;
	}

	float moveMin = m_ParticleMove3d * -1 / 1.5f;
	float Life = m_nParticleLife;
	float Size = m_ParticleAddSize / 1.5f;
	float AddR = fAddRotate * 30;
	float Distance = m_fDistance / 1.5f;
	//�t�B�[���h�̓���
	switch (EffectTime)
	{
	case(START)://�W�J��
		m_size += m_AddSize;
		fRotate += AddR;

		if (m_size > m_MaxSize)
		{
			EffectTime = ACTIVE;


			for (int i = 0; i < m_nDensity + 20; i++)
			{
				fAngle = CIRCLE;
				fAngle2 = CIRCLE;

				CStraight3D::Create(
					D3DXVECTOR3(
						m_pos.x + m_fDistance  * sinf(fAngle) * cosf(fAngle2),
						m_pos.y + m_fDistance / 2 * cosf(fAngle),
						m_pos.z + m_fDistance  * sinf(fAngle) * sinf(fAngle2)
					),

					D3DXVECTOR3(m_ParticleSize, m_ParticleSize, 0.0f),
					D3DXVECTOR3(m_ParticleAddSize, m_ParticleAddSize, 0.0f),
					D3DXVECTOR3(moveMin, 0.0f, 0.0f),
					m_ParticleColor,
					m_ParticleAddColor,
					m_nParticleTex,
					m_nParticleLife,
					CStraight3D::TARGET,
					m_pos,
					m_nParticleSynthetic,
					0,
					(CStraight3D::RAND_PATTEN)0,
					(CStraight3D::POS_PATTERN)0,
					D3DXVECTOR2(0.0f, 0.0f),
					1.0f);
			}

		}
		break;
	case(ACTIVE):	//������
		fRotate += fAddRotate;

		Time--;
		m_size += m_ActiveAddSize;
		if (m_size < 0)
		{
			m_size = 0;
		}

		if (Time <= 0)
		{
			for (int i = 0; i < m_nDensity; i++)
			{
				fAngle = CIRCLE;
				fAngle2 = CIRCLE;

				CStraight3D::Create(
					D3DXVECTOR3(
						m_pos.x + m_fDistance * sinf(fAngle) * cosf(fAngle2),
						m_pos.y + m_fDistance / 2 * cosf(fAngle),
						m_pos.z + m_fDistance * sinf(fAngle) * sinf(fAngle2)
					),

					D3DXVECTOR3(m_ParticleSize, m_ParticleSize, 0.0f),
					D3DXVECTOR3(m_ParticleAddSize, m_ParticleAddSize, 0.0f),
					D3DXVECTOR3(m_ParticleMove3d, 0.0f, 0.0f),
					m_ParticleColor,
					m_ParticleAddColor,
					m_nParticleTex,
					m_nParticleLife,
					CStraight3D::TARGET,
					m_pos,
					m_nParticleSynthetic,
					m_fDistance,
					(CStraight3D::RAND_PATTEN)0,
					(CStraight3D::POS_PATTERN)2,
					D3DXVECTOR2(0.0f, 0.0f),
					1.0f);

				Time = (int)(rand() % nParticleTime) + 1;
			}
		}

		if (m_FieldCreate == true)
		{
			m_FieldTimedelta++;
			if (m_FieldTimedelta >= m_FieldTime)
			{
				CPresetEffect::SetEffect3D(m_CreatePreset, m_pos, {}, D3DXVECTOR3(170.0f, 0.0f, 170.0f), false);
				m_FieldTimedelta = 0;
			}
		}

		m_nTime--;
		if (m_nTime < 0)
		{
			EffectTime = END;
		}
		break;
	case(END):	//�I��
		m_size -= m_AddSize;

		if (m_size < 10)
		{
			bUninit = true;

			for (int i = 0; i < m_nDensity + 10; i++)
			{
				fAngle = CIRCLE;
				fAngle2 = CIRCLE;

				CStraight3D::Create(
					D3DXVECTOR3(
						m_pos.x + m_fDistance / 3 * sinf(fAngle) * cosf(fAngle2),
						m_pos.y + m_fDistance / 4 * cosf(fAngle),
						m_pos.z + m_fDistance / 3 * sinf(fAngle) * sinf(fAngle2)
					),
					D3DXVECTOR3(m_ParticleSize, m_ParticleSize, 0.0f),
					D3DXVECTOR3(Size, Size, 0.0f),
					D3DXVECTOR3(moveMin / 2, 0.0f, 0.0f),
					m_ParticleColor,
					m_ParticleAddColor,
					m_nParticleTex,
					Life,
					CStraight3D::TARGET,
					m_pos,
					m_nParticleSynthetic,
					m_fDistance,
					(CStraight3D::RAND_PATTEN)0,
					(CStraight3D::POS_PATTERN)2,
					D3DXVECTOR2(0.0f, 0.0f),
					1.0f);
			}

		}
		break;
	default:

		break;
	}

	nLife--;
	if (nLife < 0)
	{
		bUninit = true;
	}

	ColorChange(m_FieldColor);
	SetPosField(m_pos, D3DXVECTOR3(m_size, SizeY, {}), fRotate, -fRotate);

	if (bUninit == true)
	{
		Uninit();
	}
}

//�`�揈��
void CFieldEffect::Draw()
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();     //�f�o�C�X���擾����

	//Z�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	//�A���t�@�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);


	if (m_nSynsetic == 0)
	{
		//���Z�����֌W
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}
	else if (m_nSynsetic == 1)
	{
		//���Z�����̐ݒ�
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}
	//����ȊO�̐��l�͉��Z������
	else
	{
		//���Z�����֌W
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}
	//���C���e�B���O�𖳎�����
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	//�J�����O�I�t
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	CPlane::Draw();
	//�J�����O�I��
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//Z�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//�A���t�@�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);

	//�ʏ퍇���ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//���C���e�B���O��L���ɂ���
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//�ʒu�ɂ���Ă͉f��Ȃ��悤�ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

}

//�쐬
CFieldEffect *CFieldEffect::Create(D3DXVECTOR3 size,
	D3DXVECTOR3 pos,
	D3DCOLORVALUE FieldColor,
	D3DCOLORVALUE FieldAddColor,
	float Rotate,
	int nTime,
	float MaxSize,
	float AddSize,
	int nSynsetic,
	int nDensity,
	float fDistance,
	D3DCOLORVALUE ParticleColor,
	D3DCOLORVALUE ParticleAddColor,
	int nParticleTex,
	int nParticleLife,
	int nParticleSynthetic,
	float ParticleMove3d,
	float ParticleAddSize,
	float ParticleSize,
	int ParticleTime,
	float ActiveAddSize,
	int FieldTime,
	bool FieldCreate,
	int CreatePreset)
{
	CFieldEffect *pFieldEffect;
	pFieldEffect = new CFieldEffect(OBJTYPE::OBJTYPE_EFFECT);
	if (pFieldEffect != NULL)
	{
		pFieldEffect->Init(size,
			pos,
			FieldColor,
			FieldAddColor,
			Rotate,
			nTime,
			MaxSize,
			AddSize,
			nSynsetic,
			nDensity,
			fDistance,
			ParticleColor,
			ParticleAddColor,
			nParticleTex,
			nParticleLife,
			nParticleSynthetic,
			ParticleMove3d,
			ParticleAddSize,
			ParticleSize,
			ParticleTime,
			ActiveAddSize,
			FieldTime,
			FieldCreate,
			CreatePreset);
	}

	return pFieldEffect;
}
