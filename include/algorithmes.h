#include "graphe.h"

#ifndef ALGORITHMES_H
#define ALGORITHMES_H

//algo

void ppd(graphe *g);
void visiter_ppd(graphe *g, noeud *u, uint8_t *date);
graphe inverser(graphe *g);

void pp(graphe *g);
void visiter_pp(graphe *g, noeud *u);

void composantes_fort_connexe(graphe *g);

void pl(graphe *);

void ordre_topologique(graphe *g);

void CE_hierholzer(graphe *g);

#endif
