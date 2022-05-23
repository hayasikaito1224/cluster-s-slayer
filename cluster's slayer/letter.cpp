//=============================================================================
//
// 2D�|���S������ [scene2D.cpp]
// Author : �H������
//
//=============================================================================
//=============================================================================
// �C���N���[�h
//=============================================================================
#include "letter.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "scene2D.h"
//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CLetter::CLetter(OBJTYPE nPriority) : CScene(nPriority)
{

}

//=============================================================================
// �f�t�H���g�f�X�g���N�^
//=============================================================================
CLetter::~CLetter()
{

}

//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT CLetter::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;	// �f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	// �f�o�C�X���擾����

	// �t�H���g�̐���
	LOGFONT lf = { m_nFontSize, 0, 0, 0, m_nFontWeight, 0, 0, 0, SHIFTJIS_CHARSET,
		OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_MODERN, _T("IPAex�S�V�b�N") };
	HFONT hFont = CreateFontIndirect(&lf);

	// �f�o�C�X�Ƀt�H���g���������Ȃ���GetGlyphOutline�֐��̓G���[�ƂȂ�
	HDC hdc = GetDC(NULL);
	HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

	// �t�H���g�r�b�g�}�b�v�擾
	UINT code = (UINT)m_Text[0];
	const int gradFlag = GGO_GRAY4_BITMAP;
	int grad = 0; // �K���̍ő�l
	switch (gradFlag) 
	{
	case GGO_GRAY2_BITMAP: 
		grad = 4;
		break;
	case GGO_GRAY4_BITMAP:
		grad = 16;
		break;
	case GGO_GRAY8_BITMAP:
		grad = 64;
		break;
	}

	TEXTMETRIC tm;
	GetTextMetrics(hdc, &tm);
	GLYPHMETRICS gm;
	CONST MAT2 mat = { { 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } };
	DWORD size = GetGlyphOutlineW(hdc, code, gradFlag, &gm, 0, NULL, &mat);
	BYTE *pMono = new BYTE[size];
	GetGlyphOutlineW(hdc, code, gradFlag, &gm, size, pMono, &mat);

	// �f�o�C�X�R���e�L�X�g�ƃt�H���g�n���h���͂�������Ȃ��̂ŉ��
	SelectObject(hdc, oldFont);
	ReleaseDC(NULL, hdc);

	// �e�N�X�`���쐬
	int fontWidth = (gm.gmBlackBoxX + 3) / 4 * 4;
	int fontHeight = gm.gmBlackBoxY;

	pDevice->CreateTexture( fontWidth,
							fontHeight,
							1,
							0,
							D3DFMT_A8R8G8B8,
							D3DPOOL_MANAGED, 
							&m_pTexture,
							NULL);

	// �e�N�X�`���Ƀt�H���g�r�b�g�}�b�v������������
	D3DLOCKED_RECT lockedRect;
	m_pTexture->LockRect(0, &lockedRect, NULL, 0);  // ���b�N
	DWORD *pTexBuf = (DWORD*)lockedRect.pBits;   // �e�N�X�`���������ւ̃|�C���^

	for (int y = 0; y < fontHeight; y++) 
	{
		for (int x = 0; x < fontWidth; x++) 
		{
			DWORD alpha = pMono[y * fontWidth + x] * 255 / grad;
			pTexBuf[y * fontWidth + x] = (alpha << 24) | 0x00ffffff;
		}
	}

	m_pTexture->UnlockRect(0);  // �A�����b�N
	delete[] pMono;

	VERTEX_2D *pVtx;	// ���_���

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * VERTEX_NUM,
								D3DUSAGE_WRITEONLY,
								FVF_CUSTOM,
								D3DPOOL_MANAGED,
								&m_pVtxBuff,
								NULL);

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_����ݒ�
	pVtx[0].pos = D3DXVECTOR3(m_Pos.x - m_Size.x, m_Pos.y - m_Size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_Pos.x + m_Size.x, m_Pos.y - m_Size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_Pos.x - m_Size.x, m_Pos.y + m_Size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_Pos.x + m_Size.x, m_Pos.y + m_Size.y, 0.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=============================================================================
// �|���S���̏I������
//=============================================================================
void CLetter::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
	Release();	// �����̔j��
}

//=============================================================================
// �|���S���̍X�V����
//=============================================================================
void CLetter::Update(void)
{

}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CLetter::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice;	// �f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	// �f�o�C�X���擾����

	// �`��
	pDevice->SetStreamSource(	0,
								m_pVtxBuff,
								0,
								sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_CUSTOM);

	pDevice->SetTexture(0, m_pTexture);

	pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,
							0,
							2);
}

//=============================================================================
// �t�H���g�̃��[�h
//=============================================================================
void CLetter::Load(void)
{
	AddFontResourceEx("data/FONT/ipaexg.ttf", FR_PRIVATE, NULL);	// ���菑���N������
}

CLetter * CLetter::Create(const D3DXVECTOR3 & pos, const D3DXVECTOR3 & size, const wchar_t & text, const int & nFontSize, const int & nWeight)
{
	CLetter *pLetter = new CLetter(OBJTYPE_TEXT);
	if (pLetter)
	{
		pLetter->m_Pos = pos;
		pLetter->m_Size = size;
		pLetter->m_Text = text;
		pLetter->m_nFontSize = nFontSize;
		pLetter->m_nFontWeight = nWeight;
		pLetter->Init();
	}
	return pLetter;
}
