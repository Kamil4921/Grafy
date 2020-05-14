#ifndef listah
#define listah

#include "../Krawedzie.h"

struct elementListy
{
	int waga;
	int dowierzcholka;
	elementListy* nastepny;
	
	elementListy(int waga = 0, int dowierzcholka = 0, elementListy* nastepny = nullptr)
	{
		this->waga = waga;
		this->dowierzcholka = dowierzcholka;
		this->nastepny = nastepny;
	};
};

class Lista :
	public Krawedzie
{
public:
	Lista(int iloscwierzcholkow);
	~Lista();
	virtual void dodaj_krawedz(int wierzcholek, int wierzcholek1, int waga);
	virtual void wyswietl_wagi();
	virtual int zwroc(int wierzcholek, int wierzcholek1);
private:
	elementListy** listy;
	
};

#endif 