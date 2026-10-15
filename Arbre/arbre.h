#ifndef ARBRE_H
#define ARBRE_H

/* Définition de la structure d'un nœud de l'arbre binaire */
struct NOEUD
{
    int info;
    struct NOEUD *filsG;
    struct NOEUD *filsD;
};
typedef struct NOEUD *ARBRE;

/* Teste si l'arbre (le sous-arbre pointé par A) est vide */
int vide(ARBRE A);

/* Retourne le sous-arbre gauche de A */
ARBRE filsGauche(ARBRE A);

/* Retourne le sous-arbre droit de A */
ARBRE filsDroit(ARBRE A);

/* Crée et retourne un nouveau nœud feuille contenant Element */
ARBRE nouveauNoeud(int Element);

/* Crée un nœud contenant Element, de sous-arbre gauche A et droit B */
ARBRE enracinement(ARBRE A, ARBRE B, int Element);

/* Parcours préfixe : racine, sous-arbre gauche, sous-arbre droit */
void parcours_prefixe(ARBRE A);

/* Parcours infixe : sous-arbre gauche, racine, sous-arbre droit */
void parcours_infixe(ARBRE A);

/* Parcours postfixe : sous-arbre gauche, sous-arbre droit, racine */
void parcours_postfixe(ARBRE A);

#endif
