#pragma once
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <condition_variable>
#include <returnedData.h>
#include <vld.h>

class IAutoFillWrapper
{
public:
	virtual void autoFillWrapper(HWND ListBox, Dictionaries* dictionaries, DictionaryPairLang* lang) = 0;
	virtual void setData(ReturnedData* data, DictionaryPairLang* mChoosenLang) = 0;
};

class AutoFillWrapper : public IAutoFillWrapper
{
	bool isStopRequsted() const;
	std::atomic<bool> mNeedToProcess;
	std::atomic<bool> mIsStoped;
	std::atomic<bool> mAutocompleteInUse;
	ReturnedData* mData;
	std::mutex mDataMutex;
	std::mutex mMutexSetData;
	std::condition_variable mCondSetData;
	void SendDataToWindow(HWND window);
	DictionaryPairLang* mChoosenLang;
public:
	AutoFillWrapper();
	void requestStop();
	void autoFillWrapper(HWND ListBox, Dictionaries* dictionaries, DictionaryPairLang* lang);
	void setData(ReturnedData* data, DictionaryPairLang* mChoosenLang);
	~AutoFillWrapper();
};