#ifndef _SLIST_H
#define _SLIST_H

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
    struct node * next;
} Node;

//链表
typedef struct slist
{
    Node * head;
} Slist;

Node* makeNode(const int data); //生成节点
void destroyNode(Node * node); //销毁节点

void sInit(Slist * list);//初始化
bool sInsert(Slist * list, const int data); //插入
bool sRemove(Slist * list, const int key); //删除
bool sModify(Slist * list, const int key, const int data); //修改
Node* sFind(Slist * list, const int key); //查找
void sTreaverse(Slist * list, void (*func)(Node * p)); //遍历
void sDestroy(Slist * list); //销毁
void printData(Node* p); //print

#endif //_SLIST_H
