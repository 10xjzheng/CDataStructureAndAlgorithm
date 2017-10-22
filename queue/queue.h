#ifndef _QUEUE_H
#define _QUEUE_H

#define OK 0
#define ERROR 1

typedef int QElemType; //元素类型

typedef struct qNode
{
    QElemType data;
    struct qNode *next;
} QNode, *QueuePtr;

typedef int Status; //状态

typedef struct
{
   QueuePtr front;//队头指针
   QueuePtr rear;//队尾指针
} LinkQueue;

//栈的初始化
Status initQueue(LinkQueue *q);

//销毁栈
Status destroyQueue(Queue *q);

//判断是否为空栈
Status is_empty(Queue *q);

//获取栈的长度
int queue_length(Queue *q);

//获取栈顶指针，空栈返回error
Status get_top(Queue *q, QElemType *e);

//入栈
Status push(Queue *q, QElemType e);

//出栈
Status pop(Queue *q, QElemType *e);

//遍历
Status queue_traverse(Queue *q, void (* visit)(QElemType *e));

void print_data(QElemType *e); //print
#endif //_QUEUE_H
