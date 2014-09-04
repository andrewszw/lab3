#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

arrayList * initialize(primitiveType type)
{
    arrayList * al = (arrayList*)malloc(sizeof(arrayList));
    al->arraySize = 4;
    al->numElements = 0;
    al->type = type;
    al->elementSize = getSize(type);
    al = malloc(getSize(type)*4); 
    return al;
}

int getSize(primitiveType type)
{
    if(type == charType)
        return sizeof(char);
    else if(type == shortType)
        return sizeof(short);
    else
        return sizeof(int);
}

void addElement(arrayList * arylstP, void * element)
{
   return;
}

void removeElement(arrayList * arylstP, int index)
{
   return;
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}

