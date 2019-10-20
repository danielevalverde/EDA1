#include <stdlib.h>
#include <stdio.h>

struct aluno
{
	int matricula;
	char nome [30];
	float n1,n2,n3;
};

typedef struct elemento* Pilha ; // ponteiro de ponteiros pra pegar inicio da pilha

struct elemento {
	struct aluno dados; 
	struct elemento *prox; // um ponteiro que vai guardar o endereço da próxima celula
};
typedef struct elemento Elem;


Pilha* cria_pilha(){
	Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
	if(pi!=NULL)
		*pi=NULL;
	return pi;
}

void libera_pilha(Pilha *pi){
	if(pi!=NULL){
		Elem *no;
		while(*pi!=NULL){
			no=*pi;
			*pi=(*pi)->prox;
			free(no);
		}
		free(pi);
	}
}


int tamanho_fila(Pilha *pi){
	if(pi==NULL)return 0;
	int cont =0;
	Elem * no = *pi;
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}

int insere_pilha(Pilha *pi , struct aluno al){
	if(pi==NULL)return 0;
	Elem * no = (Elem *) malloc(sizeof(Elem));
	no->dados=al;
	no->prox=(*pi);
	(*pi)=no;
	return 1;
}


int remove_pilha(Pilha *pi ){
	if(pi==NULL || (*pi)==0) return 0;
	Elem *no =*pi;
	*pi=(*pi)->prox;
	free(no);
	return 1;
}

int consulta_pilha(Pilha *pi, struct aluno *al){
	if(pi!=NULL && (*pi)!=0){
		*al=(*pi)->dados ;
		return 1;
	}

}