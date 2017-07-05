#pragma once


struct Kolejka {
	int max;
	int *kolejka;
	int poczatek, koniec;

	Kolejka(int jaki_max);

	int zdejmij();
	void dolacz(int wartosc);
	bool pusta();
	~Kolejka();
};