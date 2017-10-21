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

Node* make_node(const int data); //生成节点
void destroy_node(Node * node); //销毁节点

void s_init(Slist * list);//初始化
bool s_insert(Slist * list, const int data); //插入
bool s_remove(Slist * list, const int key); //删除
bool s_modify(Slist * list, const int key, const int data); //修改
Node* s_find(Slist * list, const int key); //查找
void s_treaverse(Slist * list, void (*func)(Node * p)); //遍历
void s_destroy(Slist * list); //销毁
void print_data(Node* p); //print

#endif //_SLIST_H
