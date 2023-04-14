#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Clientes.h"

Cliente *CriarCliente(int num, char *nome) {
  Cliente *C = (Cliente *)malloc(sizeof(struct cliente));

  C->num = num;
  C->nome = nome;
}

void MostrarClientes(Supermercado *S) {
  Cliente *atual = S->clientes;
  while (atual != NULL) {
    printf("Nome: [%s] <-> Número: [%d]", atual->nome, atual->num);
    atual = atual->prox;
  }
}
