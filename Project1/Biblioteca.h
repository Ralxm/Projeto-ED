#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100

typedef struct Livro {
	int ISBN;
	char titulo[MAX_CHAR];
	char autor[MAX_CHAR];
	int area;
	int ano_pub;
	struct Livro* next;
}Livro, * bLivro;

typedef struct Area {
	int id;
	char nome[MAX_CHAR];
	int nElem;
	struct Area* next;
	Livro* inicio;
}Area, *bArea;

typedef struct Biblioteca {
	int nElem;
	Area* inicio;
}Biblioteca, * bBliblioteca;

Livro* criarLivro(int _ISBN, char _titulo[MAX_CHAR], char _autor[MAX_CHAR], int _area, int _ano_pub);
void mostrarLivro(Livro* L);
char* traduzirAreaLivro(int n);
void freeLivros(Livro* L);
Area* criarArea(int _id, char _nome[MAX_CHAR]);
void mostrarArea(Area* A);
Biblioteca* criarBiblioteca();
void inserirLivroBiblioteca(Biblioteca* B, Livro* L);
void mostrarBiblioteca(Biblioteca* B);
void freeBiblioteca(Biblioteca* B);