#include "include/graphe.h"
#include "include/noeud.h"
#include "include/algorithmes.h"
#include "include/tools.h"

//main

int main()
{
    graphe G = graphe_eulerien();
    
    afficher_graphe(&G);
    pl(&G);
    liberer_graphe(&G);

    return 0;
}