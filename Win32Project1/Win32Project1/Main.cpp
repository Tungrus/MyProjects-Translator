#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <vector>
#include <list>
#include "View.h"
#include "Controler.h"
#include "hwndSingletone.h"
#include <WordCorrecter.h>
#include <vld.h>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	Controler controler(hInstance,nCmdShow);
	controler.onCreateAction();
	auto v = controler.Work().wParam;
	//controler.onCloseAppActon();
	return v;
}