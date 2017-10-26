#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"

/**
 *  队列测试
 */
int main(int argc, char const *argv[])
{
    int i;
    BitTNode t;
    initBitTree(&t);
    for (i = 1; i < 10; ++i)
    {
        if(insertNode(&t, i) == OK)
            printf("in %d success\n", i);
    }
    printf("out %d\n", t.rChild->rChild->data);
    return 0;
}
