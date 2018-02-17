// Nazwa pliku wykonywalnego: qCPU

// Prosze dopisac kod, tak aby program sie wykonywal,
// a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku. Opis funkcjonalny brakujacego kodu jest podany pseudokodem;

// !!! UWAGA !!!
// Przy wykonaniu tego zadania nie wolno korzystac z
// zadnych funkcji i obiektow zawartych w bibliotece standardowej
// oprocz cout, endl, printf, malloc, free.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia, zwlaszcza na
// zwolnienie pamieci na koniec programu.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie qCPU. Program nalezy kompilowac z flagami -Wall -g.

// do kompilacji niezbedne jest uzycie flagi -std=c++11

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// na UPEL, do konca biezacych zajec;

#include "Main.h"

// default number of experiments for probability distribution evaluation
// and to evaluate the qCPU state
extern int NEXPERIMENTS;


// Main function
int main ()
{
  std::cout<< ">>> (pseudo)Quantum Computing <<< " << std::endl;

  int NqBits = 16;	// number of qBits

  TqCPU MyQuantumCPU;
  qCPU_alloc("qComputer", NqBits, &MyQuantumCPU);

  NEXPERIMENTS = 1;
  Evaluate_qCPU_State(&MyQuantumCPU, NEXPERIMENTS);
  Print_qCPU_State(MyQuantumCPU);

  NEXPERIMENTS = 100;
  Evaluate_qCPU_State(&MyQuantumCPU, NEXPERIMENTS);
  Print_qCPU_State(MyQuantumCPU);

  qCPU_delete(&MyQuantumCPU);

  return 0;
}
/* wynik dzialania programu:
------------------------------------------------------------
>>> (pseudo)Quantum Computing <<<
>>> qCPU initialized with 16 qBits
qComputer CPU word (1 experiments) : 		down down down down down down down down up down down down down down down down
qComputer CPU word (100 experiments) : 		down down down down down down up up up up down down down down down down
------------------------------------------------------------

Uwaga: sekwencje: up down... sa losowe;

*/
