#include "dictionaries.h"
#include "returnedData.h"
#include <vld.h>
#include "WordCorrecter.h"
#include "stdafx.h"

#include "SeacherForWords.h"

Seacher::Seacher()
{

};

ReturnedData* Seacher::SeachForMatchesInDictionary(std::string* string, Dictionary* dictionary, int maxMistake)
{
	IWordCorrecter* correcter = new LewinshtainWordCorrecter();
	ReturnedData* wordCollection = new ReturnedData(correcter->CorrectWord(string, dictionary, maxMistake));
	delete correcter;
	return wordCollection;
}

Seacher::~Seacher()
{

}