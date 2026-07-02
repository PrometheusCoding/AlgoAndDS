#include <stdio.h>
#include <stdlib.h>
/*
How does quicksort work

1. Check if the size of the array is >1 by comparing low and high.
2. Choose the first element of the array to become the pivot.
3. Place the pivot in the correct position of the array while also moving elements less than or equal
   to the pivot to the left, and elements greater than the pivot to the right.
4. Quicksort on the right side of the pivot and on the left side of the pivot.

*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    while (j < high){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }

        j++;
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int* array, int low, int high){

    if (low < high){

        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);

    }
}

int main(){
    int array[] = {48, 62, 19, 83, 20, 20};
    int size = sizeof(array) / sizeof(int);

    printf("Initial List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

    quickSort(array, 0, size - 1);

    printf("\nFinal List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");


    return 0;
}