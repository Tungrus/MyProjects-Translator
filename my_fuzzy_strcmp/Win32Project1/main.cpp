#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <vector>
#include "HWND_Singletone.h"

WNDCLASSEX Create_Class(HINSTANCE hInstance);
void Get_Text_From_EDIT();

//Global variables scope
HwndHolder* sing;
SuperString* returnedString;

void Get_Text_From_EDIT()
{
	LPSTR str = (LPSTR) new std::string;
	GetWindowText(sing->getEditWriterWindow(), str, GetWindowTextLength(sing->getEditWriterWindow()) + 1);
	std::vector<std::string*>* vector = new std::vector<std::string*>;
	vector->push_back((std::string*)str);
	returnedString->setSuperString(vector);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	if (Message == WM_CREATE)
	{
		//File_Reader reader;
		//sDictionaryParser parser;
		//std::string filename = "dict.txt";
		//static Dictionaries dictionaries(*parser.pars((reader.Read(reader.openStream(&filename)))));
	}
	else if (WM_COMMAND)
	{
		if ((HIWORD(wparam) == 0) && (LOWORD(wparam) == ID_BUTTON))
		{
			Get_Text_From_EDIT();
			LPSTR str = (LPSTR)returnedString->getSuperString()[0][0];
			SetWindowText(sing->getEditReaderWindow(), str);
		}
	}
	else if (WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}

class Application
{
 public:
	 WPARAM InitInstance(HINSTANCE hInstance, int nCmdShow);
};

WPARAM Application::InitInstance(HINSTANCE hInstance,int nCmdShow)
{
	sing = sing->getInstance();
	returnedString = returnedString->getInstance();
	WNDCLASSEX wcex = Create_Class(hInstance);
	if (!RegisterClassEx(&wcex)){
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;
	}
	sing->setMianeWindow(CreateWindow("asd", "Полноценная оконная процедура", WS_OVERLAPPED | WS_BORDER | WS_SYSMENU, 100, 100, 540, 720, HWND(NULL), NULL, HINSTANCE(hInstance), NULL));


	sing->setButtonWindow(CreateWindow("button", "Translate", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 20, 280, 100, 40, sing->getMianeWindow(), (HMENU)ID_BUTTON, NULL, NULL));//дублировать

	sing->setEditWriterWindow(CreateWindowEx(0, "EDIT", NULL, WS_CHILD | WS_VISIBLE |ES_LEFT | ES_AUTOVSCROLL, 10, 5, 505, 20, sing->getMianeWindow(), (HMENU)ID_COMBOBOX, NULL, NULL));

	sing->setListWindow(CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("listbox"), "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL, 10, 30, 505, 100, sing->getMianeWindow(), (HMENU)ID_EDIT, NULL, NULL));

	sing->setEditReaderWindow(CreateWindowEx(0, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL |
		ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | FALSE, 10, 150, 505, 100, sing->getMianeWindow(), (HMENU)ID_RESULT, NULL, NULL));

	SendMessage(sing->getEditReaderWindow(), EM_SETREADONLY, TRUE, NULL);

	ShowWindow(sing->getMianeWindow(), nCmdShow);
	ShowWindow(sing->getButtonWindow(), nCmdShow);
	ShowWindow(sing->getEditWriterWindow(), nCmdShow);
	ShowWindow(sing->getListWindow(), nCmdShow);
	ShowWindow(sing->getEditReaderWindow(), nCmdShow);
	UpdateWindow(sing->getMianeWindow());
	UpdateWindow(sing->getButtonWindow());
	UpdateWindow(sing->getEditWriterWindow());
	UpdateWindow(sing->getEditReaderWindow());
	UpdateWindow(sing->getListWindow());
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application app;
	return app.InitInstance(hInstance, nCmdShow);
}

WNDCLASSEX Create_Class(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	memset(&wcex, 0, sizeof(wcex));
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW - 2);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "asd";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	return wcex;
}