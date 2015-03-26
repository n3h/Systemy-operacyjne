synchronizacja : synchronizacja.c nadzorca_producentow.c nadzorca_konsumentow.c pamiec_dzielona.c informacje.c semafory.c argumenty.c producent konsument
	gcc -Wall -Wextra -std=gnu99 -pthread -o synchronizacja synchronizacja.c nadzorca_producentow.c pamiec_dzielona.c informacje.c semafory.c argumenty.c nadzorca_konsumentow.c -lrt

producent : producent.c pamiec_dzielona.c
	gcc -Wall -Wextra -std=gnu99 -pthread -o producent producent.c pamiec_dzielona.c -lrt

konsument : konsument.c pamiec_dzielona.c
	gcc -Wall -Wextra -std=gnu99 -pthread -o konsument konsument.c pamiec_dzielona.c -lrt

clean :
	rm synchronizacja producent konsument
