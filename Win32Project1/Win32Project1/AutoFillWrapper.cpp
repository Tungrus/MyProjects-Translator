#include <string>
#include <Windows.h>
#include <returnedData.h>

#include <dictionaries.h>
#include <AutoFiller.h>
#include "AutoFillWrapper.h"

void SendDataToWindow(HWND window, ReturnedData* data)
{
	for (std::string* name : data->getWords()[0])
	{
		SendMessage(window, CB_ADDSTRING, 0, (LPARAM)name->c_str());
	}
}

AutoFillWrapper::AutoFillWrapper()
{

}

void AutoFillWrapper::autoFillWrapper(HWND lisBox, ReturnedData* data, Dictionaries* dictionaries)
{
	IAutoFillWrapper* filer = new AutoFillWrapper();
	AutoFill autofil;
	autofil.autoFilling(data, dictionaries);
	SendDataToWindow(lisBox, data);
}