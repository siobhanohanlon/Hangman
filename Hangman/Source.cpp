#include <iostream>
using namespace std;

char d[8] = { 191, 218, 217, 192, 179, 196, 195, 180};
//tr, tl, br, bl, sides, top/b, LTjun, RTjun
//0,  1,  2,  3,    4,    5,     6,      7

void Line(int decide, string message)
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
}

void DrawHangMan(int guess)
{
	//Rope
	if (guess >= 1)
	{
		cout << endl << d[4];
		Line(0, "|");
	}
	else
	{
		Line(0, "");
	}
	if (guess >= 2)
	{
		cout << endl << d[4];
		Line(0, "|");
	}
	else
	{
		Line(0, "");
	}

	//Head
	if (guess >= 3)
	{
		cout << endl << d[4];
		Line(0, "O");
	}
	else
	{
		Line(0, "");
	}

	//Upper Body
	if (guess == 4)
	{
		cout << endl << d[4];
		Line(0, "/");
	}
	else if (guess == 5)
	{
		cout << endl << d[4];
		Line(0, "/| ");
	}
	else if (guess >= 6)
	{
		cout << endl << d[4];
		Line(0, "/|\\");
	}
	else
	{
		Line(0, "");
	}

	//Lower Body
	if (guess >= 7)
	{
		cout << endl << d[4];
		Line(0, "|");

	}
	else 
	{
		cout << endl << d[4];
		Line(0, "");
	}
	if (guess == 8)
	{
		cout << endl << d[4];
		Line(0, "/  ");
	}
	else if (guess == 9)
	{
		cout << endl << d[4];
		Line(0, "/ \\ ");
	}
	else
	{
		Line(0, "");
	}
}

void DisplayBoard(int guess)
{
	cout <<  d[1];
	Line(1, "");
	cout << d[0] << endl << d[4];
	Line(0, "HANGMAN");
	cout << endl << d[6];
	Line(1, "");
	cout << d[7];
	DrawHangMan(9);
}

void DisplayLetters(string input, char from, char to)
{
	string search;

	for (char i = from; i <= to; i++)
	{
		//Using
		if (input.find(i) == string::npos)
		{
			search += i + " ";
		}
		//Already Used
		else
		{
			search += " ";
		}
	}
}

/*
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
>
*/

void PlayGame()
{

}

void main()
{
	DisplayBoard(0);
	PlayGame();
}