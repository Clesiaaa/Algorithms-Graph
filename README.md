# 📊 LibGraphes en C

## 🎯 Description
Implémentation de **graphes orientés** avec algorithmes de parcours en profondeur et détection de composantes fortement connexes.

## 🚀 Compilation
```bash
./compile.sh
./out
```

## 📂 Structure
```
├── graphe.h/c       📈 Gestion des graphes
├── noeud.h/c        🔵 Gestion des nœuds
├── algorithmes.h/c  🔍 Algorithmes (DFS, inversion)
└── main.c           ⚙️ Programme principal
```

## 🛠️ Fonctions principales
| Fonction | Description |
|----------|-------------|
| `creer_graphe(v)` | 🆕 Crée un graphe avec v nœuds |
| `ajouter_arete(g, src, dst)` | ➕ Ajoute une arête |
| `afficher_graphe(g)` | 👁️ Affiche la liste d'adjacence |
| `inverser(g)` | 🔄 Inverse toutes les arêtes |
| `ppd(g)` | 📍 DFS avec dates de début & fin  |
| `pp(g)` | 🔍 DFS avec arborescence |
| `liberer_graphe(g)` | 🗑️ Libère la mémoire |
| `composantes_fort_connexe(g)` | ⚙️ Détermine les composantes fortement connexe|
| `pl(g)` | 🔄 BFS avec suite de sommets|

## 💡 Exemple
```c
graphe G = creer_graphe(5);
ajouter_arete(&G, 0, 1);
ajouter_arete(&G, 1, 2);
afficher_graphe(&G);      // Affiche structure
liberer_graphe(&G);
```

## 📊 Structures de données
```c
typedef struct noeud {
    uint16_t val;           // ID du nœud
    struct noeud *suivant;  // Pointeur vers prochain successeur
    uint8_t couleur;        // 0=blanc, 1=gris, 2=noir
    uint8_t marquer;        // 0=non visité, 1=visité
    uint8_t debut;          // Date début visite
    uint8_t fin;            // Date fin visite
} noeud;

typedef struct {
    uint16_t v;             // Nombre de nœuds
    noeud *noeuds;          // Tableau de nœuds
} graphe;
```

## ⚡ Algorithmes
- **DFS** 🔍: O(V + E) - Parcours en profondeur
- **Inversion** 🔄: O(V + E) - Inverse toutes les arêtes
- **Kosaraju** 🏆: O(V + E) - Composantes fortement connexes

## ⚠️ Points clés
- ✅ Toujours libérer avec `liberer_graphe()`
- ✅ Vérifier que les nœuds existent avant d'ajouter une arête
- ✅ Utiliser `uint16_t` pour les dates (pas `uint8_t`)
- ✅ Récupérer le vrai nœud via `&g->noeuds[id]`

## 🐛 Débogage courant
| Erreur | Cause | Solution |
|--------|-------|----------|
| 💥 SEGFAULT | Nœud inexistant | Vérifier `creer_graphe(n)` |
| 📉 Dates bizarres | `uint8_t` déborde | Utiliser `uint16_t` |
| 🔗 Mauvaises arêtes | Accès liste chaînée mal | Utiliser `&g->noeuds[id]` |

## 📝 Exemple sortie
```
Graphe original:
0 : [1, 2]
1 : [3]
2 : [3]
3 : [4]

Composantes fortement connexes:
Composante 1 : 0 1 2 3 4
```

---
**Made with ❤️ in C** | *Complexité: O(V + E)* 🚀