#include <vld.h>
#include <string>
#include "returnedData.h"
#include "dictionaries.h"
#include "WordsWithPriorityCollection.h"
#include "AutoFiller.h"

AutoFill::AutoFill()
{

}

bool partialMatch(std::string* reservedWord, const std::string* testingWord)
{
	std::string::const_iterator it2 = testingWord->begin(), endIt2 = testingWord->end();
	if (reservedWord->length() > testingWord->length())
	{
		return false;
	}
	for (std::string::iterator it1 = reservedWord->begin(), endIt1 = reservedWord->end(); it1 != endIt1; it1++ ,it2++)
	{
		if (*(it1._Ptr) != *(it2._Ptr))
		{
			return false;
		}
	}
	return true;
}

void AutoFill::autoFilling(ReturnedData* insertingWord, Dictionaries* dictionaries, DictionaryPairLang* languge)
{
	std::string resevedWord = insertingWord->dropFitrsWordAndDestroyData();
	WordsWithPriority foundWords;

	Dictionary* dictionary = dictionaries->getDictionary(languge);
	dictionary->init();
	
	while (dictionary->isNext())
	{
		const std::string* testingWord = &dictionary->getNext()->first;
		if (partialMatch(&resevedWord, testingWord))
		{
			foundWords.addWordToCollection((size_t)(testingWord->length() - resevedWord.length()), const_cast<std::string*>(testingWord));
		}
	}
	foundWords.sortWords();
	insertingWord->setWords(foundWords.getWords());
}

AutoFill::~AutoFill()
{

}