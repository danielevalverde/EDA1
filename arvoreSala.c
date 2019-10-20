#include <stdlib.h>
#include <stdio.h>

typedef struct no node_t;

struct no {
  int element;
  node_t *left, *right;
};

node_t * delete( int e , node_t *r) {
  node_t *p;
  if(r == NULL) return r;
  if(r->element < e)
    r->right=delete(e,r->right);
  else if(r->element>e)
    r->left=delete(e,r->left);
    else{
      if(r->left==NULL){
        p=r;
        r=r->right;
        free(p);
      }
      else if(r->right ==NULL){
        p=r;
        p=r->left;
        free(p);
      }
      else{
        p=get_msax(r->left);
        r->element=p->element;
        r->left=delete(p->element, r->left);
      }
    }
    return r;

}