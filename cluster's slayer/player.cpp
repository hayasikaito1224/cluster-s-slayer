//=============================================
//�v���C���[�̃N���X
//=============================================
#include "player.h"
#include "keyboard.h"
#include "manager.h"
#include "camera.h"
#include "Renderer.h"
#include "sound.h"
#include "directinput.h"
#include "XInput.h"
#include "mouse.h"
#include "Enemy.h"
#include "layer_structure.h"
#include "motion.h"
#include "sword.h"
#include "model.h"
#include "game.h"
#include "gauge.h"
#include "gaugeber.h"
#include "rushattack.h"
#include "blackhole.h"
#define PLAYER_MOVE_SPEED (6.0f)//�ړ���
#define PLAYER_ROCK_LENGTH (500.0f)//���b�N�I���\�͈�
#define PLAYER_ATTACK_SPEED (15.0f)		//�U���̈ړ����x
static const float MouseCameraLimit_X = 600.0f;//�}�E�X�̈ʒu���J�����̉�]���x�Ɏg�p���邽�߂̐����l
static const float MouseCameraLimit_Y = 200.0f;//�}�E�X�̈ʒu���J�����̉�]���x�Ɏg�p���邽�߂̐����l
static const float PlayerMoveSpeed = 10.0f;//�v���C���[�̈ړ��X�s�[�h
static const float CameraLimit = 10.0f;//�����̐����l
static const float PlayerFacingUp = -100.0f;//�v���C���[�̑O�ɒ����_�ɂȂ�悤�ɂ���l
static const float RevertTime = 100.0f;
static const float AttackMoveSpeed = 0.0f;
static const float AttackMoveTime = 20.0f;
static const float AttackWaitTime = 35.0f;
static const float ComboWaitTime = 10.0f;
static const float PlayerPower = 5.0f;
static const float MaxHP = 1000.0f;
static const float MaxExp = 2.0f;
static const int RushStartTime = 30;
static const int BlackHoleShotTime= 200;

static bool s_bCursor = true;

CPlayer::CPlayer(OBJTYPE nPriority) :CCharacter(nPriority)
{
	m_nMovePush = false;
	m_bNearEnemy = false;
	m_IsCharacterDraw = true;
	m_bMoveStop = false;
	m_motionType = N_NEUTRAL;
	m_motionLastType = N_NEUTRAL;
	m_bCanAttack = true;
	m_pSword = nullptr;
	m_fMoveSpeed = PlayerMoveSpeed;
	m_fPower = PlayerPower;
	m_fPowerDiameter = 1.0f;
	m_fAutoHeel = 0.0f;
	m_nLevel = 1;
	m_fMaxExpDiameter = 1.0f;
	m_fMaxExp = MaxExp;
	m_bCanAutoHeel = false;
	m_nTimer = 0;
	m_bCanRushAttack = false;
	m_nRushStartCnt = 0;
	m_nBlackHoleCnt = BlackHoleShotTime;
	m_bCanBlackHole = false;
}

CPlayer::~CPlayer()
{
}
//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------
CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = NULL;
	pPlayer = new CPlayer(OBJTYPE_PLAYER);
	pPlayer->Init();
	return pPlayer;
}
//-----------------------------------------------
//������
//---------------------------------------------
HRESULT CPlayer::Init()
{
	//�̗͂̐ݒ�
	m_fHitPoint = MaxHP;

	//�K�w�\���̐ݒ�
	m_pLayer = new CLayer_Structure;
	m_pLayer->SetLayer_Structure("data/TEXT/PlayerParts000.txt", m_pParts, CModel::TYPE_PLAYER);
	m_fRadius = m_pParts[0]->GetMaxPos().x *3.0f;
	//���[�V�����̐ݒ�
	CMotion *Securement = {};
	m_pMotion = new CMotion;
	m_pMotion->MotionLoad("data/TEXT/PlayerMotion.txt");
	//����̐���
	WeaponSet("data/TEXT/PlayerParts000.txt");

	return S_OK;
}
//-----------------------------------------------
//�I��
//---------------------------------------------
void CPlayer::Uninit()
{
	CCharacter::Uninit();

}

//-----------------------------------------------
//�X�V
//---------------------------------------------
void CPlayer::Update()
{
	CInputKeyBoard *Key = CManager::GetInputKeyboard();


	if (Key->GetTrigger(DIK_F1) == true)
	{
		s_bCursor = s_bCursor ? false : true;
	}
	if (s_bCursor)
	{
		//��ʂ̒��S�Ƀ}�E�X��ݒu
		RECT rec;
		HWND hDeskWnd = GetForegroundWindow();
		GetWindowRect(hDeskWnd, &rec); //�f�X�N�g�b�v�̃n���h�����炻��(��ʂ�)�傫�����擾

		SetCursorPos(rec.right/2, rec.bottom/2);
		//�}�E�X�̃J��������
		MouseCameraCtrl();

	}
	//���̏����̍X�V
	m_pSword->Update();

	//�G���߂��ɂ��邩���Z�o
	m_bNearEnemy = IsNearEnemyState();
	EachSkillManager();
	//�G�Ƃ̓����蔻��
	CScene *pScene_Enemy = CScene::GetScene(OBJTYPE_ENEMY);
	while (pScene_Enemy != NULL)
	{
		if (pScene_Enemy != NULL)
		{
			CEnemy *pEnemy = (CEnemy*)pScene_Enemy;
			D3DXVECTOR3 EnemyPos = pEnemy->GetPos();
			int nSize = pEnemy->GetParts().size();
			if (nSize != 0)
			{
				if (pEnemy->GetRushAttack())
				{
					//�ǌ�����
					CRushAttack::Create(EnemyPos, pEnemy->GetRot(), pEnemy);
					//�ǌ����Ȃ��悤�ɂ���
					pEnemy->SetRushAttack(false);
				}
				//�����蔻��
				float fRadius = pEnemy->GetParts(0)->GetMaxPos().x;
				if (IsCollision(&m_pos, EnemyPos, fRadius, m_fMoveSpeed))
				{
					break;
				}
				else
				{
					m_fMoveSpeed = PlayerMoveSpeed;
				}
			}

		}
		pScene_Enemy = pScene_Enemy->GetSceneNext(pScene_Enemy);
	}

	//�L�[�{�[�h�̈ړ�
	if (!m_bMoveStop)
	{
		KeyboardMove();
	}

	//�U������
	AttackCtrl();

	//�v���C���[�̏�Ԃŏ�����ς���
	switch (m_StateType)
	{
	case ATTACK:
		Attack();
		//�U�����[�V�����̍Đ����I�������
		if (m_pMotion->IsMotionEnd()&&!m_bAttackWait)
		{
			//�ړ��\�ɂ���
			m_bMoveStop = false;
			//�R���{�����O�ɂ���
			m_nComboType = COMBOWAIT;
			//���[�V������ҋ@��Ԃɖ߂�
			m_motionType = N_NEUTRAL;

			if (m_pSword)
			{
				//����̓����蔻����I�t�ɂ���
				m_pSword->SetCanHit(false);
			}
		}

		break;
	}

	{
		int nSize = m_pParts.size();
		//���[�V�����̍Đ�
		m_pMotion->MotionTest(nSize, &m_pParts[0], &m_motionType, &m_motionLastType);

	}
}
//-----------------------------------------------
//�`��
//---------------------------------------------
void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^

	D3DXMATRIX mtxRotModel, mtxTransModel;//�v�Z�p�}�g���b�N�X

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//������ݒ�
	D3DXMatrixRotationYawPitchRoll(&mtxRotModel, m_rot.y, m_rot.x, m_rot.z);
	//�����𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRotModel);

	//�ʒu��ݒ�
	D3DXMatrixTranslation(&mtxTransModel, m_pos.x, m_pos.y, m_pos.z);
	//�ʒu�𔽉f
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTransModel);

	//�e�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���f������
	if (m_IsCharacterDraw)
	{
		int nSize = m_pLayer->GetMaxParts();
		for (int nCntParts = 0; nCntParts < nSize; nCntParts++)
		{
			m_pParts[nCntParts]->Draw();
		}
	}

	//����̕`��
	if (m_pSword)
	{
		m_pSword->Draw();
	}

	//�O��̈ʒu���̕ۑ�
	m_lastpos = m_pos;

	//�v���C���[�̈ʒu�ɃJ������Ǐ]������
	FollowingPlayerCamera();
	Drawtext();
}
//-----------------------------------------------
//�ړ��̏���(�L�[�{�[�h)
//---------------------------------------------
void CPlayer::KeyboardMove()
{
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	//�ړ��{�^���𗣂�����ҋ@���[�V�����ɖ߂�
	if (!IsMoveKeyCheck())
	{
		//�ҋ@���[�V�����ɂ���
		StateChange(IDLE);
		m_nMovePush = false;
		m_motionType = N_NEUTRAL;

	}
	else
	{
		//�ړ���Ԃɂ���
		StateChange(MOVE);
		m_nMovePush = true;
		m_motionType = N_MOVE;
		m_bCanAttack = true;


	}
	//�O�ɐi��
	if (Key->GetPress(DIK_A) == true)
	{
		//������ς���
		m_rot.y = pCamera->GetRot().x + (D3DX_PI / 2);
		//�E�ɐi��
		if (Key->GetPress(DIK_S) == true)
		{
			m_rot.y = pCamera->GetRot().x + (D3DX_PI / 4);
		}
		//���ɐi��
		else if (Key->GetPress(DIK_W) == true)
		{
			m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 3) / 4);
		}
	}

	//���ɐi��
	if (Key->GetPress(DIK_D) == true)
	{
		//������ς���
		m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 3) / 2);
		//�E�ɐi��
		if (Key->GetPress(DIK_S) == true)
		{
			m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 7) / 4);
		}
		//���ɐi��
		else if (Key->GetPress(DIK_W) == true)
		{
			m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 5) / 4);
		}
	}

	//�E�ɐi��
	if (Key->GetPress(DIK_S) == true)
	{
		//������ς���
		m_rot.y = pCamera->GetRot().x + 0.0f;
		//�O�ɐi��
		if (Key->GetPress(DIK_A) == true)
		{
			m_rot.y = pCamera->GetRot().x + (D3DX_PI / 4);
		}
		//���ɐi��
		else if (Key->GetPress(DIK_D) == true)
		{
			m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 7) / 4);
		}
	}
	//���ɐi��
	if (Key->GetPress(DIK_W) == true)
	{
		//������ς���
		m_rot.y = pCamera->GetRot().x + D3DX_PI;
		//�O�ɐi��
		if (Key->GetPress(DIK_A) == true)
		{
			m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 3) / 4);
		}
		//���ɐi��
		else if (Key->GetPress(DIK_D) == true)
		{
			m_rot.y = pCamera->GetRot().x + ((D3DX_PI * 5) / 4);
		}
	}



	//�ړ��ł����ԂɂȂ�����
	if (m_nMovePush)
	{
		m_pos.x -= (sinf(m_rot.y))*m_fMoveSpeed;
		m_pos.z -= (cosf(m_rot.y))*m_fMoveSpeed;
		m_fSoundInterval += 0.1f;
		if (m_fSoundInterval >= 1.3f)
		{
			m_fSoundInterval = 0.0f;
			/*CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_WALK);*/
		}
	}
}
//-----------------------------------------------
//�ړ��̏���(�Q�[���p�b�h)
//-----------------------------------------------
void CPlayer::PadMove()
{
	float fLength = 0.0f;

	//DirectInput�̃Q�[���p�b�h�̎擾
	CDirectInput *pGamePad = CManager::GetDirectInput();
	//�Q�[���p�b�h�̃{�^�����̎擾
	DIJOYSTATE2 GamePad = pGamePad->GetJoyState();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();

	//�O�ɐi��

	if ((float)GamePad.lX >= MAX_DEAD_ZOON || (float)GamePad.lY >= MAX_DEAD_ZOON ||
		(float)GamePad.lX <= -MAX_DEAD_ZOON || (float)GamePad.lY <= -MAX_DEAD_ZOON)
	{
		//�ړ����[�V�����ɂ���
		StateChange(MOVE);
		//�X�e�B�b�N�̌X���̒��������߂�
		fLength = (float)sqrt(GamePad.lX * GamePad.lX + GamePad.lY * GamePad.lY);
		fLength = fLength / 1000.f;
		float fRot = atan2f((float)GamePad.lX, (float)GamePad.lY);
		m_rot.y = -(fRot - pCamera->GetRot().x);
		m_rot.x -= (sinf(m_rot.y)*PLAYER_MOVE_SPEED)*fLength;
		m_pos.z -= (cosf(m_rot.y)*PLAYER_MOVE_SPEED)*fLength;
		m_fSoundInterval += 0.1f;
		if (m_fSoundInterval >= 1.3f)
		{
			m_fSoundInterval = 0.0f;
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_WALK);
		}

	}
	else
	{
		//�ҋ@���[�V�����ɖ߂�
		StateChange(IDLE);

		m_fSoundInterval = 1.3f;

		CManager::GetSound()->StopSound(CSound::SOUND_LABEL_SE_WALK);

	}
}
//-----------------------------------------------
//�U���̏���(state��Attack�Ȃ�Ă΂��)
//-----------------------------------------------
void CPlayer::Attack()
{
	//�U�����[�V�����ɂ���
	switch (m_nComboType)
	{
	case COMBO_1:
		m_fAttackWaitTime = 5.0f;
		m_motionType = N_ATTACK_1;
		break;
	case COMBO_2:
		m_motionType = N_ATTACK_2;
		m_fAttackWaitTime = 8.0f;

		break;
	case COMBO_3:
		m_motionType = N_ATTACK_3;
		break;
	}
	//�L�[�����R�ɂȂ�����U���\�ɂ���
	if (m_pMotion->GetMotionKey() >= 3 && !m_bAttackWait)
	{
		if (m_pSword)
		{
			//����̓����蔻����I�t�ɂ���
			m_pSword->SetCanHit(false);
		}
		if (FixedTimeInterval(m_fAttackWaitTime))
		{
			m_bCanAttack = true;
		}
	}
	//�U������Ƃ��Ɉړ�����
	if (m_bCanAttackMove)
	{
		m_fAttackMoveTime++;
		if (m_fAttackMoveTime > AttackMoveTime)
		{
			m_fAttackMoveTime = 0.0f;
			//�U�����Ɉړ��𐧌�
			m_bCanAttackMove = false;
		}
		//�U�����Ɉړ�
		AttackMove(AttackMoveSpeed);
	}

	//�ő�R���{����ŏ��̃R���{�ɖ߂�Ƃ��̑ҋ@
	if (m_bAttackWait)
	{

		if (m_pMotion->GetMotionKey() >= 3)
		{
			if (m_pSword)
			{
				//����̓����蔻����I�t�ɂ���
				m_pSword->SetCanHit(false);
			}

			if (FixedTimeInterval(AttackWaitTime))
			{
				m_bAttackWait = false;
				m_bCanAttack = true;
				m_nComboType = COMBOWAIT;
				m_bMoveStop = false;
			}
		}
	}
	//���̓����蔻����U���ł���悤�ɂ���

}
//-----------------------------------------------
//�ʏ�U���̑���̏���
//-----------------------------------------------
void CPlayer::AttackCtrl()
{
	//DirectInput�̃Q�[���p�b�h�̎擾
	CDirectInput *pGamePad = CManager::GetDirectInput();
	//�Q�[���p�b�h�̃{�^�����̎擾
	DIJOYSTATE2 GamePad = pGamePad->GetJoyState();
	//�}�E�X���̎擾
	CMouse *pMouse = CManager::GetMouse();

	//�U���ł����ԂȂ�U��������\�ɂ���
	if (m_bCanAttack)
	{
		if (pGamePad->GetButtonTrigger(CDirectInput::B) == true || pMouse->GetTrigger(CMouse::MOUSE_LEFT) == true)
		{
			//���݂̃L�[�����O�ɂ���
			if (m_pMotion)
			{
				m_pMotion->SetNumKey(0);
			}
			//�U����Ԃɂ���
			StateChange(ATTACK);

			//�ړ��𐧌�����
			m_bMoveStop = true;

			//����ȏ�U���ł��Ȃ��悤�ɂ���
			m_bCanAttack = false;

			//�U������Ƃ������ړ��ł���悤�ɂ���
			m_bCanAttackMove = true;

			//�v���C���[��G�̕����Ɍ�������
			if (m_pNearEnemy != nullptr&&m_bNearEnemy == true)
			{
				NearEnemyFace();
			}

			m_nComboType++;

			if (m_pSword)
			{
				//����̓����蔻����I���ɂ���
				m_pSword->SetCanHit(true);
			}
			//�ő�R���{�ɍs������
			if (m_nComboType >= COMBO_3)
			{
				//�ő�R���{����ŏ��̃R���{�ɖ߂�Ƃ��̑ҋ@����
				m_bAttackWait = true;
				
			}
			//CManager::GetSound()->StopSound(CSound::SOUND_LABEL_SE_WALK);
			//CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_SWORD_ATTACK);
			//CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_SWORD_ATTACK, 0.5f);

		}

	}
}
//-----------------------------------------------
//�}�E�X�̃J��������
//-----------------------------------------------
void CPlayer::MouseCameraCtrl()
{

	CMouse *pMouse = CManager::GetMouse();
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	D3DXVECTOR3 PosV = pCamera->GetPosV();
	D3DXVECTOR3 PosR = pCamera->GetPosR();
	D3DXVECTOR3 Rot = pCamera->GetRot();
	float fLong = 0.0f;
	float fGetLong = pCamera->GetLong();
	fLong = (float)pMouse->GetMousePos().lZ / 5.0f*-1;


	//�J�����̉�]
	Rot.y += (float)pMouse->GetMousePos().lY / MouseCameraLimit_X;
	Rot.x += (float)pMouse->GetMousePos().lX / MouseCameraLimit_Y;


	if (Rot.y > -0.1f)
	{
		Rot.y = -0.1f;
	}
	else if (Rot.y < -1.5f)
	{
		Rot.y = -1.5f;
	}
	if (Rot.x > D3DX_PI)
	{
		Rot.x = -D3DX_PI;
	}
	else if (Rot.x < -D3DX_PI)
	{
		Rot.x = D3DX_PI;
	}

	pCamera->SetLong(fLong);
	if (fGetLong <= 10.0f)
	{
		pCamera->SetLong(-fGetLong);
	}

	PosV.x = PosR.x + sinf(Rot.y)* sinf(Rot.x) * pCamera->GetLong();
	PosV.y = PosR.y + cosf(Rot.y)			   * pCamera->GetLong();
	PosV.z = PosR.z + sinf(Rot.y)* cosf(Rot.x) * pCamera->GetLong();

	pCamera->SetPosR(PosR);
	pCamera->SetPosV(PosV);
	pCamera->SetRot(Rot);

}
//-----------------------------------------------
//�߂��G�̕����Ƀv���C���[����������
//-----------------------------------------------
void CPlayer::NearEnemyFace()
{
	D3DXVECTOR3 EnemyPos = m_pNearEnemy->GetPos();
	D3DXVECTOR3 EnemyVec = EnemyPos - m_pos;			//�G�ƃv���C���[�̃x�N�g��
														//�v���C���[�ƓG�̌��������߂�
	float fAng = atan2(EnemyVec.x, EnemyVec.z);//�G�̌���
	m_rot.y = fAng + D3DX_PI;

}
//-----------------------------------------------
//���x���A�b�v�̏���
//-----------------------------------------------
void CPlayer::LevelUp(int nType)
{
	//���x�������Z����
	m_nLevel += 1;
	m_fMaxExpDiameter += 0.3f;
	m_fMaxExp = m_fMaxExp *m_fMaxExpDiameter;
	CManager::GetGame()->GetExpGauge()->GetGaugeBer(0)->SetGaugeValueMax(m_fMaxExp);
	switch (nType)
	{
	case ATKup:
		//�U���͂��グ��
		m_fPowerDiameter += 0.1f;
		m_fPower = PlayerPower * m_fPowerDiameter;
		if (m_pSword)
		{
			//���ɍU���͂𔽉f
			m_pSword->SetPower(m_fPower);
		}
		break;
	case Eye:
		break;
	case Heal:
		//�I�[�g�q�[���ݒ���I���ɂ���
		m_bCanAutoHeel = true;
		m_fAutoHeel += 10.0f;
		break;
	case OverHeal:
		CManager::GetGame()->GetHPGauge()->SetGauge(-MaxHP,0);
		CManager::GetGame()->GetHPGauge()->ResetGauge(1);
		CManager::GetGame()->GetHPGauge()->SetGauge(-MaxHP/2.0f, 1);

		break;
	case Sheild:
		break;
	case Beam:
		break;
	case BlackHole:
		m_bCanBlackHole = true;
		break;
	case Rocket:
		break;
	case RushAttack:
		m_bCanRushAttack = true;
		break;
	}
}
//-----------------------------------------------
//���G�̋߂������Z�o
//-----------------------------------------------
bool CPlayer::IsNearEnemyState()
{
	bool bNearEnemy = false;
	CScene *pScene_E = CScene::GetScene(CScene::OBJTYPE_ENEMY);//��ԍŏ��̓G
	float fLength = 0.0f;//�v���C���[�ƓG�̊Ԃ̋���
	float fLength2 = 0.0f;//�v���C���[�ƓG�̊Ԃ̋���

						  //��ԋ߂��G�̏��̕ۑ��p
	m_pNearEnemy = (CEnemy*)pScene_E;
	//��ԋ߂��G�����߂�
	while (pScene_E != NULL)
	{
		//���̓G�̋����̒��������߂�

		if (m_pNearEnemy != NULL)
		{
			D3DXVECTOR3 EnemyPos = m_pNearEnemy->GetPos();
			D3DXVECTOR3 EnemyVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			EnemyVec = EnemyPos - m_pos;			//�G�ƃv���C���[�̃x�N�g��
			fLength = sqrtf((EnemyVec.z*EnemyVec.z) + (EnemyVec.x*EnemyVec.x));
		}
		if (pScene_E != NULL)
		{
			//���̓G�̋����̒��������߂�
			CScene *pSceneNext = pScene_E->GetSceneNext(pScene_E);
			if (pSceneNext != NULL)
			{
				CEnemy *pEnemyNext = (CEnemy*)pSceneNext;
				D3DXVECTOR3 EnemyPosNext = pEnemyNext->GetPos();
				D3DXVECTOR3 EnemyVecNext = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				EnemyVecNext = EnemyPosNext - m_pos;			//�G�ƃv���C���[�̃x�N�g��
				fLength2 = sqrtf((EnemyVecNext.z*EnemyVecNext.z) + (EnemyVecNext.x*EnemyVecNext.x));
				//�G�Ƃ̋������߂������烍�b�N�I���ł���悤�ɂ���
				if (fLength2 < PLAYER_ROCK_LENGTH)
				{
					bNearEnemy = true;
				}

				//���̓G�����̓G��艓��������
				if (fLength > fLength2)
				{
					m_pNearEnemy = pEnemyNext;
				}
			}
		}
		pScene_E = pScene_E->GetSceneNext(pScene_E);
	}

	return bNearEnemy;
}
//-----------------------------------------------
//�v���C���[�ɃJ������Ǐ]�����鏈��
//-----------------------------------------------
void CPlayer::FollowingPlayerCamera()
{
	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	D3DXVECTOR3 PosR = pCamera->GetPosR();
	//�L�[�{�[�h�̎擾
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	{
		//�J�����̒����_�ƃv���C���[�̈ʒu�̍���
		float PosDifference_X = PosR.x - m_pos.x;

		//�v���C���[�̈ʒu�ɖ߂����x
		float RevertSpeed = abs(PosDifference_X / CameraLimit);
		//RevertSpeed��0.0f�o�͂Ȃ�������
		if (RevertSpeed != 0.0f)
		{
			//���������̐��Ȃ畉�̐��ɖ߂��悤�ɂ���
			if (PosDifference_X > 0)
			{
				PosR.x -= RevertSpeed;
			}
			else
			{
				PosR.x += RevertSpeed;
			}
		}
	}
	{
		float PosDifference_Z = PosR.z - m_pos.z;//�J�����̒����_�ƃv���C���[�̈ʒu�̍���
		float RevertSpeed = abs(PosDifference_Z / CameraLimit);//�v���C���[�̈ʒu�ɖ߂����x
		//RevertSpeed��0.0f�o�͂Ȃ�������
		if (RevertSpeed != 0.0f)
		{
			//���������̐��Ȃ畉�̐��ɖ߂��悤�ɂ���
			if (PosDifference_Z > 0)
			{
				PosR.z -= RevertSpeed;
			}
			else
			{
				PosR.z += RevertSpeed;
			}

		}

	}
	pCamera->SetPosR(PosR);

}
void CPlayer::Drawtext()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[3000];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n ��� \n");

	//�J�����̎擾
	CCamera *pCamera = CRenderer::GetCamera();
	D3DXVECTOR3 PosV = pCamera->GetPosV();
	D3DXVECTOR3 PosR = pCamera->GetPosR();
	D3DXVECTOR3 Rot = pCamera->GetRot();
	CMouse *pMouse = CManager::GetMouse();
	POINT po;
	GetCursorPos(&po);
	float MousePos_X = po.x;
	float MousePos_Y = po.y;
	RECT rec;
	HWND hDeskWnd = GetForegroundWindow();
	GetWindowRect(hDeskWnd, &rec); //�f�X�N�g�b�v�̃n���h�����炻��(��ʂ�)�傫�����擾

	//nNum += sprintf(&str[nNum], " [GetMousePos().lX] %.5f\n", MousePos_X);
	//nNum += sprintf(&str[nNum], " [GetMousePos().lY] %.5f\n", MousePos_Y);
	//nNum += sprintf(&str[nNum], " [rec.left] %d\n", rec.left);
	//nNum += sprintf(&str[nNum], " [rec.right] %d\n", rec.right);

	nNum += sprintf(&str[nNum], " [MotionCnt] %.5f\n", m_pMotion->GetMotionCnt());
	nNum += sprintf(&str[nNum], " [�U����] %.5f\n", m_fPower);
	nNum += sprintf(&str[nNum], " [�U�������{��] %.5f\n", m_fPowerDiameter);
	nNum += sprintf(&str[nNum], " [���x��] %d\n", m_nLevel);

	nNum += sprintf(&str[nNum], " [���_] %.5f,%.5f,%.5f\n", PosV.x, PosV.y, PosV.z);
	nNum += sprintf(&str[nNum], " [�����_] %.5f,%.5f,%.5f\n", PosR.x, PosR.y, PosR.z);
	nNum += sprintf(&str[nNum], " [��]] %.5f,%.5f,%.5f\n", Rot.x, Rot.y, Rot.z);

	//nNum += sprintf(&str[nNum], " [MotionKey] %d\n", m_pMotion->GetMotionKey());
	//nNum += sprintf(&str[nNum], " [Canhit] %d\n", m_pSword->GetCanHit());
	//nNum += sprintf(&str[nNum], " [m_bCanAttack] %d\n", m_bCanAttack);


	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// �e�L�X�g�`��
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}

//----------------------------------------------
//�ړ��p�̃L�[�������Ă��邩�̔����Ԃ�����
//----------------------------------------------
bool CPlayer::IsMoveKeyCheck()
{
	CInputKeyBoard *Key = CManager::GetInputKeyboard();

	return (Key->GetPress(DIK_W) == true ||
		Key->GetPress(DIK_A) == true ||
		Key->GetPress(DIK_S) == true ||
		Key->GetPress(DIK_D) == true);
}
//----------------------------------------------
//��莞�ԊԊu��u������
//----------------------------------------------
bool CPlayer::FixedTimeInterval(float fMaxTime)
{
	bool bStop = false;
	m_fStopTime++;
	if (m_fStopTime > fMaxTime)
	{
		m_fStopTime = 0.0f;
		bStop = true;
	}
	//��莞�Ԃ���������Ԃ�
	return bStop;
}
//-----------------------------------------------
//�ǌ�����
//-----------------------------------------------
void CPlayer::PlayerRushAttack()
{

}
//-----------------------------------------------
//�e�X�L���̏����̂܂Ƃ�
//-----------------------------------------------
void CPlayer::EachSkillManager()
{
	//�I�[�g�q�[��
	if (m_bCanAutoHeel)
	{
		m_nTimer++;

		if (m_nTimer >= 60)
		{
			m_nTimer = 0;
			float fHP = CManager::GetGame()->GetHPGauge()->GetGaugeBer(1)->GetGaugeValue();
			if (fHP <= 0.0f)
			{
				CManager::GetGame()->GetHPGauge()->SetGauge(-m_fAutoHeel, 0);
			}
		}

	}
	//�u���b�N�z�[��
	if (m_bCanBlackHole)
	{
		m_nBlackHoleCnt++;
		if (m_nBlackHoleCnt >= BlackHoleShotTime)
		{
			m_nBlackHoleCnt = 0;
			CBlackHole::Create(m_pos, m_rot, m_pNearEnemy);
		}

	}
}
//-----------------------------------------------
//�U�������Ƃ��̈ړ�����
//-----------------------------------------------
void CPlayer::AttackMove(float fMoveVolume)
{
	m_pos.x -= sinf(m_rot.y)*fMoveVolume;
	m_pos.z -= cosf(m_rot.y)*fMoveVolume;
}
//-----------------------------------------------
//����̃Z�b�g
//---------------------------------------------
void CPlayer::WeaponSet(const char * pcFileName)
{
	int nParent = 0;				//�e�q�֌W
	char string[6][255];
	D3DXVECTOR3 PartsPos, PartsRot;	//�e�p�[�c�̈ʒu�ƌ���
									//text�t�@�C���ǂݍ���
	FILE *pfile = fopen(pcFileName, "r");
	//�k���`�F�b�N
	if (pfile != NULL)
	{
		while (1)
		{
			//��P���ǂݍ���
			fscanf(pfile, "%s", &string[0]);

			while (strcmp(string[0], "CHARACTERSET") == 0)
			{
				fscanf(pfile, "%s", &string[1]);
				//�p�[�c�̐ݒ�
				while (strcmp(string[1], "WEAPONSET") == 0)
				{
					//��P���ǂݍ���
					fscanf(pfile, "%s", &string[2]);

					//�ʒu
					if (strcmp(string[2], "POS") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%f %f %f", &PartsPos.x, &PartsPos.y, &PartsPos.z);
					}
					//����
					if (strcmp(string[2], "ROT") == 0)
					{
						fscanf(pfile, "%s", &string[2]);
						fscanf(pfile, "%f %f %f", &PartsRot.x, &PartsRot.y, &PartsRot.z);
					}
					//���f���̐���
					if (strcmp(string[2], "END_WEAPONSET") == 0)
					{
						//����̐���
						if (!m_pSword)
						{
							m_pSword = CSword::Create(PartsPos, PartsRot, m_pParts[5]);
							m_pSword->SetPower(m_fPower);
						}
						break;
					}
				}
				//�I��
				if (strcmp(string[1], "END_CHARACTERSET") == 0)
				{
					break;
				}

			}
			if (strcmp(string[0], "END_SCRIPT") == 0)
			{
				break;
			}
		}
	}
}
