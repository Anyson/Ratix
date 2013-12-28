#pragma once
#include "Widget.h"
#include "ButtonListener.h"
#include "ButtonWidget.h"
#include "AnimLayer.h"
#include "DXCard.h"
#include "GameClient.h"
#include "AnimLayerListener.h"

namespace Sexy
{
	class Graphics;
	class Color;
	class ButtonWidget;
	class WidgetManager;
	class Timer;
	class GameTimer;
	class SysFont;
	class AnimLayer;
	class ListWidget;
}

class CGameClientApp;
class CGameClientDlg;
class CGameView;

class CMyBasicInfo:public Sexy::Widget, public Sexy::ButtonListener, public Sexy::AnimLayerListener
{
public:

	void				        Draw(Sexy::Graphics* g);										//���ƺ���	
	
	void						DrawBaseInfo( Sexy::Graphics* g );
	//������λ				
	void						SetMyChair(WORD wMeChair);		
	//����״̬
	void						SetNotShow(bool bShow);
	//��õȼ�����
	WORD						GetUserOrder( LONG lExperience );	
	//��óƺ�
	WORD						GetDescription(LONGLONG lBuffer);
	//����view
	void						SetGameView(CGameView *pGameView);
	CMyBasicInfo(void);
	~CMyBasicInfo(void);
	
	Sexy::ButtonWidget			*m_pBtnAddChip;


public:
	//����
 	int							m_ix, m_iy;
 	void						SetPosition(int x , int y);

	virtual void				ButtonDepress( int theId );

	CGameClientApp              *m_pGameApp;
	CGameClientDlg              *m_pGameDlg;                                         
	CGameView                   *m_pGameView;
	
	WORD						m_wMeChairID;
	Sexy::SysFont				*m_pFont10WeiRuanYaHei;						//10��΢���ź�
	Sexy::SysFont				*m_pFont9WeiRuanYaHei;						//9��΢���ź�
	
};
