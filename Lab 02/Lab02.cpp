// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac funkcje wykonujace operacje na tablicach
// reprezentujacych liste studentow.

// W tablicy "namesList" przechowywane sa pierwsze i drugie imie
// studenta oddzielone jedna spacja.

// W tablicy "surnamesList" przechowywane sa nazwiska studentow.

// W tablicy "yearsList" przechowywane sa lata na ktorych studiuja
// studenci.

// UWAGA
// Tablice powinny dostosowywac sie do liczby elementow, ktore maja byc w
// nich przechowywane.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

// Pliku Lab02.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab02. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Lab02.cpp) nalezy wgrac
// do UPEL po uprzednim spakowaniu do archiwum: Lab02.tar.gz

#include "Lab02.h"

int main ()
{
  int numberOfStudents = 0;
  char** namesList = NULL;
  char** surnamesList = NULL;
  int* yearsList = NULL;

  const char* firstName = "Spike";
  const char* secondName = "Jozef";
  const char* surname = "Spiegel";
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, firstName, secondName, surname, 3);

  firstName = "Rick";
  secondName = "Albert";
  surname = "Sanchez";
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, firstName, secondName, surname, 7);

  firstName = "Sterling";
  secondName = "Malory";
  surname = "Archer";
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, firstName, secondName, surname, 1);

  std::cout<<"Only names:\n";
  PrintListContent (numberOfStudents, namesList);

  std::cout<<"\nOnly surnames:\n";
  PrintListContent (numberOfStudents, surnamesList);

  std::cout<<"\nOnly years:\n";
  PrintListContent (numberOfStudents, yearsList);

  std::cout<<"\nEverything:\n";
  PrintListContent (numberOfStudents, namesList, surnamesList, yearsList);

  ClearStudents (&numberOfStudents, &namesList, &surnamesList, &yearsList);

  return 0;
}
/* wynik dzialania programu:
Only names:
Spike Jozef
Rick Albert
Sterling Malory

Only surnames:
Spiegel
Sanchez
Archer

Only years:
3
7
1

Everything:
Spiegel, Spike Jozef - year 3
Sanchez, Rick Albert - year 7
Archer, Sterling Malory - year 1
*/
