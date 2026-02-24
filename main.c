#include <stdio.h>
#include "include/graphe.h"
#include "include/noeud.h"
#include "include/algorithmes.h"
#include "include/tools.h"

//main

int main()
{   
    graphe G = graphe_eulerien();
    
    afficher_graphe(&G);
    
    /* Copier
    graphe H = copier(&G);
    afficher_graphe(&H);

    Inverser
    graphe V = inverser(&G);
    afficher_graphe(&V);
    */

    //Composantes Fortements Connexe
    graphe K = graphe_fort_con();
    composantes_fort_connexe(&K);
    printf("\n");

    //Ordre Topologique
    ordre_topologique(&K);
    printf("\n");

    //Circuit Eulérien;
    remplir_deg(&G);
    afficher_deg(&G);
    printf("\n");
    hierholzer(&G);
    printf("\n");

    //Parcours en Profondeur
    pp(&K);

    //Parcours en Largeur
    pl(&K);

    liberer_graphe(&G);
    //liberer_graphe(&H);
    liberer_graphe(&K);
    return 0;
}