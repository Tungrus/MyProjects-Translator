#pragma once

#include <thread>
#include <returnedData.h>
#include <AutoFiller.h>
#include "AutoFillWrapper.h"
#include <Windows.h>
#include <dictionaries.h>

class ThreadControler
{
private:
	
	std::thread* mAutoFilingThread;
	
	ReturnedData* mThreadData;
protected:
	IAutoFillWrapper* mFunk;
public:
	ThreadControler();//
	~ThreadControler();
	ThreadControler(IAutoFillWrapper* funk, ReturnedData* sendingData);
	void Launch(HWND comboBoxWindow, Dictionaries* dictionaries);
	void SetThread(IAutoFillWrapper* funk);
	void setData(ReturnedData* mThreadData);

};