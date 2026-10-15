#include <stdio.h>
#include "arbre.h"

int main()
{
    ARBRE Racine, n3, n5, n6, n8, n12, n13, n21, n25, n28;

    /* Sous-arbre autour de 8 */
    n6 = nouveauNoeud(6);
    n8 = enracinement(n6, NULL, 8);

    /* Sous-arbre autour de 12 */
    n13 = nouveauNoeud(13);
    n12 = enracinement(n8, n13, 12);

    /* Sous-arbre autour de 5 */
    n3 = nouveauNoeud(3);
    n5 = enracinement(n3, n12, 5);

    /* Sous-arbre autour de 25 */
    n21 = nouveauNoeud(21);
    n28 = nouveauNoeud(28);
    n25 = enracinement(n21, n28, 25);

    /* Racine */
    Racine = enracinement(n5, n25, 20);

    printf("PARCOURS PREFIXE  : ");
    parcours_prefixe(Racine);
    printf("\n");

    printf("PARCOURS INFIXE   : ");
    parcours_infixe(Racine);
    printf("\n");

    printf("PARCOURS POSTFIXE : ");
    parcours_postfixe(Racine);
    printf("\n");

    return 0;
}
