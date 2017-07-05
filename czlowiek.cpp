#include "Czlowiek.h"
#include <iostream>
void Czlowiek::inicjalizuj(int n)
{
	tablica_pref = (int*)malloc(n * sizeof(int));
	ilosc = n;
	odleglosc = -1;
	czy_skojarzony = false;
	czy_odwiedzony = false;
}

void Czlowiek::usun()
{
	free(tablica_pref);
}

