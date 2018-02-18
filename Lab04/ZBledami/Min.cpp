#include"Min.h"
#include"Typy.h"
#include<iostream>

using namespace std;

float Min (ciag dane, rozmiarCiagu rozmiar)
{
  cout<<"minimum: ";
  float min = dane[0];
  for (int i = 1; i < rozmiar; ++i)
    if (min > dane[i])
      min = dane[i];
  
  return min;
}
