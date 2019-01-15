// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LIBTHREAD_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LIBTHREAD_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifndef __BASICLIBRARY_INCLUDE_LIBTHREAD_H__
#define __BASICLIBRARY_INCLUDE_LIBTHREAD_H__

#ifdef WIN32

#ifdef LIBTHREAD_EXPORTS
#define LIBTHREAD_API __declspec(dllexport)
#else
#define LIBTHREAD_API __declspec(dllimport)
#endif

#else //WIN32
#define LIBTHREAD_API 
#endif //WIN32


#endif //__BASICLIBRARY_INCLUDE_LIBTHREAD_H__
