#pragma once
#include <map>

namespace Sexy
{
	typedef struct GameTimerInfo
	{
		int nTimerId;					//��ʱ��ID
		unsigned long dwElapse;			//ʱ����
		unsigned long dwTickCount;		
		bool bAvalid;					//�Ƿ����
		unsigned short wChairID;		//���λ��
		unsigned int nElapse;			//��ʱ������
	} GameTimerInfoDef;

	class GameTimerListener;
	class GameTimer
	{
	public:
		GameTimer(GameTimerListener *pGameTimerListener);
		~GameTimer(void);
	private:
		std::map<int, GameTimerInfoDef> m_GameTimeMap;
		GameTimerListener			*m_pGameTimerListener;
	public:
		//��ʱ��ID ʱ���� ���λ�� ��ʱ������
		void SetTimer(int nTimerId, unsigned long dwElapse, WORD wChairID, UINT nElapse);
		void KillTimer(int nTimerId);
		void Update();
		
	};
}
