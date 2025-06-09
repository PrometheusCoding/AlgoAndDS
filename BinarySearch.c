#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int* array, int size, int target){

    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right){

        mid = floor((left + right)/2);
        if (array[mid] == target){
            printf("%d was found at index %d\n", target, mid);
            return mid;
        } else {
            if (target < array[mid]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

    }

    printf("%d was not found in the array", target);
    return -1;
}

int main(){
    int arr[] = {1, 32, 42, 85, 93, 104};
    binarySearch(arr, 6, 85);
    return 0;
}