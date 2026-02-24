#include "../include/algorithmes.h"
#include "../include/graphe.h"
#include "../include/tools.h"
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

    printf("\n====== Parcours en Profondeur Date ======\n");
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
    printf("==== Parcours en Profondeur ====\n");
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
    demarquer_tout(g);
    file f = creer_file(g->v);
    
    noeud *racine = &g->noeuds[0];
    insere_file(&f, racine->val);
    marquer(racine);
    
    printf("\n==== Parcours en Largeur ====\n");
    
    while (!file_vide(&f)) {
        uint16_t s = supprime_file(&f);
        printf("%d ", s);
        
        noeud *noeud_voisin = g->noeuds[s].suivant;
        
        while (noeud_voisin != NULL) {
            uint16_t voisin_id = noeud_voisin->val; 
            
            if (g->noeuds[voisin_id].marquer == 0) {
                insere_file(&f, voisin_id);
                marquer(&g->noeuds[voisin_id]);
            }
            
            noeud_voisin = noeud_voisin->suivant;
        }
    }
    
    liberer_file(&f);
    printf("\n");
}

void ordre_topologique(graphe *g) {
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

    printf("===== Ordre Topologique =====\n");
    for(uint16_t k = 0x00; k < g->v; k++) {
        printf("%d ", ordre[k].val);
    }
    printf("\n");
}

void hierholzer(graphe *g)
{
    printf("=== Circuit Eulérien ===\n");
    
    if (!est_eulerien(g)) {
        printf("Le graphe n'est pas eulérien\n");
        return; 
    }

    uint16_t somme_deg = 0;
    for (uint16_t j = 0; j < g->v; j++) {
        somme_deg += g->noeuds[j].deg_out;
    }

    
    uint16_t *circuit = (uint16_t *)malloc((somme_deg + 1) * sizeof(uint16_t));
    uint16_t idx_circuit = 0;
    
    graphe g_temp = creer_graphe(g->v);
    for (uint16_t i = 0; i < g->v; i++) {
        g_temp.noeuds[i].deg_out = g->noeuds[i].deg_out;
        noeud *current = g->noeuds[i].suivant;
        while (current != NULL) {
            ajouter_arete(&g_temp, i, current->val);
            current = current->suivant;
        }
    }
    
    pile p = creer_pile(somme_deg + g->v);
    
    uint16_t v = 0;
    empiler(&p, v);
    
    while (!pile_vide(&p)) {

        v = p.data[p.sommet - 1];
        noeud *noeud_actuel = &g_temp.noeuds[v];
        
        if (noeud_actuel->suivant != NULL) {
            noeud *noeud_voisin = noeud_actuel->suivant;
            uint16_t w = noeud_voisin->val;
            
            noeud *temp = noeud_actuel->suivant;
            noeud_actuel->suivant = temp->suivant;
            free(temp);
            noeud_actuel->deg_out--;
            
            empiler(&p, w);
        } else {
            depiler(&p);
            circuit[idx_circuit] = v;
            idx_circuit++;
        }
    }
    
    // Affichage
    printf("Circuit trouvé avec %d nœuds:\n", idx_circuit);
    for (uint16_t k = idx_circuit - 1; k > 0; k--) {
        printf("%d -> ", circuit[k]);
    }
    printf("%d\n", circuit[0]);
    
    liberer_pile(&p);
    free(circuit);
    liberer_graphe(&g_temp);
}