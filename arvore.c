#include<stdio.h>
#include<stdlib.h>

typedef struct no no_t;
typedef no_t * element_t;
typedef no_t * qelement_t;

#include "queue.h" // implementa��o de filas

#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct no node_t;

struct no {
  int t_element;
  node_t *left, *right;
};

node_t *newNode() {

  node_t *p = (node_t *) malloc(sizeof(node_t));

  if (p) {
    p -> left = NULL;
    p -> right = NULL;
  }

  return p;
}


node_t *insert(int e, node_t *r) {

	if (r == NULL) {
	  r = newNode(); // aloca memoria para novo elemento
	  r -> t_element = e;
	}
	else if (r -> t_element > e)
	   r -> left = insert(e, r -> left);
	else if (r -> t_element < e)
	   r -> right = insert(e, r -> right);
  return r;
}

int height(node_t* r) {

  if (r)
    return 1+MAX(height(r -> left), height(r->right));
  else
    return -1;
}

int main(void) {

  int N = 14, i;

  int entrada[] = {50,40,60,20,25,22,30,45,55,52,57,58,59,80};

  node_t *tree;

  tree = NULL;


    for (i = 0; i<N; i++)
      tree = insert(entrada[i],tree);
 
  printf("\n");
  postorder_print(tree);
  printf("\n");
  bfs_print(tree);
  printf("\n altura = %d \n",height(tree));
}
