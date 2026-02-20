# Variables
CC = gcc
CFLAGS = -Wall -I./include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = .

# Cibles (fichiers objets)
SOURCES = $(SRC_DIR)/graphe.c $(SRC_DIR)/noeud.c $(SRC_DIR)/algorithmes.c $(SRC_DIR)/tools.c main.c
OBJECTS = $(OBJ_DIR)/graphe.o $(OBJ_DIR)/noeud.o $(OBJ_DIR)/algorithmes.o $(OBJ_DIR)/tools.o $(OBJ_DIR)/main.o
EXECUTABLE = out

# Règles
.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(EXECUTABLE)

help:
	@echo "Commandes disponibles:"
	@echo "  make        : Compile le projet"
	@echo "  make clean  : Supprime les fichiers générés"
	@echo "  make help   : Affiche ce message"