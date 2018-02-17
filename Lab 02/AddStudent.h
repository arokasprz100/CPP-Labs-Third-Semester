#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

///Funkcja dodaje studenta do listy
///Do funkcji nalezy przekazac wskaznik na liczbe studentow aktualnie na liscie
///Funkcja modyfikuje wartosc pod tym wskaznikiem - to znaczy dodaje do niej jeden
///Wartosc ta musi byc zainicjalizowana
///Nalezy do niej przekazac wskazniki na kolejne elementy skladowe listy:
/// - wskaznik na imiona
/// - wskaznik na nazwiska
/// - wskaznik na lata
///Nastepnie nalezy przekazac dane dodawanego studenta:
/// - pierwsze imie
/// - drugie imie
/// - nazwisko
/// - rok studiow
///Funkcja modyfikuje argumenty 2-4, to jest dopisuje do nich studenta
///Jesli lista studentow jest pusta (argument namesList ma wartosc 0), to funkcja alokuje pamiec
///dla poszczegolnych elementow listy za pomoca operatora new []
///Jesli lista juz istnieje, to funkcja, uzywajac new [] i delete [] poszerza liste
///Wszelkie pomocnicze tablice uzyte do tego procesu zostaja zwolnione
///Funkcja alokuje rowniez za pomoca new [] miejsce na imiona i nazwiska w listach
///Funkcja nie daje zadnego mechanizmu zwalniajacego to miejsce - do tego sluzy
///funkcja ClearStudents()
void AddStudent(int *numberOfStudents, char ***namesList, char*** surnamesList, int **yearsList, char const *firstName, char const*  secondName,  char const *surname, int year);

#endif // ADDSTUDENT_H
