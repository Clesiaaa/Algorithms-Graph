#include <stdlib.h>
#include "noeud.h"

#ifndef GRAPHE_H
#define GRAPHE_H

//graphe

typedef struct graphe {
    uint16_t v;
    noeud *noeuds;
} graphe;

graphe creer_graphe(uint16_t v);
void liberer_graphe(graphe *g);
void ajouter_noeud(graphe *g, noeud *n, uint16_t s);
void afficher_graphe(graphe *g);
void ajouter_arete(graphe *g, uint16_t source, uint16_t dest);

graphe graphe_fort_con(void);
#endif
