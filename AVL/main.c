#include <stdio.h>
#include <stdlib.h>

#include "tree.h"      

int main(void) {
  
  tree * root = NULL;

  root = insert(root, create_node(7));
  root = insert(root, create_node(4));
  root = insert(root, create_node(1));
  root = insert(root, create_node(3));
  root = insert(root, create_node(2));
  root = insert(root, create_node(5));
  root = insert(root, create_node(6));

  for(int i = 8; i<100; i++) root = insert(root, create_node(i));


  printf("%d %d\n", height(root), recursive_height(root));

  in_order(root);

  root = delete_node(root, 20);
  root = delete_node(root, 50);
  root = delete_node(root, 33);
  root = delete_node(root, 71);
  root = delete_node(root, 40);
  printf("\n%d %d\n", height(root), recursive_height(root));

  in_order(root);
  
  free_tree(root);

  return 0;
}