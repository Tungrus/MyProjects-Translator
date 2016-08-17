#pragma once
#include"dictionaries.h"
#include<vector>
#include"stdafx.h"
#include <vld.h>
class IDictionaryParser
{
public:
	virtual Dictionaries* pars(std::vector<std::string*>* filedata) = 0;
};

class FUZZY_API DictionaryParser : public IDictionaryParser
{
public:
	DictionaryParser();
	Dictionaries* pars(std::vector<std::string*>* filedata);
	~DictionaryParser();
};