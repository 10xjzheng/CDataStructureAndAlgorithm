#ifndef _DLIST_H
#define _DLIST_H

#define INI_MIN 0
//定义布尔型
typedef enum 
{
    false, true
} bool;
//节点
typedef struct node
{
    int data;
    struct node * previous;
    struct node * next;
} Node;

//链表
typedef struct dlist
{
    Node * head;
} Dlist;

Node* makeNode(const int data); //生成节点
void destroyNode(Node * node); //销毁节点

void dInit(Dlist * list);//初始化
bool dInsert(Dlist * list, const int data); //插入
bool dRemove(Dlist * list, const int key); //删除
bool dModify(Dlist * list, const int key, const int data); //修改
Node* dFind(Dlist * list, const int key); //查找
void dTreaverse(Dlist * list, void (*func)(Node* p)); //遍历
void dDestroy(Dlist * list); //销毁
void printData(Node* p); //print

#endif //_DLIST_H
