#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"

//树的初始化
Status initBitTree(BitTNode *t)
{
    t->data = ROOT_VALUE;
    t->lChild = t->rChild = NULL;
    return OK;
}

//搜索数据所在节点 
//用先序非递归遍历查找
Status searchNode(BitTNode* t, TElemType e)
{
    return OK;
}

//插入数据
Status insertNode(BitTNode* t, TElemType e)
{
    if(t == NULL) {
        BitTNode* temp = (BitTNode*)malloc(sizeof(BitTNode));
        temp.lChild = temp.rChild = NULL;
        t = temp;
        return OK;   
    }
    if(e < (t->data))
    {
        insertNode(t->lChild, e);
    } else {
        insertNode(t->rChild, e);
    }
    return OK;
}

//先序遍历
Status preOrderTraverse(BitTNode* t, void (*visit)(TElemType e))
{
    return OK;
}

//中序遍历
Status inOrderTraverse(BitTNode* t, void (*visit)(TElemType e))
{
    return OK;
}

//后序遍历
Status postOrderTraverse(BitTNode* t, void (*visit)(TElemType e))
{
    return OK;
}

//层序遍历
Status levelOrderTraverse(BitTNode* t, void (*visit)(TElemType e))
{
    return OK;
}

