#include"Main.h"

#include<iostream>

#define ARRAY_SIZE 10

int main ()
{
  int** array;
  array=new int* [ARRAY_SIZE];
  int value = 1000;
  for (int i = 0; i < ARRAY_SIZE; ++i)
    array[i] = new int (value++);

  PrintArray(array, ARRAY_SIZE);
  
  for (int i=0; i<ARRAY_SIZE; ++i)
  	delete  array[i];

  delete [] array;

  return 0;
}
