#pragma once

#include <dictionaries.h>
#include <returnedData.h>
#include "AutoFillerThreadControler.h"

class Controler : private IActionCallback
{
private:
	View* mView;
	Dictionaries* mDictionaries;
	ReturnedData* mDataInListBox;
	ThreadControler* mThread;
public:
	Controler(HINSTANCE hInstance, int nCmdShow);
	MSG Work();
	~Controler();
	void onTranslateAction();
	void onSeachAction();
	void onCharInputAtction();
	void onCreateAction();
};