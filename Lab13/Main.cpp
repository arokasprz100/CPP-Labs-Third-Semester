// Nazwa pliku wykonywalnego: SmartGeo

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy CPoint2D, CPoint2DSmartPtr, oraz CPointAverageFunctor
// reprezentujace odpowiednio:
// 1) punkt na plaszczyznie (x,y);
// 2) inteligentny wskaznik;
// 3) funktor
//
// ad.1 klasa analogiczna jak na wczesniejszych zajeciach, teraz dodatkowo
//      trzeba zdefiniowac dla niej operatory post/pre inkrementacji.
//      Dodatkowo, nalezy przeciazyc operatory new oraz delete, tak aby
//      w przypadku tworzenia/czyszczenia wskaznika wyswietlana byla informacja
//      o tym fakcie na ekran (jak w przykladzie wydruku ponizej)
//      Uwaga: typ size_t zdefiniwany jest w stddef.h
//
// ad.2. klasa będąca opakowaniem dla normalnych wskaźników na obiekt CPoint2D
//       zapewniająca wobec nich dodatkowe, zachowanie:
//       - w destruktorze klasy CPoint2DSmartPtr wywolany jest operator delete,
//       dzieki czemu klasa ta moze sluzyc do bezpiecznego obchodzenia się z pamięcią.
//       Uwaga: nalezy przeciazyc operator dereferencji oraz wyluskania
//
// ad.3. klasa stanowiaca obiekt funkcyjny (funktor), obliczający średnią 
//       arytmetyczną z podanych CPoint2D (srednia arytmetyczna osobno dla x i y)
//       i aktualizujący wynik z każdym kolejnym wywołaniem.
//       Funkcja Reset() to funkcja resetująca stan funktora.
//
//
// Pliku Main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 
//
// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie SmartGeo. Program nalezy kompilowac z flagami -Wall -g.
//
// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)
//
// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.
//
// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL

#include <iostream>
#include <math.h>
#include "Point2D.h"
#include "Point2DSmartPtr.h"
#include "PointAverageFunctor.h"

// Arkadiusz Kasprzak, Dariusz Wardęga
int main() {

  std::cout << "*** POINTS ON THE PLANE ***"<< std::endl;

  CPoint2D point1(1.2, 0.5), point2(0.8, 0.5), point3;

  point1.Print();

  point3 = 0.5 + point1 + point2;

  --point2;
  point2.Print();

  point3++;
  point3.Print();

  CPoint2DSmartPtr s_point = new CPoint2D(0.5, 1.2);

  s_point->Print();

  std::cout << std::endl << "*** AVERAGE POINT ON THE PLANE ***"<< std::endl;

  CPointAverageFunctor AveragePoint;

  AveragePoint(point1);
  AveragePoint(point2);
  AveragePoint(point3);

  AveragePoint.Print();

  AveragePoint.Reset();

  AveragePoint(point1);
  AveragePoint(point2);
  AveragePoint(*s_point);

  AveragePoint.Print();


  
  return 0;
}
/* Wynik dzialania programu

*** POINTS ON THE PLANE ***
Point:: (1.2,0.5)
Point:: (-0.2,-0.5)
Point:: (3.5,2)
CPoint2D:: alokowanie 16 bajtow
Point:: (0.5,1.2)

*** AVEDRAGE POINT ON THE PLANE ***
Average Point:: (1.5,0.666667)
Average Point:: (0.5,0.4)
CPoint2D:: zwalnianie wskaznika 0x236f030

*/
