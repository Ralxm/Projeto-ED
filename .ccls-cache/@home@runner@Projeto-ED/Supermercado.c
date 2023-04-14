#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Supermercado.h"

Supermercado* CriarSupermercado(char* nome) {
    Supermercado* S = (Supermercado*)malloc(sizeof(Supermercado));
    strcpy(S->nome, nome);
    return S;
}

int LoadSupermercado(Supermercado* S) {
    int ret0 = ler_produtos(S, "produtos.txt");
    int ret1 = ler_funcionarios(S, "funcionarios.txt");
    int ret2 = ler_clientes(S, "clientes.txt");
}

void MostrarSupermercado(Supermercado *S){
  Funcionario* atual = S->funcionarios;
  while(atual != NULL){
    printf("Número: [%d]\nNome: [%s]", atual->num, atual->nome);
    atual = atual->prox;
  }
}

#endif SUPERMERCADO_H