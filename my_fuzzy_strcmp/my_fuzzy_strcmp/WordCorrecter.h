#pragma once
#include <vld.h>
#include "stdafx.h"
#include <vector>
#include "Dictionary.h"

class IWordCorrecter
{
public:
	virtual std::vector<std::string*>* CorrectWord(std::string* word, Dictionary* Dictionary, int possibleMistake) = 0;
};

class FUZZY_API LewinshtainWordCorrecter : public IWordCorrecter
{
public:
	LewinshtainWordCorrecter();
	std::vector<std::string*>* CorrectWord(std::string* word, Dictionary* Dictionary, int possibleMistake);
	~LewinshtainWordCorrecter();
};