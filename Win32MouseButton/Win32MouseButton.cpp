// Win32MouseButton.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Win32MouseButton.h"



POINT getMousePosition(POINT point)
{
	LONG zx = -1;
	LONG zy = -1;
	POINT ptB = { 0, 0 };
	LPPOINT xy = &ptB;  //λ�ñ���  
	GetCursorPos(xy);   //��ȡ��굱ǰλ��        
	return ptB;
}
string Int_to_String(int n)
{
	ostringstream stream;
	stream << n;  //nΪint����
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

