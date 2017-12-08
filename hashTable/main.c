#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int main(int argc, char const *argv[])
{
    put("a", "1");  
    put("b", "11");  
    get("a");  
    get("b"); 
    return 0; 
}