#include <stdlib.h>
#include <stdio.h>
#include "listaEstatica.h"

int main (){

	Lista *li;
	li = cria_lista(); 	
	int x= tamanho_lista(li);
	printf("%d\n",x );
	x= lista_cheia(li);
	printf("%d\n",x );
	 x= lista_vazia(li);
	//printf("%d\n",x );


	struct aluno dados_aluno = { 3223132130,"Kara", 1 , 2 , 3};
	struct aluno asd;
	int y = insere_lista_final(li, dados_aluno);
	//x= tamanho_lista(li);
	//printf("%d\n",x );
	struct aluno dados_alunos = { 3223132132,"Alex", 1 , 2 , 3};
	struct aluno liga= { 3223132133,"Clark", 1 , 2 , 3};
	int k= insere_lista_final(li, liga);
	int o = insere_lista_final(li, dados_alunos);
	//struct aluno teste;
	//o = insere_lista_final(li, teste);
	//int z = remove_lista_final(li);
	int posicao=0;
	int w = consulta_lista_pos(li, posicao, &asd);
	// é bom fazer uma struct "teste" vazia, caso você só saiba a posição que cê quer acessar e não saiba o nome da struct
	//printf("%s\n",dados_alunos.nome);
	int matricula=3223132130;

	int x1= consulta_lista_mat(li, matricula, &dados_alunos);
	//printf("%s\n",dados_alunos.nome);

}