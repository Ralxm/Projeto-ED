#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "Supermercado.h"

//Atualmente com erros no código CriarListaProdutos e ler_produtos que não lê os devidos preços, tempo_compra e tempo_encontrar mas que dá output na mesma
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "C");
	Supermercado *S = CriarSupermercado((char *)"Continente-Viseu");
	LoadSupermercado(S);
	MostrarSupermercado(S);
	
	//A testar as funções CriarListaProdutos e AssociarListaClientes

	/*ListaP P = CriarListaP();
	P = CriarListaProdutos(S);
	Cliente* C = CriarCliente(123, "José");
	AssociarListaClientes(S, P, C);
	ptProduto atual = P->inicio;
	while (atual != NULL) {
		printf("Número: [%d] --- Nome: [%s] --- Marca: [%s]\n", atual->num, atual->nome, atual->marca);
		printf("Preço: [%lf] --- Peso: [%d] --- Tempo encontrar: [%lf] --- Tempo Comprar: [%lf]\n", atual->preco, atual->peso, atual->tempo_encontrar, atual->tempo_comprar);
		printf("--------------------------------------------------\n");
		atual = atual->prox;
	}*/
}
