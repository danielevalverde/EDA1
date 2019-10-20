node_t *newNode() {
	node_t *p = (node_t *) malloc(sizeof(node_t));

	if (p) {
		p -> left = NULL;
		p -> right = NULL;
  	}

	return p;
}

int max(int a, int b){
	if(a>=b) return a;
	else return b;
}

int avl_height(node_t *r){
	if(!r){
		return -1;
	}
	return r->height;
}

node_t *avl_rRight(node_t *x){
	node_t *y = x->left;
	x->left = y->right;
	y->right = x;
	x->height = 1 + max(avl_height(x->left), avl_height(x->right));
	y->height = 1 + max(avl_height(y->left), avl_height(y->right));

	return y;
}

node_t *avl_rLeft(node_t *x){
	node_t *y = x->right;
	x->right = y->left;
	y->left = x;
	x->height = 1 + max(avl_height(x->left), avl_height(x->right));
	y->height = 1 + max(avl_height(y->left), avl_height(y->right));

	return y;
}

node_t *rebalance(node_t *r){
	int lh, rh, fb;
	lh = avl_height(r->left);
	rh = avl_height(r->right);

	fb = lh - rh;

	r->height = 1 + max(lh, rh);

	if(fb == 2){
		if(avl_height(r->left->right) > avl_height(r->left->left))
			r->left = avl_rLeft(r->left);
		r = avl_rRight(r);
	}
	else if(fb == -2){
		if(avl_height(r->right->left) > avl_height(r->right->right))
			r->right = avl_rRight(r->right);
		r = avl_rLeft(r);
	}

	return r;
}

node_t *avl_insert(int e, node_t *r){
	if (r == NULL) {
		r = newNode();
		r -> element = e;
	}
	else if (r -> element > e)
		r -> left = avl_insert(e, r -> left);
	else if (r -> element < e)
		r -> right = avl_insert(e, r -> right);

	if(!r) return r;
	return rebalance(r);
}

node_t *get_max(node_t *p){
	while(p->right){
		p = p->right;
	}
	return p;
}

node_t *avl_delete(int e, node_t *r){
	node_t *p;

	if(r==NULL) return r;

	if(r->element < e)
		r->right = avl_delete(e,r->right);
	else if(r->element > e)
		r->left = avl_delete(e,r->left);
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
			p = get_max(r->left);
			r->element = p->element;
			r->left = avl_delete(p->element, r->left);
		}
	}

	if(r) return rebalance(r);
	return r;
}

void inorder_print(node_t *r) {

	if (r != NULL) {
		inorder_print(r->left);
		printf("%d ",r->element);
		inorder_print(r->right);
	}
}

 void postorder_print(node_t *r) {

	if (r != NULL) {
 		postorder_print(r -> left);
		postorder_print(r -> right);
		printf("%d ",r -> element);
	}
}

 void preorder_print(node_t *r) {

	if (r != NULL) {
		printf("%d ",r -> element);
		preorder_print(r -> left);
		preorder_print(r -> right);
	}
}

void bfs_print(node_t *r){

	queue_t *nq = newQueue();

	if(!r) return;

	enqueue(r, nq);
	printf("%d", r->element);
	while(!isempty(nq)){
		node_t *node = dequeue(nq);
		if(node->left){
			enqueue(node->left, nq);
			printf(" %d", node->left->element);
		}
		if(node->right){
			enqueue(node->right, nq);
			printf(" %d", node->right->element);
		}
	}
	printf("\n");
}