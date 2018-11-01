#include <stdio.h> 
#include <stdlib.h>
#define NUM 50000

void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   int flag; 
   for (i = 0; i < n-1; i++) 
   { 
     flag = 0; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           flag = 1; 
        } 
     } 
  
     // break cycle when no elements are swapped
     if (!flag) 
        break; 
   } 
} 
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
   
int main() 
{ 
    int array[NUM];
    int i;
    for(i=0; i<NUM;i++)
    {
        array[i] = rand();
    }
    printf("Array pre-sorting: \n");
    printArray(array, NUM);
    bubbleSort(array, NUM); 
    printf("Array messo in ordine: \n"); 
    printArray(array, NUM); 
    return 0;
} 
