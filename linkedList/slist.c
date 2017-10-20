#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "slist.h"

//创建节点
static Node* make_node(const int data)
{
    Node * p = (Node *)malloc(sizeof(node));
    assert(p != NULL);
    p->data = data;
    p->next = NULL;
    return p;
}

//销毁节点
static void destroy_node(void * node)
{
    free((Node *) node);
}

//带头节点的单链表
void s_init(Slist * list)
{
    list->head = make_node(INI_MIN);
}

//按顺序插入
bool s_insert(Slist * list, const int data)
{
    Node * ptem = list->head;
    Node * node;
    while( ptem->next != NULL && ptem->data < data )
    {
        if(ptem->next->data <= data)
            ptem = ptem->next;
        else
            break;
    }
    if( ptem->data == data )
        return false;
    node = make_node(data);
    node->next = ptem->next;
    ptem->next = node;
    return true;
}

//移除节点
bool s_remove(Slist * list, const int key)
{
    Node * previous = list->head;
    Node * current;

    //找到删除节点
    while( ( current = previous->next ) != NULL && current->data != key)
        if( current->data > key ) 
            return false;
        else
            previous = previous->next;
    if ( current == NULL )
        return false;
    previous->next = current->next;
    free( current );

    return true;
}

//修改,先删后插入，因为这是有序链表
bool s_modify(Slist * list, const int key, const int data)
{
    if( s_remove(list, key) )
        s_insert(list, data);
    else
        return false;
    return true;
}

//找到返回关键字的节点，否则返回null指针
bool s_find()(Slist * list, const int key)
{
    Node * current = list->head;
    while ( (current = current->next) != NULL && current->data != key)
        if( current->data > key )
            return NULL;
    return current;
}

//遍历
void s_treaverse( Slist * slist, void (*func) (void * p) )
{
    Node * current = list->head;
    while ( (current = current->next) != NULL )
        func(current);
}

//销毁节点
void s_destrory(Slist * list)
{
    s_treaverse(list, destroy_node);
    free(list->head);
}
