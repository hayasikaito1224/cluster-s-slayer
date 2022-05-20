#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "main.h"
//�}�N����`

#define PARTICLE_X (30)
#define PARTICLE_Y (30)
#define PARTICLE_Z (0)
typedef enum
{
	SET_EFFECT = 0,//�e�X�g�^�C�v
	SET_WORKEFFECT,		//�ړ����ɏo��G�t�F�N�g
	SET_CIRCLE,
	SET_HITDAMEGE,		//�_���[�W�������������̃G�t�F�N�g
	SET_DESS,			//���񂾂Ƃ��̃G�t�F�N�g
} SetEffectType;//�o���G�t�F�N�g�̃^�C�v
typedef struct
{
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 size;
	D3DXVECTOR3 move;
	SetEffectType SetEffectType;//�o���G�t�F�N�g�̃^�C�v
	float fAngle;//�p�x
	float fSpeed;//����
	int nRand;
	int nParticleTimer;				//particle���o���Ԋu
	int nControl;//particle�̏o������
	bool bUse;//�g�p���Ă��邩�ǂ���

} Particle;
//�v���g�^�C�v�錾
void InitParticle(void);//������
void UninitParticle(void);//�I������
void UpdateParticle(void);//�X�V
void DrawParticle(void);//�`��
void SetParticle(D3DXVECTOR3 pos,SetEffectType SetEffectType);
void SetWorkParticle(int nPlayer, D3DXVECTOR3 pos);
Particle *GetParticle(void);

#endif // !_Billboard_H_


