#include <stdio.h>
#include <stdlib.h>




typedef struct no no_t;

struct no{
	int element;
	no_t * left;
	no_t * right;


};

struct tree {
	no_t * raiz;
}

void in_order_print( no_t * tree){
	if(tree !=NULL){
		in_order_print(tree->left);
		printf("%d\n",tree->element );
		in_order_print(tree->right);
	}
}

no_t *search (int e, no_t *r) {
	if(r==NULL || r->element==e){
		return r;
	}
	else if(e <r->element)
		return search(e,r->left);
	else
		return search (e, r->right);
}
stack* newStack(){

	stack* s=(stack*) malloc(sizeof(stack));
	if(s){
		s->top = NULL;
	}
	return s;
}

no_t* newTree(){

	no_t* n=(no_t*) malloc(sizeof(no_t));
	if(no_t){
		
	}
	return no_t;
}