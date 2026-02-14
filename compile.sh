gcc -Wall -I./include -c src/graphe.c -o obj/graphe.o

gcc -Wall -I./include -c src/noeud.c -o obj/noeud.o

gcc -Wall -I./include -c src/algorithmes.c -o obj/alogorithmes.o

gcc -Wall -I./include -c main.c -o obj/main.o

gcc obj/main.o obj/graphe.o obj/noeud.o obj/alogorithmes.o -o out
