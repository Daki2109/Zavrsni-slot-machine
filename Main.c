#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"Funkcije.h"
#define N 150
#define y 5
#define z 3
int main() {
	int stanje[N];
	int dobitak[N];
	int maxdobitak[N];
	int menu;
	int a;
	int broj_igraca = 0;
	char polje[y][z];
	int b;
	const char* dataFilename = "players.bin";
	int validinput = 0;
	char izaci;
	int numRecords = 0;
	IGRAC* foundPlayer;
	IGRAC* igraci = NULL;
	const char* filename = "dobitci.txt";
	srand((unsigned)time(NULL));
	FILE* fp = fopen("dobitci.txt", "w");
	if (fp == NULL) {
		perror("Unable to open file");
		exit(1);
	}
	

	while (1) {
		printf("\n");
		printf("                             |===================DOMINIKOV CASINO====================| \n");
		printf("                             |     1.Napravite novog korisnika(unos credita i ime)   |\n");
		printf("                             |                 2.Provjera stanja                     |\n");
		printf("                             |                 3.Promjena uloga                      |\n");
		printf("                             |                      4.Info                           |\n");
		printf("                             |                      5.Spin                           |\n");
		printf("                             |               6.Zavrsetak igre(obrisi sve)            |\n");
		printf("                             |                 7. Pronadite igraca                   |\n");
		printf("                             |                 8. Obrisi dobitci.txt                 |\n");
		printf("                             |                 9.Rekurzivna funkcija                 |\n");
		printf("                             |                       10.Qsort                        |\n");
		printf("                             |=======================================================|\n");

			do {
				printf("Unesite broj opcije (1-10): ");
				if (scanf("%d", &menu) != 1) {
					printf("Neispravan unos ljepo sam vas zamolio 1-10.\n");
					while (getchar() != '\n');
				}
				else if (menu < 1 || menu > 10) {
					printf("Neispravan unos ljepo sam vas zamolio 1-10.\n");
				}
				else {
					validinput = 1;
				}
			} while (!validinput);
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
						if (igraci == NULL) {
							return -1;
						}
						igraci[broj_igraca++] = novi_igrac;

						printf("Cestitamo , kreirali ste novog igraca\n");

						long pozicija = ftell(fp);
						if (pozicija != -1L) {
							printf("Current file pointer position in 'dobitci.txt': %ld\n", pozicija);
						}
						else {
							perror("ftell");
						}
					}
					if (b != 1 && b != 0) {
						printf("Ne smijete to unjeti ,unesite 0 ili 1\n");
					}
				} while (b != 0 && b != 1);
		
				writePlayerDataToFile("dobitci.txt", igraci);
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
				writePlayerDataToFile("dobitci.txt", igraci);
				
				stanje[brojvrtnji] = igraci[s].stanje;
				dobitak[brojvrtnji] = igraci[s].dobitak;
				maxdobitak[brojvrtnji] = igraci[s].maxdobitak;
				
				
				fclose(fp);
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
					
					writePlayerDataToFile("dobitci.txt", igraci);
					
				
					exit(0);
				}


				break;
			case 7: {
				char searchName[100];
				printf("Unesite ime igraca za pretragu: ");
				scanf("%s", searchName);

				IGRAC* foundPlayer = findPlayerByName(igraci, broj_igraca, searchName);
				if (foundPlayer != NULL) {
					printf("Player found: %s, Ulog: %d, Dobitak: %d, Max Dobitak: %d\n", foundPlayer->ime, foundPlayer->ulog, foundPlayer->dobitak, foundPlayer->maxdobitak);
				}
				else {
					printf("Player not found\n");
				}
				break;
			}
			case 8:
				clearDobitciFile(filename);
				clearDobitciFile(dataFilename);
				deleteDobitciFile();
				break;
			case 9: {
				int num;
				printf("upisite pozitivni prirodni broj\n ");
				scanf("%d", &num);

				if (num < 0) {
					printf("Mora biti pozitivan\n");
				}
				else {
					int fact = factorial(num);
					printf("Broj koji ste unljeli je:%d , a Faktorijela je:%d\n", num, fact);
				}

				break;
			}
			case 10: {
				bubbleSortStanje(stanje);
				writeStanjeToFile(filename, stanje,igraci,dobitak,maxdobitak);

				break;
			}
			default:
				printf("Neispravan izbor. Molimo pokušajte ponovo.\n");
				break;
		}
	
			



	}
	free(igraci);
	return 0;
}
	
