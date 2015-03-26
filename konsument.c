/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: konsument.c
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
	const int czas_oczekiwania = pamiec_dzielona->konsumenci.czas_oczekiwania;

	int okienka;
  
	while(pamiec_dzielona->produkty_skonsumowane < limit_produktow) {
		sem_getvalue(&pamiec_dzielona->pelny,&okienka);
		if (okienka>0) {
			sem_wait(&pamiec_dzielona->pelny);
			sem_wait(&pamiec_dzielona->mutexK);
			++pamiec_dzielona->produkty_skonsumowane;
			printf( KOLOR_ZIELONY "\t\t\t\t\t\t\t\t\tKelner %d zaniósł posiłek do klienta." DOMYSLNY_KOLOR, pid);
			sem_getvalue(&pamiec_dzielona->pelny,&okienka);
			printf("\t\tPozostało posiłków w oknach: %d.\n", okienka);
			sem_post(&pamiec_dzielona->mutexK);
			sem_post(&pamiec_dzielona->pusty);
			sleep(czas_oczekiwania);
		}
	}
	
	pamiec_dzielona_odlacz();

	return 0;
}
