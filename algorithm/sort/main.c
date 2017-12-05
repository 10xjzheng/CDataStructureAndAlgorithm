#include <stdio.h>
#include "sort.h"
#define LEN 5
int main()
{
    int arr[LEN] = {4,2,3,4,5};
    printData(arr, LEN, "original array:");
    //冒泡排序--升序
    bubbleSort(arr, LEN);
    printData(arr, LEN, "insert sort:");
    //插入排序--降序
    insertSort(arr, LEN);
    printData(arr, LEN, "insert sort:");
    //归并排序--升序
    mergeSort(arr, 0, LEN - 1);
    printData(arr, LEN, "merge sort:");
    //快速排序--降序
    quickSort(arr, 0, LEN - 1);
    printData(arr, LEN, "quick sort:");
    //计数排序法
    int out[LEN];
    countSort(arr, out, LEN, 5);
    printData(out, LEN, "count sort:");
    return 0;
}
