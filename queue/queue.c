#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Status init_queue(Queue *queue)
{
    queue->base = (SElemTpye *) malloc(sizeof(SElemTpye) * STACK_INIT_SIZE);
    if(!queue->base) exit(ERROR);
    queue->top = queue->base;
    queue->size = STACK_INIT_SIZE;
    return OK;
}

Status get_top(Queue *s, SElemTpye *e)
{
    if(s->top == s->base) return ERROR;
    e = (s->top - 1);
    return OK;
}

Status push(Queue *s, SElemTpye e)
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

Status pop(Queue *s, SElemTpye *e)
{
    if(s->top == s->base) return ERROR;
    *e = * --s->top;
    return OK;
}

Status destroy_queue(Queue *s)
{
    free((Queue *)s);
}

Status is_empty(Queue *s)
{
    return s->top == s->base;
}

int queue_length(Queue *s)
{
    if(s->top == s->base) return ERROR;
    return s->size;
}

Status queue_traverse(Queue *s, void (* visit)(SElemTpye *e))
{
    SElemTpye *e;
    e = s->top;
    while(e != s->base)
        visit(-- e);
    return OK;
}

void print_data(SElemTpye *e)
{
    printf("%d ", *e);
}