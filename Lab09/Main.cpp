// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Prosze napisac klase MapDististance reprezentuje odleglosc pomiedzy dwoma
// punktami. Odleglosc wzdloz poludnikow lub rownoleznikow nalezy
// obliczyc po prostu odejmujac od siebie wspolrzedne punktow
// poczatkowego i koncowego.

// Metody set_latitude oraz set_longitude klasy MapPoint ustawiaja 
// opdpowiednio dlugosc i szerokosc geogreficzna punktu na podstawie 
// zadanego argumentu, ktore przyjmuje.

// Metoda set_coordinates klasy MapPoint ustawia dlugosc i szerokosc geogreficzna
// punktu na podstawie argumentow, ktore przyjmuje.

// Metoda print klasy MapPoint wypisuje na ekran, ze jest to punkt i
// podaje jego wspolrzedne w nawiasach okraglych.

// Metoda print klasy MapDististance wypisuje na ekran, informacje o odleglosci
// (przechowaywanej w zmiennych badacych sklaowymi tej klasy)
// miedzy dwoma punktami w nawiasach okraglych oraz ID typu string.

// Metoda farthest klasy MapPoint, zwraca punkt bedacy najdalej punktu na rzecz
// ktorego zostala wywolana metoda. Odleglosc pomiedzy punktami nalezy
// obliczyc jako pierwiastek sumy kwadratow roznic, czyli
// r = sqrt(delta_dlugosc*delta_dlugosc + delta_szerokosc*delta_szerokosc)
// Funkcja obliczajaca pierwiastek nazywa sie: 
// sqrt(double) i znajduje sie w bibliotece "cmath".

// Metoda half_way_to klasy MapPoint powinna tworzyc/zwracac nowy punkt na 
// mapie w polozeniu, ktore jest srednia arytmetyczna z polozen
// podanych punktow czyli x = (x_1 + x_2)/2

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Mapa. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.


#include <iostream>
#include "MapDistance.h"
#include "MapPoint.h"
#include "MapPoint.h"
#include "MapDistance.h"

int main() {
  using std::cout;

  cout<<"========== KRK ==========\n";
  MapPoint krk;
  krk.set_latitude(19.938333);
  krk.set_longitude(50.061389);
  krk.print();

  cout<<"========== NYC ==========\n";
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc;
  nyc.set_coordinates(nyc_latitude, nyc_longitude);
  nyc.print();

  cout<<"========== PORTO & IRKUTSK ==========\n";
  MapPoint porto;
  porto.set_coordinates(41.162142, -8.621953);
  porto.print();
  MapPoint irkutsk;
  irkutsk.set_coordinates(52.283333, 104.283333);
  irkutsk.print();

  cout<<"========== DISTANCE ==========\n";
  MapDistance nyc_porto;
  nyc_porto.print();
  nyc_porto = nyc.distance(porto);
  nyc_porto.print();

  cout<<"========== FARTHEST ==========\n";
  krk.farthest(porto, irkutsk).print();

  cout<<"========== SOMEWHERE ==========\n";
  krk.half_way_to(nyc).print();

  return 0;
}
/** Wynik dzialania programu:

========== KRK ==========
Point: (19.9383, 50.0614)
========== NYC ==========
Point: (40.7127, -74.0059)
========== PORTO & IRKUTSK ==========
Point: (41.1621, -8.62195)
Point: (52.2833, 104.283)
========== DISTANCE ==========
Distance None:  (0, 0)
Distance NY-POR:  (0.449444, 65.3839)
========== FARTHEST ==========
Point: (52.2833, 104.283)
========== SOMEWHERE ==========
Point: (30.3255, -11.9723))

*/
