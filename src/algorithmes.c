#include "../include/algorithmes.h"
#include <stdint.h>
#include <stdio.h>

//algo

void visiter_ppd(graphe *g, noeud *u, uint8_t *date)
{
    (*date)++;
    u->debut = *date;
    u->couleur = 1;
    noeud *noeud_actuel = u->suivant;
    while (noeud_actuel != NULL) {
        noeud *noeud_suivant = &g->noeuds[noeud_actuel->val];

        if (noeud_suivant->couleur == 0) {
            visiter_ppd(g, noeud_suivant, date);
        }

        noeud_actuel = noeud_actuel->suivant;
    }

    u->couleur = 2;
    (*date)++;
    u->fin = *date;
}

void ppd(graphe *g)
{
    uint8_t date = 0x00;

    for (uint16_t nd = 0x00; nd < g->v; nd++) {
        noeud *noeud_actuel = &g->noeuds[nd];

        if (noeud_actuel->couleur == 0) {
            visiter_ppd(g, noeud_actuel, &date);
        }
    }

    printf("\nparcours en profondeur date\n");
    printf("noeud | début | fin\n");
    for (uint16_t k = 0x00; k < g->v; k++) {
        noeud *noeud_actuel = &g->noeuds[k];
        printf("  %2d | %5d | %3d\n", noeud_actuel->val, noeud_actuel->debut, noeud_actuel->fin);
    }
}

graphe inverser(graphe *g)
{
    graphe inv_g = creer_graphe(g->v);

    for (uint16_t i = 0x00; i < g->v; i++){

        uint8_t est_present = 0;
        noeud *noeud_est_present = &g->noeuds[i];
        noeud *noeud_actuel = &g->noeuds[i];

        while (noeud_est_present != NULL){
            if (noeud_est_present->val == i){
                est_present = 1;
                break;
            }
            noeud_est_present = noeud_est_present->suivant;
        }

        if (est_present == 1){
            while(noeud_actuel != NULL){
                if (noeud_actuel->val != i){
                    ajouter_arete(&inv_g, noeud_actuel->val, i);
                    noeud_actuel = noeud_actuel->suivant;
                } else {
                    noeud_actuel = noeud_actuel->suivant;
                }
            }

        }
    }
    return inv_g;
}

void visiter_pp(graphe *g, noeud *u)
{
    u->marquer = 1;
    printf("%d ", u->val);
    
    noeud *noeud_actuel = u->suivant;
    while (noeud_actuel != NULL) {
        
        noeud *suivant_reel = &g->noeuds[noeud_actuel->val];
        
        if (suivant_reel->marquer == 0) {
            visiter_pp(g, suivant_reel);
        }
        
        noeud_actuel = noeud_actuel->suivant;
    }
}

void pp(graphe *g)
{    
    uint8_t composante = 1;
    for (uint16_t i = 0x00; i < g->v; i++) {
        noeud *noeud_actuel = &g->noeuds[i];
        
        if (noeud_actuel->marquer == 0) {
            printf("Arborescence %d : ", composante);
            visiter_pp(g, noeud_actuel);
            printf("\n");
            composante++;
        }
    }
}

void composantes_fort_connexe(graphe *g){

    ppd(g);

    noeud *ordre = (noeud *)malloc(g->v * sizeof(noeud));

    for (uint16_t j = 0x00; j < g->v; j++){
        ordre[j] = g->noeuds[j];
    }

    for (uint16_t u = 0x00; u < g->v - 1; u++){
        for (uint16_t v = 0x00; v < g->v - 1; v++){

            if (ordre[v].fin < ordre[v + 1].fin){

                noeud temp = ordre[v];
                ordre[v] = ordre[v + 1];
                ordre[v + 1] = temp;
            }
        }
    }

    graphe inv_g = inverser(g);

    uint8_t composante = 1;

    printf("\n==== Composantes Fortement Connexe ====\n");

    for (uint16_t i = 0x00; i < g->v; i++) {
        uint16_t noeud_id = ordre[i].val;
        
        if (inv_g.noeuds[noeud_id].marquer == 0) {
            printf("Composante %d : ", composante);
            visiter_pp(&inv_g, &inv_g.noeuds[noeud_id]);
            printf("\n");
            composante++;
        }
    }
    free(ordre);
    liberer_graphe(&inv_g);
}

void pl(graphe *g)
{
    printf("=== Parcours en Largeur (BFS) ===\n\n");
    
    uint16_t *queue = (uint16_t *)malloc(g->v * sizeof(uint16_t));
    uint16_t debut = 0; 
    uint16_t fin = 0;   
    
    for (uint16_t k = 0; k < g->v; k++) {
        noeud *noeud_actuel = &g->noeuds[k];
        
        if (noeud_actuel->marquer == 0) {
            printf("Composante %d : ", k + 1);
            
            queue[fin] = k;
            fin++;
            noeud_actuel->marquer = 1;
            
            while (debut < fin) {
                uint16_t noeud_id = queue[debut];
                debut++;
                
                noeud *noeud_traiter = &g->noeuds[noeud_id];
                printf("%d ", noeud_traiter->val + 1);
                
                noeud *noeud_successeur = noeud_traiter->suivant;
                while (noeud_successeur != NULL) {
                    uint16_t succ_id = noeud_successeur->val;
                    noeud *succ = &g->noeuds[succ_id];
                    
                    if (succ->marquer == 0) {
                        succ->marquer = 1;
                        queue[fin] = succ_id;
                        fin++;
                    }
                    
                    noeud_successeur = noeud_successeur->suivant;
                }
            }
            
            printf("\n");
        }
    }
    
    free(queue);
}