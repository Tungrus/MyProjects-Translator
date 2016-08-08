#pragma once

/*
class IObserver
{
public:
	virtual void handleEvent() = 0;
};

class Observer : public IObserver
{
public:
	void handleEvenet();
};

class IObservale
{
public:
	virtual void AddObserver(IObserver* o) = 0;
	virtual void RemoveObserver(IObserver* o) = 0;
	virtual void NotifyObserver() = 0;
};

class Observable : public IObservale
{
protected:
	std::vector<IObserver> mObservers;
public:
	void AddObserver(IObserver* o);
	void RemoveObserver(IObserver* o);
	void NotifyObserver();
};
*/
#define ID_BUTTON 64000
#define ID_COMBOBOX 70000
#define ID_EDIT 76000
#define ID_RESULT 82000
#define ID_TRANSLATEBUTTON 18000

#include <Windows.h>

class IActionCallback
{
public:
	virtual void onTranslateAction() = 0;
	virtual void onSeachAction() = 0;
	virtual void onCharInputAtction() = 0;
	virtual void onCreateAction() = 0;
};

class View
{
private:
	IActionCallback* mActionCallback;
	void Show();
	HWND hMainWnd, hList, hButoon, hResult, hEdit, hTranslateButton;
	static View* myInstance;
	LRESULT viewWndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam);
	
public:
	View(HINSTANCE hInstance, int nCmdShow, IActionCallback* actionCallback);
	~View();
	WNDCLASSEX Create_Class(HINSTANCE hInstance);
	HWND getMianeWindow();
	HWND getButtonWindow();
	HWND getEditReaderWindow();
	HWND getListWindow();
	HWND getEditWriterWindow();
	HWND getTranslateButton();
	MSG PollEvent();
	IActionCallback* getIactionCallback();

	static LRESULT CALLBACK treateWndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam);

	/*if ((HIWORD(wparam) == 0))
			{
				if (LOWORD(wparam) == ID_BUTTON)
				{
					if (vector != NULL)
					{
						delete(vector);
						vector = NULL;
					}
					eraseTextFromListBox();
					Get_Text_From_EDIT();
					std::string* str1 = returnedString->getSuperString()[0][0];
					if (str1->length() != 0)
					{
						vector = correcter.CorrectWord(returnedString->getSuperString()[0][0], dictionaries.getDictionary(returnedString->getSuperString()[0][0]), 2);
						for (std::string* name : *vector)
						{
							SendMessage(sing->getListWindow(), LB_ADDSTRING, 0, (LPARAM)(name)->c_str());
						}
					}
					delete str1;
				}
				else if (LOWORD(wparam) == ID_TRANSLATEBUTTON)
				{
					int lbItem = (int)SendMessage(sing->getListWindow(), LB_GETCURSEL, 0, 0);
					int i = (int)SendMessage(sing->getListWindow(), LB_GETITEMDATA, lbItem, 0);
					if (i >= 0)
					{
						SetWindowText(sing->getEditReaderWindow(), dictionaries.getDictionary((vector[0][lbItem]))->getValue(vector[0][lbItem]).c_str());
					}
				}
			}*/
};
