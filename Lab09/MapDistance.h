#ifndef MapDistance_h
#define MapDistance_h

#include <string>

extern std::string global_id;


/// Klasa reprezentujaca dystans miedzy dwoma punktami na mapie
/// Klasa ta przechowuje dystans okreslony za pomoca roznicy skladowych longitude
/// i skladowych latitude dwoch punktow
/// Klasa ma rowniez mozliwosc nadania dystanowi identyfikacji
class MapDistance
{
public:

	/// Konstruktor bezargumentowy, ustawiajacy wartosci dystansu na 0
	/// Reprezentacja id zostaje ustawiona na "None"
	MapDistance();

	/// Konstruktor z argumentami ustawiajacymi wartosci
	MapDistance (double new_lat ,double new_lon, std::string new_id);

	/// Funkcja wypisujaca na standardowe wyjscie zawartosc obiektu
	/// Funkcja nie przyjmuje argumentow
	/// Format wypisywania:
	/// Distance id:  (latitude difference, longitude difference)
	void print() const;

	/// Funkcja zwraca wartosc typu double reprezentujaca latitude
	double get_lat();

	/// Funkcja zwracajaca wartosc typu double reprezentujaca longitude
	double get_lon();


private:
	double lat_distance;
	double lon_distance;
	std::string id_name;
};

#endif