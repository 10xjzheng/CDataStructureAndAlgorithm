#include <stdio.h>
#include "sort.h"

//插入排序
void insertSort(int *arr, int length)
{
    int j, i, tmp;
    if(length == 0) {
        return;
    }
    for (i = 1; i < length; i++)
    {
        tmp = *(arr+i);
        j = i-1;
        while(tmp < *(arr+j) && j >= 0)
        {
            *(arr + j + 1) = *(arr + j);
            j--;  
        }
        *(arr + j + 1) = tmp;
    }
    printData(arr, length, "insert sort:");
}

//打印数组数据
void printData(int *arr, int length, char *s)
{
    int i;
    printf("\n%s\n", s);
    for (i = 0; i < length; ++i)
    {
        printf("%d ", *(arr+i));
    }
}

//合并数组
void merge(int *arr, int p, int q, int r)
{
    int n1, n2, n, a, b, i;
    n1 = q - p + 1; 
    n2 = r - q;
    int arr1[n1], arr2[n2];
    for (i = 0; i < n1; ++i)
    {
        arr1[i] = *(arr + p + i);
    }
    for (i = 0; i < n2; ++i)
    {
        arr2[i] = *(arr + q + 1 + i);
    }
    a = b = n = 0;
    while (a < n1 && b < n2)
    {
        if(arr1[a] < arr2[b])
        {
            *(arr + n) = arr1[a];
            a++;
        } else {
            *(arr + n) = arr2[b];
            b++;
        }
        n++;
    }
    while(n < r+1 && a < n1) {
        *(arr + n) = arr1[a++];
        n++;
    }
    while(n < r+1 && b < n2) {
        *(arr + n) = arr2[b++];
        n++;
    }
}

void mergeSort(int *arr, int p, int r)
{
    int q;
    if(p < r) q = (r-p)/2;
    mergeSort(arr, p, q);
    mergeSort(arr, p+1, r);
    merge(arr, p, q, r);
}
