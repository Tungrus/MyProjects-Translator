#pragma once

#include <returnedData.h>
#include <dictionaries.h>
#include "AutoFillerThreadControler.h"
#include "OpenFilename.h"
#include "FileOpenCollection.h"
#include <vld.h>

class Controler : private IActionCallback
{
private:
	View* mView;
	ThreadControler* mThread;
	Dictionaries* mDictionaries;
	ReturnedData* mDataInListBox;
	DictionaryPairLang* mChoosenLang;
	//ReturnedData* mDataInCombobox;
	//OpenFileNamesCollection* mFiles;

public:

	Controler(HINSTANCE hInstance, int nCmdShow);

	MSG Work();

	~Controler();

	void onTranslateAction();
	void onSeachAction();
	void onCharInputAtction();
	void onCreateAction();
	void onGetingNewDictionaryAction();
	void onChooseLanguageAction();
};