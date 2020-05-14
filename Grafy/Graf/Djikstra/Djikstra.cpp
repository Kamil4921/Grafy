#include "Djikstra.h"
#include<iostream>

int* Dijkstra(Krawedzie* krawedzie, int wierz_startowy)
{
	int ilosc_wierzcholkow = krawedzie->iloscWierzcholkow();
	int* odleglosci = new int[ilosc_wierzcholkow];
	bool* czy_odwiedzone = new bool[ilosc_wierzcholkow] { false };
	int indeks_min_odleglosci = 0;

	for (int i = 0; i < ilosc_wierzcholkow; i++)
	{
		odleglosci[i] = INT_MAX;
	}
	odleglosci[wierz_startowy] = 0;

	for (int i = 0; i < ilosc_wierzcholkow - 1; i++)
	{
		int min_odleglosc = INT_MAX;
		for (int j = 0; j < ilosc_wierzcholkow; j++)
		{
			if (czy_odwiedzone[j] == false && min_odleglosc >= odleglosci[j])
			{
				min_odleglosc = odleglosci[j];
				indeks_min_odleglosci = j;
			}
		}
		czy_odwiedzone[indeks_min_odleglosci] = true;


		for (int j = 0; j < ilosc_wierzcholkow; j++)
		{
			int odleglosc = krawedzie->zwroc(indeks_min_odleglosci, j);

			if (czy_odwiedzone[j] == false &&
				odleglosci[j] > odleglosci[indeks_min_odleglosci] + odleglosc &&
				odleglosc != INT_MAX &&
				odleglosci[indeks_min_odleglosci] != INT_MAX)
			{
				odleglosci[j] = odleglosci[indeks_min_odleglosci] + odleglosc;
			}
		}
	}

	return odleglosci;
}
