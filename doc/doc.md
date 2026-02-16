# Algorithmes

## PPD - DFS avec Dates

```c
ppd(graphe *g)
```

Affiche chaque nœud avec sa date de **début** et **fin** de visite.

**Sortie:**
```
noeud | début | fin
  0  |   1   |  10
  1  |   2   |   7
```

---

## PP - DFS avec Arborescence

```c
pp(graphe *g)
```

Affiche les **arbres de visite** du DFS.

**Sortie:**
```
Arborescence 1 : 0 1 3 2
Arborescence 2 : 4 5
```

---

## INVERSER - Inverse le Graphe

```c
graphe inverser(graphe *g)
```

Si graphe a arête `0 → 1`, la version inversée a `1 → 0`.

**Retour:** Un nouveau graphe avec toutes les arêtes inversées.

---

## PL - BFS (Parcours en Largeur)

```c
pl(graphe *g)
```

Parcourt le graphe **niveau par niveau** à partir de chaque nœud non visité.

**Sortie:**
```
Composante 1 : 1 2 3 4
Composante 2 : 5 6
```

---

## COMPOSANTES FORTEMENT CONNEXE - Kosaraju

```c
composantes_fort_connexe(graphe *g)
```

Détecte les **composantes fortement connexes** (nœuds qui peuvent s'atteindre mutuellement).

**Étapes:**
1. DFS sur graphe original → dates de fin
2. Trie nœuds par fin décroissante
3. Inverse le graphe
4. DFS sur graphe inverse → composantes

**Sortie:**
```
Composante 1 : 0 1 2
Composante 2 : 3 4 8 7
Composante 3 : 5 6
```

---

## Complexité

| Algo | Temps |
|------|-------|
| PPD | O(V+E) |
| PP | O(V+E) |
| Inverser | O(V+E) |
| PL | O(V+E) |
| Kosaraju | O(V+E) |

---

## À Retenir

- **PPD** = dates de visite
- **PP** = affichage arborescence
- **Inverser** = reverse les flèches
- **PL** = parcours par niveaux
- **Kosaraju** = groupes connexes