#ifndef _BITTREE_H
#define _BITTREE_H
#define OK 1
#define ERROR 0
#define ROOT_VALUE 0 //根的初始值
typedef int TElemType;//元素类型
typedef int Status; //状态

typedef struct BitTNode {
    TElemType data;
    struct BitTNode *lChild, *rChild;
} BitTNode, *BitTree;

//创建一个有根树
Status createBitTree(BitTree t);

//搜索数据所在节点 
Status searchNode(BitTree t, TElemType e);

//插入数据
Status insertNode(BitTree t, TElemType e);

//先序遍历
Status preOrderTraverse(BitTree t, void (*visit)(TElemType e));

//中序遍历
Status inOrderTraverse(BitTree t, void (*visit)(TElemType e));

//后序遍历
Status postOrderTraverse(BitTree t, void (*visit)(TElemType e));

//层序遍历
Status levelOrderTraverse(BitTree t, void (*visit)(TElemType e));

#endif //_BITTREE_H