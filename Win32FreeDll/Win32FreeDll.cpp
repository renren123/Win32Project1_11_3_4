// Win32FreeDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Win32FreeDll.h"
#define myError -1

HMODULE hModule;

typedef int(*pGetMaxN_0)();
typedef int(*pGetMaxN_1)(char *);
typedef int(*pGetMaxN_2)(char *, char *);
typedef int(*pGetMaxN_3)(char *, char *, char *);
typedef int(*pGetMaxN_4)(char *, char *, char *, char *);
typedef int(*pGetMaxN_5)(string, string, string, string, string);

//�ָ��ַ���
string * splitStr(string str)
{
	string  *splitStrig = new string[3];
	int countStr = 0;//�ָ���ַ�����ָ��
	int index = -1;//Ҫ�ָ���ŵ����
	int indexLast = 0;//��һ��index��λ��
	char splitChar = '/';
	while ((index = str.find(splitChar, index + 1)) != -1)
	{
		splitStrig[countStr++] = str.substr(indexLast, index - indexLast);
		indexLast = index + 1;
	}
	splitStrig[countStr++] = str.substr(indexLast, str.length() - indexLast);
	return splitStrig;
}
//���ڷָ��ַ���
string trim(string theStr)
{
	string theString = theStr;
	while (theString.length()>0 && (theString[0] == ' ' || theString[theString.length() - 1] == ' '))
	{
		if (theString[0] == ' ')
		{
			theString = theString.substr(1, theString.length() - 1);
		}
		else
		{
			theString = theString.substr(0, theString.length() - 1);
		}
	}
	return theString;
}
//���������ԡ�/���ָ����ֿ������һ��ֵ�ǲ����ĸ�����������10
WIN32FREEDLL_API int MyMethod(char * myDll, char *methodName, char * theParameters)
{
	if (trim(myDll).empty()||trim(methodName).empty()||trim(theParameters).empty())
	{
		return myError;
	}
	/*string messageAll = myDll;
	messageAll += "/";
	messageAll += methodName;
	messageAll += "/";
	messageAll += theParameters;
	MessageBox(NULL, messageAll.data(), "Error", MB_OK);*/

	string dllName = trim(myDll);
	hModule = LoadLibrary(dllName.data());
	if (hModule == NULL)
	{
		/*string message = myDll;
		message = "�Ҳ����ļ���" + message;
		message += ",MyMethod��HMODULEΪNULL��dll�ļ���Ϊ��" + dllName;
		MessageBox(NULL, message.data(), "Error", MB_OK);*/
		return NULL;
	}
	string myParameters = trim(theParameters);
	if (myParameters.empty())
	{
		//MessageBox(NULL, "MyMethod��theParametersΪNULL", "Error", MB_OK);
		return myError;
	}
	int parameterCount = myParameters[myParameters.length() - 1] - '0';
	string *splitString = splitStr(myParameters);

	switch (parameterCount)
	{
	case 0:
	{
		pGetMaxN_0 pgetm_0 = (pGetMaxN_0)GetProcAddress(hModule, methodName);
		return pgetm_0();
	}
	break;
	case 1:
	{
		pGetMaxN_1 pgetm_1 = (pGetMaxN_1)GetProcAddress(hModule, methodName);
		return pgetm_1(const_cast<char*>(splitString[0].data()));
	}
	break;
	case 2:
	{
		pGetMaxN_2 pgetm_2 = (pGetMaxN_2)GetProcAddress(hModule, methodName);
		//char* p = const_cast<char*>(str.c_str());
		pgetm_2(const_cast<char*>(splitString[0].data()), const_cast<char*>(splitString[parameterCount - 1].data()));
		//MessageBox(NULL, splitString[parameterCount - 1].data(), "Success", MB_OK);
		return 1;

	}
	break;
	case 3:
	{
		pGetMaxN_3 pgetm_3 = (pGetMaxN_3)GetProcAddress(hModule, methodName);
		return pgetm_3(const_cast<char*>(splitString[0].data()), const_cast<char*>(splitString[1].data()), const_cast<char*>(splitString[2].data()));
	}
	break;
	default:
	{
		stringstream ss;
		ss << parameterCount;
		string parameterCountStr = "";
		ss >> parameterCountStr;
		parameterCountStr = "MyMethod�Ĳ�����ĿΪ" + parameterCountStr;
		MessageBox(NULL, parameterCountStr.data(), "Error", MB_OK);
		return myError;
	}
	}
	return 1;
}


//����-1��ʾΪ�գ������ʾ�ɹ������ʾʧ�ܣ����dll�ṩ�˽������̵ĺ�����
//Ӧ�Ƚ����������ͷ�����,���û�к�����������Ϊ��
WIN32FREEDLL_API int FreeDll(char *Method)
{
	if (hModule != NULL)
	{
		string method = Method;
		if (!method.empty() && !trim(method).empty()) //��֤Method�ַ����Ƿ�Ϊ��
		{
			pGetMaxN_1 pgetm_1 = (pGetMaxN_1)GetProcAddress(hModule, Method);
			if (pgetm_1("false") != 1)
			{
				MessageBox(NULL, "FreeDll->pGetMaxN_0����","Error",MB_OK);
				return myError;
			}
			Sleep(10);
		}
		
		if (FreeLibrary(hModule) != 0)
		{
			hModule = NULL;
			return 1;
		}
		else
		{
			MessageBox(NULL, "FreeLibrary(hModule)", "Error", MB_OK);
			return myError;
		}
	}
	else
		return NULL;
}
