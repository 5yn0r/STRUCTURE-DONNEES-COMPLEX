#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/*******************************************
 * Teste si la liste est vide              *
 *******************************************/
int vide(LISTE L)
{
    return (L == NULL);
}

/*******************************************
 * Insère un élément en tête de liste      *
 *******************************************/
LISTE inserer_en_tete(int Element, LISTE L)
{
    LISTE P;
    P = (LISTE)malloc(sizeof(struct CELLULE));
    P->info = Element;
    P->suivant = L;
    return P;
}

/*******************************************
 * Insère un élément en queue de liste     *
 *******************************************/
LISTE inserer_en_queue(int Element, LISTE L)
{
    LISTE P, tmp;
    P = (LISTE)malloc(sizeof(struct CELLULE));
    P->info = Element;
    P->suivant = NULL;

    if (vide(L))
    {
        return P;
    }
    else
    {
        tmp = L;
        while (tmp->suivant != NULL)
        {
            tmp = tmp->suivant;
        }
        tmp->suivant = P;
        return L;
    }
}

/*******************************************
 * Supprime l'élément en tête de liste     *
 *******************************************/
LISTE supprimer_tete(LISTE L)
{
    LISTE tmp = L;
    if (!vide(L))
    {
        tmp = L->suivant;
        free(L);
    }
    return tmp;
}

/*******************************************
 * Supprime l'élément en queue de liste    *
 *******************************************/
LISTE supprimer_en_queue(LISTE L)
{
    LISTE tmp, prec;

    if (vide(L))
    {
        return NULL;
    }
    else if (L->suivant == NULL) /* un seul élément */
    {
        free(L);
        return NULL;
    }
    else
    {
        tmp = L;
        prec = L;
        while (tmp->suivant != NULL)
        {
            prec = tmp;
            tmp = tmp->suivant;
        }
        free(tmp);
        prec->suivant = NULL;
        return L;
    }
}

/*******************************************
 * Supprime toute la liste                 *
 *******************************************/
LISTE supprimer_liste(LISTE L)
{
    while (!vide(L))
    {
        L = supprimer_tete(L);
    }
    return L;
}

/*******************************************
 * Compte le nombre d'éléments de la liste *
 *******************************************/
int remplissage(LISTE L)
{
    LISTE tmp = L;
    int compteur = 0;
    while (!vide(tmp))
    {
        compteur++;
        tmp = tmp->suivant;
    }
    return compteur;
}

/*******************************************
 * Affiche les éléments, du premier        *
 * au dernier élément                      *
 *******************************************/
void afficher_liste(LISTE L)
{
    LISTE tmp = L;
    while (!vide(tmp))
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}
