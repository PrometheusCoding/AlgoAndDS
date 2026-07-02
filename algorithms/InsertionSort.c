#include <stdio.h>
#include <stdlib.h>

/*
How does Insertion sort work?
Go through the list starting from index one, it compares the element that it is currently at with all previous element to see if it is lesser.
While the current element is lesser, we move the compared element to the right by one and keep checking the values before. However, when the
current value is greater OR we go passed the start of the list, then we swap the current element with the compared element.

This is O(n^2) complexity.
*/

void insertionSort(int* array, int size){

    for (int iterOne = 1; iterOne<size; iterOne++){
        int key = array[iterOne];
        int iterTwo = iterOne - 1;

        while (iterTwo >= 0 && array[iterTwo] > key){
            array[iterTwo+1] = array[iterTwo];
            iterTwo--;
        }
    
        array[iterTwo+1] = key;

    }

}

int main(){
    int arr[] = {48, 62, 19, 83, 20, 20};
    int size = sizeof(arr)/sizeof(int);

        printf("Initial List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", arr[iter]);
    }
    printf("]");
    
    insertionSort(arr, 6);

        printf("\nFinal List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", arr[iter]);
    }
    printf("]");

    return 0;
}