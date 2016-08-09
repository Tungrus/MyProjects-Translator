#include "View.h"

#include <Windows.h>
#include <vector>
#include <thread>
#include <returnedData.h>
#include <dictionaries.h>
#include <SeacherForWords.h>
#include <Translator.h>

#include "AutoFillWrapper.h"
#include "AutoFillerThreadControler.h"



#include "Controler.h"


void eraseTextFromListBox(HWND listBox)//
{
	int count = SendMessage(listBox, LB_GETCOUNT, 0, 0);
	for (int i = 0; i != count; i++)
	{
		SendMessage(listBox, LB_DELETESTRING, 0, 0);
	}
	
}

ReturnedData* getTextFromEdit(HWND edit)
{
	LPSTR str = new char[GetWindowTextLength(edit) + 1];
	GetWindowText(edit, str, GetWindowTextLength(edit) + 1);
	std::string* st1 = new std::string(str);
	ReturnedData* data = new ReturnedData(st1);
	return data;
}

void sendDataToListBox(HWND hListBox, ReturnedData* stringToSend)
{
	for (std::string* name : *stringToSend->getWords())
	{
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)name->c_str());
	}
}

Controler::Controler(HINSTANCE hInstance, int nCmdShow)
{
	this->mView = new View(hInstance, nCmdShow, this);
	this->mThread = NULL;
}

Controler::~Controler()
{
	delete mView;
}

void Controler::onCharInputAtction()//
{
	if (this->mThread != NULL)
	{
		delete this->mThread;
		mThread = NULL;
	}
	ReturnedData* data = getTextFromEdit(this->mView->getEditWriterWindow());
	this->mThread = new ThreadControler(new AutoFillWrapper(), data);
	this->mThread->Launch(this->mView->getEditReaderWindow(), this->mDictionaries);
}

void Controler::onSeachAction()
{
	eraseTextFromListBox(this->mView->getListWindow());
	ReturnedData* resevedString = getTextFromEdit(this->mView->getEditReaderWindow());
	ISeacher* seacher = new Seacher();
	this->mDataInListBox = seacher->SeachForMatchesInDictionary(resevedString->getFirstWord(), this->mDictionaries, 2);
	sendDataToListBox(this->mView->getListWindow(), mDataInListBox);
	delete resevedString;
}

void Controler::onTranslateAction()
{
	int lbItem = (int)SendMessage(this->mView->getListWindow(), LB_GETCURSEL, 0, 0);
	if (lbItem >= 0)
	{
		Translator tanslate;
		SetWindowText(this->mView->getEditWriterWindow(), tanslate.Translate((this->mDataInListBox->getWordByNumber(lbItem)),this->mDictionaries)->c_str());
	}
}

MSG Controler::Work()
{
	return this->mView->PollEvent();
}

void Controler::onCreateAction()
{
	std::string str("dict.dat");
	this->mDictionaries = new Dictionaries();
	this->mDictionaries->initFromFile(&str);
}