/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: semafory.c
*/

#include <sys/types.h>
#include <semaphore.h>
#include <sys/types.h>

#include "semafory.h"
#include "pamiec_dzielona.h"

void semafory_inicjowanie() {
	sem_init(&pamiec_dzielona->pusty, 1, pamiec_dzielona->rozmiar_bufora);
	sem_init(&pamiec_dzielona->pelny, 1, 0);
	sem_init(&pamiec_dzielona->mutexP, 1, 1);
	sem_init(&pamiec_dzielona->mutexK, 1, 1);
}

void semafory_zamknij() {
	sem_close(&pamiec_dzielona->pusty); 
 	sem_close(&pamiec_dzielona->pelny); 
	sem_close(&pamiec_dzielona->mutexP); 
	sem_close(&pamiec_dzielona->mutexK); 
}
