#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
How does binary search work?

A prerequisite to use a binary search is to know that the list is sorted in some testable/comparable way.
So we first check the middle index to see if it is the target value. If not, then we compare that middle value to the target and check if we should 'discard' the
indexes before or after the middle. Then we keep repeating this process until the value is found. If the size of the array to search becomes 1, and that value is
not the target value, then the search finds that the value is not in the list.

Since we are effectively halving the search space every time, the time complexity of the binary search is O(logn)
*/

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