/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: informacje.c
*/

#include <stdio.h>
#include <sys/types.h>

#include "informacje.h"
#include "nadzorca_producentow.h"
#include "nadzorca_konsumentow.h"
#include "pamiec_dzielona.h"

void informacje_o_restauracji() {
	printf("*******************************************************************************\n");
	printf("Informacje o restauracji:\n");
	printf("- liczba kucharzy: %d\n",       pamiec_dzielona->producenci.liczba);
	printf("- liczba kelnerów: %d\n",       pamiec_dzielona->konsumenci.liczba);
	printf("- czas przygotowania posiłku przez kucharza: %d\n", pamiec_dzielona->producenci.czas_oczekiwania);
	printf("- czas dostarczenia posiłku do klienta przez kelnera: %d\n", pamiec_dzielona->konsumenci.czas_oczekiwania);
	printf("- liczba okienek, w których kucharz umieszcza posiłki, a kelner je odbiera: %d\n",   pamiec_dzielona->rozmiar_bufora);
	printf("- maksymalna ilość posiłków przygotowywanych jednego dnia: %d\n",   pamiec_dzielona->limit_produktow);
	printf("*******************************************************************************\n");
}
