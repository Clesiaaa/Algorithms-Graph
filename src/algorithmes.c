#include "../include/algorithmes.h"
#include <stdint.h>
#include <stdio.h>

void visiter_pp(graphe *g, noeud *u, uint8_t *date)
{
    (*date)++;
    u->debut = *date;
    u->couleur = 1;
    noeud *noeud_actuel = u->suivant;
    while (noeud_actuel != NULL) {
        noeud *noeud_suivant = &g->noeuds[noeud_actuel->val];

        if (noeud_suivant->couleur == 0) {
            visiter_pp(g, noeud_suivant, date);
        }

        noeud_actuel = noeud_actuel->suivant;
    }

    u->couleur = 2;
    (*date)++;
    u->fin = *date;
}

void pp(graphe *g)
{
    uint8_t date = 0x00;

    for (uint16_t nd = 0x00; nd < g->v; nd++) {
        noeud *noeud_actuel = &g->noeuds[nd];

        if (noeud_actuel->couleur == 0) {
            visiter_pp(g, noeud_actuel, &date);
        }
    }

    printf("\nparcours en profondeur\n");
    printf("noeud | début | fin\n");
    for (uint16_t k = 0x00; k < g->v; k++) {
        noeud *noeud_actuel = &g->noeuds[k];
        printf("  %2d | %5d | %3d\n", noeud_actuel->val, noeud_actuel->debut, noeud_actuel->fin);
    }
}
