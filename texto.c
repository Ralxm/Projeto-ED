#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Funcionarios.h"
#include "texto.h"

//100% feito
int ler_funcionarios(Supermercado *S, char *ficheiro) {
  char linha[100];
  FILE *file = fopen("funcionarios.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  S->funcionarios = CriarListaF();

  while (fgets(linha, sizeof(linha), file)) {
    int num;
    char nome[MAX_CHAR_NOME];

    sscanf(linha, "%d %[^\n]s", &num, nome);

    ptFuncionario funcionario = CriarFuncionario(num, nome);

    if (S->funcionarios->inicio == NULL) {
      S->funcionarios->inicio = funcionario;
    }
    else {
        ptFuncionario ultimo = S->funcionarios->inicio;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = funcionario;
    }
    S->funcionarios->nElem++;
  }
  fclose(file);
  return 1;
}

int ler_produtos(Supermercado* S, char* ficheiro) {
    char linha[100];
    FILE* file = fopen("produtos.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return 0;
    }

    S->produtos = CriarListaP();

    while (fgets(linha, sizeof(linha), file)) {
        int num;
        char nome[MAX_CHAR_NOME];
        char marca[MAX_CHAR_NOME];
        int peso;
        double preco, tempo_encontrar, tempo_comprar;

        sscanf(linha, "%d\t%[^[][%[^]]] %d gr\t%lf\t%lf\t%lf\n", &num, nome, marca, &peso, &preco, &tempo_encontrar, &tempo_comprar);

        ptProduto produto = CriarProduto(num, nome, marca, peso, preco, tempo_encontrar, tempo_comprar);

        if (S->produtos->inicio == NULL) {
            S->produtos->inicio = produto;
        }
        else {
            ptProduto ultimo = S->produtos->inicio;
            while (ultimo->prox != NULL) {
                ultimo = ultimo->prox;
            }
            ultimo->prox = produto;
        }
        S->produtos->nElem++;
    }
    fclose(file);
    return 1;
}


//100% feito
int ler_clientes(Supermercado *S, char *ficheiro) {
  char linha[1000];
  FILE *file = fopen("clientes.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  S->clientes = CriarListaC();
  
  while (fgets(linha, sizeof(linha), file)) {
    int num;
    char nome[MAX_CHAR_NOME];

    sscanf(linha, "%d %[^\n]s", &num, nome);

    ptCliente cliente = CriarCliente(num, nome);

    if (S->clientes->inicio == NULL) {
        S->clientes->inicio = cliente;
    } 
    else {
        ptCliente ultimo = S->clientes->inicio;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = cliente;
    }
    S->clientes->nElem++;
  }
  fclose(file);
  return 1;
}