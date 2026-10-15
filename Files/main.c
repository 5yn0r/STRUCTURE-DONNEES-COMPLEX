#include <stdio.h>
#include "file.h"

int main()
{
    FILE_T Tete = NULL;
    FILE_T Queue = NULL;
    int choix, valeur, n, i;

    do
    {
        printf("\n============ GESTION D'UNE FILE ============\n");
        printf("1. Verifier si la file est vide\n");
        printf("2. Ajouter un element\n");
        printf("3. Enlever un element\n");
        printf("4. Afficher la file\n");
        printf("5. Compter les elements\n");
        printf("6. Vider completement la file\n");
        printf("0. Quitter\n");
        printf("============================================\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1)
        {
            printf("Saisie invalide !\n");
            while (getchar() != '\n');
            choix = -1;
            continue;
        }

        switch (choix)
        {
            case 1:
                printf("FILE VIDE ? %s\n",
                       vide(Tete) ? "OUI" : "NON");
                break;

            case 2:
                printf("Combien d'elements voulez-vous ajouter ? ");

                if (scanf("%d", &n) != 1)
                {
                    printf("Saisie invalide !\n");
                    while (getchar() != '\n');
                    break;
                }

                if (n <= 0)
                {
                    printf("Le nombre doit etre positif.\n");
                    break;
                }

                for (i = 0; i < n; i++)
                {
                    printf("Valeur de l'element %d : ", i + 1);

                    if (scanf("%d", &valeur) != 1)
                    {
                        printf("Saisie invalide !\n");
                        while (getchar() != '\n');
                        break;
                    }

                    ajouter(&Tete, &Queue, valeur);
                }

                printf("\nFile apres ajout :\n");
                afficher(Tete);
                break;

            case 3:
                if (vide(Tete))
                {
                    printf("Impossible : la file est vide !\n");
                }
                else
                {
                    enlever(&Tete, &Queue, &valeur);

                    printf("ELEMENT ENLEVE : %d\n", valeur);
                    printf("File apres enlevement :\n");
                    afficher(Tete);
                }
                break;

            case 4:
                if (vide(Tete))
                {
                    printf("La file est vide.\n");
                }
                else
                {
                    printf("CONTENU DE LA FILE "
                           "(premier entre -> dernier entre) :\n");
                    afficher(Tete);
                }
                break;

            case 5:
                printf("NOMBRE D'ELEMENTS : %d\n",
                       remplissage(Tete));
                break;

            case 6:
                while (!vide(Tete))
                {
                    enlever(&Tete, &Queue, &valeur);
                }

                printf("La file a ete videe.\n");
                printf("FILE VIDE ? %s\n",
                       vide(Tete) ? "OUI" : "NON");
                break;

            case 0:
                printf("Fermeture du programme...\n");
                break;

            default:
                printf("Choix invalide ! Reessayez.\n");
        }

    } while (choix != 0);

    /* Vidage complet de la file avant de quitter */
    while (!vide(Tete))
    {
        enlever(&Tete, &Queue, &valeur);
    }

    printf("Memoire de la file liberee.\n");

    return 0;
}
