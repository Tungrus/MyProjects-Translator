#pragma once
#include <vld.h>
class ITranslate
{
public:
	virtual std::string* Translate(std::string* string, Dictionaries* dictionaries, DictionaryPairLang* pair) = 0;
};

class Translator : public ITranslate
{
public:
	Translator();
	std::string* Translate(std::string* string, Dictionaries* dictionaries, DictionaryPairLang* pair);
	~Translator();
};