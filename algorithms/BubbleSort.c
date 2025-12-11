#include <stdio.h>
#include <stdlib.h>

/*
How does bubble sort work?
Go through the list and for every two consecutive index, if the first one is greater than the second one (if you are sorting in ascending fashion) then swap.
Do so until there is no swap needed any more.

Since we do this at most n+1 times, going through n items, the big O is O(n^2)
*/

void bubbleSort(int* array, int size){
    printf("Initial List = [ ");
    for (int iter = 0; iter < size; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

    int swapMade;
    int temp;

    for (int iterOne=0; iterOne < size-1; iterOne++){

        for (int iterTwo=0; iterTwo < size-iterOne-1; iterTwo++){
            
            if (array[iterTwo] > array[iterTwo + 1]){
                swapMade = 1;
                temp = array[iterTwo];
                array[iterTwo] = array[iterTwo + 1];
                array[iterTwo + 1] = temp;
            }

        }

        if (swapMade == 0){
            break;
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
    bubbleSort(arr, 6);
    return 0;
}