#include <vector>
#include <vld.h>
#include "DictionaryPairLangugae.h"
#include "Languages.h"

Languages::Languages()
{
	this->mLanguages = new std::vector<DictionaryPairLang*>;
}

void Languages::addLanguageToCollection(DictionaryPairLang* language)
{
	mLanguages->push_back(language);
}

DictionaryPairLang* Languages::getLanguegeByNomber(int nomber) const
{
	return mLanguages[0][nomber];
}

std::vector<DictionaryPairLang*>* Languages::getAllLanguages() const
{
	return this->mLanguages;
}

int Languages::getNomberInCollection(DictionaryPairLang* language) const
{
	int i = 0;
	for (DictionaryPairLang* langInVector : *this->mLanguages)
	{
		if (language == langInVector)
		{
			return i;
		}
		i++;
	}
	return -1;
}

void Languages::ClearData()
{
	this->mLanguages->clear();
}

Languages::~Languages()
{
	for (DictionaryPairLang* langInVector : *this->mLanguages)
	{
		delete langInVector;
		langInVector = NULL;
	}
	delete mLanguages;
}