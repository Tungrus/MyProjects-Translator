#pragma once

#include <thread>
#include <returnedData.h>
#include <AutoFiller.h>
#include "AutoFillWrapper.h"
#include <Windows.h>
#include <dictionaries.h>
#include <vld.h>

class ThreadControler
{
private:
	std::thread* mAutoFilingThread;
	bool work = true;
protected:
	IAutoFillWrapper* mFunk;
public:
	~ThreadControler();
	ThreadControler(IAutoFillWrapper* funk);
	void Launch(HWND comboBoxWindow, Dictionaries* dictionaries, DictionaryPairLang* lang);
	void setAutocomlitionData(ReturnedData* mThreadData, DictionaryPairLang* pair);
};