#include <stdio.h>
#include <stdlib.h>
#include "bittree.h"

//栈的初始化
Status initStack(Stack *stack)
{
    stack->base = (BitTNode *) malloc(sizeof(BitTNode) * STACK_INIT_SIZE);
    if(!stack->base) exit(ERROR);
    stack->top = stack->base;
    stack->size = STACK_INIT_SIZE;
    return OK;
}

//判断是否为空栈
Status isEmpty(Stack *s)
{
    return s->top == s->base;
}

//获取栈顶指针，空栈返回error
Status getTop(Stack *s, BitTNode *e)
{
    if(s->top == s->base) return ERROR;
    e = (s->top - 1);
    return OK;
}

//入栈
Status push(Stack *s, BitTNode e)
{
    if(s->top - s->base >= s->size)
    {
        s->base = (BitTNode *) realloc( s->base, (s->size + STACK_INCREMENT) * sizeof(BitTNode));
        if(!s->base) exit(ERROR);
        s->top = s->base + s->size;
        s->size += STACK_INCREMENT;
    }
    *s->top++ = e;
    return OK;
}

//出栈
Status pop(Stack *s, BitTNode *e)
{
    if(s->top == s->base) return ERROR;
    *e = * --s->top;
    return OK;
}

//生成节点
BitTNode* makeNode(TElemType e)
{
    BitTNode* temp = (BitTNode*)malloc(sizeof(BitTNode));
    temp->lChild = temp->rChild = NULL;
    temp->data = e;
    return temp;
}

//树的初始化
Status initBitTree(BitTNode *t)
{
    t->data = ROOT_VALUE;
    t->lChild = t->rChild = NULL;
    return OK;
}

//搜索数据所在节点 
//用先序非递归遍历查找
Status searchNode(BitTNode* t, TElemType e, BitTNode *res)
{
    if(t == NULL) return ERROR;
    Stack s;
    BitTNode* p = t;
    BitTNode tmp;
    initStack(&s);
    push(&s, *t);
    while(!isEmpty(&s) || p)
    {
        while(p)
        {
            push(&s, *p);
            p = p->lChild;
        }

        if(!isEmpty(&s))
        {
            pop(&s, &tmp);
            if(tmp.data == e) {
                *res = tmp;
                return OK;
            }
            p = tmp.rChild;
        }
    }
    return ERROR;
}

//插入数据
Status insertNode(BitTNode* t, TElemType e)
{
    if(t== NULL) {
        return ERROR;   
    }
    if(e < (t->data))
    {
        if(t->lChild == NULL) {       
            t->lChild = makeNode(e);
            return OK;
        } else {
            insertNode(t->lChild, e);
        }
    } else {
        if(t->rChild == NULL) {
            t->rChild = makeNode(e);
            return OK;
        } else {
            insertNode(t->rChild, e);
        }
    }
    return OK;
}

//先序遍历
Status preOrderTraverse(BitTNode* t, Status (*visit)(TElemType e))
{
    if(t) {
        if(visit(t->data))
            if(preOrderTraverse(t->lChild, visit)) 
                if(preOrderTraverse(t->rChild, visit)) return OK;
    }   
    return OK;
}

//中序遍历
Status inOrderTraverse(BitTNode* t, Status (*visit)(TElemType e))
{
    if(t) {
        if(preOrderTraverse(t->lChild, visit)) 
            if(visit(t->data))
                if(preOrderTraverse(t->rChild, visit)) return OK;
    }   
    return OK;
}

//后序遍历
Status postOrderTraverse(BitTNode* t, Status (*visit)(TElemType e))
{
    if(t) {
        if(preOrderTraverse(t->lChild, visit)) 
            if(preOrderTraverse(t->rChild, visit)) 
                if(visit(t->data)) return OK;
    }   
    return OK;
}


//print
Status printData(TElemType e)
{
    printf("%d ", e);
    return OK;
}
