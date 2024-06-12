
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include "Funkcije.h"

 brojvrtnji = 0;

void provjeraStanja(IGRAC* igrac) {
	printf("Stanje: %d\n", igrac->stanje);
	printf("Ulog: %d\n", igrac->ulog);
	printf("Posljednji Dobitak: %d\n", igrac->dobitak);
	printf("Maksimalni dobitak: %d\n", igrac->maxdobitak);
	printf("Broj vrtnji odigranih: %d\n", brojvrtnji);
}


void promijenaUloga(IGRAC* igrac) {
	int novi_ulog;
	int validinput = 0;
	do {
		printf("Unesite novi ulog djeljiv s 10!!:\n ");
		if (scanf(" %d", &novi_ulog) != 1) {
			while (getchar() != '\n');

		}
		else {
			validinput = (novi_ulog % 10 == 0);
			if (novi_ulog <= 0) {
				printf("ne smije bit 0 i u minusu\n");

			}

		}
	} while (!validinput);

	if (novi_ulog <= igrac->stanje) {
		igrac->ulog = novi_ulog;
		printf("Ulog je uspjesno promijenjen.\n");
	}
	else if (novi_ulog > igrac->stanje)
	{
		printf("Nemate dovoljno sredstava za postavljeni ulog.\n");
	}
}
char Simboli() {
	int Broj = random(1, 100);

	if (Broj <= 20) {
		return 'J';
	}
	else if (Broj <= 40) {
		return 'Q';
	}
	else if (Broj <= 60) {
		return 'A';
	}
	else if (Broj <= 80) {
		return 'K';
	}
	else if (Broj <= 100)
	{
		return '7';
	}
}
void PrintP(char polje[5][3])
{

	for (int j = 0; j < 3; j++) {
		printf("================");
		printf("||");
		for (int i = 0; i < 5; i++) {
			printf("%c |\t", polje[i][j]);
		}
		printf("================\n");
	}
}
int provjera(char polje[5][3]) {
	//prve 3 linije
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == '7' && polje[1][i] == '7') {
			return 1;
		}
	}
	//1.dijagonala
	if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A') {
		return 1;
	}
	if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K') {
		return 1;
	}
	if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q') {
		return 1;
	}
	if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J') {
		return 1;
	}
	if (polje[0][0] == '7' && polje[1][1] == '7') {
		return 1;
	}
	//2. dijagonala
	if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A') {
		return 1;
	}
	if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K') {
		return 1;
	}
	if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J') {
		return 1;
	}
	if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q') {
		return 1;
	}
	if (polje[0][2] == '7' && polje[1][1] == '7') {
		return 1;
	}
	//6.linija
	if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A') {
		return 1;
	}
	if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K') {
		return 1;
	}
	if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J') {
		return 1;
	}
	if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q') {
		return 1;
	}
	if (polje[0][1] == '7' && polje[1][2] == '7') {
		return 1;
	}
	//7.linija
	if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A') {
		return 1;
	}
	if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K') {
		return 1;
	}
	if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J') {
		return 1;
	}
	if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q') {
		return 1;
	}
	if (polje[0][1] == '7' && polje[1][0] == '7') {
		return 1;
	}
	//8.linija
	if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A') {
		return 1;
	}
	if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K') {
		return 1;
	}
	if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J') {
		return 1;
	}
	if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q') {
		return 1;
	}
	if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][1] == '7') {
		return 1;
	}
	//9.linija
	if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A') {
		return 1;
	}
	if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K') {
		return 1;
	}
	if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J') {
		return 1;
	}
	if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q') {
		return 1;
	}
	if (polje[0][2] == '7' && polje[1][0] == '7' && polje[2][1] == '7') {
		return 1;
	}
}
void spin(IGRAC* igrac, char polje[5][3]) {


	if (igrac->stanje < igrac->ulog) {
		printf("Nedovoljno kredita, smanjite ulog!\n");
		return 1;
	}

	igrac->stanje = igrac->stanje - igrac->ulog;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			polje[i][j] = Simboli();
		}
	}
	brojvrtnji++;

	PrintP(polje);
	
	static double dobitak = 0;

	if (provjera(polje) == 1) {
		printf("Cestitamo, osvojili ste:\n");

		int provjera = 0;
		int provjerad = 0;
		//provjera za prve 3 linije
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J' && polje[3][i] == 'J' && polje[4][i] == 'J') {
				dobitak = igrac->ulog * 10;
				igrac->stanje = igrac->stanje + igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J' && polje[3][i] == 'J') {
				dobitak = igrac->ulog * 2.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
				printf(" %d kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J') {
				dobitak = igrac->ulog * 0.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q' && polje[3][i] == 'Q' && polje[4][i] == 'Q') {
				dobitak = igrac->ulog * 10;
				igrac->stanje = igrac->stanje + igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q' && polje[3][i] == 'Q') {
				dobitak = igrac->ulog * 2.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q') {
				dobitak = igrac->ulog * 0.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K' && polje[3][i] == 'K' && polje[4][i] == 'K') {
				dobitak = igrac->ulog * 15;
				igrac->stanje = igrac->stanje + igrac->ulog * 15;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K' && polje[3][i] == 'K') {
				dobitak = igrac->ulog * 4;
				igrac->stanje = igrac->stanje + igrac->ulog * 4;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K') {
				dobitak = igrac->ulog * 1;
				igrac->stanje = igrac->stanje + igrac->ulog * 1;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A' && polje[3][i] == 'A' && polje[4][i] == 'A') {
				dobitak = igrac->ulog * 15;
				igrac->stanje = igrac->stanje + igrac->ulog * 15;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A' && polje[3][i] == 'A') {
				dobitak = igrac->ulog * 4;
				igrac->stanje = igrac->stanje + igrac->ulog * 4;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A') {
				dobitak = igrac->ulog * 1;
				igrac->stanje = igrac->stanje + igrac->ulog * 1;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7' && polje[3][i] == '7' && polje[4][i] == '7') {
				dobitak = igrac->ulog * 150;
				igrac->stanje = igrac->stanje + igrac->ulog * 150;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7' && polje[3][i] == '7') {
				dobitak = igrac->ulog * 75;
				igrac->stanje = igrac->stanje + igrac->ulog * 75;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7') {
				dobitak = igrac->ulog * 10;
				igrac->stanje = igrac->stanje + igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == '7' && polje[1][i] == '7') {
				dobitak = igrac->ulog * 2;
				igrac->stanje = igrac->stanje + igrac->ulog * 2;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}

		//prva dijagonala
		if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J' && polje[3][1] == 'J' && polje[4][0] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J' && polje[3][1] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q' && polje[3][1] == 'Q' && polje[4][0] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q' && polje[3][1] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}



		if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K' && polje[3][1] == 'K' && polje[4][0] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K' && polje[3][1] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}



		if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A' && polje[3][1] == 'A' && polje[4][0] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A' && polje[3][1] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][0] == '7' && polje[1][1] == '7' && polje[2][2] == '7' && polje[3][1] == '7' && polje[4][0] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][1] == '7' && polje[2][2] == '7' && polje[3][1] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][1] == '7' && polje[2][2] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][1] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//suprotna dijagonala
		if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J' && polje[3][1] == 'J' && polje[4][2] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J' && polje[3][1] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q' && polje[3][1] == 'Q' && polje[4][2] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q' && polje[3][1] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A' && polje[3][1] == 'A' && polje[4][2] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A' && polje[3][1] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K' && polje[3][1] == 'K' && polje[4][2] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K' && polje[3][1] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == '7' && polje[1][1] == '7' && polje[2][0] == '7' && polje[3][1] == '7' && polje[4][2] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][1] == '7' && polje[2][0] == '7' && polje[3][1] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][1] == '7' && polje[2][0] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][1] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//6.Linija

		if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J' && polje[3][2] == 'J' && polje[4][1] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J' && polje[3][2] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q' && polje[3][2] == 'Q' && polje[4][1] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q' && polje[3][2] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A' && polje[3][2] == 'A' && polje[4][1] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A' && polje[3][2] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K' && polje[3][2] == 'K' && polje[4][1] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K' && polje[3][2] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == '7' && polje[1][2] == '7' && polje[2][2] == '7' && polje[3][2] == '7' && polje[4][1] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][2] == '7' && polje[2][2] == '7' && polje[3][2] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][2] == '7' && polje[2][2] == '7') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][2] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//7.Linija

		if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J' && polje[3][0] == 'J' && polje[4][1] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J' && polje[3][0] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q' && polje[3][0] == 'Q' && polje[4][1] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q' && polje[3][0] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A' && polje[3][0] == 'A' && polje[4][1] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A' && polje[3][0] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K' && polje[3][0] == 'K' && polje[4][1] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K' && polje[3][0] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][0] == '7' && polje[3][0] == '7' && polje[4][1] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][0] == '7' && polje[3][0] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][0] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][0] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//8.linija

		if (polje[0][0] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J' && polje[3][2] == 'J' && polje[4][2] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J' && polje[3][2] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q' && polje[3][2] == 'Q' && polje[4][2] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q' && polje[3][2] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A' && polje[3][2] == 'A' && polje[4][2] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A' && polje[3][2] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K' && polje[3][2] == 'K' && polje[4][2] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K' && polje[3][2] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == '7' && polje[1][0] == '7' && polje[2][1] == '7' && polje[3][2] == '7' && polje[4][2] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][0] == '7' && polje[2][1] == '7' && polje[3][2] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][0] == '7' && polje[2][1] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][0] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//9.linija

		if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J' && polje[3][0] == 'J' && polje[4][0] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J' && polje[3][0] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q' && polje[3][0] == 'Q' && polje[4][0] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q' && polje[3][0] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A' && polje[3][0] == 'A' && polje[4][0] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A' && polje[3][0] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K' && polje[3][0] == 'K' && polje[4][0] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K' && polje[3][0] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == '7' && polje[1][2] == '7' && polje[2][1] == '7' && polje[3][0] == '7' && polje[4][0] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][2] == '7' && polje[2][1] == '7' && polje[3][0] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][2] == '7' && polje[2][1] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][2] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}
		igrac->dobitak = dobitak;
		if (igrac->maxdobitak < igrac->dobitak) {
			igrac->maxdobitak = igrac->dobitak;
		}
	}

	else {
		printf("Niste osvojili, pokusajte ponovno.\n");
	}
}

void writePlayerDataToFile(const char* filename, const IGRAC* igraci) {
	FILE* fp = fopen(filename, "a");
	if (fp == NULL) {
		perror("Error opening file");
		return;
	}
	int broj = brojvrtnji;

	fprintf(fp, "Ime: %s, Stanje :%d ,Ulog: %d, Max Dobitak: %d, broj vrtnji:%d\n", igraci->ime, igraci ->stanje, igraci->ulog, igraci->maxdobitak, broj);


	fclose(fp);
}

int compareByName(const void* a, const void* b) {
	return strcmp(((IGRAC*)a)->ime, ((IGRAC*)b)->ime);
}
IGRAC* findPlayerByName(IGRAC* igraci, int broj_igraca, const char* ime) {
	IGRAC key;
	strcpy(key.ime, ime);

	IGRAC* found = bsearch(&key, igraci, broj_igraca, sizeof(IGRAC), compareByName);

	return found;
}
int compareByStanje(const void* a, const void* b) {
	const IGRAC* playerA = (const IGRAC*)a;
	const IGRAC* playerB = (const IGRAC*)b;

	return playerA->stanje - playerB->stanje;
}
void sortPlayersByStanje(IGRAC* igraci, int broj_igraca) {
	qsort(igraci, broj_igraca, sizeof(IGRAC), compareByStanje);
}
void bubbleSortStanje(int* stanje) {
	for (int i = 0; i < brojvrtnji - 1; i++) {
		for (int j = 0; j < brojvrtnji - 1 - i; j++) {
			if (stanje[j] > stanje[j + 1]) {
				int temp = stanje[j];
				stanje[j] = stanje[j + 1];
				stanje[j + 1] = temp;
			}
		}
	}
}
void writeStanjeToFile(const char* filename, int* stanje, IGRAC* igraci, int* dobitak, int* maxdobitak) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		perror("Error opening file");
		return;
	}
	for (int i = 1; i < brojvrtnji; i++) {
	fprintf(fp, "Ime: %s,stanje:%d, Ulog: %d, Max Dobitak: %d,dobitak:%d \n", igraci->ime, stanje[i],igraci->ulog, maxdobitak[i], dobitak[i]);
	}

	fclose(fp);
}



int factorial(int num) {
	if (num == 0 || num == 1) {
		return 1;
	}
	else {
		return num * factorial(num - 1);
	}
}
void deleteDobitciFile() {
	const char* filename = "dobitci.txt";
	int result = remove(filename);

	if (result == 0) {
		printf("File '%s' deleted successfully.\n", filename);
	}
	else {
		perror("Error deleting file");
	}
}
void clearDobitciFile(const char* filename) {
	FILE* fp = fopen(filename, "w"); 
	if (fp == NULL) {
		perror("Error opening file for clearing");
		return;
	}

	fclose(fp); 
	printf("File '%s' cleared successfully.\n", filename);
}

int random(int min, int max) {
	return rand() % (max - min) + min;
}