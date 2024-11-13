#include "Requisitantes.h"
#include "Locais.h"

int carregarRequisitantes(char* file, listaRequisitante* B);
int carregarDistritos(char* file, listaDistritos* L);
int carregarConcelhos(char* file, listaConcelhos* L);
int carregarFreguesias(char* file, listaFreguesias* L);
int carregarRequesiçoes(char* ficheiro, listaRequesiçoes* LR);
int carregarTudo(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesiçoes* LR);
int carregarBiblioteca(Biblioteca* B);
int verificarLivroExisteFicheiro(Livro* L, Biblioteca* B);
int verificarLivroExisteBiblioteca(Livro* L, Biblioteca* B);
int escreverLivroBiblioteca(Livro* L, Biblioteca* B);
Livro* verificarLivroDadoISBN(int isbn, Biblioteca* B);
void livroMaisRecente(Biblioteca* B);
int determinarAreaComMaisLivros(Biblioteca* B);
int determinarAreaMaisRequesitada(Biblioteca* B, listaRequesiçoes* Req);
void listarLivrosPorArea(Biblioteca* B);
int verificarRequisitanteExisteFicheiro(Requisitante* R);
int verificarRequisitanteExisteListaRequisitantes(Requisitante* R, listaRequisitante* L);
int escreverRequesitante(Requisitante* R, listaRequisitante* L);
int calcularPessoasAcimaIdade(listaRequisitante* R, int n);
int determinarIdadeMaisRequisitantes(listaRequisitante* R);
int listarRequisitantesComLivrosRequisitados(listaRequisitante* R);
int verificarRequisiçaoExisteFicheiro(Requisiçao* R);
int verificarRequisiçaoExisteListaRequisiçoes(Requisiçao* R, listaRequesiçoes* LR);
int escreverRequesiçao(Requisiçao* R, listaRequesiçoes* LR);
double calcularMemoriaRequisitantes(listaRequisitante* R);
double calcularMemoriaDistritos(listaDistritos* D);
double calcularMemoriaConcelhos(listaConcelhos* C);
double calcularMemoriaFreguesias(listaFreguesias* F);
double calcularMemoriaRequisiçoes(listaRequesiçoes* LR);
double calcularMemoriaBiblioteca(Biblioteca* B);
int calcularMemória(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesiçoes* LR, Biblioteca* B); 
int limparMemoria(listaRequisitante* R, listaDistritos* D, listaConcelhos* C, listaFreguesias* F, listaRequesiçoes* LR, Biblioteca* B);









