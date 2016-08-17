#pragma once
#include <vld.h>

#define ID_BUTTON 64000
#define ID_COMBOBOX 70000
#define ID_RESULT 82000
#define ID_TRANSLATEBUTTON 18000
/*
class HwndHolder
{
private:
	static HwndHolder* instance;
	HwndHolder() : hMainWnd(0), hList(0), hButoon(0), hResult(0), hEdit(0),hTranslateButton(0) {}
	~HwndHolder();
	HWND hMainWnd, hList, hButoon, hResult, hEdit, hTranslateButton;
public:
	static HwndHolder* getInstance();
	void init(HINSTANCE hInstance);

	HWND getMianeWindow();
	HWND getButtonWindow();
	HWND getEditReaderWindow();
	HWND getListWindow();
	HWND getEditWriterWindow();
	HWND getTranslateButton();

	void HwndHolder::setTranslateButton(HWND wnd);
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
};*/