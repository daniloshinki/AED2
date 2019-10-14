#include <stdio.h>
#include <stdbool.h>

void swap1(int arr[], int i, int j)
{	
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

  int partition(int arr[], int l, int h) 
{ 
  int left,right,pivot;
  
  left = l;
  right = h;
  pivot = arr[l];

  while(left<=right)
  {
    while (arr[left] < pivot) left++; //mudar aqui para decre
    while(arr[right] > pivot) right--; //mudar aqui para decre
    if(left <= right) 
    {
      swap1(arr, left, right);
      left++; right--;
    }
  }
  if(l < right) partition(arr, l, right);
  if(left > h) partition(arr, left , h);
  return left;
}

// insertionsort
void insertion(int arr[], int start, int end) {
   
        for (int i = (start + 1); i < end; ++i) {
            double temporary = arr[i];
            int j = (i - 1);
            while ((j >= 0) && ( arr[j] > temporary  )) {
                arr[(j + 1)] = arr[j];
                j = (j - 1);
            }
            arr[(j + 1)] = temporary;
        } }

//função que escolhe quando usar insert e quick
void sort(int arr[], int start, int end){
    if(start < end) 
    {
      if((end - start) < 10) 
      {
        insertion(arr, start, end + 1);
      } else{
        int part = partition(arr,start,end);
        sort(arr, start, part - 1);
        sort(arr, part + 1, end);
      }  }  }

void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
}


int main(void) {
  int arr[] = {10,3,5,2,1,6,4,9,0,11,33,22,100};
  int n = sizeof(arr) / sizeof(*arr);
  sort(arr, 0, n-1);
  printArr(arr, n);

  return 0;
}