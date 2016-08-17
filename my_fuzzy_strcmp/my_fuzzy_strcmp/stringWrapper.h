#pragma once
#include "stdafx.h"
#include<string>
#include <vld.h>
template<typename T> class StringWrapper
{
private:
	T mStringBeginIterator;
	T mStringEndIterator;
	T mStringStartIterator;
public:
	StringWrapper();
	StringWrapper(T begin, T end);

	T getNext();
	T getIt();
	bool isNext();
	void getFirst();

	~StringWrapper();
};

