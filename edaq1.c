#include <stdlib.h>
#include <stdio.h>



/*4 casos
	fila vazia - Feito
	O elemento não está na fila  - Feito
	O elemento está inicio da fila - Feito
	"     "         "   final da fila - Feito
	O elemento está em um lugar qualquer da fila
	// você vai usar o cache pra saber quando a fila está cheia e poder remover o elemento inicial
	// testar funções separadas e por pra retornar o elemento e imprimir a fila

*/

typedef struct fila queue;

struct fila {
	struct cell *inicio;
	struct cell *final;
	int size, maxsize;
};

typedef struct cell cell;
struct cell{
	int elemento;
	struct cell *next;
};


queue *cria_fila(int k);
int push(queue* q,int x);
cell *pop(queue *q);
int isEmpty (queue* q);
int isFull (queue* q);
cell *consulta_fila(queue *q, int x);
void printFila(queue *q);



int main(int argc , char *argv[]){
	int cont = 0;

	FILE *f;
	f=fopen(argv[2],"r");

	int k = atoi(argv[1]);

	queue * fila =cria_fila(k);
	queue * filaAux =cria_fila(k);
	int a ;
	if(fila!=NULL){
		while (!feof(f) ){
			fscanf(f, "%d", &a);
			push(fila,a);
		}
	}

	int controle=0;
	cell * aux;
	cell * auxFila;
	auxFila=fila->inicio;
	int x = auxFila->elemento;
	
	while(controle<=fila->size){
		controle++;		
		//caso 1: fila vazia
		if(isEmpty(filaAux)){
			push(filaAux,auxFila->elemento);
			cont++;
		}
		else if(!isEmpty(filaAux)){
			//caso 2:  não está vazia
			if(consulta_fila(filaAux,x)==NULL){
				// caso 2.1 - fila não está cheia 
				if(isFull(filaAux)==0){
					push(filaAux,x);
					cont++;
				}
				else{
				// caso 2.2 - fila está cheia
					pop(filaAux);
					push(filaAux,x);
					cont++;
				}	
			}
			else{
				// caso 2.3 - A fila não está vazia e o elemento já está na fila
				aux=consulta_fila(filaAux,x);
				aux->next=aux->next->next;
				push(filaAux,x);
			}
		
		}
	}

	printFila(filaAux);
	
	fclose(f);

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

int push(queue* q, int x) {
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



cell* pop (queue* q) {
	cell *c= q->inicio;
	if (q->inicio!=NULL) {
		q->inicio = q->inicio->next;
		if (q->inicio==NULL) {
			q->final = NULL;
		}
		c->next = NULL;
		return c;
	}

	return NULL;
}

int isEmpty (queue* q) {
	if (q->inicio == NULL)
		return 1;
	return 0;
}

int isFull (queue* q) {
	if (q->size == q->maxsize) 
		return 1;
	return 0;
}

cell* consulta_fila(queue *fi, int x){
	if(fi==NULL || fi->inicio==NULL)
		return NULL;
	cell* anterior,  *atual = fi->inicio;
	while (atual->next!= NULL || atual->elemento!=x) {
		anterior = atual;	
		atual=atual->next;
	}
	if(atual->elemento==x);
		return anterior;
	return NULL;
	
}

void printFila( queue *q ){
	if(q->inicio!=NULL){
		cell *aux = q->inicio;
		 printf("{");
		while(aux!=NULL){
			printf("%d ",aux->elemento);
			aux=aux->next;
			 printf(",");
			pop(q);
		}
		printf("} ");
		printf("\n");
	}
}
