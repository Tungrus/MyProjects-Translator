#include "dictionaries.h"
#include "Word_Correcter.h"
#include "returnedData.h"
#include "Word_Correcter.h"
#include "stdafx.h"

#include "SeacherForWords.h"

Seacher::Seacher(){};

returnedData* Seacher::SeachForMatchesInDictionary(std::string* string, Dictionaries* dictionaries, int maxMistake)
{
	I_Word_Correcter* correcter = new Lewinshtain_Word_Correcter();
	return new returnedData(correcter->CorrectWord(string, dictionaries->getDictionary(string), maxMistake));

}