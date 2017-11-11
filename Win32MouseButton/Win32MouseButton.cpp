// Win32MouseButton.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Win32MouseButton.h"



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
	return Int_to_String(a.x) + "/" + Int_to_String(a.y) + "/" + Int_to_String(b.x) + "/" + Int_to_String(b.y);
}
WIN32MOUSEBUTTON_API int GetMouseButtonUpDownPosition(int *a , int * b , int *c ,int *d)
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
			*a = xy1.x;
			*b = xy1.y;
			*c = xy2.x;
			*d = xy2.y;
			//MessageBox(NULL, GetPointStr(xy1, xy2).data(), "success", MB_OK);
			//*pointStr =  GetPointStr(xy1, xy2).data();
			return 1;
		}
		Sleep(5);
	}
}

