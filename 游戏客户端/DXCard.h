#pragma once
#include "Stdafx.h"
#include "widget.h"
#include "WidgetManager.h"



#pragma   warning(disable:4305)

#ifndef PI
#define PI 3.1415926535
#endif
//����
#define		CARD_V_WIDTH		36
#define		CARD_V_HEIGHT		50
//#define		MAX_FRAME			6
#define		CENTER_FRAME		1
#define		GIVEUPFRAME			8

namespace Sexy
{
	class Graphics;
}

class CGameClientApp;
class CGameClientDlg;
class CGameView;

//�ص��ӿ���
class CardCallback
{
public:
	//virtual void OnMoveOneStart(int id) = NULL;		//���ƿ�ʼ(��Ҫ�������ŷ�������)
	virtual void OnMoveFinish(int id) = NULL;			//�������
	//virtual void OnHideFinish(int id) = NULL;			//���������
	//virtual void OnFlyFinish(int id) = NULL;			//���������Ѿ��ɵ��ɹ���ǰ
};


class CCard
{
public:
	CCard(void);
	CCard(char cCard);
	~CCard(void);
public:
	int                         GetType();
	int                         GetVaule();
	void                        SetCard(char cCard);
	void                        SetSelect(bool bSelect);
	bool                        IsSelect();
	void                        SetMouseSelect(bool bSelect);
	bool                        IsMouseSelect();
	void                        SetCardPos(int x,int y);
	BYTE                        GetCard(){return m_cCard;}
	void                        SetMark(int iMark);
	int                         GetMark(){return m_iMark;}    

public:
	BYTE                        m_cCard;           //��
	bool                        m_bSelect;         //�Ƿ�ѡ��
	bool                        m_bMouseSelect;    //���ѡ��
	int                         m_iMark;           //Ĭ��0,����1,�ع�2
	int                         m_CardX;		   //�Ƶ�λ��
	int                         m_CardY;   
	int							m_iNowFrame;		//��ǰ֡��
	int							m_iTotalFrame;		//��֡��
};

class CGameCard:public Sexy::Widget
{
public:
	CGameCard(void);
	~CGameCard();

	void				        Draw(Sexy::Graphics* g);										//���ƺ���
	void                        DrawMeCard(Sexy::Graphics* g);                                  //���Լ�����
	void                        DrawOtherCard(Sexy::Graphics* g);                               //�������˵���
	virtual void				MouseMove(int x, int y);										//����ƶ�
	virtual void				MouseDrag(int x, int y);										//�����ק
	virtual void				MouseDown(int x, int y, int theClickCount);		                //��갴��
	virtual void	            MouseUp(int x, int y, int theClickCount);	                    //���̧��
	void                        SetGameView(CGameView *pGameView);

	DWORD                       SetCardData(std::vector<CCard> &Card,const BYTE bCardData[], DWORD dwCardCount);    //������
	//��ʼ����
	DWORD						InitCardData(WORD wViewChair,const BYTE bCardData[], DWORD dwCardCount); 
	//��������
	void						Reset();
	//����ʱ��
	void						AniTimer();	
	//����֡����
	bool						CardAddFrame(int id);
	//���ûص��ӿ�
	void						setCallBack(CardCallback * pCallBack);
	//���÷��ƶ���
	void						InitSendCardAni(int id);
	//�Ƿ�ȫ���ƶ�����
	bool                        IsAllFinish();
	//����̯��
	void						SetOutCard(int iIndex, BYTE cbOutCard[]);
	//�ѳ��Լ�����
	void						RemoveMyAllCard();
	//���ý����˿�
	void						SetResultCardData();
	//����ʧ����֡����
	void						CardDisAppearFrame();			
	//��������ʧ��������
	void						SetCardDisAppear(bool bDis);					

	void                        RemoveHandCardDate(BYTE bCardData[]);                           //ȥ������
	bool                        SetShootCard(const BYTE bCardData[], DWORD dwCardCount);
	void                        SetHandCardShoot(BYTE bCardData[],WORD wCardCount);             //�����Լ����Ƶ���
	int                         GetHandCardShoot(BYTE bCardData[]);                             //��õ��������
	void                        SetPayTruibuteShoot( BYTE bCardData,WORD wCardCount );

	WORD                        GetOutCard( CCard cbCardData[], WORD wBufferCount );
	//���ó���
	bool	                    SetOutCardData(const BYTE cbOutCardData[], WORD wOutCardCount,WORD wViewChairID,WORD wOutCardShowCount=0);
	void                        SetHandAllShoot(bool bSelect);                                   //�������е����Ƿ���

	static void					DrawTextString(Sexy::Graphics* g, const SexyString& theString, int theX, int theY, int iWidth,int itheJustification, Sexy::Color crText, Sexy::Color crFrame);

	std::vector<CCard>          m_vecHandCard[GAME_PLAYER];                                                  //�Լ�������
	std::vector<CCard>          m_vecFaceCard;                                                  //�Լҵ�����
	std::vector<CCard>          m_vecSendCard[GAME_PLAYER];                                     //������
	std::vector<CCard>			m_vecSendCard2[GAME_PLAYER];									//������2
	std::vector<CCard>			m_vecResultCard[GAME_PLAYER];									//�����˿�
						

	WORD						m_cbOtherHandCard[GAME_PLAYER];						            //�����˵�����
	

	int							m_iTransNow[MAX_COUNT];						//��ǰ͸����ֵ
	bool			            mLeftDown;
	bool			            mRightDown;
	bool			            mMiddleDown;
	int				            mMouseX, mMouseY;
	int				            mMouseDownX, mMouseDownY;
	CardCallback				*m_pCallBack;
	bool						m_bSendCard;
	bool						m_bShow;									//�Ƿ���ʾ��ʼ����
	int							m_iDisTrans;								//����ʧ����͸����
	bool						m_bDisappear;								//����ʧ��������
private:
	CGameClientApp              *m_pGameApp;
	CGameClientDlg              *m_pGameDlg;                                         
	CGameView                   *m_pGameView;
	CGameLogic					*m_GameLogic;

	Sexy::SysFont				*m_pFont10WeiRuanYaHei;											//10��΢���ź�
	
	//test
	int							m_iCardx;
	int							m_iCardy;
public:
	void						SetPos(int x, int y);

	virtual	void				Update();

};
