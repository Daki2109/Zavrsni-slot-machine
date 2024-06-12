#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include"Funkcije.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int menu;
	int a;
	int broj_igraca = 0;
	char polje[5][3];
	int b;
	int validinput = 0;
	char izaci;
	IGRAC* igraci = NULL;
	srand((unsigned)time(NULL));
	FILE* fp = fopen("dobitci.txt", "w");
		while (1) {
			printf("\n");
			printf("                             |===================DOMINIKOV CASINO=================== |\n");
			printf("                             |     1.Napravite novog korisnika(unos credita i ime)   |\n");
			printf("                             |                 2.Provjera stanja                     |\n");
			printf("                             |                 3.Promjena uloga                      |\n");
			printf("                             |                      4.Info                           |\n");
			printf("                             |                      5.Spin                           |\n");
			printf("                             |               6.Zavrsetak igre(obrisi sve)            |\n");
			printf("                             |=======================================================|\n");
			scanf("%d", &menu);

			switch (menu) {
			case 1:;
				IGRAC novi_igrac;
				do {
					printf("Unesite ime igraca:\n ");
					scanf("%s", &novi_igrac.ime);
					printf("Jeste li sigurni da ste unjeli pravilno ime\n");
					printf("Ako jeste unesite 1 u suprotnom unesite 0\n");
					scanf("%d", &b);
					if (b == 0) {
						while (b == 0) {
							printf("Unesite ime igraca:\n ");
							scanf("%s", &novi_igrac.ime);
							printf("Jeste li sigurni da ste unjeli pravilno ime\n");
							printf("Ako jeste unesite 1 u suprotnom unesite 0\n");
							scanf("%d", &b);
						}
					}
					if (b == 1) {
						do {
							printf("Unesite pocetno stanje djeljivo s 10!!:\n ");
							if (scanf(" %d", &novi_igrac.stanje) != 1) {
								while (getchar() != '\n');
								
							}
							else {
								validinput = (novi_igrac.stanje % 10 == 0);
								if (novi_igrac.stanje <= 0) {
									printf("ne smije bit 0 i u minusu\n");

								}
								
							}
						} while (!validinput);
						
						int min = 0;
						int max = 100;

						novi_igrac.ulog = 0;
						novi_igrac.dobitak = 0;
						novi_igrac.maxdobitak = 0;
						igraci = realloc(igraci, (broj_igraca + 1) * sizeof(IGRAC));
						igraci[broj_igraca++] = novi_igrac;

						printf("Cestitamo , kreirali ste novog igraca\n");
					}
					if (b != 1 && b != 0) {
						printf("Ne smijete to unjeti ,unesite 0 ili 1\n");
					}
				} while (b != 0 && b != 1);

				break;
			case 2:
				a = broj_igraca - 1;
				provjeraStanja(&igraci[a]);

				break;
			case 3:
				promijenaUloga(&igraci[broj_igraca - 1]);

				break;
			
			case 4: {
				printf("Igra se sastoji od 5 simbola\n");
				printf("Za Q simbol dobitak je : 3 simbola spojena(0.5x uloga) , 4 simbola spojena(2.5x) , 5 simbola(10x)\n");
				printf("Za J simbol dobitak je : 3 simbola spojena(0.5x uloga) , 4 simbola spojena(2.5x uloga) , 5 simbola(10x uloga)\n");
				printf("Za A simbol dobitak je : 3 simbola spojena(1x uloga) , 4 simbola spojena(4x uloga) , 5 simbola(15x uloga)\n");
				printf("Za K simbol dobitak je : 3 simbola spojena(1x uloga) , 4 simbola spojena(4x uloga) , 5 simbola(15x uloga)\n");
				printf("Za 7 simbol dobitak je : 3 simbola spojena(2x uloga) Za 7 simbol dobitak je : 3 simbola spojena(10x uloga) , 4 simbola spojena(75xuloga) , 5 simbola(150x uloga)\n");
				break;
			}
			case 5: {
				int s = broj_igraca - 1;
				spin(&igraci[s], polje);
				break;
			
			}
			case 6:
				validinput = 0;
				do {
					printf("Jeste li sigurni da zelite izaci iz programa? (D za da / N za ne): ");
					scanf(" %c", &izaci);
					while (getchar() != '\n');
					izaci = tolower(izaci);
					validinput = (izaci == 'd' || izaci == 'n');
					if (!validinput) {
						printf("Neispravan unos. Molimo unesite D za da ili N za ne.\n");
					}
				} while (!validinput);

				if (izaci == 'd') {
					printf("\nPosjetite casino opet!<3\n");
					exit(0);
				}
				
				
				break;

			}


		}
	
	return 0;
}