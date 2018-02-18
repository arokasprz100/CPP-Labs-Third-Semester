#ifndef Point2DArray_h
#define Point2DArray_h

#include "Point2D.h"


/// Klasa reprezentujaca tablice jednowymiarowa przechowujaca wskazniki do punktow dwuwymiarowych (typ CPoint2D)
/// Obiekt tej klasy przechowuje tablice - zaimplementowana jako tablica wskaznikow do punktow oraz rozmiar tablicy
/// Klasa uzywa operatorow new, delete oraz new[] i delete[] ale pamiec przez nia przydzielona jest w calosci przez nia
/// zarzadzana - w tym zwolniona
class CPoint2DArray
{
public:
	/// Kostruktor obiektu klasy CPoint2DArray
	/// Konstruktor ten przyjmuje wielkosc tablicy
	/// Jesli nie zostanie podany argument. wielkosc zostaje ustawiona na 0
	/// Uzywany jest operator new oraz new []
	/// Punkty sa inicjalizowane swoimi wartosciami domyslnymi
	CPoint2DArray (int newSize = 0);

	/// Konstruktor dzialajacy podobnie do powyzszego, z tym ze tym razem
	/// Wartosci punktow sa ustawiane zgodnie z wartosciami w copiedPoint
	/// Konstruktor jako pierwszy argument przyjmuje punkt wzorcowy
	/// Drugi argument to wielkosc tablicy
	CPoint2DArray (const CPoint2D& copiedPoint, int newSize);


	/// Konstruktor kopiujacy. Kopiuje on tablice punktow dowuwymiarowych
	/// Robi to w taki sposob, ze nowa tablica i punkty w niej sa calkowicie niezalezne
	/// Od puntkow w tablicy copied
	CPoint2DArray (const CPoint2DArray& copied);


	/// Funkcja wypisujaca zawartosc tablicy punktow
	/// Funkcja jest const wiec gwarantuje brak zmian w obiekcie 
	/// Wypisywane sa po kolei wszystkie punkty w tablicy, w jednej linii
	void Print () const;

	/// Funkcja ustawiajaca wartosci punktow przechowywanych w tablicy jako wartosci losowe
	/// Argumenty tej funkcji okreslaja kolejno dolna i gorna granice przedzialu, z jakiego maja byc
	/// losowane liczby
	void FillRand(int lower, int upper);


	/// Operator kopiujacy tablice punktow dwuwymiarowych
	/// Operator tworzy nowe instancje punktow kopiowanych
	/// Czyli wartosci puntkow w tablicy, na rzecz ktorej wywolano operator
	/// Sa niezalezne od tych z tablicy copied po wykonaniu kopiowania
	CPoint2DArray& operator= (const CPoint2DArray& copied);


	/// Przeladowany operator [] - daje on dostep do elementu tablicy pod indeksem index
	/// Uwaga: Funkcja nie sprawdza, czy index miesci sie w tablicy
	/// Zwracana jest referencja na punkt dwuwymiarowy przechowywany pod indeksem index
	CPoint2D& operator [] (int index);

	/// Destruktor obiektu klasy CPoint2DArray
	/// Zwalnia on pamiec przydzielona na poszczegolne punkty w tablicy 
	/// oraz na sama tablice wskaznikow na punkty
	~CPoint2DArray();

private:

	/// Skladowa reprezentujaca tablice wskaznikow na punkty typu CPoint2D
	CPoint2D **arrayOfPoints;

	/// Skladowa reprezentujaca wielkosc przechowywanej tablicy
	int sizeOfArray;

};

#endif