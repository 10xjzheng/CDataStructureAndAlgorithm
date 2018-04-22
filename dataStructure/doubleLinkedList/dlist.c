#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
//创建节点
Node* makeNode(const int data)
{
    Node * p = (Node *)malloc(sizeof(Node));
    if( p == NULL )
    {
        exit(1);
        printf("Malloc failed");
    }
    p->data = data;
    p->next = NULL;
    p->previous = NULL;
    return p;
}

//销毁节点
void destroyNode(Node* node)
{
    free((Node *) node);
}

//带头节点的单链表
void dInit(Dlist * list)
{
    list->head = makeNode(INI_MIN);
}

//按顺序插入
bool dInsert(Dlist * list, const int data)
{
    Node * ptem = list->head;
    Node* current;
    Node * node;
    node = makeNode(data);
    if(ptem->data > data)
    {
        list->head = node;
        node->next = ptem;
        ptem->previous = node;
    } else {
        while((current = ptem->next) != NULL && current->data < data )
            ptem = ptem->next;

        ptem->next = node;
        node->previous = ptem;
        if( current != NULL)
        {
            node->next = current;
            current->previous = node;
        }
    }
    return true;
}


//移除节点
bool dRemove(Dlist * list, const int key)
{
    Node* previous = list->head;
    Node* current;
    //删除头结点
    if( previous->data == key )
    {
        list->head = previous->next;
        return true;
    }
    //找到删除节点
    while( ( current = previous->next ) != NULL && current->data != key)
        previous = previous->next;

    if(current != NULL)
    {
        if (current->next != NULL)
        {
            previous->next = current->next;
            current->next->previous = previous;
        } else {
            previous->next = NULL;
        }
        free( current );
    }
    return true;
}

//修改,先删后插入，因为这是有序链表
bool dModify(Dlist * list, const int key, const int data)
{
    if( dRemove(list, key) )
        dInsert(list, data);
    else
        return false;
    return true;
}

//找到返回关键字的节点，否则返回null指针
Node* dFind(Dlist * list, const int key)
{
    Node * current = list->head;
    while ( (current = current->next) != NULL && current->data != key)
        if( current->data > key )
            return NULL;
    return current;
}

//遍历
void dTreaverse(Dlist * dlist, void (*func) (Node* p))
{
    Node * current = dlist->head;
    func(current);
    while ( (current = current->next) != NULL )
        func(current);
}

//销毁节点
void dDestrory(Dlist * list)
{
    dTreaverse(list, destroyNode);
    free(list->head);
}

//print
void printData(Node * p)
{
    printf("%d ", p->data);
}
