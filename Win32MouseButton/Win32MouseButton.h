// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� WIN32MOUSEBUTTON_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// WIN32MOUSEBUTTON_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#ifdef WIN32MOUSEBUTTON_EXPORTS
#define WIN32MOUSEBUTTON_API __declspec(dllexport)
#else
#define WIN32MOUSEBUTTON_API __declspec(dllimport)
#endif

extern "C" WIN32MOUSEBUTTON_API int GetMouseButtonUpDownPosition(int *a, int * b, int *c, int *d);
