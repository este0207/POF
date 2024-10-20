#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PILE 1
#define FACE 2
#define QUITTER 0

int pause() {
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int main() {
    int choix;
    int reussites = 0, echecs = 0;
    char input[10];


    while (1) {
        system("clear");
        printf("######## Pile ou Face ##########\n");
        printf("\nPile ou face ?\n");
        printf("1. Pile\n");
        printf("2. Face\n");
        printf("0. Quitter le jeu\n");

        fgets(input, sizeof(input), stdin);
        
        // strcasecmp compare deux chaines de caractères sans prendre en compte les majuscules et minuscules
        if (strncasecmp(input, "quitter", 7) == 0 || strncasecmp(input, "quit", 4) == 0 || strncasecmp(input, "exit", 4) == 0 || strncasecmp(input, "q", 1) == 0 || strncasecmp(input, "0", 1) == 0) {
            choix = QUITTER;
        }
        else if (strncasecmp(input, "pile", 4) == 0 || strncasecmp(input, "1", 1) == 0 || strncasecmp(input, "p", 1) == 0) {
            choix = PILE;
        }
        else if (strncasecmp(input, "face", 4) == 0 || strncasecmp(input, "2", 1) == 0 || strncasecmp(input, "f", 1) == 0) {
            choix = FACE;
        }
        else {
            printf("Choix invalide. Essayez encore.\n");
            continue;
        }

        if (choix == QUITTER) {
            break;
        }

        printf("Vous faites %s !\n", choix == PILE ? "Pile" : "Face");
        printf("La pièce est jetée");
        pause();

        int resultat = rand() % 2 + 1; // 1 = Pile, 2 = Face

        if (resultat == choix) {
            printf("C'est GAGNé, bien joué !\n");
            reussites++;
        } else {
            printf("C'est PERDU, dommage...\n");
            echecs++;
        }

        printf("Reussites : %d\nEchecs : %d\n", reussites, echecs);
        printf("Appuyez sur Entrée pour continuer...\n" );
        getchar();

        if (echecs >= 10) {
            printf("GAME OVER\n");
            break;
        }
    }

    printf("Vous quittez le jeu.\n");
    printf("Reussites : %d\nEchecs : %d\n", reussites, echecs);
    printf("|-------------------------------|\n");
    printf("########### GAME OVER ###########\n");

    return 0;
}

