#ifndef TOOLS_H
#define TOOLS_H

typedef struct pile
{
    int taille;
    int sommet;
    int *data;
} pile;

typedef struct file
{   
    int taille;
    int *data;
    int debut;
    int fin;
} file;

file creer_file(int taille);
void liberer_file(file *f);
int file_vide(file *f);
int file_pleine(file *f);
void insere_file(file *f, int x);
int supprime_file(file *f);

pile creer_pile(int taille);
void liberer_pile(pile *p);
int depiler(pile *p);
void empiler(pile *p, int x);
int pile_vide(pile *p);

#endif