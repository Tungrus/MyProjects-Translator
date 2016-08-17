#include <thread>
#include <returnedData.h>
#include <vld.h>
#include <Windows.h>
#include <dictionaries.h>
#include <AutoFiller.h>
#include "AutoFillWrapper.h"
#include "AutoFillerThreadControler.h"


ThreadControler::~ThreadControler()
{
	delete mFunk;
	delete mAutoFilingThread;
}

ThreadControler::ThreadControler(IAutoFillWrapper* funk)
{
	this->mFunk = funk;
}

void ThreadControler::setAutocomlitionData(ReturnedData* data,DictionaryPairLang* pair)
{
	this->mFunk->setData(data,pair);
}

void ThreadControler::Launch(HWND ListBox, Dictionaries* dictionaries, DictionaryPairLang* pair)
{
	auto a = [&, this](HWND _ListBox, Dictionaries* _dictionaries, DictionaryPairLang* _pair){this->mFunk->autoFillWrapper(_ListBox, dictionaries,_pair); };
	this->mAutoFilingThread = new std::thread(a, ListBox, dictionaries, pair);
	
	//mFunk->autoFillWrapper(ListBox, this->mThreadData, dictionaries);
	this->mAutoFilingThread->detach();
}
