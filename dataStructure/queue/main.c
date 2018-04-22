#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 *  队列测试
 */
int main(int argc, char const *argv[])
{
    LinkQueue q;
    int i = 0;
    QElemType e;
    if(initQueue(&q) != OK) return ERROR;
    //进队列
    for (i = 0; i < 10; ++i)
    {
        if(in(&q, i) == OK)
            printf("in %d success\n", i);
    }
    //遍历打印
    printf("Traverse queue:\n");
    queueTraverse(&q, printData);
    printf("\n");
    //出队列
    for (i = 0; i < 10; ++i)
    {
        out(&q, &e);
        printf("out: %d success \n", e);
    }
}
