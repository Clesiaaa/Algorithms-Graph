#include "include/graphe.h"
#include "include/noeud.h"
#include "include/algorithmes.h"

//main

int main()
{
    graphe G = graphe_fort_con();

    afficher_graphe(&G);

    pp(&G);

    liberer_graphe(&G);
    return 0;
}
