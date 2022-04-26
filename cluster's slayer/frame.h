//--------------------------------------
//�QD�|���S���̉����̏���
//--------------------------------------
#ifndef _FRAME_H
#define _FRAME_H
#include "scene.h"

//�O���錾
class CPolygon;

class CFrame : public CScene
{
public:
	CFrame(OBJTYPE nPriority = OBJTYPE_FRAME);
	~CFrame();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CFrame *Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& size, const D3DXCOLOR& col);
private:
	CPolygon *pPolygonFrame;
	bool m_bEnd;//�I������
};


#endif //_RESULT_H