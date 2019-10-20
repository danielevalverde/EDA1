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
};

// Chama funções de pilha
stack* newStack ();
int push (stack* s, int x);
cell* pop (stack* s);
void freePilha(stack *s);
void printPilha(stack *s);


int main(int argc , char *argv[]){

stack *pilha=newStack();
stack *pilhaAux=newStack();
cell*cellAux;

	//
/*
	4 casos
	fila vazia
	O elemento não está na fila
	O elemento está inicio da fila
	"     "         "   final da fila 
	O elemento está em um lugar qualquer da fila
	// você vai usar o cache pra saber quando a fila está cheia e poder remover o elemento inicial



*/
	for(int i =0 ; i<15;i++){

	}

	

	

	printPilha(pilha);

	//printf("%d\n",soma);
	//printf("%d\n",soma);
	//	printf("%d\n",soma);
	
	return 0;
	freePilha(pilhaAux);
	freePilha(pilha);
	fclose(f);
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
			c->next = s->top;
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
		 printf("{");
		while(aux!=NULL){
			printf("%d ",aux->element);
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



