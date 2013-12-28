#ifndef TABLE_CONTRAL_HEAD_FILE
#define TABLE_CONTRAL_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "GameLogic.h"
#include <string>
#include <vector>

struct STModePrizeValue 
{
	bool bValid;
	LONGLONG lSysWinScore;
	LONGLONG lContralScore;
	BYTE cbMathCardData[GAME_PLAYER*MAX_COUNT];
};


struct ITableFrame;
class CLog;

class Contral
{
public:
	Contral(void);
	~Contral(void);
public:
	static BYTE			m_cbDefaultCardType[13][MAX_COUNT];
	static LONGLONG		m_lScorePool;		//�ŷֳ�

private:
	static LONGLONG			m_lThreshold[5];
//	static LONGLONG			m_lScorePool[2];
	
	LONGLONG			m_lScoreValue[2];
	
	LONG				m_lCellScore;

private:
	BYTE				m_WinRete;			//��Ӯ����
	BYTE				m_LoseRate;			//�������
	

	BYTE				m_cbFriedRate;
	BYTE				m_cbThresholdRate;
	BYTE				m_cbSysEateRate;
	BYTE				m_cbBufferRate;
	
	WORD				m_wRevenue;

private:
	BYTE				m_bContral[GAME_PLAYER];

private:
	ITableFrame			*m_pTableFrame;
	CLog				*m_pLog;				//��־
	CGameLogic			m_GameLogic;

private:
	BYTE				m_cbMode;

private:
	std::vector<STModePrizeValue> m_vcPrizeValue;

public:
	BOOL CheckBuffer(LONGLONG lScore);
	VOID DeductionBuffer(LONGLONG lScore);
	VOID AddBuffer(LONGLONG lScore);
	void Init(ITableFrame *pTableFrame,CLog *pLog,LONG lCellScore , WORD wRevenue);
	void LoadCfg(TCHAR *szINIPath, int iEatRate=0);
	BYTE GetNextGamePrizeMode();
	void Reset();
	void DispathCard(BYTE cbHandCardData[GAME_PLAYER*MAX_COUNT] , LONGLONG lPlayScore[GAME_PLAYER] ,BYTE cbPlayStatus[GAME_PLAYER] ,WORD wBankerUser);
	void RandDispath(BYTE cbMathCardData[GAME_PLAYER*MAX_COUNT] , LONGLONG lPlayScore[GAME_PLAYER] , WORD wBankerUser);
	BOOL GetContral() { return m_cbMode; }
	BOOL CheckFried(WORD wChairID) { return m_bContral[wChairID]==1;}
	//��ȡһ����������λ��
	WORD GetRandUser();
	//��ȡһ�������������λ��
	WORD GetRandAndroid();
	//��������
	void ControlDispath(BYTE cbHandCardData[GAME_PLAYER][MAX_COUNT],BYTE cbPlayStatus[GAME_PLAYER]);
	//���ϵͳ��Ӯ��
	LONGLONG GetSysWinScore(LONGLONG lWinScore[GAME_PLAYER], WORD wWinUser);
	//�ı��ֵ
	VOID ChangeBuffer(LONGLONG lScore);
	//��ȡ�ŷֳ��е�ֵ
	LONGLONG GetPoolScore();
private:
	BYTE CheckTriggerContral(IServerUserItem* pServerUserItem);
	LONGLONG CalculateSysScore(LONGLONG lUserWinScore[GAME_PLAYER]);
	LONGLONG CalculateContralScore(LONGLONG lUserWinScore[GAME_PLAYER]);
	void CalculateScore(LONGLONG lPlayScore[GAME_PLAYER] ,WORD wBankerUser ,BYTE cbHandCardData[GAME_PLAYER][MAX_COUNT], LONGLONG& dwSysScore , LONGLONG& dwContralScore);
	BOOL MathOptimalCard(BYTE cbMathCardData[GAME_PLAYER*MAX_COUNT] , LONGLONG lPlayScore[GAME_PLAYER] , WORD wBankerUser);
	VOID CheckOptimalScore(STModePrizeValue &stModePrizeValue , LONGLONG &lOptimalScore , std::vector<STModePrizeValue>& vcSTModePrizeValue);
	BOOL CheckSimpleBuffer(BYTE cbHandCardData[GAME_PLAYER][MAX_COUNT] , LONGLONG lPlayScore[GAME_PLAYER] , WORD wBankerUser);
	bool CheckTask(BYTE cbMathCardData[GAME_PLAYER*MAX_COUNT],BYTE cbHandCardData[GAME_PLAYER][MAX_COUNT]);
};

void StrSplit(std::string src, std::string token, std::vector<std::string>& vect);

#endif