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

Node* make_node(const int data); //生成节点
void destroy_node(Node * node); //销毁节点

void d_init(Dlist * list);//初始化
bool d_insert(Dlist * list, const int data); //插入
bool d_remove(Dlist * list, const int key); //删除
bool d_modify(Dlist * list, const int key, const int data); //修改
Node* d_find(Dlist * list, const int key); //查找
void d_treaverse(Dlist * list, void (*func)(Node* p)); //遍历
void d_destroy(Dlist * list); //销毁
void print_data(Node* p); //print

#endif //_SLIST_H
