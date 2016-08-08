#include <vector>
#include <Windows.h>
#include <functional>
#include "View.h"

LRESULT CALLBACK WindProc(_In_ HWND hwnd, _In_ UINT Message, _In_ WPARAM wparam, _In_ LPARAM lparam);

View* View::myInstance = NULL;

WNDCLASSEX View::Create_Class(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	memset(&wcex, 0, sizeof(wcex));
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = &treateWndProc;
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
View::View(HINSTANCE hInstance, int nCmdShow, IActionCallback* actionCallback) : mActionCallback(actionCallback)
{
	WNDCLASSEX wcex = Create_Class(hInstance);
	if (!RegisterClassEx(&wcex)){
		MessageBox(NULL, ("Call to RegisterClassEx failed!"), ("Win32 Guided Tour"), NULL);
	}
	myInstance = this;

	this->hMainWnd = CreateWindow("asd", "Полноценная оконная процедура", WS_OVERLAPPED | WS_BORDER | WS_SYSMENU, 100, 100, 540, 720, HWND(NULL), NULL, HINSTANCE(hInstance), NULL);
	int a = GetLastError();
	this->hButoon = CreateWindow("button", "Seach", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 20, 280, 100, 40, hMainWnd, (HMENU)ID_BUTTON, NULL, NULL);//дублировать

	this->hTranslateButton = CreateWindow("button", "Translate", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 140, 280, 100, 40, hMainWnd, (HMENU)ID_TRANSLATEBUTTON, NULL, NULL);

	this->hEdit = CreateWindowEx(0, "EDIT", NULL, WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOVSCROLL, 10, 5, 505, 20, hMainWnd, (HMENU)ID_COMBOBOX, NULL, NULL);

	this->hList = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("listbox"), "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL, 10, 30, 505, 100, hMainWnd, (HMENU)ID_EDIT, NULL, NULL);

	this->hResult = CreateWindowEx(0, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL |
		ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | FALSE, 10, 150, 505, 100, hMainWnd, (HMENU)ID_RESULT, NULL, NULL);

	SendMessage(this->hResult, EM_SETREADONLY, TRUE, NULL);

	ShowWindow(this->hMainWnd, nCmdShow);
	ShowWindow(this->hButoon, nCmdShow);
	ShowWindow(this->hTranslateButton, nCmdShow);
	ShowWindow(this->hEdit, nCmdShow);
	ShowWindow(this->hList, nCmdShow);
	UpdateWindow(this->hMainWnd);
	UpdateWindow(this->hButoon);
	UpdateWindow(this->hTranslateButton);
	UpdateWindow(this->hEdit);
	UpdateWindow(this->hList);
}

MSG View::PollEvent()
{
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg;
}
View::~View()
{

}

HWND View::getMianeWindow()
{
	return this->hMainWnd;
}
HWND View::getButtonWindow()
{
	return this->hButoon;
}
HWND View::getTranslateButton()
{
	return this->hTranslateButton;
}
HWND View::getEditReaderWindow()
{
	return this->hEdit;
}
HWND View::getListWindow()
{
	return this->hList;
}
HWND View::getEditWriterWindow()
{
	return this->hResult;
}

IActionCallback* View::getIactionCallback()
{
	return this->mActionCallback;
}

LRESULT View::treateWndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	return myInstance->viewWndProc(hwnd, Message, wparam, lparam);
}

LRESULT View::viewWndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	if (Message == WM_CREATE)
	{
		this->getIactionCallback()->onCreateAction();
	}
	else if (Message == WM_CHAR)
	{
		this->getIactionCallback();
	}
	else if (Message == WM_COMMAND)
	{
		if (HIWORD(wparam) == 0)
		{
			if (LOWORD(wparam) == ID_BUTTON)
			{
				this->getIactionCallback()->onSeachAction();
			}
			else if (LOWORD(wparam) == ID_TRANSLATEBUTTON)
			{
				this->getIactionCallback()->onTranslateAction();
			}
		}
	}
	else if (Message == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}
