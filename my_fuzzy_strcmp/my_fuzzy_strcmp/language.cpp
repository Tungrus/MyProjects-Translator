#include <string>

#include <vld.h>
#include "Language.h"

Language::Language()
{
	this->mLangugae = new std::string;
}

Language::Language(std::string* str)
{
	this->mLangugae = str;
}

void Language::copyString(std::string* str)
{
	*this->mLangugae = *str;
}

std::string* Language::getLanguege() const
{
	return this->mLangugae;
}

Language::~Language()
{
	if (this->mLangugae != NULL)
		delete this->mLangugae;
	this->mLangugae = NULL;
}

