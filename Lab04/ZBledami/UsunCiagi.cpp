#include"UsunCiagi.h"

void UsunCiagi()
{
  for (int i = 0; i < g_ileCiagow-1; ++i)
     delete [] ga_usunac[i];

  delete [] ga_usunac;
}
