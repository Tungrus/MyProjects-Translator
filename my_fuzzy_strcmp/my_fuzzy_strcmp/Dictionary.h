#pragma once
#include <map>
#include "stdafx.h"
#include <vld.h>
class FUZZY_API Dictionary
{
private:
	std::map<std::string, std::string>* mDictionary;
	std::map<std::string, std::string>::iterator mCurrentIt;
public:
	Dictionary();
	Dictionary(std::map<std::string, std::string>* std);

	void InsertData(std::string& key, std::string& value);

	void init();//
	bool isNext();//
	int getType();//Fix ME -> class DictinaryIteratorWrapper;
	bool isAlredyExist(std::string* new_word);//

	//void setType(int type);//

	
	std::map<std::string, std::string>::iterator getNext();

	void setMap(std::map<std::string,std::string>* someWords);
	void addString(std::pair<std::string, std::string>* pair_word);

	std::string* getValue(std::string* newWord);
	
	~Dictionary();
};

