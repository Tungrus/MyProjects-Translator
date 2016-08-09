#pragma once

#include <Windows.h>

class IAutoFillWrapper
{
public:
	virtual void autoFillWrapper(HWND ListBox, ReturnedData* data, Dictionaries* dictionaries) = 0;
};

class AutoFillWrapper : public IAutoFillWrapper
{
public:
	AutoFillWrapper();
	void autoFillWrapper(HWND ListBox, ReturnedData* data, Dictionaries* dictionaries);
};