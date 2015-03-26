/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: nadzorca_konsumentow.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "nadzorca_konsumentow.h"
#include "pamiec_dzielona.h"

void konsumenci_konstruowanie() {
	pamiec_dzielona->konsumenci.lista = malloc(pamiec_dzielona->konsumenci.liczba * sizeof(pid_t));
	pid_t* p = pamiec_dzielona->konsumenci.lista;
	for (int i = 0; i < pamiec_dzielona->konsumenci.liczba; ++i, ++p) {
		pid_t id = fork();
		if (id == 0) {
			execl("konsument", "konsument", NULL);
		} else {
			*p = id;
			printf( KOLOR_CZERWONY "Kelner %d przyszedł do pracy.\n" DOMYSLNY_KOLOR, id);
		}
	}
}

void konsumenci_oczekiwanie() {
	pid_t* obecny_konsument = pamiec_dzielona->konsumenci.lista;
	for (int i = 0; i < pamiec_dzielona->konsumenci.liczba; ++i, ++obecny_konsument) {
		waitpid(*obecny_konsument, 0, 0);
		printf( KOLOR_CZERWONY "Kelner %d wyszedł z pracy.\n" DOMYSLNY_KOLOR, *obecny_konsument);
	}
}

