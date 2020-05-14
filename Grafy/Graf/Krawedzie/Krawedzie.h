#ifndef UNTITLED6_KRAWEDZIE_H
#define UNTITLED6_KRAWEDZIE_H

#include <iostream>

#define NIESK INT32_MAX
#define BRAK_KRAWEDZI INT32_MAX

class Krawedzie {
protected:
	int wierzcholki_;
public:
	virtual ~Krawedzie() {};
	virtual void dodaj_krawedz(int wierzcholek, int wierzcholek1, int waga) = 0;
	virtual void wyswietl_wagi() = 0;
	virtual int zwroc(int wierzcholek, int wierzcholek1) = 0;
	void genruj_wagi(double procent);
	int iloscWierzcholkow () const;
};

#endif //UNTITLED6_KRAWEDZIE_H