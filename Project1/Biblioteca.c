#include "Biblioteca.h"

Livro* criarLivro(int _ISBN, char _titulo[MAX_CHAR], char _autor[MAX_CHAR], char _area[MAX_CHAR], int _ano_pub) {
	Livro* L = (Livro*)malloc(sizeof(struct Livro));
	L->ISBN = _ISBN;
	strcpy(L->titulo, _titulo);
	strcpy(L->autor, _autor);
	L->area = _area;
	L->ano_pub = _ano_pub;
	L->next = NULL;

	return L;
}

void mostrarLivro(Livro* L) {
	printf("Livro: \n\t");
	printf("ISBN: %d\n\t", L->ISBN);
	printf("Título: %s\n\t", L->titulo);
	printf("Autor: %s\n\t", L->autor);
	printf("Área: %d\n\t", L->area);
	printf("Ano: %d\n\n", L->ano_pub);
}

char* traduzirAreaLivro(int n) {
	//1 - Literatura Portuguesa
	//2 - Matemática
	//3 - Ciência
	//4 - Romance
	//5 - Autobiografia
	//6 - Sci-fi
	//7 - Ação
	//8 - Thriller
	//9 - Aventuras
	//10 - Literatura Infantil
	//11 - História
	switch (n) {
	case 1:
		return "Literatura Portuguesa";
		break;
	case 2:
		return "Matemática";
		break;
	case 3:
		return "Ciência";
		break;
	case 4:
		return "Romance";
		break;
	case 5:
		return "Autobiografia";
		break;
	case 6:
		return "Sci-fi";
		break;
	case 7:
		return "Ação";
		break;
	case 8:
		return "Thriller";
		break;
	case 9:
		return "Aventuras";
		break;
	case 10:
		return "Literatura Infantil";
		break;
	case 11:
		return "História";
		break;
	}
}

void freeLivro(Livro* L) {
	free(L->ISBN);
	free(L->area);
	free(L->ano_pub);
	free(L->autor);
	free(L->titulo);
}


Area* criarArea(int _id, char _nome[MAX_CHAR], int _elem) {
	Area* A = (Area*)malloc(sizeof(struct Area));
	A->id = _id;
	strcpy(A->nome, _nome);
	A->nElem = _elem;
	A->next = NULL;
	A->inicio = NULL;

	return A;
}

void mostrarArea(Area* A) {
	printf("Area: \n\t");
	printf("ID: %d\n\t", A->id);
	printf("Área: %s\n\t", A->nome);
}


Biblioteca* criarBiblioteca() {
	char* nomes[MAX_CHAR] = {{"Literatura Portuguesa"}, {"Matematica"}, {"Ciencia"}, {"Romance"} , {"Autobiografia"} , {"Sci-fi"} , {"Acao"} , {"Thriller"} , {"Aventuras"} , {"Literatura Infantil"} , {"Historia"}};
	Biblioteca* B = (Biblioteca*)malloc(sizeof(struct Biblioteca));
	B->inicio = NULL;
	B->nElem = 0;

	for (int i = 0; i <11; i++) {
		Area* A = criarArea(i+1, nomes[i], 0);
		if (B->inicio == NULL) {
			B->inicio = A;
			B->nElem++;
		}
		else {
			Area* aux = B->inicio;
			while (aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = A;
			B->nElem++;
		}
	}
	return B;
}

void inserirLivroBiblioteca(Biblioteca* B, Livro* L) {
	Area* aux = B->inicio;
	while (aux != NULL) {
		if (aux->id == L->area) {
			Livro* auxL = aux->inicio;
			if (auxL == NULL) {
				aux->inicio = L;
				aux->nElem++;
				break;
			}
			else {
				while (auxL->next != NULL) {
					auxL = auxL->next;
				}
				auxL->next = L;
				aux->nElem++;
				break;
			}
		}
		else {
			aux = aux->next;
		}
	}
}

int contarLivrosBiblioteca(Biblioteca* B) {
	int count = 0;
	Area* aux = B->inicio;
	while (aux != NULL) {
		count += aux->nElem;
		aux = aux->next;
	}

	return count;
}

void mostrarBiblioteca(Biblioteca* B) {
	int count = contarLivrosBiblioteca(B);
	int countLivros = 1;

	while (countLivros <= count) {
		Area* aux = B->inicio;
		while (aux != NULL) {
			Livro* auxL = aux->inicio;
			while (auxL != NULL) {
				if (auxL->ISBN == countLivros) {
					mostrarLivro(auxL);
					countLivros++;
				}
				auxL = auxL->next;
			}
			aux = aux->next;
		}
	}
}

void freeBiblioteca(Biblioteca* B) {
	Area* aux = B->inicio;
	Livro* next = NULL;
	Area* nextA = NULL;

	while (aux != NULL) {
		Livro* auxL = aux->inicio;
		while (auxL != NULL) {
			next = auxL->next;
			free(auxL);
			auxL = next;
		}
		nextA = aux->next;
		free(aux);
		aux = nextA;
	}
	free(B);
}