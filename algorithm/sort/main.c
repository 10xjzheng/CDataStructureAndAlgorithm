#include <stdio.h>
#include "sort.h"

int main()
{
    int length, arr[] = {1,3,5,7,9,2,4,6,8};
    length = sizeof(arr)/sizeof(int);
    //printData(arr, length, "original array:");
    //insertSort(arr, length);
    mergeSort(arr, 0, 8);
    printData(arr, length, "mergeSort array:");
    return 0;
}
