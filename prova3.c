#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*

OLá, Professor.

A questão parte da questão 06 que pede o calculo do logaritmo está comentada  nas linhas 178 e 179, visto que no meu computador só funcionou quando dei o comando -lm junto. Desta forma:

gcc prova3.c -lm -o prova3 && ./prova3 entrada.txt

Deixei comentado devido a esse trech do trabalho : 
" 
Certifique-se que o programa desenvolvido por você não contenha erros de compilação ou de execução que o impeçam de
exibir as respostas. Em tais situações, será atribuı́da nota zero. O uso de bibliotecas fora do padrão não é recomendável.
Procure usar os compiladores ‘gcc’ ou ‘clang’ " 

E o programa está um pouco lento aqui. Não sei se é relacionado ao desempneho da minha máquina ou devido a implementação do algoritmo.



*/

typedef struct no no_t;
typedef no_t * element_t;
typedef no_t * qelement_t;
typedef struct no node_t;
#include "queue.h"

int cont =0;
int total=0;
int busca = 0;

node_t *insertBinary(int e, node_t *r);

#define MAX(a,b) ((a) > (b) ? (a) : (b))
void bfs_print(node_t* r);
node_t *newNode();
int avl_height(node_t* r);
node_t *avl_rRight(node_t *x);
node_t *avl_rLeft(node_t *x);
node_t *avl_delete (int e, node_t *r);
node_t *search ( int e, node_t *r);
node_t *rebalance(node_t *r);
node_t *avl_insert(int e, node_t *r);
node_t *get_max(node_t *x);


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
    node_t *tree,* treeBinary;
    tree = NULL;
    treeBinary=NULL;
    int primeiro=20000,ultimo=-20000;
    int soma =0, max=0;
    int vetor[100000];
    int i =0; int number;

printf("aviso: para entradas muito grandes, o programa está demorando cerca de um minuto para rodar\n");
    while(fscanf(imputFile,"%d\n", &date) != EOF){
      tree = avl_insert(date, tree);
      treeBinary = insertBinary(date, treeBinary);
      total++;
      if(cont>=max)
        max=cont;
      soma+=cont;
      cont=0;
      vetor[i]=date;
      i++;

    }
   
    
    printf("Questão 1-A: ");
    printf("%d\n",max);
    printf("\n");

    printf("Questão 2-A: ");
   // printf("%d\n",total );
    float result = (float)soma/(total);
    printf("%f\n",result );



   
    cont=0, busca=0,soma=0, max=0;
    int porcentagem = total/10;
    //printf("%d\n",porcentagem );


    int BuscaBinary, BuscaAvl;
    
   for(int j =0 ; j< porcentagem;j++){
      //1 teste 
      number= (rand()%total);
    search(vetor[number],tree);
    //  printf("%d %d\n",vetor[number],number );
      //soma+=busca;
    
    }
    BuscaAvl=busca;
    busca=0;

      for(int j =0 ; j< porcentagem;j++){
      //1 teste 
      number= (rand()%total);
    search(vetor[number],treeBinary);
    //  printf("%d %d\n",vetor[number],number );
      //soma+=busca;
    
    }
    BuscaBinary=busca;
   

    soma=0;
    max=0;
    cont=0;

    for(int j =0 ; j< porcentagem;j++){
      //1 teste 
      number= (rand()%total);
     tree=avl_delete(vetor[number],tree);
    //  printf("%d %d\n",vetor[number],number );
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
     printf("\n");
    printf( "Questão 4: %f\n",result);
    printf("\n");

    //printf("quantidade de buscas %d\n",busca );
    result=(float)BuscaAvl/porcentagem;
    printf("Questão 05 Avl:%f\n ",result);
    result=(float)BuscaBinary/porcentagem;
    printf("\n");
    printf("Questão 05 Binary:%f\n ",result);
    printf("\n");



// QUESTÃO 6

int l =0;
 printf("Questão 06 \n\n ");
int sup=0,n=0;
while(sup<19){ 
  if(sup==0)
    n=10;
  else if(sup==1)
    n=50;
  else{
    if(n==50)
      n=500;
    else
      n+=500;
  }
  porcentagem=n/10;
     for(int j =0 ; j< porcentagem;j++){
      //1 teste 
      number= (rand()%n);
    search(vetor[number],tree);
    }
    BuscaAvl=busca;
    busca=0;

      for(int j =0 ; j< porcentagem;j++){
      //1 teste 
      number= (rand()%n);
    search(vetor[number],treeBinary);  
    }
    BuscaBinary=busca;


    result=(float)BuscaAvl/porcentagem;
    printf("Avl: %f  ",result);
    result=(float)BuscaBinary/porcentagem;
    printf("Binary: %f  ",result);

   //l= log2(n);
    //printf("log :%d\n" ,l );
    printf("\n");



    sup++;
}




    fclose(imputFile);

}





/// Arvore BINARIA

node_t *insertBinary(int e, node_t *r) {

  if (r == NULL) {
    r = newNode(); // aloca memoria para novo elemento
    r -> element = e;
  }
  else if (r -> element > e)
     r -> left = insertBinary(e, r -> left);
  else if (r -> element < e)
     r -> right = insertBinary(e, r -> right);
  return r;
}
/////

/// AVL


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
      r = r->right;
      free(p);
    }
    else if(r->right == NULL){
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
    busca++;
    return search(e,r->left);
    
  }
  else{
    busca++;
    return search(e,r->right);
    }
}


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























