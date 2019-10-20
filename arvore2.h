#include <stdio.h>
#include <stdlib.h>

typedef struct no arvore;

struct no{
	int info;
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

int height(arvore *raiz){
	if (raiz==NULL)
		return 0;
	int height_left=height(&(*raiz->esq));
	int height_right=height(&(*raiz->dir));
	if(height_right>height_left)
		return height_right+1;
	/*	
		quando chega no nó folha, ele compara ambos os lados(direita e equerda)
		como ambos dão zero, ele retorna 1 ;
		aí ele sobre pro nó anterior e vai pra direita, repete o mesmo procedimento e volta
	*/
	else
		return height_left+1;
}


int totalNo(arvore *raiz){
	if(raiz==NULL)
		return 0;
	int height_left =totalNo(&(*raiz->esq));
	int height_right=totalNo(&(*raiz->dir));
	
	return (height_right + height_left +1);
}

void preOrdem(arvore *raiz){
	if(raiz==NULL)
		return ;
	printf("%d\n",raiz->info );
	preOrdem(raiz->esq);
	preOrdem(raiz->dir);
}

void emOrdem(arvore *raiz){
	if(raiz==NULL)
		return ;
	emOrdem(raiz->esq);
	printf("%d\n",raiz->info );
	emOrdem(raiz->dir);
}

void posOrdem(arvore *raiz){
	if(raiz==NULL)
		return ;
	posOrdem(raiz->esq);
	posOrdem(raiz->dir);
	printf("%d\n",raiz->info );
}

int insert( arvore *raiz, int valor){
	if(raiz==NULL)
		return 0;
	arvore *novo = (arvore*)malloc(sizeof(arvore));
	if(novo==NULL)
		return 0;
	novo->info=valor;
	novo->dir=NULL;
	novo->esq=NULL;

	if(raiz==NULL)
		raiz=novo;
	else{
		arvore *atual= raiz;
		arvore *ant = NULL;
		while(atual!=NULL){
			ant=atual;
			if(valor==atual->info){
				free(novo);// não aloca elementos repetidos
				return 0;
			}
			if(valor>atual->info)
				atual=atual->dir;
			else
				atual=atual->esq;
		}
		if(valor>ant->info)
			ant->dir=novo;
		else
			ant->esq=novo;
	}
}

arvore * remove_atual(arvore *atual ){
	arvore * no1, *no2;
	if(atual->esq==NULL){
		no2=atual->dir;
		free(atual);
		return no2;
	}

	no1=atual;
	no2=atual->esq;
	while(no2->dir!=NULL){
		no1=no2;
		no2=no2->dir;
	}
	if(no1!=atual){
		no1->dir=no2->esq;
		no2->esq=atual->esq;
	}
	no2->dir=atual->dir;
	free(atual);
	return no2;
}
int remove_arvore(arvore *raiz, int valor){
	if(raiz==NULL) return 0;
	no*ant = NULL, *atual = raiz;
	while(atual!=NULL){
		if(valor==atual->info){ 
			if(atual==raiz)
				raiz=remove_atual(atual);
			else{
				if(ant->dir==atual)
					ant->dir=remove_atual(atual);
				else
					ant->esq=remove_atual(atual);	
			}
			return 1;
		}
		ant=atual;
		if(valor>atual->info)
			atual=atual->dir;
		else
			atual=atual->esq;

	}

}

int consulta_arvore( arvore *raiz, int valor){
	if(raiz==NULL)
		return 0;
	no * atual = raiz;
	while(atual!=NULL){ 
		if(valor==atual->info)
			return 1;
		if(valor>atual->info)
			atual=atual->dir;
		else
			atual=atual->esq;
	}
	return 0;
}