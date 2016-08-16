#include <vector>
#include <map>
#include <algorithm>
#include "dictionaries.h"
#include "Dictionary.h"
#include "stringWrapper.h"
#include "Parser.h"
#include "stdafx.h"

void InsertDataInMap(std::map<std::string, std::string>* map,std::string* dataToInsert,std::string* key)
{
	if (map->operator[](*key) == "")
	{
		map->operator[](*key) = *dataToInsert;
	}
	else
	{
		map->operator[](*key) += ", " + *dataToInsert;
	}
}



Dictionaries* DictionaryParser::pars(std::vector<std::string*>* filedata)
{
	std::map<std::string, std::string>* newMap1 = new std::map<std::string, std::string>;
	std::map<std::string, std::string>* newMap2 = new std::map<std::string, std::string>;
	std::string* helperWord;
	DictionaryPairLang* lang = new DictionaryPairLang(filedata[0][0]);
	for (std::vector<std::string*>::iterator it = filedata->begin() + 1, endIt = filedata->end(); it != endIt; it++)
	{
		helperWord = *(it._Ptr);
		std::string str;
		std::string str1;
		str = helperWord->substr(0, helperWord->find('<'));
		str1 = helperWord->substr(helperWord->find('>') + 1, helperWord->length() - 1);
		if (str.length() != 0 && str1.length() != 0)
		{
			InsertDataInMap(newMap1, &str1, &str);
			InsertDataInMap(newMap2, &str, &str1);
		}
	}
	Dictionary* dict1 = new Dictionary(newMap1);
	Dictionary* dict2 = new Dictionary(newMap2);

	Dictionaries* dict = new Dictionaries(dict1, lang);
	bool needToReverce = true;
	dict->addDict(dict2, new DictionaryPairLang(lang, needToReverce));
	return dict;
}

DictionaryParser::DictionaryParser()
{

}

DictionaryParser::~DictionaryParser()
{

}