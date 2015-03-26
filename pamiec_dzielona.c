/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: pamiec_dzielona.c
*/

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#include "pamiec_dzielona.h"

#define LICZBA_PRODUCENTOW			4
#define LICZBA_KONSUMENTOW			3
#define CZAS_OCZEKIWANIA_PRODUCENTA		7
#define CZAS_OCZEKIWANIA_KONSUMENTA		3
#define ROZMIAR_BUFORA				5
#define LIMIT_PRODUKTOW				16

void pamiec_dzielona_konstruowanie() {
	int segment = shm_open("pamiec", O_CREAT | O_RDWR, 0664);
	ftruncate(segment, sizeof(struct dzielona));
	pamiec_dzielona = mmap(NULL, sizeof(struct dzielona), PROT_READ | PROT_WRITE, MAP_SHARED, segment, 0);
}

void pamiec_dzielona_domyslne_wartosci() {
	pamiec_dzielona->produkty_skonstruowane 	= 0;
	pamiec_dzielona->produkty_skonsumowane 		= 0;
	pamiec_dzielona->rozmiar_bufora        		= ROZMIAR_BUFORA;
	pamiec_dzielona->limit_produktow        	= LIMIT_PRODUKTOW;
	pamiec_dzielona->producenci.liczba      	= LICZBA_PRODUCENTOW;
	pamiec_dzielona->konsumenci.liczba      	= LICZBA_KONSUMENTOW;
	pamiec_dzielona->producenci.czas_oczekiwania  	= CZAS_OCZEKIWANIA_PRODUCENTA;
	pamiec_dzielona->konsumenci.czas_oczekiwania  	= CZAS_OCZEKIWANIA_KONSUMENTA;
}

void pamiec_dzielona_odlacz() {
	shm_unlink("pamiec");
}
