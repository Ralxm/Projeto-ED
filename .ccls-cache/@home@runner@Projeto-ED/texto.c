#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Funcionarios.h"
#include "texto.h"

int ler_funcionarios(Supermercado *supermercado, char *ficheiro) {
  char linha[100];
  FILE *file = fopen("funcionarios.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  while (fgets(linha, sizeof(linha), file)) {
    int num;
    char nome[MAX_CHAR_NOME];

    sscanf(linha, "%d %[^\n]s", &num, nome);

    Funcionario *funcionario = CriarFuncionario(num, nome);
    funcionario->nElem++;

    if (supermercado->funcionarios == NULL) {
      supermercado->funcionarios = funcionario;
    } else {
      Funcionario *atual = supermercado->funcionarios;
      while (atual->prox != NULL) {
        atual = atual->prox;
      }
      atual->prox = funcionario;
    }
  }

  fclose(file);
  return 1;
}

int ler_produtos(Supermercado *supermercado, char *ficheiro) {
  char linha[200];
  FILE *file = fopen(ficheiro, "r");

  if (file == NULL) {
    printf("Erro ao abrir o ficheiro.\n");
    return 0;
  }

  while (fgets(linha, sizeof(linha), file)) {
    int num;
    char nome[100];
    float preco, tempo_encontrar, tempo_comprar;

    sscanf(linha, "%d %[^\t]s %f %f %f", &num, nome, &preco, &tempo_encontrar,
           &tempo_comprar);

    Produto *produto =
        CriarProduto(num, nome, preco, tempo_encontrar, tempo_comprar);
    produto->nElem++;

    if (supermercado->produtos == NULL) {
      supermercado->produtos = produto;
    } else {
      Produto *atual = supermercado->produtos;
      while (atual->prox != NULL) {
        atual = atual->prox;
      }
      atual->prox = produto;
    }
    supermercado->produtos->num++;
  }
  fclose(file);
  return 1;
}

int ler_clientes(Supermercado *supermercado, char *ficheiro) {
  char linha[100];
  FILE *file = fopen("clientes.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  while (fgets(linha, sizeof(linha), file)) {
    int num;
    char nome[MAX_CHAR_NOME];

    sscanf(linha, "%d %[^\n]s", &num, nome);

    Cliente *cliente = CriarCliente(num, nome);

    if (supermercado->clientes == NULL) {
      supermercado->clientes = cliente;
    } else {
      Funcionario *atual = supermercado->clientes;
      while (atual->prox != NULL) {
        atual = atual->prox;
      }
      atual->prox = cliente;
    }
    cliente->nElem++;
  }

  fclose(file);
  return 1;
}