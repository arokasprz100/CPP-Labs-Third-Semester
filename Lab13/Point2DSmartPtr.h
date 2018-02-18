#ifndef Point2DSmartPtr_h
#define Point2DSmartPtr_h

#include "Point2D.h"

/// Klasa reprezentujaca inteligentny wskaznik na obiekt klasy CPoint2D
/// ktorego idea jest zapewnienie bezpiecznego zarzadzania pamiecia
class CPoint2DSmartPtr
{
public:
	/// Konstruktor przyjmujacy wskaznik na obiekt typu CPoint2D, 
	/// na ktory pozniej bedzie wskazywal nasz obiekt
	CPoint2DSmartPtr (CPoint2D* point);
	//Destruktor dbajacy o zwolnienie pamieci
	~CPoint2DSmartPtr();

	/// Przeladowany operator wyluskania, pozwalajacy odwolywac sie 
	/// bezposrednio do przechowywanego obiektu
	CPoint2D* operator-> ();

	/// Przeladowany operator dereferencji, pozwalajacy odwolac sie
	/// bezposrednio do wartosci przechowywanego obiektu
	CPoint2D& operator* ();

private:
	CPoint2D* ptrToPoint;


};

#endif