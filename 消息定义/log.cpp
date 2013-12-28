#include "Stdafx.h"
#include "log.h"
#include <string>
#include "GameLogic.h"

//CLog* CLog::m_pInstance = NULL;

CLog			g_Log;				//ȫ����־

bool CLog::Init(const char* szSubDir,const char* szSubDir2,const char* szLogFileName)
{

	char szDir[1024] = {0};
	sprintf(szDir,"%s\\%s\\%s",GetRootPath(),szSubDir,szSubDir2);
	if (!m_oBaseLogger.Init(LOG_MODE_DAY_DIR_DIVIDE,0,szDir,szLogFileName))
	{
		return false;
	}
	
	//bool Init(INT32 nMode, UINT32 dwID,	const char* pszDir, const char* pszName);
	//if (NULL == m_pLog)
	//{
	//	m_pLog = SDErrorGetModule(&SDERROR_VERSION);
	//	if (NULL == m_pLog)
	//	{
	//		return false;
	//	}

	//	if (!m_pLog->InitErrorModule())
	//	{
	//		return false;
	//	}
	//	if (!m_pLog->SetOutputMode(SDERROR_TYPE_LOG,SDERROR_OUTPUT_LOGFILE))
	//	{
	//		return false;
	//	}
	//	m_pLog->SetLogFormat(SDERROR_LOGFORMAT_DIVIDEBYTIME | SDERROR_LOGFORMAT_DIVIDEBYMODULE,szLogFileName);
	//	

	//	//m_pFileLogger = SDCreateFileLogger(&SDFILELOGGER_VERSION);
	//	return true;
	//}

	return true;
}

bool CLog::InitEx(const char* szSubDir,const char* szLogFileName)
{
	char szDir[1024] = {0};
	sprintf(szDir,"%s\\%s",GetRootPath(),szSubDir);
	if (!m_oBaseLogger.Init(LOG_MODE_DAY_DIVIDE,0,szDir,szLogFileName))
	{
		return false;
	}

	return true;
}
void CLog::UnInit()
{
	//if (NULL != m_pLog)
	//{
	//	Log("��־����");
	//	m_pLog->Release();
	//	m_pLog = NULL;
	//}

}

void CLog::Log(const char* pszFormat, ...) 
{ 
	char pszDest[1024] = {0};
	va_list args; 
	va_start(args, pszFormat); 
	_vsnprintf(pszDest, 1024, pszFormat, args); 
	va_end(args);
	//if (NULL != m_pLog)
	//{
	//	m_pLog->Log(pszDest,"3dAnimal");
	//}
	m_oBaseLogger.Log(pszDest,sizeof(pszDest));
	m_oBaseLogger.Flush();

}

void CLog::LogWithoutTimeMark(const char* pszFormat, ...) 
{ 
	char pszDest[1024] = {0};
	va_list args; 
	va_start(args, pszFormat); 
	_vsnprintf(pszDest, 1024, pszFormat, args); 
	va_end(args);
	//if (NULL != m_pLog)
	//{
	//	m_pLog->Log(pszDest,"3dAnimal");
	//}
	m_oBaseLogger.LogWithoutTimeMark(pszDest,sizeof(pszDest));
	m_oBaseLogger.Flush();

}

const char* vn(BYTE nType)
{	
	switch(nType&0x0F)
	{
	case 1:
		return "A";
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	case 10:
		return "10";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	case 14:
		return "С��";
	case 15:
		return "����";
	}
	return "δ֪��";
}

const char* cn(BYTE nType)
{
	switch(nType&0xF0)
	{
	case 0x00:
		return "����";
	case 0x10:
		return "÷��";
	case 0x20:
		return "����";
	case 0x30:
		return "����";
	case 0x40:
		return "";
	}
	return "δ֪��ɫ";
}

const char* GetBowlName(BYTE cbCardData)
{
	switch(cbCardData)
	{
	case BIG_BUFFER:
		return "��۱���";
	case SMALL_BUFFER:
		return "С�۱���";
	case 2:
		return "ϲ��";
	}
	return "δ֪�۱���";
}

const char* CardTypeName( BYTE cbType )
{

	switch(cbType)
	{
	case 0:
		return "��ţ";
	case 1:
		return "ţһ";
	case 2:
		return "ţ��";
	case 3:
		return "ţ��";
	case 4:
		return "ţ��";
	case 5:
		return "ţ��";
	case 6:
		return "ţ��";
	case 7:
		return "ţ��";
	case 8:
		return "ţ��";
	case 9:
		return "ţ��";
	case 10:
		return "ţţ";
	case OX_GOLD:
		return "��ţ";
	case OX_DOUBLE_JOKE:
		return "��ţ��";
	}
	return "δ֪����";
}