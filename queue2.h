typedef struct cell cell_t;
typedef struct queue queue_t;
typedef enum {FALSE, TRUE} bool; 

struct queue {

  cell_t *first;
  cell_t *last;

  unsigned int size;
};
  
struct cell {

      qelement_t element;

      cell_t *next;
};

bool    enqueue(qelement_t , queue_t *);
qelement_t dequeue(queue_t *);
cell_t *newcell(void);
queue_t *newQueue(void);
void    display(queue_t *);

bool isempty(queue_t *q) { return (q -> size == 0); }
//bool isfull(queue_t *q)  { return (q -> size == q -> maxsize); }

queue_t *newQueue() {

  queue_t *p = malloc ( sizeof (queue_t));
  if (!p) return NULL;
  
  p -> first = p -> last = NULL;
  p -> size  = 0;
  return p;

}

cell_t *newCell() {

  cell_t *p = malloc( sizeof (cell_t));
  p -> next = NULL;
  return p;

} 

bool enqueue(qelement_t e, queue_t *q) {

  
  cell_t *p = newCell();
  if (!p) return FALSE;

  if (isempty(q)) q -> first = p;
  else q -> last -> next = p;
  
  q -> last = p;
  q -> size++;
  p -> element = e;

  return TRUE;
}

// dequeue an element returning it to the caller
qelement_t dequeue(queue_t *q) {

  if (isempty(q)) return NULL;

  cell_t *p = q -> first;
  qelement_t e = q -> first -> element;
  
  q -> first = q -> first -> next;
  q -> size--;

  if (isempty(q))
    q -> first = q -> last = NULL;

  free(p);
  return (e);
}