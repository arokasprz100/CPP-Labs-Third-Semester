#include<iostream>
#include"Suma2.h"
#include"PolozeniePoczatkowe.h"
#include"Czas.h"
#include"Przyspieszenie.h"
#include"Predkosc.h"

#include"assert.h"

int main ()
{
  using namespace std;

#ifndef NODEBUG
  cout<<"This is debug version!\n";
#endif

  assert(5==3);


#ifdef ENGLISH
  cout<<"Good day to you sir!\n";
#endif
  
  cout<<"a = "<<Przyspieszenie()<<"\n";
  cout<<"v = "<<Predkosc()<<"\n";
  cout<<"r_0 = "<<PolozeniePoczatkowe()<<"\n";
  cout<<"t = "<<Czas()<<"\n";

  cout<<"r = a*t^2/2 + v*t + r_0 = "<<Suma2()<<"\n";

  return 0;
}
