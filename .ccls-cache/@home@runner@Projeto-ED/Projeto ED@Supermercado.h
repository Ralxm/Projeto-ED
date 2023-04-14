#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstdio>

#include "Funcionarios.h"
#include "Clientes.h"
#include "Produtos.h"

typedef struct supermercado {
    char nome[100];
    Produto* produtos;
    Funcionario* funcionarios;
    Cliente* clientes;
} Supermercado;

Supermercado* CriarSupermercado(char* nome);
int LoadSupermercado(Supermercado* S);
void MostrarSupermercado(Supermercado* supermercado);
