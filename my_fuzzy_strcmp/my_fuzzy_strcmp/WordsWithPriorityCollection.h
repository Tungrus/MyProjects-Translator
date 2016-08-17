#pragma once 
#include <vld.h>
class WordsWithPriority
{
public:
	WordsWithPriority();

	void addWordToCollection(std::pair<size_t,std::string*>* pairWord_Priority);
	void addWordToCollection(size_t nomber, std::string* word);

	void sortWords();

	std::vector<std::string*>* getWords();

	~WordsWithPriority();
private:
	std::vector<std::pair<size_t, std::string*>*>* mWordsInCollection;
};
