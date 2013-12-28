#pragma once

#include <map>

namespace Sexy
{
	class SexyAppBase;
}



/*
//����������
������ֱ�����ļ������������ķ���
*/
class CSoundPlayer
{
public:
	CSoundPlayer(Sexy::SexyAppBase *pGameApp);
	~CSoundPlayer(void);

	//����һ�������ļ�·��  ��������������С0~1 ��������ָ������ID������С��1000���������ֱ�������
	int PlaySound(std::string str,double dVolume,int iInSoundID = -1);

	void PlayMusic(int theId);										//��������
	void PlayMusic(std::string str,int iInSoundID = -1);			//������
	void StopMusic();												//�رձ�����
	int  PlaySound(std::string str);								//��Ч
	void PlaySpeech(std::string str);								//������
	void PlaySound(std::string str,int iInSoundID);					//��Ч


	int GetBackMusicNum();											//��ñ������ֵ���Ŀ
	void UpdateMusic();												//�������ű�����

	void SetSongVolume(const AppInfoDef *pAppInfo, int iPos);					//��������
	void EnableSound(bool bEnable);
private:
	int m_iSoundID;

	int m_iCurrentMusicID;											//��ǰ���ű������ֵ�ID
	int m_iMaxMusicNum;												//������������

	Sexy::SexyAppBase *m_pGameApp;

	//��Ϸ����
	AppInfoDef			m_AppInfo;
	
	
	std::map<std::string, int> m_mapSound;
	std::map<int, std::string> m_mapSoundID;						//���IDͬһ��·��

};
