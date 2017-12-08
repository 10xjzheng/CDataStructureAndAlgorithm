#ifndef _SORT_H
#define _SORT_H
//插入排序
void insertSort(int arr[], int length);

//归并排序
void mergeSort(int arr[], int start, int end);
//合并数组
void merge(int arr[], int start, int mid, int end);

//快速排序
void quickSort(int arr[], int start, int end);
//快速排序切分
int partition(int arr[], int start, int end);

//冒泡排序
void bubbleSort(int arr[], int length);

//计数排序法
void countSort(int arr[], int out[], int length, int range);

//基数排序法
void radixSort(int arr[], int output[], int length);

// 基数排序用到的计数排序法
void radixCountSort(int arr[], int out[], int origin[], int length, int range);

//打印数组数据
void printData(int *arr, int length, char *s);

//求最大值
int max(int arr[], int length);
#endif //_SORT_H

