#include <stdint.h>

#ifndef NOEUD_H
#define NOEUD_H

//noeud

typedef struct noeud {
    uint16_t val;
    uint8_t couleur;
    uint8_t debut;
    uint8_t fin;
    uint8_t marquer;
    struct noeud *suivant;
} noeud;

noeud creer_noeud(uint16_t val);

#endif
