#include <stdio.h>
#include <stdlib.h>

typedef struct no no_t;
typedef no_t * element_t;
typedef no_t * qelement_t;

#include "queue.h"

int cont =0;
int total=0;
int busca = 0;

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
node_t *search ( int e, node_t *r);

struct no {
  int element;
  int height;
  node_t *left, *right;
};




int main(int argc , char *argv[]){
    FILE* imputFile;
    char* fileName = argv[1];
    int date;
    imputFile = fopen(fileName, "r");
    node_t *tree;
    tree = NULL;
    int primeiro=20000,ultimo=-20000;
    int soma =0, max=0;
    int i =0; int number;
   queue * fila =new_queue();

    while(fscanf(imputFile,"%d\n", &date) != EOF){
      tree = avl_insert(date, tree);
      total++;
      if(cont>=max)
        max=cont;
      soma+=cont;
      cont=0;
      push(fila,date);
    }
    int vetor[total-1];
   cell *aux = fila->inicio;
    while(aux!=NULL){
   // printf( " %d ", aux->elemento);
    vetor[i]=aux->elemento;
    i++;
    aux = aux->next;
  }

  for(int k=0; k< total;k++){
    printf("%d ", vetor[k]);
  }


    //
    printf("Questão 1-A: ");
    printf("%d\n",max);
    printf("\n");

    printf("Questão 2-A: ");
   // printf("%d\n",total );
    float result = (float)soma/(total);
    printf("%f\n",result );

    soma=0;
    max=0;
    cont=0;
    int porcentagem = total/10;
    //printf("%d\n",porcentagem );
  
     for(int j =0 ; j< porcentagem;j++){
      number= (rand()%total);
     tree=avl_delete(vetor[number],tree);
     printf("%d %d\n",vetor[number],number );
      if(cont>=max){
        //printf("cont %d\n",cont );
        max=cont;
      }
      soma+=cont;
      cont=0;
      tree = avl_insert(vetor[number], tree);
   }



    printf("\n");
    printf( "Questão 3: %d\n",max);
    result=(float)soma/total;
    printf( "Questão 4: %f\n",result);
    printf("\n");
    printf("%d\n",fila->size );




    fclose(imputFile);

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

node_t *search ( int e, node_t *r){
  if(r==NULL || r->element==e)
    return r;
  else if(r->element<e){
    return search(e,r->left);
    busca++;
  }
  else{
    return search(e,r->right);
    busca++;
  }
}