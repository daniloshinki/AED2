#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) ((a>b)?a:b)
#define DATA_TYPE registro
int contador;
int count;
int aux;


typedef struct registro {
    int key;
    double velocidade;
    double preco;
} registro;

/* lista ligada */
typedef struct info {
  DATA_TYPE x;
  struct info * prox;
} info;

info * cria_info (DATA_TYPE x) {
  info * p = malloc(sizeof(info));
  p->x = x;
  p->prox = NULL;
  return p;
}

/* insere p2 após p1 */
info * p2_apos_p1(info * p1, info * p2) {
  p2->prox = p1->prox;
  p1->prox = p2;
  return p1;
}

info * insere_fim(info * p, DATA_TYPE x) {
  info * new_p = cria_info(x);
  info * w = p;

  if (p==NULL) return new_p;

  while(w->prox != NULL) w = w->prox;
  p2_apos_p1(w, new_p);
  
  return p;
}


info * insert(info *sortedList, info *root) {
  info * walker = sortedList;
  if (sortedList == NULL) {
    root->prox = NULL;
    return root;
  }

  if (sortedList->x.preco > root->x.preco) {
    root->prox = sortedList;
    return root;
  }

 while(walker->prox != NULL && walker->prox->x.preco <= root->x.preco)
  {
    walker = walker->prox;   
  }
  root->prox = walker->prox;
  walker->prox = root;
  return sortedList;
}

//insertion sort 
info * insertionSort(info *root) {
    info * tmp;
    info * sortedList = NULL;
    
    while (root != NULL)
    {
      tmp = root->prox;
      sortedList = insert(sortedList, root);
      root = tmp;
      
    }

    return sortedList;
}

void print_ll(info * p) {
  info * w = p;
  while (w != NULL)
  {
    printf("k: %d, v: %f, p: %f\n", w->x.key, w->x.velocidade, w->x.preco);
    w = w->prox;
    contador++;
  }
  printf("---------------\n");
}

void free_list(info * p) {
  info * tmp;

  while(p->prox != NULL) {
    tmp = p;
    p = p->prox;
    free(tmp);
  }
  free(p);
}

registro values[] = { (registro){5, 123, 6}, (registro){1, 234, 6},
                       (registro){9,551, 4}, (registro){2, 122, 3}, 
                       (registro){28, 127, 2},  (registro){12, 551, 1}
                    };



void swap(info *a, info *b) {
    registro tmp;
    tmp = a->x;

    a->x = b->x;
    b->x = tmp;
}

info * find_min (info * root) {
    info * i_min = root;
    info * walker = root;

    while (walker != NULL) {
      if (walker->x.preco < i_min->x.preco) i_min = walker;
      walker = walker->prox;
      count++;
    }
    return i_min;
}
// selection sort
info * selectionSort(info *root) {
    info * walker = root;
    info * i_min = NULL;

    while(walker->prox != NULL) {
      i_min = find_min(walker);
      swap(walker, i_min);
      walker = walker->prox;
      aux = aux + count;

    }
    return root;
}
//bubble sort modificado para remover precos duplicados
info * bubbleSort(info *root) {
    info * walker;
    char changed = 1;
    int newn;
    struct info* next_next;


    while (changed)
    {
      changed = 0;

      walker = root;
      while (walker->prox != NULL) {
        //remove os duplicados
        if(walker->x.preco == walker->prox->x.preco) {

          next_next = walker->prox->prox; 
           free(walker->prox); 
           walker->prox = next_next; 

        } else if (walker->x.preco > walker->prox->x.preco) {
          swap(walker, walker->prox);
          changed = 1;          
        }
        walker = walker->prox;
        count++;
      }        
    }
    return root;
}

//remove valores duplicados em uma linked list
void removeDuplicates(struct info *root) 
{ 
    /* Pointer to traverse the linked list */
    struct info* current = root; 
  
    /* Pointer to store the next pointer of a node to be deleted*/
    struct info* next_next;  
    
    /* do nothing if the list is empty */
    if (current == NULL)  
       return;  
  
    /* Traverse the list till last node */
    while (current->prox != NULL)  
    { 
       /* Compare current node with next node */
       if (current->x.preco == current->prox->x.preco)  
       { 
           /* The sequence of steps is important*/               
           next_next = current->prox->prox; 
           free(current->prox); 
           current->prox = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          current = current->prox;  
       } 
    } 
} 



int main() {
  
  info * root = NULL;
  info * sorted = NULL;
  

 for(int i=0;i<6;i++) root = insere_fim(root, values[i]);
 //print_ll(root);


 // sorted = insertionSort(root);  
 // print_ll(sorted);

 // sorted = selectionSort(root);
  //print_ll(sorted);

  sorted = bubbleSort(root);  
 print_ll(sorted);

 // removeDuplicates(sorted);
 // print_ll(sorted);

 
  //sorted = selectionSort(root);
  //print_ll(sorted);


  printf("numero de repetições do bubble para ordenar : %d\n", count);
  //printf("Numero maximo de operações do maior para o menor indice: %d\n", contador);
  //printf("repetições x operações + para - indice = %d", count-contador);
  free_list(root);

  return 0;
}