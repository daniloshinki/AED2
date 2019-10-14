#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
  
void printArray(int * array, int size){

  int curr;
  for(curr = 0; curr < size; curr++){
    printf(" %d", array[curr]);
  }
  printf("\n");
}
int maximum(int * array, int size){

  int curr = 0;
  int max = 0;

  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }

  return max;
}
void countingSort(int * array, int size){

  int count = 0;
  int max = maximum(array, size);
  int * x = calloc(max, sizeof(int)); // Zeros out the array

  for(count = 0; count < size; count++){
    x[array[count]]++;
  }
  int num = 0;
  count = 0;
  
  while(count <= size){
    while(x[num] > 0){
      array[count] = num;
      x[num]--;
      count++;
      if(count > size){ break; }
    }
    num++;
  }
}
  
// Driver program to test above function 
int main() 
{ 
  int arr[] = {10,7,12,4,8,1,2,3,9,11,25,0};
  int n = sizeof(arr) / sizeof(*arr);

  countingSort(arr, n);
  printArray(arr,n);

  return 0;
} 