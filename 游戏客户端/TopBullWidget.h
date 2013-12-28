#pragma once
#include "TimerListener.h"
#include "Res.h"
#include "widget.h"
#include "ButtonListener.h"

class CGameClientApp;

namespace Sexy
{
	class Timer;
	class ButtonWidget;
	class Graphics;
};

//����ϵͳ����
class CTopBullWidget :
	public Sexy::Widget, public Sexy::TimerListener, public Sexy::ButtonListener
{
public:
	//��ӹ���
	void AddString(LPCTSTR pszString);


public:
	CTopBullWidget(void);
	~CTopBullWidget(void);

	CGameClientApp *m_pGameApp;

	virtual void Resize(int theX, int theY, int theWidth, int theHeight);
	virtual void Update();									//����
	virtual void Draw(Sexy::Graphics *g);					//��ͼ

	Sexy::Timer		*m_pTimer;
	enum { TIM_BULL_SHOW_ID = 1,  TIM_BULL_HIDE_ID};
	virtual void OnTimer(int nTimerId);						//��ʱ������

	enum { BTN_HIDE_ID = 1};
	virtual void ButtonDepress(int theId);
	void OnBtnHide();										//���ذ�ť��Ӧ

	Sexy::ButtonWidget *m_pBtnHide;							//���ذ�ť
	Sexy::SysFont *m_pFontHei;								//����

	std::vector<std::string> m_strBull;						//��Ϣ����

	wchar_t m_szBullContent[128];							//����



};
