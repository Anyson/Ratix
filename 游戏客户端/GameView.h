#pragma once
#include "Widget.h"
#include "ButtonListener.h"
#include "TimerListener.h"
#include "ListListener.h"
#include "AnimLayer.h"
#include "GameTimerListener.h"
#include "AnimLayerListener.h"
#include "Player.h"
#include "Chip.h"
#include "DXCard.h"
#include "GameEnd.h"
#include "ResultNum.h"
#include "ListWidget.h"
#include "MyBasicInfo.h"

//��������
#define						   MAX_DOUBLEHEAP_COUNT					32		//��ʼ������
#define						   DOUBLE_COUNT							2		//һ���Ƹ���


//��ť��ʶ
enum
{
	BT_EXCHANGECHIP_SPACE1 = 0,
	BT_EXCHANGECHIP_SPACE2,
	BT_EXCHANGECHIP_SPACE3,
	BT_EXCHANGECHIP_SPACE4,
	BT_EXCHANGECHIP_SPACE5,

	BT_OPEN_CARD,			//̯��
	BT_HINT_CARD,			//��ʾ
	BT_RELIST_CARD,			//����
	BT_ADD_CHIP,			//�������
	BT_CUI_PAI,				//����
	BT_TUOGUAN,				//�й�
	BT_CANCEL_TUOGUAN,		//ȡ���й�
};
namespace Sexy
{
	class Graphics;
	class Color;
	class ButtonWidget;
	class Timer;
	class GameTimer;
	class SysFont;
	class AnimLayer;
	class ListWidget;
}


class CGameClientApp;
class CGameClientDlg;
class CTopBullWidget;

class CGameView : public Sexy::Widget, public Sexy::ButtonListener, public Sexy::ListListener,public Sexy::TimerListener, public Sexy::AnimLayerListener,
	public Sexy::GameTimerListener,public ChipCallback,public CardCallback
	
{
public:
	CGameView(void);
	~CGameView(void);
	virtual void				Draw(Sexy::Graphics* g);										//���ƺ���
	virtual void				Update();														//ˢ�º���
	virtual void				MouseLeave();													//����뿪
	virtual void				MouseEnter();													//������
	virtual void				MouseMove(int x, int y);										//����ƶ�
	virtual void				MouseDrag(int x, int y);										//�����ק
	virtual void				MouseDown(int x, int y, int theBtnNum, int theClickCount);		//��갴��
	virtual void				ButtonDepress(int theId);										//��ţ̌��
	virtual	void				KeyDown(Sexy::KeyCode theKey);									//������Ϣ
	virtual void				Resize(int theX, int theY, int theWidth, int theHeight);		//��С�ı�

	int	m_x,m_y,m_index,iAciton, iActor;			//����������

	void						OnAniFinish(int id);											//�����ص�	

	//��������
public:
	void						InitWidget();													//��ʼ��Widget
	void						AddBull(LPCTSTR pszString);										//��ӹ���
	//��������
	void						ResetGameFrame();
	
	//�������ź���
public:
	//���ŵȴ�����
	void						ShowWaitAni();									
	//�����Զ���������
	void						ShowAutoDeskAni(bool bShow=true);									
	//��ʼ������Ӯ�ֶ���
	void						ShowMoneyAni(LONGLONG lScore[]);
	//���ƺ���
private:
	//�������ֵķ��� theJustification ���뷽ʽ -1Ϊ����� 0Ϊ���ж���(x��Ϊ����������),1Ϊ�Ҷ���(x��Ϊ���ұߵ�����)
	static void					DrawNum1(Sexy::Graphics* g, Sexy::Image *img, LONGLONG iNum, int x, int y, int theJustification = 0);
	static void 				DrawTextString(Sexy::Graphics* g, const SexyString& theString, int theX, int theY, int iWidth,int itheJustification, Sexy::Color crText, Sexy::Color crFrame);;
	
	//�Զ�����ƺ���
	void						DrawBg(Sexy::Graphics* g);										//������
	void						DrawBaseInfo(Sexy::Graphics* g);								//����Ϣ���Լ���Ϣ�����������Ϣ��
	void						DrawPlayer(Sexy::Graphics* g);									//�����
	//������
	void						DrawTest(Sexy::Graphics* g);
	//����׼��
	void                        DrawReady(Sexy::Graphics* g);
	//���������
	void						DrawDeskChip(Sexy::Graphics* g);
	//��Ѻע����
	void						DrawAddScore(Sexy::Graphics *g);
	//�����ƽ׶θ��˵�����
	void						DrawOxType(Sexy::Graphics *g);
	//���һ������
	void						DrawExChangeChipDlg(Sexy::Graphics *g);
	//������
	void						DrawUcCard(Sexy::Graphics *g);
	//�����������Ϣ��			
	void						DrawOtherInfo(Sexy::Graphics *g);
	//��̯��״̬
	void						DrawOpenCard(Sexy::Graphics *g);						
	//���۱�����Ϣ
	void						DrawBuffer(Sexy::Graphics *g);
	//��ϲ����
	void						DrawReward(Sexy::Graphics *g);
	//��ϲ������ʾ
	void						DrawRewardHint(Sexy::Graphics *g);



	void						DrawAni(Sexy::Graphics* g);										//������			

public:
	void						RemoveAllAni();

public:
	void						OnGameMessage(WPARAM wParam, LPARAM lParam);					//������Ϣ
	//������Ϣ����
	virtual	bool				OnGameMessage(WORD wSubCmdID, const void * pBuffer, WORD wDataSize);
	//��Ϸ׼����ʼ
	bool                        OnSubGameReady(const void * pBuffer, WORD wDataSize);
	//��Ϸ��ʼ
	bool                        OnSubGameStart(const void * pBuffer, WORD wDataSize);
	//��Ϸ����
	bool						OnSubGameEnd(const void * pBuffer, WORD wDataSize);
	//��Ϸȫ������
	bool						OnSubGameAllFinish(const void * pBuffer, WORD wDataSize);
	//������Ϣ����
	bool						OnSubHurryCard(const void * pBuffer, WORD wDataSize);
	//̯����Ϣ����
	bool						OnSubOpenCard(const void * pBuffer, WORD wDataSize);
	//��Ϸ����
	bool						OnSubGameFree(const void * pBuffer, WORD wDataSize);
	//�۱�����Ϣ����
	bool						OnSubBowl(const void * pBuffer, WORD wDataSize);

	//��������
public:
	//�һ����� 
	void						OnExChip(UINT nIDEvent);
	//��ʾ�һ������
	void						ShowExChip(bool bShow = false);
	//��õȼ�����
	WORD						GetUserOrder( LONG lExperience );	
	//��óƺ�����
	WORD						GetDescription( LONGLONG lBuffer );	
	//��óƺ���ɫ����
	WORD						GetDesColor(WORD wIndex);
	//ʱ�Ӳ���
	void						OperaTimer(UINT nTimerID, UINT nElapse ,WORD wChair, BOOL bStart=true);
	//���ƽ���
	void						OnSendCardFinish();
	//��ʾ��ť��Ӧ
	void						OnBtnHintCard();
	//̯�ư�ť��Ӧ
	void						OnBtnOpenCard();
	//���Ű�ť��Ӧ
	void						OnBtnReListCard();
	//�������Ͷ���
	void						ShowCardAni(BYTE cbCardType, WORD wViewChair);
	//��ʾ���ƿ�
	void						ShowUcCardDlg(bool bShow = false);
	//������Ϣ
	void						OnUcCard(int iIndex);
	//�û�������Ϣ				
	void						OnUserEnter(tagUserData * pUserData, WORD wViewChairID, bool bLookonUser);
	//�ƶ���ť	
	void						MoveButton(int iBtnTag, int iUp);
	//׼�����¼�
	void						AfterReady();
	//����ϲ��Ԫ����ͼƬ
	void						MakeLikeIngotImg();
	
	//��������-------------------------------------------------------------------
	void						ControlCardData();
	
	Sexy::ButtonWidget			*m_pBtnTuoGuan;													//�йܰ�ť
	//Sexy::ButtonWidget			*m_pBtnAddChip;													//�������
private:
	CGameClientApp				*m_pGameApp;													//��ʼ����
	CGameClientDlg				*m_pGameDlg;													//���߼�������
	Sexy::Timer					*m_pTimer;														//��ʱ����	
	Sexy::GameTimer				*m_pGameTimer;													//��ʱ����	
	CGameLogic					*m_pGameLogic;													//��Ϸ�߼�
	DXChip						m_pChip;
	
	
	virtual		void            OnTimer(int id, WORD wChairID, UINT nElapse);					//��ʱ���ص�����
	virtual		void			OnTimer(int id);												//��ʱ���ص�����

	virtual		void			OnYaDiFinish();

	virtual		void			OnMoveFinish( int id );

	virtual		void			DrawOverlay( Sexy::Graphics* g, int thePriority );

	virtual		void			ListClicked( int theId, int theIdx, int theClickCount );

private:
	Sexy::Point					m_ptMouse;														//�������
	CTopBullWidget				*m_pTopBullWidget;												//��������

	//����
	Sexy::SysFont				*m_pFont10Song;													//10������
	Sexy::SysFont				*m_pFont10Hei;													//10������
	
	//��ť����
	Sexy::ButtonWidget			*m_pBtnExChip[MAX_CHIP_COUNT];													//Ѻע��ť
// 	Sexy::ButtonWidget			*m_pBtnExChip2;													//Ѻע��ť
// 	Sexy::ButtonWidget			*m_pBtnExChip3;													//Ѻע��ť
// 	Sexy::ButtonWidget			*m_pBtnExChip4;													//Ѻע��ť
	Sexy::ButtonWidget			*m_pBtnOpenCard;												//̯�ư�ť
	Sexy::ButtonWidget			*m_pBtnHintCard;												//��ʾ
	Sexy::ButtonWidget			*m_pBtnReListCard;												//����
	Sexy::ButtonWidget			*m_pBtnQuickSub;												//���ٺ���
	
	Sexy::ButtonWidget			*m_pBtnCancelTuoGuan;											//ȡ���й�
	

	Sexy::ButtonWidget			*m_pBtnTest;													//���԰�ť

	//��������
	Sexy::AnimLayer             *m_pDiceAni0;													//���Ӷ���1
	Sexy::AnimLayer				*m_pDiceAni1;													//���Ӷ���2
	/*Sexy::AnimLayer				*m_pCardAppearAni[MAX_DOUBLEHEAP_COUNT];						//�Ƴ��ֶ���*/
	Player						*m_pPlayer[GAME_PLAYER];
	Sexy::AnimLayer				*m_pOxAni[11];													//���Ͷ���
	Sexy::AnimLayer				*m_pAddMoneyAni[GAME_PLAYER];				//��Ǯ����
	Sexy::AnimLayer				*m_pWaitOtherAni;							//�ȴ�������Ҷ���
	Sexy::AnimLayer				*m_pAutoDeskAni;							//�Զ���������
	Sexy::AnimLayer				*m_pLikeIngotAni;							//ϲ�𶯻�
	Sexy::AnimLayer				*m_pOffLineAni[GAME_PLAYER];				//���߶���
// 	Sexy::AnimLayer				*m_pJackocur;								//����·������
// 	Sexy::AnimLayer				*m_pJackpotwin;								//�۱��趯��
	Sexy::AnimLayer				*m_pTuoGuanAni;
	//���渨������
protected:
	bool							m_bShowExChangeChipDlg;					//�Ƿ���ʾ�һ������
	bool							m_bGetMsg;								//��������������Ϣ
	bool							m_bOpenCard[GAME_PLAYER];				//�Ƿ�̯��
	GameEnd							*m_pGameEnd;							//������ͼ
	bool							m_bAddScore;							//�Ƿ�Ѻע
	bool							m_bShowOxType;							//��ʾ��������
	bool							m_bShowUcCard;							//��ʾ���ƿ�
	//��Ϸ����
public:
	WORD							m_wMeChairID;								//�Լ���ʵ������
	int								m_iMyFaceIndex;								//�Լ�ͷ������
	WORD							m_wTimeNum;
	BYTE							m_cbPalyStatus[GAME_PLAYER];			//�����Ϸ״̬
	BYTE							m_cbHandCard[GAME_PLAYER][MAX_COUNT];	//�������
	BYTE							m_cbRewardCard[GAME_PLAYER][MAX_COUNT];	//ϲ����
	BYTE							m_cbCardType[GAME_PLAYER];				//�������
	CResultNum						*m_pResultNum;							//�������
	CMyBasicInfo					*m_pMyBasicInfo;						//�ҵ���Ϣ
	Sexy::DDImage					*m_pLikeIngotImg[4];					//ϲ�𷢷���Ŀ��ת����ͼƬ


	CGameCard						m_GameCard;								//��
	CPoint							m_cpTimer;								//ʱ��λ��
	bool							m_bTrustee;								//�Ƿ��й�

	LONG							m_lBowl;								//�۱���
	LONG							m_lLikeIngot;							//ϲ��

	bool							m_bMouseSelect[GAME_PLAYER];			//���ѡ�����]
	int								m_iOtherInfoTrans[GAME_PLAYER];			//�����Ϣ��͸����
	int								m_iOtherInfofPos[GAME_PLAYER][3];

	Sexy::ListWidget				*m_pListUcCard;							//�����б�
	WORD						    m_wHurryCardUser;						//�������
	WORD						    m_wHurryWordID;							//�����������ID

	LONGLONG						m_lCellScore;							//��λ����
	LONGLONG						m_lMinbet;								//��С��ע
	LONGLONG						m_lUserAddScore[GAME_PLAYER];			//�����ע
	LONGLONG						m_lChipNum[MAX_CHIP_COUNT];				//��������
	LONG							m_lNewLikeIngot[4];
	LONG							m_lPercentage[MAX_CHIP_COUNT];			//����ѱ���
	WORD							m_wServerType;							//����������
	bool							m_bShowBowlHint;						//�Ƿ���ʾ�۱�����ʾ
	bool							m_bShowLikeIngotHint;
	bool							m_bShowRewardCard;						//�Ƿ���ʾϲ����
	CPoint							m_cpRewardCard;
	bool							m_bShowSameTag[MAX_COUNT];							//��ʾϲ������ͬ
	int								m_iTransBowlHint;						//�۱�����ʾ͸����
	int								m_iTransLikeIngotHing;					//ϲ����ʾ
	

	//����
protected:
	Sexy::SysFont					*m_pFont10WeiRuanYaHei;					//10��΢���ź�
	Sexy::SysFont					*m_pFont9WeiRuanYaHei;					//9��΢���ź�
	Sexy::SysFont					*m_pFont9HeiTi;							//9�ź���
};
