#include <stdlib.h>
#include <stdio.h>

/*

Inserções e exlusões ocorrem apenas no inicio da lista

*/

#define MAX 100 
struct aluno
{
	 int matricula;
	 char nome[40];
	 float n1, n2, n3;
};

typedef struct pilha Pilha;

struct pilha {
	int qtd;
	struct aluno dados[MAX];
};

Pilha * cria_pilha(){
	Pilha * pi= (Pilha*)malloc(sizeof(Pilha));
	if(pi==NULL)return 0;
	pi->qtd=0;
	return pi;
}

void libera_Pilha(Pilha *pi){
	free(pi);
}

int Tamanho_pilha(Pilha *pi){
	if (pi==NULL) return -1;
	return pi->qtd;
}

int insere_pilha(Pilha *pi , struct aluno al){
	if(pi==NULL)return 0;
	pi->dados[pi->qtd]=al;
	pi->qtd++;
	return 1;
}


int remove_pilha(Pilha *pi ){
	if(pi==NULL || pi->qtd==0) return 0;
	pi->qtd--;
	return 1;
}

int consulta_pilha(Pilha *pi, struct aluno *al){
	if(pi!=NULL && pi->qtd!=0){
		*al=pi->dados[pi->qtd-1];
		return 1;
	}

}