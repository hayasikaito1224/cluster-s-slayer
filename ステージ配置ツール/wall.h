#ifndef _WALL_H_
#define _WALL_H_
#include "scene3D.h"
#include "texture.h"
#define MAX_WALL_VTX (4)

class CWall : public CScene3D
{
public:
	typedef struct
	{
		D3DXVECTOR3 vtx, rot;
		D3DXMATRIX mtxWorld;							//ワールドマトリックス
	}WallVtx;//モデルの各頂点の保存用構造体
	
	struct WallData
	{
		D3DXVECTOR3 m_size, m_InitSize;//メッシュのサイズ
		int m_nMax_Vtx_X;		//横ブロックの数
		int m_nMax_Vtx_Y;		//縦ブロックの数

		WallData() : m_nMax_Vtx_X(0), m_nMax_Vtx_Y(0) {}

	};//モデルの各頂点の保存用構造体

	explicit CWall(OBJTYPE nPriority = OBJTYPE_WALL);
	~CWall();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CWall *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, int nNum_X, int nNum_Y, CTexture::Type Tex);
	WallVtx GetVtx(int nCnt) { return m_vtx[nCnt]; }
	const D3DXVECTOR3& GetPos() const { return m_pos; }
	const D3DXVECTOR3& GetRot() const { return m_rot; }
	void SetSize(const D3DXVECTOR3& size) {m_WallData.m_size = size;}//内部データだけ反映
	void SetPos(const D3DXVECTOR3& pos) { m_pos = pos; }
	void SetRot(const D3DXVECTOR3& rot) { m_rot = rot; }

	void SetMoveTex(float fSpeedX, float fSpeedY);
	void SetCol(float fAlpha);
	const WallData& GetWallData() const { return m_WallData; }

private:
	WallData m_WallData;
	D3DXCOLOR m_col;
	LPDIRECT3DINDEXBUFFER9  m_pIdxBuffWall;		//インデックスバッファへのポインタ
	WallVtx				m_vtx[MAX_WALL_VTX];	//各頂点の情報格納構造体
	D3DXVECTOR3			m_vtxMin;				//モデルの最小値
	D3DXVECTOR3			m_vtxMax;						//モデル最大値
	float m_MoveTexX;
	float m_MoveTexY;
	int m_nVtx_Num_Max;							//全体頂点の数
	int m_nIdx_Num_Max;							//インデックスの数
	int m_nPoly_Num_Max;						//三角形のポリゴンの数
	float m_fHalfWidth;							//半分のサイズ
	float m_fHalfDepth;							//半分のサイズ
};


#endif // !_WALL_H_

