#pragma once
#include "Stdafx.h"
#include "AnimLayer.h"
#include "GameClient.h"
#include "AnimLayerListener.h"
#include <vector>
using namespace std;


enum PlayerAct																	//��ʾ���ֶ���
{
	ZHENG_CHANG=0,
	DAI_JI,
	DAI_JI2,
	HAPPY,
	JU_SANG,
	JING_YA,
	MAX_NORMAL_ACT,

	MY_ACT_ONE
};

namespace Sexy
{
	class Graphics;
	class AnimLayer;
	class AnimLayerListener;
}


class CGameClientApp;
class Player: public Sexy::AnimLayerListener
{
public:
    static vector<int> m_vecPlayerIndex;
public:
	Player(void);
	~Player(void);
public:
	//��������
	void					Draw(Sexy::Graphics* g);
	void					Update();
	//void					MouseMove( int x, int y );
private:
	int						m_palyerX;						//����λ��
	int						m_palyerY;
    bool                    m_bReversal;                    //�Ƿ�ת
	int					    m_iDirection;					//����
	PlayerAct				m_PlayerAct;					//���ﶯ��
	int						m_iSex;							//�����Ա�  1��0Ů	
public:
	bool					m_bShowUserInfo;				//��ʾ������Ϣ
    int						m_iPlayerIndex;

	Sexy::AnimLayer			*m_pPlayerActAni;				//���ﶯ��
	Sexy::AnimLayer			*m_pMeActAni1;
	CGameClientApp			*m_pGameApp;
public:
	void					InitPlayerAni(PlayerAct act);

	void					SetPlayerPos(int x,int y);

    void					SetReversal(bool bReversal);

	void					SetDirection(int iDirection);

	void					SetStatus(PlayerAct act);

	void SetPlayerSex(int isex=-1);

	//������ص�
	void					OnAniFinish(int id);
};
