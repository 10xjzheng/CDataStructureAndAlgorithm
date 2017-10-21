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
    s_init(&nlist); //初始化
    for(num = 1; num < 10; num++)
    {
        s_insert(&nlist, num);  //插入
    }
    s_treaverse(&nlist, print_data);//遍历打印data
    s_remove(&nlist, 3); //移除
    printf("\n");
    s_treaverse(&nlist, print_data);
    s_modify(&nlist, 8, 44);//修改
    printf("\n");
    s_treaverse(&nlist, print_data);
    return 0;
}
