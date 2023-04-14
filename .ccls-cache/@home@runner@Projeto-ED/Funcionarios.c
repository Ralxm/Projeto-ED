#ifndef FUNCIONARIOS_H_
#define FUNCIONARIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Funcionarios.h"

Funcionario *CriarFuncionario(int num, char *nome) {
  Funcionario *funcionario = (Funcionario *)malloc(sizeof(struct funcionario));

  if (!funcionario) {
    printf("Erro ao alocar memoria.\n");
    exit(1);
  }

  funcionario->num = num;
  strcpy(funcionario->nome, nome);
  funcionario->nElem = 0;
}

#endif FUNCIONARIOS_H_