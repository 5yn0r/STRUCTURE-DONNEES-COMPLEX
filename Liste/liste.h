#ifndef LISTE_H
#define LISTE_H

/* Définition de la structure d'une cellule de la liste */
struct CELLULE
{
    int info;
    struct CELLULE *suivant;
};
typedef struct CELLULE *LISTE;

/* Teste si la liste est vide */
int vide(LISTE L);

/* Insère un élément en tête de liste */
LISTE inserer_en_tete(int Element, LISTE L);

/* Insère un élément en queue de liste */
LISTE inserer_en_queue(int Element, LISTE L);

/* Supprime l'élément en tête de liste */
LISTE supprimer_tete(LISTE L);

/* Supprime l'élément en queue de liste */
LISTE supprimer_en_queue(LISTE L);

/* Supprime toute la liste et libère la mémoire */
LISTE supprimer_liste(LISTE L);

/* Compte le nombre d'éléments de la liste */
int remplissage(LISTE L);

/* Affiche les éléments de la liste, du premier au dernier */
void afficher_liste(LISTE L);

#endif
