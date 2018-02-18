#include<iostream>

void PrintStats (const int age, const int knowledge, const int creativity)
{
  std::cout<<"Age: "<<age<<"\tKnowledge: "<<knowledge<<"\tcreatvity: "<<creativity<<"\n";
}


void GetOlder (int& knowledge, int& age, int& creativity)
{
  const int statModifier = 1;

  knowledge += 2*statModifier;
  age += statModifier;
  creativity -= 3*statModifier;
}
