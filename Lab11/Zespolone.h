#ifndef Zespolone_h
#define Zespolone_h

#include "Wymierne.h"

///Klasa reperezentujaca liczbe zespolona
///Liczba zespolona posiada czesc rzeczywista oraz urojona
///Obie czesci moga byc ulamkami
class CZespolone
{
public:

	/// Konstruktor dwuargumentowy liczby zespolonej.
	/// Pierwszym argumentem powinna byc czesc rzeczywista typu float
	/// Drugim argumentem powinna byc czesc urojona typu float
	CZespolone (float rzeczywista = 0.0, float urojona=0.0):
	    m_rzeczywista(rzeczywista), m_urojona(urojona) {}

	/// Konstruktor jednoargumentowy (konwertujacy), przyjmujacy argument typu
	/// CWymierne. Konstruktor ustawia jako wartosc rzeczywista iloczyn skladnikow
	/// klasy CWymierne. Czesc urojona zostaje ustawiona na 0
	CZespolone (CWymierne liczba);

	/// Funkcja wypisujaca zawartosc obiektu typu CZespolone
	/// Funkcja jest zadeklarowana jako const, wiec gwarantuje
	/// ze nie zmieni zawartosci obiektu
	/// Funkcja nie przyjmuje argumentow i nie zwraca nic
	/// Format wypisywania: (czesc_rzeczywista, czesc_urojona)
	void Print() const;

	/// Funkcja zwracajaca wartosc czesci rzeczywistej przechowywanej przez obiekt
	/// Funcja jest typu const wiec gwarantuje, ze zawartosc obiektu nie zostanie zmieniona
	/// Funkcja nie przyjmuje argumentow, zwraca typ float
	float DajRzeczywista() const;

	/// Funkcja zwracajaca wartosc czesci urojonej przechowywanej przez obiekt
	/// Funcja jest typu const wiec gwarantuje, ze zawartosc obiektu nie zostanie zmieniona
	/// Funkcja nie przyjmuje argumentow, zwraca typ float
	float DajUrojona() const;

private:
	/// Zmienna przechowujaca czesc rzeczywista liczby zespolonej
	float m_rzeczywista;

	/// Zmienna  przechowujaca czesc urojona liczby zespolonej
	float m_urojona;

};


/// Funkcja dodajaca dwie liczby zespolone
/// Zwraca nowa liczbe zespolona (obiekt typu CZespolone)
/// Jako argumenty przyjmuje dodawane liczby
CZespolone Dodaj(const CZespolone& liczba1, const CZespolone& liczba2);




/// Klasa reprezentujaca tablice liczb zespolonych
class CZespoloneTab
{
public:
	/// Konstruktor tworzacy dynamicznie nowa tablice liczb zespolonych
	/// Wielkosc tablicy jest okreslona przez argument wielkosc
	/// Do alokacji zostaje uzyty oprator new []
	CZespoloneTab(int wielkosc);

	/// Przeladowany operator [] zwracajacy referencje do liczby zespolonej
	/// przechowywanaj w tablicy pod indeksem index
	CZespolone& operator[] (int index);


	/// Destruktor zwalniajacy pamiec zajmowana przez tablice liczb zespolonych
	/// Do zwolnienia pamieci uzywa operatora delete []
	~CZespoloneTab();

private:
	/// Wskaznik sluzacy do przechowywania tablicy liczb zespolonych
	CZespolone* m_tablicaZespolonych;

	/// Zmienna przechowujaca ilosc elementow w tablicy liczb zespolonych
	int m_iloscLiczb;

};


#endif
