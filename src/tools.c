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

file creer_file(int taille)
{
    file f;
    f.taille = taille;
    f.data = (int *)malloc(taille * sizeof(int));
    f.debut = 0;
    f.fin = 0;
    return f;
}

void liberer_file(file *f) { free(f->data); }

int file_vide(file *f) {
    if (f->debut == f->fin) return 1;
    return 0;
}

int file_pleine(file *f) {
    if (f->debut == (f->fin + 1) % f->taille) return 1;
    return 0;
}

void insere_file(file *f, int x) {
    if (!file_pleine(f)){
        f->data[f->fin] = x;
        f->fin = (f->fin + 1) % f->taille;
    }
}

int supprime_file(file *f) {
    if (!file_vide(f)) {
        int x = f->data[f->debut];
        f->debut = (f->debut + 1) % f->taille;
        return x;
    }
    return -1;
}