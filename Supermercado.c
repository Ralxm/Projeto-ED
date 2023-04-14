#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Supermercado.h"

int aleatorioInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

Supermercado* CriarSupermercado(char* nome) {
    Supermercado* S = (Supermercado*)malloc(sizeof(Supermercado));
    S->funcionarios = NULL;
    S->clientes = NULL;
    S->produtos = NULL;
    strcpy(S->nome, nome);
    return S;
}

int LoadSupermercado(Supermercado* S) {
    int ret0 = ler_produtos(S, "produtos.txt");
    int ret1 = ler_funcionarios(S, "funcionarios.txt");
    int ret2 = ler_clientes(S, "clientes.txt");

    return  ret0 && ret1 && ret2;
}

void MostrarFuncionarios(Supermercado* S) {
    ptFuncionario atual = S->funcionarios->inicio;
    while (atual != NULL) {
        printf("Número: [%d] Nome: [%s]\n", atual->num, atual->nome);
        atual = atual->prox;
    }
}

void MostrarClientes(Supermercado* S) {
    ptCliente atual = S->clientes->inicio;
    while (atual != NULL) {
        printf("Número: [%d] Nome: [%s]\n", atual->num, atual->nome);
        atual = atual->prox;
    }
}

void MostrarProdutos(Supermercado* S) {
    ptProduto atual = S->produtos->inicio;
    while (atual != NULL) {
        printf("Número: [%d] --- Nome: [%s] --- Marca: [%s]\n", atual->num, atual->nome, atual->marca);
        printf("Preço: [%lf] --- Peso: [%d] --- Tempo encontrar: [%lf] --- Tempo Comprar: [%lf]\n", atual->preco, atual->peso, atual->tempo_encontrar, atual->tempo_comprar);
        printf("--------------------------------------------------\n");
        atual = atual->prox;
    }
}

void MostrarSupermercado(Supermercado *S){
    printf("Supermercado: [%s]\n", S->nome);

    printf("Clientes:\n");
    MostrarClientes(S);
    printf("\n\n\n\n\n\n\nFuncionários:\n");
    MostrarFuncionarios(S);
    printf("\n\n\n\n\n\n\nProdutos:\n");
    MostrarProdutos(S);
}

//Cria uma lista de produtos aleatória para depois associar a um cliente
ListaP CriarListaProdutos(Supermercado *S) {
    int quantidadeProdutos = aleatorioInt(1, 20);
    ptProduto produto = S->produtos;
    ListaP NovaLista = CriarListaP();
    for (int i = 0; i <= quantidadeProdutos; i++) {
        int random = aleatorioInt(1, 250);
        for (int j = 0; j <= random; j++) {
            if (produto->prox != NULL) {
                produto = produto->prox;
            }
            else {
                break;
            }
        }
        if (NovaLista->inicio == NULL) {
            NovaLista->inicio = produto;
        }
        else {
            ptProduto ultimo = NovaLista->inicio;
            while (ultimo->prox != NULL) {
                ultimo = ultimo->prox;
            }
            ultimo->prox = produto;
        }
    }
    return NovaLista;
}

//Associa a lista a um cliente
ptCliente AssociarListaClientes(Supermercado *S, ListaP listaProdutos, ptCliente cliente) {
    int random = aleatorioInt(1, 100);
    do {
        for (int i = 0; i <= random; i++) {
            cliente = cliente->prox;
        }
    } while (cliente->ListaProdutosAssociados == NULL);
    cliente->ListaProdutosAssociados = listaProdutos;
    return cliente;
}

#endif SUPERMERCADO_H