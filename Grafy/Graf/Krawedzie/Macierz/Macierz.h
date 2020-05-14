#ifndef UNTITLED6_MACIERZ_H
#define UNTITLED6_MACIERZ_H

#include "../Krawedzie.h"

class Macierz :
	public Krawedzie
{
	int** tablica;
public:
	Macierz(int ilosc_wierzcholkow);
	~Macierz();

	virtual void dodaj_krawedz(int wierzcholek, int wierzcholek1, int waga);
	virtual void wyswietl_wagi();
	virtual int zwroc(int wierzcholek, int wierzcholek1);
};

#endif //UNTITLED6_MACIERZ_H