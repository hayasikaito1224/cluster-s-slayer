//===================================================
//�K�w�\���̐ݒ������N���X
//===================================================
#ifndef _LAYER_STRUCTURE_H
#define _LAYER_STRUCTURE_H

class CModel;

class CLayer_Structure
{
#define MAX_LAYER_PARTS (20)

public:
	CLayer_Structure();
	~CLayer_Structure();
	void SetLayer_Structure(const char *sFileName, CModel **apModel);
	int	 GetMaxParts(void) { return m_MaxParts; }

private:
	int		m_MaxParts;//�p�[�c�̍ő吔

};


#endif // !_LAYER_STRUCTURE_H

