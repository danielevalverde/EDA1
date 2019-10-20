#include <stdlib.h>
#include "List.h"
#include "Bool.h"

typedef struct stack
{
	cell* top;
} stack;

//Cabeçalho
stack* stack_new ();
bool stack_push (stack* s, int x);
cell* stack_pop (stack* s);
bool stack_isEmpty (stack* s);


stack* stack_new () {

	stack* s = malloc(sizeof(stack));

	if (s) {

		s->top = NULL;
	}

	return s;
}

bool stack_push (stack* s, int x) {

	if (s) {

		cell* cellAux = malloc(sizeof(cell));

		if (cellAux) {

			cellAux->element = x;
			cellAux->next = NULL;

			if (stack_isEmpty(s) == FALSE) {

				cellAux->next = s->top;
			}

			s->top = cellAux;

			return TRUE;
		}
	}

	return FALSE;
}

cell* stack_pop (stack* s) {
	
	if (s) {

		if (stack_isEmpty(s) == FALSE) {

			cell* topCell = s->top;
			s->top = s->top->next;

			topCell->next = NULL;

			return topCell;
		}
	}

	return NULL;
}

bool stack_isEmpty (stack* s) {

	if (s->top) {

		return FALSE;
	}

	return TRUE;
}	
