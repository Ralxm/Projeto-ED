#ifndef SUPERMERCADO_H_
#define SUPERMERCADO_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Clientes.h"
#include "Funcionarios.h"
#include "Produtos.h"

typedef struct supermercado {
  char nome[100];
  ListaP produtos;
  ListaF funcionarios;
  ListaC clientes;
} Supermercado;

Supermercado *CriarSupermercado(char *nome);
int LoadSupermercado(Supermercado *S);
void MostrarSupermercado(Supermercado *S);
void MostrarFuncionarios(Supermercado* S);
void MostrarProdutos(Supermercado* S);
void MostrarClientes(Supermercado* S);
ListaP CriarListaProdutos();
ptCliente AssociarListaClientes(Supermercado *S, ListaP listaProdutos, ptCliente);

#endif SUPERMERCADO_H_