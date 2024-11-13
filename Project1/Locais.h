#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_LOCAL 40

typedef struct Distrito {
	int id;
	char nome[MAX_CHAR_LOCAL];
	struct Distrito* next;
}Distrito;

typedef struct listaDistritos {
	int nElem;
	Distrito* inicio;
}listaDistritos;

Distrito* criarDistrito(int _id, char _nome[MAX_CHAR_LOCAL]);
listaDistritos* criarListaDistrito();
void mostrarDistrito(Distrito* D);
void mostrarListaDistritos(listaDistritos* L);
void freeListaDistritos(listaDistritos* D);

//---------------------------------------------------------------------------------- CONCELHOS

typedef struct Concelho {
	int id;
	char nome[MAX_CHAR_LOCAL];
	struct Concelho* next;
}Concelho;

typedef struct listaConcelhos {
	int nElem;
	Concelho* inicio;
}listaConcelhos;

Concelho* criarConcelho(int _id, char _nome[MAX_CHAR_LOCAL]);
listaConcelhos* criarListaConcelhos();
void mostrarConcelho(Concelho* C);
void mostrarListaConcelhos(listaConcelhos* L);
void freeListaConcelhos(listaConcelhos* D);

//---------------------------------------------------------------------------------- FREGUESIAS

typedef struct Freguesia {
	int id;
	char nome[MAX_CHAR_LOCAL];
	struct Freguesia* next;
}Freguesia;

typedef struct listaFreguesias {
	int nElem;
	Freguesia* inicio;
}listaFreguesias;

Freguesia* criarFreguesia(int _id, char _nome[MAX_CHAR_LOCAL]);
listaFreguesias* criarListaFreguesias();
void mostrarFreguesia(Freguesia* C);
void mostrarListaFreguesias(listaFreguesias* L);
void freeListaFreguesias(listaFreguesias* D);
