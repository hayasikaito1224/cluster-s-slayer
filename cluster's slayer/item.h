//--------------------------------------
//�A�C�e���̏���
//����ҁF��
//--------------------------------------
#ifndef _ITEM_H_
#define _ITEM_H_
#include "scene.h"

class CSound;
class CBillboard;

class CItem : public CScene
{
public:

	CItem(OBJTYPE nPriority = CScene::OBJTYPE_ITEM);
	~CItem();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	bool IsColision(const D3DXVECTOR3& HitPos, const float& radius);
	void Inhale(const D3DXVECTOR3& vec);//�A�C�e�����v���C���[�ɋz�����܂�鏈��
	void Leave();//�o���ʒu���痣��鏈��
private:
protected:
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_lastpos;//1�t���[���O�̈ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	CBillboard * pItemObj;//�A�C�e���̉摜
	float m_fRadius;//�����蔻��͈̔�
	float m_fLeaveAng;//�o���ʒu���痣���v�Z�Ɏg���p�x
	int m_nLeaveTimer;//�J�E���^�[
	int m_nLeaveTime;//�o���ʒu���痣��鎞��
	bool m_bIsLeave;//�o���ʒu���痣��锻��
	bool m_bIsHit;//�����蔻��
	bool m_IsInhale;//�z�����܂�邩�̔���
	bool m_IsDeath;//���S����

};


#endif // !_PLAYER_H_

