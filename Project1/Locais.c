#include "Locais.h"

Distrito* criarDistrito(int _id, char _nome[40]) {
	Distrito* D = (Distrito*)malloc(sizeof(struct Distrito));
	D->id = _id;
	strcpy(D->nome, _nome);
	D->next = NULL;

	return D;
}

listaDistritos* criarListaDistrito() {
	listaDistritos* L = (listaDistritos*)malloc(sizeof(struct listaDistritos));
	L->nElem = 0;
	L->inicio = NULL;
	
	return L;
}

void mostrarDistrito(Distrito* D) {
	printf("Distrito: \n\t");
	printf("ID: %d\n\t", D->id);
	printf("Nome: %s\n\n", D->nome);
}

void mostrarListaDistritos(listaDistritos* L) {
	Distrito* aux = L->inicio;
	while (aux != NULL) {
		mostrarDistrito(aux);
		aux = aux->next;
	}
}

void freeListaDistritos(listaDistritos* D) {
	Distrito* aux = D->inicio;
	Distrito* next;

	while (aux != NULL) {
		next = aux->next;
		free(aux);
		aux = next;
	}
	free(D);
}

//----------------------------------------------------CONCELHOS---------------------------------------------------------

Concelho* criarConcelho(int _id, char _nome[MAX_CHAR_LOCAL]) {
	Concelho* C = (Concelho*)malloc(sizeof(struct Concelho));
	C->id = _id;
	strcpy(C->nome, _nome);
	C->next = NULL;

	return C;
}

listaConcelhos* criarListaConcelhos() {
	listaConcelhos* L = (listaConcelhos*)malloc(sizeof(struct listaConcelhos));
	L->nElem = 0;
	L->inicio = NULL;

	return L;
}

void mostrarConcelho(Concelho* C) {
	printf("Concelho: \n\t");
	printf("ID: %d\n\t", C->id);
	printf("Nome: %s\n\n", C->nome);
}

void mostrarListaConcelhos(listaConcelhos* L) {
	Concelho* aux = L->inicio;
	while (aux != NULL) {
		mostrarConcelho(aux);
		aux = aux->next;
	}
}

void freeListaConcelhos(listaConcelhos* C) {
	Concelho* aux = C->inicio;
	Concelho* next;

	while (aux != NULL) {
		next = aux->next;
		free(aux);
		aux = next;
	}
	free(C);
}

//----------------------------------------------------FREGUESIAS---------------------------------------------------------

Freguesia* criarFreguesia(int _id, char _nome[MAX_CHAR_LOCAL]) {
	Freguesia* F = (Freguesia*)malloc(sizeof(struct Freguesia));
	F->id = _id;
	strcpy(F->nome, _nome);
	F->next = NULL;

	return F;
}

listaFreguesias* criarListaFreguesias() {
	listaFreguesias* L = (listaFreguesias*)malloc(sizeof(struct listaFreguesias));
	L->nElem = 0;
	L->inicio = NULL;

	return L;
}

void mostrarFreguesia(Freguesia* F) {
	printf("Freguesia: \n\t");
	printf("ID: %d\n\t", F->id);
	printf("Nome: %s\n\n", F->nome);
}

void mostrarListaFreguesias(listaFreguesias* L) {
	Freguesia* aux = L->inicio;
	while (aux != NULL) {
		mostrarFreguesia(aux);
		aux = aux->next;
	}
}

void freeListaFreguesias(listaFreguesias* F) {
	Freguesia* aux = F->inicio;
	Freguesia* next;

	while (aux != NULL) {
		next = aux->next;
		free(aux);
		aux = next;
	}
	free(F);
}
