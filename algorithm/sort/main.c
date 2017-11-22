#include <stdio.h>
#include "sort.h"
#define LEN 10
int main()
{
    int arr[LEN] = {91,2,44,65,32,12,23,21,86,10};
    insertSort(arr, LEN);
    mergeSort(arr, 0, LEN - 1);
    return 0;
}
