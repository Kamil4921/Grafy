#include "Krawedzie.h"

void Krawedzie::genruj_wagi(double procent)
{
	int mozliwe_wierzcholki = wierzcholki_ * (wierzcholki_ - 1) / 2;

	int pocz=1 , kon=0;

	for(int i = 0; i < mozliwe_wierzcholki*procent; ++i)
	{
		dodaj_krawedz(kon, pocz, 1 + rand() % 100);
			
		if (kon == pocz-1)
		{
			kon = 0;
			pocz++;
		}
		else
		{
			kon++;
		}
	}

}

int Krawedzie::iloscWierzcholkow() const
{
	return wierzcholki_;
}
