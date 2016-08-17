#include <algorithm>
#include <utility>
#include <vector>
#include <vld.h>
#include "WordsWithPriorityCollection.h"


WordsWithPriority::WordsWithPriority()
{
	this->mWordsInCollection = new std::vector<std::pair<size_t, std::string*>*>;
}

void WordsWithPriority::addWordToCollection(std::pair<size_t, std::string*>* pairWord_Priority)
{
	this->mWordsInCollection->push_back(pairWord_Priority);
}

void WordsWithPriority::addWordToCollection(size_t nomber, std::string* word)
{
	this->mWordsInCollection->push_back(new std::pair<size_t, std::string*>(nomber, word));
}

bool Is_NeedToReplase(std::pair<size_t, std::string*>* firstElement, std::pair<size_t, std::string*>* secondElement)
{
	if (firstElement->first > secondElement->first)
	{
		return false;
	}
	else if (firstElement->first < secondElement->first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void WordsWithPriority::sortWords()
{
	std::sort(this->mWordsInCollection->begin(), this->mWordsInCollection->end(), Is_NeedToReplase);
}

std::vector<std::string*>* WordsWithPriority::getWords()
{
	std::vector<std::string*>* sortedSequnceWords = new std::vector<std::string*>;
	for (std::pair<size_t, std::string*>* pair : *this->mWordsInCollection)
	{
		sortedSequnceWords->push_back(pair->second);
	}
	return sortedSequnceWords;
}

WordsWithPriority::~WordsWithPriority()
{
	for (std::pair<size_t, std::string*>* pair : *this->mWordsInCollection)
	{
		delete pair;
	}
	this->mWordsInCollection->clear();
	delete this->mWordsInCollection;
}