#include "Reader.h"
#include "stdafx.h"

std::vector<std::string*>* File_Reader::Read(std::string* filename)
{
	std::ifstream str;
	str.open(*filename);
	if (!str.is_open())
	{
		str.close();
	}
	std::vector<std::string*>* filedata = new std::vector<std::string*>;
	std::string* line; 
	while (true)
	{
		if (!str.eof())
			line = new std::string;
		else
			break;
		std::getline(str, *line);
		if (line->length() != 0)
		{
			filedata->push_back(line);
		}
	}
	str.close();
	return filedata;
}

std::ifstream& File_Reader::openStream(std::string* filename)
{
	std::ifstream str;
	str.open(*filename);
	if (!str.is_open())
	{
		str.close();
	}

	return str;
}

File_Reader::File_Reader()
{
}