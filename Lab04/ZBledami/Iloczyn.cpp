#include"Iloczyn.h"
#include<iostream>

float Iloczyn (ciag dane, rozmiarCiagu rozmiar)
{
  std::cout<<"iloczyn: ";
  float iloczyn = 1;
  for (int i = 0; i < rozmiar; ++i)
    iloczyn *= dane[i];

  return iloczyn;
}
