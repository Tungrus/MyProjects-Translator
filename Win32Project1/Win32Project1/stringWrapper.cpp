//#include<wstring>
#include"stringWrapper.h"

stringWrapper<std::string::iterator>::stringWrapper(std::string::iterator begin, std::string::iterator end)
{
	this->mStringBeginIterator = begin;
	this->mStringEndIterator = end;
	this->mStringStartIterator = begin;
}

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

std::string::iterator stringWrapper<std::string::iterator>::getIt()
{
	return this->mStringBeginIterator;
}

void stringWrapper<std::string::iterator>::getFirst()
{
	this->mStringBeginIterator = this->mStringStartIterator;
}