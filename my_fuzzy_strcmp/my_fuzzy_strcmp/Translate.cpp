

#include <vld.h>
#include "dictionaries.h"
#include "Translator.h"

Translator::Translator()
{

}

std::string* Translator::Translate(std::string* string, Dictionaries* dictionaries, DictionaryPairLang* pair)
{
	return dictionaries->getDictionary(pair)->getValue(string);
}

Translator::~Translator()
{

}
