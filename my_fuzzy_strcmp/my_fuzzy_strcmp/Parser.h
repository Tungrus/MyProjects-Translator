#pragma once
#include"dictionaries.h"
#include<vector>
#include"stdafx.h"

class IParser
{
public:
	virtual Dictionaries* pars(std::vector<std::string*>* filedata) = NULL;
};

class FUZZY_API sDictionaryParser : public IParser
{
public:
	sDictionaryParser();
	Dictionaries* pars(std::vector<std::string*>* filedata);
};