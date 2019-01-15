#ifndef __HSAVPLAYER_H__
#define __HSAVPLAYER_H__

#include "AVPlayerDef.h"

#define HSAVPLAYER_DLL

#ifdef HSAVPLAYER_DLL
#ifdef HSAVPLAYER_EXPORTS
#define HSAVPLAYER_API extern "C" __declspec(dllexport)
#else
#define HSAVPLAYER_API extern "C" __declspec(dllimport)
#endif
#else
#define HSAVPLAYER_API extern "C"
#endif


//1 ��ʼ��
HSAVPLAYER_API long __stdcall HS_Initial( );

//2 �ͷ���Դ
HSAVPLAYER_API long __stdcall HS_Free();

//3 ���ļ�,����ɹ� �򷵻�0,
HSAVPLAYER_API long __stdcall HS_OpenRecFile(  char * sFileName, HANDLE * handle);

//4 �ر��ļ�
HSAVPLAYER_API long __stdcall HS_CloseRecFile( HANDLE handle );

//5 ��ȡ�ļ�����ʱ��
HSAVPLAYER_API long __stdcall HS_GetFileTotalTime( HANDLE handle, long *lTime );

//6 ������Ƶ
HSAVPLAYER_API long __stdcall HS_OpenStream(AV_STREAM_INFO* pStreamHead, HANDLE * handle);

//7 �ر���Ƶ��, 
HSAVPLAYER_API long __stdcall HS_CloseStream( HANDLE handle );

//8 �������뺯��
HSAVPLAYER_API long __stdcall HS_InputData( HANDLE handle, char * buf, long lSize, AV_STREAM_INFO *pStream);

//9 ��������
HSAVPLAYER_API long __stdcall HS_OpenSound( HANDLE handle );

//10 �ر���Ƶ
HSAVPLAYER_API long __stdcall HS_CloseSound(HANDLE handle);

//11 ��������,ȡֵ��Χ��0- 0Xff
HSAVPLAYER_API long __stdcall HS_SetVolume( HANDLE handle, long lVolume );

//12 ��ʼ����
HSAVPLAYER_API long __stdcall HS_Play( HANDLE handle, HWND hWnd );

//13 ֹͣ����
HSAVPLAYER_API long __stdcall HS_Stop( HANDLE handle );

//14 ��ͣ,
HSAVPLAYER_API long __stdcall HS_Pause( HANDLE handle, long lPause );

//15 �����ļ��ط�λ��
HSAVPLAYER_API long __stdcall HS_SetPlayTime( HANDLE handle, long lSecond );

//16 ��ȡ�ļ��ط�ʱ��
HSAVPLAYER_API long __stdcall HS_GetPlayTime( HANDLE handle, long * lSecond );

//17 ���ò����ٶ�, 
HSAVPLAYER_API long __stdcall HS_SetSpeed( HANDLE handle, long lSpeed );

//18 ��ȡ�����ٵ�
HSAVPLAYER_API long __stdcall HS_GetSpeed( HANDLE handle,long *lSpeed );

//19 ��֡����,��֡����ط�
HSAVPLAYER_API long __stdcall HS_OneByOne( HANDLE handle );

//20 ץ��
HSAVPLAYER_API long __stdcall HS_Snapshot( HANDLE handle, const char * sFileName,long lPicType = 0 );

//21 ˢ�º���
HSAVPLAYER_API long __stdcall HS_Refresh( HANDLE handle );

//22 ��ȡͼ���С,
HSAVPLAYER_API long __stdcall HS_GetPictureSize( HANDLE handle, long * lWidth, long * lHeight );


//24 ������ʾ�ص�����,
HSAVPLAYER_API long __stdcall HS_SetDrawCallBack( HANDLE hHandle, HsDrawCallback DrawCallBack, void* lpcContext );

//25 �Ŵ���ʾָ������
HSAVPLAYER_API long __stdcall HS_ShowRect( HANDLE handle, RECT *pRect );

//26 ���ٶ��ʵ��������˳�,���ٶ��ʵ�����˳�
HSAVPLAYER_API long __stdcall HS_SetStopFlag( HANDLE handle );

//27¼�� ʱ����
HSAVPLAYER_API long __stdcall HS_StartRecord( HANDLE handle, const char* filename, int second);
HSAVPLAYER_API long __stdcall HS_StartRecord2( HANDLE handle, const char* filename, int second,int frameRate=0);

//28ֹͣ¼��
HSAVPLAYER_API long __stdcall HS_StopRecord( HANDLE handle );

//27¼�� ʱ����
HSAVPLAYER_API long __stdcall HS_StartRecordAnother( HANDLE handle, const char* filename, int second);
HSAVPLAYER_API long __stdcall HS_StartRecordAnother2( HANDLE handle, const char* filename, int second,int frameRate=0);

//28ֹͣ¼��
HSAVPLAYER_API long __stdcall HS_StopRecordAnother( HANDLE handle );

//29���û����е�֡��,����������,ͬʱ��������ʱ nFrame һ�㲻Ҫ����60
HSAVPLAYER_API long __stdcall HS_SetFrameCache( HANDLE handle,unsigned long nFrame );

//32 ��Ϣ�ص�����
HSAVPLAYER_API long __stdcall HS_SetMSGCallBack( HANDLE handle,HsAVMessageCallBack msgCallBack ,void* lpContext);

//33 ��Ƶ�ص�����
HSAVPLAYER_API long __stdcall HS_SetAVDataCallBack( HANDLE handle, HsAVDataCallBack avCallBack , void* lpContext);

//34��ȡ��Ƶ�������е�֡��
HSAVPLAYER_API long __stdcall HS_GetVideoFrame( HANDLE handle,  long *frame);

//35�����Ƶ����Ƶ������
HSAVPLAYER_API long __stdcall HS_ResetVideoBuffer( HANDLE handle);

//36��ȡ����Ƶ����,2012.7.2 add
HSAVPLAYER_API long __stdcall HS_GetStreamInfo( HANDLE handle, AV_STREAM_INFO*pInfo);

HSAVPLAYER_API long __stdcall HS_SetStreamInfo( HANDLE handle, AV_STREAM_INFO *pInfo);

//37���ý���ص�,2012.7.3 add

#ifdef HXHT_PLAYER

HSAVPLAYER_API long __stdcall HS_SetDecodeCallBack( HANDLE handle, HXHT_DecodeCallBack decfun, long param);

#else

HSAVPLAYER_API long __stdcall HS_SetDecodeCallBack( HANDLE handle, HsDecodeCallBack decfun, void* lpcontext);
#endif

//��ȡ��Ƶ������״̬
HSAVPLAYER_API long __stdcall HS_GetVideoBufferInfo( HANDLE handle,  int *total, int *stock, int *frames);

//������Ļ˺�ѿ���, ctrl=0(Ĭ��),��Դ���ñȽϸ�      <0 ������
HSAVPLAYER_API long __stdcall HS_SetVertBlank( HANDLE handle,  long ctrl);

//������Ƶ��Ƭͼ��
HSAVPLAYER_API long __stdcall HS_SetSliceImage( HANDLE handle,HWND hWnd,int nSeek=0);

//��¼���ļ�ץ��
HSAVPLAYER_API long __stdcall HS_SnapshotFromFile(const char * sRecFileName, const char * sPicFileName,int nSeek = 0,int lPicType = 0,int quality = 80 );

//�򿪲ɼ�����
HSAVPLAYER_API long __stdcall HS_OpenCaptureSound(HANDLE * handle,int audioCode,int nSamplesPerSec=8000,int wBitsPerSample=16,int nChannels=1);
//��ʼ�ɼ�
HSAVPLAYER_API long __stdcall HS_StartCaptureSound(HANDLE handle);
//ֹͣ�ɼ�
HSAVPLAYER_API long __stdcall HS_StopCaptureSound(HANDLE handle);
//�رղɼ�����
HSAVPLAYER_API long __stdcall HS_CloseCaptureSound(HANDLE handle);

//6 ������Ƶ
HSAVPLAYER_API long __stdcall HS_OpenStreamRecord(char* filename,AV_STREAM_INFO* pStreamInfo, HANDLE * handle);

HSAVPLAYER_API long __stdcall HS_InputRecordData( HANDLE handle, char * buf, long lSize, AV_STREAM_INFO *pStream);
//7 �ر���Ƶ��, 
HSAVPLAYER_API long __stdcall HS_CloseStreamRecord( HANDLE handle );

#endif