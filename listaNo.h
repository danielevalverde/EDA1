#include <stdlib.h>
#include <stdio.h>

/*

Lista com nó descritor: Trata-se da uma variação da lista dinamica
Pode ser usado em listas simples, duplamente encadeadas ou circular
usa um nó especial chamado de descritor para armazenar diversas informações
sobre a lista
O nó descritor substitui o ponteiro para ponteiro que indica o inicio da lista
Ele permite armazenar informações como:
ponteiro para o inicio da lista
ponteiro para o final da lista
tamanho da lista

*/


struct aluno
{
	 int matricula;
	 char nome[40];
	 float n1, n2, n3;
};

typedef struct descritor Lista;

struct elemento {
	struct aluno dados;		
	struct elemento *prox;// tem o endereço do elemento
};

typedef struct elemento Elem;

struct descritor {
	struct elemento *inicio;
	struct elemento *final;// tem o endereço do elemento
	int qtd;
};

Lista *cria_lista(){
	Lista *li = (Lista*)malloc(sizeof(Lista));
	if(li!=NULL){
		li->inicio=NULL;
		li->final=NULL;
		li->qtd=0;
	}
	return li;
}

void libera_lista(Lista* li){
	if(li!=NULL){
		Elem *no;
		while(li->inicio!=NULL){
			no=li->inicio;
			li->inicio=li->inicio->prox;
			free(no);
		}
		free(li);
	}
}

int tamanho_lista(Lista *li){
	if(li==NULL)
		return 0;
	return li->qtd;
}

int insere_inicio(Lista *li, struct aluno al){
	if(li==NULL) return 0;
	Elem *no=(Elem *) malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=li->inicio;// faz no apontar para onde li->inicio apontava(inicio da lista)
	if(li->inicio==NULL)// se li apontar para zero, então só á no na lista e li->final vai apontar pro último e unico elemento
		li->final=no;
	li->inicio=no;
	li->qtd++;
	return 1;
}


int insere_end(Lista *li, struct aluno al){
	if(li==NULL) return 0;
	Elem *no=(Elem *) malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=NULL;// 
	if(li->inicio==NULL)// se li apontar para zero, então só há no na lista e li->final vai apontar pro último e unico elemento
		li->inicio=no;
	else
		li->final->prox=no;//faz o ultimo elemento(final->prox)apontar para nó
	// li->final pega o endereço do último elemento .
	//li->final->prox pega pra onde o último elemento aponta
	li->final=no;// faz o nó descritor apontar para nó
	li->qtd++;
	return 1;
}


int remove_inicio( Lista *li){
	if (li==NULL || li->inicio==NULL) return 0;
	Elem *no = li->inicio;
	li->inicio=no->prox;
	free(no);
	if(li->inicio==NULL)
		li->final=NULL;// 
	li->qtd--;
	return 1;
}


int remove_end( Lista *li){
	if (li==NULL || li->inicio==NULL) return 0;
	Elem *ant,  *no = li->inicio;
	while(no->prox!=NULL){
		ant=no;
		no=no->prox;
	}
	if(no==li->inicio){
		li->inicio=	NULL;
		li->finaL=NULL;
	}
	else{
		ant->prox=no->prox;
		li->final=ant;
	}
	free(no);
	li->qtd--;
	return 1;
}
