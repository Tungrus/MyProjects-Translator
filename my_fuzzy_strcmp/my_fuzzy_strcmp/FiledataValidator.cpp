//#include <regex>

#include <string>
#include "returnedData.h"
#include "FiledataValidator.h"

FiledataValidator::FiledataValidator()
{

}

FiledataValidator::~FiledataValidator()
{

}

bool FiledataValidator::is_valid(ReturnedData* filedata)
{
	std::string* helperWord;
	bool noErrorAccured = true;
	int plase = 0;
	int lengthOfWord;
	for (std::vector<std::string*>::iterator it = filedata->getWords()->begin() + 1, endIt = filedata->getWords()->end() - 1; it != endIt; it++)
	{
		helperWord = *(it._Ptr);
		int lengthOfWord = helperWord->length();
		plase = helperWord->find('<');
		if (lengthOfWord != plase)
		{
			if (plase + 1 == helperWord->find('>'))
			{
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}