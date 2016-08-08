#pragma once
#include <map>
#include "stdafx.h"

class FUZZY_API SDictionary
{
private:
	int mType;
	std::map<std::string, std::string>* mDictionary;
	std::map<std::string, std::string>::iterator mCurrentIt;
public:
	SDictionary(std::map<std::string, std::string>* std);
	SDictionary();
	void init();
	bool isNext();
	int getType();
	void setType(int type);
	bool isAlredyExist(std::string* new_word);
	std::map<std::string, std::string>::iterator getNext();
	void setMap(std::map<std::string,std::string>* someWords);
	void addString(std::pair<std::string, std::string>* pair_word);
	std::string* getValue(std::string* newWord);
};

