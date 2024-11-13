#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include <locale.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "Portuguese");
	//FALTA:
	//DEFINIR E GUARDAR OS LIVROS POR ÁREA - CRIAR E DEFINIR AS ÁREAS DOS LIVROS	------------------------ FEITO
	//LISTAR LIVROS POR ÁREA														------------------------ FEITO
	//DETERMINAR QUAL A ÁREA COM MAIS LIVROS										------------------------ FEITO
	//VERIFICAR SE UM LIVRO EXISTE DADO O SEU ISBN									------------------------ FEITO
	//DETERMINAR O(S) LIVROS MAIS RECENTE(S)										------------------------ FEITO
	//DETERMINAR O LIVRO MAIS REQUISITADO
	//DETERMINAR QUAL A ÁREA MAIS REQUISITADA										------------------------ FEITO
	//ADICIONAR NOVOS REQUISITANTES													------------------------ FEITO
	//VERIFICAR SE UM REQUISITANTE EXISTE NA LISTA DADO O SEU NOME					------------------------ FEITO
	//DETERMINAR A IDADE MÁXIMA DOS REQUISITANTES									------------------------ FEITO
	//DETERMINAR A IDADE MÉDIA DOS REQUISITANTES									------------------------ FEITO
	//Listar todos os clientes, com uma ordenação à escolha do utilizador - por ordem alfabética do nome, por ordem do campo id_freguesia, por ordem alfabética do apelido(considera - se apelido a última palavra do nome completo);
	//Contar o número de pessoas cuja idade é superior a um dado valor				------------------------ FEITO
	//Determinar qual a idade com mais requisitantes;								------------------------ FEITO
	//Mostrar as requisições de um dado requisitante;
	//Devolver uma lista das pessoas que nunca requisitaram nada;
	//Listar os requisitantes que no momento têm livros requisitados				------------------------ FEITO
	//Determinar qual o sobrenome mais usado pelos requisitantes;
	//Determinar o número de pessoas de um dado Distrito (ou Concelho), cujo nome contém um determinado apelido / nome, por ex.determinar o  número de pessoas do concelho ‘Viseu’ cujo nome contém ‘Lopes’;
	//Devolver um livro que anteriormente estava requisitado;
	//Gravar toda a informação para um dado ficheiro XML, cujo nome é introduzido pelo utilizador;
	//Libertar convenientemente toda a memória usada pelas estruturas de dados antes do programa termina ------------------------ FEITO

	//Run();

	int* Q = (int)malloc(sizeof(int));
	int* L = (int)malloc(sizeof(int));
	*Q = 10;
	*L = 20;
	L = Q;
	Q = L;
	printf("L = [%d]; Q = [%d];\n", L, Q);
} 
