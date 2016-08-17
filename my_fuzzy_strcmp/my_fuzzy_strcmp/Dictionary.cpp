#include <vector>
#include <map>
#include "Dictionary.h"
#include <vld.h>
#include "stdafx.h"

void Dictionary::addString(std::pair<std::string, std::string>* pair_word)
{
	mDictionary->insert(*pair_word);
}

void Dictionary::setMap(std::map<std::string, std::string>* newMap)
{
	this->mDictionary = newMap;
}

Dictionary::Dictionary(std::map<std::string, std::string>* map)
{
	this->mDictionary = map;
}

Dictionary::Dictionary()
{
	this->mDictionary = new std::map<std::string,std::string>;
}

std::map<std::string,std::string>::iterator Dictionary::getNext()
{
	std::map<std::string, std::string>::iterator it = this->mCurrentIt;
	this->mCurrentIt++;
	return it;
}

bool Dictionary::isNext()
{
	if (this->mCurrentIt != this->mDictionary->end())
	{
		return true;
	}
	return false;
}

void Dictionary::init()
{
	this->mCurrentIt = this->mDictionary->begin();
}

std::string* Dictionary::getValue(std::string* newWord)
{
	return &(this->mDictionary->operator[](*newWord));
}

Dictionary::~Dictionary()
{
	delete this->mDictionary;
}

void Dictionary::InsertData(std::string& dataToInsert, std::string& key)
{
	if (this->mDictionary->operator[](key) == "")
	{
		this->mDictionary->operator[](key) = dataToInsert;
	}
	else
	{
		this->mDictionary->operator[](key) += ", " + dataToInsert;
	}
}