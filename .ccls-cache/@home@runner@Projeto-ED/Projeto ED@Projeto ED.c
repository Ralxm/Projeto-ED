#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Supermercado.h"

int main() {
  Supermercado *S = CriarSupermercado((char *)"Continente-Viseu");
  Funcionario *R = CriarFuncionario(123, (char *)"asdf");
}
