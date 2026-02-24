#include "include/graphe.h"
#include "include/noeud.h"
#include "include/algorithmes.h"
#include "include/tools.h"

//main

int main()
{
    graphe G = graphe_eulerien();
    
    afficher_graphe(&G);

    graphe H = copier(&G);

    afficher_graphe(&H);

    liberer_graphe(&G);
    liberer_graphe(&H);
    
    return 0;
}