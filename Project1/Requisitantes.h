#include <stdio.h>
#include "Biblioteca.h"
#define MAX_CHAR_NOME 100

typedef struct requisitante {
	int id;
	char nome[MAX_CHAR_NOME];
	char data_nascimento[11];
	int id_freguesia;
	struct requisitante* next;
}Requisitante;

typedef struct listaRequisitante {
	int nElem;
	Requisitante* inicio;
}listaRequisitante;

typedef struct requisiçao {
	int isbn;
	int id_requisitante;
	Livro* ptr_livro;
	Requisitante* ptr_Requisitante;
	struct requisiçao* next;
}Requisiçao;

typedef struct listaRequesiçoes {
	int nElem;
	Requisiçao* inicio;
}listaRequesiçoes;

Requisitante* criarRequisitante(int _id, char _nome[MAX_CHAR_NOME], char _data[10], int _freg);
listaRequisitante* criarListaRequisitante();
void mostrarListaRequisitantes(listaRequisitante* L);
void mostrarRequisitante(Requisitante* R);
int determinarAno(Requisitante* R);
Requisitante* determinarIdadeMaxima(listaRequisitante* L);
void verificarExisteRequisitante(char nome[MAX_CHAR_NOME], listaRequisitante* L);
void encontrarRequisitante(int id_req);
void determinarIdadeMédiaRequisitantes(listaRequisitante* L);
void freeListaRequisitante(listaRequisitante* R);

Requisiçao* criarRequisiçao(int _isbn, int _id_requisitante);
listaRequesiçoes* criarListaRequisiçoes();
void mostrarRequisiçao(Requisiçao* R);
void mostrarListaRequisiçoes(listaRequesiçoes* LR);
void freeListaRequisiçoes(listaRequesiçoes* R);

