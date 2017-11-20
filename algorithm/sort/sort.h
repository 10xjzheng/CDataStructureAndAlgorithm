#ifndef _SORT_H
#define _SORT_H
//插入排序
void insertSort(int *arr, int length);

//归并排序
void mergeSort(int *arr, int p, int r);

//打印数组数据
void printData(int *arr, int length, char *s);

void merge(int *arr, int p, int q, int r);
#endif //_SORT_H