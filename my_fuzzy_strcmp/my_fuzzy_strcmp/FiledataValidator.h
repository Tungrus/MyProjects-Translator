#pragma once

#include <vld.h>
#include "returnedData.h"

class IFiledataValidator
{
public:
	virtual bool is_valid(ReturnedData* filedata) = 0;
};


class FiledataValidator : public IFiledataValidator
{
public:
	FiledataValidator();
	bool is_valid(ReturnedData* filedata);
	~FiledataValidator();
};