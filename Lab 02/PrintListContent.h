#ifndef PRINTLISTCONTENT_H
#define PRINTLISTCONTENT_H

///Plik zawiera 3 wersje przeladowanej funkcji PrintListContent do wypisywania aktualnej listy studentow
///Dane kazdego ze studentow sa wypisywane w nowej linii

///Funkcja wypisuje imiona lub nazwiska studentow
void PrintListContent (int numberOfStudents, char **wordsList);

///Funkcja wypisuje lata studiow studentow
void PrintListContent (int numberOfStudents, int *yearsList);

///Funkcja wypisuje wszystkie dane studentow
void PrintListContent (int numberOfStudents, char** namesList, char **surnamesList, int* yearsList);

#endif // PRINTLISTCONTENT_H
