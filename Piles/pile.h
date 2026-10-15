#ifndef PILE_H
#define PILE_H

/* Définition de la structure d'une cellule de la pile */
struct CELLULE
{
    int info;
    struct CELLULE *suivant;
};
typedef struct CELLULE *PILE;

/* Teste si la pile est vide */
int vide(PILE P);

/* Empile un élément au sommet de la pile */
PILE empiler(int Element, PILE P);

/* Dépile l'élément du sommet de la pile */
PILE depiler(PILE P);

/* Compte le nombre d'éléments de la pile */
int remplissage(PILE P);

/* Affiche les éléments de la pile, du sommet vers la base */
void afficher(PILE P);

#endif
