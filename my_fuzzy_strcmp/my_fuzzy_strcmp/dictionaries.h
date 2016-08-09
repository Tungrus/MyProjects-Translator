#pragma once

#include "stdafx.h"
#include "SDictionary.h"
#include <vector>

class FUZZY_API Dictionaries
{
private:
	std::vector<std::pair<SDictionary*, SDictionary*>*>* mDictionaries;
	SDictionary* getDictionaryByLang(std::string* newWord);
public:
	Dictionaries();
	Dictionaries(SDictionary* first, SDictionary* second);
	SDictionary* getDictionary(std::string* newWord);
	void addPairDict(SDictionary* first, SDictionary* second);
	void initFromFile(std::string* filename);
};