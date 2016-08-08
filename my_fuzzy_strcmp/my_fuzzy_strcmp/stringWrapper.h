#pragma once
#include "stdafx.h"
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
	T getIt();
	bool isNext();
	void getFirst();
};

