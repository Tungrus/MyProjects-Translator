#include<vector>
#include"hwndSingletone.h"

HwndHolder* HwndHolder::instance = NULL;
SuperString* SuperString::instance = NULL;

void HwndHolder::init(HINSTANCE hInstance)
{

}

HWND HwndHolder::getMianeWindow()
{
	return this->hMainWnd;
}
HWND HwndHolder::getButtonWindow()
{
	return this->hButoon;
}
HWND HwndHolder::getTranslateButton()
{
	return this->hTranslateButton;
}
HWND HwndHolder::getEditReaderWindow()
{
	return this->hEdit;
}
HWND HwndHolder::getListWindow()
{
	return this->hList;
}
HWND HwndHolder::getEditWriterWindow()
{
	return this->hResult;
}

void HwndHolder::setTranslateButton(HWND wnd)
{
	this->hTranslateButton = wnd;
}
void HwndHolder::setMianeWindow(HWND wnd)
{
	this->hMainWnd = wnd;
}
void HwndHolder::setButtonWindow(HWND wnd)
{
	this->hButoon = wnd;
}
void HwndHolder::setEditReaderWindow(HWND wnd)
{
	this->hEdit = wnd;
}
void HwndHolder::setListWindow(HWND wnd)
{
	this->hList = wnd;
}
void HwndHolder::setEditWriterWindow(HWND wnd)
{
	this->hResult = wnd;
}

HwndHolder* HwndHolder::getInstance()
{
	if (instance == NULL)
	{
		instance = new HwndHolder;
	}
	return instance;
}

SuperString::SuperString()
{
	this->reseved_data = NULL;
}

void SuperString::setSuperString(std::vector<std::string*>* str)
{
	if (reseved_data != NULL)
	{
		delete(reseved_data);
	}
	reseved_data = str;
}
std::vector<std::string*>* SuperString::getSuperString()
{
	return reseved_data;
}
SuperString* SuperString::getInstance()
{
	if (instance == NULL)
	{
		instance = new SuperString;
	}
	return instance;
}
