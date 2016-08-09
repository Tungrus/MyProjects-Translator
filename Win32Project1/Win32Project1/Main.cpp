#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <vector>
#include <list>
#include"View.h"
#include"Controler.h"

#include "hwndSingletone.h"
#include <Word_Correcter.h>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Controler controler(hInstance,nCmdShow);

	return controler.Work().wParam;
}