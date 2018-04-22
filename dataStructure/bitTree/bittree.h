#ifndef _BITTREE_H
#define _BITTREE_H
#define OK 1
#define ERROR 0
#define ROOT_VALUE 30 //根的初始值
typedef int TElemType;//元素类型
typedef int Status; //状态

//树节点
typedef struct bitTNode {
    TElemType data;
    struct bitTNode *lChild, *rChild;
} BitTNode;

//栈
#define STACK_INIT_SIZE 10 //存储空间的初始化分配
#define STACK_INCREMENT 10 //增量
typedef struct
{
   BitTNode *base;//栈底指针
   BitTNode *top;//栈顶指针
   int size;
} Stack;

//print
Status printData(TElemType e); 

//栈的初始化
Status initStack(Stack *s);

//判断是否为空栈
Status isEmpty(Stack *s);

//获取栈顶指针，空栈返回error
Status getTop(Stack *s, BitTNode *e);

//入栈
Status push(Stack *s, BitTNode e);

//出栈
Status pop(Stack *s, BitTNode *e);

//生成节点
BitTNode* makeNode(TElemType e);

//创建一个有根树
Status initBitTree(BitTNode *t);

//搜索数据所在节点 
Status searchNode(BitTNode* t, TElemType e, BitTNode *res);

//插入数据
Status insertNode(BitTNode* t, TElemType e);

//先序遍历
Status preOrderTraverse(BitTNode* t, Status (*visit)(TElemType e));

//中序遍历
Status inOrderTraverse(BitTNode* t, Status (*visit)(TElemType e));

//后序遍历
Status postOrderTraverse(BitTNode* t, Status (*visit)(TElemType e));



#endif //_BITTREE_H