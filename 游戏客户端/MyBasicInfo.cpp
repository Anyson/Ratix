#include "stdafx.h"
#include "MyBasicInfo.h"
#include "Res.h"
#include "SysFont.h"
#include "SexyAppBase.h"
#include "widget.h"
#include "WidgetManager.h"
#include "GameView.h"
#include "GameClient.h"
#include "GameClientDlg.h"
#include "StdAfx.h"
#include "DDImage.h"
#include "ButtonWidget.h"





using namespace Sexy;
//view Chair
//CPoint cpPosition[GAME_PLAYER] = {CPoint(430,292),CPoint(180,362),CPoint(290,520),CPoint(810,488),CPoint(700,295)};

static const PTCHAR  szOrder[]={TEXT("��ͨ��Ա"),TEXT("һ�����"),TEXT("�������"),TEXT("�������"),TEXT("�ļ����"),TEXT("�弶���"),TEXT("�������"),
TEXT("�߼����"),TEXT("�˼����"),TEXT("�ż����"),TEXT("�������"),TEXT("�ƽ���"),TEXT("��ʯ���"),TEXT("�������")
};

//�ƺ�
static PTCHAR   szDescription[]={TEXT("ţ����"),TEXT("��ţ"),TEXT("Сţ"),TEXT("Ұţ"),TEXT("׳ţ"),TEXT("��ţ"),TEXT("��ţ"),
TEXT("��ţ"),TEXT("Ѫţ"),TEXT("��ţ"),TEXT("��ţ"),TEXT("ţħ��"),TEXT("��ս��ţ")
};

CMyBasicInfo::CMyBasicInfo(void)
{
	m_pGameApp = (CGameClientApp *)AfxGetApp();
	m_pGameDlg = (CGameClientDlg *)m_pGameApp->m_pGameClientDlg;
	m_pFont10WeiRuanYaHei = new Sexy::SysFont("΢���ź�",10);
	m_pFont9WeiRuanYaHei = new Sexy::SysFont("΢���ź�",9);
 	//�������
 	m_pBtnAddChip = new Sexy::ButtonWidget(BT_ADD_CHIP, this);
 	m_pBtnAddChip->SetBtnImage(m_pGameApp, IMG_BTN_BtnAddChip);
 	m_pBtnAddChip->Resize(120,34,IMG_BTN_BtnAddChip->GetWidth()/4, IMG_BTN_BtnAddChip->GetHeight());
 	/*	m_pBtnAddChip->mZOrder = 2;*/
 	m_pBtnAddChip->SetVisible(1);
 	m_pBtnAddChip->SetDisabled(1);
 	AddWidget(m_pBtnAddChip);
}

CMyBasicInfo::~CMyBasicInfo(void)
{
	RemoveAllWidgets(true);
	SAFE_DELETE(m_pFont10WeiRuanYaHei);
	SAFE_DELETE(m_pFont9WeiRuanYaHei);
}

void CMyBasicInfo::SetMyChair( WORD wMeChair )
{
	m_wMeChairID = wMeChair;
}



//���÷���	
void CMyBasicInfo::Draw( Sexy::Graphics* g )
{
	//�Լ�����Ϣ����
// 	 g->DrawImage(IMG_RATIOX_UserInfo,0,70);
// 	 // 	//���ֳ��뱳��
// 	 g->DrawImage(IMG_RATIOX_UserChip,18,1);
// 	 // 	//�������
// 	 g->DrawImage(IMG_RATIOX_CellScoreBack,16,30);
// 	//����Ϣ���Լ���Ϣ�����������Ϣ��
	
	//�Լ�����Ϣ����
	if (m_pGameDlg->m_wServerType == GAME_GENRE_SCORE_CHIP)
	{
		g->DrawImage(IMG_RATIOX_UserInfoLingZhu,0,70);
	}
	else
	{
		g->DrawImage(IMG_RATIOX_UserInfo,0,70);
	}
	
	//���ֳ��뱳��
	g->DrawImage(IMG_RATIOX_UserChip,18,1);
	//�������
	g->DrawImage(IMG_RATIOX_CellScoreBack,16,30);

	DrawBaseInfo(g);

}

void CMyBasicInfo::SetNotShow( bool bShow )
{

}



void CMyBasicInfo::SetPosition( int x , int y )
{
	m_iy = y;
	m_ix = x;
/*	m_pBtnAddChip->Resize(m_ix,m_iy,IMG_BTN_BtnAddChip->GetWidth()/4, IMG_BTN_BtnAddChip->GetHeight());*/
}


//����Ϣ���Լ���Ϣ�����������Ϣ��
void CMyBasicInfo::DrawBaseInfo( Sexy::Graphics* g )
{
	const tagUserData *pUserData = m_pGameDlg->GetUserData(m_wMeChairID);
	if (pUserData == NULL) return; 

	SexyString str;
	//�ǳ�
	g->SetFont(m_pFont10WeiRuanYaHei);
	g->SetColor(Sexy::Color(186,167,58));
	_bstr_t bstr = pUserData->szNickName;
	wchar_t pname[NAME_LEN];
	StrCpyW(pname, (wchar_t *)bstr);
	g->WriteString(pname, 0+82, 70+37, 100,0);
	//���ֶ������飩
	if (m_pGameDlg->m_wServerType == GAME_GENRE_GOLD)
	{
		str = Sexy::StrFormat(_S("%I64d"),pUserData->lBodySilverScore);
	}
	else
	{
		str = Sexy::StrFormat(_S("%I64d"),pUserData->lBodyScore);
	}
	g->WriteString(str, 0+82, 70+71, 100,0);
	//�ƺ�
	_bstr_t m_description= szDescription[GetDescription((pUserData->lWinCount+pUserData->lLostCount))];
	wchar_t* pwcharDes = (wchar_t*)m_description;
// 	g->WriteString(pwcharDJ, 0+82, 70+20, 100,0);
	g->WriteString(pwcharDes, 0+82, 70+54, 100,0);
	//�ȼ�
	_bstr_t m_grade = szOrder[GetUserOrder(pUserData->lExperience)];
	wchar_t* pwcharDJ = (wchar_t*)m_grade;
	g->WriteString(pwcharDJ, 0+82, 70+20, 100,0);
	//Ԫ��
	str = Sexy::StrFormat(_S("%I64d"),pUserData->lIngot);
	g->WriteString(str, 0+82, 70+88, 100,0);

	str = Sexy::StrFormat(_S("%I64d"),pUserData->lBodyChip);
	g->WriteString(str, 18+79, 1+17, 100,0);

	g->SetFont(m_pFont9WeiRuanYaHei);
	if(m_pGameDlg->m_wServerType == GAME_GENRE_SCORE_CHIP)
	{
		str = Sexy::StrFormat(_S("1����=%I64d����"),m_pGameView->m_lCellScore);
	}
	else
	{
		str = Sexy::StrFormat(_S("1����=%I64d���ֶ�"),m_pGameView->m_lCellScore);
	}
	g->WriteString(str, 16+2, 30+22, 100,0);
}

WORD CMyBasicInfo::GetUserOrder( LONG lExperience )
{
	LONG lOrder[13] = {
		21600,		100800,		928800,		3376800,	8344800,
		14738400,	29440800,	47368800,	71416800,	141472800,
		246808800,	394624800,	59210800
	};
	for(int i=0; i<13; i++)
	{
		if(lExperience < lOrder[i])
		{
			return i;
		}
	}

	return 13;
}


//��óƺ�
WORD CMyBasicInfo::GetDescription( LONGLONG lBuffer )
{
	LONG lOrder[12] = {
		100,		200,		400,		800,	2000,
		4000,	6000,	8000,	20000,	40000,
		60000,	100000
	};
	for(int i=0; i<12; i++)
	{
		if(lBuffer < lOrder[i])
		{
			return i;
		}
	}

	return 12;
}

void CMyBasicInfo::SetGameView( CGameView *pGameView )
{
	m_pGameView = pGameView;
}

void CMyBasicInfo::ButtonDepress( int theId )
{
	m_pGameView->ButtonDepress(theId);
}
