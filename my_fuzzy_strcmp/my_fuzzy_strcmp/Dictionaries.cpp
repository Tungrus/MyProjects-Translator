#include "Reader.h"
#include "Dictionary.h"
#include <vector>
#include "Language.h"
#include "Languages.h"
#include "DictionaryPairLangugae.h"
#include "FiledataValidator.h"
#include "dictionaries.h"
#include "parser.h"
#include <vld.h>
#include "stdafx.h"

void ClearVector(std::vector<std::string*>* fileadata);

Dictionaries::Dictionaries()
{
	this->mDictionaries = NULL;
	this->mLanguages = NULL;
}

Dictionaries::Dictionaries(Dictionary* dictionary, DictionaryPairLang* language)
{
	this->mDictionaries = new std::vector<Dictionary*>;
	this->mLanguages = new Languages();
	addDict(dictionary, language);
}

void Dictionaries::addDict(Dictionary* dictionary, DictionaryPairLang* language)
{
	this->mDictionaries->push_back(dictionary);
	this->mLanguages->addLanguageToCollection(language);
}

Dictionary* Dictionaries::getDictionary(std::string* language) const
{
	DictionaryPairLang lng(language);
	return getDictionaryByLang(&lng);
}

Dictionary* Dictionaries::getDictionaryByLang(DictionaryPairLang* lng) const
{
	return this->mDictionaries[0][this->mLanguages->getNomberInCollection(lng)];
}

bool Dictionaries::initFromFile(std::string* filename)
{
	IDictionaryParser* parser = new DictionaryParser;
	IFileReader* reader = new FileReader;//FIX ME
	IFiledataValidator* validator = new FiledataValidator;

	std::vector<std::string*>* filedata = reader->Read(filename);
	ReturnedData data(filedata);
	bool is_Success = validator->is_valid(&data);
	if (!is_Success)
	{
		delete parser;
		delete reader;//FIX ME
		delete validator;
		return false;
	}
	Dictionaries* dict = parser->pars((filedata));
	this->mDictionaries = dict->mDictionaries;
	this->mLanguages = dict->mLanguages;

	delete parser;
	delete reader;//FIX ME
	delete validator;

	dict->ClearData();
	delete dict;
	return true;
}

bool Dictionaries::addFromFile(std::string* filename)
{
	IDictionaryParser* parser = new DictionaryParser;
	IFileReader* reader = new FileReader;//FIX ME
	IFiledataValidator* validator = new FiledataValidator;

	std::vector<std::string*>* filedata = reader->Read(filename);
	ReturnedData data(filedata);
	bool is_Success = validator->is_valid(&data);
	if (!is_Success)
	{
		delete parser;
		delete reader;//FIX ME
		delete validator;
		return false;
	}
	Dictionaries* dict = parser->pars((filedata));
	InsertDict(dict);

	delete parser;
	delete reader;//FIX ME
	delete validator;

	return true;
}

Languages* Dictionaries::getLanguages() const
{
	return this->mLanguages;
}

/*
void mergeVectors(std::vector<std::pair<SDictionary*, SDictionary*>*>* vectorToReturn, std::vector<std::pair<SDictionary*, SDictionary*>*>* vectorForAdd)
{
	for (std::pair<SDictionary*, SDictionary*>* element : *vectorForAdd)
	{
		vectorToReturn->push_back(element);
	}
}*/
void Dictionaries::InsertDict(Dictionaries* dictionary)
{ 
	int i = 0;
	for (Dictionary* name : *dictionary->mDictionaries)
	{
		this->addDict(name, dictionary->mLanguages->getLanguegeByNomber(i));
		i++;
	}
	
	dictionary->mLanguages->ClearData();
	dictionary->mDictionaries->clear();
	delete dictionary->mLanguages;
	delete dictionary->mDictionaries;
	dictionary->ClearData();
	delete dictionary;
}

Dictionary* Dictionaries::getDictionary(DictionaryPairLang* pair) const
{
	int nomberInVector = this->mLanguages->getNomberInCollection(pair);
	Dictionary* n = this->mDictionaries[0][nomberInVector];
	return n;
}

void ClearVector(std::vector<std::string*>* fileadata)
{
	for (std::string* name : *fileadata)
	{
		delete name;
	}
	delete fileadata;
}

Dictionaries::~Dictionaries()
{
	if (this->mDictionaries != NULL)
	{
		for (Dictionary* dictionary : *this->mDictionaries)
		{
			delete dictionary;
		}
		delete this->mDictionaries;
		this->mDictionaries = NULL;
	}
	if (this->mLanguages != NULL)
	{
		delete this->mLanguages;
	}
}

void Dictionaries::ClearData()
{
	this->mDictionaries = NULL;
	this->mLanguages = NULL;
}