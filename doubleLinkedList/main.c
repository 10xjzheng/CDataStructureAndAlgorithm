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
    d_init(&nlist); //初始化
    for(num = 1; num < 10; num++)
    {
        d_insert(&nlist, num);  //插入
    }
    d_treaverse(&nlist, print_data);//遍历打印data
    printf("\nremove:3\n");
    d_remove(&nlist, 3); //移除
    d_treaverse(&nlist, print_data);
    printf("\nmodify:8 to 44\n");
    d_modify(&nlist, 8, 44);//修改
    d_treaverse(&nlist, print_data);

    //查找
    Node* node = d_find(&nlist, 6);
    printf("\nfind:%d previous:%d next:%d\n", node->data, node->previous->data, node->next->data);
    return 0;
}
