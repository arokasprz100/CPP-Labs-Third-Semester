// Nazwa pliku wykonywalnego: Geometria

// Uwaga ogolna:
// Przeciążenia przewidziane w zadaniu nie są tylko sztuką dla samej sztuki.
// Zaproponowane obiekty są np niezbędne w programowaniu grafiki przy użyciu DirectX.
// Tutaj przy okazji ilustrują tę ciekawą technikę programistyczną, jaką jest przeciążanie operatorów.

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy CPoint2D, CPoint2DArray i CVector2D, reprezentujace odpowiednio
// punkt na plaszczyznie (x,y), tablice tyh punktow oraz wektor, z odpowiednią funkcjonalnością
// którą należy wywnioskować z poniższezgo kodu (w niektórych przypadkach znajduje sie
// wyjaśniający komentarz)
// Uwaga: Klase CPoint2DArray proszę zaimplementować tak, aby zawierała tablicę wskaźników
//        na obiekty CPoint2D

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Geometria. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

#include "Point2D.h"
#include "Point2DArray.h"
#include "Vector2D.h"

int main() {

  srand(time(NULL));

  std::cout << "*** POINTS ON THE PLANE ***"<< std::endl;

  CPoint2D point1(1.2, 0.5), point2(0.8, 0.5), point3, point4;
 
  point3 = 0.5 + point1 + point2;
  point4 = 0.7 + point1 - point2;

  point3.Print();
  point4.Print();
  
  std::cout << "*** ARRAY OF THE POINTS ***"<< std::endl;
  CPoint2DArray pointA1(5), pointA2(5), pointA3; // argument: wielkosc wektora
  CPoint2DArray pointA4(point3,5);               // argument: obiekt inicjalizacjalizujacy wszystkie wartosci, wielkosc wektora
  CPoint2DArray pointA5 = pointA4;

  pointA4.Print();
  pointA4.FillRand(0,100);                      // Przypisanie wartosci losowych z podanego przedzialu
  pointA4.Print();
  pointA5.Print();

  pointA1.FillRand(0,10);
  pointA2.FillRand(11,100);
  
  pointA1 = pointA1;

  pointA1.Print();
  pointA2.Print();

  pointA3 = pointA2 = pointA1;
  pointA2.Print();
  pointA3.Print();

  CVector2D vectorV1(pointA1[0], point3);
  CVector2D vectorV2(pointA1[1], point4);

  double ScalarProduct = vectorV1*vectorV2;    // mnozenie wektorow (iloczyn skalarny)

  std::cout<<"Scalar product : " << ScalarProduct << std::endl;

  return 0;

}
/* Wynik dzialania programu (uwaga, w drugiej czesci zadania liczby sa losowe,
   nie bedzie identycznego wyniku - prosze zwrocic uwage na powtarzalnosc outputu):
   Komentarze // <-- nie sa wynikiem drukowania, maja tylko pomóc w zrozumieniu przykładu

*** POINTS ON THE PLANE ***
Point:: (2.5,1.5)
Point:: (1.1,0.7)
*** ARRAY OF THE POINTS ***
Point array:: (2.5,1), (2.5,1), (2.5,1), (2.5,1), (2.5,1)   // <-- pointA4
Point array:: (40,19), (97,78), (14,94), (22,5), (7,53)     // <-- pointA4 po wywyolaniu FillRand()
Point array:: (2.5,1), (2.5,1), (2.5,1), (2.5,1), (2.5,1)   // <-- pointA5
Point array:: (7,1), (0,1), (2,7), (0,4), (2,1)             // <-- pointA1 po wywolaniu FillRand(0,10)
Point array:: (61,53), (79,22), (87,35), (84,12), (60,65)   // <-- pointA2 po wywolaniu FillRand(11,100)
Point array:: (7,1), (0,1), (2,7), (0,4), (2,1)             // <-- pointA2 po przypisaniu pointA2 = pointA1;
Point array:: (7,1), (0,1), (2,7), (0,4), (2,1)             // <-- pointA3 po przypisaniu pointA3 = pointA1;
Scalar product : 5.1

*/
