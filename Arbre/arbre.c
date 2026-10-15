#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

/*******************************************
 * Teste si l'arbre est vide                *
 *******************************************/
int vide(ARBRE A)
{
    return (A == NULL);
}

/*******************************************
 * Retourne le sous-arbre gauche de A       *
 *******************************************/
ARBRE filsGauche(ARBRE A)
{
    ARBRE res = A;
    if (!vide(res))
    {
        res = res->filsG;
    }
    return res;
}

/*******************************************
 * Retourne le sous-arbre droit de A        *
 *******************************************/
ARBRE filsDroit(ARBRE A)
{
    ARBRE res = A;
    if (!vide(res))
    {
        res = res->filsD;
    }
    return res;
}

/*******************************************
 * Crée un nouveau nœud feuille             *
 *******************************************/
ARBRE nouveauNoeud(int Element)
{
    ARBRE A = (ARBRE)malloc(sizeof(struct NOEUD));
    A->info = Element;
    A->filsG = NULL;
    A->filsD = NULL;
    return A;
}

/*******************************************
 * Crée un nœud raccordé aux sous-arbres    *
 * gauche A et droit B                      *
 *******************************************/
ARBRE enracinement(ARBRE A, ARBRE B, int Element)
{
    ARBRE tmp = (ARBRE)malloc(sizeof(struct NOEUD));
    tmp->info = Element;
    tmp->filsG = A;
    tmp->filsD = B;
    return tmp;
}

/*******************************************
 * Parcours préfixe (racine, gauche, droit) *
 *******************************************/
void parcours_prefixe(ARBRE A)
{
    if (!vide(A))
    {
        printf("%d ", A->info);
        parcours_prefixe(filsGauche(A));
        parcours_prefixe(filsDroit(A));
    }
}

/*******************************************
 * Parcours infixe (gauche, racine, droit)  *
 *******************************************/
void parcours_infixe(ARBRE A)
{
    if (!vide(A))
    {
        parcours_infixe(filsGauche(A));
        printf("%d ", A->info);
        parcours_infixe(filsDroit(A));
    }
}

/*******************************************
 * Parcours postfixe (gauche, droit, racine)*
 *******************************************/
void parcours_postfixe(ARBRE A)
{
    if (!vide(A))
    {
        parcours_postfixe(filsGauche(A));
        parcours_postfixe(filsDroit(A));
        printf("%d ", A->info);
    }
}
