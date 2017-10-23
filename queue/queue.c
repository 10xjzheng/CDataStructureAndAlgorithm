#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//队列的初始化
Status initQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr) malloc(sizeof(QNode));
    if(!q->front) exit(OVERFLOW);
    q->front->next = NULL;
    return OK;
}

//销毁队列
Status destroyQueue(LinkQueue *q)
{
    while(q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}

//判断是否为空队列
Status isEmpty(LinkQueue *q)
{
    if(q->front == q->rear) return OK;
    else return NOPE;
}

//获取队列的长度
int queueLength(LinkQueue q)
{
    return 0;
}

//获取队头指针
Status getHead(LinkQueue *q, QElemType *e)
{
    return OK;
}   

//插入
Status in(LinkQueue *q, QElemType e)
{
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return OK;
}

//出队列，并返回队头元素到*e
Status out(LinkQueue *q, QElemType *e)
{
    if(q->front == q->rear) return ERROR;
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;
    free(p);
    return OK;
}

//遍历
Status queueTraverse(LinkQueue *q, void (* visit)(QElemType e))
{
    if(q->front == q->rear) return ERROR;
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p = q->front->next;
    while(1)
    {
        visit(p->data);
        if(p == q->rear) break;
        p = p->next;
    }
    return OK;
}

void printData(QElemType e)
{
    printf("%d ", e);
}