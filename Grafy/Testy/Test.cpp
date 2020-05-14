#include "Test.h"

#include <fstream>
#include <iostream>
#include <chrono>
#include <cstdint>

#include "../Graf/Graf.h"

using namespace std;

void testy(){
	fstream wyniki[2] = { fstream("Macierz.txt", ios::out), fstream("Lista.txt", ios::out) };
	uint64_t czas[2];

	for (int i = 0; i < ROZMIAR_WIERZCHOLKI; i++) {
		cout << "Ilosc wierzcholkow: " << ILOSC_WIERZCHOLKOW[i] << endl;
		for(int j= 0; j < ROZMIAR_PROCENTY ; j++)
		{
			cout << "Procent wypelnienia: " << PROCENTY[j] << endl;
			czas[0] = czas[1] = 0;
			for (int k = 0; k < ILOSC_TESTOW; k++) {
				Graf grafy[2] = { Graf(GRAF_TYP_MACIERZ, ILOSC_WIERZCHOLKOW[i]), Graf(GRAF_TYP_LISTA, ILOSC_WIERZCHOLKOW[i]) };
				for (int l = 0; l < sizeof(grafy) / sizeof(Graf); l++) {
					grafy[l].pobierz_krawedzie()->genruj_wagi(PROCENTY[j]);

					auto start = chrono::high_resolution_clock::now();
					delete grafy[l].dijkstra(0); //usuwa tablice odleglosci
					auto koniec = chrono::high_resolution_clock::now();
					czas[l]+= chrono::duration_cast<chrono::nanoseconds>(koniec - start).count();
				}
			}
			for (int k = 0; k < sizeof(wyniki) / sizeof(fstream); k++) {
				wyniki[k] << ILOSC_WIERZCHOLKOW[i] << "\t" << PROCENTY[j] << "\t" << czas[k] / ILOSC_TESTOW << endl;
			}

		}
	}
	for (int k = 0; k < sizeof(wyniki) / sizeof(fstream); k++) {
		wyniki[k].close();
	}
};