#include <stdlib.h>
#include <stdio.h>

struct aluno
{
	 int matricula;
	 char nome[40];
	 float n1, n2, n3;
};

typedef struct fila Fila;

struct fila {
	struct elemento *inicio;
	struct elemento *final;
};

struct elemento{
	//struct aluno dados;
	int elemento;
	struct elemento *prox;
};

typedef struct elemento Elem;


Fila* cria_fila(){
	Fila *fi=(Fila *)malloc(sizeof(Fila));
	if(fi==NULL) return 0;
	fi->inicio=NULL;
	fi->final=NULL;
	return fi;
}

int remove_fila(Fila *fi){
	if(fi==NULL)return 0;
	Elem *no;
	while(fi->inicio!=NULL){
		no=fi->inicio;
		fi->inicio=fi->inicio->prox;
		free(no);
	}
	free(fi);
}


int tamanho_fila(Fila *fi){
	if(fi==NULL)return 0;
	int cont =0;
	Elem * no = fi->inicio;
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}

int iserir(Fila*fi, struct aluno al){
	if(fi==NULL)return 0;
	Elem *no=(Elem *)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	no->prox=NULL;
	if(fi->inicio==NULL){
		fi->inicio=no;
	}
	else
		fi->final->prox=no;
	fi->final=no;
}

int remover_fila(Fila *fi){
	if(fi==NULL || fi->inicio==NULL) return 0;
	Elem  *aux=fi->inicio;
	fi->inicio=fi->inicio->prox;
	if(fi->inicio==NULL)
		fi->final=NULL;
	free(aux);
	return 1;
}

int consulta_fila(Fila*fi, struct aluno *al){
	Elem* cellAux = fi->inicio;
    while (cellAux->prox != NULL) {
      if(cellAux->prox->elemento != x){
        cellAux = cellAux->prox;
      }

}