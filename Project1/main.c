#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include <locale.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "Portuguese");
	//FALTA:
	//DEFINIR E GUARDAR OS LIVROS POR �REA - CRIAR E DEFINIR AS �REAS DOS LIVROS	------------------------ FEITO
	//LISTAR LIVROS POR �REA														------------------------ FEITO
	//DETERMINAR QUAL A �REA COM MAIS LIVROS										------------------------ FEITO
	//VERIFICAR SE UM LIVRO EXISTE DADO O SEU ISBN									------------------------ FEITO
	//DETERMINAR O(S) LIVROS MAIS RECENTE(S)										------------------------ FEITO
	//DETERMINAR O LIVRO MAIS REQUISITADO
	//DETERMINAR QUAL A �REA MAIS REQUISITADA										------------------------ FEITO
	//ADICIONAR NOVOS REQUISITANTES													------------------------ FEITO
	//VERIFICAR SE UM REQUISITANTE EXISTE NA LISTA DADO O SEU NOME					------------------------ FEITO
	//DETERMINAR A IDADE M�XIMA DOS REQUISITANTES									------------------------ FEITO
	//DETERMINAR A IDADE M�DIA DOS REQUISITANTES									------------------------ FEITO
	//Listar todos os clientes, com uma ordena��o � escolha do utilizador - por ordem alfab�tica do nome, por ordem do campo id_freguesia, por ordem alfab�tica do apelido(considera - se apelido a �ltima palavra do nome completo);
	//Contar o n�mero de pessoas cuja idade � superior a um dado valor				------------------------ FEITO
	//Determinar qual a idade com mais requisitantes;								------------------------ FEITO
	//Mostrar as requisi��es de um dado requisitante;
	//Devolver uma lista das pessoas que nunca requisitaram nada;
	//Listar os requisitantes que no momento t�m livros requisitados				------------------------ FEITO
	//Determinar qual o sobrenome mais usado pelos requisitantes;
	//Determinar o n�mero de pessoas de um dado Distrito (ou Concelho), cujo nome cont�m um determinado apelido / nome, por ex.determinar o  n�mero de pessoas do concelho �Viseu� cujo nome cont�m �Lopes�;
	//Devolver um livro que anteriormente estava requisitado;
	//Gravar toda a informa��o para um dado ficheiro XML, cujo nome � introduzido pelo utilizador;
	//Libertar convenientemente toda a mem�ria usada pelas estruturas de dados antes do programa termina ------------------------ FEITO

	//Run();

	int* Q = (int)malloc(sizeof(int));
	int* L = (int)malloc(sizeof(int));
	*Q = 10;
	*L = 20;
	L = Q;
	Q = L;
	printf("L = [%d]; Q = [%d];\n", L, Q);
} 
