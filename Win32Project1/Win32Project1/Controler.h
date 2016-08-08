#pragma once

#include <dictionaries.h>
#include <returnedData.h>

class Controler : private IActionCallback
{
private:
	View* mView;
	Dictionaries* mDictionaries;
	returnedData* mDataInListBox;

public:
	Controler(HINSTANCE hInstance, int nCmdShow);
	MSG Work();
	~Controler();
	void onTranslateAction();
	void onSeachAction();
	void onCharInputAtction();
	void onCreateAction();
};