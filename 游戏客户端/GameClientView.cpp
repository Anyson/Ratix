#include "StdAfx.h"
#include "GameClient.h"
#include "GameClientView.h"
#include "GameClientDlg.h"
#include "SexyAppBase.h"



BEGIN_MESSAGE_MAP(CGameClientView, CGameFrameViewGDI)
	ON_WM_CREATE()
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()

//���캯��
CGameClientView::CGameClientView()
{
	m_pGameView = NULL;
	return;
}

//��������
CGameClientView::~CGameClientView()
{
}

//���ý���
void CGameClientView::ResetGameView()
{
	return ;
}

//�����ؼ�
VOID CGameClientView::RectifyGameView(INT nWidth, INT nHeight)
{
	 m_ChatMessage.MoveWindow(CRect(821,598,1007,677));
	return;
}

//�滭����
VOID CGameClientView::DrawGameView(CDC * pDC, INT nWidth, INT nHeight)
{
	return;
}

//��������
INT CGameClientView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct)==-1) return -1;
	//���ô���
	CGameClientDlg *pGameClientDlg=CONTAINING_RECORD(this,CGameClientDlg,m_GameClientView);


	m_ChatMessage.Create(WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOVSCROLL ,CRect(0,0,0,0) , this , 1);
	m_ChatMessage.SetBackgroundColor(FALSE,RGB(27,9,0));
	//SetWindowLong(m_ChatMessage.m_hWnd, GWL_EXSTYLE, GetWindowLong(m_ChatMessage.m_hWnd,GWL_EXSTYLE)|WS_EX_TRANSPARENT); 

	CHARFORMAT cf;
	m_ChatMessage.GetSelectionCharFormat(cf);
	cf.dwEffects&=~CFE_BOLD;//���ô��壬ȡ����cf.dwEffects&=~CFE_BOLD;
	cf.crTextColor = RGB(255,255,255);//������ɫ
	cf.dwMask|=CFM_SIZE;
	cf.yHeight =180;//���ø߶�
	cf.dwMask|=CFM_FACE;
	strcpy(cf.szFaceName ,_T("����"));//��������

	m_ChatMessage.SetDefaultCharFormat(cf);
	m_ChatMessage.SetReadOnly(true);
	m_ChatMessage.HideSelection(TRUE , true);
	m_ChatMessage.ShowWindow(SW_HIDE);

	return 0;
}



//��Ϣ��ȡ
BOOL CGameClientView::PreTranslateMessage(MSG * pMsg)
{
	return FALSE;
	if (pMsg->message == WM_KEYDOWN)
	{
		
		int i=0;
	}
	return __super::PreTranslateMessage(pMsg);
}

LRESULT CGameClientView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (message == WM_SHOWCHAT)
	{
		m_ChatMessage.ShowWindow(SW_SHOW);
	}
	return CGameFrameViewGDI::WindowProc(message, wParam, lParam);
}

void CGameClientView::OnKillFocus(CWnd* pNewWnd)
{
	CGameFrameViewGDI::OnKillFocus(pNewWnd);
	//SetFocus();
	// TODO: �ڴ˴������Ϣ����������
}
