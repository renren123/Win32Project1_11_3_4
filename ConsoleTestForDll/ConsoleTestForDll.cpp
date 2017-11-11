// ConsoleTestForDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
//GetAsyncKeyState是一个用来判断函数调用时指定虚拟键的状态，确定用户当前是否按下了键盘上的一个键的函数。如果按下，则返回值最高位为1。
//&运算符是各位与运算，最如0010 & 0011 = 0010
//VK_NONAME :指定256个可能的虚拟键盘值中的一个.
//256个虚拟值所以是4位16进制的数0x8000的0x表示16进制 ， 下面这个判断语句是判断GetAsyncKeyState的返回值最高位是否为1
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的 
#include <sstream>
using namespace std;

typedef int(*pGetMaxN)(bool, string);
typedef void(*pShowMsg)(string, string);

string * splitStr(char* a)
{	
	string  *splitStrig = new string[3];
	int countStr = 0;//分割后字符串的指针
	int index = -1;//要分割符号的序号
	int indexLast = 0;//上一个index的位置
	string str = a;
	char splitChar = '/';
	while((index= str.find(splitChar, index + 1))!=-1)
	{
		splitStrig[countStr++] = str.substr(indexLast, index - indexLast);
		indexLast = index+1;
	} 
	splitStrig[countStr++] = str.substr(indexLast, str.length()-indexLast);
	return splitStrig;
}
string trim(char * theStr)
{
	string theString = theStr;
	while (theString[0]==' '|| theString[theString.length()-1]==' ')
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
void getMousePosition()
{
	LONG zx = -1;
	LONG zy = -1;
	POINT ptB = { 0, 0 };
	while (1)
	{
		LPPOINT xy = &ptB;  //位置变量  
		GetCursorPos(xy);   //获取鼠标当前位置        
							//如果鼠标移动，（即当前的坐标改变则打印出坐标）打印出做坐标。  
		if ((zx != xy->x) || (zy != xy->y))
		{
			printf("x=%d,y=%d\n", xy->x, xy->y);
			zx = xy->x;
			zy = xy->y;
		}
	}
}
void getMoustClick()
{
	while (1)
	{
		printf("鼠标左键是否按下：");
		if (KEY_DOWN(VK_LBUTTON))printf("是");
		else printf("否");
		printf("\n");

		printf("鼠标右键是否按下：");
		if (KEY_DOWN(VK_RBUTTON))printf("是");
		else printf("否");
		printf("\n");

		printf("鼠标滚轮键是否按下：");
		if (KEY_DOWN(VK_MBUTTON))printf("是");
		else printf("否");
		printf("\n");

		Sleep(20);//循环时间间隔，防止太占内存 
		system("cls");//清屏 
	}
}
//void getPicture()
//{
//	<strong>	//获取桌面窗口的CDC
//		CDC *pdeskdc = GetDesktopWindow()->GetDC();
//	CRect re;
//	//获取窗口的大小
//	GetDesktopWindow()->GetClientRect(&re);
//	CBitmap bmp;
//	bmp.CreateCompatibleBitmap(pdeskdc, re.Width(), re.Height());
//	//创建一个兼容的内存画板
//	CDC memorydc;
//	memorydc.CreateCompatibleDC(pdeskdc);
//
//	//选中画笔
//	CBitmap *pold = memorydc.SelectObject(&bmp);
//
//	//绘制图像
//	memorydc.BitBlt(0, 0, re.Width(), re.Height(), pdeskdc, 0, 0, SRCCOPY);
//
//	//获取鼠标位置，然后添加鼠标图像
//	CPoint po;
//	GetCursorPos(&po);
//	HICON hinco = (HICON)GetCursor();
//	memorydc.DrawIcon(po.x - 10, po.y - 10, hinco);
//	//选中原来的画笔
//	memorydc.SelectObject(pold);
//	BITMAP bit;
//	bmp.GetBitmap(&bit);
//	//	DWORD size = bit.bmWidth * bit.bmHeight ;
//
//	//定义 图像大小（单位：byte）
//	DWORD size = bit.bmWidthBytes * bit.bmHeight;
//	LPSTR lpdata = (LPSTR)GlobalAlloc(GPTR, size);
//
//	//后面是创建一个bmp文件的必须文件头，想要了解可以参考msdn
//
//	BITMAPINFOHEADER pbitinfo;
//	pbitinfo.biBitCount = 24;
//	pbitinfo.biClrImportant = 0;
//	pbitinfo.biCompression = BI_RGB;
//	pbitinfo.biHeight = bit.bmHeight;
//	pbitinfo.biPlanes = 1;
//	pbitinfo.biSize = sizeof(BITMAPINFOHEADER);
//	pbitinfo.biSizeImage = size;
//	pbitinfo.biWidth = bit.bmWidth;
//	pbitinfo.biXPelsPerMeter = 0;
//	pbitinfo.biYPelsPerMeter = 0;
//
//	GetDIBits(pdeskdc->m_hDC, bmp, 0, pbitinfo.biHeight, lpdata,
//		(BITMAPINFO*)&pbitinfo, DIB_RGB_COLORS);
//
//	BITMAPFILEHEADER bfh;
//	bfh.bfReserved1 = bfh.bfReserved2 = 0;
//	bfh.bfType = ((WORD)('M' << 8) | 'B');
//	bfh.bfSize = 54 + size;
//	bfh.bfOffBits = 54;
//
//	//写入文件
//
//	CFile file;
//	if (file.Open("1.bmp", CFile::modeCreate | CFile::modeWrite))
//	{
//		file.WriteHuge(&bfh, sizeof(BITMAPFILEHEADER));
//		file.WriteHuge(&pbitinfo, sizeof(BITMAPINFOHEADER));
//		file.WriteHuge(lpdata, size);
//		file.Close();
//	}
//	GlobalFree(lpdata); </strong>
POINT getMousePosition(POINT point)
{
	LONG zx = -1;
	LONG zy = -1;
	POINT ptB = { 0, 0 };
	LPPOINT xy = &ptB;  //位置变量  
	GetCursorPos(xy);   //获取鼠标当前位置        
	return ptB;
}
string Int_to_String(int n)
{
	ostringstream stream;
	stream << n;  //n为int类型
	return stream.str();
}
string GetPointStr(POINT a, POINT b)
{
	return Int_to_String(a.x)+"/"+ Int_to_String(a.y)+"/"+ Int_to_String(b.x)+"/"+ Int_to_String(b.y);
}
int main()
{
	POINT xy1 = { 0, 0 };
	POINT xy2 = { 0, 0 };

	while (true)
	{
		if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000))
		{
			xy1 = getMousePosition(xy1);
			while ((GetAsyncKeyState(VK_LBUTTON) & 0x8000))
			{
				Sleep(5);
			}
			xy2 = getMousePosition(xy2);
			MessageBox(NULL, GetPointStr(xy1, xy2).data(), "success", MB_OK);
			//cout << GetPointStr(xy1, xy2) << endl;
			return 0;
		}
		Sleep(5);
	}
	/*VK_LBUTTON 鼠标左键
		VK_RBUTTON 鼠标右键*/
	//getMoustClick();
	/*cout << MOUSE_MOVED << "  " << MOUSE_EVENT << "  " << MOUSE_WHEELED<<endl;
	cout << VK_LBUTTON << "  " << VK_RBUTTON <<"  "<<VK_MBUTTON<< endl;*/
	/*string a = "123/234/467";
	string *str;
	str=splitStr("123/234/467");
	for (size_t i = 0; i < 3; i++)
	{
		cout << str[i] << endl;
	}*/
	/*while (str++)
	{
		cout << str << endl;
	}*/

	/*
	string dllName = "Win32Project1.dll";

	HMODULE hModule = LoadLibrary(dllName.data());
	if (hModule ==NULL)
	{
		cout << "Error!" << endl;
		return 0;
	}
	pGetMaxN pgetm = (pGetMaxN)GetProcAddress(hModule, "MyGetKeyState");
	cout << "结果：" << endl;
	cout << pgetm(true, "1111.txt") << endl;

	FreeLibrary(hModule);
	*/
	
	/*cout << WinExec("WpfApplication.exe",SW_SHOW) << endl;
	cout << ShellExecute(NULL, "open", "shutdown.exe", "-r -c haha -t 30", NULL, SW_SHOW) << endl;
	*/
	
	
	
	/*char ExePath[MAX_PATH];
	char ExePath2[MAX_PATH];
	GetModuleFileName(NULL, ExePath, MAX_PATH);
	GetCurrentDirectory(MAX_PATH, ExePath2);
	printf(ExePath);
	printf("\n");
	printf(ExePath2);
	printf("\n");
	string path = "\"C:\\Users\\13643\\Documents\\Visual Studio 2015\\Projects\\Win32Project1\\Debug\\WpfApplication.exe\"";
	string exeName = "WpfApplication.exe";
	string filePath = ExePath2;
	string fpath ="\""+ filePath + "\\" + exeName+"\"";
	cout << system(fpath.data()) << endl;
	system("pause");*/
    return 0;
}

