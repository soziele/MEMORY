#include"mechanizm.h"
#include"wyswietlanie.h"
#include<iostream>
using namespace std;






int main()
{
	KARTA karta1a{ 1,{ { char(201), char(205), char(187) },{ char(186), '1', char(186) },{ char(200), char(205), char(188) } } , zakryta, false };
	KARTA karta1b{ 1,{ { char(201), char(205), char(187) },{ char(186), '1', char(186) },{ char(200), char(205), char(188) } }, zakryta, false };
	KARTA karta2a{ 2,{ { char(201), char(205), char(187) },{ char(186), '2', char(186) },{ char(200), char(205), char(188) } } , zakryta, false };
	KARTA karta2b{ 2,{ { char(201), char(205), char(187) },{ char(186), '2', char(186) },{ char(200), char(205), char(188) } }, zakryta, false };
	KARTA karta3a{ 3,{ { char(201), char(205), char(187) },{ char(186), '3', char(186) },{ char(200), char(205), char(188) } },zakryta, false };
	KARTA karta3b{ 3,{ { char(201), char(205), char(187) },{ char(186), '3', char(186) },{ char(200), char(205), char(188) } },zakryta, false };
	KARTA karta4a{ 4,{ { char(201), char(205), char(187) },{ char(186), '4', char(186) },{ char(200), char(205), char(188) } },zakryta, false };
	KARTA karta4b{ 4,{ { char(201), char(205), char(187) },{ char(186), '4', char(186) },{ char(200), char(205), char(188) } },zakryta, false };

	PLANSZA Plansza{ { karta1a, karta1b, karta2a, karta2b, karta3a, karta3b, karta4a, karta4b } };


	menu(Plansza);



	system("PAUSE");
	return 0;
}