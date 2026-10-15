
#include <stdio.h>
#include "liste.h"

int main()
{
    LISTE L = NULL;
    int choix, valeur, n, i;

    do
    {
        printf("\n========== GESTION D'UNE LISTE ==========\n");
        printf("1. Verifier si la liste est vide\n");
        printf("2. Inserer en tete\n");
        printf("3. Inserer en queue\n");
        printf("4. Supprimer en tete\n");
        printf("5. Supprimer en queue\n");
        printf("6. Afficher la liste\n");
        printf("7. Compter les elements\n");
        printf("8. Supprimer toute la liste\n");
        printf("0. Quitter\n");
        printf("=========================================\n");
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
                printf("LISTE VIDE : %s\n",
                       vide(L) ? "OUI" : "NON");
                break;

            case 2:
                printf("Combien d'elements voulez-vous inserer ? ");

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

                    L = inserer_en_tete(valeur, L);
                }

                printf("\nListe apres insertion en tete :\n");
                afficher_liste(L);
                break;

            case 3:
                printf("Combien d'elements voulez-vous inserer ? ");

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

                    L = inserer_en_queue(valeur, L);
                }

                printf("\nListe apres insertion en queue :\n");
                afficher_liste(L);
                break;

            case 4:
                if (vide(L))
                {
                    printf("Impossible : la liste est vide !\n");
                }
                else
                {
                    L = supprimer_tete(L);
                    printf("Liste apres suppression en tete :\n");
                    afficher_liste(L);
                }
                break;

            case 5:
                if (vide(L))
                {
                    printf("Impossible : la liste est vide !\n");
                }
                else
                {
                    L = supprimer_en_queue(L);
                    printf("Liste apres suppression en queue :\n");
                    afficher_liste(L);
                }
                break;

            case 6:
                if (vide(L))
                {
                    printf("La liste est vide.\n");
                }
                else
                {
                    printf("CONTENU DE LA LISTE :\n");
                    afficher_liste(L);
                }
                break;

            case 7:
                printf("NOMBRE D'ELEMENTS : %d\n",
                       remplissage(L));
                break;

            case 8:
                L = supprimer_liste(L);
                printf("Toute la liste a ete supprimee.\n");
                printf("LISTE VIDE : %s\n",
                       vide(L) ? "OUI" : "NON");
                break;

            case 0:
                printf("Fermeture du programme...\n");
                break;

            default:
                printf("Choix invalide ! Reessayez.\n");
        }

    } while (choix != 0);

    /* Liberation de la memoire avant de quitter */
    L = supprimer_liste(L);

    printf("Memoire de la liste liberee.\n");

    return 0;
}
