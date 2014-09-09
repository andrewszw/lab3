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
    //al = malloc((al->elementSize)*4); 
    al -> array = (void*)malloc((getSize(type)) * al ->arraySize);
    return al;
}

int getSize(primitiveType type)
{
    if(type == charType)
        return sizeof(char);
    else if(type == shortType)
        return sizeof(short);
    else if(type == intType)
        return sizeof(int);
    else
        return 0;
}

void addElement(arrayList * arylstP, void * element)
{
   int i;
   if(arylstP -> numElements == arylstP -> arraySize)
   {
       char * newarray = (char *) malloc(2 * arylstP -> numElements * arylstP -> elementSize);
       
       for(i = 0; i < (arylstP -> numElements * arylstP -> elementSize); i++)
       {
           newarray[i] = ((char *)arylstP->array)[i]; 
       }
       free(arylstP -> array);
       arylstP->array = newarray;
       arylstP->arraySize = arylstP -> arraySize*2;
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
   arylstP -> numElements++;
}

void removeElement(arrayList * arylstP, int index)
{
   int i;
   for(i = index; i < arylstP ->numElements - 1; i++)
   {
       if(arylstP -> type == charType)
       {
           char* value = (char*) arylstP -> array;
           value[i] = value[i + 1];
       }
       else if(arylstP -> type == shortType)
       {
           short* value = (short*) arylstP -> array;
           value[i] = value[i + 1];
       }
       else if(arylstP -> type == intType)
       {
           int* value = (int*) arylstP -> array;
           value[i] = value[i + 1];
       }
   }
   arylstP -> numElements--;
}

void printArray(arrayList * arylstP)
{
   int i;
   char* temp1;
   short* temp2;
   int* temp3;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
      {
         temp1 = (char*)arylstP -> array;
         printf("%02x ", (char)temp1[i] & 0xff);
      }
      else if (arylstP->type == shortType)
      {
         temp2 = (short*)arylstP -> array;
         printf("%04x ", (short)temp2[i] & 0xffff);
      }
      else if (arylstP->type == intType)
      {
         temp3 = (int*)arylstP -> array;
         printf("%08x ", (int)temp3[i] & 0xffffffff);
      }
   }
   printf("\n");
}

