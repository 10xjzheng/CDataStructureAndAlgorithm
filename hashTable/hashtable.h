#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define HASHSIZE 101

//哈希表元素
typedef struct nodelist
{
    struct nodelist *next; //链表法的链表
    char *key; //哈希的key
    char *value; //哈希的值
} Nodelist;

//哈希表
static Nodelist *hashTable[HASHSIZE]; 


//散列函数--除法散列法
unsigned hash(char *key);

//查询key
Nodelist *search(char *key);

//插入到哈希表
Nodelist *put(char *key, char *value);

//根据key获取值
void get(char *key);

#endif //_HASHTABLE_H

