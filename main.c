#include "include/graphe.h"
#include "include/noeud.h"
#include "include/algorithmes.h"

//main

int main()
{
    graphe G = graphe_eulerien();
    graphe H = graphe_fort_con();

    afficher_graphe(&G);
    
    //composantes_fort_connexe(&G);
    
    remplir_deg(&G);
    afficher_deg(&G);
    est_eulerien(&G);

    remplir_deg(&H);
    afficher_deg(&H);
    est_eulerien(&H);

    ordre_topologique(&H);

    liberer_graphe(&H);
    liberer_graphe(&G);

    return 0;
}