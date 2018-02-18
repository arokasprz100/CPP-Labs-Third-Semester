#include"Typy.h"
#include<iostream>

using namespace std;

void Wypisz(ciag dane, rozmiarCiagu ile)
{
  cout<<"("<<dane[0];
  for (int i = 1; i < ile; ++i)
    cout<<", "<<dane[i];
  cout<<")\n";
}
