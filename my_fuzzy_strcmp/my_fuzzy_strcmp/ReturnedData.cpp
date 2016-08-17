#include <vld.h>
#include <vector>
#include "returnedData.h"
#include "stdafx.h"

ReturnedData::ReturnedData()
{
	this->mSavedData = NULL;
}

ReturnedData::ReturnedData(std::vector<std::string*>* mReturnedWords)
{
	setWords(mReturnedWords);
}

ReturnedData::ReturnedData(std::string* returnedWord)
{
	this->mSavedData = new std::vector<std::string*>;
	mSavedData->push_back(returnedWord);
}

std::string* ReturnedData::getFirstWord()
{
	return this->mSavedData[0][0];
}

std::vector<std::string*>* ReturnedData::getWords()
{
	return this->mSavedData;
}

std::string* ReturnedData::getWordByNumber(int nomberOfWord)
{
	return this->mSavedData[0][nomberOfWord];
}

std::string ReturnedData::dropFitrsWordAndDestroyData()
{
	std::string* str = this->mSavedData[0][0];
	std::string str1 = *str;
	this->mSavedData->pop_back();
	delete str;
	delete this->mSavedData;
	return str1;
}

void ReturnedData::setWords(std::vector<std::string*>* mTranslatedWords)
{
	this->mSavedData = mTranslatedWords;
}

void ReturnedData::setFirstWord(std::string* returnedWord)
{
	this->mSavedData = new std::vector<std::string*>;
	mSavedData->push_back(returnedWord);
}

void ReturnedData::addWord(std::string* newWord)
{
	this->mSavedData->push_back(newWord);
}

ReturnedData::~ReturnedData()
{
	if (this->mSavedData != NULL)
	{
		for (std::string* name : *this->mSavedData)
		{
			delete name;
		}
		delete this->mSavedData;
	}
}

void ReturnedData::clearVector()
{
	this->mSavedData->clear();
}