#ifndef __GAME_TIMER_LISTENER_H_
#define __GAME_TIMER_LISTENER_H_

namespace Sexy
{

//��ʱ���ļ�����
	class GameTimerListener
	{
	public:
		virtual	void OnTimer(int id, WORD wChairID, UINT nElapse){};
	};

}


#endif