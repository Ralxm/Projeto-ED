#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


int carregarRequisitantes(char* ficheiro, listaRequisitante* L) {
	FILE* file = fopen(ficheiro, "r");
	char line[10000];
	int sum = 0, x, m;

	if (file == NULL) {
		printf("Erro ao abrir requesitos.txt");
		return 0;
	}
	while (fgets(line, sizeof(line), file)) {
		int id;
		char nome[MAX_CHAR_NOME];
		char data_nascimento[12];
		int id_freguesia;
		sscanf(line, "%d %[^\t\n]\t%s\t%d", &id, nome, data_nascimento, &id_freguesia);

		x = id;

		while (x > 0)
		{
			m = x % 10;
			sum = sum + m;
			x = x / 10;
		}

		if (sum % 10 == 0) {
			Requisitante* R = criarRequisitante(id, nome, data_nascimento, id_freguesia);

			if (L->inicio == NULL) {
				L->inicio = R;
			}
			else {
				Requisitante* atual = L->inicio;
				while (atual->next != NULL) {
					atual = atual->next;
				}
				atual->next = R;
			}
			L->nElem++;
		}
		else {
			escreverLog("Requisitante não é válido", id);
		}

		sum = 0;
	}

	fclose(file);
	return 1;
}

int carregarDistritos(char* ficheiro, listaDistritos* L) {
	FILE* file = fopen(ficheiro, "r");
	int x = 0;
	char line[10000];

	if (file == NULL) {
		printf("Erro ao abrir requesitos.txt");
		return 0;
	}
	//fread(&line, sizeof(line), 4, file)
	while (fgets(line, sizeof(line), file)) {
		int id;
		char nome[MAX_CHAR_NOME];
		sscanf(line, "%d %[^\t\n]\t", &id, nome);

		Distrito* R = criarDistrito(id, nome);

		if (L->inicio == NULL) {
			L->inicio = R;
		}
		else {
			Distrito* atual = L->inicio;
			while (atual->next != NULL) {
				atual = atual->next;
			}
			atual->next = R;
		}
		L->nElem++;
	}

	fclose(file);
	return 1;
}

int carregarConcelhos(char* ficheiro, listaConcelhos* L) {
	FILE* file = fopen(ficheiro, "r");
	int x = 0;
	char line[10000];

	if (file == NULL) {
		printf("Erro ao abrir requesitos.txt");
		return 0;
	}

	while (fgets(line, sizeof(line), file)) {
		int id;
		char nome[MAX_CHAR_NOME];
		sscanf(line, "%d %[^\t\n]\t", &id, nome);

		Concelho* C = criarConcelho(id, nome);

		if (L->inicio == NULL) {
			L->inicio = C;
		}
		else {
			Concelho* atual = L->inicio;
			while (atual->next != NULL) {
				atual = atual->next;
			}
			atual->next = C;
		}
		L->nElem++;
	}

	fclose(file);
	return 1;
}

int carregarFreguesias(char* ficheiro, listaFreguesias* L) {
	FILE* file = fopen(ficheiro, "r");
	char line[10000];

	if (file == NULL) {
		printf("Erro ao abrir requesitos.txt");
		return 0;
	}

	while (fgets(line, sizeof(line), file)) {
		int id;
		char nome[MAX_CHAR_NOME];
		sscanf(line, "%d %[^\t\n]\t", &id, nome);

		Freguesia* F = criarFreguesia(id, nome);

		if (L->inicio == NULL) {
			L->inicio = F;
		}
		else {
			Freguesia* atual = L->inicio;
			while (atual->next != NULL) {
				atual = atual->next;
			}
			atual->next = F;
		}
		L->nElem++;
	}

	fclose(file);
	return 1;
}

int carregarRequesiçoes(char* ficheiro, listaRequesiçoes* LR) {
	FILE* file = fopen(ficheiro, "r");
	char line[10000];

	if (file == NULL) {
		printf("Erro ao abrir requesitos.txt");
		return 0;
	}

	while (fgets(line, sizeof(line), file)) {
		int isbn_livro;
		int id_req;
		sscanf(line, "%d;%d\n", &isbn_livro, &id_req);

		Requisiçao* Req = criarRequisiçao(isbn_livro, id_req);

		if (LR->inicio == NULL) {
			LR->inicio = Req;
		}
		else {
			Requisiçao* atual = LR->inicio;
			while (atual->next != NULL) {
				atual = atual->next;
			}
			atual->next = Req;
		}
		LR->nElem++;
	}
	fclose(file);
	return 1;
}

int carregarTudo(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesiçoes* LR) {
	return carregarRequisitantes("requisitantes.txt", R) && carregarDistritos("distritos.txt", D) && carregarConcelhos("concelhos.txt", C) && carregarFreguesias("freguesias.txt", F) && carregarRequesiçoes("requisiçoes.txt", LR);
}

int carregarBiblioteca(Biblioteca* B) {
	FILE* file = fopen("livros.txt", "r");
	if (file == NULL) {
		printf("Ficheiro livros.txt não aberto corretamente");
		return 0;
	}
	char line[10000];

	while (fgets(line, sizeof(line), file)) {
		int isbn;
		char titulo[MAX_CHAR_NOME];
		char autor[MAX_CHAR_NOME];
		int area;
		int ano;
		sscanf(line, "%d;%[^;\n];%[^;\n];%d;%d", &isbn, titulo, autor, &area, &ano);
		Livro* L = criarLivro(isbn, titulo, autor, area, ano);

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

	fclose(file);
	return 1;
}


int verificarLivroExisteFicheiro(Livro* L, Biblioteca* B) { 
	int isbn_check = L->ISBN;
	FILE* file = fopen("livros.txt", "r");
	if (file == NULL) {
		printf("Ficheiro livros.txt não aberto corretamente");
		return 0;
	}
	char line[10000];

	while (fgets(line, sizeof(line), file)) {
		int isbn;
		char titulo[MAX_CHAR_NOME];
		char autor[MAX_CHAR_NOME];
		int area;
		int ano;
		sscanf(line, "%d;%[^;\n];%[^;\n];%d;%d", &isbn, titulo, autor, &area, &ano);

		if (isbn == isbn_check) {
			return 1;
		}
	}
	fclose(file);
	return 0;
}

int verificarLivroExisteBiblioteca(Livro* L, Biblioteca* B) {
	int isbn_check = L->ISBN;

	Area* aux = B->inicio;
	while (aux->next != NULL) {
		Livro* auxL = aux->inicio;
		if (auxL != NULL) {
			if (isbn_check == aux->inicio->ISBN) {
				return 1;
			}
			else {
				while (auxL->next != NULL) {
					auxL = auxL->next;
					if (isbn_check == auxL->ISBN) {
						return 1;
					}
				}
			}
		}
		aux = aux->next;
	}
	return 0;
}

int escreverLivroBiblioteca(Livro* L, Biblioteca* B) {
	FILE* file = fopen("livros.txt", "ab+");
	if (file == NULL) {
		printf("Ficheiro livros.txt não aberto corretamente\n");
		return 0;
	}
	if (verificarLivroExisteFicheiro(L, B) == 1 && verificarLivroExisteBiblioteca(L, B) == 1) {
		printf("O livro já existe na biblioteca! Não foi inserido\n");
	}
	else {
		fprintf(file, "\n%d;%s;%s;%d;%d", L->ISBN, L->titulo, L->autor, L->area, L->ano_pub);
		inserirLivroBiblioteca(B, L);
	}
	fclose(file);
	return 1;
}

Livro* verificarLivroDadoISBN(int isbn, Biblioteca* B) {
	Area* aux = B->inicio;
	while (aux != NULL) {
		Livro* auxL = aux->inicio;
		while (auxL != NULL) {
			if (auxL->ISBN == isbn) {
				return auxL;
			}
			auxL = auxL->next;
		}
		aux = aux->next;
	}
	return NULL;
}

void livroMaisRecente(Biblioteca* B) {
	Livro* final = NULL;
	Area* aux = B->inicio;
	while(aux != NULL){
		Livro* auxL = aux->inicio;
		if (final == NULL) {
			final = auxL;
		}
		while (auxL != NULL) {
			if (auxL->ano_pub > final->ano_pub) {
				final = auxL;	
			}
			auxL = auxL->next;
		}
		aux = aux->next;
	}

	mostrarLivro(final);
}

int determinarAreaComMaisLivros(Biblioteca* B) {
	Area* final = B->inicio;
	Area* aux = B->inicio;
	while (aux != NULL) {
		if (aux->nElem > final->nElem) {
			final = aux;
		}
		aux = aux->next;
	}
	return final->id;
}

int determinarAreaMaisRequesitada(Biblioteca* B, listaRequesiçoes* Req) {
	Biblioteca* copiaB = criarBiblioteca();

	Requisiçao* aux = Req->inicio;
	while (aux != NULL) {
		Livro* L = verificarLivroDadoISBN(aux->isbn, B);
		if (L != NULL) {
			Livro* copiaL = criarLivro(L->ISBN, L->titulo, L->autor, L->area, L->ano_pub);
			inserirLivroBiblioteca(copiaB, copiaL);
		}
		aux = aux->next;
	}
	
	int req = determinarAreaComMaisLivros(copiaB);
	freeBiblioteca(copiaB);
	return req;
}

void listarLivrosPorArea(Biblioteca* B) {
	Area* aux = B->inicio;
	while (aux != NULL) {
		printf("-----------------------------ÁREA: %s QUANTIDADE DE LIVROS: %d-----------------------------\n", traduzirAreaLivro(aux->id), aux->nElem);
		Livro* auxL = aux->inicio;
		while(auxL != NULL) {
			mostrarLivro(auxL);
			auxL = auxL->next;
		}
		aux = aux->next;
		printf("\n\n");
	}
}

int verificarRequisitanteExisteFicheiro(Requisitante* R) {
	int id_check = R->id;
	FILE* file = fopen("requisitantes.txt", "r");
	if (file == NULL) {
		printf("Ficheiro requisitantes.txt não aberto corretamente");
		return 0;
	}
	char line[10000];

	while (fgets(line, sizeof(line), file)) {
		int id;
		char nome[MAX_CHAR_NOME];
		char data_nascimento[12];
		int id_freguesia;
		sscanf(line, "%d %[^\t\n]\t%s\t%d", &id, nome, data_nascimento, &id_freguesia);

		if (id == id_check) {
			return 1;
		}
	}
	fclose(file);
	return 0;
}

int verificarRequisitanteExisteListaRequisitantes(Requisitante* R, listaRequisitante* L) {
	int id_check = R->id;
	Requisitante* aux = L->inicio;
	if (aux != NULL) {
		if (aux->id == id_check) {
			return 1;
		}
		else {
			while (aux->next != NULL) {
				aux = aux->next;
				if (aux->id == id_check) {
					return 1;
				}
			}
		}
	}
	else {
		return 0;
	}
}

int escreverRequesitante(Requisitante* R, listaRequisitante* L) {
	FILE* file = fopen("requisitantes.txt", "ab+");
	if (file == NULL) {
		printf("Ficheiro requisitantes.txt não aberto corretamente\n");
		return 0;
	}
	if (verificarRequisitanteExisteFicheiro(R) == 1 && verificarRequisitanteExisteListaRequisitantes(R, L) == 1) {
		printf("O requisitante já existe! Não foi inserido\n");
	}
	else {
		fprintf(file, "\n%d\t%s\t%s\t%d", R->id, R->nome, R->data_nascimento, R->id_freguesia);
		Requisitante* aux = L->inicio;
		if (aux == NULL) {
			L->inicio = R;
		}
		else {
			while (aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = R;
		}
	}
	fclose(file);
	return 1;
}

int calcularPessoasAcimaIdade(listaRequisitante* R, int n) {
	int count = 0;
	if (R->inicio != NULL) {
		if (2024 - determinarAno(R->inicio) > n) {
			count++;
		}
		Requisitante* aux = R->inicio;
		while (aux->next != NULL) {
			aux = aux->next;
			if (2024 - determinarAno(aux) > n) {
				count++;
			}
		}
		return count;
	}
}

int determinarIdadeMaisRequisitantes(listaRequisitante* R) {
	int idade[150], ano, final=0, atual=0, id;
	for (int i = 0; i < 150; i++) {
		idade[i] = 0;
	}
	
	if (R->inicio != NULL) {
		idade[2024 - determinarAno(R->inicio)]++;
		Requisitante* aux = R->inicio;
		while (aux->next != NULL) {
			idade[2024 - determinarAno(aux)]++;
			aux = aux->next;
		}
	}

	for (int i = 0; i < 150; i++) {
		if (idade[i] > atual) {
			atual = idade[i];
			final = i;
		}
	}
	return final;
}

int listarRequisitantesComLivrosRequisitados(listaRequisitante* R) {
	int encontrado = 0;
	int counter = 0;
	int arr[1000];
	for (int i = 0; i < 1000; i++) {
		arr[i] = 0;
	}

	Requisiçao* aux = R->inicio;
	if (aux) {
		arr[counter++] = aux->id_requisitante;
		while (aux->next != NULL) {
			aux = aux->next;
			for (int i = 0; i < 1000; i++) {
				if (arr[i] == aux->id_requisitante) {
					encontrado = 1;
					i = 1001;
				}
			}
			if (encontrado == 0) {
				arr[counter++] = aux->id_requisitante;
			}
			encontrado = 0;
		}
	}

	for (int i = 0; i < 1000; i++) {
		if (arr[i] != 0) {
			encontrarRequisitante(arr[i]);
		}
	}
	return 1;
}

int verificarRequisiçaoExisteFicheiro(Requisiçao* R) {
	int isbn_check = R->isbn;
	int id_check = R->id_requisitante;
	FILE* file = fopen("requisiçoes.txt", "r");
	if (file == NULL) {
		printf("Ficheiro requisiçoes.txt não aberto corretamente");
		return 0;
	}
	char line[10000];

	while (fgets(line, sizeof(line), file)) {
		int isbn;
		int id;
		sscanf(line, "%d;%d", &isbn, &id);

		if (isbn == isbn_check && id == id_check) {
			return 1;
		}
	}
	fclose(file);
	return 0;
}

int verificarRequisiçaoExisteListaRequisiçoes(Requisiçao* R, listaRequesiçoes* LR) {
	int isbn_check = R->isbn;
	int id_check = R->id_requisitante;
	Requisiçao* aux = LR->inicio;
	if (aux != NULL) {
		if (aux->isbn == isbn_check && aux->id_requisitante == id_check) {
			return 1;
		}
		else {
			while (aux->next != NULL) {
				aux = aux->next;
				if (aux->isbn == isbn_check && aux->id_requisitante == id_check) {
					return 1;
				}
			}
		}
	}
	else {
		return 0;
	}
}

int escreverRequesiçao(Requisiçao* R, listaRequesiçoes* LR) {
	FILE* file = fopen("requisitantes.txt", "ab+");
	if (file == NULL) {
		printf("Ficheiro requisições.txt não aberto corretamente\n");
		return 0;
	}
	if (verificarRequisiçaoExisteFicheiro(R) == 1 && verificarRequisiçaoExisteListaRequisiçoes(R, LR) == 1) {
		printf("A requisição já existe na biblioteca! Não foi inserido\n");
	}
	else {
		fprintf(file, "%d;%d\n", R->isbn, R->id_requisitante);
		Requisiçao* aux = LR->inicio;
		if (aux == NULL) {
			LR->inicio = R;
		}
		else {
			while (aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = R;
		}
	}
	fclose(file);
	return 1;
}

double calcularMemoriaRequisitantes(listaRequisitante* R) {
	double memoriaReq = 0;
	Requisitante* Req = R->inicio;
	if (Req != NULL) {
		memoriaReq += sizeof(Req->id);
		memoriaReq += sizeof(Req->data_nascimento);
		memoriaReq += sizeof(Req->id_freguesia);
		memoriaReq += sizeof(Req->nome);
		memoriaReq += sizeof(Req);
		while (Req->next != NULL) {
			Req = Req->next;
			memoriaReq += sizeof(Req->id);
			memoriaReq += sizeof(Req->data_nascimento);
			memoriaReq += sizeof(Req->id_freguesia);
			memoriaReq += sizeof(Req->nome);
			memoriaReq += sizeof(Req);
		}
	}
	return memoriaReq;
}

double calcularMemoriaDistritos(listaDistritos* D) {
	double memoriaDis = 0;
	Distrito* Dis = D->inicio;
	if (Dis != NULL) {
		memoriaDis += sizeof(Dis->id);
		memoriaDis += sizeof(Dis->nome);
		while (Dis->next != NULL) {
			Dis = Dis->next;
			memoriaDis += sizeof(Dis->id);
			memoriaDis += sizeof(Dis->nome);
		}
	}
	return memoriaDis;
}

double calcularMemoriaConcelhos(listaConcelhos* C) {
	double memoriaCon = 0;
	Concelho* Con = C->inicio;
	if (Con != NULL) {
		memoriaCon += sizeof(Con->id);
		memoriaCon += sizeof(Con->nome);
		while (Con->next != NULL) {
			Con = Con->next;
			memoriaCon += sizeof(Con->id);
			memoriaCon += sizeof(Con->nome);
		}
	}
	return memoriaCon;
}

double calcularMemoriaFreguesias(listaFreguesias* F) {
	double memoriaFre = 0;
	Freguesia* Fre = F->inicio;
	if (Fre != NULL) {
		memoriaFre += sizeof(Fre->id);
		memoriaFre += sizeof(Fre->nome);
		while (Fre->next != NULL) {
			Fre = Fre->next;
			memoriaFre += sizeof(Fre->id);
			memoriaFre += sizeof(Fre->nome);
		}
	}
	return memoriaFre;
}

double calcularMemoriaRequisiçoes(listaRequesiçoes* LR) {
	double memoriaRe = 0;
	Requisiçao* Re = LR->inicio;
	if (Re != NULL) {
		memoriaRe += sizeof(Re->isbn);
		memoriaRe += sizeof(Re->id_requisitante);
		while (Re->next != NULL) {
			Re = Re->next;
			memoriaRe += sizeof(Re->isbn);
			memoriaRe += sizeof(Re->id_requisitante);
		}
	}
	return memoriaRe;
}

double calcularMemoriaBiblioteca(Biblioteca* B) {
	double memoriaLiv = 0;
	Area* aux = B->inicio;

	while (aux != NULL) {
		Livro* auxL = aux->inicio;
		while (auxL != NULL) {
			memoriaLiv += sizeof(auxL->ISBN);
			memoriaLiv += sizeof(auxL->autor);
			memoriaLiv += sizeof(auxL->titulo);
			memoriaLiv += sizeof(auxL->area);
			memoriaLiv += sizeof(auxL->ano_pub);
			auxL = auxL->next;
		}
		aux = aux->next;
	}

	return memoriaLiv;
}

double KB(double mem) {
	return mem / 1024;
}

double MB(double mem) {
	return KB(mem) / 1024;
}

int calcularMemória(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesiçoes* LR, Biblioteca* B) {
	double memoriaReq = calcularMemoriaRequisitantes(R);
	double memoriaDis = calcularMemoriaDistritos(D);
	double memoriaCon = calcularMemoriaConcelhos(C);
	double memoriaFre = calcularMemoriaFreguesias(F);
	double memoriaRe = calcularMemoriaRequisiçoes(LR);
	double memoriaLiv = calcularMemoriaBiblioteca(B);

	double memoriaTotal = memoriaReq + memoriaDis + memoriaCon + memoriaFre + memoriaRe + memoriaLiv;
	printf("\nMemória Requisitantes: %.01lf B = %.01lf KB = %.01lf MB\n", memoriaReq, KB(memoriaReq), MB(memoriaReq));
	printf("Memória Distritos: %.01lf B = %.01lf KB = %.01lf MB\n", memoriaDis, KB(memoriaDis), MB(memoriaDis));
	printf("Memória Concelhos: %.01lf B = %.01lf KB = %.01lf MB\n", memoriaCon, KB(memoriaCon), MB(memoriaCon));
	printf("Memória Freguesias: %.01lf B = %.01lf KB = %.01lf MB\n", memoriaFre, KB(memoriaFre), MB(memoriaFre));
	printf("Memória Requisições: %.01lf B = %.01lf KB = %.01lf MB\n", memoriaRe, KB(memoriaRe), MB(memoriaRe));
	printf("Memória Livros: %.01lf B = %.01lf KB = %.01lf MB\n\n", memoriaLiv, KB(memoriaLiv), MB(memoriaLiv));
	printf("Memória Total: %.01lf B = %.01lf KB = %.02lf MB\n\n", memoriaTotal, KB(memoriaTotal), MB(memoriaTotal));
}

int limparMemoria(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesiçoes* LR, Biblioteca* B) {
	freeListaRequisitante(R);
	freeListaDistritos(D);
	freeListaConcelhos(C);
	freeListaFreguesias(F);
	freeListaRequisiçoes(LR);
	freeBiblioteca(B);

	return 1;
}

