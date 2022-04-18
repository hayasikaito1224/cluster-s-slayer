//=============================================
//����̃N���X
//=============================================
#ifndef _WEAPON_H_
#define _WEAPON_H_
#include "main.h"
class CModel;

class CWeapon
{
public:
	struct HitCollision
	{
		D3DXVECTOR3 m_pos;//�ʒu
		D3DXVECTOR3 m_rot;//����
		D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	};
	CWeapon();
	~CWeapon();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void HItCollisionSet();
	void SetCanHit(const bool& bCanHit) { m_bCanHitCollision = bCanHit; }//����̓����蔻��𔭐������邩�̐ݒ�
	bool GetCanHit() { return m_bCanHitCollision; }//����̓����蔻��𔭐������邩�̐ݒ�

	//�����������̈ʒu���Ɠ����������̓����蔻��̑傫��
	bool HitSet(D3DXVECTOR3 *Hitpos,const float& HitSize);//����̓����蔻��̐ݒ�

private:
protected:
	HitCollision m_HitCollision;//�����蔻��
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_lastpos;//1�t���[���O�̈ʒu
	D3DXVECTOR3 m_rot;//����
	D3DXMATRIX m_mtxWorld;//���[���h�}�g���b�N�X
	CModel*m_pWeapon;//����̃��f��
	CModel *m_pParent;//�e���f���̃|�C���^
	float m_fHitSize;//�����蔻��̑傫��
	bool m_bWeaponDraw;//����̕`��ݒ�
	bool m_bCanHitCollision;//�U�����肪�ł��邩
	bool m_bIsHit;//�����킪�G�ɓ������Ă��邩
};


#endif // !_WEAPON_H_
