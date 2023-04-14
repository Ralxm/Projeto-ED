#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Produtos.h"

//Criar o produto
ptProduto CriarProduto(int num, char* nome, char* marca, int peso, float preco, float tempo_encontrar, float tempo_comprar) {
	ptProduto produto = (ptProduto)malloc(sizeof(struct produto));
	produto->num = num;
	strcpy(produto->nome, nome);
	strcpy(produto->marca, marca);
	produto->peso = peso;
	produto->preco = preco;
	produto->tempo_encontrar = tempo_encontrar;
	produto->tempo_comprar = tempo_comprar;
	produto->prox = NULL;

	return produto;
}

ListaP CriarListaP() {
	ListaP P = (ListaP)malloc(sizeof(struct listaProdutos));
	P->nElem = 0;
	P->inicio = NULL;

	return P;
}
