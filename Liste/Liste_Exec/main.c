#include <stdio.h>
#include "liste.h"

int main()
{
    LISTE L = NULL;

    printf("LISTE VIDE ? %s\n\n", vide(L) ? "OUI" : "NON");

    printf("INSERTION EN TETE DE 10, 3, 2 :\n\n");
    L = inserer_en_tete(10, L);
    L = inserer_en_tete(3, L);
    L = inserer_en_tete(2, L);

    printf("AFFICHAGE DE LA LISTE :\n");
    afficher_liste(L);

    printf("\nINSERTION EN QUEUE DE 14 :\n\n");
    L = inserer_en_queue(14, L);
    afficher_liste(L);

    printf("\nNOMBRE D'ELEMENTS DANS LA LISTE : %d\n\n", remplissage(L));

    printf("SUPPRESSION EN TETE :\n");
    L = supprimer_tete(L);
    afficher_liste(L);

    printf("\nSUPPRESSION EN QUEUE :\n");
    L = supprimer_en_queue(L);
    afficher_liste(L);

    printf("\nNOMBRE D'ELEMENTS DANS LA LISTE : %d\n\n", remplissage(L));

    printf("SUPPRESSION DE TOUTE LA LISTE :\n");
    L = supprimer_liste(L);
    afficher_liste(L);

    printf("\nLISTE VIDE APRES SUPPRESSION ? %s\n", vide(L) ? "OUI" : "NON");

    return 0;
}
