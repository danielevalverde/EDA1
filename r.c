#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cell cell;
typedef struct stack stack;
typedef struct fila queue;
typedef enum {FALSE, TRUE} bool;
struct cell{
	int elemento;
	cell* next;
};

 struct stack{
	cell* top;
	int tamanho;
};
struct fila {
	struct cell *inicio;
	struct cell *final;
	int size, maxsize;
};


// Chama funções 
stack* newStack ();
int pushPilha (stack* s, int x);
cell* popPilha (stack* s);
void freePilha(stack *s);
void printPilha(stack *s);
queue *cria_fila(int k);
int pushFila(queue* q,int x);
cell *popFila(queue *q);
void recursao(int vetor[], stack * s, int soma, int last, int valor, int tam ); 


int main(int argc , char *argv[]){

stack *pilha=newStack();
stack *pilhaAux=newStack();
queue * fila =cria_fila(40);
cell*cellAux;
	
	int n = 4;
	int vetor[n];
	vetor[0]=3;
	vetor[1]=4;
	vetor[2]=8;
	vetor[3]=5;
	int soma =0;
	int k =10;
	int ordem;
	for(int i=0; i<n-1;i++){
	 	for (int j=i+1;j<n; j++){ 
	 		if(vetor[i]>vetor[j]){
	 			ordem=vetor[i];
	 			vetor[i]=vetor[j];
	 			vetor[j]=ordem;
	 		}
	 	 }
	 }
	//pilha->top=fila->inicio;
	int last ;
	int pos=0;
	recursao(vetor, pilha, soma , last, k, n);

	return 0;
	//fclose(f);
}



void recursao ( int vetor[], stack* pilha, int soma, int last, int k, int tam ){
	if(k == last){
		printf("%d\n",last );
		soma-=last;
		return;
	}
	
    else if(soma >k){
		soma -= last;
		popPilha(pilha);
		return;
    }
  else if(soma==k){
		soma -= last;
		printPilha(pilha);
		//popPilha(pilha);
		return;
  }
  for (int i = 0; i < tam; i++) {
		last = vetor[i];
		soma+=last;
		pushPilha(pilha, last);
		recursao(vetor,pilha, soma , last, k, tam);
		if(i == tam-1){
			soma -= last;
			popPilha(pilha);
		}
	}
}

stack* newStack(){

	stack* s=(stack*) malloc(sizeof(stack));
	if(s){
		s->top = NULL;
	}
	return s;
}

int pushPilha(stack* s, int x) {
	if(s){
		cell* c =(cell*) malloc(sizeof(cell));
		if (c){
			c->elemento = x;
			c->next = s->top;
			s->top = c;
			s->tamanho++;
			return 1;
		}
	}
	return 0;
}

cell* popPilha(stack* s){
	if(s){
		if (s->top!=NULL) {
			cell* c = s->top;
			s->top = s->top->next;
			c->next = NULL;
			s->tamanho--;
			return c;
		}
	}

	return NULL;
}

void printPilha( stack *s){
	if(s->top!=NULL){
		cell *aux = s->top;
		 printf("{");
		while(aux!=NULL){
			printf("%d ",aux->elemento);
			aux=aux->next;
			if(aux!=NULL)
				printf(", ");
	
		}
		printf("} ");
		printf("\n");
	}

	
}


void freePilha(stack *s){
	while(s->top!=NULL){
		cell *aux=s->top;
		s->top=s->top->next;
		free(aux);
	}
	free(s);
}



queue* cria_fila(int sizeMax){
	queue *fi=(queue *)malloc(sizeof(queue));
	if(fi==NULL) return 0;
	fi->inicio=NULL;
	fi->final=NULL;
	fi->size=0;
	fi->maxsize=sizeMax;
	return fi;
}

int pushFila(queue* q, int x) {
		cell* c= (cell*)malloc(sizeof(cell));
		if (c) {
			c->elemento = x;
			c->next = NULL;
			if (q->inicio ==NULL) {
				q->inicio = c;
			}
			else {
				q->final->next = c;
			}
			q->final = c;
			q->size++;
			return 1;
		}
		return 0;
	}



cell* popFila (queue* q) {
	cell *c= q->inicio;
	if (q->inicio!=NULL) {
		q->inicio = q->inicio->next;
		q->size--;
		if (q->inicio==NULL) {
			q->final = NULL;
		}
		c->next = NULL;
		return c;
	}

	return NULL;
}

bool isEmpty (queue* q) {
	if (q->inicio == NULL)
		return TRUE;
	return FALSE;
}

bool isFull (queue* q) {
	if (q->size == q->maxsize) 
		return TRUE;
	return FALSE;
}

