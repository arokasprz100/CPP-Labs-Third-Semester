#ifndef Vector2D_h
#define Vector2D_h

#include "Point2D.h"

/// Klasa reprezentujaca wektor dwuwymiarowy
/// Wektor ma punkt w ktorym sie zaczyna i punkt w ktorym sie konczy
/// Klasa korzysta z implementacji CPoint2D punktu dwuwymiarowego
class CVector2D
{
public:

	/// Konstruktor obiektu klasy CVector2D
	/// Konstruktor ten przyjmuje stale referencje na dwa obiekty typu
	/// CPoint2D - jest to odpowiednio poczatek i koniec wektora
	/// Wartosci z tych referencji zostaja skopiowane do pol obiektu CVector2D
	/// Klasa posiada wiec wlasne kopie tych punktow - nie jest zalezna od tych
	/// podanych w argumencie konstruktora
	CVector2D (const CPoint2D& newStart, const CPoint2D& newEnd);

	/// Przeladowany operator mnozenia
	/// Ta implementacja wykonuje iloczyn skalarny dwoch wektorow dwuwymiarowych
	/// Iloczyn zwraca tych double
	/// Po prawej i po lewej stronie operatora powinny znajdowac sie obiekty typu CVector2D
	/// Dlatego tez jako argument dla tej funkcji przekazywana jest stala referencja 
	/// do obiektu znajdujacego sie po prawej stronie operatora
	double operator*(const CVector2D& rhs);

private:

	/// Punkt dwuwymiarowy reprezentujacy poczatek wektora - implementacja za pomoca klasy CPoint2D
	CPoint2D start; 

	/// Punkt dwuwymiarowy reprezentujacy koniec wektora - implementacja za pomoca klasy CPoint2D
	CPoint2D end;



};

#endif

