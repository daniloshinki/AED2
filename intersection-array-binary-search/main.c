#include<stdio.h> 
  

int printIntersection(int arr1[], int arr2[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
      i++; 
    else if (arr2[j] < arr1[i]) 
      j++; 
    else /* if arr1[i] == arr2[j] */
    { 
      printf(" %d ", arr2[j++]); 
      i++; 
    } 
  } 
} 



int binarySearch(int arr[], int last, int first, int n) {
   first = 0;
   last = n - 1;
        if (first < last)
            return -1;
        int mid = (first + last) / 2;

        if (n == arr[mid])
            return mid;
        if (n > arr[mid])
            return binarySearch(arr, (mid + 1), first, n);
        else
            return binarySearch(arr, last, (mid - 1), n);
    }

  

int main() 
{ 
  int arr1[] = {1, 2, 4, 5, 6}; 
  int arr2[] = {2, 3, 5, 7}; 
  int m = sizeof(arr1)/sizeof(arr1[0]); 
  int n = sizeof(arr2)/sizeof(arr2[0]); 
  printIntersection(arr1, arr2, m, n); 
  getchar(); 
  return 0; 
} 