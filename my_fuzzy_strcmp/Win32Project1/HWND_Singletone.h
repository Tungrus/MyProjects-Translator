#pragma once

#include <Windows.h>

#define ID_BUTTON 64000
#define ID_COMBOBOX 70000
#define ID_EDIT 76000
#define ID_RESULT 82000

class HwndHolder
{
private:
	static HwndHolder* instance;
	HwndHolder() : hMainWnd(0), hList(0), hButoon(0), hResult(0), hEdit(0) {}
	~HwndHolder();
	HWND hMainWnd, hList, hButoon, hResult, hEdit;
public:
	static HwndHolder* getInstance();
	void init(HINSTANCE hInstance);
	HWND getMianeWindow();
	HWND getButtonWindow();
	HWND getEditReaderWindow();
	HWND getListWindow();
	HWND getEditWriterWindow();
	void HwndHolder::setMianeWindow(HWND wnd);
	void HwndHolder::setButtonWindow(HWND wnd);
	void HwndHolder::setEditReaderWindow(HWND wnd);
	void HwndHolder::setListWindow(HWND wnd);
	void HwndHolder::setEditWriterWindow(HWND wnd);
};

class SuperString
{
private:
	static SuperString* instance;
	std::vector<std::string*>* reseved_data;
	SuperString();
	~SuperString();
public:
	void setSuperString(std::vector<std::string*> * new_liens);
	static SuperString* getInstance();
	std::vector<std::string*> * getSuperString();
};
