#ifndef GradeBook_h
#define GradeBook_h

#include "Grade.h"


///Klasa reprezentujca dziennik ocen
class GradeBook 
{
public:
	///Konstruktor wywolywany przy tworzeniu obiektu typu GradeBook, gdy nie zostały
	///podane zadne argumenty
	///Inicjhalizuje on wszystkie pola obiektu na 0
	GradeBook();

	///Konstruktor kopiujacy, odpowiedzialny za skopiowanie obietu typu GradeBook
	///Podczas kopiowania tworzone sa nowe instancje ocen przechowywanych w dzienniku
	///Stworzone obiekty sa zatem calkowicie niezalezne od siebie
	///Jako arguement przyjmowana jest referencja na staly obiekt typu GradeBook
	///Funkcja dba o alokacje pamieci
	///Pamiec zostaje potem zwolniona przez destruktor
	GradeBook(const GradeBook& copiedBook);

	///Destruktor obiektu typu GradeBook
	///Zajmuje sie on zwolnieniem calej zaalowowanej pamieci
	~GradeBook();

	///Metoda wstawiajaca ocene do dziennika
	///Przyjmuje wskaznik na staly obiekt typu Grade
	///Nalezy zadbac, by przekazywany obiekt byl zaalokowany dynamicznie !!!
	///Pamiec alokowana zostaje potem zwolniona przez destruktor
	///Funkcja jest typu void
	void insert (const Grade *insertedGrade);

	///Stala metoda wypisujaca oceny w dzienniku
	///Uzywa tego samego formatu co metoda klasy Grade
	///(poniewaz korzysta z tej metody)
	///funkcja jest typu void
	///Funkcja nie przyjmuje zadnych argumentow
	void print() const;

	///Funkcja dodajaca ocene do dziennika
	///Jako argument przyjmuje wartosc typu double reprezentujaca ocene
	///Funkcja alokuje pamiec na nowy obiekt typu Grade
	///Nastepnie dodaje go do tablicy ocen
	void addGrade (double newGrade);

	///Metoda usuwajaca obiekt typu Grade z dziennika 
	///Usuwa obiekt na pozycji okreslonej przez index
	///Z tym ze jako element 0 brany jest index 1
	void remove(int index);


private:
	///pole przechowuje ilosc ocen
	int numberOfGrades; 

	///Tablica ocen
	const Grade ** gradeList;



};

#endif