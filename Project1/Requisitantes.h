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

typedef struct requisi�ao {
	int isbn;
	int id_requisitante;
	Livro* ptr_livro;
	Requisitante* ptr_Requisitante;
	struct requisi�ao* next;
}Requisi�ao;

typedef struct listaRequesi�oes {
	int nElem;
	Requisi�ao* inicio;
}listaRequesi�oes;

Requisitante* criarRequisitante(int _id, char _nome[MAX_CHAR_NOME], char _data[10], int _freg);
listaRequisitante* criarListaRequisitante();
void mostrarListaRequisitantes(listaRequisitante* L);
void mostrarRequisitante(Requisitante* R);
int determinarAno(Requisitante* R);
Requisitante* determinarIdadeMaxima(listaRequisitante* L);
void verificarExisteRequisitante(char nome[MAX_CHAR_NOME], listaRequisitante* L);
void encontrarRequisitante(int id_req);
void determinarIdadeM�diaRequisitantes(listaRequisitante* L);
void freeListaRequisitante(listaRequisitante* R);

Requisi�ao* criarRequisi�ao(int _isbn, int _id_requisitante);
listaRequesi�oes* criarListaRequisi�oes();
void mostrarRequisi�ao(Requisi�ao* R);
void mostrarListaRequisi�oes(listaRequesi�oes* LR);
void freeListaRequisi�oes(listaRequesi�oes* R);

