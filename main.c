#include "include/graphe.h"
#include "include/noeud.h"
#include "include/algorithmes.h"

//main

int main()
{
    graphe G = graphe_fort_con();

    afficher_graphe(&G);

    graphe inv_G = inverser(&G);

    afficher_graphe(&inv_G);

    ppd(&G);
    pp(&inv_G);

    liberer_graphe(&G);
    liberer_graphe(&inv_G);
    return 0;
}
