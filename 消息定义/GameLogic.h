#ifndef GAME_LOGIC_HEAD_FILE
#define GAME_LOGIC_HEAD_FILE

#pragma once

#include "stdafx.h"
//#include "..\..\ģ���\Template.h"
//////////////////////////////////////////////////////////////////////////
//�궨��

#define MAX_COUNT					5									//�����Ŀ

//��ֵ����
#define	LOGIC_MASK_COLOR			0xF0								//��ɫ����
#define	LOGIC_MASK_VALUE			0x0F								//��ֵ����

//�˿�����
#define OX_VALUE0					0									//�������
#define OX_GOLD						11									//��ţ
#define OX_DOUBLE_JOKE				12									//˫��ţ

#define CARD_COUNT					54

//////////////////////////////////////////////////////////////////////////

//�����ṹ
struct tagAnalyseResult
{
	BYTE 							cbFourCount;						//������Ŀ
	BYTE 							cbThreeCount;						//������Ŀ
	BYTE 							cbDoubleCount;						//������Ŀ
	BYTE							cbSignedCount;						//������Ŀ
	BYTE 							cbFourLogicVolue[1];				//�����б�
	BYTE 							cbThreeLogicVolue[1];				//�����б�
	BYTE 							cbDoubleLogicVolue[2];				//�����б�
	BYTE 							cbSignedLogicVolue[5];				//�����б�
	BYTE							cbFourCardData[MAX_COUNT];			//�����б�
	BYTE							cbThreeCardData[MAX_COUNT];			//�����б�
	BYTE							cbDoubleCardData[MAX_COUNT];		//�����б�
	BYTE							cbSignedCardData[MAX_COUNT];		//������Ŀ
};

//////////////////////////////////////////////////////////////////////////

//��Ϸ�߼���
class CGameLogic
{
	//��������
private:
	static BYTE						m_cbCardListData[CARD_COUNT];				//�˿˶���

	//��������
public:
	//���캯��
	CGameLogic();
	//��������
	virtual ~CGameLogic();

	//���ͺ���
public:
	//��ȡ����
	BYTE GetCardType(BYTE cbCardData[], BYTE cbCardCount, BYTE cbSendCard[]=NULL, bool bGet=false);
	//�����Ҹ��������е�����
	BYTE GetListCardType(BYTE cbCardData[], BYTE cbCardCount);
	//��ȡ��ֵ
	BYTE GetCardValue(BYTE cbCardData) { return cbCardData&LOGIC_MASK_VALUE; }
	//��ȡ��ɫ
	BYTE GetCardColor(BYTE cbCardData) { return cbCardData&LOGIC_MASK_COLOR; }
	//��ȡ����
	BYTE GetTimes(BYTE cbCardData[], BYTE cbCardCount);
	//��ȡţţ
	bool GetOxCard(BYTE cbCardData[], BYTE cbCardCount);
	//��ȡ����
	bool IsIntValue(BYTE cbCardData[], BYTE cbCardCount);
	//�������Ƿ�����
	int IsHaveJoker(BYTE cbCardData[], BYTE cbCardCount);
	//ͨ��ţţ�л�ȡ���ͣ��д�С����ʱ���ȡ������ͣ�
	BYTE GetBestCardType(BYTE cbCardData[], BYTE cbCardCount, BYTE cbSendCard[2]=NULL, bool bGet=false);
	//�����ţ���͵�����������
	void GetIndexOx(int iIndex[]);
	//������������ͬ��
	int GetSameCount(BYTE CardData1[], BYTE CardData2[], BYTE cbCount = 5);
	
	//���ƺ���
public:
	//�����˿�
	void SortCardList(BYTE cbCardData[], BYTE cbCardCount);
	//�����˿�
	void RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount , bool bJoke=true);

	void MathCardList( BYTE cbCardBuffer[], BYTE cbBufferCount , BYTE cbMathCard1[] , BYTE cbIndex1, BYTE cbMathCard2[]=NULL ,BYTE cbIndex2=INVALID_BYTE);

	void RandMathCard( BYTE cbCardBuffer[], BYTE cbBufferCount , BYTE cbMathCard1[] , BYTE cbIndex1, BYTE cbMathCard2[]=NULL ,BYTE cbIndex2=INVALID_BYTE);

	void MakeCard(BYTE cbMathCard1[] , BYTE cbType);

	BOOL ValidCardValue(BYTE cbCardBuffer[] , BYTE cbBufferCount);


	//���ܺ���
public:
	//�߼���ֵ
	BYTE GetCardLogicValue(BYTE cbCardData);
	//�Ա��˿ˣ�ͨ��ţţ��
	bool RatioCompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount,BOOL FirstOX,BOOL NextOX);
	//�Ա��˿�
	bool CompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount,BOOL FirstOX,BOOL NextOX);
	//Ӯ�����
	WORD GetWinScore(BYTE cbPlayStatus[GAME_PLAYER] ,BYTE cbHandCardData[GAME_PLAYER][MAX_COUNT] , LONGLONG lTableScore , LONGLONG *lWinScore , WORD wRevenue , LONGLONG *lUserRevenue=NULL);
	//���Ӯ����λ��
	WORD GetWinUser(BYTE cbPlayStatus[GAME_PLAYER] ,BYTE cbHandCardData[GAME_PLAYER][MAX_COUNT]);

};

//////////////////////////////////////////////////////////////////////////

#endif
