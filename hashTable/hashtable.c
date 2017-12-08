#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

//散列函数--除法散列法
unsigned hash(char *key)
{
    unsigned hashVal;
    for (hashVal = 0; *key != '\0'; key++)
    {
        hashVal = *key + 31 * hashVal;
    }
    return hashVal % HASHSIZE;
}

//查询key
Nodelist *search(char *key)
{
    Nodelist *np;
    for (np = hashTable[hash(key)]; np != NULL; np = np->next)
    {
        if(strcmp(key, np->key) == 0)
            return np;
    }
    return NULL;
}

//插入到哈希表
Nodelist *put(char *key, char *value)
{
    Nodelist *np;
    unsigned hashVal;
    if((np = search(key)) == NULL) 
    {
        np = (Nodelist *) malloc(sizeof(Nodelist));
        if(np == NULL || (np->key = (char *)key) == NULL)
            return NULL;
        np->next = NULL;
        hashVal = hash(key);
        hashTable[hashVal] = np;
    } else{
        free((void*)np->value);
    }
    if ((np->value = (char *)value) == NULL)
        return NULL;
    return np;
}

//获取值
void get(char *key)
{
    Nodelist *np;
    unsigned hashVal = hash(key);
    np =  (Nodelist *)hashTable[hashVal];
    if(np == NULL)
        printf("\n");
    else 
        printf("%s\n", np->value);
}

//打印节点
void printNode(Nodelist *np)
{
    if(np != NULL)
    {
        printf("key: %s value:%s\t", np->key, np->value);  
        printNode(np->next); 
    }
}

//打印哈希表
void print()
{
    int i = 0;
    for (; i < HASHSIZE; ++i)
    {
        printNode(hashTable[i]);
        printf("\n");
    }    
}