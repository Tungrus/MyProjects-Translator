#include <vector>
#include <map>
#include <algorithm>
#include "dictionaries.h"
#include "SDictionary.h"
#include "stringWrapper.h"
#include "Parser.h"
#include "stdafx.h"

Dictionaries* sDictionaryParser::pars(std::vector<std::string*>* filedata)
{
	std::map<std::string, std::string>* newMap1 = new std::map<std::string, std::string>;
	std::map<std::string, std::string>* newMap2 = new std::map<std::string, std::string>;
	std::string* helperWord;
	for (std::vector<std::string*>::iterator it = filedata->begin(), endIt = filedata->end(); it != endIt; it++)
	{
		helperWord = *(it._Ptr);
		std::string str;
		std::string str1;
		str = helperWord->substr(0, helperWord->find('<'));
		str1 = helperWord->substr(helperWord->find('>') + 1, helperWord->length() - 1);
		if (str.length() != 0 && str1.length() != 0)
		{
			newMap1->operator[](str) = str1;
			newMap2->operator[](str1) = str;
		}
	}
	SDictionary* dict1 = new SDictionary(newMap1);
	SDictionary* dict2 = new SDictionary(newMap2);

	Dictionaries* dict = new Dictionaries(dict1, dict2);

	dict->addPairDict(dict2, dict1);

	return dict;
}

sDictionaryParser::sDictionaryParser()
{

}