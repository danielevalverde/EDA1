#include <stdlib.h>
#include <stdio.h>


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

queue *new_queue(int k);
int push(queue* q,int x);
cell *pop(queue *q);
bool isEmpty (queue* q);
bool isFull (queue* q);
cell *searchElement(queue *q, int x);
void printQueue(queue *q);


int main(int argc, char const *argv[]){

	FILE *f;
	f=fopen(argv[2],"r");

	int k = atoi(argv[1]);
	int a , x;
	queue * fila =new_queue(k);
	queue * filaFinal =new_queue(k);
	if(fila!=NULL){
		while (!feof(f) ){
			fscanf(f, "%d", &a);
			push(fila,a);
		}
	}

	int vetor[fila->size];
	int cont = 0;
	cell*aux;
	cell *e=fila->inicio;
	
	for(int i =0; i< fila->size; i++){
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
			aux=searchElement(filaFinal,x);
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
	printf("\n%d", cont);
	printf("\n");

}

queue* new_queue(int sizeMax){
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

cell* pop(queue* q){
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

bool isEmpty(queue* q){
	if (q->inicio == NULL)
		return TRUE;
	return FALSE;
}

bool isFull(queue* q){
	if (q->size == q->maxsize) 
		return TRUE;
	return FALSE;
}


void printQueue( queue *q ){
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

	
cell* searchElement(queue *q, int x){
	if(q==NULL || q->inicio==NULL)
		return NULL;
	cell* anterior,  *atual = q->inicio;
	while (atual->next!= NULL) {
		if(atual->elemento != x){
        anterior = atual;	
		atual=atual->next;
      }
      else
      	break;
		
	}
	if(atual->elemento==x){
		if(atual->elemento==q->inicio->elemento)
			return atual;
		if(atual->elemento==q->final->elemento)
			return NULL;
		else
			return anterior;
	}
	return NULL;	
}

