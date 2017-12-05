#include <stdio.h>
#include "sort.h"

//插入排序--倒序
void insertSort(int arr[], int length)
{
    int j, i, tmp;
    if(length == 0) {
        return;
    }
    for (i = 1; i < length; i++)
    {
        tmp = arr[i];
        j = i-1;
        while(tmp > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;  
        }
        arr[j + 1] = tmp;
    }
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

//归并排序--合并数组
void merge(int arr[], int start, int mid, int end)
{
    int n1 = (mid - start) + 1;
    int n2 = (end - mid);
    int arr1[n1], arr2[n2];
    int i,j,n;
    for (i = 0; i < n1; ++i)
        arr1[i] = arr[start + i];
    for (j = 0; j < n2; ++j)
        arr2[j] = arr[j + mid +1];
    i = j = 0;
    n = start;
    while(i < n1 && j < n2)  
    {
        if(arr1[i] < arr2[j])
            arr[n] = arr1[i++];
        else 
            arr[n] = arr2[j++];
        n++;
    }
    while(i < n1)
        arr[n++] = arr1[i++];
    while(j < n2)
        arr[n++] = arr2[j++];
}

/**
 * 归并排序法
 */
void mergeSort(int arr[], int start, int end)
{
    int mid;
    if(start < end) {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

/**
 * 快速排序
 */
void quickSort(int arr[], int start, int end)
{
    if(start< end) {
        int mid;
        mid = partition(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}

/**
 * 快速排序切分
 */
int partition(int arr[], int start, int end)
{
    int measure = arr[end];
    int tmp, j, lowNumPointer = start - 1;
    for(j = start; j < end; j++)
    {
        if(arr[j] >= measure)
        {
            lowNumPointer = lowNumPointer+1;
            tmp = arr[j];
            arr[j] = arr[lowNumPointer];
            arr[lowNumPointer] = tmp;
        }
    }
    tmp = arr[end];
    arr[end] = arr[lowNumPointer + 1];
    arr[lowNumPointer + 1] = tmp;
    return lowNumPointer + 1;
}

/**
* 冒泡排序
**/
void bubbleSort(int arr[], int length)
{
    int exchangeFlag = 1, i,j, tmp;
    for (i = 0; i < length && exchangeFlag; ++i)
    {
        exchangeFlag = 0;
        for (j = 0; j < length - i - 1; ++j)
        {
            if(arr[j] > arr[j+1]) {
                exchangeFlag = 1;
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

/**
* 计数排序法
* @parma int range 数值的最大值即范围
**/
void countSort(int arr[], int out[], int length, int range)
{
    int tmp[range], i;
    //初始化
    for (i = 0; i < range + 1; ++i)
        tmp[i] = 0;
    //计算数值出现的次数
    for (i = 0; i < length; ++i)
        tmp[arr[i]] = tmp[arr[i]] + 1;
    //计算数字的下标
    for (i = 1; i < range + 1; ++i){
        tmp[i] = tmp[i] + tmp[i-1];
    }
    //排序结果
    for(i = length - 1; i > -1; i--)
    {
        out[tmp[arr[i]] - 1] = arr[i]; //注意tmp[arr[i]] - 1必须-1，因为计算数字的下标的时候出来的是实际数组的下标+1
        tmp[arr[i]] = tmp[arr[i]] - 1;
    }
}
