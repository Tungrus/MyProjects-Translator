#include <string>
//#include<wstring>
#include <vld.h>
#include"stringWrapper.h"

StringWrapper<std::string::iterator>::StringWrapper(std::string::iterator begin, std::string::iterator end)
{
	this->mStringBeginIterator = begin;
	this->mStringEndIterator = end;
	this->mStringStartIterator = begin;
}

//stringWrapper<std::string::iterator>::stringWrapper(std::string* str)
//{
//	this->mStringBeginIterator = str->begin();
//	this->mStringEndIterator = str->end();
//}

std::string::iterator StringWrapper<std::string::iterator>::getNext()
{
	std::string::iterator it = mStringBeginIterator;
	mStringBeginIterator++;
	return it;
}

bool StringWrapper<std::string::iterator>::isNext()
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

std::string::iterator StringWrapper<std::string::iterator>::getIt()
{
	return this->mStringBeginIterator;
}

void StringWrapper<std::string::iterator>::getFirst()
{
	this->mStringBeginIterator = this->mStringStartIterator;
}

StringWrapper<std::string::iterator>::~StringWrapper()
{

}