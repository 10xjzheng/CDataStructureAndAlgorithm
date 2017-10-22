#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 *  队列测试
 */
int main(int argc, char const *argv[])
{
    Stack s;
    SElemTpye e;
    int i;
    init_queue(&s);
    for (i = 1; i < 5; ++i)
    {
        scanf("%d", &e);
        if(push(&s, e) == OK)
            printf("push %d success\n", e);
    }
    printf("traverse this queue:", e);
    queue_traverse(&s, print_data);
    printf("\n", e);
    for (i = 1; i < 5; ++i)
    {
        if(pop(&s, &e) == OK)
            printf("pop %d success\n", e);
    }
    destroy_queue(&s);
}
