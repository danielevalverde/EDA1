// 
// IMPLEMENTAÇÃO DE LISTA DUPLAMENTE ENCADEADA EM C
//

#include <stdlib.h>
#include <stdio.h>

typedef struct cell {

	int element;
	struct cell* prev;
	struct cell* next;

} cell;

cell* newListDup () {

	cell* c = malloc(sizeof(cell));

	if (c) {

		c->next = NULL;
		c->prev = NULL;
		c->element = -1; //Inicializa elemento da cabeça como -1
	}

	return c;
}

cell* list_dup_insert_begin (cell* lHead, int value) {

	cell* c = malloc(sizeof(cell));	

	if (c) {

		c->element = value;

		lHead->next->prev = c;
		lHead->next = c;

		c->next = lHead->next;
		c->prev = lHead;
	}

	return lHead;
}

cell* list_dup_insert_end (cell* lHead, int value) {

	cell* cellAux = lHead;

	cell* c = malloc(sizeof(cell));	

	if (c) {

		c->element = value;

		while (cellAux->next) {
			
			cellAux = cellAux->next;
		}

		c->next = NULL;
		c->prev = cellAux;

		cellAux->next = c;		
	}

	return lHead;
}

cell* list_dup_insert (cell* lHead, int value) {

	cell* cellAux = lHead;

	cell* c = malloc(sizeof(cell));	

	if (c) {

		c->element = value;

		while (cellAux->next && cellAux->next->element < value) {

			cellAux = cellAux->next;	
		}

		c->next = cellAux->next;
		c->prev = cellAux;

		c->next->prev = c;

		cellAux->next = c;
	}

	return lHead;
}

cell* list_dup_deleteAt (cell* lHead, int index) {

	cell* cellAux = lHead;

	for (int i = -1; i < index; ++i)
	{
		if (cellAux->next == NULL) {

			printf("%s\n", "Index out of range!");
			return lHead;
		}

		cellAux = cellAux->next;
	}

	cellAux->prev->next = cellAux->next;
	cellAux->next->prev = cellAux->prev;

	free(cellAux);

	return lHead;
}

cell* list_dup_delete (cell* lHead, int element) {

	cell* cellAux = lHead->next;

	while (cellAux && cellAux->element != element) {

		cellAux = cellAux->next;
	}

	if (cellAux == NULL) {

		printf("%s\n", "Index out of range!");
		return lHead;
	}

	cellAux->prev->next = cellAux->next;
	cellAux->next->prev = cellAux->prev;

	free(cellAux);

	return lHead;
}

int list_dup_first (cell* l) {

	return l->next->element;
}

int list_dup_last (cell* l) {

	while (l->next) {

		l = l->next;
	}

	return l->element;
}

cell* list_dup_concat(cell* l1, cell* l2)  {

	cell* cellAux = l1;

	while (cellAux->next) {

		cellAux = cellAux->next;
	}

	cellAux->next = l2->next;

	return l1;
}