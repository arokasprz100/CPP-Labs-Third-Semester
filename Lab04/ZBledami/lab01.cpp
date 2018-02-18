// Prosze poprawic kod we wszystkich plikach oprocz tego, tak aby
// program kompilowal sie, wykonywal, a wynik jego dzialania byl taki
// sam jak podany na końcu tego pliku.

// Pliku lab01.cpp, nie wolno modyfikowac.

// Przy rozwiazaniu zadania mozna korzystac ze wszystkich dostepnych
// narzedzi sluzacych do debugowania np. gdb, valgrind. Wolno rowniez
// korzystac z internetu.

// Prosze upewnic sie, ze nie ma zadnych problemow z pamiecia.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Prosze dopisac rowniez dokumentacje.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab01.

// Makefile powinien zawierac rowniez etykiete "clean", ktora usuwa pliki
// obiektowe i plik wykonywalny.

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wgrac na UPEL.

#include "lab01.h"

int main ()
{
  const rozmiarCiagu rozmiar = 8;
  const float iloraz1 = 2;
  
  // pierwszy element ciagu to 1
  const ciag geometryczny1 = InicjalizujCiagGeometryczny (rozmiar, iloraz1);
  Wypisz(geometryczny1, rozmiar);
  const float iloraz2 = 3.;
  const ciag geometryczny2 = InicjalizujCiagGeometryczny (rozmiar, iloraz2);
  Wypisz(geometryczny2, rozmiar);
  const ciag geometryczny3 = InicjalizujCiagGeometryczny (23, 1.1);
  Wypisz(geometryczny3, 23);

  Suma(geometryczny1, rozmiar);
  
  operacja przeksztalc [] = {Suma, Iloczyn, Max, Min};
  const int ileOperacji = sizeof(przeksztalc)/sizeof(operacja);
  for (int i = 0; i < ileOperacji; ++i)
    WykonajIWypisz (przeksztalc[i], geometryczny1, rozmiar);

  UsunCiagi();
}
/* wynik dzialania programu:
(1, 2, 4, 8, 16, 32, 64, 128)
(1, 3, 9, 27, 81, 243, 729, 2187)
(1, 1.1, 1.21, 1.331, 1.4641, 1.61051, 1.77156, 1.94872, 2.14359, 2.35795, 2.59374, 2.85312, 3.13843, 3.45227, 3.7975, 4.17725, 4.59497, 5.05447, 5.55992, 6.11591, 6.7275, 7.40025, 8.14028)
suma: suma: 255
iloczyn: 2.68435e+08
maksimum: 128
minimum: 1
*/
