/*
#include <vector>
#include "OpenFilename.h"
#include "FileOpenCollection.h"

OpenFileNamesCollection::OpenFileNamesCollection()
{
	this->allOpenedFiles = new std::vector<OpenFileNameWrapper*>;
}

void OpenFileNamesCollection::addFilenameWrapper(OpenFileNameWrapper* newData)
{
	this->allOpenedFiles->push_back(newData);
}

OpenFileNameWrapper* OpenFileNamesCollection::getFilenameWrapperByNomber(int nomberOfElement) const
{
	return this->allOpenedFiles[0][nomberOfElement];
}

std::vector<OpenFileNameWrapper*>* OpenFileNamesCollection::getFilenameWrappers() const
{
	return this->allOpenedFiles;
}

OpenFileNameWrapper* OpenFileNamesCollection::getLastFilenameWrapper() const
{
	return this->allOpenedFiles[0][this->allOpenedFiles->size() - 1];
}

OpenFileNamesCollection::~OpenFileNamesCollection()
{

}
*/