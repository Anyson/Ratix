#pragma once

#include "Stdafx.h"
#include "GameClientView.h"

#define	WM_SHOWCHAT					    WM_USER+101					    //��ʾ�Ի���
//////////////////////////////////////////////////////////////////////////
class CGameClientApp;
class CGameView;
//��Ϸ�Ի���
class CGameClientDlg : public CGameFrameDlg
{
public:
	CGameClientView					m_GameClientView;					//��Ϸ��ͼ
	CGameView						*m_pGameView;						//D2D��Ϸ��ͼ
	CGameClientApp					*m_pGameApp;						

	//״̬����
public:
    
	//��������
public:
	//���캯��
	CGameClientDlg();
	//��������
	virtual ~CGameClientDlg();

	//����̳�
private:
	//ϵͳ��Ϣ
	virtual bool __cdecl InsertNoticeMessage(LPCTSTR pszString , BYTE cbType);

	virtual bool SetDlgTitle(){return true;}
	//��ʼ����
	virtual bool InitGameFrame();
	//��ʼ����
	virtual BOOL OnInitDialog();
	//���ÿ��
	virtual void ResetGameFrame();
	//��Ϸ���� �¼�
	virtual void OnGameRuleSet(){};
	//��Ϸ����
	virtual void OnGameOptionSet();
	//ʱ����Ϣ
	virtual bool OnTimerMessage(WORD wChairID, UINT nElapse, UINT nTimerID);
	//�Թ�״̬
	virtual void OnLookonChanged(bool bLookonUser, const void * pBuffer, WORD wDataSize){return;}
	//������Ϣ
	virtual bool OnGameMessage(WORD wSubCmdID, const void * pBuffer, WORD wDataSize);
	//��Ϸ����
	virtual bool OnGameSceneMessage(BYTE cbGameStatus, bool bLookonOther, const void * pBuffer, WORD wDataSize);
	//�رհ�ť
	virtual void OnCancel(); 
	//�Ƿ��������������С
	virtual bool IsSetSound(){return true;};

public:
	//����������
	void	SetGameView(CGameView *pGameView);

	//���ܺ���
	void TimeOutCloseWidget();
	//�����������
	void ShowChat(bool bShow);
	//���ֳ��벻����Ϣ��
	void ShowHintMsg();
	//��Ϣ����
protected:
	//��Ϸ����
	bool OnSubGameEnd(const void * pBuffer, WORD wDataSize);

	//��Ϣӳ��
protected:
	//��ʱ����Ϣ
	afx_msg void OnTimer(UINT nIDEvent);

	//�û��¼�
private:
	//�û�����
	virtual void __cdecl OnEventUserEnter(tagUserData * pUserData, WORD wChairID, bool bLookonUser);
	//�û��뿪
	virtual void __cdecl OnEventUserLeave(tagUserData * pUserData, WORD wChairID, bool bLookonUser);
	//�û�����
	virtual void __cdecl OnEventUserScore(tagUserData * pUserData, WORD wChairID, bool bLookonUser);


	//��������
	LRESULT OnMessageSound(WPARAM wParam, LPARAM lParam);
	//��ʾ�������������
	LRESULT OnMessageShowChat(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

extern HANDLE g_hEventVec;

//////////////////////////////////////////////////////////////////////////
