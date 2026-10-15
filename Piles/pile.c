#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/*******************************************
 * Teste si la pile est vide               *
 *******************************************/
int vide(PILE P)
{
    return (P == NULL);
}

/*******************************************
 * Empile un élément au sommet de la pile  *
 *******************************************/
PILE empiler(int Element, PILE P)
{
    PILE L;
    L = (PILE)malloc(sizeof(struct CELLULE));
    L->info = Element;
    L->suivant = P;
    return L;
}

/*******************************************
 * Dépile l'élément du sommet de la pile   *
 *******************************************/
PILE depiler(PILE P)
{
    PILE tmp = P;
    if (!vide(P))
    {
        tmp = P->suivant;
        free(P);
    }
    return tmp;
}

/*******************************************
 * Compte le nombre d'éléments de la pile  *
 *******************************************/
int remplissage(PILE P)
{
    PILE tmp = P;
    int compteur = 0;
    while (!vide(tmp))
    {
        compteur++;
        tmp = tmp->suivant;
    }
    return compteur;
}

/*******************************************
 * Affiche les éléments, du sommet         *
 * (dernier entré) au premier entré        *
 *******************************************/
void afficher(PILE P)
{
    PILE tmp = P;
    while (!vide(tmp))
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}
