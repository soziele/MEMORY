#include"mechanizm.h"
#include"wyswietlanie.h"
#include<time.h>
#include<iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

void KARTA::drukuj(char obrazek[3][3], stan stan_karty, int X, int Y, COORD a, bool podswietlona)
{

	if (podswietlona == true) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);


	if (stan_karty == odkryta)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				cout << obrazek[i][j];
			}
			a.Y += 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
		}
	}
	else if (stan_karty == zakryta)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) cout << ' ';
				else cout << obrazek[i][j];
			}

			a.Y += 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
		}
	}
	else if (stan_karty == usunieta)
	{

		a.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
		cout << " o ";


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);


	}
}


KARTA PLANSZA::mieszaj(KARTA plansza[8])
{
	KARTA przechowanie;
	int x;
	srand(time(NULL));


	for (int i = 0; i < 8; i++)
	{
		przechowanie = plansza[i];
		x = (rand() % 8);
		plansza[i] = plansza[x];
		plansza[x] = przechowanie;

	}

	return *plansza;
}


void PLANSZA::drukuj_plansze(KARTA plansza[8])
{
	COORD a;
	a.X = 40;
	a.Y = 7;

	for (int i = 0; i < 4; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
		plansza[i].drukuj(plansza[i].obrazek, plansza[i].stan_karty, a.X, a.Y, a, plansza[i].podswietlona);
		a.X += 5;
	}
	a.X -= 20;
	a.Y += 5;
	for (int i = 4; i < 8; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
		plansza[i].drukuj(plansza[i].obrazek, plansza[i].stan_karty, a.X, a.Y, a, plansza[i].podswietlona);
		a.X += 5;
	}


}

int* PLANSZA::rozgrywka(KARTA plansza[8], PLANSZA Plansza, int* akt)
{
	bool enter = false;
	int tmp = 0;
	int nr1, nr2;
	KARTA wybrana1;
	KARTA wybrana2;
	int aktualna = *akt;

	Plansza.drukuj_plansze(plansza);
	for (int i = 0; i < 8; i++)
	{
		if (plansza[i].podswietlona == true) aktualna = i;
	}


	while (enter == false)
	{

		unsigned char z = _getch();
		switch (z)
		{
		case 224:

			z = _getch();
			switch (z)
			{
			case 72: if (aktualna > 3) aktualna = aktualna - 4;

				plansza[aktualna].podswietlona = true;
				plansza[aktualna + 4].podswietlona = false;
				Plansza.drukuj_plansze(plansza);

				break;
			case 80: if (aktualna < 4) aktualna = aktualna + 4;
				plansza[aktualna].podswietlona = true;
				plansza[aktualna - 4].podswietlona = false;
				Plansza.drukuj_plansze(plansza);

				break;
			case 75: if (aktualna > 0) aktualna--;
				plansza[aktualna].podswietlona = true;
				plansza[aktualna + 1].podswietlona = false;
				Plansza.drukuj_plansze(plansza);

				break;

			case 77: if (aktualna < 7) aktualna++;
				plansza[aktualna].podswietlona = true;
				plansza[aktualna - 1].podswietlona = false;
				Plansza.drukuj_plansze(plansza);

				break;
			}
			z = 0;
			break;
		case 13: if (tmp != 0) enter = true;
			plansza[aktualna].stan_karty = odkryta;

			if (tmp == 0)
			{
				wybrana1 = plansza[aktualna];
				nr1 = aktualna;
			}
			else
			{
				wybrana2 = plansza[aktualna];
				nr2 = aktualna;
			}
			Plansza.drukuj_plansze(plansza);
			tmp++;
			break;


		}
		cout << endl;
		//cout << aktualna << endl;

	}
	if (wybrana1.indeks == wybrana2.indeks && nr1 != nr2)
	{

		plansza[nr1].stan_karty = usunieta;
		plansza[nr2].stan_karty = usunieta;
	}
	else
	{
		Sleep(200);
		plansza[nr1].stan_karty = zakryta;
		plansza[nr2].stan_karty = zakryta;
	}
	system("cls");
	ramka();
	Plansza.drukuj_plansze(plansza);


	//cout << wybrana1.indeks << endl << wybrana2.indeks << endl;
	return akt;
}



void menu(PLANSZA Plansza)
{
	podkreslenie();
	int aktualna = 0;
	int*akt = &aktualna;
	int ilosc_ruchow = 0;
	Plansza.mieszaj(Plansza.plansza);
	Plansza.plansza[0].podswietlona = true;
	int wybor;
	int tmp;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	COORD a;
	a.X = 40;
	a.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << "MENU:";
	a.Y += 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << "1. START";
	a.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << "2. INSTRUKCJA";
	a.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << "3. WYJSCIE";
	a.Y += 4;
	a.X += 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cin >> wybor;

	do
	{
		tmp = 0;
		switch (wybor)
		{
		case 1:
			system("cls");

			ramka();
			Plansza.drukuj_plansze(Plansza.plansza);
			while (Plansza.plansza[0].stan_karty != usunieta || Plansza.plansza[1].stan_karty != usunieta || Plansza.plansza[2].stan_karty != usunieta || Plansza.plansza[3].stan_karty != usunieta || Plansza.plansza[4].stan_karty != usunieta || Plansza.plansza[5].stan_karty != usunieta || Plansza.plansza[6].stan_karty != usunieta || Plansza.plansza[7].stan_karty != usunieta)
			{
				Plansza.rozgrywka(Plansza.plansza, Plansza, akt);
				ilosc_ruchow++;
			}

			system("cls");
			wygrana(ilosc_ruchow);


			break;
		case 2:
			system("cls");
			cout << "Sterowanie odbywa sie za pomoca strzalek.\nWybor karty nalezy zatwierdzic klawiszem enter. \nZadanie polega na polaczeniu kart w pary przy mozliwie najmniejszej liczbie ruchow." << endl << endl;
			cout << "1. START\n3. WYJSCIE" << endl;
			tmp++;

			cin >> wybor;
			break;
		case 3: exit(0);
			break;
		default: cout << "Wpisz numer od 1 do 3!" << endl;
			tmp++;
			cin >> wybor;

			break;
		}

	} while (tmp != 0 || wybor > 3 || wybor < 1);

}
