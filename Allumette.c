//
// Created by Piquionne Andy on 03/05/2023.
//


#include <stdio.h>

int main() {
    int matches = 21;
    int currentPlayer = 1;

    while (matches > 0) {
        printf("Il reste %d allumettes.\n", matches);
        printf("Joueur %d, combien d'allumettes voulez-vous retirer (1-3) ? ", currentPlayer);

        int removed;
        scanf("%d", &removed);

        if (removed < 1 || removed > 3) {
            printf("Veuillez entrer un nombre valide d'allumettes à retirer (1-3).\n");
        } else if (removed > matches) {
            printf("Il n'y a pas assez d'allumettes restantes. Veuillez choisir un nombre inférieur d'allumettes à retirer.\n");
        } else {
            matches -= removed;
            currentPlayer = 3 - currentPlayer; // Alterne entre 1 et 2
        }
    }

    printf("Joueur %d a retiré la dernière allumette. Joueur %d gagne!\n", 3 - currentPlayer, currentPlayer);
    return 0;
}


//Ordi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matches = 21;
    int currentPlayer = 1;

    srand(time(NULL));

    while (matches > 0) {
        printf("Il reste %d allumettes.\n", matches);

        int removed;

        if (currentPlayer == 1) {
            printf("Joueur, combien d'allumettes voulez-vous retirer (1-3) ? ");
            scanf("%d", &removed);
        } else {
            removed = (matches - 1) % 4;
            if (removed == 0) {
                removed = rand() % 3 + 1;
            }
            printf("L'ordinateur retire %d allumettes.\n", removed);
        }

        if (removed < 1 || removed > 3) {
            printf("Veuillez entrer un nombre valide d'allumettes à retirer (1-3).\n");
        } else if (removed > matches) {
            printf("Il n'y a pas assez d'allumettes restantes. Veuillez choisir un nombre inférieur d'allumettes à retirer.\n");
        } else {
            matches -= removed;
            currentPlayer = 3 - currentPlayer; // Alterne entre 1 et 2
        }
    }

    if (currentPlayer == 1) {
        printf("L'ordinateur a retiré la dernière allumette. Vous avez gagné !\n");
    } else {
        printf("Vous avez retiré la dernière allumette. L'ordinateur gagne !\n");
    }

    return 0;
}
