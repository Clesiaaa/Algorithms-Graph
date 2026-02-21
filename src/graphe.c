#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/graphe.h"
#include "../include/noeud.h"

//graphe

graphe creer_graphe(uint16_t v)
{
    graphe g;
    g.v = v;
    g.noeuds = (noeud *)malloc(v * sizeof(noeud));

    for (uint16_t i = 0; i < v; i++) {
        g.noeuds[i] = creer_noeud(i);
    }
    return g;
};

void liberer_graphe(graphe *g)
{
    for (uint16_t i = 0; i < g->v; i++){
        noeud *current = g->noeuds[i].suivant;
        while (current != NULL) {
            noeud *temp = current;
            current = current->suivant;
            free(temp);
        }
    }
    free(g->noeuds);
}

void ajouter_noeud(graphe *g, noeud *n, uint16_t s)
{
    noeud *noeud_actuel = &g->noeuds[s];
    while (noeud_actuel->suivant != NULL)
    {
        noeud_actuel = noeud_actuel->suivant;
    }
    noeud_actuel->suivant = n;
}

void afficher_graphe(graphe *g)
{
    printf("Graphe ==================\n");
    for (uint16_t i = 0; i < g->v; i++)
    {
        printf("%d : [", i);
        noeud *noeud_actuel = g->noeuds[i].suivant;
        while (noeud_actuel != NULL)
        {
            printf("%d", noeud_actuel->val);
            noeud_actuel = noeud_actuel->suivant;
            if (noeud_actuel != NULL)
                printf(", ");
        }
        printf("]\n");
    }
}

void ajouter_arete(graphe *g, uint16_t source, uint16_t dest)
{
    noeud *nouveau = (noeud *)malloc(sizeof(noeud));
    *nouveau = creer_noeud(dest);
    ajouter_noeud(g, nouveau, source);
}

void remplir_deg(graphe *g)
{
    //deg_out
    for (uint16_t i = 0x00; i < g->v; i++) {
        noeud *noeud_actuel = &g->noeuds[i];
        
        while (noeud_actuel->suivant != NULL) {
            g->noeuds[i].deg_out++;
            noeud_actuel = noeud_actuel->suivant;
        }
    }

    //deg_in
    for (uint16_t j = 0x00; j < g->v; j++) {
        for (uint16_t k = 0x00; k < g->v; k++) {
            
            noeud *noeud_actuel = &g->noeuds[k];
            noeud_actuel = noeud_actuel->suivant;
            
            while (noeud_actuel != NULL) {
                if (noeud_actuel->val == j) {
                    g->noeuds[j].deg_in++;
                }
                noeud_actuel = noeud_actuel->suivant;
            }
        }
    } 
}

uint8_t est_eulerien(graphe *g) {

    for (uint16_t i = 0x00; i < g->v; i++) {
        noeud *noeud_actuel = &g->noeuds[i];
        if (noeud_actuel->deg_in != noeud_actuel->deg_out) {
            //printf("Non Eulerien\n");
            return 0;
        }
    }
    //printf("Eulerien\n");
    return 1;
}

void afficher_deg_sommet(graphe *g, uint16_t i) {
    printf("%d | %d | %d\n", i, g->noeuds[i].deg_out, g->noeuds[i].deg_in);
}

void afficher_deg(graphe *g) {
    printf("Noeuds | Successeurs | Predecesseurs\n");
    for (uint16_t i = 0x00; i < g->v; i++) {
        afficher_deg_sommet(g, i);
    }
}

graphe graphe_fort_con(void)
{
    graphe g = creer_graphe(10);

    ajouter_arete(&g, 0, 1);

    ajouter_arete(&g, 1, 2);
    ajouter_arete(&g, 1, 6);
    ajouter_arete(&g, 1, 0);

    ajouter_arete(&g, 2, 3);

    ajouter_arete(&g, 3, 4);
    ajouter_arete(&g, 3, 7);

    ajouter_arete(&g, 4, 3);

    ajouter_arete(&g, 5, 6);
    ajouter_arete(&g, 5, 0);
    ajouter_arete(&g, 5, 9);

    ajouter_arete(&g, 6, 5);

    ajouter_arete(&g, 7, 8);

    ajouter_arete(&g, 8, 7);
    ajouter_arete(&g, 8, 4);

    ajouter_arete(&g, 9, 7);

    return g;
}

graphe graphe_eulerien(void)
{
    graphe g = creer_graphe(8);

    ajouter_arete(&g, 0, 1);
    ajouter_arete(&g, 0, 2);
    ajouter_arete(&g, 0, 4);

    ajouter_arete(&g, 1, 0);
    ajouter_arete(&g, 1, 5);
    ajouter_arete(&g, 1, 7);

    ajouter_arete(&g, 2, 3);

    ajouter_arete(&g, 3, 1);
    ajouter_arete(&g, 3, 5);

    ajouter_arete(&g, 4, 1);
    ajouter_arete(&g, 4, 6);

    ajouter_arete(&g, 5, 4);
    ajouter_arete(&g, 5, 7);

    ajouter_arete(&g, 6, 0);

    ajouter_arete(&g, 7, 0);
    ajouter_arete(&g, 7, 3);

    return g;
}