#ifndef GRAF_H
#define GRAF_H
#include "Krawedzie/Krawedzie.h"

enum Graf_typ_t
{
	GRAF_TYP_MACIERZ,
	GRAF_TYP_LISTA,
};

class Graf {
public:
	Graf(Graf_typ_t typ, int ilosc_wierzcholkow);
	~Graf();
	
	int* dijkstra(int wierz_startowy);

	Krawedzie* pobierz_krawedzie();

private:
	Krawedzie* krawedzie_;
};

#endif 
