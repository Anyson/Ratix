#pragma once

#include "Stdafx.h"

//////////////////////////////////////////////////////////////////////////
class CGameView;
//��Ϸ��ͼ
class CGameClientView : public CGameFrameViewGDI
{
	//��������
public:
	
	//���캯��
	CGameClientView();
	//��������
	virtual ~CGameClientView();

	CGameView						*m_pGameView;						//d2d������
	CSkinRichEdit					m_ChatMessage;						//�������
	//���ƽӿ�
public:
	//���ý���
	virtual void ResetGameView();

	//�̳к���
protected:
	//�����ؼ�
	virtual void RectifyGameView(INT nWidth, INT nHeight);
	//�滭����
	virtual void DrawGameView(CDC * pDC, INT nWidth, INT nHeight);

	//��Ϣ����
public:
	//��������
	INT OnCreate(LPCREATESTRUCT lpCreateStruct);
	//��Ϣ��ȡ
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()		

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};

//////////////////////////////////////////////////////////////////////////
