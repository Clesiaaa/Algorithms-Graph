#ifndef TOOLS_H
#define TOOLS_H

typedef struct pile
{
    int taille;
    int sommet;
    int *data;
} pile;

pile creer_pile(int taille);
void liberer_pile(pile *p);
int depiler(pile *p);
void empiler(pile *p, int x);

#endif