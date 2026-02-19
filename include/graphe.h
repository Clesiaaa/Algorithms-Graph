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
void remplir_deg(graphe *g);
void afficher_deg_sommet(graphe *g, uint16_t i);
void afficher_deg(graphe *g);
uint8_t est_eulerien(graphe *g);

graphe graphe_eulerien(void);
graphe graphe_fort_con(void);
#endif
