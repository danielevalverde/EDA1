#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cell cell;
typedef struct stack stack;
typedef enum {FALSE, TRUE} bool;
struct cell{
	int elemento;
	cell* next;
};

 struct stack{
	cell* top;
	int tamanho;
};


// Chama funções de pilha
stack* newStack ();
int push (stack* s, int x);
cell* pop (stack* s);
void freePilha(stack *s);
void printPilha(stack *s);
int recursao

// TENTE ORDENAR ESSE BAGULHO
int main(){

	stack *pilha=newStack();
	int soma =0;
	int k =10;
	int n = 4;
	int top;
	int vetor[n];
	vetor[0]=3;
	vetor[1]=4;
	vetor[2]=5;
	vetor[3]=8;

	for( int i =0 ; i<n;i++){
		soma=0;
		if( (k%vetor[i])==0 ){
			while(soma<k){
				soma+=vetor[i];
				push(pilha,vetor[i]);

			}
			printPilha(pilha);
			soma=0;
		}
		for(int j =i ; j<n;j++){
			while(soma<k){
				soma+=vetor[j];
				push(pilha, vetor[i]);
			}
			if(soma==k){
				printPilha(pilha);
				continue;
			}
			else if(soma>k){
				top=pilha->top->elemento;
				pop(pilha);
				continue;
			}
			if(top!=vetor[j] || pilha->size>){
				while(soma!=k || soma <k){
					soma+=vetor[j];
					push(vetor[j]);
				}
				if(soma>k){
					while(top==vetor[j]){
						pop(pilha);
					}
					pop(pilha);
				}
			}
		}
	}
	
	//printf("%d\n",soma);
	//printf("%d\n",soma);
	//	printf("%d\n",soma);
	
	return 0;
	
}


stack* newStack(){

	stack* s=(stack*) malloc(sizeof(stack));
	if(s){
		s->top = NULL;
	}
	return s;
}

int push(stack* s, int x) {
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

cell* pop(stack* s){
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
			 printf(",");
			pop(s);
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



