#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <vector>
#include <list>
#include"View.h"
#include"Controler.h"

#include "hwndSingletone.h"
#include "Fuzzy_Strcmp.h"
#include <Word_Correcter.h>

/*LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	static File_Reader reader;
	static sDictionaryParser parser;
	static std::string filename = "dict.dat";
	static Dictionaries dictionaries(*parser.pars((reader.Read(&filename))));//вставить вызов в init(&filename);
	static Lewinshtain_Word_Correcter correcter;
	static std::vector<std::string*>* vector = NULL;

	if (Message == WM_CHAR)
	{
		Get_Text_From_EDIT();
		if (returnedString->getSuperString() != NULL)
		{

		}
	}
	else if (Message == WM_COMMAND)
	{
		if ((HIWORD(wparam) == 0))
		{
			if (LOWORD(wparam) == ID_BUTTON)
			{
				if (vector != NULL)
				{
					delete(vector);
					vector = NULL;
				}
				eraseTextFromListBox();
				Get_Text_From_EDIT();
				std::string* str1 = returnedString->getSuperString()[0][0];
				if (str1->length() != 0)
				{
					vector = correcter.CorrectWord(returnedString->getSuperString()[0][0], dictionaries.getDictionary(returnedString->getSuperString()[0][0]), 2);
					
				}
				delete str1;
			}
			else if (LOWORD(wparam) == ID_TRANSLATEBUTTON)
			{
				
			}
		}
	}
	else if (Message == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Controler controler(hInstance,nCmdShow);

	return controler.Work().wParam;
}