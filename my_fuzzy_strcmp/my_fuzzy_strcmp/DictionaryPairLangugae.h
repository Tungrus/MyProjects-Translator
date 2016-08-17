#pragma once 
#include <string>
#include "Language.h"
#include <vld.h>
class DictionaryPairLang
{
private:
	Language* mFromLang;
	Language* mToLang;
public:
	DictionaryPairLang();
	
	DictionaryPairLang(Language* FromLang, Language* ToLang);
	DictionaryPairLang(std::string* fileString);
	DictionaryPairLang(DictionaryPairLang* pair);
	DictionaryPairLang(DictionaryPairLang* pair,bool reversed);

	void setLangs(Language* mFromLang, Language* ToLang);

	std::string getFullTranslationName()const;
	Language* getFromLang() const;
	Language* getToLang() const;

	bool operator==(DictionaryPairLang &other)
	{
		if (*(this->mFromLang->getLanguege()) == *other.mFromLang->getLanguege())
		{
			if (*(this->mToLang->getLanguege()) == *other.mToLang->getLanguege())
			{
				return true;
			}
		}
		return false;
	}

	~DictionaryPairLang();
};