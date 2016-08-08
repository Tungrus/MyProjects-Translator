#include <vector>
#include <map>
#include "SDictionary.h"
#include "stdafx.h"

void SDictionary::addString(std::pair<std::string, std::string>* pair_word)
{
	mDictionary->insert(*pair_word);
}

void SDictionary::setMap(std::map<std::string, std::string>* newMap)
{
	this->mDictionary = newMap;
}

SDictionary::SDictionary(std::map<std::string, std::string>* map)
{
	this->mDictionary = map;
}

SDictionary::SDictionary()
{
	this->mDictionary = new std::map<std::string,std::string>;
}

std::map<std::string,std::string>::iterator SDictionary::getNext()
{
	std::map<std::string, std::string>::iterator it = this->mCurrentIt;
	this->mCurrentIt++;
	return it;
}

bool SDictionary::isNext()
{
	if (this->mCurrentIt != this->mDictionary->end())
	{
		return true;
	}
	return false;
}

void SDictionary::init()
{
	this->mCurrentIt = this->mDictionary->begin();
}

std::string* SDictionary::getValue(std::string* newWord)
{
	return &(this->mDictionary->operator[](*newWord));
}