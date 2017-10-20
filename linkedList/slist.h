#ifndef _SLIST_H
#define _SLIST_H

#define INI_MIN 10

typedef struct node
{
    int data;
    struct node * next;
} Node;

typedef struct slist
{
    Node * head;
} Slist;

static Node* make_node(const int data); //生成节点
static void destroy_node(void * node); //销毁节点

void s_init(Slist * list);//初始化
bool s_insert(Slist * list, const int data); //插入
bool s_remove(Slist * list, const int key); //删除
bool s_modify(Slist * list, const int key, const int data); //修改
Node * s_find(Slist * list, const int key); //查找
void s_treaverse(Slist * list, void (*func)(void * p)); //遍历
void s_destroy(Slist * list); //销毁

#endif //_SLIST_H
