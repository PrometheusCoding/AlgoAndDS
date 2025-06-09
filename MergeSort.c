#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int* array, int left, int mid, int right){

    int iterOne, iterTwo, iterThree;
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int leftArray[sizeLeft], rightArray[sizeRight];

    // Create copies of the two arrays
    for (iterOne = 0; iterOne < sizeLeft; iterOne++){
        leftArray[iterOne] = array[left + iterOne];
    }

    for (iterTwo = 0; iterTwo < sizeRight; iterTwo++){
        rightArray[iterTwo] = array[mid + 1 + iterTwo];
    }


    iterOne = 0;
    iterTwo = 0;
    iterThree = left;

    while (iterOne < sizeLeft && iterTwo < sizeRight) {
        if (leftArray[iterOne] <= rightArray[iterTwo]) {
            array[iterThree] = leftArray[iterOne];
            iterOne++;
        }
        else {
            array[iterThree] = rightArray[iterTwo];
            iterTwo++;
        }
        iterThree++;
    }

    while (iterOne < sizeLeft) {
        array[iterThree] = leftArray[iterOne];
        iterOne++;
        iterThree++;
    }

    while (iterTwo < sizeRight) {
        array[iterThree] = rightArray[iterTwo];
        iterTwo++;
        iterThree++;
    }
}

void mergeSort(int* array, int left, int right){

    //int mid = floor((left + right)/2);
    int mid = left + (right - left) / 2;

    // This works by recursively calling mergeSort on smaller parts of the initial array and then merging the smaller parts together.
    if (left < right){

        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);

        merge(array, left, mid, right);
    }
}

int main(){
    int array[] = {48, 62, 19, 83, 20, 20};

    printf("Initial List = [ ");
    for (int iter = 0; iter < 6; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");

    mergeSort(array, 0, 5);

    printf("\nFinal List = [ ");
    for (int iter = 0; iter < 6; iter++){
        printf("%d ", array[iter]);
    }
    printf("]");


    return 0;
}