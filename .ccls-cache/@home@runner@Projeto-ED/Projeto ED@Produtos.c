#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstdio>

#include "Supermercado.h"


//Criar o produto
Produto* CriarProduto(int num, char* nome, float preco, float tempo_encontrar, float tempo_comprar) {
	Produto* produto = (Produto*)malloc(sizeof(Produto));

	if (produto == NULL) {
		printf("Erro ao alocar memoria.\n");
		exit(1);
	}

	produto->num = num;
	strcpy(produto->nome, nome);
	produto->preco = preco;
	produto->tempo_encontrar = tempo_encontrar;
	produto->tempo_comprar = tempo_comprar;
	produto->prox = NULL;

	char* token = strtok(produto->nome, "[");
	strcpy(produto->nome, token);
	token = strtok(NULL, "]");
	strcpy(produto->marca, token);
	token = strtok(NULL, " \t");
	strcpy(produto->peso, token);

	return produto;
}

//Mostrar todos os produtos
void MostrarProdutos(Produto* produtos) {
	Produto* atual = produtos;

	printf("Num\tNome\t\tMarca\t\tPeso\t\tPreco\tTempo Encontrar\tTempo Comprar\n");
	printf("------------------------------------------------------------------------------------\n");

	while (atual != NULL) {
		printf("%d\t%s\t%s\t%s\t%.2f\t%.2f\t\t%.2f\n",
			atual->num, atual->nome, atual->marca, atual->peso, atual->preco,
			atual->tempo_encontrar, atual->tempo_comprar);
		atual = atual->prox;
	}
}