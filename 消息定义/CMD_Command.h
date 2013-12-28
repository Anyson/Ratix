#ifndef CMD_SPARROW_HEAD_FILE
#define CMD_SPARROW_HEAD_FILE

//////////////////////////////////////////////////////////////////////////
//�����궨��
#define IDR_MAINFRAME				128
#define KIND_ID						5									//��Ϸ I D
#define GAME_PLAYER					5									//��Ϸ����
#define GAME_NAME					TEXT("ͨ��ţţ")					//��Ϸ����
#define GAME_GENRE					(GAME_GENRE_SCORE|GAME_GENRE_MATCH|GAME_GENRE_GOLD)	//��Ϸ����
#define MAXCOUNT					5									//�˿���Ŀ
#define MAXMULITY					2									//�������
#define MAX_CHIP_COUNT				5									//�һ�����ĵ���

#define BIG_BUFFER						0									//���ۼ�
#define SMALL_BUFFER					1									//С�ۼ�
#define BUFFER_COUNT					2									//�۱�������
//��Ϸ״̬
#define GS_OX_FREE					GS_FREE								//����״̬
#define GS_OX_PLAY					(GS_PLAYING+1)						//��Ϸ״̬
#define GS_OX_ACCOUNTS				(GS_PLAYING+2)						//����̯��״̬



// �����
// #define SUB_S_SENCE_FREE			109									//������Ϣ(����)
// #define SUB_S_SENCE_PLAY			110									//������Ϣ(�з�)
// #define SUB_S_SENCE_END				111									//������Ϣ(��Ϸ)



//////////////////////////////////////////////////////////////////////////
//����������ṹ

#define SUB_S_GAME_START			1000									//��Ϸ��ʼ
#define SUB_S_GAME_READY			1001									//���׼��
#define SUB_S_SEND_CARD				1002									//�����˿�
#define SUB_S_EX_CHIP				1003									//�һ��������
#define	SUB_S_BOWL					1004									//�۱���
#define SUB_S_OPEN_CARD				1005									//�û�̯��
#define SUB_S_GAME_END				1006
#define SUB_S_GAME_FINISH			1007									//��Ϸȫ������
#define SUB_S_HURRY_CARD			1008									//����
#define SUB_S_GAME_FREE				1009									//��Ϸ����
#define SUB_S_XIJIN					1010									//ϲ��
#define	SUB_S_SEND_BOWL				1011									//�۱�����Ϣ
#define SUB_S_OFFLINE				1012									//������Ϣ
#define SUB_S_RECONN				1013									//����

//����/����
struct CMD_S_OffLine_Reconn
{
	WORD								wOperaUser;
};

//�۱���/ϲ��
struct CMD_S_Send_Bowl
{
	DWORD								dwUserID;							//�û� I D
	LONG								lIngot;								//Ԫ������
	BYTE								cbBowlType;							//�۱�������

	LONG								lNewIngot;							//�¾۱��轱��
};
struct CMD_S_HurryCard
{
	WORD								wCurrentUser;
	BYTE								cbWords;
};
//��Ϸ׼��
struct CMD_S_GameReady
{
	BYTE								cbTimeLeave;						//ʣ��ʱ��
};

//��Ϸ����
struct CMD_S_GameFree
{
	BYTE							cbTimeLeave;						//ʣ��ʱ��
};
//��Ϸ״̬
struct CMD_S_StatusFree
{
	LONGLONG							lCellScore;							//��������
	WORD								wServerType;						//��������
	LONGLONG							lMinBet;							//��С��ע
	WORD								wServerID;							//����ID
	LONGLONG							lChipNum[MAX_CHIP_COUNT];			//��������
	LONG								lPercentage[MAX_CHIP_COUNT];		//����ѱ���
	
	/*LONGLONG							lDescription[GAME_PLAYER];			//�ƺŻ���*/
};

//��Ϸ״̬
struct CMD_S_StatusPlay
{

	LONGLONG							lCellScore;							//��������
	WORD								wServerType;						//��������
	LONGLONG							lMinBet;							//��С��ע
	WORD								wServerID;							//����ID
	LONGLONG							lChipNum[MAX_CHIP_COUNT];			//��������
	LONG								lPercentage[MAX_CHIP_COUNT];		//����ѱ���
	
	BYTE								cbOx[GAME_PLAYER];					//̯����Ϣ
	BYTE								cbCardData[GAME_PLAYER][MAXCOUNT];			//�˿���Ϣ
	BYTE								cbRewardCardData[GAME_PLAYER][MAXCOUNT];	//ϲ���˿���Ϣ
	BYTE								cbPlayStatus[GAME_PLAYER];			//��Ϸ״̬

};
//����״̬
struct CMD_S_StatusEnd
{

	LONGLONG							lCellScore;							//��������
	WORD								wServerType;						//��������
	LONGLONG							lMinBet;							//��С��ע
	WORD								wServerID;							//����ID
	LONGLONG							lChipNum[MAX_CHIP_COUNT];			//��������
	LONG								lPercentage[MAX_CHIP_COUNT];		//����ѱ���

	
	//BYTE								cbOx[GAME_PLAYER];					//̯����Ϣ
	LONGLONG							lGameScore[GAME_PLAYER];			//��Ϸ�÷�
	BYTE								cbCardData[GAME_PLAYER][MAXCOUNT];	//�û��˿�
	BYTE								cbRewardCardData[GAME_PLAYER][MAXCOUNT];//ϲ���˿���Ϣ
	LONG								lDeskPay;							//�۵�������
	BYTE								cbPlayStatus[GAME_PLAYER];			//��Ϸ״̬

};

//��Ϸ��ʼ
struct CMD_S_GameStart
{
	//LONG								lAddScore;							//��ע��ע
	BYTE								cbCardData[GAME_PLAYER][MAXCOUNT];	//�û��˿�
	BYTE								cbRewardCardData[GAME_PLAYER][MAXCOUNT];//ϲ����
	BYTE								cbPlayStatus[GAME_PLAYER];			//��Ϸ״̬
};

//�����˿�
struct CMD_S_SendCard
{
	
};

//�û�̯��
struct CMD_S_Open_Card
{
	WORD								wPlayerID;							//̯���û�
	BYTE								bOpen;								//̯�Ʊ�־
};

//��������
struct CMD_S_OperateResult
{
	WORD							wOperateUser;						//�����û�
	WORD							wProvideUser;						//��Ӧ�û�
	BYTE							cbOperateCode;						//��������
	BYTE							cbOperateCard;						//�����˿�
};
//�۱�����Ϣ
struct CMD_S_Bowl
{
	LONGLONG						lBowlIngot;							//�۱���
	//LONG							lSmallBowlIngot;
	LONG							lLikeGoldIngot;						//ϲ��
	LONG							lNewLikeIngot[4];					//��ϲ�𷢷���Ŀ
};

//��Ϸ����
struct CMD_S_GameEnd
{
	LONG								lGameTax[GAME_PLAYER];				//��Ϸ˰��
	LONGLONG							lGameScore[GAME_PLAYER];			//��Ϸ�÷�
	BYTE								cbCardData[GAME_PLAYER][MAXCOUNT];	//�û��˿�
	LONG								lDeskPay;							//�۵�������
};
//�û��й�
struct CMD_S_Trustee
{
	bool							bTrustee;							//�Ƿ��й�
	WORD							wChairID;							//�й��û�
};
//////////////////////////////////////////////////////////////////////////
//�ͻ�������ṹ

#define SUB_C_EX_CHIP				1									//�һ�����
#define SUB_C_OPEN_CARD				2									//�û�̯��
#define SUB_C_COMPARE_CARD			3									//�������
#define SUB_C_CHEAT					4									//����
#define SUB_C_HURRY_CARD			5									//����
//����
struct CMD_C_HurryCard
{
	BYTE								cbWords;
};

struct CMD_C_Cheat
{
	int								iCheatControl;						//�Ƿ���п���
	BYTE							cbHandCardData[GAME_PLAYER][MAXCOUNT];	
	BYTE							cbRewardCard[GAME_PLAYER][MAXCOUNT];
	LONGLONG						lPoolScore;
};

//�û�̯��
struct CMD_C_OxCard
{
	BYTE								bOX;								//ţţ��־
};

//�û��һ�����
struct CMD_C_ExchangeChip
{
	WORD							wExchangeUserChairID;				//�һ��û�
	LONGLONG						lExchangeCount;						//�һ���Ŀ
};

//��������
struct CMD_C_OperateCard
{
	BYTE							cbOperateCode;						//��������
	BYTE							cbOperateCard;						//�����˿�
};
//�û��й�
struct CMD_C_Trustee
{
	bool							bTrustee;							//�Ƿ��й�	
};
//////////////////////////////////////////////////////////////////////////

#endif