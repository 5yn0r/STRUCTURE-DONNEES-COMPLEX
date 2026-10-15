#include <stdio.h>
#include "pile.h"

int main()
{
    PILE P = NULL;
    int choix, valeur, n, i;

    do
    {
        printf("\n========== GESTION D'UNE PILE ==========\n");
        printf("1. Verifier si la pile est vide\n");
        printf("2. Empiler un element\n");
        printf("3. Depiler un element\n");
        printf("4. Afficher la pile\n");
        printf("5. Compter les elements\n");
        printf("6. Vider completement la pile\n");
        printf("0. Quitter\n");
        printf("========================================\n");
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
                printf("PILE VIDE ? %s\n",
                       vide(P) ? "OUI" : "NON");
                break;

            case 2:
                printf("Combien d'elements voulez-vous empiler ? ");
                if (scanf("%d", &n) != 1)
                {
                    printf("Saisie invalide !\n");
                    while (getchar() != '\n');
                    break;
                }

                if (n < 1)
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

                    P = empiler(valeur, P);
                }

                printf("\nPile apres empilage :\n");
                afficher(P);
                break;

            case 3:
                if (vide(P))
                {
                    printf("Impossible : la pile est vide !\n");
                }
                else
                {
                    printf("Depilement d'un element...\n");
                    P = depiler(P);
                    printf("Pile apres depilement :\n");
                    afficher(P);
                }
                break;

            case 4:
                if (vide(P))
                {
                    printf("La pile est vide.\n");
                }
                else
                {
                    printf("PILE (sommet -> base) :\n");
                    afficher(P);
                }
                break;

            case 5:
                printf("NOMBRE D'ELEMENTS : %d\n",
                       remplissage(P));
                break;

            case 6:
                while (!vide(P))
                {
                    P = depiler(P);
                }

                printf("La pile a ete videe.\n");
                break;

            case 0:
                printf("Fermeture du programme...\n");
                break;

            default:
                printf("Choix invalide ! Reessayez.\n");
        }

    } while (choix != 0);

    /* Liberation de la pile avant de quitter */
    while (!vide(P))
    {
        P = depiler(P);
    }

    printf("Memoire de la pile liberee.\n");

    return 0;
}
