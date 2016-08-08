#pragma once
#include<string>

template<typename T> class stringWrapper
{
private:
	T mStringBeginIterator;
	T mStringEndIterator;
	T mStringStartIterator;
public:
	stringWrapper(T begin, T end);
	T getNext();
	bool isNext();
	T getIt();
	void getFirst();
	//void setNext(string::iterator begin,string::iterator end);
};