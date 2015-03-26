/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: argumenty.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "informacje.h"
#include "pamiec_dzielona.h"

void argumenty_inicjowanie(int argc, char** argv)
{
	int parametr;

	while ((parametr = getopt(argc, argv, "p:k:m:n:r:i:")) != -1) {
		switch (parametr) {
			case 'p':
				if (atoi(optarg) >= 0)
					pamiec_dzielona->producenci.liczba = atoi(optarg);
				break;
			case 'k':
				if (atoi(optarg) >= 0)
				pamiec_dzielona->konsumenci.liczba = atoi(optarg);
				break;
			case 'm':
				if (atoi(optarg) >= 0)
					pamiec_dzielona->producenci.czas_oczekiwania = atoi(optarg);
				break;
			case 'n':
				if (atoi(optarg) >= 0)
					pamiec_dzielona->konsumenci.czas_oczekiwania = atoi(optarg);
				break;
		
			case 'r':
				if (atoi(optarg) >= 0)
					pamiec_dzielona->rozmiar_bufora = atoi(optarg);
				break;

			case 'i':
				if (atoi(optarg) >= 0)
					pamiec_dzielona->limit_produktow = atoi(optarg);
				break;

			default:
				exit(EXIT_FAILURE);
    }
  }
}
