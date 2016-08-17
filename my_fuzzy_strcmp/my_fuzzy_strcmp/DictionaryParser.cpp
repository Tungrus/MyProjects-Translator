#include <vector>
#include <map>
#include <algorithm>
#include "dictionaries.h"
#include "Dictionary.h"
#include "stringWrapper.h"
#include "Parser.h"
#include <vld.h>
#include "stdafx.h"


Dictionaries* DictionaryParser::pars(std::vector<std::string*>* filedata)
{
	Dictionary* dictionary_1 = new Dictionary;
	Dictionary* dictionary_2 = new Dictionary;
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
			dictionary_1->InsertData(str1, str);
			dictionary_2->InsertData(str, str1);
		}
	}
	Dictionaries* dict = new Dictionaries(dictionary_1, lang);
	bool needToReverce = true;
	auto sss = new DictionaryPairLang(lang, needToReverce);
	dict->addDict(dictionary_2, sss);
	return dict;
}

DictionaryParser::DictionaryParser()
{

}

DictionaryParser::~DictionaryParser()
{

}