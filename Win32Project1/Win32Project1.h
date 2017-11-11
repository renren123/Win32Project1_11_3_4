// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 WIN32PROJECT1_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// WIN32PROJECT1_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
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

//用char*类型定义字符串，然后用string引用，不然c#调用dll时会出现内存错误，切记
extern "C" WIN32PROJECT1_API int MyGetKeyState(char* isRun, char* filePath);
extern "C" WIN32PROJECT1_API int SetIsRun(char* isRun);