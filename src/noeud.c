#include <stdint.h>
#include <stdio.h>
#include "../include/noeud.h"

//graphe

noeud creer_noeud(uint16_t val)
{
    noeud n;
    n.val = val;
    n.couleur = 0;
    n.debut = 0;
    n.fin = 0;
    n.marquer = 0;
    n.suivant = NULL;
    return n;
}
