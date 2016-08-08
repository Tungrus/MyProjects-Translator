//#include<wstring>
#include"stringWrapper.h"

stringWrapper<std::string::iterator>::stringWrapper(std::string::iterator begin, std::string::iterator end)
{
	this->mStringBeginIterator = begin;
	this->mStringEndIterator = end;
}

//stringWrapper<std::string::iterator>::stringWrapper(std::string* str)
//{
//	this->mStringBeginIterator = str->begin();
//	this->mStringEndIterator = str->end();
//}

std::string::iterator stringWrapper<std::string::iterator>::getNext()
{
	std::string::iterator it = mStringBeginIterator;
	mStringBeginIterator++;
	return it;
}

bool stringWrapper<std::string::iterator>::isNext()
{
	if (this->mStringBeginIterator == this->mStringEndIterator)
	{
		return false;
	}
	else
	{
		return true;
	}
}