#pragma once

#include <vector>

class ReturnedData
{
private:
	std::vector<std::string*>* mSavedData;
public:
	ReturnedData();
	~ReturnedData();
	ReturnedData(std::string* mReturnedWord);
	ReturnedData(std::vector<std::string*>* returnedData);

	std::string* getFirstWord();
	std::vector<std::string*>* getWords();
	std::string* getWordByNumber(int nomber);
	std::string dropFitrsWord();

	void setWords(std::vector<std::string*>* returnedData);
	void setFirstWord(std::string* returnedWord);
	void addWord(std::string* newWord);
};