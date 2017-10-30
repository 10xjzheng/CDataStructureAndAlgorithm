#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"

/**
 *  队列测试
 */
int main(int argc, char const *argv[])
{
    int i;
    int arr[10] = {3,5,12,23,56,31,43,35,63,14};
    BitTNode t;
    BitTNode res;
    initBitTree(&t);
    for (i = 0; i < 10; i++)
    {
        if(insertNode(&t, arr[i]) == OK)
            printf("in %d success\n", arr[i]);
    }
    printf("Pre Order:\n");
    preOrderTraverse(&t, printData);
    printf("\nIn Order:\n");
    inOrderTraverse(&t, printData);
    printf("\nPost Order:\n");
    postOrderTraverse(&t, printData);

    if(searchNode(&t, 23, &res) == OK) {
        printf("\nresult: %d\n", res.data);
    }
    return 0;
}
