<div align="center"> <image src="GraphLib.PNG" alt="Description"> </div>

# GraphLib

Bibliothèque C pour manipuler des graphes orientés avec algorithmes.

## Installation

```bash
make
```

## Fonctions

| Fonction | Description |
|----------|-------------|
| `creer_graphe(v)` | Crée un graphe avec v nœuds |
| `ajouter_arete(g, src, dst)` | Ajoute une arête |
| `afficher_graphe(g)` | Affiche la liste d'adjacence |
| `inverser(g)` | Inverse toutes les arêtes |
| `ppd(g)` | DFS avec dates de visite |
| `pp(g)` | DFS avec affichage arborescence |
| `pl(g)` | BFS (parcours largeur) |
| `composantes_fort_connexe(g)` | Détecte composantes fortement connexes |
| `ordre_topologique(g)` | Ordre Topologique |
| `hierholzer(g)` | Circuit Eulerien |
| `liberer_graphe(g)` | Libère la mémoire |

## Exemple

```
graphe G = creer_graphe(5);
ajouter_arete(&G, 0, 1);
ajouter_arete(&G, 1, 2);

afficher_graphe(&G);

composantes_fort_connexe(&G);

liberer_graphe(&G);
```

## Structure

```c
typedef struct noeud {
    uint16_t val;           // ID
    struct noeud *suivant;  // Successeur
    uint8_t couleur;        // 0=blanc, 1=gris, 2=noir
    uint8_t marquer;        // Marquage visité
    uint8_t debut;          // Date début (DFS)
    uint8_t fin;            // Date fin (DFS)
} noeud;

typedef struct {
    uint16_t v;             // Nb nœuds
    noeud *noeuds;          // Tableau nœuds
} graphe;
```

## Points clés

- ⚠️ Noeuds indexés de 0 à v-1
- ⚠️ Toujours appeler `liberer_graphe()`
- ⚠️ Utiliser `uint16_t` pour les dates si >255 nœuds
- ⚠️ Récupérer noeud via `&g->noeuds[id]`, pas via liste

Made with C