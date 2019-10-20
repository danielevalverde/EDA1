#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct cell cell_t;
typedef struct queue queue_t;
typedef enum {TRUE, FALSE} bool; 

struct queue {

  cell_t *first;
  cell_t *last;

  unsigned int size;
  unsigned int maxsize;
};
  
struct cell {

      int element;

      cell_t *next;
};

bool    enqueue(int, queue_t *);
cell_t *dequeue(queue_t *);
cell_t *newcell(void);
queue_t *newQueue(unsigned int);
void    display(queue_t *);

bool isempty(queue_t *q) { return (q -> size == 0); }
bool isfull(queue_t *q)  { return (q -> size == q -> maxsize); }


int main() {

  queue_t *queue = newQueue(10);

  enqueue(10,queue);
  display(queue);
  enqueue(20,queue);
  display(queue);
  enqueue(50,queue);
  enqueue(40,queue);
  display(queue);
  enqueue(5,queue);
  display(queue);

  dequeue(queue);

  display(queue);

}
