#ifndef PRODUTO_h
#define PRODUTO_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR_NOME 100

typedef struct produto {
    int num;
    char nome[MAX_CHAR_NOME];
    char marca[MAX_CHAR_NOME];
    char peso[20];
    float preco;
    float tempo_encontrar;
    float tempo_comprar;
    struct produto* prox;
    int nElem;
} Produto;

Produto* CriarProduto(int num, char* nome, float preco, float tempo_encontrar, float tempo_comprar);
void MostrarProdutos(Produto* produtos);

#endif PRODUTO_h