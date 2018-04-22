#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

/**
 * 有序单链表测试
 */
int main(int argc, char const *argv[])
{
    Slist nlist;
    int num;
    sInit(&nlist); //初始化
    for(num = 1; num < 10; num++)
    {
        sInsert(&nlist, num);  //插入
    }
    sTreaverse(&nlist, printData);//遍历打印data
    sRemove(&nlist, 3); //移除
    printf("\n");
    sTreaverse(&nlist, printData);
    sModify(&nlist, 8, 44);//修改
    printf("\n");
    sTreaverse(&nlist, printData);
    return 0;
}
