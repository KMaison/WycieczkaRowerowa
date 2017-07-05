#include <iostream>
#include "Czlowiek.h"
#include "Kolejka.h"

void BFS(int *rowery, Czlowiek *tab, Kolejka &kolejka, int l_ludzi)
{
	int tmp_id, Z;
	while (kolejka.pusta()==false)
	{
		tmp_id = kolejka.zdejmij();
		for (int j = 0; j < tab[tmp_id].ilosc; j++)
		{
			if (rowery[tab[tmp_id].tablica_pref[j]] != -1)  
			{
				Z = rowery[tab[tmp_id].tablica_pref[j]];
				if (tab[Z].odleglosc == -1)
				{
					tab[Z].odleglosc = tab[tmp_id].odleglosc + 1; 
					kolejka.dolacz(Z); 
				}
			}
		}
	}
}
bool DFS(int *rowery, Czlowiek *tab, int i)
{
	tab[i].czy_odwiedzony = true;
	int y;
	for (int j = 0; j < tab[i].ilosc; j++)
	{
		y = rowery[tab[i].tablica_pref[j]]; //y to numer id osoby skojarzonej (lub -1 jak rower jest nieskojarzony) z rowerem ktory chce tab[i]
		if (y == -1) //jeśli y nie jest skojarzona
		{
			rowery[tab[i].tablica_pref[j]] = i;  //to skojarz X z Y i zwróć true
			tab[i].czy_skojarzony = true;
			return true;
		}
		if (tab[y].czy_odwiedzony == false && tab[y].odleglosc - tab[i].odleglosc==1 )
		{
			if (DFS(rowery, tab, y))
			{
				rowery[tab[i].tablica_pref[j]] = i;
				tab[i].czy_skojarzony = true;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int l_ludzi, l_rowerow;
	scanf("%d%d", &l_ludzi, &l_rowerow);
	Czlowiek* tab;
	tab = (Czlowiek*)malloc(l_ludzi * sizeof(Czlowiek));

	Kolejka kolejka(l_ludzi);
	int ilosc_wybranych, rower;
	int *rowery;
	rowery = (int*)malloc(l_rowerow * sizeof(int));
	for (int i = 0; i < l_rowerow; i++)
	{
		rowery[i] = -1;  //-1 czyli nieskojarzony
	}
	for (int i = 0; i < l_ludzi; i++) //wpisywanie danych
	{
		scanf("%i", &ilosc_wybranych);
		tab[i].inicjalizuj(ilosc_wybranych);
		for (int j = 0; j < ilosc_wybranych; j++)
		{
			scanf("%i", &rower);
			rower--;
			tab[i].tablica_pref[j] = rower;
		}
	}
	int wynik = 0,lla=0;
	bool dfs;
	do
	{
		//ETAP 1 - BFS
		kolejka.poczatek = 0;
		kolejka.koniec = 0;
		for (int i = 0; i < l_ludzi; i++)
		{
			
			if (tab[i].czy_skojarzony == false)
			{
				kolejka.dolacz(i);	
				tab[i].odleglosc = 0;
			}
			else tab[i].odleglosc = -1;
		}
		BFS(rowery, tab, kolejka, l_ludzi);

		//ETAP 2 - DFS
		dfs = false;
		for (int i = 0; i < l_ludzi; i++)
		{
			tab[i].czy_odwiedzony = false;
			if (tab[i].czy_skojarzony == false)
				if (DFS(rowery, tab, i)==true)
				{
					dfs = true;
				}
		}
	} while (dfs == true);

	for (int i = 0; i < l_ludzi; i++)
	{
		if (tab[i].czy_skojarzony) wynik++;
	}
	printf("%d ", wynik);
	for (int i = 0; i < l_ludzi; i++) {
		tab[i].usun();
	}
	free(tab);
	free(rowery);
	return 0;

}