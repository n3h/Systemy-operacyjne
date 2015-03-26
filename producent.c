/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: producent.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>

#include "pamiec_dzielona.h"


int main() {
	pamiec_dzielona_konstruowanie();

	const int pid = getpid();

	const int limit_produktow = pamiec_dzielona->limit_produktow;
	const int czas_oczekiwania = pamiec_dzielona->producenci.czas_oczekiwania;

	int okienka;

	while(pamiec_dzielona->produkty_skonstruowane < limit_produktow) {
		sem_getvalue(&pamiec_dzielona->pusty,&okienka);
		if (okienka>0) {
			sem_wait(&pamiec_dzielona->pusty);
			sem_wait(&pamiec_dzielona->mutexP);
			++pamiec_dzielona->produkty_skonstruowane;
			printf( KOLOR_CYAN "\t\t\t\tKucharz %d przygotował nowy posiłek.\n" DOMYSLNY_KOLOR, pid);
			sem_post(&pamiec_dzielona->mutexP);
			sem_post(&pamiec_dzielona->pelny);
			sleep(czas_oczekiwania);
		}
	}
	
	pamiec_dzielona_odlacz();
	return 0;
}
