#pragma once
#include "Stdafx.h"
#include "widget.h"
#include "WidgetManager.h"
#include "GameClient.h"
#include "AnimLayer.h"

#pragma   warning(disable:4305)

#ifndef PI
#define PI 3.1415926535
#endif
	
enum ChipType
{
	CHIP_100 = 0,
	CHIP_1000,
	CHIP_5000,
	CHIP_10000,

	MAX_CHIP_TYPE
};

enum enDirection
{
	d_x,
	d_y
};

struct ChipInfo
{
	ChipType	type;				//��������
	CPoint		ptNow;				//��ǰ����
	CPoint		ptBegin;			//�������
	CPoint		ptEnd;				//�յ�����
	bool		bFly;				//�Ƿ��ڷ�
	WORD		wFrameNow;			//��ǰ֡��
	WORD		wTotalFrame;		//��֡
	bool		bCollection;		//�Ƿ��ռ�
	WORD		wWinnerID;			//
	INT			iIndex;				//����
	bool		bAddSpeed;			//����
};


struct Shadow
{
	bool		bShow;
	CPoint		ptNow;				//��ǰ����
	CPoint		ptBegin;			//�������
	CPoint		ptEnd;				//�յ�����
	bool		bFly;				//�Ƿ��ڷ�
	WORD		wFrameNow;			//��ǰ֡��
	WORD		wTotalFrame;		//��֡
};

//�ص��ӿ���
class ChipCallback
{
public:
	virtual void OnYaDiFinish() = NULL;		//���ƿ�ʼ(��Ҫ�������ŷ�������)
};

//������
class DXChip:public Sexy::Widget
{
public:
	DXChip(void);
	~DXChip(void);

	//����
	void setPos(int x, int y);
	//���ƺ���
public:
	//������
	void Draw( Sexy::Graphics* g );
	//�����������
	void DrawDeskChip1(Sexy::Graphics* g, WORD index, LONGLONG lScrapChip);				
private:
	


public:
	LONGLONG GetChipScore(ChipType type);

	//�ƶ���������
	float GetInitSpeed(ChipInfo chipInfo , enDirection EnDirection);
	float GetAddSpeed(ChipInfo chipInfo , enDirection EnDirection);
	float GetCoordinate(ChipInfo chipInfo , enDirection EnDirection);

	//���ܺ���
	//��ע
	void AddChips(LONGLONG lTotalPoint, int iPos , bool bAllIn=false);	
	//����
	void Reset();
	//���ûص�����
	void SetCallBack(ChipCallback * pCallBack);
	//����仯ʱ��
	void AniTimer();
	//����λ��
	void ChipAddFrame(ChipInfo& chipinfo,float fAngle=0);

	virtual void Update();

	Sexy::Image							*m_BigChipImg[4];
	Sexy::Image							*m_SmallChipImg[4];
	//����λ�ñ���
	BYTE								m_cbDeskHeapCount[5][4];				//ÿ�ѵ����
	CPoint								m_ptDesk[GAME_PLAYER][MAX_CHIP_TYPE];	//ÿ����������������λ��
	BYTE								m_iAddChipKind1[5][2];
	BYTE								m_iAddChipKind2[5][2];
	CPoint								m_ptBegin[GAME_PLAYER];					//ÿ����ҳ������ʼλ��
	CPoint								m_ptEnd[GAME_PLAYER];					//ÿ����ҳ�������λ��
	std::vector<Sexy::AnimLayer*>		m_vecChipAni;							//���붯��	
	// 	//�������
	std::vector<ChipInfo>				m_vecChip[GAME_PLAYER];					//���г���
	Shadow								m_Shadow[GAME_PLAYER][2];

	CGameClientApp						*m_pGameApp;
	CGameClientDlg						*m_pGameDlg;                                         
	CGameView							*m_pGameView;
private:
	int									m_ix;
	int									m_iy;
	ChipCallback						*m_pCallback;
	bool								m_bMoveFinish;

};

