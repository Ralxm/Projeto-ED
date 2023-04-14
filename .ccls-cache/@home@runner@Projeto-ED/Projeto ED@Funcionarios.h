#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR_NOME 100

typedef struct funcionario {
  int num;
  char nome[MAX_CHAR_NOME];
  struct funcionario *prox;
} Funcionario;

Funcionario *CriarFuncionario(int num, char *nome);

#endif FUNCIONARIOS_H