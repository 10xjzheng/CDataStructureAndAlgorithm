#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status initStack(Stack *stack)
{
    stack->base = (SElemTpye *) malloc(sizeof(SElemTpye) * STACK_INIT_SIZE);
    if(!stack->base) exit(ERROR);
    stack->top = stack->base;
    stack->size = STACK_INIT_SIZE;
    return OK;
}

Status getTop(Stack *s, SElemTpye *e)
{
    if(s->top == s->base) return ERROR;
    e = (s->top - 1);
    return OK;
}

Status push(Stack *s, SElemTpye e)
{
    if(s->top - s->base >= s->size)
    {
        s->base = (SElemTpye *) realloc( s->base, (s->size + STACK_INCREMENT) * sizeof(SElemTpye));
        if(!s->base) exit(ERROR);
        s->top = s->base + s->size;
        s->size += STACK_INCREMENT;
    }
    *s->top++ = e;
    return OK;
}

Status pop(Stack *s, SElemTpye *e)
{
    if(s->top == s->base) return ERROR;
    *e = * --s->top;
    return OK;
}

Status destroyStack(Stack *s)
{
    free((Stack *)s);
}

Status isEmpty(Stack *s)
{
    return s->top == s->base;
}

int stackLength(Stack *s)
{
    if(s->top == s->base) return ERROR;
    return s->size;
}

Status stackTraverse(Stack *s, void (* visit)(SElemTpye *e))
{
    SElemTpye *e;
    e = s->top;
    while(e != s->base)
        visit(-- e);
    return OK;
}

void printData(SElemTpye *e)
{
    printf("%d ", *e);
}