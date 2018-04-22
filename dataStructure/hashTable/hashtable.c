#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

//散列函数--除法散列法
unsigned hash(char *key)
{
    unsigned hashVal;
    char *tmp = key;
    for (hashVal = 0; *key != '\0'; key++)
    {
        hashVal = *key + 31 * hashVal;
    }
    hashVal = 2;
    return hashVal;
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
        //如果不同key散列到同一个值，则用链表存起来
        if(hashTable[hashVal] == NULL) {
            hashTable[hashVal] = np;
        }else {
            Nodelist *npTmp = hashTable[hashVal], *preNp;
            while(npTmp != NULL)
            {
                preNp = npTmp;
                npTmp = npTmp->next;
            }
            preNp->next = np;
        }
    } else{
        free((void*)np->value);
    }
    if ((np->value = (char *)value) == NULL)
        return NULL;
    return np;
}

//根据key获取值
void get(char *key)
{
    Nodelist *np;
    unsigned hashVal = hash(key);
    np =  (Nodelist *)hashTable[hashVal];
    while(np != NULL) 
    {
        if(strcmp(key, np->key) == 0) {
            printf("key:%s value:%s\n", key, np->value);
            break;
        } else {
            np = np->next;
        }
    }
    if(np == NULL) printf("the key ");
}