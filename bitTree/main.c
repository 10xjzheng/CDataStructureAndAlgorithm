#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"

/**
 *  队列测试
 */
int main(int argc, char const *argv[])
{
    int i;
    BitTree t = NULL;
    initBitTree(t);
    for (i = 0; i < 10; ++i)
    {
        if(insertNode(t, i) == OK)
            printf("in %d success\n", i);
    }
  
}
