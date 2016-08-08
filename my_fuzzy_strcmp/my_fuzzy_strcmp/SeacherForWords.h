#pragma once


class ISeacher
{
public:
	virtual returnedData* SeachForMatchesInDictionary(std::string* str, Dictionaries* dictionaries, int maxMistake) = 0;
};



class Seacher : public ISeacher
{
public:
	Seacher();
	returnedData* SeachForMatchesInDictionary(std::string* string, Dictionaries* dictionaries, int maxMistake);
};
