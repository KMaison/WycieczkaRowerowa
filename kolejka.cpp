#include "Kolejka.h"
#include <iostream>
Kolejka::Kolejka(int jaki_max)
{
	max = jaki_max;
	kolejka= (int*)malloc(max * sizeof(int));
	for (int i = 0; i < max; i++) {
		kolejka[i] = 0;
	}
	poczatek = 0, koniec = 0;
	}

int Kolejka::zdejmij()
{
	int pom=kolejka[poczatek];
	poczatek++;
	return pom;
}


void Kolejka::dolacz(int wartosc)
{
	kolejka[koniec] = wartosc;
	koniec++;
}
bool Kolejka::pusta()
{
	if (poczatek != koniec)
		return false;
	else
		return true;
}

Kolejka::~Kolejka()
{
	free(kolejka); 
}
