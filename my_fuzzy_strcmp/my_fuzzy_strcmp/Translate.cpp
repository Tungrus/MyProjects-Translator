


#include "dictionaries.h"
#include "Translator.h"

Translator::Translator()
{

}


std::string* Translator::Translate(std::string* string, Dictionaries* dictionaries)
{
	return dictionaries->getDictionary(string)->getValue(string);
}


