#ifndef Grade_h
#define Grade_h


///Klasa reperezentujaca ocene studenta
///Kazdemu obiektowi tej klasy przyporzadowanny jest unikalny numer ID
class Grade 
{
public:
	///Konstruktor wywolywany, gdy tworzony jest obiekt typu Grade
	///Jego argumentem jest wartosc oceny, jaka dany obiekt ma przechowywac
	///Konstruktor ustawia numer ID zgodnie z nastepnym dostepnym
	Grade(double newGrade);

	///Metoda wypisujaca zawartosc przechowywana w obiekcie
	///Jest to metoda const (stala) - nie modyfikuje ona zawartosci obiektu
	///Format wypisywania:
	///Grade ID=[id] value=[gradeValue]
	///Funkcja zwraca void 
	///Funkcja nie przyjmuje zadnych argumentow
	void print() const;

	///Metoda zwracajaca numer ID obiektu repezentujacego ocene
	///Zwraca int, zgodnie z typem id
	///Metoda nie przyjmuje zadnych argumentow
	int getID() const;

private:
	///Pole reprezentujace przechowywana wartosc oceny
	double gradeValue;

	///Pole reprezentujace numer ID oceny
	int gradeID;

	///Zmienna statyczna przechowujaca nastepny dostepny numer ID 
	///do przydzielenia obiektowi typu Grade
	static int nextID;
};


#endif