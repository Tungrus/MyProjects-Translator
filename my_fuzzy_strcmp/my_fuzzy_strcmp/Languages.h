#pragma once

#include "DictionaryPairLangugae.h"
#include <vector>

class Languages
{
private:
	std::vector<DictionaryPairLang*>* mLanguages;
public:
	Languages();
	Languages(std::string* filestring);

	void addLanguageToCollection(DictionaryPairLang* lang);

	DictionaryPairLang* getLanguegeByNomber(int nomber) const;
	std::vector<DictionaryPairLang*>* getAllLanguages() const;
	int getNomberInCollection(DictionaryPairLang* pairLang) const;
	
	~Languages();
};