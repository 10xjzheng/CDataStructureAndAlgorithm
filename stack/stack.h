#ifndef _STACK_H
#define _STACK_H

#define OK 0
#define ERROR 1
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
Status init_stack(Stack *s);

//销毁栈
Status destroy_stack(Stack *s);

//判断是否为空栈
Status is_empty(Stack *s);

//获取栈的长度
int stack_length(Stack *s);

//获取栈顶指针，空栈返回error
Status get_top(Stack *s, SElemTpye *e);

//入栈
Status push(Stack *s, SElemTpye e);

//出栈
Status pop(Stack *s, SElemTpye *e);

//遍历
Status stack_traverse(Stack *s, void (* visit)(SElemTpye *e));

void print_data(SElemTpye *e); //print
#endif //_STACK_H
