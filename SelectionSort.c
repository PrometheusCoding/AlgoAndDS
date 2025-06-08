#include <stdio.h>
#include <stdlib.h>

/*
How does selection sort work?
We search the list for the smallest element and then swap it with the first index of the list
We repeat for the second and swap it with the second index of the list
We do this up until the list is sorted

Since it loops through n items, n times we have an algorithm with big O of O(n)
*/

void selectionSort(int* array, int size){
    printf("Initial List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

    // Let's perform the selectionSort
    int minVal;
    int minIndex;
    int temp;
    
    // First 'loop' is used to track how many times we've gone through the items
    for (int iterOne=0; iterOne<size; iterOne++){

        minVal = 10000000; // Obviously, if they use a value greater than this, then there would be issues. However, it should just be a really large number.
        minIndex = iterOne;

        // Second 'loop' is used to go through the unsorted part of the list. So when iterOne = 0; index 0 is the start of the unsorted part of the list.
        for (int iterTwo=0; iterTwo<size-iterOne; iterTwo++){

            if (array[iterOne+iterTwo] < minVal){
                minVal = array[iterOne+iterTwo];
                minIndex = iterOne + iterTwo;
            }

        }

        // If there is a need to swap the ordering then swap, if not, do nothing.
        if (minIndex != iterOne){
            temp = array[iterOne];
            array[iterOne] = array[minIndex];
            array[minIndex] = temp;
        }

    }

    printf("\nFinal List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

}

int main(){
    int arr[] = {48, 62, 19, 83, 20, 20};

    selectionSort(arr, 6);
    return 0;
}
