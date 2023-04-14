#ifndef CLIENTES_H_
#define CLIENTES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR_NOME 100
#include "Produtos.h"

typedef struct cliente {
  int num;
  char nome[MAX_CHAR_NOME];
  struct cliente *prox;
  ListaP ListaProdutosAssociados;
} Cliente, *ptCliente;

typedef struct listaClientes {
	int nElem;
	ptCliente inicio;
}Lista, *ListaC;

ListaC CriarListaC();
ptCliente CriarCliente(int num, char* nome);

#endif CLIENTES_H_