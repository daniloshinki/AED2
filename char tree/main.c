#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE_TYPE char
#define MAX(a,b) ((a>b)?a:b)

typedef struct tree {
   TREE_TYPE x;
   struct tree * left;
   struct tree * right;
} tree;

/* cria um único nó da árvore */
tree * create_node (int x) {
  tree * node = malloc(sizeof(tree));
  node->left = node->right = NULL;
  node->x = x;
  return node;
}

/* Insere um nó na árvore caso ele não exista */
tree * insert (tree * t, tree * node) {
  
  if (t==NULL) return node;

  if (node->x == t->x) return t;
  if (node->x < t->x) t->left  = insert(t->left , node);
  else                t->right = insert(t->right, node);

  return t;
}

/* busca por uma chave, se encontrar retorna o nó, 
   caso contrário, insere e retorna o nó */
tree * search_insert (tree * t, int k) {
  tree * parent = t;

  while(t != NULL)
  {    
    if (t->x == k) return t;
    if (k < t->x)  {parent = t; t = t->left;  } 
    else           {parent = t; t = t->right; }    
  }
  return insert(parent, create_node(k));
}


void in_order(tree * t) {
  
  if(t==NULL) return;
  
  in_order(t->left);  
  printf("%c ", t->x);
  in_order(t->right);

  return;
}

void pre_order(tree * t) {
  
  if(t==NULL) return;

  printf("%c ", t->x);
  pre_order(t->left);  
  pre_order(t->right);

  return;
}

void pos_order(tree * t) {
  
  if(t==NULL) return;
  
  pos_order(t->left);  
  pos_order(t->right);
  printf("%c ", t->x);

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

int height(tree * t) { 
  if (t==NULL) return 0;
    
  return 1 + MAX(height(t->left), height(t->right));  
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
                       

int main(void) {
  
  tree * root = NULL;
  char s[256];
  int i;

  fgets(s, 255, stdin);

  for(i=0; i<strlen(s); i++) {
    if ('a' <= s[i] && s[i] <= 'z') {
      root = insert(root, create_node(s[i]));
    }
  }
  
  in_order(root);

  printf("%d\n", n_nodes(root));
  printf("%d\n", leaf_nodes(root));
  printf("%d\n", height(root));
  printf("%c\n", min_elem(root));
  printf("%c\n", max_elem(root));

  pos_order(root);
  pre_order(root);
  
  
  free_tree(root);

  return 0;
}