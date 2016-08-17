#include <vector>
#include <thread>
#include <Windows.h>
#include "View.h"
#include <SeacherForWords.h>
#include <Translator.h>
#include <dictionaries.h>
#include <returnedData.h>
#include <vld.h>
#include "AutoFillWrapper.h"
#include "AutoFillerThreadControler.h"

#include "Controler.h"

void sendLangsToDropDown(HWND DropDown, Languages* lang);

void sendLangsToDropDown(HWND DropDown, Languages* lang)
{
	for (DictionaryPairLang* pair : *lang->getAllLanguages())
	{
		SendMessage(DropDown, CB_ADDSTRING, 0, (LPARAM)(pair->getFullTranslationName().c_str()));
	}	
}

void eraseTextFromComboBox(HWND comboBox)
{
	int count = SendMessage(comboBox, CB_GETCOUNT, 0, 0);
	for (int i = 0; i != count; i++)
	{
		SendMessage(comboBox, CB_DELETESTRING, 0, 0);
	}
}

void eraseTextFromListBox(HWND listBox)
{
	int count = SendMessage(listBox, LB_GETCOUNT, 0, 0);
	for (int i = 0; i != count; i++)
	{
		SendMessage(listBox, LB_DELETESTRING, 0, 0);
	}
}

ReturnedData* getTextFromEdit(HWND edit)
{

	char* n= new char[GetWindowTextLength(edit) + 1];
	std::string* st1 = NULL;
	ReturnedData* data = NULL;
	if (GetWindowText(edit, n, GetWindowTextLength(edit) + 1))
	{
		st1 = new std::string(n);
		data = new ReturnedData(st1);
	}
	/*std::string* st2 = new std::string;
	*st2 = *st1;
	data->dropFitrsWord();
	data->addWord(st2);
	delete data;*/
	delete (n);
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
	this->mDictionaries = NULL;
	this->mChoosenLang = NULL;
	this->mThread = NULL;
	this->mDataInListBox = NULL;
	this->mDictionaries = NULL;
	mView = new View(hInstance, nCmdShow, this);
}

Controler::~Controler()
{
	delete this->mView;
	this->mView = NULL;
	if (this->mDictionaries != NULL)
	{
		delete this->mDictionaries;
		this->mDictionaries = NULL;
		this->mChoosenLang = NULL;
	}
	if (mDataInListBox != NULL)
	{
		this->mDataInListBox->clearVector();
		delete this->mDataInListBox;
	}
	if (mThread != NULL)
		delete this->mThread;
}

void Controler::onCharInputAtction()
{	
	SendMessage(this->mView->getEditReaderWindow(), CB_SHOWDROPDOWN, TRUE, 0);
	eraseTextFromComboBox(this->mView->getEditReaderWindow());
	if (this->mChoosenLang == NULL)
	{
		return;
	}
	ReturnedData* dataFromEdit = getTextFromEdit(this->mView->getEditReaderWindow());
	if (dataFromEdit == NULL)
	{
		return;
	}
	
	if (this->mThread == NULL)
	{
		this->mThread = new ThreadControler(new AutoFillWrapper());
		this->mThread->Launch(this->mView->getEditReaderWindow(), this->mDictionaries,this->mChoosenLang);
	}
	this->mThread->setAutocomlitionData(dataFromEdit, this->mChoosenLang);
}

void Controler::onSeachAction()
{
	eraseTextFromListBox(this->mView->getListWindow());
	if (this->mChoosenLang == NULL)
	{
		return;
	}
	ReturnedData* resevedString = getTextFromEdit(this->mView->getEditReaderWindow());
	if (resevedString == NULL)
	{
		return;
	}
	if (this->mDataInListBox != NULL)
	{
		this->mDataInListBox->clearVector();
		delete mDataInListBox;
	}
	ISeacher* seacher = new Seacher();
	
	this->mDataInListBox = seacher->SeachForMatchesInDictionary(resevedString->getFirstWord(), this->mDictionaries->getDictionary(this->mChoosenLang), 2);
	sendDataToListBox(this->mView->getListWindow(), mDataInListBox);
	delete seacher;
	delete resevedString;
}

void Controler::onTranslateAction()
{
	int lbItem = (int)SendMessage(this->mView->getListWindow(), LB_GETCURSEL, 0, 0);
	if (lbItem >= 0)
	{
		Translator tanslate;
		SetWindowText(this->mView->getEditWriterWindow(), tanslate.Translate((this->mDataInListBox->getWordByNumber(lbItem)),this->mDictionaries,this->mChoosenLang)->c_str());
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
	bool is_sucess = this->mDictionaries->initFromFile(&str);
	if (is_sucess)
		sendLangsToDropDown(this->mView->getHLangDropDown(), this->mDictionaries->getLanguages());
}

void Controler::onGetingNewDictionaryAction()
{
	/*
	OpenFileNameWrapper* file = new OpenFileNameWrapper();
	
	char szFile[260];       // buffer for file name
	HANDLE hf;              // file handle

	// Initialize OPENFILENAME
	ZeroMemory(file->getPointerToOPENFILENAME(), sizeof(*file->getPointerToOPENFILENAME()));
	file->getPointerToOPENFILENAME()->lStructSize = sizeof(file->getPointerToOPENFILENAME());
	file->getPointerToOPENFILENAME()->hwndOwner = this->mView->getMianeWindow();
	file->getPointerToOPENFILENAME()->lpstrFile = szFile;
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	file->getPointerToOPENFILENAME()->lpstrFile[0] = '\0';
	file->getPointerToOPENFILENAME()->nMaxFile = sizeof(szFile);
	file->getPointerToOPENFILENAME()->lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	file->getPointerToOPENFILENAME()->nFilterIndex = 1;
	file->getPointerToOPENFILENAME()->lpstrFileTitle = NULL;
	file->getPointerToOPENFILENAME()->nMaxFileTitle = 0;
	file->getPointerToOPENFILENAME()->lpstrInitialDir = NULL;
	file->getPointerToOPENFILENAME()->Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;*/
	OPENFILENAME ofn;       
	char szFile[260];       
	//HANDLE hf;              
	//FIX ME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = this->mView->getMianeWindow();
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetOpenFileName(&ofn))
	{
		std::string* filepath = new std::string(ofn.lpstrFile);
		
		if (!this->mDictionaries->addFromFile(filepath))
		{
			//void callErrorWindow();
		}
		delete filepath;
	}
}

void Controler::onChooseLanguageAction()
{
	if (CB_ERR == SendMessage(this->mView->getHLangDropDown(), CB_GETCURSEL, 0, 0))
	{
		return;
	}
	int lbItem = (int)SendMessage(this->mView->getHLangDropDown(), CB_GETCURSEL, 0, 0);
	this->mChoosenLang = this->mDictionaries->getLanguages()->getLanguegeByNomber(lbItem);
}
