//-----------------------------------------
//プレイヤーの操作
//-----------------------------------------
#include "main.h"
#define PLAYER_MOVE_SPEED (10.0f)//移動量
#define NUM_ADD_SPEED (3)//増価させる数の配列

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
	bool bLongOn();//長押しができるかを返す
	bool bLongKey(int nKey);//長押しの処理
	void LongPush();
private:
	POINT m_Cursol;
	float m_fAddSpeed[NUM_ADD_SPEED];//増価させる数
	float m_fAddRotSpeed[NUM_ADD_SPEED];//増価させる数
	int	  m_nAddType;
	int	  m_nAddRotType;
	int m_nCntPushTime;//どれくらいキーを押したか
	bool m_bPush;//きーを押したかどうか
	bool m_bShiftLock;//シフトを押したか
	bool m_bAltLock;//オルトを押したか
	bool m_bCtrlLock;//コントロールを押したか

};

