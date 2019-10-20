#include <stdlib.h>
#include <stdio.h>



typedef struct no arvore;
//typedef struct no* arvore;

struct no{
	int info;
	int alt;
	struct no *esq;
	struct no *dir;
};


arvore* cria_arvore(){
	arvore * raiz= (arvore*) malloc(sizeof(arvore));
	if(raiz!=NULL)
		raiz=NULL;
	//*raiz=NULL;
	return raiz;
}

void free_no( arvore * a){
	if(a==NULL)
		return;
	free_no(a->esq);
	/* vai chamando até encontrar a vazio
	 a é vazio ?
	 Então o fluxo da função começa a acontecer 
	*/
	free_no(a->dir);
	free(a);
	a=NULL;
}

void free_arv(arvore * raiz){
	if(raiz==NULL)
		return;
	free_no(raiz);
	free(raiz);
}

int isEmpty(arvore *raiz){
	if(raiz==NULL)
		return 1;
	else
		return 0;

}


int height( arvore * no){
	if(no==NULL)
		return -1;
	else
		return no->alt;
}

int fatorBalanceamento(arvore* no){
	return labs(height(no->esq) - height(no->dir));
}

int maior(int x, int y){
	if(x>y)
		return x;
	else
		return y;
}


void RotacaLL(arvore *raiz){
	no* no;
	no=raiz->esq;
	raiz->esq=no->dir;
	no->dir=raiz;
	raiz->alt=maior(height(raiz->esq),height(raiz->dir)+1);
	raiz=no;
}


void RotacaRR(arvore *raiz){
	no* no;
	no=raiz->dir;
	raiz->dir=no->esq;
	no->dir=raiz;
	raiz->alt=maior(height(raiz->esq),height(raiz->dir)+1);
	raiz=no;
}

void RotacaoLR(arvore *raiz){
	RotacaoRR(raiz->esq);
	RotacaLL(raiz);
}