#include <climits>
#include <string>
#include <vector>
#include "stringWrapper.h"
#include "Dictionary.h"
#include "WordsWithPriorityCollection.h"
#include "WordCorrecter.h"

#define	PRISE_OF_ADD 1
#define PRISE_OF_DELETE 1
#define PRISE_OF_RESET 1

int** Create_Table(std::string* wordFromDictionary, std::string* checkingWord)
{
	int **matrix = new int*[wordFromDictionary->length() + 1];
	
	for (int l = 0, len = wordFromDictionary->length() + 1; l != len; l++)
	{
		matrix[l] = new int[checkingWord->length() + 1];
		memset(matrix[l], 0, checkingWord->length());
	}
	return matrix;
}
void Init_Matrix(int len_1, int len_2,int** matrix)
{
	matrix[0][0] = 0;
	for (int x = 1; x != len_2 + 1; x++)
	{
		matrix[0][x] = matrix[0][x-1] + PRISE_OF_ADD;
	}
	for (int y = 1; y != len_1 + 1; y++)
	{
		matrix[y][0] = matrix[y-1][0] + PRISE_OF_DELETE;
	}
}

void Delete_Matrix(int y, int** matrix)
{
	for (int y1 = 0; y1 != y; y1++)
	{
		delete(matrix[y1]);
	}
}

void bestPairCreater(int** matrix, StringWrapper<std::string::iterator>* newWrod, StringWrapper<std::string::iterator>* dictWord)
{
	int y = 0;
	while (dictWord->isNext())
	{
		y++;
		int x = 0;
		while (newWrod->isNext())
		{
			x++;
			if (*(dictWord->getIt()) != *(newWrod->getNext()._Ptr))//FIX ME
			{
				if ((matrix[y - 1][x - 1]) < matrix[y][x - 1])
				{
					if (matrix[y - 1][x - 1] < matrix[y - 1][x])
					{
						matrix[y][x] = matrix[y - 1][x - 1] + PRISE_OF_RESET;
					}
					else
					{
						matrix[y][x] = matrix[y - 1][x] + PRISE_OF_DELETE;
					}
				}
				else if (matrix[y][x - 1] < matrix[y - 1][x])
				{
					matrix[y][x] = matrix[y][x - 1] + PRISE_OF_ADD;
				}
				else
				{
					matrix[y][x] = matrix[y - 1][x] + PRISE_OF_DELETE;
				}
			}
			else
			{
				if ((matrix[y - 1][x - 1]) < matrix[y][x - 1])
				{
					if (matrix[y - 1][x - 1] < matrix[y - 1][x])
					{
						matrix[y][x] = matrix[y - 1][x - 1];
					}
					else
					{
						matrix[y][x] = matrix[y - 1][x];
					}
				}
				else if (matrix[y][x - 1] < matrix[y - 1][x])
				{
					matrix[y][x] = matrix[y][x - 1];
				}
				else
				{
					matrix[y][x] = matrix[y - 1][x];
				}
			}
		}
		x = 0;
		newWrod->getFirst();
		dictWord->getNext();
	}
}

int MyABS(int len)
{
	if (len >= 0)
		return len;
	else
		return len*(-1);
}

std::vector<std::string*>* LewinshtainWordCorrecter::CorrectWord(std::string* word, Dictionary* Dictionary,int possibleMistake)
{
	WordsWithPriority foundWords;
	size_t currPrice;
	std::string* checkWord = NULL;
	Dictionary->init();
	StringWrapper<std::string::iterator> newWrod(word->begin(), word->end());
	while (Dictionary->isNext())
	{
		checkWord = const_cast<std::string*>(&(Dictionary->getNext()->first));
		StringWrapper<std::string::iterator> dictWord(checkWord->begin(), checkWord->end());
		int** matrix = Create_Table(checkWord, word);
		Init_Matrix(checkWord->length(), word->length(), matrix);
		bestPairCreater(matrix, &newWrod, &dictWord);
		currPrice = matrix[checkWord->length()][word->length()];
		//currPrice += MyABS(checkWord->length() - word->length());
		if (currPrice <= possibleMistake)
		{
			foundWords.addWordToCollection(currPrice, checkWord);
		}
		Delete_Matrix(checkWord->length(), matrix);
	}

	foundWords.sortWords();
	std::vector<std::string*>* matchedWords = foundWords.getWords();
	return matchedWords;
}

LewinshtainWordCorrecter::LewinshtainWordCorrecter()
{

}

LewinshtainWordCorrecter::~LewinshtainWordCorrecter()
{

}