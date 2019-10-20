#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int *element_t;
typedef struct stk stk_t;

struct stk {
  unsigned int top, maxsize;
  element_t *velement;
};

bool push(element_t, stk_t *);
element_t pop(stk_t *);
stk_t *newStok(unsigned int);

bool isEmpty(stk_t *s){
  return (s->top == 0);
}

bool isFull(stk_t *s){
  return (s->top == s->maxsize);
}

stk_t *newStok(unsigned int size){
  stk_t *s = malloc(sizeof(stk_t));
  if(!s){
    return NULL;
  }
  s->velement = malloc(sizeof(element_t) * size);
  s->top = 0;
  s->maxsize = size;
  return (s);
}

bool push(element_t e, stk_t *s){
  if(isFull(s)){
     return false;
  }
  s->velement[s->top++] = e;
  return true;
}

element_t pop(stk_t *s){
  if(isEmpty(s)){
    return NULL;
  }
  return(s->velement[--s->top]);
}