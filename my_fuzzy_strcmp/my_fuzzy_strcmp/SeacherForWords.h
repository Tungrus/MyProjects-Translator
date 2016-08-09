#pragma once


class ISeacher
{
public:
	virtual ReturnedData* SeachForMatchesInDictionary(std::string* str, Dictionaries* dictionaries, int maxMistake) = 0;
};



class Seacher : public ISeacher
{
public:
	Seacher();
	ReturnedData* SeachForMatchesInDictionary(std::string* string, Dictionaries* dictionaries, int maxMistake);
};
