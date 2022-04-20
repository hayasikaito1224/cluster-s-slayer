//--------------------------------------
//�A�C�e���̏���
//--------------------------------------
#include "item.h"
#include "manager.h"
#include "game.h"
#include "player.h"
#include "model.h"
#include "Renderer.h"
#include "billboard.h"
static const float InhaleHitSize = 100.0f;//�z�����܂��͈�
static const float InhaleSpeed = 11.0f;//�z�����܂�鑬�x
static const int LeaveTimeMin = 5;//�o���ʒu���痣��鎞��
static const int LeaveTimeMax = 10;//�o���ʒu���痣��鎞��

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CItem::CItem(OBJTYPE nPriority) :CScene(nPriority)
{
	m_bIsHit = false;
	m_IsDeath = false;
	m_IsInhale = false;
	m_bIsLeave = true;
	m_nLeaveTimer = 0;
	m_nLeaveTime = 0;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CItem::~CItem()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CItem::Init(void)
{
	static std::random_device random;	// �񌈒�I�ȗ���������
	std::mt19937_64 mt(random());            // �����Z���k�E�c�C�X�^��64�r�b�g�ŁA�����͏����V�[�h
	std::uniform_real_distribution<> randAng(0.0f, D3DX_PI);
	std::uniform_real_distribution<> randAng2(0.0f, D3DX_PI);
	std::uniform_real_distribution<> randTime(LeaveTimeMin, LeaveTimeMax);
	//�o���ʒu���痣���v�Z�Ɏg���p�x�����߂�
	m_fLeaveAng = (float)randAng(mt) - (float)randAng2(mt);
	//�o���ʒu���痣��鎞��
	m_nLeaveTime = randTime(mt);
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CItem::Uninit(void)
{
	if (pItemObj)
	{
		pItemObj->Uninit();
		pItemObj = nullptr;
	}
	Release();
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CItem::Update(void)
{
	//�o���ʒu���痣��鏈��
	if (m_bIsLeave)
	{
		Leave();
	}
	else
	{
		//�v���C���[�����擾
		CPlayer *pPlayer = CManager::GetGame()->GetPlayer();
		////�v���C���[�ɑ΂��Ă̓����蔻��
		if (pPlayer)
		{
			float fRadius = pPlayer->GetParts(0)->GetMaxPos().x*3.0f;
			float HitSize = fRadius + InhaleHitSize;
			D3DXVECTOR3 pos = pPlayer->GetPos();
			D3DXVECTOR3 vec = m_pos - pos;
			float Length = sqrtf((vec.x*vec.x) + (vec.z*vec.z));
			//�A�C�e�����v���C���[�ɋz�����܂�Ă��Ȃ�������&&
			if (!m_IsInhale)
			{
				//�z�����ݔ͈͂ɓ�������
				if (Length < HitSize)
				{
					//���z�����܂�Ă��锻��ɂ���
					m_IsInhale = true;
				}

			}
			else
			{
				//�A�C�e�����v���C���[�ɋz�����܂�鏈��
				Inhale(vec);
			}
			//�A�C�e�����v���C���[�ɓ������Ă��Ȃ�������
			if (!m_bIsHit)
			{
				//�����蔻����擾
				m_bIsHit = IsColision(pos, fRadius);
			}
			else
			{
				//�A�C�e��������
				m_IsDeath = true;
			}
		}

	}
	//�������肪�I���Ȃ�
	if (m_IsDeath)
	{
		Uninit();
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CItem::Draw()
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

}
//--------------------------------------------
//�����蔻��
//--------------------------------------------
bool CItem::IsColision(const D3DXVECTOR3& HitPos, const float& radius)
{
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�����Ƒ���̃x�N�g��
	vec = HitPos - m_pos;
	float fLength = 0.0f;
	//����Ǝ����̋��������߂�
	fLength = sqrtf((vec.z*vec.z) + (vec.x*vec.x));
	//�����蔻��̑傫�������߂�
	float fCollisionRadius = m_fRadius + radius;
	//����Ǝ����̋����������̓����蔻��̑傫����菬�����Ȃ�����
	if (fLength <= fCollisionRadius)
	{
		//���������Ƃ��������Ԃ�
		return true;
	}
	return false;
}
//--------------------------------------------
//�A�C�e�����v���C���[�ɋz�����܂�鏈��
//--------------------------------------------
void CItem::Inhale(const D3DXVECTOR3& vec)
{
	//�ړ�������������߂�
	float MoveAng = atan2(vec.x, vec.z);
	m_pos.x -= sinf(MoveAng)*InhaleSpeed;
	m_pos.z -= cosf(MoveAng)*InhaleSpeed;
	if (pItemObj)
	{
		pItemObj->Setpos(m_pos, { m_fRadius ,m_fRadius ,0.0f});
	}
}
//--------------------------------------------
//�o���ʒu���痣��鏈��
//--------------------------------------------
void CItem::Leave()
{

	m_pos.x += sinf(m_fLeaveAng)*InhaleSpeed;
	m_pos.z += cosf(m_fLeaveAng)*InhaleSpeed;
	if (pItemObj)
	{
		pItemObj->Setpos(m_pos, { m_fRadius ,m_fRadius ,0.0f });
	}
	m_nLeaveTimer++;
	if (m_nLeaveTimer > m_nLeaveTime)
	{
		m_nLeaveTimer = 0;
		m_bIsLeave = false;
	}
}

