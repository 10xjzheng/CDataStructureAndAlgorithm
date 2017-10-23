#ifndef _STACK_H
#define _STACK_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define STACK_INIT_SIZE 10 //存储空间的初始化分配
#define STACK_INCREMENT 10 //增量

typedef int SElemTpye; //元素类型
typedef int Status; //元素类型

typedef struct
{
   SElemTpye *base;//栈底指针
   SElemTpye *top;//栈顶指针
   int size;
} Stack;

//栈的初始化
Status initStack(Stack *s);

//销毁栈
Status destroyStack(Stack *s);

//判断是否为空栈
Status isEmpty(Stack *s);

//获取栈的长度
int stackLength(Stack *s);

//获取栈顶指针，空栈返回error
Status getTop(Stack *s, SElemTpye *e);

//入栈
Status push(Stack *s, SElemTpye e);

//出栈
Status pop(Stack *s, SElemTpye *e);

//遍历
Status stackTraverse(Stack *s, void (* visit)(SElemTpye *e));

void printData(SElemTpye *e); //print
#endif //_STACK_H
