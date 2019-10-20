#include<stdio.h>
#include<stdlib.h>

typedef struct no no_t;
typedef no_t * element_t;
typedef no_t * qelement_t;

#include "queue.h" // implementação de filas

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

/* Questão (a) -- Implementar bfs_print*/
void bfs_print(node_t *r); // varredura da árvore com raiz r em largura

node_t *insert(int e, node_t *r); // inserção de elemento e
                                 // num novo nó da árvore com raiz r

/* Questão (b) -- Implementar it_insert*/
node_t *it_insert(int e, node_t *r); // versão iterativa da inserção  

void inorder_print(node_t *r); // varredura em-ordem
void postorder_print(node_t *r); // varredura pos-ordem

/* Questão (c) -- Implementar it_inorder_print */
void it_inorder_print(node_t *r); // varredura in-order (versão iterativa)

 int height(node_t* r); // fornece a altura da árvore de raiz r

/* Questão (d) -- Implementar it_height */
 int it_height(node_t* r); // versão iterativa da mesma função

  /* code starts here */
  
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

void inorder_print(node_t *r) { 

  if (r != NULL) {
      inorder_print(r->left);
      printf("%d \t",r->t_element);
      inorder_print(r->right);
    }
}

 void postorder_print(node_t *r) { 

  if (r != NULL) {
      postorder_print(r -> left);
      postorder_print(r -> right);
      printf("%d \t",r -> t_element);
    }
}

 void preorder_print(node_t *r) {

  if (r != NULL) {
    printf("%d \t",r -> t_element);
    preorder_print(r -> left);
    preorder_print(r -> right);
  }
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
  inorder_print(tree);
  printf("\n");
  postorder_print(tree);
  printf("\n");
  //  bfs_print(tree);
  printf("\n altura = %d \n",height(tree));
}