#ifndef MapPoint_h
#define MapPoint_h

#include "MapDistance.h"


///Klasa przechowujaca punkt na mapie
///Punkt na mapie opisany jest przez jego dlugosc i szerokosc goeograficzna
class MapPoint 
{
public:
	/// \brief Funkcja pozwalajaca na ustawienie latitude punktu na mapie
	/// \param[in] arg1 Funckja przyjmuje jako argument wartosc typu double oznaczjaca
	///					nowa wartosc latitude do nadania
	///	\param[out] Funkcja nie zwraca nic - jest typu void
	void set_latitude(double new_latitude);

	/// \brief Funkcja pozwalajaca na ustawienie longitude punktu na mapie
	/// \param[in] arg1 Funckja przyjmuje jako argument wartosc typu double oznaczjaca
	///					nowa wartosc longitude do nadania
	///	\param[out] Funkcja nie zwraca nic - jest typu void
	void set_longitude(double new_longitude);

	/// \brief Funkcja zwracajaca longitude danego punktu na mapie
	/// \param[out] Funkcja zwraca wartosc typu double reprezentujaca longitude punktu na mapie
	/// Funkcja nie przyjmuje zadych argumentow, jedyne co robi to zwraca wartosc
	double get_longitude ();


	/// \brief Funkcja zwracajaca latitude danego punktu na mapie
	/// \param[out] Funkcja zwraca wartosc typu double reprezentujaca latitude punktu na mapie
	/// Funkcja nie przyjmuje zadych argumentow, jedyne co robi to zwraca wartosc
	double get_latitude();  


	/// Funkcja wypisuje na standardowe wyjscie wspolrzedne przechowywanego przez obiekt punktu
	/// Funkcja zapewnia, ze obiekt nie zostanie zmodyfikowany (const)
	/// Funkcja nie przyjmuje zadnych argumentow
	/// Funkcja nic nie zwraca (jest typu void)
	/// Format wypisywany:
	/// Point: (latitude, longitude)
	void print() const;

	/// Funkcja pozwalajaca ustalic oba koordynaty punktu na mapie
	/// Ustawiane koordynaty specyfikuje sie poprzez argumenty funkcji
	/// Funkcja nie zwraca nic - typ void
	void set_coordinates (double new_lat, double new_long);

	/// Funkcja zwracajaca obiekt typu MapDistance reprezentujacy dystans
	/// obiektu, na rzecz ktorego zostala wywolana, do obiektu zadanego 
	/// argumentem
	/// Funkcja jest zaprojektowana tak, aby dystanse byly zawsze dodatnie
	/// Funkcja gwarantuje, ze jej argument nie bedzie modyfiowany
	MapDistance distance(const MapPoint& otherPoint);


	/// Funkcja zwracajaca referencje na punkt, ktory jest dalej od obiektu, na rzecz 
	/// ktorego funkcja zostal wywolana
	/// Punkty, ktore beda sprawdzane sa przekazywane jako referencje w argumentach
	const MapPoint& farthest(const MapPoint& one, const MapPoint& other);

	/// Funkcja zwraca punkt znajdujacy sie w polowie drogi miedzy punktem, na rzecz ktorego
	/// zostala wywolana, a punktem podanym w argumencie
	/// Funkcja zwraca obiekt typu MapPoint
	MapPoint half_way_to (const MapPoint& onePoint);

private:
	/// Jedna ze wspolrzednych punktu
	double latitude;

	/// Jedna ze wspolrzednych punktu
	double longitude;

};


#endif