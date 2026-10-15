#ifndef FILE_H
#define FILE_H

/* Définition de la structure d'une cellule de la file */
struct CELLULE
{
    int info;
    struct CELLULE *suivant;
};
typedef struct CELLULE *FILE_T;

/* Teste si la file est vide */
int vide(FILE_T Tete);

/* Ajoute un élément à la queue de la file */
void ajouter(FILE_T *Tete, FILE_T *Queue, int Element);

/* Enlève l'élément de tête de la file et le renvoie dans Valeur */
void enlever(FILE_T *Tete, FILE_T *Queue, int *Valeur);

/* Compte le nombre d'éléments de la file */
int remplissage(FILE_T Tete);

/* Affiche les éléments de la file, du premier entré au dernier entré */
void afficher(FILE_T Tete);

#endif
