/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: pamiec_dzielona.h
*/

#ifndef pamiecdzielona
#define pamiecdzielona

#include <semaphore.h>

#define KOLOR_CZERWONY		"\x1b[31m"
#define KOLOR_ZIELONY		"\x1b[32m"
#define KOLOR_ZOLTY		"\x1b[33m"
#define KOLOR_NIEBIECKI		"\x1b[34m"
#define KOLOR_MAGENTA		"\x1b[35m"
#define KOLOR_CYAN		"\x1b[36m"
#define DOMYSLNY_KOLOR		"\x1b[0m"

struct dzielona {
	sem_t pelny, pusty, mutexP, mutexK;

	int produkty_skonstruowane;
	int produkty_skonsumowane;
	int rozmiar_bufora;
	int limit_produktow;

	struct {
		int liczba;
		pid_t* lista;
		int czas_oczekiwania;
	} konsumenci;

	struct {
		int liczba;
		pid_t* lista;
		int czas_oczekiwania;
	} producenci;
} *pamiec_dzielona;

void pamiec_dzielona_konstruowanie();
void pamiec_dzielona_domyslne_wartosci();
void pamiec_dzielona_odlacz();

#endif

