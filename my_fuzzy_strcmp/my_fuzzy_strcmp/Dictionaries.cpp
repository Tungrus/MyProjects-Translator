
#include "Reader.h"
#include "SDictionary.h"
#include <vector>
#include "dictionaries.h"
#include "parser.h"
#include "stdafx.h"

Dictionaries::Dictionaries()
{
	this->mDictionaries = NULL;
}

Dictionaries::Dictionaries(SDictionary* first, SDictionary* second)
{
	this->mDictionaries = new std::vector<std::pair<SDictionary*, SDictionary*>*>;
	mDictionaries->push_back(new std::pair<SDictionary*, SDictionary*>(first, second));
}

void Dictionaries::addPairDict(SDictionary* first, SDictionary* second)
{
	mDictionaries->push_back(new std::pair<SDictionary*, SDictionary*>(first, second));
}

SDictionary* Dictionaries::getDictionary(std::string* newWord)
{
	return getDictionaryByLang(newWord);
}

SDictionary* Dictionaries::getDictionaryByLang(std::string* newWord)
{
	for (std::vector<std::pair<SDictionary*, SDictionary*>*>::iterator it = this->mDictionaries->begin(), endIT = this->mDictionaries->end(); it != endIT; it++)
	{
		std::pair<SDictionary*, SDictionary*>* s = *(it._Ptr);
		s->first->init();
		const std::string* d = &(s->first->getNext()->first);
		if ('A' < d->c_str()[0] && d->c_str()[0] < 'z')
		{
			if ('A' < newWord->c_str()[0] && newWord->c_str()[0] < 'z')
			{
				return s->first;
			}
		}
		else
		{
			return s->second;
		}
	}
}

void Dictionaries::initFromFile(std::string* filename)
{
	IParser* parser = new sDictionaryParser;
	File_Reader reader;
	std::vector<std::string*>* filedata = reader.Read(filename);
	Dictionaries* dict = parser->pars((filedata));
	this->mDictionaries = dict->mDictionaries;
	//filedata->clear();
	//delete filedata;
}