// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� WIN32PROJECT1_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// WIN32PROJECT1_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef WIN32PROJECT1_EXPORTS
#define WIN32PROJECT1_API __declspec(dllexport)
#else
#define WIN32PROJECT1_API __declspec(dllimport)
#endif
#include <string>
#include<iostream>  
#include<stdio.h>  
#include<stdlib.h>
#include<windows.h>
#include<Winuser.h>
#include<string>
#include<fstream>
#include<ctime>

//��char*���Ͷ����ַ�����Ȼ����string���ã���Ȼc#����dllʱ������ڴ�����м�
extern "C" WIN32PROJECT1_API int MyGetKeyState(char* isRun, char* filePath);
extern "C" WIN32PROJECT1_API int SetIsRun(char* isRun);