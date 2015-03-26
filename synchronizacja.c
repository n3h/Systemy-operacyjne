/*
* Systemy operacyjne: problem producentów-konsumentów
* Autor: Kamil Bębenek
* Data: 17.02.2013
* Nazwa pliku: synchronizacja.c
*/

#include "argumenty.h"
#include "informacje.h"
#include "semafory.h"
#include "pamiec_dzielona.h"
#include "nadzorca_producentow.h"
#include "nadzorca_konsumentow.h"

int main(int argc, char* argv[]) {
	pamiec_dzielona_konstruowanie();
	pamiec_dzielona_domyslne_wartosci();
	argumenty_inicjowanie(argc, argv);

	semafory_inicjowanie();

	informacje_o_restauracji();

	producenci_konstruowanie();
	konsumenci_konstruowanie();

	producenci_oczekiwanie();
	konsumenci_oczekiwanie();
	
	pamiec_dzielona_odlacz();
	semafory_zamknij();

	return 0;
}
