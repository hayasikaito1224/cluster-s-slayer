//----------------------------------
//�X�e�[�W�G�f�B�^�̏���
//----------------------------------
#ifndef _STAGEEDITOR_H
#define _STAGEEDITOR_H
#include "scene.h"
#define NUM_SAVE_FILE (3)

class CModel;
class CScene3D;
class CPlayer_Controller;
class CField;
class CWall;

class CStageEditor : public CScene
{
public:
	typedef enum
	{
		TYPE_OBJECT=0,
		TYPE_FIELD,
		TYPE_WALL,
		TYPE_ENEMY,
		TYPE_MAX
	}TYPE;
	typedef enum
	{
		MODE_SET = 0,
		MODE_EDIT,
		MODE_MAX
	}MODE;
	CStageEditor(OBJTYPE nPriority = CScene::OBJTYPE_NONE);
	~CStageEditor();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Drawtext();
	void MeshSizeChange();
	void MeshNumChange();
	void Wall();//�ǂ͈ʒu�֌W�̏���
	void Enemy();//�G�̔z�u�֌W�̏���
	void ShiftLock();
	void CtrlLock();

	void Save();
	void Load();
	void SelectNum(int nKeyAdd,int nKeyDef,int& nSelectData,const int nAddNumber,const int nMax);
private:
	CPlayer_Controller	*m_pController;//����n�̃N���X
	static vector<CModel*>		m_pModel;//�z�u���ꂽ���f��
	static vector<CModel*>		m_pAssistModel;//�z�u���ꂽ���f��
	static vector<CModel*>		m_pAssistEnemyModel;//�z�u���ꂽ���f��
	static vector<CField*>		m_pField;//�z�u���ꂽ���b�V���t�B�[���h
	static vector<CWall*>		m_pWall;//�z�u���ꂽ��
	static vector<CModel*>		m_pEnemyModel;//�z�u����G

	CScene3D *pAssistCursor;//�z�u�ꏊ�𕪂���₷������p�̔|���S��
	CScene3D *pAssistCursorWall;//�z�u�ꏊ�𕪂���₷������p�̔|���S��

	D3DXVECTOR3 m_pos, m_rot,m_size,m_Meshsize;
	D3DXMATRIX m_mtxWorld;											//���[���h�}�g���b�N�X
	int m_nSetModelType;//�ݒu���郂�f���̃^�C�v
	int m_nSetType;//�ݒu����I�u�W�F�N�g�̃^�C�v
	int m_nCnt;
	int m_nMeshNumX;//���b�V���t�B�[���h�̉��̐�
	int m_nMeshNumZ;//���b�V���t�B�[���h�̏c�̐�
	int m_nMeshCnt;//���b�V���t�B�[���h�̐�
	int m_nWallCnt;//���b�V���t�B�[���h�̐�
	int m_nEnemyCnt;//�G�̐�
	int m_nNumSaveFile;//�ǂ̃Z�[�u�t�@�C����I��ł��邩
	int m_nModeType;
	int m_nSelectModel;//�ǂ̃��f����I�����Ă��邩
	int m_nSelectMeshField;//�ǂ̃��b�V���t�B�[���h��I�����Ă��邩
	int m_nSelectWall;//�ǂ̕ǂ�I�����Ă��邩
	int m_nSelectEnemy;
	bool m_bIsCulling;//�J�����O�̃I���I�t
	float m_fMoveSpeed;
	bool m_bShiftLock, m_bCtrlLock;
	char m_sSaveFileName[NUM_SAVE_FILE][100];
	bool m_bTextDraw;
};
#endif