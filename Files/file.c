#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/*******************************************
 * Teste si la file est vide               *
 *******************************************/
int vide(FILE_T Tete)
{
    return (Tete == NULL);
}

/*******************************************
 * Ajoute un élément à la queue de la file *
 * Tete et Queue sont modifiés via leurs   *
 * adresses (pointeurs sur pointeurs)      *
 *******************************************/
void ajouter(FILE_T *Tete, FILE_T *Queue, int Element)
{
    FILE_T L;
    L = (FILE_T)malloc(sizeof(struct CELLULE));
    L->info = Element;
    L->suivant = NULL;

    if (vide(*Tete))
    {
        *Tete = L;
    }
    else
    {
        (*Queue)->suivant = L;
    }
    *Queue = L;
}

/*******************************************
 * Enlève l'élément de tête de la file     *
 * et renvoie sa valeur dans *Valeur       *
 *******************************************/
void enlever(FILE_T *Tete, FILE_T *Queue, int *Valeur)
{
    FILE_T tmp;
    if (!vide(*Tete))
    {
        *Valeur = (*Tete)->info;
        tmp = *Tete;
        *Tete = (*Tete)->suivant;
        free(tmp);
        if (vide(*Tete))
        {
            *Queue = NULL;
        }
    }
}

/*******************************************
 * Compte le nombre d'éléments de la file  *
 *******************************************/
int remplissage(FILE_T Tete)
{
    FILE_T tmp = Tete;
    int compteur = 0;
    while (!vide(tmp))
    {
        compteur++;
        tmp = tmp->suivant;
    }
    return compteur;
}

/*******************************************
 * Affiche les éléments, du premier entré  *
 * (Tete) au dernier entré (Queue)         *
 *******************************************/
void afficher(FILE_T Tete)
{
    FILE_T tmp = Tete;
    while (!vide(tmp))
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}
