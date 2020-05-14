#include "Graf.h"
#include "Djikstra/Djikstra.h"

#include "Krawedzie/Macierz/Macierz.h"
#include "Krawedzie/Lista/lista.h"


Graf::Graf(Graf_typ_t typ, int ilosc_wierzcholkow):
	krawedzie_(nullptr)
{
	switch (typ)
	{
	case GRAF_TYP_MACIERZ:
		krawedzie_ = new Macierz(ilosc_wierzcholkow);
		break;
	case GRAF_TYP_LISTA:
		krawedzie_ = new Lista(ilosc_wierzcholkow);
		break;
	default:
		break;
	}
}

Graf::~Graf()
{
	delete krawedzie_;
}

int* Graf::dijkstra(int wierz_startowy)
{
	return Dijkstra(krawedzie_, wierz_startowy);
}

Krawedzie* Graf::pobierz_krawedzie() {
	return krawedzie_;
}