#define TREE_TYPE int
#define MAX(a,b) ((a>b)?a:b)

typedef struct tree {
   TREE_TYPE x;
   struct tree * left;
   struct tree * right;
   int height;
} tree;

/* cria um único nó da árvore */
tree * create_node (int x) {
  tree * node = malloc(sizeof(tree));
  node->left = node->right = NULL;
  node->x = x;
  node->height = 0;
  return node;
}

int height(tree * t) { 
  if (t==NULL) return -1;
  return t->height;
}

int calc_height(tree * t) {
   return MAX( height(t->left), height(t->right) ) + 1;
}

/* right_right = rotate_left  */
tree * right_right( tree * root ) {
    printf("RIGHT-RIGHT!\n");
    
    tree * pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
 
    root->height = calc_height(root);
    pivot->height = calc_height(pivot);
 
    return pivot;
}

/* left_left = rotate_right */
tree * left_left( tree * root ) {
    printf("LEFT-LEFT!\n");
    
    tree * pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;
 
    root->height = calc_height(root);
    pivot->height = calc_height(pivot);
 
    return pivot;
}

/* left_right = rotate_left -> rotate_right */
tree * left_right( tree * t ) {
    printf("LEFT-RIGHT!\n");
    t->left = right_right( t->left );
    return left_left( t );
}

/* right_left = rotate_right -> rotate_left */
tree * right_left( tree * t ) {
    printf("RIGHT-LEFT!\n");
    t->right = left_left( t->right );
    return right_right( t );
}

int balance_factor(tree * t) {
  if (t==NULL) return 0;
  return height(t->left) - height(t->right);
}

tree * balance(tree * root) {
	if (balance_factor(root) < -1) {
		
		if (balance_factor(root->right) <= 0)
			root = right_right(root);
		else 
			root = right_left(root);
		
		
	} else if (balance_factor(root) > 1) {
		
		if (balance_factor(root->left) >= 0)
			root = left_left(root);
		else 			
			root = left_right(root);
		
	}
	
	return root;
}

/* Insere um nó na árvore caso ele não exista */
tree * insert (tree * t, tree * node) {
  
  if (t==NULL) return node;
  
  if (node->x < t->x)      t->left  = insert(t->left , node);    
  else if (node->x > t->x) t->right = insert(t->right, node);
  
  t = balance(t);
  t->height = calc_height(t);

  return t;
}


void pre_order(tree * t) {
  
  if(t==NULL) return;

  printf("%d ", t->x);
  pre_order(t->left);  
  pre_order(t->right);

  return;
}

void in_order(tree * t) {
  
  if(t==NULL) return;
  
  in_order(t->left);  
  printf("%d ", t->x);
  in_order(t->right);

  return;
}

void pos_order(tree * t) {
  
  if(t==NULL) return;
  
  pos_order(t->left);  
  pos_order(t->right);
  printf("%d ", t->x);

  return;
}

int n_nodes(tree * t) {
  if(t==NULL) return 0;

  return 1 + n_nodes(t->left) + n_nodes(t->right);
}

int leaf_nodes(tree * t) {
  if(t==NULL) return 0;

  if (t->left == NULL && t->right == NULL) return 1;

  return leaf_nodes(t->left) + leaf_nodes(t->right);
}

TREE_TYPE min_elem(tree * t) {
  if (t->left == NULL) return t->x;
  return min_elem(t->left);
}

TREE_TYPE max_elem(tree * t) {
  if (t->right == NULL) return t->x;
  return max_elem(t->right);
}

void free_tree(tree *t) {
   if(t==NULL) return;
   
   free_tree(t->left);
   free_tree(t->right);
   free(t);
}

tree * find_min(tree * root) {
  if (root == NULL) return NULL;
  if (root->left == NULL) return root;
  return find_min(root->left);
}



tree * delete_node(tree * root, TREE_TYPE n) {
  tree * tmp;

  if (root == NULL) return NULL;

  if (root->x == n) {
    if (root->right == NULL && root->left == NULL) {
      free(root);
      return NULL;
    }else if (root->right == NULL) {
      tmp = root->left; free(root);
      // tmp deve ser folha se a arv. esta balanceada
      tmp->height = tmp->height - 1;
      return tmp;
    }else if (root->left == NULL) {
      tmp = root->right; free(root);
      tmp->height =  tmp->height - 1;
      return tmp;
    }else{
      tmp = find_min(root->right);
      root->x = tmp->x;
      root->right = delete_node(root->right, tmp->x);
      // rebalanço
      if (balance_factor(root) == 2)
      {
        if (balance_factor(root->left) >= 0) root = left_left(root);
        else                                 root = left_right(root);
      }
    }
  } else {
    if (n > root->x) {
      root->right = delete_node(root->right, n);
      // rebalanca
      if (balance_factor(root) == 2)
      {
        if (balance_factor(root->left) >= 0) root = left_left(root);
        else                                 root = left_right(root);
      }
    } else {
      root->left = delete_node(root->left, n);
      // rebalanca
      if (balance_factor(root) == -2)
      {
        if (balance_factor(root->right) <= 0) root = right_right(root);
        else                                  root = right_left(root);
      }
    }
  }

  root->height = calc_height(root);

  return root;
}

int recursive_height(tree * t) { 
  if (t==NULL) return -1;
    
  return 1 + MAX(recursive_height(t->left), recursive_height(t->right));  
}