#include"Suma.h"
#include<iostream>

float Suma (ciag dane, rozmiarCiagu rozmiar)
{
  std::cout<<"suma: ";
  float suma=0;
  for (int i = 0; i < rozmiar; ++i)
    suma += dane[i];
  return suma;

}

