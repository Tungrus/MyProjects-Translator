#include <vector>

#include "DictionaryPairLangugae.h"
#include "Languages.h"

Languages::Languages()
{
	this->mLanguages = new std::vector<DictionaryPairLang*>;
}

void Languages::addLanguageToCollection(DictionaryPairLang* language)
{
	mLanguages->push_back(new DictionaryPairLang(language));
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

Languages::~Languages()
{
	for (DictionaryPairLang* langInVector : *this->mLanguages)
	{
		delete langInVector;
	}
	delete mLanguages;
}