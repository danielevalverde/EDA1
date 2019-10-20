#include <stdlib.h>
#include <stdio.h>


typedef struct fila queue;

struct fila {
  struct cell *inicio;
  struct cell *final;
  int size;
};

typedef struct cell cell;
struct cell{
  int elemento;
  struct cell *next;
};

typedef enum {FALSE, TRUE} bool;

queue *new_queue();
int push(queue* q,int x);
cell *pop(queue *q);
bool isEmpty (queue* q);
bool isFull (queue* q);
cell *searchElement(queue *q, int x);
void printQueue(queue *q);




queue* new_queue(){
  queue *fi=(queue *)malloc(sizeof(queue));
  if(fi==NULL) return 0;
  fi->inicio=NULL;
  fi->final=NULL;
  fi->size=0;
  //fi->maxsize=sizeMax;
  return fi;
}

int push(queue* q, int x) {
  cell* c= (cell*)malloc(sizeof(cell));
  if (c) {
    c->elemento = x;
    c->next = NULL;
    if (q->inicio ==NULL) {
      q->inicio = c;
    }
    else {
      q->final->next = c;
    }
    q->final = c;
    q->size++;
    return 1;
  }
  return 0;
}

cell* pop(queue* q){
  cell *c= q->inicio;
  if (q->inicio!=NULL) {
    q->inicio = q->inicio->next;
    q->size--;
    if (q->inicio==NULL) {
      q->final = NULL;
    }
    c->next = NULL;
    return c;
  }
  return NULL;
}

bool isEmpty(queue* q){
  if (q->inicio == NULL)
    return TRUE;
  return FALSE;
}



void printQueue( queue *q ){
    cell *aux = q->inicio;
    while(aux!=NULL){
    printf( " %d", aux->elemento);
    aux = aux->next;

  }
  
}

  
cell* searchElement(queue *q, int x){
  if(q==NULL || q->inicio==NULL)
    return NULL;
  cell* anterior,  *atual = q->inicio;
  while (atual->next!= NULL) {
    if(atual->elemento != x){
        anterior = atual; 
    atual=atual->next;
      }
      else
        break;
    
  }
  if(atual->elemento==x){
    if(atual->elemento==q->inicio->elemento)
      return atual;
    if(atual->elemento==q->final->elemento)
      return NULL;
    else
      return anterior;
  }
  return NULL;  
}

