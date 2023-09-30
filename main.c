#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour dessiner un motif simple
void dessinerMotif() {
    printf("*****\n");
    printf("*   *\n");
    printf("*   *\n");
    printf("*****\n");
}

int main() {
    srand(time(NULL));

    int continuer = 1;
    int nombreSecret = 0; // Initialise le nombre secret à 0

    while (continuer) {
        printf("Menu Principal\n");
        printf("1. Choisir le nombre à deviner\n");
        printf("2. Jouer\n");
        printf("3. Quitter\n");

        int choix;
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Choisir le nombre à deviner
                printf("Entrez un nombre que l'ordinateur devra deviner : ");
                scanf("%d", &nombreSecret);
                printf("Vous avez choisi le nombre %d.\n", nombreSecret);
                break;

            case 2: // Jouer
                if (nombreSecret == 0) {
                    printf("Veuillez d'abord choisir un nombre à deviner.\n");
                } else {
                    system("cls"); // Efface l'écran (Windows)
                    // Vous pouvez utiliser "clear" à la place sous Linux/macOS

                    // Dessine le motif
                    dessinerMotif();

                    // Mesure le temps au début de la recherche
                    clock_t debut = clock();

                    // Simule l'ordinateur qui essaie de deviner
                    int tentative = 0;
                    int devine = 0;

                    while (!devine) {
                        int supposition = rand() % 100 + 1;
                        tentative++;

                        printf("L'ordinateur a devine %d en %d tentatives.\n", supposition, tentative);

                        if (supposition == nombreSecret) {
                            // Mesure le temps à la fin de la recherche
                            clock_t fin = clock();
                            double temps = (double)(fin - debut) / CLOCKS_PER_SEC * 1000.0; // Temps en millisecondes

                            printf("L'ordinateur a trouve le nombre secret %d en %.2f millisecondes!\n", nombreSecret, temps);
                            devine = 1;
                            break;
                        }
                    }

                    // Demande si l'utilisateur veut rejouer
                    printf("Voulez-vous rejouer ? (1 pour oui, 0 pour non) : ");
                    scanf("%d", &continuer);
                }
                break;

            case 3: // Quitter
                continuer = 0;
                break;
        }
    }

    return 0;
}
