#pragma once
#include <vld.h>
#include "returnedData.h"
#include "dictionaries.h"
class ISeacher
{
public:
	virtual ReturnedData* SeachForMatchesInDictionary(std::string* str, Dictionary* dictionaries, int maxMistake) = 0;
};



class Seacher : public ISeacher
{
public:
	Seacher();
	ReturnedData* SeachForMatchesInDictionary(std::string* string, Dictionary* dictionaries, int maxMistake);
	~Seacher();
};
