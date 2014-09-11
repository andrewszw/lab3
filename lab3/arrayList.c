#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

/**
 * @author: Zachary Andrews
 *
 * @userid: andrewszw
 *
 * This program is designed to implement an "arraylist" in C.
 * This is achieved by passing a parameter to the initialize function
 * that indicates the type of element to be stored in the array.
 * There is a function to initialize the array, add an element to the array,
 * remove an element from the array, and print the array
 **/

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/**
 * initialize: This function initializes our array by passing it
 *             a primitive type an allocating the proper amount of space
 *             for an array of that type.
 *
 * parameters: primitiveType type (type of element to be stored in array)
 *
 * returns: returns a pointer to the newly initialized array
 **/
arrayList * initialize(primitiveType type)
{
    arrayList * al = (arrayList*)malloc(sizeof(arrayList));
    al->arraySize = 4;
    al->numElements = 0;
    al->type = type;
    al->elementSize = getSize(type); 
    al -> array = (void*)malloc((getSize(type)) * al ->arraySize);
    return al;
}

/**
 * getSize: This function gives us the number of bytes in a variable
 *          of the primitive type that is passed.
 *
 * parameters: primitiveType type (type of element to calculate bytes of)
 *
 * returns: an integer representing the number of bytes of the primitive type
 **/
int getSize(primitiveType type)
{

    // compare types and use sizeof(type) operator to get value

    if(type == charType)
        return sizeof(char);
    else if(type == shortType)
        return sizeof(short);
    else if(type == intType)
        return sizeof(int);
    else
        return 0;
}

/**
 * addElement: This function adds an element to the end of the array. It will double
 *             the size of the array and copy all of the old elements to the new array.
 *
 * parameters: arrayList * arylstP (represents our array)
 *             void * element (represents element to be added)
 *
 * returns: void
 **/
void addElement(arrayList * arylstP, void * element)
{
   int i;
   if(arylstP -> numElements == arylstP -> arraySize)
   {
       char * newarray = (char *) malloc(2 * arylstP -> numElements * arylstP -> elementSize);
       
       // copy elements to new array
       
       for(i = 0; i < (arylstP -> numElements * arylstP -> elementSize); i++)
       {
           newarray[i] = ((char *)arylstP->array)[i]; 
       }

       // free memory of old array

       free(arylstP -> array);
       arylstP->array = newarray;

       // properly reset the array size

       arylstP->arraySize = arylstP -> arraySize*2;
   }

   // add element to array based proper type

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

   // increment the number of elements in the array

   arylstP -> numElements++;
}

/**
 * removeElement: This function will remove an element from the array at
 *                the specified index that is passed as a parameter.
 *
 * parameters: arrayList * arylstP (represents our array)
 *             int index (index of the array to remove element)
 *
 * returns: void
 **/
void removeElement(arrayList * arylstP, int index)
{
   int i;
   
   // shift all values from index down one
   
   for(i = index; i < arylstP ->numElements - 1; i++)
   {

       // handle each type case

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

   // decrement the number of elements

   arylstP -> numElements--;
}

/**
 * printArray: This function simply prints each element that is stored
 *             in given array.
 *
 * parameters: arrayList * arylstP (represents the array)
 *
 * returns: void
 **/
void printArray(arrayList * arylstP)
{
   int i;
   
   // create temp variables for each primitive type to be anded with given values

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

