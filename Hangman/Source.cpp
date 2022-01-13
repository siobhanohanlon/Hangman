#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

char d[8] = { 191, 218, 217, 192, 179, 196, 195, 180};
char w[];

void Borders(int decide, string message)
{
	if (decide == 1)
	{
		for (int i = 0; i < 33; i++)
		{
			cout << d[5];
		}
	}
	else if (decide == 0)
	{
		bool front = true;
		int totalSpace = 33;

		cout << endl << d[4];
		for (int i = message.length(); i < totalSpace; i++)
		{
			if (front)
			{
				message = " " + message;
			}
			else
			{
				message = message + " ";
			}
			front = !front;
		}
		cout << message.c_str() << d[4];
	}
	else if (decide == 2)
	{
		cout << endl << d[4];
		cout << "          " << d[1];
		for (int i = 0; i < 11; i++)
		{
			cout << d[5];
		}
		cout << d[0] << "          " << d[4] << endl << d[4];
		cout << "          " << d[4] << "           " << d[4] << "          " << d[4];

	}
}
//
void DrawHangMan(int guess)
{
	//Rope
	if (guess >= 1)
	{
		Borders(0, "|");
	}
	else
	{
		Borders(0, "");
	}
	if (guess >= 2)
	{
		Borders(0, "|");
	}
	else
	{
		Borders(0, "");
	}

	//Head
	if (guess >= 3)
	{
		Borders(0, "O");
	}
	else
	{
		Borders(0, "");
	}

	//Upper Body
	if (guess == 4)
	{
		Borders(0, "/");
	}
	else if (guess == 5)
	{
		Borders(0, "/| ");
	}
	else if (guess >= 6)
	{
		Borders(0, "/|\\");
	}
	else
	{
		Borders(0, "");
	}

	//Lower Body
	if (guess >= 7)
	{
		Borders(0, "|");

	}
	else 
	{
		Borders(0, "");
	}
	if (guess == 8)
	{
		Borders(0, "/  ");
	}
	else if (guess == 9)
	{
		Borders(0, "/ \\ ");
	}
	else
	{
		Borders(0, "");
	}
}

void DisplayLetters(string input, char from, char to)
{
	string search;

	for (char i = from; i <= to; i++)
	{
		//Using
		if (input.find(i) == string::npos)
		{
			search += i;
			search += " ";
		}
		//Already Used
		else
		{
			search += "  ";
		}
	}
	Borders(0, search);
}

void DisplayBoard(int guess, string input)
{
	cout <<  d[1];
	Borders(1, "");
	cout << d[0];
	Borders(0, "HANGMAN");
	cout << endl << d[6];
	Borders(1, "");
	cout << d[7];
	DrawHangMan(9);
	Borders(2, "");
	cout << endl << d[6];
	Borders(1, "");
	cout << d[7];
	Borders(0, "Available Letters");
	cout << endl << d[6];
	Borders(1, "");
	cout << d[7];
	DisplayLetters(input, 'A', 'M');
	DisplayLetters(input, 'N', 'Z');
	cout << endl << d[6];
	Borders(1, "");
	cout << d[7];
	Borders(0, "Guess the Word");
	cout << endl << d[6];
	Borders(1, "");
	cout << d[7];	
}

void PlayGame(string word, string input)
{
	bool won = true;
	string s;

	for (int i = 0; i < word.length(); i++)
	{
		if (input.find(word[i]) == string::npos)
		{
			won = false;
			s += "_ ";
		}
		else
		{
			s += word[i];
			s += " ";
		}
	}
	Borders(0, s);
	cout << endl << d[3];
	Borders(1, "");
	cout << d[2] << endl << endl;
}

string LoadWord()
{
	string word;
	int arrLength, lineCount;

	ifstream wordFile;

	wordFile.open("Words.txt");

	if (!wordFile)
	{
		//cerr prints error message
		cerr << "File could not be opened!";
	}
	else
	{
		while (std::getline(wordFile, word))
		{
			for (int i = 0; i < word.length(); i++)
			{

			}
		}
	}
	return "";
}

void main()
{
	string word;

	DisplayBoard(0, "ALEXA");
	word = "ALEXIS";
		//LoadWord();
	PlayGame(word, "ALEXA");
}