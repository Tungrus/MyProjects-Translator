#pragma once
#include <vld.h>


class IAutoComplete
{
public:
	virtual void autoFilling(ReturnedData* insertingWord, Dictionaries* dictionaries, DictionaryPairLang* languge) = 0;
};


class AutoFill : public IAutoComplete
{
public:
	AutoFill();
	void autoFilling(ReturnedData* insertingWord, Dictionaries* dictionaries, DictionaryPairLang* languge);
	~AutoFill();
};