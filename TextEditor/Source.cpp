#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

struct line
{
	int Size;
	char*Cs;
};
struct Document
{
	int NoOfLines;
	line*lines;

};

using namespace std;
void Initialization(Document &Doc);
void gotoRowCol(int rpos, int cpos);
void WordNotFound(int crow, int ccol, int counter);
void AdditionOfChar(Document &MSDoc, int& cc, int &cr, char ch, int Size, int NewSize);
void Print(Document Doc, int ccol, int crow);
void Shrinkage(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize);
void InBetweenAdditionOfChar(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize);
void InputFromFile(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word);
void InBetweenShrinkage(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize);
void Switch(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, int&ri, char*&File);
void Clear(int cr, int Sizee, int cc);
void ErasingCharacter(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize);
void AddingCharacter(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize);
void AdditionOfLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines);
void NextLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines);
void InBetweenAdditionofLines(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines);
void InBetweenDeletingLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines);
void FunctionsMenu(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, char*F, int&r);
void Deleting(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize);
void DeletingLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines);
void SaveOnFile(Document &MSDoc, char*A);
void FillSpace(Document &MSDoc, int row, int col, int Size);
void Lines(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize);
void CursorMovement(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize);
void ReadFromFile(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, char*F, int& ri);
void InitialPrinter(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines);
void Message(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char* &File, int& r);
void FindingWord(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, int choice, char*File);
bool WordMatcher(Document &MSDoc, int rii, int cii, char word[], int wordlen);
void ToUpper(Document &MSDoc);
void InputSentence(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word);
void ToLower(Document &MSDoc);
bool CompareStrings(char st1[], char st2[]);
void PrintAWord(Document &MSDoc, int row, int col, int wordlen, int i);
void Prefix(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word, char*&RWord, int wordlen);
void ShashkayAnagram(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, int choice, char*File, char*&word);
void FunctionT(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, int wordlen, int rii, int cii, char*RWord, int& counter, int i);
void ReplaceWord(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, int wordlen, int rii, int cii, char*RWord);
void Postfix(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word, char*&RWord, int wordlen);
void FunctionFF(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, int wordlen, int rii, int cii, char*RWord, int &counter, int choice);
int TotalWordinAFile(const Document &MSDo, char*F);
int AlphabetsCounter(const Document &MSDoc);
int AverageWordLen(const Document &MSDoc, char*F);
int SpecialChCount(const Document &MSDoc);
int SentenceCount(const Document &MSDoc);
void PassOutput(char pass[], char*A);
void PassInput(char pass[], char*A);
void MaximumLength(const Document &MSDoc, char *&word, char*File);
void MiniMumLength(const Document &MSDoc, char *&word, char * File);
bool TrueFalse(char arr[], char arr2[], int len1, int len2);
int AnagramChecker(Document &MSDoc, char * File, char arr[]);
int ParaGraphCounter(Document &MSDoc);
void Anagram(Document &MSDoc, char * File, char* &word);
void MAXParaGraphCounter(Document &MSDoc, char*F);
void EncodeTheFile(Document &MSDoc, int Pass);
void DecodeTheFile(Document &MSDoc, int Pass);
void PasswordEn(char Pass[], int choice);
void ChangeColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
	SetConsoleTextAttribute(hConsole, color);
}

void main()
{


	int crow = 0, ccol = 0, Sizee = 0, NewSize = 0;
	char ch = 'A';
	char*File = NULL;
	int ri = 0;
	Document MSDoc;
	MSDoc.NoOfLines = 1;
	MSDoc.lines = new line[1];
	Message(MSDoc, ccol, crow, ch, Sizee, NewSize, File, ri);

	while (true)
	{
		if (_kbhit())
		{
			Switch(MSDoc, ccol, crow, ch, Sizee, NewSize, ri, File);
		}
	}
}
void EncodeTheFile(Document &MSDoc, int Pass)
{
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] != ' ')

			{
				MSDoc.lines[ri].Cs[ci] = MSDoc.lines[ri].Cs[ci] + Pass;
			}
		}
	}
}
void DecodeTheFile(Document &MSDoc, int Pass)
{
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] != ' ')
			{
				MSDoc.lines[ri].Cs[ci] = MSDoc.lines[ri].Cs[ci] - Pass;
			}
		}
	}
}
int ParaGraphCounter(Document &MSDoc)
{
	int counter = 0;
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		if (MSDoc.lines[ri].Size == 0) counter++;
	}
	counter++;
	return counter;
}
void MAXParaGraphCounter(Document &MSDoc, char*F)
{
	int Paracounter = 0;
	char arr[100];
	int counter = 0;
	int wordcounter = 0;
	int paragraphs = 0;

	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 1; ci < MSDoc.lines[ri].Size - 1; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci - 1] == ' ' && MSDoc.lines[ri].Cs[ci + 1] != ' ' && MSDoc.lines[ri].Cs[ci] != ' ') counter++;
			if (ci == 1) counter++;

		}
		if (MSDoc.lines[ri].Size == 0 || ri == (MSDoc.NoOfLines - 1))
		{
			Paracounter++;
			if (counter>wordcounter)
			{
				wordcounter = counter;
				paragraphs = Paracounter;
			}
			counter = 0;
		}

	}


	cout << "The Paragraph " << paragraphs << " is longest with " << wordcounter << " words !! ";
}

void Anagram(Document &MSDoc, char * File, char * &word)
{
	ifstream fin(File);
	char arr[30];
	int counter = 0;
	int MAx = 0;
	char Maxword[30];
	while (fin)
	{
		fin >> arr;
		if (AnagramChecker(MSDoc, File, arr)>counter)
		{
			strcpy_s(Maxword, 30, arr);
			counter = AnagramChecker(MSDoc, File, arr);
		}
	}
	word = new char[strlen(Maxword) + 1];
	strcpy_s(word, strlen(Maxword) + 1, Maxword);
	*(word + strlen(Maxword)) = '\0';
}
int AnagramChecker(Document &MSDoc, char * File, char arr[])
{
	ifstream fin(File);
	int len2 = 0;
	int counter = 0;
	char arr2[100];
	int len1 = strlen(arr);
	while (fin)
	{

		fin >> arr2;
		len2 = strlen(arr2);
		if (TrueFalse(arr, arr2, len1, len2)) counter++;
	}
	return counter;

}

bool TrueFalse(char arr[], char arr2[], int len1, int len2)
{
	int counter = 0;
	if (len2 <= len1)
	{
		for (int i = 0; i < len2; i++)
		{
			for (int j = 0; j < len1; j++)
			{
				if (arr2[i] == arr[j])
				{
					counter++;
					break;
				}
			}
		}
		if (counter == len2) return true;
		return false;
	}
	else
	{
		return false;
	}

}
void MaximumLength(const Document &MSDoc, char *&word, char * File)
{
	ifstream fin(File);
	char arr[30];
	char wordss[30];
	int counter = 0;
	int MaxI = 0; int Maxl = 0; int len = 0;
	while (fin)
	{
		fin >> arr;
		len = strlen(arr);
		if (len > Maxl)
		{
			Maxl = len;
			strcpy_s(wordss, 30, arr);
		}
	}
	word = new char[Maxl + 1];
	strcpy_s(word, Maxl + 1, wordss);
	*(word + Maxl) = '\0';
}
void MiniMumLength(const Document &MSDoc, char *&word, char * File)
{
	ifstream fin(File);
	char arr[30];
	char wordss[30];
	int counter = 0;
	int MaxI = 0; int Maxl = 0; int len = 0;
	while (true)
	{
		fin >> arr;
		len = strlen(arr);
		Maxl = len;
		strcpy_s(wordss, 30, arr);
		if (len >= 2) break;
	}
	while (fin)
	{
		fin >> arr;
		len = strlen(arr);
		if (len <= Maxl && len>=2)
		{
			Maxl = len;
			strcpy_s(wordss, 30, arr);
		}
	}
	word = new char[Maxl + 1];
	strcpy_s(word, Maxl + 1, wordss);
	*(word + Maxl) = '\0';
}





int SentenceCount(const Document &MSDoc)
{
	int counter = 0;
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] == '.' || MSDoc.lines[ri].Cs[ci] == '!' || MSDoc.lines[ri].Cs[ci] == '?')
			{
				if (ci < (MSDoc.lines[ri].Size - 1))
				{
					if (MSDoc.lines[ri].Cs[ci + 1] == ' ') counter++;
				}
				else
				{
					counter++;
				}
			}
		}
	}
	return counter;
}
int SpecialChCount(const Document &MSDoc)
{
	int counter = 0;
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] != ' ' && MSDoc.lines[ri].Cs[ci] != '.')
			{
				if (!((MSDoc.lines[ri].Cs[ci] >= 'a' && MSDoc.lines[ri].Cs[ci] <= 'z') || (MSDoc.lines[ri].Cs[ci] >= 'A' && MSDoc.lines[ri].Cs[ci] <= 'Z')))
				{
					if (!((MSDoc.lines[ri].Cs[ci] >= '0' && MSDoc.lines[ri].Cs[ci] <= '9'))) counter++;
				}
			}
		}

	}
	return counter;
}

int AverageWordLen(const Document &MSDoc, char*F)
{
	double res = AlphabetsCounter(MSDoc)*1.00 / TotalWordinAFile(MSDoc, F)*1.00;
	int res1 = AlphabetsCounter(MSDoc) / TotalWordinAFile(MSDoc, F);
	if (res - res1 <= 0.5) return res1;
	else return res1 + 1;
}

int TotalWordinAFile(const Document &MSDoc, char *F)
{
	int counter = 0;
	char arr[100];
	ifstream fin(F);
	while (true)
	{
		fin >> arr;
		if (!fin) return counter;
		counter++;
	}


}
int AlphabetsCounter(const Document &MSDoc)
{
	int counter = 0;
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] != ' ' &&  MSDoc.lines[ri].Cs[ci] != '.')
			{
				counter++;
			}
		}
	}
	return counter;
}


void Switch(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, int &ri, char*&File)
{


	ch = _getch();

	if (int(ch) == -32)
	{
		CursorMovement(MSDoc, ccol, crow, ch, Sizee, NewSize);
	}

	else if (int(ch) == 19)
	{
		char A[30];
		system("cls");
		gotoRowCol(20, 25);
		cout << "Enter the File Name Where you want to Save : ";
		ChangeColor(3);
		cin >> A;
		ChangeColor(7);
		SaveOnFile(MSDoc, A);
		exit(1);

	}
	else if (int(ch) == 8)
	{
		Deleting(MSDoc, ccol, crow, ch, Sizee, NewSize);
	}
	else if (int(ch) == 13)
	{
		Lines(MSDoc, ccol, crow, ch, Sizee, NewSize);
	}
	else if (int(ch) == 23)
	{
		FunctionsMenu(MSDoc, ccol, crow, ch, Sizee, NewSize, File, ri);
	}
	else if (int(ch) == 18)
	{
		SaveOnFile(MSDoc, "RunTime.txt");
		FunctionsMenu(MSDoc, ccol, crow, ch, Sizee, NewSize, "RunTime.txt", ri);
	}

	else
	{
		AddingCharacter(MSDoc, ccol, crow, ch, Sizee, NewSize);
		NextLine(MSDoc, ccol, crow, ch, Sizee, NewSize);
	}

	gotoRowCol(crow, ccol);
}

void Deleting(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize)
{
	if (ccol >= 1)ErasingCharacter(MSDoc, ccol, crow, ch, Sizee, NewSize);
	else if (ccol == 0 && crow >= 1)
	{
		if (crow < MSDoc.NoOfLines - 1)
		{
			InBetweenDeletingLine(MSDoc, ccol, crow, ch, Sizee, NewSize);
		}
		else
		{
			DeletingLine(MSDoc, ccol, crow, ch, Sizee, NewSize);
		}

	}
}
void Lines(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize)
{
	if (crow < MSDoc.NoOfLines - 1)
	{
		InBetweenAdditionofLines(MSDoc, ccol, crow, ch, Sizee, NewSize);
	}
	else
	{
		AdditionOfLine(MSDoc, ccol, crow, ch, Sizee, NewSize);
	}
}


void ErasingCharacter(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize)
{
	if (ccol < MSDoc.lines[crow].Size)
	{
		InBetweenShrinkage(MSDoc, ccol, crow, ch, Sizee, NewSize);
		Clear(crow, MSDoc.lines[crow].Size, ccol);
		Print(MSDoc, MSDoc.lines[crow].Size, crow);

	}
	else
	{
		Shrinkage(MSDoc, ccol, crow, ch, Sizee, NewSize);
		Clear(crow, MSDoc.lines[crow].Size, ccol);
		Print(MSDoc, ccol, crow);
	}
}
void AddingCharacter(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize)
{
	if (ccol < MSDoc.lines[crow].Size)
	{
		InBetweenAdditionOfChar(MSDoc, ccol, crow, ch, Sizee, NewSize);
		Clear(crow, MSDoc.lines[crow].Size, ccol);
		Print(MSDoc, MSDoc.lines[crow].Size, crow);

	}
	else
	{
		AdditionOfChar(MSDoc, ccol, crow, ch, Sizee, NewSize);
		Clear(crow, MSDoc.lines[crow].Size, ccol);
		Print(MSDoc, ccol, crow);
	}
}
void CursorMovement(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize)
{
	ch = _getch();
	if (int(ch) == 77)
	{
		if (ccol < 100)
		{
			ccol++;
		}
	}
	else if (int(ch) == 75)
	{
		if (ccol >= 1)
		{
			ccol--;
		}
	}
	else if (int(ch) == 72)
	{
		if (crow >= 1)
		{
			crow--;
			ccol = MSDoc.lines[crow].Size;
		}
	}
	else if (int(ch) == 80)
	{
		if (crow < MSDoc.NoOfLines - 1)
		{
			crow++;
			ccol = MSDoc.lines[crow].Size;
		}

	}
}
void InBetweenAdditionOfChar(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize)
{
	Sizee = MSDoc.lines[cr].Size;
	NewSize = Sizee + 1;
	line* CopyCh = new line[1];
	CopyCh[0].Cs = new char[NewSize];
	for (int j = 0; j < MSDoc.lines[cr].Size; j++)
	{
		CopyCh[0].Cs[j] = MSDoc.lines[cr].Cs[j];
	}
	for (int i = Sizee; i > cc; i--)
	{
		CopyCh[0].Cs[i + 1] = MSDoc.lines[cr].Cs[i];
	}
	CopyCh[0].Cs[cc + 1] = ch;
	delete[] MSDoc.lines[cr].Cs;
	MSDoc.lines[cr].Cs = CopyCh[0].Cs;
	MSDoc.lines[cr].Size = NewSize;
	cc++;
}
void AdditionOfChar(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize)
{
	Sizee = MSDoc.lines[cr].Size;
	NewSize = Sizee + 1;
	line* CopyCh = new line[1];
	CopyCh[0].Cs = new char[NewSize];
	for (int i = 0; i < MSDoc.lines[cr].Size; i++)
	{
		CopyCh[0].Cs[i] = MSDoc.lines[cr].Cs[i];
	}
	CopyCh[0].Cs[cc] = ch;
	delete[] MSDoc.lines[cr].Cs;
	MSDoc.lines[cr].Cs = CopyCh[0].Cs;
	MSDoc.lines[cr].Size = NewSize;
	cc++;
}
void PasswordEn(char Pass[], int choice)
{
	char word;
	gotoRowCol(17, 30);
	ChangeColor(3);
	cout << "Enter Password : ";
	ChangeColor(7);
	gotoRowCol(17, 48);
	int row = 0;
	int i = 0;
	while (true)
	{
		if (_kbhit())
		{
			word = _getch();
			if (int(word) == 13) break;
			else if (int(word) == 8)
			{
				row--;
				gotoRowCol(17, 48 + row);
				cout << " ";
			}
			else
			{
				gotoRowCol(17, 48 + row);
				cout << "*";
				Pass[i] = word;
				Pass[i + 1] = '\0';
				i++;
				row++;
			}
			if (choice == 20)
			{
				if (strlen(Pass) <= 2)
				{

					gotoRowCol(22, 20);
					cout << "Password Strength : ";
					ChangeColor(4);
					gotoRowCol(22, 40);
					cout << "           ";
					gotoRowCol(22, 40);
					cout << "Too Weak";
					ChangeColor(7);
				}
				else if (strlen(Pass) > 3 && strlen(Pass) <= 6)
				{
					gotoRowCol(22, 20);
					cout << "Password Strength : ";
					ChangeColor(4);
					gotoRowCol(22, 40);
					cout << "           ";
					gotoRowCol(22, 40);
					cout << "Weak";
					ChangeColor(7);
				}
				else if (strlen(Pass) > 6 && strlen(Pass) <= 10)
				{
					gotoRowCol(22, 20);
					cout << "Password Strength : ";
					ChangeColor(5);
					gotoRowCol(22, 40);
					cout << "           ";
					gotoRowCol(22, 40);
					cout << "Strong";
					ChangeColor(7);
				}
				else if (strlen(Pass) > 10)
				{
					gotoRowCol(22, 20);
					cout << "Password  Strength : ";
					ChangeColor(2);
					gotoRowCol(22, 40);
					cout << "           ";
					gotoRowCol(22, 40);
					cout << "Too Strong";
					ChangeColor(7);
				}
			}

		}

	}

}
void InBetweenShrinkage(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize)
{
	Sizee = MSDoc.lines[cr].Size;
	NewSize = Sizee - 1;
	line* CopyCh = new line[1];
	CopyCh[0].Cs = new char[NewSize];
	for (int j = cc; j < Sizee - 1; j++)
	{
		MSDoc.lines[cr].Cs[j] = MSDoc.lines[cr].Cs[j + 1];
	}
	for (int i = 0; i < MSDoc.lines[cr].Size - 1; i++)
	{
		CopyCh[0].Cs[i] = MSDoc.lines[cr].Cs[i];
	}
	delete[] MSDoc.lines[cr].Cs;
	MSDoc.lines[cr].Cs = CopyCh[0].Cs;
	MSDoc.lines[cr].Size = NewSize;
	cc--;
}
void Shrinkage(Document &MSDoc, int& cc, int &cr, char ch, int Sizee, int NewSize)
{
	Sizee = MSDoc.lines[cr].Size;
	NewSize = Sizee - 1;
	line* CopyCh = new line[1];
	CopyCh[0].Cs = new char[NewSize];
	for (int i = 0; i < MSDoc.lines[cr].Size - 1; i++)
	{
		CopyCh[0].Cs[i] = MSDoc.lines[cr].Cs[i];
	}
	delete[] MSDoc.lines[cr].Cs;
	MSDoc.lines[cr].Cs = CopyCh[0].Cs;
	MSDoc.lines[cr].Size = NewSize;
	cc--;
}

void Initialization(Document &Doc)
{
	Doc.NoOfLines = 1;
	Doc.lines = new line[Doc.NoOfLines];
	Doc.lines[0].Cs = NULL;
	Doc.lines[0].Size = 0;
}

void Print(Document Doc, int ccol, int crow)
{

	for (int i = 0; i < ccol; i++)
	{
		cout << Doc.lines[crow].Cs[i];
	}



}
void gotoRowCol(int rpos, int cpos)
{
	int xpos = cpos, ypos = rpos;
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}
void Clear(int cr, int Sizee, int cc)
{
	gotoRowCol(cr, 0);
	for (int i = 0; i <101; i++)
	{
		cout << " ";
	}
	gotoRowCol(cr, 0);

}
void AdditionOfLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines)
{
	CLines = MSDoc.NoOfLines;
	NewLines = MSDoc.NoOfLines + 1;
	Document Copy;
	Copy.lines = new line[NewLines];
	for (int i = 0; i < CLines; i++)
	{
		Copy.lines[i].Cs = MSDoc.lines[i].Cs;
		Copy.lines[i].Size = MSDoc.lines[i].Size;
	}
	delete[] MSDoc.lines;
	MSDoc.lines = Copy.lines;
	cc = 0;
	cr++;
	MSDoc.lines[cr].Cs = NULL;
	MSDoc.lines[cr].Size = 0;
	MSDoc.NoOfLines = NewLines;
}
void DeletingLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines)
{
	CLines = MSDoc.NoOfLines;
	NewLines = MSDoc.NoOfLines - 1;
	Document Copy;
	Copy.lines = new line[NewLines];
	for (int i = 0; i < NewLines; i++)
	{
		Copy.lines[i].Cs = MSDoc.lines[i].Cs;
		Copy.lines[i].Size = MSDoc.lines[i].Size;
	}
	delete[] MSDoc.lines;
	MSDoc.lines = Copy.lines;
	cr--;
	cc = Copy.lines[cr].Size;
	MSDoc.NoOfLines = NewLines;
}
void NextLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines)
{
	if (MSDoc.lines[cr].Size == 100)
	{
		AdditionOfLine(MSDoc, cc, cr, ch, CLines, NewLines);
	}
}
void InBetweenDeletingLine(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines)
{
	CLines = MSDoc.NoOfLines;
	NewLines = MSDoc.NoOfLines - 1;
	for (int i = cr; i < NewLines; i++)
	{
		MSDoc.lines[i].Cs = MSDoc.lines[i + 1].Cs;
		MSDoc.lines[i].Size = MSDoc.lines[i + 1].Size;
	}
	Document Copy;
	Copy.lines = new line[NewLines];
	for (int i = 0; i < NewLines; i++)
	{
		Copy.lines[i].Cs = MSDoc.lines[i].Cs;
		Copy.lines[i].Size = MSDoc.lines[i].Size;
	}
	for (int i = cr; i <NewLines; i++)
	{
		gotoRowCol(i, 0);
		Clear(i, Copy.lines[i].Size, i);
		Print(Copy, Copy.lines[i].Size, i);
		cout << endl;
	}
	Clear(NewLines, Copy.lines[NewLines].Size, NewLines);
	delete[] MSDoc.lines;
	MSDoc.lines = Copy.lines;
	cr--;
	cc = Copy.lines[cr].Size;
	MSDoc.NoOfLines = NewLines;
}
void InBetweenAdditionofLines(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines)
{
	CLines = MSDoc.NoOfLines;
	NewLines = MSDoc.NoOfLines + 1;
	Document Copy;
	Copy.lines = new line[NewLines];
	for (int i = 0; i < CLines; i++)
	{
		Copy.lines[i].Cs = MSDoc.lines[i].Cs;
		Copy.lines[i].Size = MSDoc.lines[i].Size;
	}
	for (int i = CLines; i > cr + 1; i--)
	{
		Copy.lines[i].Cs = Copy.lines[i - 1].Cs;
		Copy.lines[i].Size = Copy.lines[i - 1].Size;
	}
	Copy.lines[cr + 1].Size = 0;
	Clear(cr + 1, MSDoc.lines[cr].Size, cc);
	for (int i = cr + 2; i <= CLines; i++)
	{
		gotoRowCol(i, 0);
		Clear(i, Copy.lines[i].Size, i);
		Print(Copy, Copy.lines[i].Size, i);
		cout << endl;
	}

	delete[] MSDoc.lines;
	MSDoc.lines = Copy.lines;
	cc = 0;
	cr++;
	MSDoc.lines[cr].Cs = NULL;
	MSDoc.lines[cr].Size = 0;
	MSDoc.NoOfLines = NewLines;
}
void FillSpace(Document &MSDoc, int row, int col, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		MSDoc.lines[row].Cs[i] = ' ';
	}
}
void SaveOnFile(Document &MSDoc, char * A)
{

	ofstream writer(A);
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			writer << MSDoc.lines[ri].Cs[ci];
		}
		writer << endl;
	}
	cout << "\n\n\n\n\n\n\n\n\n";
}

void ReadFromFile(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, char*F, int &ri)
{
	ifstream fin(F);
	if (!fin)
	{
		cout << "\n\nFile Doesn't Open\n\n";
		exit(1);
	}

	char arr[100];
	int Size = 0;
	int LSIZE = MSDoc.NoOfLines;

	while (fin)
	{
		fin.getline(arr, 100);
		if (!(fin)) break;
		if (ri)
		{
			AdditionOfLine(MSDoc, cc, cr, ch, LSIZE, NewLines);
		}
		Size = strlen(arr);
		MSDoc.lines[ri].Cs = new char[Size + 1];
		MSDoc.lines[ri].Size = Size;
		strcpy_s(MSDoc.lines[ri].Cs, strlen(arr) + 1, arr);
		ri++;

	}
	FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, ri);
}
void FunctionsMenu(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, char*F, int&r)
{
	cr = MSDoc.NoOfLines - 1;
	cc = MSDoc.lines[cr].Size;
	char EnPass[30];
	char DePass[30];
	char word;
	system("cls");
	int Fchoice = 0;
	gotoRowCol(0, 0);
	int Password = 40;
	char PFN[8] = "PFN.txt";
	ChangeColor(2);
	cout << "\n\t\t\t\tYour File Is Successfully Loadad !! \n\n\n";
	ChangeColor(7);
	cout << "Press 1  ,  To Simply Print The File .\n\n";
	cout << "Press 2  ,  To Find Any Word in File .\n\n";
	cout << "Press 3  ,  To Find Any Sentence in File .\n\n";
	cout << "Press 4  ,  To Replace Only First Word .\n\n";
	cout << "Press 5  ,  To Replace All Words .\n\n";
	cout << "Press 6  ,  To Add Prefix to a Specific Word .\n\n";
	cout << "Press 7  ,  To Add Postfix to a Specific Word .\n\n";
	cout << "Press 8  ,  To Find Average Word Length in File .\n\n";
	cout << "Press 9  ,  To Find Total Special Characters in File .\n\n";
	cout << "Press 10 ,  To Find Total Sentences in File .\n\n";
	cout << "Press 11 ,  To Find MaxiMuM Length Word in File .\n\n";
	cout << "Press 12 ,  To Find MiniMUM Length Word in File .\n\n";
	cout << "Press 13 ,  To MergeAnother File .\n\n";
	cout << "Press 14 ,  To Convert into UpperCase Letters .\n\n";
	cout << "Press 15 ,  Convert into LowerCase Letters .\n\n";
	cout << "Press 16 ,  to find a word that contains the alphabets for highest number of other words.\n\n";
	cout << "Press 17 ,  To Find Total Paragraghs in File .\n\n";
	cout << "Press 18 ,  To Find a Paragragh with Maximum words .\n\n";
	cout << "Press 19 ,  To count Substrings in a File .\n\n";
	cout << "Press 20 ,  To EnCode The File .\n\n";
	cout << "Press 21 ,  To DeCode The File .\n\n";
	cout << "Press 22 ,  To Exit .\n\n";
	cout << "\nEnter : ";
	cin >> Fchoice;
	system("cls");
	if (Fchoice == 1)
	{

		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
	}
	else if (Fchoice == 2)
	{

		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
	}
	else if (Fchoice == 3)
	{

		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
	}
	else if (Fchoice == 4)
	{

		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
		SaveOnFile(MSDoc, F);
		system("cls");
		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
		cc = MSDoc.lines[cr].Size;
		gotoRowCol(cr, cc);
	}
	else if (Fchoice == 5)
	{

		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
		SaveOnFile(MSDoc, F);
		system("cls");
		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
		cc = MSDoc.lines[cr].Size;
		gotoRowCol(cr, cc);
	
	}
	else if (Fchoice == 6)
	{

		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
		SaveOnFile(MSDoc, F);
		system("cls");
		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
		cc = MSDoc.lines[cr].Size;
		gotoRowCol(cr, cc);
	}
	else if (Fchoice == 7)
	{

		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
		SaveOnFile(MSDoc, F);
		system("cls");
		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
		cc = MSDoc.lines[cr].Size;
		gotoRowCol(cr, cc);
	}
	else if (Fchoice == 8)
	{
		system("cls");
		cout << "The Average Word Length in the File is : " << AverageWordLen(MSDoc, F);
		Sleep(5000);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 9)
	{
		system("cls");
		cout << "The Total SPecial Characters in the File are : " << SpecialChCount(MSDoc);
		Sleep(5000);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 10)
	{
		system("cls");
		cout << "The Sentences in the File are : " << SentenceCount(MSDoc);
		Sleep(5000);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 11)
	{
		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
	}
	else if (Fchoice == 12)
	{
		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
	}
	else if (Fchoice == 13)
	{
		char arr123[100];
		gotoRowCol(15, 20);
		cout << "Enter The Name of Your File Which you want to Merge : ";
		ChangeColor(3);
		cin >> arr123;
		ChangeColor(7);
		system("cls");
		char*F = arr123;
		ReadFromFile(MSDoc, cc, cr, ch, CLines, NewLines, F, r);

	}
	else if (Fchoice == 14)
	{
		ToUpper(MSDoc);
		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
	}
	else if (Fchoice == 15)
	{
		ToLower(MSDoc);
		InitialPrinter(MSDoc, cc, cr, ch, CLines, NewLines);
	}
	else if (Fchoice == 16)
	{
		FindingWord(MSDoc, cc, cr, ch, CLines, NewLines, Fchoice, F);
	}
	else if (Fchoice == 17)
	{
		system("cls");
		cout << "The Pragraphs in the File are : " << ParaGraphCounter(MSDoc);
		Sleep(5000);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 18)
	{
		system("cls");
		MAXParaGraphCounter(MSDoc, F);
		Sleep(5000);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 19)
	{
		system("cls");
		cout << "The Substrings in this File are : " << TotalWordinAFile(MSDoc, F);
		Sleep(5000);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 20)
	{
		system("cls");
		EncodeTheFile(MSDoc, Password);
		PasswordEn(EnPass, Fchoice);
		PassOutput(EnPass, PFN);
		system("cls");
		SaveOnFile(MSDoc, F);
		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);


	}
	else if (Fchoice == 21)
	{
		PassInput(EnPass, PFN);
		PasswordEn(DePass, Fchoice);
		system("cls");
		if (CompareStrings(EnPass, DePass) == 1)
		{
			DecodeTheFile(MSDoc, Password);
			SaveOnFile(MSDoc, F);
		}
		else
		{
			cout << "\n\nSorry Can't Decrypt it , You Entered the Wrong Password !! ";
			Sleep(2000);
		}

		FunctionsMenu(MSDoc, cc, cr, ch, CLines, NewLines, F, r);
	}
	else if (Fchoice == 22)
	{
		exit(1);
	}
}
void PassOutput(char pass[], char*A)
{
	ofstream fout(A);
	fout << pass;
}
void PassInput(char pass[], char*A)
{
	ifstream fin(A);
	fin >> pass;
}
bool CompareStrings(char st1[], char st2[])
{
	int len1 = strlen(st1);
	int len2 = strlen(st2);
	if (len1 == len2)
	{
		for (int i = 0; i < len1; i++)
		{
			if (st1[i] != st2[i]) return false;
		}
		return true;
	}
	return false;
}

void InitialPrinter(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines)
{
	for (int rii = 0; rii < MSDoc.NoOfLines; rii++)
	{
		for (int cii = 0; cii < MSDoc.lines[rii].Size; cii++)
		{
			cout << MSDoc.lines[rii].Cs[cii];
		}
		cout << endl;
	}

	gotoRowCol(cr, cc);
}
void Message(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char* &File, int& r)
{
	char Mood = 0;
	gotoRowCol(15, 22);
	cout << "Do You Want to Write a New Document ? ( ";
	ChangeColor(2);
	cout << "Y";
	ChangeColor(7);
	cout << " / ";
	ChangeColor(4);
	cout << "N";
	ChangeColor(7);
	cout << " ) : ";
	cin >> Mood;
	system("cls");
	if (Mood == 'y')
	{
		Initialization(MSDoc);
	}
	else
	{
		char arr[100];
		gotoRowCol(15, 28);
		cout << "Enter The Name of Your File : ";
		ChangeColor(3);
		cin >> arr;
		ChangeColor(7);
		system("cls");
		char*F = arr;
		File = F;
		ReadFromFile(MSDoc, ccol, crow, ch, Sizee, NewSize, F, r);
	}
}
void ToUpper(Document &MSDoc)
{
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] >= 'a' && MSDoc.lines[ri].Cs[ci] <= 'z')
			{
				MSDoc.lines[ri].Cs[ci] = MSDoc.lines[ri].Cs[ci] - 32;
			}
		}

	}
}
void ToLower(Document &MSDoc)
{
	for (int ri = 0; ri < MSDoc.NoOfLines; ri++)
	{
		for (int ci = 0; ci < MSDoc.lines[ri].Size; ci++)
		{
			if (MSDoc.lines[ri].Cs[ci] >= 'A' && MSDoc.lines[ri].Cs[ci] <= 'Z')
			{
				MSDoc.lines[ri].Cs[ci] = MSDoc.lines[ri].Cs[ci] + 32;
			}
		}

	}
}
void InputSentence(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word)
{


	cout << "\nEnter Word or Sentence : ";
	int Sizeee = 1;
	int NewSizeee = 0;
	char variable;
	bool check = true;
	while (check)
	{
		if (_kbhit())
		{
			variable = _getch();
			cout << variable;
			if (int(variable) == 13) check = false;
			else
			{
				NewSizeee = Sizeee + 1;
				char* copyword = new char[NewSizeee];
				copyword[Sizeee] = '\0';
				for (int j = 0; j < Sizeee; j++)
				{
					*(copyword + j) = *(word + j);
				}
				copyword[Sizeee - 1] = variable;
				delete[] word;
				word = copyword;
				Sizeee = NewSizeee;
			}
		}

	}
}
void Postfix(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word, char*&RWord, int wordlen)
{
	//cout << "Enter The File name form Where You want to Read the PostFix: ";
	//InputFromFile(MSDoc, ccol, crow, ch, Sizee, NewSize, RWord);
	InputSentence(MSDoc, ccol, crow, ch, Sizee, NewSize, RWord);
	int len = strlen(RWord);
	char*RWCOPY = new char[len + wordlen + 1];
	for (int i = 0; i < wordlen; i++)
	{
		*(RWCOPY + i) = *(word + i);

	}
	for (int j = wordlen; j < len + wordlen; j++)
	{
		*(RWCOPY + j) = *(RWord + (j - wordlen));
	}
	*(RWCOPY + (len + wordlen)) = '\0';
	RWord = RWCOPY;

}
void Prefix(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word, char*&RWord, int wordlen)
{
	//cout << "Enter The File name form Where You want to Read the Prefix : ";
	//InputFromFile(MSDoc, ccol, crow, ch, Sizee, NewSize, RWord);
	InputSentence(MSDoc, ccol, crow, ch, Sizee, NewSize, RWord);
	int len = strlen(RWord);
	char*RWCOPY = new char[len + wordlen + 1];
	for (int i = 0; i < len; i++)
	{
		*(RWCOPY + i) = *(RWord + i);

	}
	for (int j = len; j < len + wordlen; j++)
	{
		*(RWCOPY + j) = *(word + (j - len));
	}
	*(RWCOPY + (len + wordlen)) = '\0';
	RWord = RWCOPY;

}
void InputFromFile(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, char*&word)
{
	char arr[100];
	char input[100];
	cin >> input;
	ifstream fin(input);
	fin.getline(arr, 100);
	int len = strlen(arr);
	word = new char[len];
	strcpy_s(word, len + 1, arr);

}

void FindingWord(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, int choice, char*File)
{
	system("cls");
	char*word = NULL;
	if (choice == 11)
	{
		MaximumLength(MSDoc, word, File);
	}
	else if (choice == 12)
	{
		MiniMumLength(MSDoc, word, File);
	}
	else if (choice == 16)
	{
		Anagram(MSDoc, File, word);
	}
	else
	{
		//	cout << "Enter The File name form Where You want to Read to Search : ";
		//InputFromFile(MSDoc, ccol, crow, ch, Sizee, NewSize, word);
		word = new char[1];
		word[0] = '\0';
		InputSentence(MSDoc, ccol, crow, ch, Sizee, NewSize, word);
	}


	system("cls");
	int wordlen = 0;
	wordlen = strlen(word);
	int counter = 0;
	char * RWord = NULL;
	RWord = new char[1];     // from user
	RWord[0] = '\0';            // from user
	if (choice == 4 || choice == 5)
	{
		cout << "\nTo Replace with !! \n\n";
		//cout << "Enter The File name form Where You want to Read : ";
		InputSentence(MSDoc, ccol, crow, ch, Sizee, NewSize, RWord);
		//InputFromFile(MSDoc, ccol, crow, ch, Sizee, NewSize, RWord);
	}
	else if (choice == 6)
	{
		Prefix(MSDoc, ccol, crow, ch, Sizee, NewSize, word, RWord, wordlen);
	}
	else if (choice == 7)
	{
		Postfix(MSDoc, ccol, crow, ch, Sizee, NewSize, word, RWord, wordlen);
	}
	system("cls");
	InitialPrinter(MSDoc, ccol, crow, ch, Sizee, NewSize);
	for (int rii = 0; rii < MSDoc.NoOfLines; rii++)
	{
		for (int cii = 0; cii < MSDoc.lines[rii].Size; cii++)
		{
			if (word[0] == MSDoc.lines[rii].Cs[cii])
			{
				if (WordMatcher(MSDoc, rii, cii, word, wordlen))
				{
					if (choice == 16)
					{

						ShashkayAnagram(MSDoc, ccol, crow, ch, Sizee, NewSize, choice, File, word);
					}
					if (choice == 2 || choice == 11 || choice == 12 || choice == 16)
					{
						FunctionT(MSDoc, ccol, crow, ch, Sizee, NewSize, wordlen, rii, cii, RWord, counter, 4);
					}
					else if (choice == 3)
					{
						PrintAWord(MSDoc, rii, cii, wordlen, 4);
						gotoRowCol(0, 0);
						counter++;
					}
					else if (choice == 4 || choice == 5 || choice == 6 || choice == 7)
					{

						FunctionFF(MSDoc, ccol, crow, ch, Sizee, NewSize, wordlen, rii, cii, RWord, counter, choice);
						if (choice == 4)
						{
							return;
						}
					}

				}
			}
		}

	}
	gotoRowCol(crow, ccol);
	WordNotFound(crow, ccol, counter);

}





void FunctionT(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, int wordlen, int rii, int cii, char*RWord, int &counter, int i)
{
	if (cii != 0)
	{
		if (cii == MSDoc.lines[rii].Size - wordlen)
		{
			if (MSDoc.lines[rii].Cs[cii - 1] == ' ')
			{
				PrintAWord(MSDoc, rii, cii, wordlen, i);
				gotoRowCol(0, 0);
				counter++;
			}
		}
		else if (MSDoc.lines[rii].Cs[cii - 1] == ' ' && MSDoc.lines[rii].Cs[cii + wordlen] == ' ')
		{
			PrintAWord(MSDoc, rii, cii, wordlen, i);
			gotoRowCol(0, 0);
			counter++;
		}
	}
	else
	{
		if (MSDoc.lines[rii].Cs[cii + wordlen] == ' ')
		{
			PrintAWord(MSDoc, rii, cii, wordlen, i);
			gotoRowCol(0, 0);
			counter++;
		}
	}
}
void FunctionFF(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, int wordlen, int rii, int cii, char*RWord, int &counter, int choice)
{
	if (cii != 0)
	{
		if (cii == MSDoc.lines[rii].Size - wordlen)
		{
			if (MSDoc.lines[rii].Cs[cii - 1] == ' ')
			{
				PrintAWord(MSDoc, rii, cii, wordlen, 4);
				gotoRowCol(0, 0);
				ReplaceWord(MSDoc, cc, cr, ch, CLines, NewLines, wordlen, rii, cii, RWord);
				counter++;
				if (choice == 4)return;
			}
		}
		else if (MSDoc.lines[rii].Cs[cii - 1] == ' ' && MSDoc.lines[rii].Cs[cii + wordlen] == ' ')
		{
			PrintAWord(MSDoc, rii, cii, wordlen, 4);
			gotoRowCol(0, 0);
			ReplaceWord(MSDoc, cc, cr, ch, CLines, NewLines, wordlen, rii, cii, RWord);
			counter++;
			if (choice == 4)return;
		}
	}
	else
	{
		if (MSDoc.lines[rii].Cs[cii + wordlen] == ' ')
		{
			PrintAWord(MSDoc, rii, cii, wordlen, 4);
			gotoRowCol(0, 0);
			if (choice == 4) Sleep(4000);
			ReplaceWord(MSDoc, cc, cr, ch, CLines, NewLines, wordlen, rii, cii, RWord);
			counter++;
			if (choice == 4)return;
		}

	}
}
void ReplaceWord(Document &MSDoc, int& cc, int &cr, char ch, int CLines, int NewLines, int wordlen, int rii, int cii, char*RWord)
{


	cout << endl << endl << RWord;
	char character = 'a';
	int rwordlen = strlen(RWord);
	system("cls");
	InitialPrinter(MSDoc, cii, rii, ch, CLines, NewLines);
	int coll = 0;
	for (int i = 0; i < wordlen; i++)
	{
		coll = (cii + (wordlen - 1)) - i;
		InBetweenShrinkage(MSDoc, coll, rii, ch, CLines, NewLines);
		Clear(rii, MSDoc.lines[rii].Size, coll);
		Print(MSDoc, MSDoc.lines[rii].Size, rii);
	}
	for (int j = 0; j < rwordlen; j++)
	{
		coll = (cii - 1) + j;
		character = *(RWord + j);
		InBetweenAdditionOfChar(MSDoc, coll, rii, character, CLines, NewLines);
		Clear(rii, MSDoc.lines[rii].Size, coll);
		Print(MSDoc, MSDoc.lines[rii].Size, rii);
	}



}
void WordNotFound(int crow, int ccol, int counter)
{
	gotoRowCol(crow, ccol);
	if (!(counter))
	{
		system("cls");
		gotoRowCol(15, 45);
		ChangeColor(3);
		cout << " Not Found!!\n\n\n";
		ChangeColor(7);
		Sleep(5000);
		exit(1);
	}
}
void ShashkayAnagram(Document &MSDoc, int& ccol, int &crow, char ch, int Sizee, int NewSize, int choice, char*File, char*&word)
{
	ifstream fin(File);
	int len2 = 0;
	int counter = 0;
	char arr2[100];
	int len1 = strlen(word);
	while (fin)
	{

		fin >> arr2;
		len2 = strlen(arr2);
		if (TrueFalse(word, arr2, len1, len2))
		{
			for (int rii = 0; rii < MSDoc.NoOfLines; rii++)
			{
				for (int cii = 0; cii < MSDoc.lines[rii].Size; cii++)
				{
					if (arr2[0] == MSDoc.lines[rii].Cs[cii])
					{
						if (WordMatcher(MSDoc, rii, cii, arr2, len2))
						{
							FunctionT(MSDoc, ccol, crow, ch, Sizee, NewSize, len2, rii, cii, arr2, counter, 2);
						}
					}
				}
			}
		}
	}
}

void PrintAWord(Document &MSDoc, int row, int col, int wordlen, int i)
{
	gotoRowCol(row, col);
	ChangeColor(i);
	int ci = 0;
	for (int i = 0; i < wordlen; i++)
	{
		if (col + ci == MSDoc.lines[row].Size)
		{
			row++;
			col = 0;
			ci = 0;
			i += 1;
			gotoRowCol(row, col);

		}
		cout << MSDoc.lines[row].Cs[col + ci];
		ci++;

	}
	ChangeColor(7);
}
bool WordMatcher(Document &MSDoc, int rii, int cii, char word[], int wordlen)
{
	int ciii = 0;
	int riii = 0;
	for (int i = 0; i < wordlen; i++)
	{
		if (cii + ciii == MSDoc.lines[rii].Size && rii<MSDoc.NoOfLines)
		{
			rii++;
			cii = 0;
			ciii = 0;
			riii += 1;
			i += 2;
		}
		if (rii >= MSDoc.NoOfLines) return false;
		if (word[riii] != MSDoc.lines[rii].Cs[cii + ciii]) return false;
		riii++;
		ciii++;

	}
	return true;
}

