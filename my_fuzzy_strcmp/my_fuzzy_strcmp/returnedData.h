#pragma once
#include <vld.h>
#include <vector>
//need TO Rename
class ReturnedData//need template with const string/wstring
{
private:
	std::vector<std::string*> *mSavedData;
public:
	ReturnedData();
	ReturnedData(std::string* mReturnedWord);
	ReturnedData(std::vector<std::string*>* returnedData);

	std::string* getFirstWord();
	std::vector<std::string*>* getWords();
	std::string* getWordByNumber(int nomber);
	std::string dropFitrsWordAndDestroyData();

	void setWords(std::vector<std::string*>* returnedData);
	void setFirstWord(std::string* returnedWord);
	void addWord(std::string* newWord);

	void clearVector();

	~ReturnedData();
};