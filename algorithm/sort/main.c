#include <stdio.h>
#include "sort.h"
#define LEN 10
int main()
{
    int arr[LEN] = {86,2,34,65,32,12,23,87,14,91};
    printData(arr, LEN, "original array:");
    //插入排序--降序
    insertSort(arr, LEN);
    printData(arr, LEN, "insert sort:");
    //归并排序--升序
    mergeSort(arr, 0, LEN - 1);
    printData(arr, LEN, "merge sort:");
    //快速排序--降序
    quickSort(arr, 0, LEN - 1);
    printData(arr, LEN, "quick sort:");
    return 0;
}
