#ifndef CLEARSTUDENTS_H
#define CLEARSTUDENTS_H

///Funkcja czysci liste studentow, ktora zostala wczesniej stworzona przez uzytkownika
///Funkcja powinna zostac wywolana na koncu dzialania programu
///Uzywa operatora delete [] najpierw do zwolnienia miejsca zajmowaniego przez imiona i nazwiska
///a nastepnie przez reszta struktury list
///Funkcja przyjmuje na wejscie ilosc studentow oraz poszczeglne skladowe listy
///Zwolnione wskazniki ustawiane sa na 0
void ClearStudents (int *numberOfStudents, char ***namesList, char ***surnamesList, int **yearsList);

#endif // CLEARSTUDENTS_H
