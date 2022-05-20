//-----------------------------------------
//�v���C���[�̑���
//-----------------------------------------
#include "main.h"
#define PLAYER_MOVE_SPEED (10.0f)//�ړ���
#define NUM_ADD_SPEED (3)//���������鐔�̔z��

class CPlayer_Controller
{
public:
	CPlayer_Controller();
	~CPlayer_Controller();
	void TestMove(D3DXVECTOR3& pos);
	void FieldMove(D3DXVECTOR3& pos, const D3DXVECTOR3 size);
	void WallMove(D3DXVECTOR3& pos, const D3DXVECTOR3 size);

	void MouseMove(D3DXVECTOR3& pos);
	void MouseFieldMove(D3DXVECTOR3& pos, const D3DXVECTOR3 size);
	void ModelRot(D3DXVECTOR3& rot);
	void AddTypeChange();
	void Drawtext(void);
	void MouseCameraControl();
	float	 GetAddSpeed() { return m_fAddSpeed[m_nAddType]; }
	float	 GetAddRotSpeed() { return m_fAddRotSpeed[m_nAddRotType]; }
	bool bLongOn();//���������ł��邩��Ԃ�
	bool bLongKey(int nKey);//�������̏���
	void LongPush();
private:
	POINT m_Cursol;
	float m_fAddSpeed[NUM_ADD_SPEED];//���������鐔
	float m_fAddRotSpeed[NUM_ADD_SPEED];//���������鐔
	int	  m_nAddType;
	int	  m_nAddRotType;
	int m_nCntPushTime;//�ǂꂭ�炢�L�[����������
	bool m_bPush;//���[�����������ǂ���
	bool m_bShiftLock;//�V�t�g����������
	bool m_bAltLock;//�I���g����������
	bool m_bCtrlLock;//�R���g���[������������

};

