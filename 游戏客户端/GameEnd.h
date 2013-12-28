#pragma once
#include "Widget.h"
#include "ButtonListener.h"
#include "AnimLayer.h"
#include "DXCard.h"
#include "GameClient.h"
#include "AnimLayerListener.h"

namespace Sexy
{
    class Graphics;
    class ButtonWidget;
    class WidgetManager;
	class SysFont;
	class AnimLayer;
	class AnimLayerListener;    
}

class CGameClientApp;
class CGameClientDlg;
class CGameView;
class CCard;

enum
{
	BT_CHANGE_DESK=0,
	BT_CONTINUE,
	BT_EXIT
};

class GameEnd:public Sexy::Widget,public Sexy::ButtonListener,public Sexy::AnimLayerListener
{
public:
    GameEnd(void);
    ~GameEnd(void);

    void                Draw(Sexy::Graphics* g);
    void                Update();
    virtual void        MouseDown(int x, int y, int theClickCount);                        //��갴��
    virtual void        MouseDrag(int x, int y);                                           //����϶� 
	virtual void		MouseMove(int x, int y);
    virtual void        MouseUp(int x, int y, int theClickCount);                          //����ɿ�
    virtual void        KeyDown(Sexy::KeyCode theKey);                                     //���̰���
    virtual void        ButtonDepress(int theId);                                          //��ť����
    virtual void        AddedToManager(Sexy::WidgetManager* theWidgetManager);
    virtual void        Resize(int theX, int theY, int theWidth, int theHeight);           //���þ���


	//������Ϣ
protected:
	std::vector<CCard>	m_vecResultCard[GAME_PLAYER];							//ʣ�����
	BYTE				m_cbOX[GAME_PLAYER];									//ţţ��Ϣ



	WORD				m_RemainCardCount[GAME_PLAYER];							//ʣ���˿�����
	LONGLONG			m_EndScore[GAME_PLAYER];								//�������
	LONGLONG			m_EndScoreTemp[GAME_PLAYER];
	WORD				m_wBanker;												//����    
	int					m_wBeiShu;												//����
	WORD				m_wTimerNum;											//ʱ������
    int                 m_iScore;                                               //�����ȼ�����



	//���ܺ���
public:

    static int m_x,m_y;
    static bool m_bCtrlDown;

    void    SetGameView(CGameView *pGameView);
	void	InitWidget();
	//���ý�����
	void	SetGameEndResultCard(std::vector<CCard> result[]);
	//����ţţ��Ϣ
	void	SetOxData(BYTE cbOx[GAME_PLAYER]);

	//���õ���ʱ������
	void	SetTimerNum(WORD wNum);
    bool	SetEndScore(LONG lScore[]);
	void	SetShowScore(bool bShowScore);
    void    ResetPlace();
	//�����ֵķ��� theJustification ���뷽ʽ -1Ϊ����� 0Ϊ���ж���(x��Ϊ����������),1Ϊ�Ҷ���(x��Ϊ���ұߵ�����)
	void	DrawNum2( Sexy::Graphics* g, Sexy::Image *img, LONGLONG iNum, int x, int y, int theJustification /*= 0*/, int iSign /*= 0*/);
	//ʱ�Ӷ���
	void	InitTimerAni();
	void	InitResultAni(bool bWin);

private:
    CGameClientApp              *m_pGameApp;
    CGameClientDlg              *m_pGameDlg;
    CGameView                   *m_pGameView;
	bool						m_bLeftDown;
	bool						m_bShowEndScore;

	Sexy::ButtonWidget			*m_pBtnExit;													//�˳���ť
	Sexy::ButtonWidget			*m_pBtnChangeDesk;												//������ť
	Sexy::ButtonWidget			*m_pBtnContinue;												//������ť

	//����
	Sexy::SysFont				*m_pFont10WeiRuanYaHei;											//10��΢���ź�
	Sexy::AnimLayer				*m_pTimerAni;													//ʱ�䶯��

};
