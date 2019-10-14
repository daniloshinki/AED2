#include <stdio.h>
#include <stdbool.h>

void swap(int arr[], int i, int j)
{	
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// quicksort dividindo a array em 3 subarrays elementos menores,maiores e iguais ao pivo 
void quickSort3way(int arr[], int l, int h) 
{ 
  int left,right,pivot;
  if(l>=h) return;

  left = l;
  int i = l+1;
  right = h;
  pivot = arr[l];

  while(i<=right)
  {
    if(arr[i] < pivot)
    {
      swap(arr,left++,i++);   /* move os menores elementos para antes do index do pivo */
    } else if(arr[i] >= pivot) {
      swap(arr,i,right--);    /* move os maiores elementos para o fim */
    } else{
      i++;  /*deixar elementos iguais sozinhos */
    }
  }
  quickSort3way(arr, l,left -1);
  quickSort3way(arr, right +1, h);
}

void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
        } 
}

int main(void) {

  // divide em 3 array < = > que o pivo
  int arr[] = { 10, 3, 5, 2, 8, 7,11,102,55,27,17,94,13,1,0,255,11,11,11,11,11,11,11}; 
  int n = sizeof(arr) / sizeof(*arr); 
  quickSort3way(arr, 0, n - 1); 
  printArr(arr, n); 

     return 0; 
}

