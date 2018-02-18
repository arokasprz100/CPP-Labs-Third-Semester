#ifndef Wymierne_h
#define Wymierne_h

/// Klasa reprezentujaca liczbe wymierna
/// Liczba wymierna jest to ulamek - ma licznik i mianownik (calkowite)
class CWymierne
{
public:

	/// Konstruktor dwuargumentowy ustawiajacy wartosci liczby wymiernej
	/// Pierwszy argument to licznik drugi mianownik
	CWymierne(int licznik, int mianownik = 1):
	    m_licznik(licznik), m_mianownik(mianownik) {}

	/// Funkcja wypisujaca zawartosc liczby wymiernej
	/// Nie zmienia obiektu na rzecz ktorego zostala wywolana
	/// Format wypisywania:
	/// licznik/mianownik
	/// Jesli mianownik == 1, to:
	/// licznik
	void Print () const;


	/// Funkcja zwracajaca wartosc licznika przechowywana w obiekcie typu
	/// CWymierne. Funkcja jest typu const - gwarantuje brak zmian w obiekcie
	/// Nie przyjmuje argumentow, zwraca inta
	int DajLicznik() const;

	/// Funkcja zwracajaca wartosc mianownika przechowywana w obiekcie typu
	/// CWymierne. Funkcja jest typu const - gwarantuje brak zmian w obiekcie
	/// Nie przyjmuje argumentow, zwraca inta
	int DajMianownik() const;

	/// Operator konwersji liczby wymiernej na typ float
	/// Operator ten zwraca wynik dzielenia licznika przez mianownik
	/// zrzutowanych na float
	/// Operator gwarantuje niezmienianie zawartosci obiektu
	operator float () const;

private:
	/// Zmienna przechowujaca wartosc licznika liczby wymiernej
	int m_licznik;

	/// Zmienna przechowujaca wartosc mianownika liczby wymiernej
	int m_mianownik;

};


/// Funkcja mnozaca dwie liczby wymierne
/// Mnozone liczby sa przekazywane do funkcji jako const referencje
CWymierne Pomnoz (const CWymierne& skladnik1, const CWymierne skladnik2);


#endif
