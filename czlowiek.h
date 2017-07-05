#pragma once

struct Czlowiek
{
	int* tablica_pref;
	bool czy_skojarzony;
	int odleglosc;
	bool czy_odwiedzony;
	int ilosc;
	void inicjalizuj(int n);
	void usun();
};
