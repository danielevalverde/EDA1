#include <stdlib.h>
#include <stdio.h>

typedef struct cell {
	int element;
	struct cell* next;

} cell;

cell* newlist () {

	cell* c = (cell*) malloc(sizeof(cell));
	if(c){
		c->next = NULL;
		return c;	
	}
}

cell* insert (cell* list, int value) {

	cell* listRefHead = list;
	//cell* listRefHead = no;


	cell* c = (cell*) malloc(sizeof(cell));	

	c->element = value;

	while (list->next != NULL && list->next->element < value) {

		list = list->next;	
		//no=no->next;
	}

	c->next = list->next;
	// vai apontar para onde list->next apontava
	// ou seja, pro último elemento
	list->next = c;		

	return listRefHead;
}

cell* insert_end (cell* list, int value) {

	cell* listRef = list;

	cell* c = (cell*) malloc(sizeof(cell));	

	c->element = value;

	while (listRef->next != NULL ) {

		listRef = listRef->next;	
	}

	c->next = listRef->next;
	// vai apontar para onde listRef>next apontava
	listRef->next = c;	
	// listRef passa a apontar pra null 
	// e não perdemos a referência da cabeça

	return listRef;
}

int Last (cell* list) {
	cell* last = list;
	while (last->next != NULL) {
		last = last->next;	
	}
	return last->element;
}




int main(int argc, char const *argv[]) {

	cell* l = newlist();

	insert(l, 10);
	insert(l, 20);
	insert(l, 100);
	insert(l, 40);
	insert(l, 4000);
	insert(l, 6220);
	insert(l, 70);
	int x = Last(l);
	insert_end(l, 10);	
	for (int i = 0; i < 8; ++i)
	{
		printf("%d\n", l->next->element);

		l = l->next;
	}

	printf("\n%d\n",x );
	
	return 0;
}