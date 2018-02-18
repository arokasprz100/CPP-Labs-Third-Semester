#include<iostream>

#include"Functions.h"

int main ()
{
  int age; //0
  int knowledge; //32767
  int creativity; //-7088

  age = 21;
  knowledge = 18;
  creativity = 79;

  PrintStats (age, knowledge, creativity);

  GetOlder (knowledge, age, creativity);

  const int maxAge = 30;
  while (age < maxAge) {
    GetOlder (knowledge, age, creativity);
    std::cout<<"Another year passed\n";
  }

  PrintStats (age, knowledge, creativity);
    
  return 0;
}
