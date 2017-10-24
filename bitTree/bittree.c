#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"
#include "stack.h"

//树的初始化
Status initBitTree(BitTree t)
{
    t->data = ROOT_VALUE;
    t->lChild = t->rChild = NULL;
    return OK;
}

//搜索数据所在节点 
//用先序非递归遍历查找
Status searchNode(BitTree t, TElemType e)
{
    return OK;
}

//插入数据
Status insertNode(BitTree t, TElemType e)
{
    if(t == NULL) {
        BitTNode temp;
        temp.lChild = temp.rChild = NULL;
        *t = temp;
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
Status preOrderTraverse(BitTree t, void (*visit)(TElemType e))
{
    return OK;
}

//中序遍历
Status inOrderTraverse(BitTree t, void (*visit)(TElemType e))
{
    Stack s;
    BitTNode *p;
    initStack(&s);
    push(&s, t);
    while(!isEmpty(&s))
    {
        while(getTop(&s, p) && p) push(&s, p->lChild);
        pop(&s, p);
        if(!isEmpty(&s))
        {
            pop(&s, p);
            visit(p->data);
            push(&s, p->rChild);
        }
    }
    return OK;
}

//后序遍历
Status postOrderTraverse(BitTree t, void (*visit)(TElemType e))
{
    return OK;
}

//层序遍历
Status levelOrderTraverse(BitTree t, void (*visit)(TElemType e))
{
    return OK;
}

