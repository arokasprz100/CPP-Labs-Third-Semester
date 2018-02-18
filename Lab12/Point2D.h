#ifndef Point2D_h
#define Point2D_h


/// Klasa reprezentujaca punkt dwuwymiarowy, ktorego wspolrzedne moga byc wartosciami
/// typu double
class CPoint2D
{
public:
	/// Konstruktor przyjmujacy jako argumenty wartosci skladowych x i y
	/// Jesli nie podano, wartosci ustawiane sa na 0.0
	CPoint2D (double newX = 0.0, double newY = 0.0):
		x(newX), y(newY) {}


	/// Prosta funckja zwracajaca wartosc skladowej x punktu 
	double GetX() const{
		return x;
	}

	/// Funkcja zwracajaca wartosc skladowej y punktu
	double GetY() const{
		return y;
	}

	/// Funkcja pozwalajaca ustawic wartosc skladowej x punktu wedlug podanego argumentu
	void SetX(double newX){
		x= newX;
	}

	/// Funkcja pozwalajaca ustawic wartosc skladowej y puntku wedlug podanego argumentu
	void SetY(double newY){
		y = newY;
	}

	/// Przeladowany operator pozwalajacy dodac dwa punkty
	/// Dodawanie po skladowych tzn x do x y do y
	/// Zwracany jest nowy punkt bedacy wynikiem dodawania
	CPoint2D operator+ (const CPoint2D& added);

	/// Przeladowany operator pozwalajacy odjac dwa punkty
	/// Odejmowanie po skladowych tzn x do x y do y
	/// Zwracany jest nowy punkt bedacy wynikiem odejmowania
	CPoint2D operator- (const CPoint2D& rhs);


	/// Funkcja wypisujaca wartosc przechowywanego punktu tzn jego skladowe x i y
	void Print() const;



private:

	/// Skladowa reprezentujaca wspolrzedna x punktu
	double x;

	/// Skladowa reprezentujaca wspolrzedna y punktu
	double y;

};

/// Operator pozwalajacy dodac wartosc typu double do punktu
/// wartosc dodawana jest do x i do y
/// Zwracany jest nowy punkt
CPoint2D operator+ (double value, const CPoint2D& added);

#endif