#include <stdlib.h>
#include <stdio.h>

typedef struct cell cell;
typedef struct stack stack;
struct cell{
	int element;
	cell* next;
};

 struct stack{
	cell* top;
};

stack* newStack ();
int push (stack* s, int x);
void pop (stack* s);
cell* top (stack* s);
void freeStack(stack *s);
void printStack(stack *s);
void findSum(int somaAteAgora, int valorSomado, stack* pilhaAtual);

int numeroDaSequencia;
int somaTotal;
int entrada[] = {3, 4, 8, 5};
// int entrada[] = {1, 2};

int main(int argc, char const *argv[]) {
	stack* pilhaAtual = newStack();
	somaTotal = 10;
  int somaAteAgora = 0;
	int valorSomado = 0;
  findSum(somaAteAgora, valorSomado, pilhaAtual);
  return 0;
}

void findSum(int somaAteAgora, int valorSomado, stack* pilhaAtual){
  if(somaAteAgora > somaTotal){
		somaAteAgora -= valorSomado;
		pop(pilhaAtual);
		return;
  }
	else if(somaAteAgora == somaTotal){
		printStack(pilhaAtual);
		printf("achou\n");
		somaAteAgora -= valorSomado;
		pop(pilhaAtual);
		return;
  }
		for (int i = 0; i < sizeof(entrada)/sizeof(int); i++) {
			numeroDaSequencia = entrada[i];
			push(pilhaAtual, numeroDaSequencia);
			findSum((somaAteAgora + numeroDaSequencia), numeroDaSequencia, pilhaAtual);
			if(i == sizeof(entrada)/sizeof(int)-1){
				somaAteAgora -= valorSomado;
				pop(pilhaAtual);
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

cell* top(stack* s){
	if(s){
		cell* c = s->top;
		return c;
	}
	return NULL;
}

void pop(stack* s){
	if(s){
		if (s->top != NULL) {
			cell* c = s->top;
			s->top = s->top->next;
			free(c);
		}
	}
}

void printStack( stack *s){
	if(s->top!=NULL){
		cell *aux = s->top;
		printf("(");
		while(aux!=NULL){
			printf("%d ",aux->element);
			aux=aux->next;
		}
		printf(")");
	}
}

void freeStack(stack *s){
	while(s->top!=NULL){
		cell *aux=s->top;
		s->top=s->top->next;
		free(aux);
	}
	free(s);
}