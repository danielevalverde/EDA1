#include <stdlib.h>
#include <stdio.h>



/*4 casos
	qla vazia - Feito
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

typedef enum {FALSE, TRUE} bool;

queue *cria_fila(int k);
int push(queue* q,int x);
cell *pop(queue *q);
bool isEmpty (queue* q);
bool isFull (queue* q);
cell *consulta_fila(queue *q, int x);
void printFila(queue *q);
void freeFila(queue *q);



int main(){
	int vetor[9] = {2, 1, 10, 4, 5, 1, 4, 1, 2};
	//int teste[4]={3, 4 , 6, 8};
	int cont = 0;
	int k =3,x;
	queue * fila =cria_fila(k);
	queue * filaFinal =cria_fila(k);
 

 
	for( int i =0 ; i < 9; i++){
	
		push(fila,vetor[i]);
	}
	
	//printFila(fila);
	//printFila(fila2);
	cell*aux;
	cell *e=fila->inicio;

	printFila(fila);
	//cell* teste =consulta_fila(fila,5);
	//printf("%d\n",teste->elemento );
	

	for(int i =0; i< 9; i++){
		x=e->elemento;
		//printf("%d\n",x );
		e=e->next;		

		if(isEmpty(filaFinal)==TRUE){
			push(filaFinal,x);
			cont++;
		}
		else if(filaFinal->final->elemento == x){
		    continue;
		 }
		else{
			aux=consulta_fila(filaFinal,x);
			if(aux!=NULL){
				if(filaFinal->inicio->elemento==x){
					push(filaFinal,x);
					pop(filaFinal);
				}
 				else{
	 				push(filaFinal,aux->next->elemento);
					aux->next=aux->next->next;
					filaFinal->size--;
 				}

 			}
			else{
				if(isFull(filaFinal)){
					pop(filaFinal);
				}
				push(filaFinal,x);
					cont++;
			}

		}
		
	}
	cell* num = filaFinal->inicio ;
	for(int i = 0 ;i < filaFinal->size;i++){
		vetor[i]=num->elemento;
		num=num->next;
	}
	printf("{ ");
	for(int i = filaFinal->size-1 ;i >=0;i--){
		printf("%d",vetor[i]);
		if(i>0)
		printf(", " );

	}
	printf("} ");
	printf("%d", cont);
	printf("\n");

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


void printFila( queue *q ){
	int c =0;
	if(isEmpty(q)==FALSE){
		cell *aux = q->inicio;
		 printf("{");
		while(aux!=NULL){
		c++;
		printf( " %d", aux->elemento);
		aux = aux->next;
		if(c<q->size){
			printf(",");
		}
		
	}

		printf("} ");
		printf("\n");
	}
	else{
		printf("Fila Vazia\n");
	}
}



	
cell* consulta_fila(queue *fi, int x){
	if(fi==NULL || fi->inicio==NULL)
		return NULL;
	cell* anterior,  *atual = fi->inicio;
	while (atual->next!= NULL) {
		if(atual->elemento != x){
        anterior = atual;	
		atual=atual->next;
      }
      else
      	break;
		
	}
	if(atual->elemento==x){
		if(atual->elemento==fi->inicio->elemento)
			return atual;
		if(atual->elemento==fi->final->elemento)
			return NULL;
		else
			return anterior;
	}
	return NULL;	
}

