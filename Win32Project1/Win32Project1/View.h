#pragma once
#include <vld.h>
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
#define ID_EDIT 3000
#define ID_RESULT 82000
#define ID_TRANSLATEBUTTON 18000
#define ID_TRANSLATEDIRECTION 10000
#define ID_INPUT 19000

class IActionCallback
{
public:
	virtual void onGetingNewDictionaryAction() = 0;
	virtual void onTranslateAction() = 0;
	virtual void onSeachAction() = 0;
	virtual void onCharInputAtction() = 0;
	virtual void onCreateAction() = 0;
	virtual void onChooseLanguageAction() = 0;
};

class View
{
private:
	IActionCallback* mActionCallback;
	void Show();
	HWND hMainWnd, hList, hButoon, hResult, hEdit, hTranslateButton, hLangDropDown;
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
	HWND getHLangDropDown();
	MSG PollEvent();
	IActionCallback* getIactionCallback();

	static LRESULT CALLBACK treateWndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam);
};
