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


