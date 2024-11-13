#include "Requisitantes.h"
#include "Locais.h"

int carregarRequisitantes(char* file, listaRequisitante* B);
int carregarDistritos(char* file, listaDistritos* L);
int carregarConcelhos(char* file, listaConcelhos* L);
int carregarFreguesias(char* file, listaFreguesias* L);
int carregarRequesi�oes(char* ficheiro, listaRequesi�oes* LR);
int carregarTudo(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesi�oes* LR);
int carregarBiblioteca(Biblioteca* B);
int verificarLivroExisteFicheiro(Livro* L, Biblioteca* B);
int verificarLivroExisteBiblioteca(Livro* L, Biblioteca* B);
int escreverLivroBiblioteca(Livro* L, Biblioteca* B);
Livro* verificarLivroDadoISBN(int isbn, Biblioteca* B);
void livroMaisRecente(Biblioteca* B);
int determinarAreaComMaisLivros(Biblioteca* B);
int determinarAreaMaisRequesitada(Biblioteca* B, listaRequesi�oes* Req);
void listarLivrosPorArea(Biblioteca* B);
int verificarRequisitanteExisteFicheiro(Requisitante* R);
int verificarRequisitanteExisteListaRequisitantes(Requisitante* R, listaRequisitante* L);
int escreverRequesitante(Requisitante* R, listaRequisitante* L);
int calcularPessoasAcimaIdade(listaRequisitante* R, int n);
int determinarIdadeMaisRequisitantes(listaRequisitante* R);
int listarRequisitantesComLivrosRequisitados(listaRequisitante* R);
int verificarRequisi�aoExisteFicheiro(Requisi�ao* R);
int verificarRequisi�aoExisteListaRequisi�oes(Requisi�ao* R, listaRequesi�oes* LR);
int escreverRequesi�ao(Requisi�ao* R, listaRequesi�oes* LR);
double calcularMemoriaRequisitantes(listaRequisitante* R);
double calcularMemoriaDistritos(listaDistritos* D);
double calcularMemoriaConcelhos(listaConcelhos* C);
double calcularMemoriaFreguesias(listaFreguesias* F);
double calcularMemoriaRequisi�oes(listaRequesi�oes* LR);
double calcularMemoriaBiblioteca(Biblioteca* B);
int calcularMem�ria(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesi�oes* LR, Biblioteca* B); 
int limparMemoria(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesi�oes* LR, Biblioteca* B);









