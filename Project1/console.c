#include "console.h"

void print_console_locais() {
	printf("#--------------------------------------------------------#\n");
	printf("# 1 - Mostrar Lista Distritos                            #\n");
	printf("# 2 - Mostrar Lista Concelhos                            #\n");
	printf("# 3 - Mostrar Lista Freguesias                           #\n");
	printf("#                                                        #\n");
	printf("# 0 - Voltar                                             #\n");
	printf("#--------------------------------------------------------#\n\n");
}

void print_console_biblioteca() {
	printf("#--------------------------------------------------------#\n");
	printf("# 1 - Mostrar Livros na Biblioteca                       #\n");
	printf("# 2 - Inserir Um Livro na Biblioteca                     #\n");
	printf("# 3 - Verificar se um livro existe dado o ISBN           #\n");
	printf("# 4 - Livro mais recente presente na Biblioteca          #\n");
	printf("# 5 - Determinar a �rea com mais livros                  #\n");
	printf("# 6 - Listar Livros por �rea                             #\n");
	printf("#                                                        #\n");
	printf("# 0 - Voltar                                             #\n");
	printf("#--------------------------------------------------------#\n\n");
}

void print_console_requesi�oes() {
	printf("#--------------------------------------------------------#\n");
	printf("# 1 - Mostrar Lista de Requisi��es                       #\n");
	printf("# 2 - Inserir Requisitante                               #\n");
	printf("# 3 - Insira uma requisi��o                              #\n");
	printf("# 4 - Pesquise um Requisitante pelo nome                 #\n");
	printf("# 5 - Requisitante com maior idade                       #\n");
	printf("# 6 - Determinar idade m�dia dos Requisitantes           #\n");
	printf("# 7 - Determinar a �rea mais requisitada                 #\n");
	printf("# 8 - Determinar quantas pessoas acima de X idade        #\n");
	printf("# 9 - Determinar idade com mais requisitantes            #\n");
	printf("# 10 - Listar Requisitantes com livros requisitados      #\n");
	printf("#                                                        #\n");
	printf("# 0 - Voltar                                             #\n");
	printf("#--------------------------------------------------------#\n\n");
}

void print_console() {
	printf("#--------------------------------------------------------#\n");
	printf("# 1 - Gerir Listas de Locais                             #\n");
	printf("# 2 - Gerir Biblioteca                                   #\n");
	printf("# 3 - Gerir Requesi��es                                  #\n");
	printf("#                                                        #\n");
	printf("# 4 - Calcular a mem�ria                                 #\n");
	printf("#                                                        #\n");
	printf("# 0 - Terminar Programa                                  #\n");
	printf("#--------------------------------------------------------#\n\n");
}

int Run() {
	int x = 1000, y, z = 1000, k = 1000, j = 1000;

	Biblioteca* B = criarBiblioteca();
	listaRequisitante* R = criarListaRequisitante();
	listaDistritos* D = criarListaDistrito();
	listaConcelhos* C = criarListaConcelhos();
	listaFreguesias* F = criarListaFreguesias();
	listaRequesi�oes* LR = criarListaRequisi�oes();
	carregarTudo(R, D, C, F, LR);
	carregarBiblioteca(B);

	do {
		system("cls");
		print_console2();
		printf("Op��o: ");
		scanf("%d", &x);
		y = 1000, k = 1000, j = 1000;
		switch (x) {
			case 1: {
				do {
					system("cls");
					print_console_locais();
					printf("Op��o: ");
					scanf("%d", &z);
					switch (z) {
						case 1: {
							mostrarListaDistritos(D);
							break;
						}
						case 2: {
							mostrarListaConcelhos(C);
							break;
						}
						case 3: {
							mostrarListaFreguesias(F);
							break;
						}
						case 0: {
							z = 0;
							break;
						}
					}
					if (z != 0) {
						printf("Digite qualquer n�mero para prosseguir: ");
						scanf("%d", &y);
					}
				} while (z != 0);
				break;
			}
			case 2: {
				do {
					system("cls");
					print_console_biblioteca();
					printf("Op��o: ");
					scanf("%d", &k);
					switch (k) {
						case 1: {
							mostrarBiblioteca(B);
							break;
						}
						case 2: {
							int isbn;
							char titulo[MAX_CHAR_NOME];
							char autor[MAX_CHAR_NOME];
							int area;
							int ano;
							while (getchar() != '\n');
							printf("Introduza o ISBN do livro: ");
							scanf("%d", &isbn);
							while (getchar() != '\n');
							printf("Introduza o t�tulo do livro: ");
							scanf("%[^\n]", titulo);
							while (getchar() != '\n');
							printf("Introduza o autor do livro: ");
							scanf("%[^\n]", autor);
							while (getchar() != '\n');
							printf("Introduza a area do livro: ");
							scanf("%d", &area);
							while (getchar() != '\n');
							printf("Introduza ano de publica��o do livro: ");
							scanf("%d", &ano);
							Livro* L = criarLivro(isbn, titulo, autor, area, ano);
							escreverLivroBiblioteca(L, B);
							break;
						}
						case 3: {
							int isbn_verifica;
							printf("Introduza o ISBN: ");
							scanf("%d", &isbn_verifica);
							Livro* L = verificarLivroDadoISBN(isbn_verifica, B);
							if (L != NULL) {
								mostrarLivro(L);
							}
							else {
								printf("O livro com o isbn %d n�o existe na biblioteca\n", isbn_verifica);
							}
							break;
						}
						case 4: {
							livroMaisRecente(B);
							break;
						}
						case 5: {
							int area = determinarAreaComMaisLivros(B);
							printf("A �rea com mais livros �: %s\n", traduzirAreaLivro(area));
							break;
						}
						case 6: {
							listarLivrosPorArea(B);
							break;
						}
						case 0: {
							k = 0;
							break;
						}
					}
					if (k != 0) {
						printf("Digite qualquer n�mero para prosseguir: ");
						scanf("%d", &y);
					}
				} while (k != 0);
				break;
			}
			case 3: {
				do {
					system("cls");
					print_console_requesi�oes();
					printf("Op��o: ");
					scanf("%d", &j);
					switch (j) {
						case 1: {
							mostrarListaRequisi�oes(LR);
							break;
						}
						case 2: {
							int id;
							int id_freguesia;
							char nome[MAX_CHAR_NOME];
							char data[12];
							while (getchar() != '\n');
							printf("Introduza o ID do Requisitante: ");
							scanf("%d", &id);
							while (getchar() != '\n');
							printf("Introduza o nome do Requisitante: ");
							scanf("%[^\n]", nome);
							while (getchar() != '\n');
							printf("Introduza a data de nascimento no formato 'dd-mm-yyyy' (ex: '04-02-2023) do Requisitante: ");
							scanf("%[^\n]", data);
							while (getchar() != '\n');
							printf("Introduza ID de freguesia do Requisitante: ");
							scanf("%d", &id_freguesia);
							Requisitante* Req = criarRequisitante(id, nome, data, id_freguesia);
							escreverRequesitante(Req, R);
							break;
						}
						case 3: {
							int isbn_livro;
							int id_req;
							printf("Introduza o ISBN do livro: ");
							scanf("%d", &isbn_livro);
							printf("Introduza o ID do Requisitante: ");
							scanf("%d", &id_req);
							Requisi�ao* Req = criarRequisi�ao(isbn_livro, id_req);
							escreverRequesi�ao(Req, LR);
							break;
						}
						case 4: {
							char nome[MAX_CHAR_NOME];
							printf("Introduza o nome do Requisitante que pretende encontrar: ");
							int c;
							while ((c = getchar()) != '\n' && c != EOF);
							fgets(nome, MAX_CHAR_NOME, stdin);
							verificarExisteRequisitante(nome, R);
							break;
						}
						case 5: {
							mostrarRequisitante(determinarIdadeMaxima(R));
							break;
						}
						case 6: {
							determinarIdadeM�diaRequisitantes(R);
							break;
						}
						case 7: {
							int nova_area = determinarAreaMaisRequesitada(B, LR);
							printf("A �rea com mais livros requisitada �: %s\n", traduzirAreaLivro(nova_area));
							break;
						}
						case 8: {
							int idade_check;
							printf("Qual a idade? ");
							scanf("%d", &idade_check);
							printf("\nExistem %d pessoas acima de %d anos\n", calcularPessoasAcimaIdade(R, idade_check), idade_check);
							break;
						}
						case 9: {
							printf("\nA idade com mais requisitantes �: %d\n", determinarIdadeMaisRequisitantes(R));
							break;
						}
						case 10: {
							listarRequisitantesComLivrosRequisitados(LR);
							break;
						}
						case 0: {
							j = 0;
							break;
						}
					}
					if (j != 0) {
						printf("Digite qualquer n�mero para prosseguir: ");
						scanf("%d", &y);
					}
				} while (j != 0);
				break;
			}
			case 4: {
				calcularMem�ria(R, D, C, F, LR, B);
				break;
			}
		}
		if (x != 0) {
			printf("Digite qualquer n�mero para prosseguir: ");
			scanf("%d", &y);
		}
	} while (x != 0);
	escreverXML(R, D, C, F, LR, B);
	limparMemoria(R, D, C, F, LR, B);
	return 1;
}