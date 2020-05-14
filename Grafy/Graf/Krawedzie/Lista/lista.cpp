#include "lista.h"

Lista::Lista(int iloscwierzcholkow)
{
	wierzcholki_ = iloscwierzcholkow;
	listy = new elementListy * [iloscwierzcholkow] {nullptr};
}

Lista::~Lista()
{
	elementListy* tmp;
	for(int i=0; i< wierzcholki_; i++)
	{
		while (listy[i] != nullptr)
		{
			tmp = listy[i]->nastepny;
			delete listy[i];

			listy[i] = tmp;
		}
	}
	delete[] listy;
}

void Lista::dodaj_krawedz(int wierzcholek, int wierzcholek1, int waga)
{
	elementListy* nowy = new elementListy{waga, wierzcholek1, nullptr};

	if (listy[wierzcholek] == nullptr)
	{
		listy[wierzcholek] = nowy;
	}
	else
	{
		elementListy* tmp;
		tmp = listy[wierzcholek];
		while (tmp->nastepny != nullptr)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = nowy;
	}
}

void Lista::wyswietl_wagi()
{
	for (int i = 0; i < wierzcholki_; i++)
	{
		elementListy* tmp = listy[i];

		while (tmp != nullptr)
		{
			std::cout << tmp->dowierzcholka << " " << tmp->waga << "    ";
			tmp = tmp->nastepny;
		}
		std::cout << std::endl;
	}
}

int Lista::zwroc(int wierzcholek, int wierzcholek1)
{
	elementListy* tmp = listy[wierzcholek];

	for (int i = 0; i < wierzcholki_; i++)
	{
		if (tmp == nullptr)
		{
			return NIESK;
		}

		if (tmp->dowierzcholka == wierzcholek1)
		{
			return tmp->waga;
		}

		tmp = tmp->nastepny;
	}
}
