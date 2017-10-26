#ifndef _BITTREE_H
#define _BITTREE_H
#define OK 1
#define ERROR 0
#define ROOT_VALUE 0 //根的初始值
typedef int TElemType;//元素类型
typedef int Status; //状态

typedef struct bitTNode {
    TElemType data;
    struct bitTNode *lChild, *rChild;
} BitTNode;

BitTNode* makeNode(TElemType e);
//创建一个有根树
Status initBitTree(BitTNode *t);

//搜索数据所在节点 
Status searchNode(BitTNode* t, TElemType e);

//插入数据
Status insertNode(BitTNode* t, TElemType e);

//先序遍历
Status preOrderTraverse(BitTNode* t, void (*visit)(TElemType e));

//中序遍历
Status inOrderTraverse(BitTNode* t, void (*visit)(TElemType e));

//后序遍历
Status postOrderTraverse(BitTNode* t, void (*visit)(TElemType e));

//层序遍历
Status levelOrderTraverse(BitTNode* t, void (*visit)(TElemType e));

#endif //_BITTREE_H