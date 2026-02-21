#include <stdio.h>
#include <stdlib.h>
#include "../include/tools.h"

pile creer_pile(int taille) { 
    pile p;
    p.taille = taille;
    p.sommet = 0;
    p.data = (int *)malloc(taille * sizeof(int));
    return p;
}

void liberer_pile(pile *p) {
    free(p->data);
}

int depiler(pile *p) {
    if (p->sommet == 0) return -1;
    p->sommet--;
    return p->data[p->sommet];
}

void empiler(pile *p, int x) {
    if (p->sommet >= p->taille) return;
    p->data[p->sommet] = x;
    p->sommet++;
}

int pile_vide(pile *p) {
    if (p->sommet == 0) return 1;
    return 0;
}