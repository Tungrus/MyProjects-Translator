
#include <string>
#include "returnedData.h"
#include "dictionaries.h"
#include "AutoFiller.h"


AutoFill::AutoFill()
{

}

bool partialMatch(std::string* reservedWord, const std::string* testingWord)
{
	std::string::const_iterator it2 = testingWord->begin(), endIt2 = testingWord->end();
	
	for (std::string::iterator it1 = reservedWord->begin(), endIt1 = reservedWord->end(); it1 != endIt1; it1++ ,it2++)
	{
		if (it1._Ptr != it2._Ptr)
		{
			return false;
			break;
		}
	}
	return true;
}

void AutoFill::autoFilling(ReturnedData* insertingWord, Dictionaries* dictionaries)
{
	std::string resevedWord = insertingWord->dropFitrsWord();
	SDictionary* dictionary = dictionaries->getDictionary(&resevedWord);
	dictionary->init();
	
	while (dictionary->isNext())
	{
		const std::string* testingWord = &dictionary->getNext()->first;
		if (partialMatch(&resevedWord, testingWord))
		{
			insertingWord->addWord(const_cast<std::string*>(testingWord));
		}
	}
}