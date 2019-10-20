#include <stdio.h>
#include <stdlib.h>

typedef struct no node_t;
#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct no {
  int element;
  int height;
  node_t *left, *right;
};

int avl_height(node_t* r) {

  if (r)
    return 1+MAX(avl_height(r -> left), avl_height(r->right));
  else
    return -1;
}


node_t *newNode() {

  node_t *r = (node_t *) malloc(sizeof(node_t));

  if (r) {
    r -> left = NULL;
    r -> right = NULL;
  }

  return r;
}

node_t *avl_rright(node_t *x){
  node_t *y = x->left;
  x->left = y->right;
  y->right = x;
  x->height = 1 + MAX(avl_height(x->left), avl_height(x->right));
  y->height = 1 + MAX(avl_height(y->left), avl_height(y->right));
  return y;
}

node_t *avl_rleft(node_t *x){
  node_t *y = x->right;
  x->right = y->left;
  y->left = x;
  x->height = 1 + MAX(avl_height(x->left), avl_height(x->right));
  y->height = 1 + MAX(avl_height(y->left), avl_height(y->right));
  return y;
}

node_t *rebalance(node_t *r){
  int lh, rh, fb;
  lh = avl_height(r->left);
  rh = avl_height(r->right);
  fb = lh - rh;
  r->height =  1 + MAX(lh, rh);

  if(fb == 2){
    if(avl_height(r->left->right) > avl_height(r->left->left)){
      r->left = avl_rleft(r->left);
    }
    r = avl_rright(r);
  }
  else if(fb == 2){
    if(avl_height(r->right->left) > avl_height(r->right->right)){
      r->right = avl_rright(r->right);
    }
    r = avl_rleft(r);
  }
  return r;
}

node_t *avl_insert(int e, node_t *r){
  if(r == NULL){
    r = newNode();
    r->element = e;
  }
  else if(r->element > e){
    r->left = avl_insert(e, r->left);
  }
  else if(r->element < e){
    r->right = avl_insert(e, r->right);
  }
  else {
    return r;
  }
  return r;

  // return rebalance(r);
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