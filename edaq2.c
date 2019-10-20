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



int main(){

stack *pilha=newStack();
stack *pilhaAux=newStack();
queue * fila =cria_fila(40);
cell*cellAux;
	/*FILE *f;
	f=fopen(argv[2],"r");
	int a,b,tam=0, soma=0,cont=0;

	int k = atoi(argv[1]);

	if(fila!=NULL){
		while (!feof(f) ){
			fscanf(f, "%d", &a);
			pushFila(fila,a);
		}
	}
	int n = fila->size;
	int vetor[n];
	cell * aux = fila->inicio;
	for(int i =0 ; i <fila->size; i++){
		vetor[i]= aux->elemento;
		aux=aux->next;

	}
	
	// COLOQUE DO MAIOR PARA O MENOR
	int ordem;
	for(int i=0; i<-1;i++){
	 	for (int j=i+1;j<n; j++){ 
	 		if(vetor[i]>vetor[j]){
	 			ordem=vetor[i];
	 			vetor[i]=vetor[j];
	 			vetor[j]=ordem;
	 		}
	 	 }
	 }
	*/

	int n =5;
	int k =10;
	int vetor[n];
	vetor[0]=10;
	vetor[1]=2;
	vetor[2]=5;
	vetor[3]=4;
	vetor[4]=3;
	int itera =0;

	 for(int i =0 ; i < n ;i++){
	 	int soma=0;
	 	itera=0;
	 	if(vetor[i]==k){
			soma=k;
			pushPilha(pilha, k);
			printPilha(pilha);
			popPilha(pilha);
			soma=0;
			continue;
		}
		else if( (k%vetor[i])==0){
			soma=0;
			while(soma<k){
				itera++;
				soma+=vetor[i];
				pushPilha(pilha,vetor[i]);
			}
			printPilha(pilha);
			for(int m =0 ; m < itera; m++){
				popPilha(pilha);
			}
			printf("%d\n",pilha->tamanho );
			soma=vetor[i];
			pushPilha(pilha, vetor[i]);
		}
		else{
			soma=vetor[i];
			pushPilha(pilha, vetor[i]);
		}
		printf("inicio %d %d\n",soma,vetor[i] );
		for(int j =i ; j < n ; j++){
			int retira =0;
			printf("soma :%d valor %d indice :i %d j %d valor[j] : %d\n",soma,vetor[i],i, j, vetor[j] );
			while(soma<k){
				printf("entrou\n");
				soma+=vetor[j];
				pushPilha(pilha,vetor[j]);
				retira++;
					//printf("%d\n soma:",soma );
				if(soma>k){
					soma-=vetor[j];
					//printPilha(pilha);
					//printf("maior : \n");
					popPilha(pilha);
					break;
				}
				else if(soma==k){
					printf("igual ");
					printPilha(pilha);
					popPilha(pilha);
					soma-=vetor[j];
					break;
				}
			}
		}
	 	
	}



	return 0;
	//fclose(f);
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
			//popPilha(s);
			 printf(",");
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

