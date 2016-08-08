#pragma once

class returnedData
{
private:
	std::vector<std::string*>* mSavedData;
public:
	returnedData();
	~returnedData();
	returnedData(std::string* mReturnedWord);
	returnedData(std::vector<std::string*>* returnedData);

	std::string* getFirstWord();
	std::vector<std::string*>* getWords();
	std::string* getWordByNumber(int nomber);

	void setWords(std::vector<std::string*>* returnedData);
	void setFirstWord(std::string* returnedWord);
};