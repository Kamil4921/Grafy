#ifndef TEST_H
#define TEST_H

constexpr int ILOSC_WIERZCHOLKOW[] = { 10, 50, 100, 500, 1000 };
constexpr int ROZMIAR_WIERZCHOLKI = sizeof (ILOSC_WIERZCHOLKOW)/sizeof (int);

constexpr double PROCENTY[] = { 0.25, 0.5, 0.75, 1 };
constexpr int ROZMIAR_PROCENTY = sizeof(PROCENTY) / sizeof(double);

constexpr int ILOSC_TESTOW = 100;

void testy();

#endif