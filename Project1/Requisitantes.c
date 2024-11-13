#include <stdlib.h>
#include "Requisitantes.h"
#include <string.h>
#include <time.h>

int menorAno = 0;

Requisitante* criarRequisitante(int _id, char _nome[MAX_CHAR_NOME], char _data[11], int _freg) {
	Requisitante* R = (Requisitante*)malloc(sizeof(struct requisitante));
	R->id = _id;
	strcpy(R->nome, _nome);
	strcpy(R->data_nascimento, _data);
	R->id_freguesia = _freg;
	R->next = NULL;

	return R;
}

listaRequisitante* criarListaRequisitante() {
	listaRequisitante* L = (listaRequisitante*)malloc(sizeof(struct listaRequisitante));
	L->nElem = 0;
	L->inicio = NULL;

	return L;
}

void mostrarListaRequisitantes(listaRequisitante* L) {
	Requisitante* aux = L->inicio;
	while(aux != NULL) {
		mostrarRequisitante(aux);
		aux = aux->next;
	}
}

void mostrarRequisitante(Requisitante* R) {
	printf("Requisitante:\n\t");
	printf("ID: %d\n\t", R->id);
	printf("NOME: %s\n\t", R->nome);
	printf("DATA NASCIMENTO %s\n\t", R->data_nascimento);
	printf("FREGUESIA: %d\n\t\n", R->id_freguesia);
}

int determinarAno(Requisitante* R) {
	char ano[5];
	ano[0] = R->data_nascimento[6];
	ano[1] = R->data_nascimento[7];
	ano[2] = R->data_nascimento[8];
	ano[3] = R->data_nascimento[9];
	return atoi(ano);
}

Requisitante* determinarIdadeMaxima(listaRequisitante* L) {
	Requisitante* aux = L->inicio;
	Requisitante* final = aux;
	if (aux == NULL) {
		return aux;
	}
	else {
		while (aux->next != NULL) {
			aux = aux->next;
			if (determinarAno(final) > determinarAno(aux)) { //462278579	Bruna Dias Valbom Belchior Brito	04-set-1959	150506 alterado para 04-09-1959
				final = aux;
			}
		}
	}
	return final;
}

void verificarExisteRequisitante(char nome[MAX_CHAR_NOME], listaRequisitante* L) {
	Requisitante* aux = L->inicio;
	int encontrado = 0;
	if (aux != NULL) {
		if (strcmp(strcat(aux->nome, "\n"), nome) == 0) {
			encontrado = 1;
			printf("O Requisitante existe na lista!\n");
			mostrarRequisitante(aux);
		}
		while (aux->next != NULL) {
			aux = aux->next;
			if (strcmp(strcat(aux->nome, "\n"), nome) == 0) {
				encontrado = 1;
				printf("O Requisitante existe na lista!\n");
				mostrarRequisitante(aux);
			}
		}
	}	
	if (!encontrado) {
		printf("O Requisitante não foi encontrado. Verifique se escreveu bem o nome.\n");
	}
}

void encontrarRequisitante(int id_req) {
	FILE* file = fopen("requisitantes.txt", "r");
	if (file == NULL) {
		printf("Ficheiro requisiçoes.txt não aberto corretamente");
		return 0;
	}
	char line[10000];

	while (fgets(line, sizeof(line), file)) {
		int id;
		char nome[MAX_CHAR_NOME];
		char data_nascimento[12];
		int id_freguesia;
		sscanf(line, "%d %[^\t\n]\t%s\t%d", &id, nome, data_nascimento, &id_freguesia);

		if (id == id_req) {
			Requisitante* R = criarRequisitante(id, nome, data_nascimento, id_freguesia);
			mostrarRequisitante(R);
			free(R);
		}
	}
	fclose(file);
}

void determinarIdadeMédiaRequisitantes(listaRequisitante* L) {
	double idade = 0;
	Requisitante* aux = L->inicio;
	while (aux != NULL) {
		idade += (2024-determinarAno(aux));
		aux = aux->next;
	}
	idade /= L->nElem;
	printf("A idade média dos requisitantes é %.2lf anos\n", idade);
}

void freeListaRequisitante(listaRequisitante* R) {
	Requisitante* aux = R->inicio;
	Requisitante* next;

	while (aux != NULL) {
		next = aux->next;
		free(aux);
		aux = next;
	}
	free(R);
}

//-------------------------------------------------------------------------------------------------------------REQUISIÇÕES----------------------------------

Requisiçao* criarRequisiçao(int _isbn, int _id_requisitante) {
	Requisiçao* Req = (Requisiçao*)malloc(sizeof(struct requisiçao));

	Req->isbn = _isbn;
	Req->id_requisitante = _id_requisitante;
	Req->next = NULL;

	return Req;
}

listaRequesiçoes* criarListaRequisiçoes() {
	listaRequesiçoes* LR = (listaRequesiçoes*)malloc(sizeof(struct listaRequesiçoes));

	LR->nElem = 0;
	LR->inicio = NULL;

	return LR;
}

void mostrarRequisiçao(Requisiçao* R) {
	printf("Requisição: \n\t");
	printf("ISBN: %d\n\t", R->isbn);
	encontrarRequisitante(R->id_requisitante);
}

void mostrarListaRequisiçoes(listaRequesiçoes* LR) {
	Requisiçao* aux = LR->inicio;
	while (aux != NULL) {
		mostrarRequisiçao(aux);
		aux = aux->next;
	}
}

void freeListaRequisiçoes(listaRequesiçoes* R) {
	Requisiçao* aux = R->inicio;
	Requisiçao* next;

	while (aux != NULL) {
		next = aux->next;
		free(aux);
		aux = next;
	}
	free(R);
}