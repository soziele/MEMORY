#include"wyswietlanie.h"
#include<iostream>
#include<windows.h>

using namespace std;

void podkreslenie()
{
	COORD a;
	a.X = 40;
	a.Y = 3;
	char z = '_';
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	for (int j = 0; j < 2; j++)
	{
		for (int i = 4; i < 16; i++)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << z;
		}
	}

}


void ramka()
{
	const int szer = 36;
	const int wys = 14;
	char z = 'O';
	cout << endl;


	COORD a;
	a.X = 39;
	a.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "M E M O R Y    G A M E";

	a.Y += 2;
	a.X -= 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	for (int j = 0; j < 3; j++)
	{
		for (int i = 4; i < 16; i++)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << z;
		}
	}
	a.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	for (int i = 0; i < wys - 2; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i + 4);
		cout << z;
		for (int j = 0; j < szer - 2; j++)
		{
			cout << ' ';
		}
		cout << z;
		a.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	}
	for (int j = 0; j < 3; j++)
	{
		for (int i = 4; i < 16; i++)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << z;
		}
	}

}


void wygrana(int ilosc_ruchow)
{
	const int szer = 60;
	const int wys = 14;
	char z = 'O';
	COORD a;
	a.X = 0;
	a.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);


	for (int j = 0; j < 10; j++)
	{
		for (int i = 4; i < 16; i++)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << z;
		}
	}
	a.Y += 10;
	a.X += 40;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "VICTORY!";
	a.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << "ILOSC WYKONANYCH RUCHOW: " << ilosc_ruchow;
	a.Y += 10;
	a.X -= 40;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	for (int j = 0; j < 10; j++)
	{
		for (int i = 4; i < 16; i++)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << z;
		}
	}

}