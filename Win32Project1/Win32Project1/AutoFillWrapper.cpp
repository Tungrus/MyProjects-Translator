#include <string>
#include <Windows.h>
#include <returnedData.h>
#include <vld.h>
#include <dictionaries.h>
#include <Windows.h>
#include <condition_variable>
#include <AutoFiller.h>
#include "AutoFillWrapper.h"

void AutoFillWrapper::SendDataToWindow(HWND window)
{
	for (std::string* name : this->mData->getWords()[0])
	{
		SendMessage(window, CB_ADDSTRING, 0, (LPARAM)name->c_str());
	}
}

AutoFillWrapper::AutoFillWrapper()
{
	mNeedToProcess.store(false);
	mIsStoped.store(false);
	this->mAutocompleteInUse.store(false);
}

void AutoFillWrapper::setData(ReturnedData* data, DictionaryPairLang* mChoosenLang)
{
	if (mAutocompleteInUse.load() == true)
		return;

	this->mNeedToProcess = false;
	this->mData = data;
	this->mChoosenLang = mChoosenLang;
	this->mCondSetData.notify_all();
}

void AutoFillWrapper::autoFillWrapper(HWND lisBox, Dictionaries* dictionaries, DictionaryPairLang* pair)
{
	while (!isStopRequsted())
	{
		std::unique_lock<std::mutex> ld(this->mMutexSetData);
		this->mCondSetData.wait(ld);
		if (isStopRequsted())
			return;

		mAutocompleteInUse.store(true);
		//IAutoFillWrapper* filer = new AutoFillWrapper();
		AutoFill autofil;
		autofil.autoFilling(this->mData, dictionaries, pair);
		if (mData->getWords()->size() != 0)
		{
			SendDataToWindow(lisBox);
		}
		mData->clearVector();
		delete mData;
		mData = NULL;
		mAutocompleteInUse.store(false);
	}
}

void AutoFillWrapper::requestStop()
{
	this->mIsStoped.store(true);
}

bool AutoFillWrapper::isStopRequsted() const
{
	return this->mIsStoped.load();
}

AutoFillWrapper::~AutoFillWrapper()
{
	this->mIsStoped = true;
	this->mChoosenLang = NULL;
	this->mData = NULL;
}