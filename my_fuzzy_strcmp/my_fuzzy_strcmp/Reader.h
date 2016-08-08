#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stdafx.h"


class FUZZY_API IReader
{
public:
	virtual std::vector<std::string*>* Read(std::string* filename) = NULL;
	virtual std::ifstream& openStream(std::string* filename) = NULL;
};

class FUZZY_API File_Reader : public IReader
{
public:
	File_Reader();
	std::vector<std::string*>* Read(std::string* filename);
	std::ifstream& openStream(std::string* filename);
};
