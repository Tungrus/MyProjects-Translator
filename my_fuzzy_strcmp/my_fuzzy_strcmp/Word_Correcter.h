#pragma once

#include "stdafx.h"
#include <vector>
#include "SDictionary.h"

class I_Word_Correcter
{
public:
	virtual std::vector<std::string*>* CorrectWord(std::string* word, SDictionary* Dictionary, int possibleMistake) = 0;
};

class FUZZY_API Lewinshtain_Word_Correcter : public I_Word_Correcter
{
public:
	Lewinshtain_Word_Correcter();
	std::vector<std::string*>* CorrectWord(std::string* word, SDictionary* Dictionary, int possibleMistake);
};