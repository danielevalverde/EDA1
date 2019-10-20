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
	int size;
};


// Chama funções 
stack* newStack ();
int pushPilha (stack* s, int x);
cell* popPilha (stack* s);
void freePilha(stack *s);
void printPilha(stack *s);
queue *cria_fila();
int pushFila(queue* q,int x);
cell *popFila(queue *q);



int main(int argc, char const *argv[]){

stack *pilha=newStack();
stack *pilhaAux=newStack();
queue * fila =cria_fila();
cell*cellAux;
FILE *f;
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

	int itera;
	 for(int i =0 ; i < n ;i++){
	 	int soma=0;
	 	itera=0;
	 	int retira=0;
	 	int valor=0;
	 	int controle =0;
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
				retira++;
				soma+=vetor[i];
				pushPilha(pilha,vetor[i]);
			}
			
			printPilha(pilha);
			for(int m =0 ; m < retira; m++){
				popPilha(pilha);
			}
			//printf("%d\n",pilha->tamanho );
			soma=0;
		}
		else{
			//printf("entrou %d\n", vetor[i]);
			soma=vetor[i];
			pushPilha(pilha, vetor[i]);
			itera=1;
			while(soma<k){
				soma+=vetor[i];
				pushPilha(pilha, vetor[i]);
				itera++;
			
			}
			itera++;
			valor=vetor[i];
			//printf("%d\n",soma );
		}
		
		while(controle<itera){
			if((k%vetor[i]) !=0){
				popPilha(pilha);
				controle++;
				soma-=valor;
				if(soma+vetor[i+1]>k){
					popPilha(pilha);
					soma-=valor;
					controle++;
					if( i!=n-1)
						i++;
					
				}
			}
			for( int j = i ; j < n ; j++){
				if(soma==k){
					printPilha(pilha);
					popPilha(pilha);
					//printf("soma \n");
				}
				else if(soma>k){
					popPilha(pilha);
					soma-=vetor[j];					
				}
				else{
					soma+=vetor[j];
					pushPilha(pilha, vetor[j]);
					if(soma==k){
						printPilha(pilha);
						if(j!=n-1){
							j++;controle++;
						}
					}
				}
				if(j==n-1){
					freePilha(pilha);
				}
			}

		}
	
	 	
	}

	return 0;
	fclose(f);
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
			// printf(",");
		}
		printf("} ");
		printf("\n");
	}
}

void freePilha(stack *s){
	while(s->top!=NULL){
		s->top=NULL;
	}

}



queue* cria_fila(int sizeMax){
	queue *fi=(queue *)malloc(sizeof(queue));
	if(fi==NULL) return 0;
	fi->inicio=NULL;
	fi->final=NULL;
	fi->size=0;
	//fi->maxsize=sizeMax;
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


