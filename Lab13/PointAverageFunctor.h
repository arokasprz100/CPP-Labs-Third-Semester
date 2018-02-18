#ifndef PointAverageFunctor_h
#define PointAverageFunctor_h

#include "Point2D.h"

/// Klasa reprezentujaca Funktor, liczacy srednia arytmetyczna przekazanych punktow
class CPointAverageFunctor
{
public:
	/// Konstruktor przyjmujacy wartosci startowe dla srednich, domyslnie inicjalizowane wartoscia 0.0
	CPointAverageFunctor (double offsetX = 0.0, double offsetY = 0.0) :
		aver_x(offsetX), aver_y(offsetY), counter(0) {}
	
	/// Przeladowany operator(), przyjmujacy jako argument stala referencje do obiektu klasy CPoint2D
	///Dzialanie polega na dodaniu do obecnej sredniej wartosci przekazanego punktu
	CPointAverageFunctor& operator () (const CPoint2D& added);

	///Metoda wypisujaca na ekran zawartosc obiektu wedlug ustalonego szablonu
	void Print() const;

	/// Metoda zerujaca wszystkie pola obiektu na rzecz ktorego zostala wywolana
	void Reset();



private:
	double aver_x;
	double aver_y;

	int counter;

};

#endif