#ifndef __RTMP_VF__H__
#define __RTMP_VF__H__


#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
	int channel;
	int stream;
	int record_type;

	//!��ʱ��طţ���ʼʱ�䣬����ʱ��
	int st_year;
	int st_month;
	int st_day;
	int st_hour;
	int st_mintute;
	int st_second;

	int ed_year;
	int ed_month;
	int ed_day;
	int ed_hour;
	int ed_mintute;
	int ed_second;

	//!���ļ��ط�ʱʹ��
	int iDisk;
	int iPart;
	int iCluster;
}RTMP_PLAY_INFO;

//!FrameType -- 3:audio, 0:p frame, 1: iframe
typedef int (*pfnAddFrameData)(void* handle, const int channel, const int stream, const unsigned char* data, const int len, int FrameType, int rate);
typedef struct
{
	int (*pfnOpenSource)(const RTMP_PLAY_INFO* play_info, pfnAddFrameData pfnAddFrame, void** handle);
	int (*pfnPauseSource)(void* handle, const RTMP_PLAY_INFO* play_info);
	int (*pfnCloseSource)(void* handle, const RTMP_PLAY_INFO* play_info);
}RTMP_LIVE_SOURCE;

int RtmpSetLiveSource(RTMP_LIVE_SOURCE* live_source);
int rtmp_Start(int port);

//����ɹ����ؾ��phandle��ʧ�ܷ���NULL
void *RtmpPublishLiveOpen(char *url);

//�رգ�ע�ⷢ���������ģ����������ݵ�ʱ�������ر�
int RtmpPublishLiveClose(void *phandle);

//�������ͣ�ע��͹رյĻ��⣬����-1��ʾ����ʧ�ܣ�������socket�Ѿ��رտɻ�����Դ��
int RtmpPublishLiveSendAV(void *phandle, const unsigned char* videoData, const int frameLen, int frmType, int frmRate);



#ifdef __cplusplus
};
#endif

#endif
