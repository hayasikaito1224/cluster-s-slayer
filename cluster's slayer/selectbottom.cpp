//--------------------------------------
//�X�L�������\���p�̏���
//--------------------------------------
#include "selectbottom.h"
#include "Polygon.h"
#include "input.h"
#include "keyboard.h"
#include "manager.h"
#include "mouse.h"
#include "frame.h"
#include "skillselect.h"
#include "player.h"
#include "Renderer.h"
#include "letter.h"
#include "skill_leveldata.h"
#include "game.h"
#include "sound.h"

static const float IconSize = 50.0f;//�A�C�R���̑傫��
static const float TextSize = 15.0f;//�A�C�R���̑傫��
static const float TextInterval = 17.0f;//�A�C�R���̑傫��

static const int TextLinefeed = 9;//���s���郉�C��

static const D3DXVECTOR3 IconPos = {10.0f,-100.0f,0.0f};//�A�C�R���̈ʒu
static const float TextPosY = 70.0f;//�A�C�R���̈ʒu
static const float TextPosX = 120.0f;//�A�C�R���̈ʒu

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CSkillSelectBottom::CSkillSelectBottom(OBJTYPE nPriority) :CScene(nPriority)
{
	pSelectBottom = nullptr;
	m_bPopSelectBottom = true;
	m_bIsSelect = false;
	pSkillIcon = nullptr;
	pFrame = nullptr;
	m_Letter.clear();
	m_Text.clear();
	m_bPopText = false;
	m_nLevel = 0;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CSkillSelectBottom::~CSkillSelectBottom()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CSkillSelectBottom::Init(void)
{
	CPlayer *pPlayer = CManager::GetGame()->GetPlayer();
	int nLevel = pPlayer->GetSkillLevel(m_nSkillNo);
	m_nLevel = nLevel + 1;//������Ԃ́[�P�̃��x���Ȃ̂łP�v���X����

	
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CSkillSelectBottom::Uninit(void)
{
	if (pSelectBottom)
	{
		pSelectBottom->Uninit();
		pSelectBottom = nullptr;
	}
	if (pFrame)
	{
		pFrame->Uninit();
		pFrame = nullptr;
	}
	if (pSkillIcon)
	{
		pSkillIcon->Uninit();
		pSkillIcon = nullptr;
	}
	{
		int nSize = m_Letter.size();
		if (nSize != 0)
		{
			for (int nCnt = 0; nCnt < nSize; nCnt++)
			{
				m_Letter[0]->Uninit();
				m_Letter.erase(m_Letter.begin());
			}
		}
	}

	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CSkillSelectBottom::Update(void)
{
	if (m_bPopSelectBottom)
	{
		//�Z���N�g�E�B���h�E�̏o��
		PopSelectBottom();
	}
	else
	{
		SelectBottom();
	}
	if (m_bPopText)
	{
		m_bPopText = false;
		//�X�L�������̕��͂̐���

		int nSize = m_Text[m_nLevel].size();
		int nTextLine = TextLinefeed;
		if (nSize <= TextLinefeed)
		{
			nTextLine = nSize;
		}
		for (m_nCntLetter = 0; m_nCntLetter < nSize; m_nCntLetter++)
		{
			float fPosX = ((m_size.x * 2) / nTextLine) * m_nCntChar;
			float fSize = ((m_size.x) / nTextLine);

			m_Letter.push_back(CLetter::Create({ (m_pos.x - (m_size.x) + (fSize)) + fPosX,m_pos.y + TextPosY + ((fSize * 2)*m_nCntLine), 0.0f },
			{ fSize, fSize, 0.0f }, m_Text[m_nLevel][m_nCntLetter], 260, 500));

			if (m_Text[m_nLevel].size() - 1 <= m_nCntLetter)
			{
				m_bEndStatement = true;
			}

			else
			{
				m_nCntChar++;
			}
			//���̕����ɒB����Ɖ��s
			if (m_nCntChar >= nTextLine)
			{
				m_nCntChar = 0;
				m_nCntLine++;
			}
		}

	}
	//�I�����肪�I���Ȃ�
	if (m_bEnd)
	{
		//�I���������Ă�
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CSkillSelectBottom::Draw()
{

}
//-----------------------------------------------
//�C���X�^���X����
//---------------------------------------------
CSkillSelectBottom *CSkillSelectBottom::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const int& tex,
	const int& SkillType)
{
	CSkillSelectBottom *pSkillSelect = new CSkillSelectBottom(OBJTYPE_UI);
	char sFileName[64];
	if (pSkillSelect)
	{
		pSkillSelect->m_pos = pos;
		pSkillSelect->m_size = size;

		if (!pSkillSelect->pSelectBottom)
		{
			//�X�L���I����ʉ摜�̐���
			pSkillSelect->pSelectBottom = CPolygon::Create(pos, size, (CTexture::Type)tex, { 1.0,1.0,1.0,0.0f });
		}
		int nTex = 0;
		pSkillSelect->m_nSkillNo = SkillType;

		switch (SkillType)
		{
		case CPlayer::ATKup:
			nTex = CTexture::ATKup;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/ATKUp.txt");
			break;
		case CPlayer::Heal:
			nTex = CTexture::Heal;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/Heal.txt");

			break;
		case CPlayer::OverHeal:
			nTex = CTexture::OverHeal;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/OverHeal.txt");

			break;
		case CPlayer::Sheild:
			nTex = CTexture::Sheild;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/Sheild.txt");

			break;
		case CPlayer::Beam:
			nTex = CTexture::Beam;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/Beam.txt");

			break;
		case CPlayer::BlackHole:
			nTex = CTexture::BlackHole;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/BlackHole.txt");
			break;
		case CPlayer::Rocket:
			nTex = CTexture::Rocket;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/Rocket.txt");

			break;
		case CPlayer::RushAttack:
			nTex = CTexture::RushAttack;
			wsprintf(&sFileName[0], "data/TEXT/SKILLCOMMENT/RushAttack.txt");

			break;
		}
		if (!pSkillSelect->pSkillIcon)
		{
			//�X�L���I����ʉ摜�̐���
			pSkillSelect->pSkillIcon = CPolygon::Create({ pos.x + IconPos.x,pos.y + IconPos.y,0.0f }, { IconSize ,IconSize ,0.0f}, (CTexture::Type)nTex, { 1.0,1.0,1.0,0.0f });
		}
		//�e�L�X�g�̓ǂݍ���
		pSkillSelect->TextLoad(sFileName);
		pSkillSelect->Init();
	}

	return pSkillSelect;
}
//-----------------------------------------------
//�Z���N�g�E�B���h�E�̏o��
//---------------------------------------------
void CSkillSelectBottom::PopSelectBottom()
{

	if (pSelectBottom)
	{
		D3DXCOLOR col = pSelectBottom->GetColor();
		D3DXVECTOR3 pos = pSelectBottom->GetPos();
		//��������s�����ɂȂ鏈��
		if (col.a <= 1.0f)
		{
			col.a += 0.05f;
			pSelectBottom->SetCol(col);
		}
		//�w��̈ʒu�Ɉړ������鏈��
		if (pos.y <= SCREEN_HEIGHT / 2.0f)
		{
			pos.y += 2.0f;
			pSelectBottom->SetPos(pos);
		}
		else
		{
			m_bPopSelectBottom = false;
			m_bPopText = true;
		}
	}
	if (pSkillIcon)
	{
		D3DXCOLOR col = pSkillIcon->GetColor();
		D3DXVECTOR3 pos = pSkillIcon->GetPos();
		//��������s�����ɂȂ鏈��
		if (col.a <= 1.0f)
		{
			col.a += 0.05f;
			pSkillIcon->SetCol(col);
		}
		//�w��̈ʒu�Ɉړ������鏈��
		pos.y += 2.0f;
		pSkillIcon->SetPos(pos);
	}
}
//-----------------------------------------------
//�X�L���I���{�^���̑I������
//---------------------------------------------
void CSkillSelectBottom::SelectBottom()
{
	//�}�E�X���̎擾
	CMouse *pMouse = CManager::GetMouse();

	POINT po;
	//�}�E�X�̃X�N���[�����W�̈ʒu�̎擾
	GetCursorPos(&po);
	D3DXVECTOR3 pos = pSelectBottom->GetPos();
	D3DXVECTOR3 scale = pSelectBottom->GetScale();
	HWND hWnd = GetForegroundWindow();

	//�X�N���[�����W����N���C�A���g���W�̕ϊ�
	ScreenToClient(hWnd, &po);

	float MousePos_X = (float)po.x;
	float MousePos_Y = (float)po.y;
	//�z�u���Ă���|���S���͈̔͂ɃJ�[�\������������
	if (MousePos_X > pos.x- scale.x&&
		MousePos_X < pos.x + scale.x&&
		MousePos_Y > pos.y - scale.y&&
		MousePos_Y < pos.y + scale.y)
	{
		//�I����Ԃɂ���
		m_bIsSelect = true;
		//�I�����ꂽ�|���S���ɘg��\��
		if (!pFrame)
		{
			pFrame = CFrame::Create(pos, scale, { 1.0,1.0,0.0,1.0 });

			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_POINTOUT);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_POINTOUT, 1.0f);
		}
		//�I�����Ă����Ԃō��N���b�N������ƌ����Ԃɂ���
		if (pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
		{
			m_bIsDecision = true;
		}
	}
	else
	{
		//�I����Ԃ�����
		m_bIsSelect = false;
		if (pFrame)
		{
			pFrame->Uninit();
			pFrame = nullptr;
		}
	}
}
//-----------------------------------------------
//�F�̐ݒ�
//---------------------------------------------
void CSkillSelectBottom::SetCol(D3DXCOLOR col)
{
	if (pSelectBottom)
	{
		pSelectBottom->SetCol(col);
	}
}

void CSkillSelectBottom::TextLoad(const char * sFileName)
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X���擾����
	FILE *pFile;
	char aFile[64];

	pFile = fopen(sFileName, "r");

	if (pFile != NULL)
	{
		while (true)
		{
			fscanf(pFile, "%s", &aFile[0]);
			if (strcmp(&aFile[0], "SET_TEXT") == 0) // SET_TEXT�̕��������������
			{
				while (true)
				{
					fscanf(pFile, "%s", &aFile[0]);
					if (strcmp(&aFile[0], "TEXT") == 0) // TEXT�̕��������������
					{
						char aTextBuf[1][200];
						string textbuf;
						fscanf(pFile, "%s%s", &aFile[0], aTextBuf[0]);
						textbuf = aTextBuf[0];

						// SJIS �� wstring
						int iBufferSize = MultiByteToWideChar(CP_ACP,
							0,
							textbuf.c_str(),
							-1,
							(wchar_t*)NULL,
							0);

						// �o�b�t�@�̎擾
						wchar_t* cpUCS2 = new wchar_t[iBufferSize];

						// SJIS �� wstring
						MultiByteToWideChar(CP_ACP,
							0,
							textbuf.c_str(),
							-1,
							cpUCS2,
							iBufferSize);

						// string�̐���
						std::wstring utextbuf(cpUCS2, cpUCS2 + iBufferSize - 1);

						// �o�b�t�@�̔j��
						delete[] cpUCS2;

						m_Text.push_back(utextbuf);
					}
					if (strcmp(&aFile[0], "END_SETTEXT") == 0) // EMD_SETTEXT�̕��������������
					{
						break;
					}
				}
			}
			else if (strcmp(&aFile[0], "END") == 0) //END�̕��������������
			{
				break;
			}
		}
	}
	else
	{
		printf("�e�N�X�`���f�[�^���ǂݎ��܂���ł����B");
	}

	if (pFile != NULL)
	{
		fclose(pFile);
	}


}

