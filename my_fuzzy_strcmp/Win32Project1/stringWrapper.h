#pragma once
#include<string>

template<typename T> class stringWrapper
{
private:
	T mStringBeginIterator;
	T mStringEndIterator;
public:
	T getIt();
	stringWrapper(T begin, T end);
	T getNext();
	bool isNext();
	//void setNext(string::iterator begin,string::iterator end);
};