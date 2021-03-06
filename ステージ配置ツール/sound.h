//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
// TEh [sound.h]
// Author : ÑCl
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//===========================================================
// TEhNX
//===========================================================
class CSound
{
public:
	CSound();
	~CSound();

	//=================================
	// TEht@C
	//=================================
	typedef enum
	{
		//--------------------------
		// afl
		//--------------------------
		SOUND_LABEL_BGM_TITLE = 0,			// ^CgÌBGM
		SOUND_LABEL_BGM_GAME,				// Q[ÌBGM
		SOUND_LABEL_BGM_RESULT,				// UgÌBGM

		//--------------------------
		// rd
		//--------------------------
		SOUND_LABEL_SE_ENEMY_DEATH,			// GÌÁÅ
		SOUND_LABEL_SE_ENEMY_DEATH2,		// GÌÁÅ2
		SOUND_LABEL_SE_ENEMY_DEATH3,		// GÌÁÅ3
		SOUND_LABEL_SE_ENEMY_DEATH4,		// GÌÁÅ4
		SOUND_LABEL_SE_AXE_ATTACK,			// U
		SOUND_LABEL_SE_AXE_HIT,				// qbg(G)
		SOUND_LABEL_SE_AXE_HIT_WALL,		// qbg(Ç)
		SOUND_LABEL_SE_AXE_HIT_TREE,		// qbg(Ø)
		SOUND_LABEL_SE_SWORD_ATTACK,		// U
		SOUND_LABEL_SE_SWORD_HIT,			// qbg(G)
		SOUND_LABEL_SE_SWORD_HIT_WALL,		// qbg(Ç)
		SOUND_LABEL_SE_SWORD_HIT_TREE,		// qbg(Ø)
		SOUND_LABEL_SE_BREAK_TREE,			// ØÌjó
		SOUND_LABEL_SE_BREAK_WALL,			// ÇÌjó
		SOUND_LABEL_SE_GOAL,				// S[(NbJ[¹)
		SOUND_LABEL_SE_GOAL2,				// S[2(è¹)
		SOUND_LABEL_SE_WARNING,				// x¹
		SOUND_LABEL_SE_WATER_FALL,			// º¹
		SOUND_LABEL_SE_DAMAGE,				// _[W¹
		SOUND_LABEL_SE_WALK,				// à­¹
		SOUND_LABEL_SE_WALK2,				// à­¹2
		SOUND_LABEL_SE_JUMP,				// Wv
		SOUND_LABEL_SE_CHANGE_WEAPON,		// í¿Ö¦
		SOUND_LABEL_SE_SELECT,				// J[\¹
		SOUND_LABEL_SE_ENTER,				// è¹
		SOUND_LABEL_MAX

	} SOUND_LABEL;

	//=============================================================================
	// vg^Cvé¾
	//=============================================================================
	HRESULT InitSound(void);
	void UninitSound(void);
	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);
	void ControllVoice(SOUND_LABEL label, float fVolume) { m_apSourceVoice[label]->SetVolume(fVolume); }

private:
	//=============================================================================
	// p[^\¢Ìè`
	//=============================================================================
	typedef struct
	{
		char *filename;		// t@C¼
		int nCntLoop;		// [vJEg
	} PARAM;

	// e¹fÞÌp[^
	static PARAM m_aParam[SOUND_LABEL_MAX];

	//=============================================================================
	// vg^Cvé¾
	//=============================================================================
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	//=============================================================================
	// O[oÏ
	//=============================================================================
	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2IuWFNgÖÌC^[tFCX
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// }X^[{CX
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// \[X{CX
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// I[fBIf[^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// I[fBIf[^TCY

};
#endif
