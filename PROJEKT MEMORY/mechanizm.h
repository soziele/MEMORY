#pragma once
#ifndef mechanizm_hpp
#define mechanizm_hpp
#include<windows.h>

enum stan
{
	zakryta = 1,
	odkryta = 2,
	usunieta = 3


};

struct KARTA {
	int indeks;
	char obrazek[3][3];
	stan stan_karty;
	bool podswietlona;
	void drukuj(char[3][3], stan, int, int, COORD, bool);

};

struct PLANSZA {
	KARTA plansza[8];
	KARTA mieszaj(KARTA[8]);
	void drukuj_plansze(KARTA[8]);
	int* rozgrywka(KARTA[8], PLANSZA Plansza, int*);
};

void menu(PLANSZA);


#endif
