#pragma once
#include <vld.h>
#include "stdafx.h"
#include "Dictionary.h"
#include "Language.h"
#include "Languages.h"


/*class IDictionaries
{
	virtual Dictionary* getDictionary(DictionaryPairLang* lang) = 0;

};*/


class FUZZY_API Dictionaries
{
private:
	Languages* mLanguages;
	std::vector<Dictionary*>* mDictionaries;//FIX ME
	Dictionary* getDictionaryByLang(DictionaryPairLang* language) const;
	void ClearData();
public:
	Dictionaries();
	Dictionaries(Dictionary* dictionary, DictionaryPairLang* language);

	Dictionary* getDictionary(std::string* lang) const;
	Dictionary* getDictionary(DictionaryPairLang* pair) const;

	void addDict(Dictionary* first, DictionaryPairLang* language);
	void InsertDict(Dictionaries* dictionary);

	bool initFromFile(std::string* filename);
	bool addFromFile(std::string* filename);
	Languages* getLanguages() const;

	~Dictionaries();
};