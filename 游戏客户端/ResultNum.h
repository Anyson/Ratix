#pragma once
#include "Stdafx.h"
#include "widget.h"
#include "WidgetManager.h"

namespace Sexy
{
	class Graphics;
}

class CGameClientApp;
class CGameClientDlg;
class CGameView;

class CResultNum:public Sexy::Widget
{
public:

	void				        Draw(Sexy::Graphics* g);										//���ƺ���	
	
	
	//���÷���					
	void						SetResultNum(LONGLONG lResultNum[GAME_PLAYER], BYTE cbPlayStatus[GAME_PLAYER]);		
	//����״̬
	void						SetNowShow(bool bShow);
	//����ʱ��
	void						AniTimer();	
	//����֡����
	void NumAddFrame();

	CResultNum(void);
	~CResultNum(void);




public:
	//����
 	int							m_ix, m_iy;
 	void						SetPosition(int x , int y);

 	bool						m_bShow;
 	BYTE						m_cbViewStatus[GAME_PLAYER];		//���״̬
 	LONGLONG					m_lResultNum[GAME_PLAYER];			//�������
	int							m_iTrans;							//͸����		
	
	CGameClientApp              *m_pGameApp;
	CGameClientDlg              *m_pGameDlg;                                         
	CGameView                   *m_pGameView;
	
};
