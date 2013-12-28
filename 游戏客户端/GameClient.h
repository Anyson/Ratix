#pragma once

#include "Resource.h"
#include "GameClientDlg.h"

//////////////////////////////////////////////////////////////////////////
#include "SexyAppBase.h"

class CSoundPlayer;
class LoadWidget;
class CGameView;
//Ӧ�ó�����
class CGameClientApp : public CGameFrameApp,public Sexy::SexyAppBase
{
	//��������
public:
	//���캯��
	CGameClientApp();
	//��������
	virtual ~CGameClientApp();
	
	CGameFrameDlg		*m_pGameClientDlg;

	CGameView			*m_pGameView;

	//����������
	CSoundPlayer		*m_pSoundPlayer;

	//���ؽ�����ʾ��
	LoadWidget			*m_pLoadWidget;

	//�Ƿ���3D����
	bool				m_b3DAccelerated;
	//�̳к���
public:
	//����������
	virtual CGameFrameDlg * GetGameFrameDlg() { 
		if (m_pGameClientDlg == NULL)m_pGameClientDlg = new CGameClientDlg;	return m_pGameClientDlg;
	}

	virtual BOOL InitInstance();

	void	InitLoadWidget();

	virtual void	LoadingThreadProc();

	virtual void	LoadingThreadCompleted();

	void DestroyGameView();							//����GameView����
	void SetGameViewFocus();						//���ý��㵽GameView

	static bool bStart;
	static void StartThread(void *p);

	virtual void OnGameNetMessage(WPARAM wParam, LPARAM lParam);

	virtual void			EnforceCursor();
};

//////////////////////////////////////////////////////////////////////////

//Ӧ�ó������
extern CGameClientApp theApp;


//////////////////////////////////////////////////////////////////////////
