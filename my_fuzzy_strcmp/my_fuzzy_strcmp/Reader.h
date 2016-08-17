#pragma once
#include <vld.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stdafx.h"


class FUZZY_API IFileReader
{
public:
	virtual std::vector<std::string*>* Read(std::string* filename) = NULL;
	virtual std::ifstream& openStream(std::string* filename) = NULL;
};

class FUZZY_API FileReader : public IFileReader
{
public:
	FileReader();

	std::vector<std::string*>* Read(std::string* filename);
	std::ifstream& openStream(std::string* filename);

	~FileReader();
};
