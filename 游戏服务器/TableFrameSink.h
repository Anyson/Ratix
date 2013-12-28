#ifndef TABLE_FRAME_SINK_HEAD_FILE
#define TABLE_FRAME_SINK_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "MD5Checksum.h"
#include <algorithm>
#include "GameLogic.h"
#include "log.h"
#include "Contral.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////


//��Ϸ������
class CTableFrameSink : public ITableFrameSink, public ITableUserAction
{
	//��������
protected:
	LONGLONG						m_wbOperateTime;
	BYTE							m_bOxCard[GAME_PLAYER];					//ţţ����
	bool							m_bCheat;								//�Ƿ��������
	DWORD							m_dwJettonTime;							//��ʼʱ��
	DWORD							m_dwOverTime;							//��ʼʱ��
	//��ע����
protected:
	LONGLONG						m_lCellScore;							//��λ����
	LONGLONG						m_lMinbet;								//��С��ע
	
	//������������
	static LONGLONG					m_lBuffer;								//�ۼƳ�
	static BOOL						m_bMeetConditions;						//�Ƿ��������
	static LONGLONG					m_lBufferFund;							//������ų���������

	LONGLONG						m_lBufferNumSection[4];					//�ۼ�Ԫ���ֶ�
	BYTE							m_cbBufferGrandRate[4];					//�ۼƱ���

	LONG							m_lLikeIngot;							//ϲ��Ԫ��
	LONG							m_lNewLikeIngot[4];						//������Ŀ
	int								m_iSameCountLine;						//ϲ�𷢷�����						

	LONGLONG						m_lUserRevenue[GAME_PLAYER];			//˰�ձ���
	LONG							m_lDeskPay;								//����
	BYTE							m_cbEateRate;							//�Էֱ���
	LONG							m_lInitBuffer;							//��ʼ�۱���Ԫ��
	BYTE							m_cbForceRate;							//ǿ������
	BYTE							m_cbBufferRate;							//�۱����ۼƱ���
	//����˿˱���
protected:
	BYTE							m_cbHandCardData[GAME_PLAYER][MAX_COUNT];//�������
	BYTE							m_cbRewardCardData[GAME_PLAYER][MAX_COUNT]; //���������

	BYTE							m_cbCheatCardData[GAME_PLAYER][MAX_COUNT];	//���ƺ����
	BYTE							m_cbCheatRewardCard[GAME_PLAYER][MAX_COUNT];				//
	
	
	//�������
	BYTE							m_cbPlayStatus[GAME_PLAYER];				//��Ϸ״̬
protected:
	CRITICAL_SECTION				m_csPlaceJetton;
	LONGLONG						m_lChipNum[MAX_CHIP_COUNT];				//��������
	LONG							m_lPercentage[MAX_CHIP_COUNT];			//����ѱ���
	LONGLONG						m_lUserAddScore[GAME_PLAYER];			//�����ע
	LONGLONG						m_lSysWinScore;							//ϵͳ��Ӯ��
	LONGLONG						m_lUserWinScore[GAME_PLAYER];			//�����Ӯ��
	LONGLONG						m_lTotalWinScore[GAME_PLAYER];			//����ܵ���Ӯ�֣��������ѣ�
	BOOL							m_bCompare[GAME_PLAYER];				//�����Ƿ����
	//�������
protected:
	CGameLogic						m_GameLogic;							//��Ϸ�߼�
	ITableFrame						* m_pITableFrame;						//��ܽӿ�
	const tagGameServiceOption		* m_pGameServiceOption;					//���ò���
	ITableFrameControl				* m_pITableFrameControl;				//��ܽӿ�
	ITableFrameManager	*		    m_pITableFrameManager;
/*	CMD_GR_TblCfg					m_strTableCfg;							//��������*/

    //
	//���Ա���
protected:
	static const WORD				m_wPlayerCount;							//��Ϸ����
	static const enStartMode		m_GameStartMode;						//��ʼģʽ


	CLog							m_oLog;									//��־
	Contral							m_oContral;								//���Ϳ���
	IServerUserItem *				m_pIUserItem;							//���������

	//��������
public:
	//���캯��
	CTableFrameSink();
	//��������
	virtual ~CTableFrameSink();

	//�����ӿ�
public:
	//�ͷŶ���
	virtual VOID __cdecl Release() { }
	//�Ƿ���Ч
	virtual bool __cdecl IsValid() { return AfxIsValidAddress(this,sizeof(CTableFrameSink))?true:false; }
	//�ӿڲ�ѯ
	virtual void * __cdecl QueryInterface(const IID & Guid, DWORD dwQueryVer);

	//����ӿ�
public:
	//��ʼ��
	virtual bool __cdecl InitTableFrameSink(IUnknownEx * pIUnknownEx);
	//��λ����
	virtual void __cdecl RepositTableFrameSink();

	//��Ϣ�ӿ�
public:
	//��ʼģʽ
	virtual enStartMode __cdecl GetGameStartMode();
	//�¼ӵ�
	virtual bool __cdecl GetGameBGode(WORD nChair){return true;}
	//�Ƿ����û���Ϸ
	virtual bool __cdecl IsUserPlaying(WORD wChairID);

public:
	//��Ϸ��ʼ
	virtual bool __cdecl OnEventGameStart();
	//��Ϸ����
	virtual bool __cdecl OnEventGameEnd(WORD wChairID, IServerUserItem * pIServerUserItem, BYTE cbReason);
	//���ͳ���
	virtual bool __cdecl SendGameScene(WORD wChiarID, IServerUserItem * pIServerUserItem, BYTE cbGameStatus, bool bSendSecret);

	//�¼��ӿ�
public:
	//��ʱ���¼� 
	virtual bool __cdecl OnTimerMessage(WORD wTimerID, WPARAM wBindParam);
	//��Ϸ��Ϣ����
	virtual bool __cdecl OnGameMessage(WORD wSubCmdID, const void * pDataBuffer, WORD wDataSize, IServerUserItem * pIServerUserItem);
	//�����Ϣ����
	virtual bool __cdecl OnFrameMessage(WORD wSubCmdID, const void * pDataBuffer, WORD wDataSize, IServerUserItem * pIServerUserItem);


	//�����¼�
public:
	//�û�����
	virtual bool __cdecl OnActionUserOffLine(WORD wChairID, IServerUserItem * pIServerUserItem) ;
	//�û�����
	virtual bool __cdecl OnActionUserReConnect(WORD wChairID, IServerUserItem * pIServerUserItem);
	//�û�����
	virtual bool __cdecl OnActionUserSitDown(WORD wChairID, IServerUserItem * pIServerUserItem, bool bLookonUser);
	//�û�����
	virtual bool __cdecl OnActionUserStandUp(WORD wChairID, IServerUserItem * pIServerUserItem, bool bLookonUser);
	//�û�ͬ��
	virtual bool __cdecl OnActionUserReady(WORD wChairID, IServerUserItem * pIServerUserItem, VOID * pData, WORD wDataSize);
	
// 	//��ȡ����������Ϣ
// 	virtual const CMD_GR_TblCfg* __cdecl GetTableCfg()
// 	{
// 		return &m_strTableCfg;
// 	}
	
	//��Ϸ�¼�
protected:
	//�һ�����
	bool OnExchangeChip(WORD wChairID, LONGLONG lChip);
	//����
	bool OnHurryCard(WORD wChairID , WORD cbWords);


	//����ʱ��
	void OperateTimer(WORD wChairID,WORD wTime);
	//��������
protected:
	void CountDownTime(WORD wChairID , bool bKill=false);
	//��ȡ�����ļ�
	void ReadIniCfg();
	//�ж���Ϸ�Ƿ�ɿ�ʼ
	BYTE CheckStartGame();
	//д�����
	void WriteScore();
	//��Ϸ����
	void ConcludeGame();
	//��Ϸ׼����ʼ
	void GameReady(WORD wChair);
	//���;۱�����Ϣ
	void SendBowl(WORD wChairID);
	//��Ϸ��ʼ
	void GameStart();
	//�������ͨ������
	bool DispathCard();
	//̯���¼�
	bool OnUserOpenCard(WORD wChairID, BYTE bOx);
	//�������
	bool OnCompareCardFinish(WORD wChairID);
	//����Ƿ���ϲ��
	void CheckXijin();
	


	
	//�˹����ܺ���
protected:
	//�����ҹ��׶�
	bool CheckUserContribution(WORD wChairID , LONGLONG lBuffer);
	//���¾۱���
	bool UpdateTask(BYTE cbBufferType=0);
	//��¼�۱�������
	void logCard(WORD wChairID);
	//���;۱���
	void SendTaskIngot();
	//�����ǳ�
	void HideNickName(const TCHAR *szNickName , TCHAR *szOutNickName );
	//����۱���
	bool AddBuffer(BYTE cbBufferType=0 , LONGLONG lChip=0);
	//����Ƿ�����ǿ��
	bool CheckBufferForce(BYTE cbBufferType=0);
	//ǿ��
	bool ForceDispathCard();
public:
	//������Ϣ
	void SendGameMessage(WORD wChairID, LPCTSTR pszTipMsg);

};

//////////////////////////////////////////////////////////////////////////

#endif