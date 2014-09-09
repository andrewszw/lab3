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
    al = malloc((al->elementSize)*4); 
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
   int i;
   if(arylstP -> numElements == arylstP -> arraySize)
   {
       char * newarray = (char *) malloc(2* arylstP -> numElements * arylstP -> elementSize);
       for(i = 0; i < (arylstP -> numElements * arylstP -> elementSize); i++)
       {
           newarray[i] = ((char *)arylstP->array)[i];
       }
   }
   if(arylstP -> type == charType)
   {
       ((char *)arylstP -> array)[arylstP -> numElements] = *((char *)element);
   }
   else if(arylstP -> type == shortType)
   {
       ((short *)arylstP -> array)[arylstP -> numElements] = *((short *)element);
   }
   else if(arylstP -> type == intType)
   {
       ((int *)arylstP -> array)[arylstP -> numElements] = *((int *)element);
   }
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

