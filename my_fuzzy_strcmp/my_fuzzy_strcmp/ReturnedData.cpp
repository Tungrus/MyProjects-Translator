#include <vector>

#include "returnedData.h"
#include "stdafx.h"

returnedData::returnedData()
{
	this->mSavedData = NULL;
}
returnedData::~returnedData()
{
	this->mSavedData->clear();
	this->mSavedData = NULL;
}
returnedData::returnedData(std::vector<std::string*>* mReturnedWords)
{
	setWords(mReturnedWords);
}

returnedData::returnedData(std::string* returnedWord)
{
	this->mSavedData = new std::vector<std::string*>;
	mSavedData->push_back(returnedWord);
}

std::string* returnedData::getFirstWord()
{
	return this->mSavedData[0][0];
}
std::vector<std::string*>* returnedData::getWords()
{
	return this->mSavedData;
}
std::string* returnedData::getWordByNumber(int nomberOfWord)
{
	return this->mSavedData[0][nomberOfWord];
}

void returnedData::setWords(std::vector<std::string*>* mTranslatedWords)
{
	this->mSavedData = mTranslatedWords;
}
void returnedData::setFirstWord(std::string* returnedWord)
{
	this->mSavedData = new std::vector<std::string*>;
	mSavedData->push_back(returnedWord);
}