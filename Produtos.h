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
    int peso;
    float preco;
    float tempo_encontrar;
    float tempo_comprar;
    struct produto* prox;
    int nElem;
} Produto, *ptProduto;

typedef struct listaProdutos {
    int nElem;
    ptProduto inicio;
}ListaProdutos, *ListaP;

Produto* CriarProduto(int num, char* nome, char* marca, int peso, float preco, float tempo_encontrar, float tempo_comprar);
ListaP CriarListaP();

#endif PRODUTO_h