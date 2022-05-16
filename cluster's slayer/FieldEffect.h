//=============================================================================
// ���ʃG�t�F�N�g���� [FieldEffect.h]
// Author : �����G��
//=============================================================================
#ifndef _FIELDEFFECT_H_
#define _FIELDEFFECT_H_

#include "main.h"
#include "plane.h"

class CFieldEffect : public CPlane
{
public:
	typedef enum
	{
		START,
		ACTIVE,
		END,
		MAX,
	} EFFECT_TIME;

	CFieldEffect(int nPriority);
	~CFieldEffect();

	HRESULT Init(D3DXVECTOR3 size,
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
		int CreatePreset);

	void Uninit();
	void Update();
	void Draw();

	static CFieldEffect *Create(D3DXVECTOR3 size,
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
		int CreatePreset);

private:
	EFFECT_TIME EffectTime;	//�G�t�F�N�g�̍��̏��

	int nLife;	//����
	int nParticleTime;	//�p�[�e�B�N���̔����Ԋu
	int Time;		//�p�[�e�B�N���Ԋu�v�Z

	float fRotate;	//���݂̉�]
	float fAddRotate;	//��]�̉��Z
	D3DCOLORVALUE m_FieldColor;	//�p�[�e�B�N���J���[
	D3DCOLORVALUE m_FieldAddColor;	//�p�[�e�B�N���J���[����

	D3DXVECTOR3 m_pos;
	float m_MaxSize;	//�ڕW�T�C�Y
	float m_size;		//���݂̑傫��
	float m_AddSize;	//�傫���̉��Z
	float m_ActiveAddSize;	//�A�N�e�B�u���̑傫���̉��Z

	int m_nTime;	//�A�N�e�B�u���̎���
	int m_nSynsetic;	//����

	int m_nDensity;	//���x
	float m_fDistance;	//�p�[�e�B�N�������Ԋu����
	D3DCOLORVALUE m_ParticleColor;	//�p�[�e�B�N���J���[
	D3DCOLORVALUE m_ParticleAddColor;	//�p�[�e�B�N���J���[����
	int m_nParticleTex;	//�e�N�X�`��
	int m_nParticleLife;	//����
	int m_nParticleSynthetic;	//����
	float m_ParticleMove3d;	//�ړ��l
	float m_ParticleAddSize;	//�p�[�e�B�N���T�C�Y���Z
	float m_ParticleSize;	//�p�[�e�B�N���T�C�Y

	float SizeY;

	int m_FieldTime;	//�t�B�[���h�����Ԋu
	int m_FieldTimedelta;	//�t�B�[���h�����Ԋu�v�Z

	bool m_FieldCreate;	//�t�B�[���h�������邩
	int m_CreatePreset;	//�ǂ̃v���Z�b�g�𐶐����邩

	bool bUninit;
};

#endif