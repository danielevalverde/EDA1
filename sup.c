#include <stdio.h>
#include <stdlib.h>

typedef struct no no_t;
typedef no_t * element_t;
typedef no_t * qelement_t;

#include "queue.h"

int cont =0;
int total=0;

typedef struct no node_t;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
node_t *get_max(node_t *x);
int avl_height(node_t* r);
node_t *newNode();
node_t *avl_rRight(node_t *x);
node_t *avl_rLeft(node_t *x);
node_t *rebalance(node_t *r);
node_t *avl_insert(int e, node_t *r);
node_t *avl_delete (int e, node_t *r);

struct no {
  int element;
  int height;
  node_t *left, *right;
};

void bfs_print(node_t* r){
  queue_t* q = newQueue();
  enqueue(r, q);
  while (q->size != 0)
  {

      node_t *next = dequeue(q);
      printf("%d \t", next->element);
      if (next->left) {
        enqueue(next->left, q);
      }
      if (next->right) {
        enqueue(next->right, q);
      }
  }

}



int main(int argc , char *argv[]){
    FILE* imputFile;
    char* fileName = argv[1];
    int imputInt;
    imputFile = fopen(fileName, "r");
    node_t *tree;
    tree = NULL;
    int primeiro=20000,ultimo=-20000;
    int vetor[500];
    int max; 
    while(fscanf(imputFile,"%d\n", &imputInt) != EOF){
      cont=0;
      tree = avl_insert(imputInt, tree);
      if(cont>max)
        max=cont;
        total++;
    }

    //
    printf("Questão 1-A: ");
    printf("%d\n",max );
    printf("\n");

    printf("Questão 2-A: ");
   // printf("%d\n",total );
    float result = (float)cont/(total);
    printf("%f\n",result );

    cont=0;
    //printf("%d\n",primeiro );
   // printf("%d\n",ultimo );
    int porcentagem = total*0.10;
   // printf("%d\n",porcentagem );

  for(int i =0 ; i < porcentagem; i++){ 
    int number = rand() % ultimo;
   // avl_delete (number, tree);
  }   

  printf("total  %d\n",total );


}



node_t *get_max(node_t *x){
  node_t* aux = x;
  while (aux->right != NULL) {
        aux = aux->right;
    }
  return aux;
}

int avl_height(node_t* r){

  if (r)
    return 1+MAX(avl_height(r->left), avl_height(r->right));
  else
    return -1;
}

node_t *newNode(){

  node_t *r = (node_t *) malloc(sizeof(node_t));

  if (r) {
    r->left = NULL;
    r->right = NULL;
  }

  return r;
}

node_t *avl_insert(int e, node_t *r){
  if(r == NULL){
    r = newNode();
    r->element = e;
    return r;
  }
  else if(r->element > e){
    r->left = avl_insert(e, r->left);
  }
  else if(r->element < e){
    r->right = avl_insert(e, r->right);
  }

  return rebalance(r);
}


node_t *avl_rRight(node_t *x){
  node_t *y = x->left;
  x->left = y->right;
  y->right = x;
  x->height = 1 + MAX(avl_height(x->left), avl_height(x->right));
  y->height = 1 + MAX(avl_height(y->left), avl_height(y->right));
  cont++;
  return y;
  
}

node_t *avl_rLeft(node_t *x){
  node_t *y = x->right;
  x->right = y->left;
  y->left = x;
  x->height = 1 + MAX(avl_height(x->left), avl_height(x->right));
  y->height = 1 + MAX(avl_height(y->left), avl_height(y->right));
  cont++;
  return y;
  
}

node_t *rebalance(node_t *r){
  int lh = avl_height (r->left);
  int rh = avl_height (r->right);
  int fb = lh - rh;
  r->height = 1 + MAX(lh, rh);
  if(fb == 2){
    if (avl_height(r->left->right) > avl_height(r->left->left)) {
      r->left = avl_rLeft (r->left);
    }
    r = avl_rRight (r);
  }
  else if (fb == -2) {
    if (avl_height (r->right->left) > avl_height (r->right->right)) {
      r->right = avl_rRight (r->right);
    }
    r = avl_rLeft(r);
  }
  return r;
}

node_t *avl_delete (int e, node_t *r){
  node_t *p;
  if (r == NULL) {
    return r;
  }
  if(r->element < e){
    r->right = avl_delete(e, r->right);
  }
  else if(r->element > e){
    r->left = avl_delete(e, r->left);
  }
  else{
    if(r->left == NULL){
      p = r;
      r = r->left;
      free(p);
    }
    else{
      p = get_max(r->right);
      r->element = p->element;
      r->left = avl_delete(p->element, r->left);
    }
  }
  if(r){
    return rebalance(r);
  }
  return r;
}