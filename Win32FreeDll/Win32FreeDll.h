#ifdef WIN32FREEDLL_EXPORTS
#define WIN32FREEDLL_API __declspec(dllexport)
#else
#define WIN32FREEDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

extern "C" WIN32FREEDLL_API int MyMethod(char * myDll, char *methodName, char * theParameters);

//extern "C" WIN32FREEDLL_API int FreeDll();
extern "C" WIN32FREEDLL_API int FreeDll(char *Method);