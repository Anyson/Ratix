#include "Stdafx.h"
#include "GameView.h"
#include "GameClient.h"
#include "GameClientDlg.h"
#include "SoundPlayer.h"

//////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CGameClientDlg, CGameFrameDlg)
	ON_WM_TIMER()
	ON_MESSAGE(WM_USER+808,OnMessageSound)
	ON_MESSAGE(WM_USER+200,OnMessageShowChat)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////
//���캯��
CGameClientDlg::CGameClientDlg() : CGameFrameDlg(&m_GameClientView)
{
	//������Ϣ
	m_pGameApp = (CGameClientApp *)AfxGetApp();
	m_pGameView = NULL;
	ResetGameFrame();
	return;
}

//��������
CGameClientDlg::~CGameClientDlg()
{

}

//��ʼ����
bool CGameClientDlg::InitGameFrame()
{
	//���ñ���
	SetWindowText(TEXT("ͨ��ţţ"));
	HideGameRight();

	//����ͼ��
	HICON hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	SetIcon(hIcon,TRUE);
	SetIcon(hIcon,FALSE);

	return true;
}

//��ʼ����
BOOL CGameClientDlg::OnInitDialog()
{
	__super::OnInitDialog();
	SetWindowPos(NULL,0,0,1015+10,727+30,SWP_NOZORDER|SWP_NOMOVE);
	m_MessageProxyHelper->SetRichEditHwnd(&m_GameClientView.m_ChatMessage);
	return TRUE;
}

//���ÿ��
void CGameClientDlg::ResetGameFrame()
{	
	return;
}

//��Ϸ����
void CGameClientDlg::OnGameOptionSet()
{
	return;
}

//ʱ����Ϣ
bool CGameClientDlg::OnTimerMessage(WORD wChairID, UINT nElapse, UINT nTimerID)
{
	return false;
}

//������Ϣ
bool CGameClientDlg::OnGameMessage(WORD wSubCmdID, const void * pBuffer, WORD wDataSize)
{
	m_pGameApp->PostNetMessage(wSubCmdID, pBuffer, wDataSize);
	if(wSubCmdID == SUB_S_GAME_END)
	{
		ASSERT(wDataSize == sizeof(CMD_S_GameEnd));
		if(wDataSize!=sizeof(CMD_S_GameEnd)) return false;
		SetGameStatus(GS_OX_ACCOUNTS);
		CMD_S_GameEnd * pGameEnd = (CMD_S_GameEnd *)pBuffer;
		TCHAR wChar[50];
		if (pGameEnd->lGameScore[GetMeChairID()] >= 0)
		{
			_sntprintf(wChar,CountArray(wChar),TEXT("���ֻ�ó���%d\n"), pGameEnd->lGameScore[GetMeChairID()]);
		}
		else
		{
			_sntprintf(wChar,CountArray(wChar),TEXT("�����������%d\n"), pGameEnd->lGameScore[GetMeChairID()]);
		}

		TCHAR wChar2[50];
		_sntprintf(wChar2,CountArray(wChar2),TEXT("���ֿ۳������%d\n"), -pGameEnd->lDeskPay);

		//_log("RatioxLog", "�����ַ���begin");

		m_GameClientView.m_ChatMessage.InsertString(wChar, RGB(255,255,255));
		m_GameClientView.m_ChatMessage.InsertString(wChar2, RGB(255,255,255));
		//_log("RatioxLog", "�����ַ���end");

		return true;
	}
	else if(wSubCmdID == SUB_S_SEND_BOWL)
	{
		//Ч������
		ASSERT(wDataSize==sizeof(CMD_S_Send_Bowl));
		if (wDataSize!=sizeof(CMD_S_Send_Bowl)) return false;
		CMD_S_Send_Bowl* pSendBowl = (CMD_S_Send_Bowl*)pBuffer;
		TCHAR wChar[50];
		_sntprintf(wChar,CountArray(wChar),TEXT("��ϲ���ϲ��%dԪ��!\n"), pSendBowl->lNewIngot);
		m_GameClientView.m_ChatMessage.InsertString(wChar, RGB(186,167,58));

		return true;
	}


	return true;
}

//��Ϸ����
bool CGameClientDlg::OnGameSceneMessage(BYTE cbGameStation, bool bLookonOther, const void * pBuffer, WORD wDataSize)
{
	switch(cbGameStation)
	{
	case  GS_OX_FREE:
		{
			m_pGameApp->PostNetMessage(GS_OX_FREE, pBuffer, wDataSize);

			break;
		}
	case  GS_OX_PLAY:
		{
			m_pGameApp->PostNetMessage(GS_OX_PLAY, pBuffer, wDataSize);
			break;
		}
	case GS_OX_ACCOUNTS:
		{
			m_pGameApp->PostNetMessage(GS_OX_ACCOUNTS, pBuffer, wDataSize);
			break;
		}
	}
	return true;
}


//��ʱ����Ϣ
void CGameClientDlg::OnTimer(UINT nIDEvent)
{
	if (1000 == nIDEvent)
	{
		static int iCount = 0;
		//printf("��ʱ��[%d]\n", iCount++);
	}
}


//��Ϸ����
bool CGameClientDlg::OnSubGameEnd(const void * pBuffer, WORD wDataSize)
{
	//Ч������
	ASSERT(wDataSize==sizeof(CMD_S_GameEnd));
	if (wDataSize!=sizeof(CMD_S_GameEnd)) return false;
	ResetGameFrame();
	return true;
}


void CGameClientDlg::OnCancel()
{
	CGameFrameDlg::OnCancel();
}

void CGameClientDlg::SetGameView( CGameView *pGameView )
{
	m_pGameView = pGameView;
	m_GameClientView.m_pGameView = m_pGameView;
	::PostMessage(m_GameClientView.GetSafeHwnd(), WM_SHOWCHAT, 0, 0);
	m_pGameApp->m_pSoundPlayer->EnableSound(IsEnableSound());
	m_pGameApp->m_pSoundPlayer->PlayMusic(0);
}

//////////////////////////////////////////////////////////////////////////

void CGameClientDlg::OnDestroy()
{
	m_pGameApp->DestroyGameView();
	CGameFrameDlg::OnDestroy();
	// TODO: �ڴ˴������Ϣ����������
}


void __cdecl CGameClientDlg::OnEventUserEnter( tagUserData * pUserData, WORD wChairID, bool bLookonUser )
{
	while (m_pGameView == NULL)
	{
		Sleep(50);
	}
	WORD wChair = SwitchViewChairID(wChairID);
	m_pGameView->OnUserEnter(pUserData,wChair,bLookonUser);
	
}

void __cdecl CGameClientDlg::OnEventUserLeave( tagUserData * pUserData, WORD wChairID, bool bLookonUser )
{

}

void __cdecl CGameClientDlg::OnEventUserScore( tagUserData * pUserData, WORD wChairID, bool bLookonUser )
{

}




LRESULT CGameClientDlg::OnMessageSound( WPARAM wParam, LPARAM lParam )
{
	if (wParam != NULL)
	{
		m_pGameApp->m_pSoundPlayer->SetSongVolume( (const AppInfoDef*)wParam , (int)lParam);
	}
	else
	{
		m_pGameApp->m_pSoundPlayer->EnableSound(IsEnableSound());
	}
	return 0;
}

bool CGameClientDlg::InsertNoticeMessage( LPCTSTR pszString , BYTE cbType )
{
	if (m_pGameView != NULL)
	{
		m_pGameView->AddBull(pszString);
	}
	return true;
}

void CGameClientDlg::TimeOutCloseWidget()
{
	//���͹رմ�����Ϣ 
	m_ClientKernelHelper->SendProcessData(IPC_MAIN_CONCTROL,IPC_SUB_TIME_OUT);
	PostMessage(WM_CLOSE);
}

void CGameClientDlg::ShowChat( bool bShow )
{
	if (bShow)
	{
		/*if(m_GameClientView.m_ChatMessage.IsWindowVisible())*/
			m_GameClientView.m_ChatMessage.ShowWindow(SW_HIDE);
	}
	else
	{
		/*if(!m_GameClientView.m_ChatMessage.IsWindowVisible())*/
			m_GameClientView.m_ChatMessage.ShowWindow(SW_SHOW);
	}
}

void CGameClientDlg::ShowHintMsg()
{

}

LRESULT CGameClientDlg::OnMessageShowChat( WPARAM wParam, LPARAM lParam )
{
	if(wParam >0)
	{
		m_GameClientView.m_ChatMessage.ShowWindow(SW_SHOW);
	}
	else
	{
		m_GameClientView.m_ChatMessage.ShowWindow(SW_HIDE);
	}
	return 0;
}

