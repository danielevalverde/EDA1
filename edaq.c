#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cell cell;
typedef struct stack stack;
struct cell{
	int element;
	cell* next;
};

 struct stack{
	cell* top;
} ;


int main(int argc , char *argv[]){

// Chama funções de pilha
stack* newStack ();
int push (stack* s, int x);
cell* pop (stack* s);
void freePilha(stack *s);
void printPilha(stack *s);

stack *pilha=newStack();
stack *pilhaAux=newStack();
cell*cellAux;

	FILE *f;
	f=fopen(argv[2],"r");
	int a,b,tam=0, soma=0,cont=0 ;

	int k = atoi(argv[1]);

	if(pilha!=NULL){
		while (!feof(f) ){
			fscanf(f, "%d", &a);
			push(pilha,a);
			tam++;
		}
	}

	if(pilha!=NULL || pilha->top!=NULL){
		cellAux=pilha->top;
		soma+=pilha->top->element;
		push(pilhaAux,cellAux->element);

		while(cellAux->next!=NULL){
			soma+=cellAux->element;
			push(pilhaAux,cellAux->element);
			cellAux=cellAux->next;

			if(soma==k){
				printPilha(pilhaAux);
				cellAux=pilha->top->next;
				pop(pilha);
				soma=cellAux->element;
				freePilha(pilhaAux);
				push(pilhaAux,cellAux->element);


			}
			
		}
	}
	printf("%d\n",soma);
	printf("%d\n",soma);
		printf("%d\n",soma);
	
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
			c->element = x;
			c->next = NULL;
			if (s->top!=NULL) {
				c->next = s->top;
			}
			s->top = c;
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
			return c;
		}
	}

	return NULL;
}

void printPilha( stack *s){
	if(s->top!=NULL){
		cell *aux = s->top;
		while(aux!=NULL){
			printf("%d ",aux->element);
			aux=aux->next;
			pop(s);
		}
		printf("\n");
	}
}

void freePilha(stack *s){
	if(s->top!=NULL){
		s->top=NULL;
	}
}


