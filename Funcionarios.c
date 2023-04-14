#ifndef FUNCIONARIOS_H_
#define FUNCIONARIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Funcionarios.h"

ptFuncionario CriarFuncionario(int num, char *nome) {
  ptFuncionario funcionario = (ptFuncionario)malloc(sizeof(struct funcionario));
  funcionario->num = num;
  strcpy(funcionario->nome, nome);
  funcionario->prox = NULL;
}

ListaF CriarListaF() {
    ListaF L = (ListaF)malloc(sizeof(struct listaFuncionarios));
    L->nElem = 0;
    L->inicio = NULL;
}

#endif FUNCIONARIOS_H_