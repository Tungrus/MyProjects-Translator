#include <string>
#include "Language.h"
#include <vld.h>
#include "DictionaryPairLangugae.h"

DictionaryPairLang::DictionaryPairLang(Language* fromLang, Language* toLang)
{
	setLangs(fromLang, toLang);
}

void DictionaryPairLang::setLangs(Language* fromLang, Language* toLang)
{
	this->mFromLang = fromLang;
	this->mToLang = toLang;
}

DictionaryPairLang::DictionaryPairLang()
{
	this->mFromLang = NULL;
	this->mToLang = NULL;
}

DictionaryPairLang::~DictionaryPairLang()
{
	if (this->mFromLang != NULL)
	{
		delete this->mFromLang;
		this->mFromLang = NULL;
	}
	if (this->mToLang != NULL)
	{
		delete this->mToLang;
		this->mToLang = NULL;
	}

}

Language* DictionaryPairLang::getFromLang() const
{
	return this->mFromLang;
}

Language* DictionaryPairLang::getToLang() const
{
	return this->mToLang;
}

DictionaryPairLang::DictionaryPairLang(std::string* fileString)
{
	this->mFromLang = new Language();
	this->mToLang = new Language();
	mFromLang->copyString(&fileString->substr(0,fileString->find('<')));
	mToLang->copyString(&fileString->substr(fileString->find('>') + 1));
}

DictionaryPairLang::DictionaryPairLang(DictionaryPairLang* lang)
{
	this->mFromLang = new Language;
	this->mToLang = new Language;
	this->mToLang->copyString(lang->mToLang->getLanguege());
	this->mFromLang->copyString(lang->mFromLang->getLanguege());
}

std::string DictionaryPairLang::getFullTranslationName() const
{
	std::string toReturn;
	toReturn += *this->mFromLang->getLanguege();
	toReturn += '-';
	toReturn += *this->mToLang->getLanguege();
	return toReturn;
}

DictionaryPairLang::DictionaryPairLang(DictionaryPairLang* lang, bool reversed)
{
	this->mFromLang = new Language;
	this->mToLang = new Language;
	this->mFromLang->copyString(lang->mToLang->getLanguege());
	this->mToLang->copyString(lang->mFromLang->getLanguege());
}