//=============================================================================
// �G�t�F�N�g�������[�h������ [Load.h]
// Author : �����G��
//=============================================================================
#ifndef _LOADEFFECT_H_
#define _LOADEFFECT_H_

#include "main.h"

class CLoadEffect
{
public:
	CLoadEffect();
	~CLoadEffect();

	static void EffectStateLoad(const char *aFileName);	//�G�t�F�N�g�̃X�e�[�^�X
	static int GetPresetTotal() { return m_Total; }

	static void EffectOrder(const char *aFileName);	//�G�t�F�N�g�I�[�_�[
	static int GetOrderTotal() { return m_OrderTotal; }
	static int GetFullOrder() { return m_FullOrder; }

private:
	static int m_Total;
	static int m_OrderTotal;
	static int m_FullOrder;
};

#endif // !_LOADEFFECT_H_