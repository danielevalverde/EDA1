// 
// IMPLEMENTAÇÃO DE LISTA EM C
//


#include <stdlib.h>
#include <stdio.h>

typedef struct cell {

	union {

		int element;
		struct cell* tail;
	};

	struct cell* next;

} cell;

cell* newList () {

	cell* c = malloc(sizeof(cell));

	if (c) {

		c->next = NULL;
		c->tail = NULL;
	}

	return c;
}

cell* list_insert_begin (cell* lHead, int value) {

	cell* c = malloc(sizeof(cell));	

	if (c) {

		c->element = value;
		c->next = lHead->next;
		lHead->next = c;

		if (c->next == NULL) {
			lHead->tail = c;
		}		
	}

	return lHead;
}

cell* list_insert_end (cell* lHead, int value) {

	cell* c = malloc(sizeof(cell));	

	if (c) {

		c->element = value;
		lHead->tail->next = c;
		lHead->tail = c;
	}

	return lHead;
}

cell* list_insert (cell* lHead, int value) {

	cell* cellAux = lHead;

	cell* c = malloc(sizeof(cell));	

	if (c) {

		c->element = value;

		while (cellAux->next && cellAux->next->element < value) {

			cellAux = cellAux->next;	
		}

		c->next = cellAux->next;
		cellAux->next = c;

		if (c->next == NULL) {
			lHead->tail = c;
		}		
	}

	return lHead;
}

cell* list_deleteAt (cell* lHead, int index) {

	cell* cellAux = lHead;

	for (int i = 0; i < index; ++i)
	{
		if (cellAux->next == NULL) {
			printf("%s\n", "Index out of range!");
			return lHead;
		}

		cellAux = cellAux->next;
	}

	cell* cellToFree = cellAux->next;

	cellAux->next = cellAux->next->next;

	free(cellToFree);

	if (cellAux->next == NULL) {
		lHead->tail = cellAux;
	}

	return lHead;
}

int list_first (cell* l) {

	return l->next->element;
}

int list_last (cell* l) {

	return l->tail->element;
}

cell* list_concat(cell* l1, cell* l2)  {

	l1->tail->next = l2->next;

	l1->tail = l2->tail;

	return l1;
}