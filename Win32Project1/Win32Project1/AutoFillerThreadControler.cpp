#include <thread>
#include <returnedData.h>

#include <Windows.h>
#include <dictionaries.h>
#include <AutoFiller.h>
#include "AutoFillWrapper.h"
#include "AutoFillerThreadControler.h"

ThreadControler::ThreadControler()
{
	this->mFunk = NULL;
	this->mAutoFilingThread = NULL;
	this->mThreadData = NULL;
}

ThreadControler::~ThreadControler()
{
	delete mFunk;
	delete mAutoFilingThread;
	delete mThreadData;
}

ThreadControler::ThreadControler(IAutoFillWrapper* funk, ReturnedData* data)
{
	this->mFunk = funk;
	this->mThreadData = data;
}

void ThreadControler::SetThread(IAutoFillWrapper* funk)
{
	this->mFunk = funk;
}

void ThreadControler::setData(ReturnedData* data)
{
	this->mThreadData = data;
}

void ThreadControler::Launch(HWND ListBox, Dictionaries* dictionaries)
{
	auto a = [&, this](HWND _ListBox, Dictionaries* _dictionaries, ReturnedData* _data){this->mFunk->autoFillWrapper(_ListBox, _data, dictionaries); };
	this->mAutoFilingThread = new std::thread(a, ListBox, dictionaries, this->mThreadData);
	
	//mFunk->autoFillWrapper(ListBox, this->mThreadData, dictionaries);
	this->mAutoFilingThread->detach();
}