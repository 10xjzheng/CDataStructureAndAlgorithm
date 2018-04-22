#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/**
 * 有序双链表测试
 */
int main(int argc, char const *argv[])
{
    Dlist nlist;
    int num;
    dInit(&nlist); //初始化
    for(num = 1; num < 10; num++)
    {
        dInsert(&nlist, num);  //插入
    }
    dTreaverse(&nlist, printData);//遍历打印data
    printf("\nremove:3\n");
    dRemove(&nlist, 3); //移除
    dTreaverse(&nlist, printData);
    printf("\nmodify:8 to 44\n");
    dModify(&nlist, 8, 44);//修改
    dTreaverse(&nlist, printData);

    //查找
    Node* node = dFind(&nlist, 6);
    printf("\nfind:%d previous:%d next:%d\n", node->data, node->previous->data, node->next->data);
    return 0;
}
