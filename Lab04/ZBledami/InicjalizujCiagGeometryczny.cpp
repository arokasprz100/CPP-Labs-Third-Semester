#include"InicjalizujCiagGeometryczny.h"

int g_ileCiagow=1;
ciag* ga_usunac=0;

const ciag InicjalizujCiagGeometryczny (rozmiarCiagu rozmiar, float skok)
{
  ciag wynik = new typCiagu[rozmiar];
  int i = 0;
  wynik[i] = 1;
  i = i + 1;
  do {
    wynik[i] = wynik[i-1]*skok;
    i = i + 1;
  } while (i < rozmiar);

  ciag* stare = ga_usunac;
  ga_usunac = new ciag[g_ileCiagow];

  for (int i = 0; i < g_ileCiagow - 1; ++i)
    ga_usunac[i] = stare[i];
    
  ga_usunac[g_ileCiagow-1] = wynik;
  delete [] stare; 

  g_ileCiagow++;
  
  return ga_usunac[g_ileCiagow-2];
}
