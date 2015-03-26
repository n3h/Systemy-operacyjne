/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: nadzorca_producentow.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "nadzorca_producentow.h"
#include "pamiec_dzielona.h"

void producenci_konstruowanie() {
	pamiec_dzielona->producenci.lista = malloc(pamiec_dzielona->producenci.liczba * sizeof(pid_t));
	pid_t* p = pamiec_dzielona->producenci.lista;
	for (int i = 0; i < pamiec_dzielona->producenci.liczba; ++i, ++p) {
		pid_t id = fork();
		if (id == 0) {
			execl("producent", "producent", NULL);
		} else {
			*p = id;
			printf( KOLOR_MAGENTA "Kucharz %d przyszedł do pracy.\n" DOMYSLNY_KOLOR, id);
		}
	}
}

void producenci_oczekiwanie() {
	pid_t* obecny_producent = pamiec_dzielona->producenci.lista;
	for (int i = 0; i < pamiec_dzielona->producenci.liczba; ++i, ++obecny_producent) {
		waitpid(*obecny_producent, 0, 0);
		printf( KOLOR_MAGENTA "Kucharz %d zakończył pracę.\n" DOMYSLNY_KOLOR, *obecny_producent);
	}
}

