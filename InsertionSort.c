#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* array, int size){

    printf("Initial List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

    for (int iterOne = 1; iterOne<size; iterOne++){
        int key = array[iterOne];
        int j = iterOne - 1;

        while (j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j = j - 1;
        }
    
        array[j+1] = key;

    }

    printf("\nFinal List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

}

int main(){
    int arr[] = {48, 62, 19, 83, 20, 20};
    insertionSort(arr, 6);
    return 0;
}