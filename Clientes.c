#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Clientes.h"

ptCliente CriarCliente(int num, char *nome) {
  ptCliente cliente = (ptCliente)malloc(sizeof(struct cliente));
  cliente->num = num;
  strcpy(cliente->nome, nome);
  cliente->prox = NULL;
  cliente->ListaProdutosAssociados = NULL;
}

ListaC CriarListaC() {
	ListaC L = (ListaC)malloc(sizeof(struct listaClientes));
	L->inicio = NULL;
	L->nElem = 0;
}