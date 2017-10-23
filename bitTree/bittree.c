#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"

//树的初始化
Status initBitTree(BitTree t)
{
    t->data = ROOT_VALUE;
    t->lChild = t->rChild = NULL;
    return OK;
}

//搜索数据所在节点 
BitTNode* searchNode(BitTree t, TElemType e)
{
    if(!t) return ERROR;
    BitTNode *n;
    while(n != NULL)
    {
        if(e > n->data) 
        {
            n = n->rChild;
        } else {
            n = n->lChild;
        }
    }
}

//插入数据
Status insertNode(BitTree t, TElemType e)
{

}

//先序遍历
Status preOrderTraverse(BitTree t, void (*visit)(TElemType e))
{

}

//中序遍历
Status inOrderTraverse(BitTree t, void (*visit)(TElemType e));

//后序遍历
Status postOrderTraverse(BitTree t, void (*visit)(TElemType e));

//层序遍历
Status levelOrderTraverse(BitTree t, void (*visit)(TElemType e));

