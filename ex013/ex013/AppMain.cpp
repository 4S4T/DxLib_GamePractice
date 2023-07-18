#include "DxLib.h"


int Sum(int para1, int para2)
{

	return para1 + para2;

}

int WINAPI WinMain(_In_HINSTANCE hInstance, _In_opt_HINSTANCE hPrevInstance, _In_LPSTR lpCmdLine, _in_int nShowCmd)

{

	int num = Sum(2, 3);

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)

	{

		return -1;

	}

}