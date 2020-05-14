#include "Macierz.h"

Macierz::Macierz(int ilosc_wierzcholkow)
{
	wierzcholki_ = ilosc_wierzcholkow;

	tablica = new int* [wierzcholki_];

	for (int i = 0; i < wierzcholki_; ++i)
	{
		tablica[i] = new int[wierzcholki_];
		for (int j = 0; j < wierzcholki_; ++j)
		{
			tablica[i][j] = BRAK_KRAWEDZI;
		}
	}
}

Macierz::~Macierz()
{
	for (int i = 0; i < wierzcholki_; ++i)
	{
		delete[] tablica[i];
	}
	delete[] tablica;
}

void Macierz::dodaj_krawedz(int wierzcholek, int wierzcholek1, int waga)
{
	tablica[wierzcholek][wierzcholek1] = waga;
}

void Macierz::wyswietl_wagi()
{
	for (int i = 0; i < wierzcholki_; ++i)
	{
		for (int j = 0; j < wierzcholki_; ++j)
		{
			std::cout << tablica[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int Macierz::zwroc(int wierzcholek, int wierzcholek1)
{
	return tablica[wierzcholek][wierzcholek1];
}
