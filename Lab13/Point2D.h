#ifndef Point2D_h
#define Point2D_h

#include <stddef.h>

///Klasa reprezentujaca punkt na plaszczyznie
class CPoint2D
{
public:
	/// Konstruktor, przyjmujacy wartosci wspolrzednych, w domniemaniu przyjmujacy punkty (0,0)
	/// umozliwiajacy konwersje z liczb zmiennoprzecinkowych
	CPoint2D (double newX = 0.0, double newY = 0.0) :
		m_x(newX), m_y(newY) {}

	/// Funkcje zwracajace wspolrzedne
	double GetX() const  {return m_x;}
	double GetY() const  {return m_y;}

	///Metoda wypisujaca na ekran zawartosc obiektu wedlug ustalonego szablonu
	void Print() const;

	///Przeladowany operator pre-dekrementacji, dzialajacy na obie wspolrzedne
	CPoint2D& operator--();

	///Przeladowany operator post-inkrementacji, dzialajacy na obie wspolrzedne
	CPoint2D& operator++(int);

	///Przeladowany operator new, alokujacy pamiec i informujacy o tymn uzytkownika
	static void* operator new(size_t size);

	///Przeladowany operator delete, dealokujacy pamiec i informujacy o tymn uzytkownika
	static void operator delete (void* ptr);



private:
	double m_x;
	double m_y;

};

///Globalny operator+, pozwalajacy sumowac obiekty typu CPoint2D
CPoint2D operator+(const CPoint2D& lhs, const CPoint2D& rhs);

#endif