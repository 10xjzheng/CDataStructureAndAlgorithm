#ifndef _QUEUE_H
#define _QUEUE_H

#define OK 1
#define NOPE 0
#define ERROR 0
#define OVERFLOW -2

typedef int QElemType; //元素类型

typedef struct qNode
{
    QElemType data;
    struct qNode *next;
} QNode, *QueuePtr;

typedef int Status; //状态

typedef struct
{
   QueuePtr front;//队头指针,不存数据，front->next是才是真正的对头节点
   QueuePtr rear;//队尾指针
} LinkQueue;

//队列的初始化
Status initQueue(LinkQueue *q);

//销毁栈
Status destroyQueue(LinkQueue *q);

//判断是否为空栈
Status isEmpty(LinkQueue *q);

//获取栈的长度
int queueLength(LinkQueue q);

//获取栈顶指针，空栈返回error
Status getHead(LinkQueue *q, QElemType *e);

//插入
Status in(LinkQueue *q, QElemType e);

//出队
Status out(LinkQueue *q, QElemType *e);

//遍历
Status queueTraverse(LinkQueue *q, void (* visit)(QElemType e));

//print
void printData(QElemType e); 
#endif //_QUEUE_H
