#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR_NOME 100
#include "Supermercado.h"

typedef struct cliente {
    int num;
    char nome[MAX_CHAR_NOME];
    struct cliente* prox;
    int nElem;
} Cliente;

Cliente* CriarCliente(int num, char* nome);
void MostrarClientes(Supermercado* S);