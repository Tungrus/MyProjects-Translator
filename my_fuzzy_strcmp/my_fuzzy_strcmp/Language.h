#pragma once
#include <vld.h>
class Language
{
private:
	std::string* mLangugae;
public:
	Language();
	Language(std::string* mLangugae);

	std::string* getLanguege() const;

	void copyString(std::string* str);

	~Language();
};