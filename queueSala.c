// 
// IMPLEMENTAÇÃO DE FILA EM C
//

#include <stdio.h>
#include <stdlib.h>
#include "listaSala2.h"
#include "bool.h"


typedef struct queue {

	int maxSize, size;
	cell* first;
	cell* last;

} queue;

queue* newQueue (int limit) {

	queue* queueAux = (queue*)malloc(sizeof(queue));

	if (queueAux) {

		queueAux->size  = 0;
		queueAux->maxSize   = limit;
		queueAux->first = NULL;
		queueAux->last  = NULL;
	}

	return queueAux;
}

bool queue_isEmpty (queue* q) {

	if (q->first == NULL) {
		return TRUE;
	}

	return FALSE;
}

bool queue_isFull (queue* q) {

	if (q->size == q->maxSize) {
		return TRUE;
	}

	return FALSE;
}


bool queue_enqueue (int x, queue* q) {

	if (queue_isFull(q) == FALSE) {

		cell* cellAux = (cell*)malloc(sizeof(cell));

		if (cellAux) {
			
			cellAux->element = x;
			cellAux->next = NULL;

			if (queue_isEmpty(q) == TRUE) {

				q->first = cellAux;
			}
			else {

				q->last->next = cellAux;
			}
			
			q->last = cellAux;
			q->size++;

			return TRUE;
		}
	}

	return FALSE;
}

cell* queue_dequeue (queue* q) {

	cell* cellAux = q->first;

	if (queue_isEmpty(q) == FALSE) {

		q->first = q->first->next;
		q->size--;
	
		if (queue_isEmpty(q) == TRUE) {

			q->last = NULL;
		}

		cellAux->next = NULL;

		return cellAux;
	}

	return NULL;
}

cell* queue_first (queue* q) {

	if (queue_isEmpty(q) == FALSE) {

		return q->first;
	}

	return NULL;
}

void queue_display (queue* q) {

	printf("\nSize: %d\n", q->size);

	printf("Max Size: %d\n", q->maxSize);

	printf("\nElementos:\n");

	cell* cellAux = q->first;

	for (int i = 0; i < q->size; ++i)
	{
		printf("%d : %d\n", i + 1, cellAux->element);
		cellAux = cellAux->next;
	}

	printf("\n");
}

int main() {

  queue *queue = newQueue(10);

  queue_enqueue(10,queue);
  queue_display(queue);
  queue_enqueue(20,queue);
  queue_display(queue);
  queue_enqueue(50,queue);
  queue_enqueue(40,queue);
  queue_display(queue);
  queue_enqueue(5,queue);
  queue_display(queue);

  queue_dequeue(queue);

  queue_display(queue);

  queue_display(queue);
}
