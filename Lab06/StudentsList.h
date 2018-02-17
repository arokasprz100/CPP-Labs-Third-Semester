#ifndef StudentsList_h
#define StudentsList_h

///Funkcja dodajaca studenta do listy
///Przyjmuje wskazniki na juz utworzone listy
///wskaznik nailosc studentow
///oraz parametry nowego studenta
///Uzywa malloc i realloc
///Po tej funkcji trzeba uzyc ClearStudents()
void AddStudent(int *numberOfStudents, char ***namesList, char***surnamesList, int **yearsList,
	const char * firstname, const char *secondname, const char *surname, int year);

///Funkcja wypisuje liste imion lub nazwisk studentow
///W tym przypadku wypisuje imiona lub nazwiska zaleznie od 
///przekazanego parametru
///Format: kazdy student w osobnej linii
///Pierwszy argument to ilosc studentow na liscie
///drugi to wypisywana lista
void PrintListContent (int numberOfStudents, char ** wordsList);

///Funkcja wypisuje liste lat studentow
///kazdy student w osobnej linii
///Pierwszy argument to ilosc studentow na liscie
///Drugi to lista lat (tablica intow alokowana dynamicznie)
void  PrintListContent (int numberOfStudents, int *yearsList);

///Funkcja wypisuje wszystkie dane z list studentow
///Format: kazdy student w osobnej linii
///Pierwszy argument to ilosc studentow
///Pozostale argumenty to poszczegolne listy
void PrintListContent (int numberOfStudents, char **namesList, char **surnamesList, int *yearsList);

///Funkcja usuwa wskazanego przez ID studenta z listy
///Przyjmuje wskazniki na liste studentow oraz ilosc studentow
///Funkcja uzywa free()
void DeleteStudent(int *numberOfStudents, char*** namesList, char***surnamesList, int **yearsList, int studentToDeleteID);

///Funkcja zmienia imiona jedenego ze studentow
///Jako argumenty przyjmuje wskaznik na liste imion
///Przyjmuje rowniez nowe pierwsze imie, oraz drugie imie
///Ostatnim argumentem jest ID studenta - czyli poprostu jego
///numer na lisce
void RenameStudent(char ***namesList, const char *firstname, const char * secondname, int studentToRenameID);

///Funkcja czysci liste studentow
///Uzywa w tym celu free()
///Funkcja ta musi byc wywolana na koniec programu 
///operujacego na liscie studentow, aby zapobiec
///wyciekowi pamieci
void ClearStudents (int *numberOfStudents, char***namesList, char***surnamesList, int**yearsList);

#endif 