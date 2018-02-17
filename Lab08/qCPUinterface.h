#ifndef QCPUINTERFACE_H
#define QCPUINTERFACE_H

#include <string.h>

#include "qCPUcore.h"
#include "qGlobals.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>	/* time */



///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp);

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method);

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp);

///////////////////////////////////////////////////////////////////////////
///Funckcja przypsiujaca nowa wartosc dla zmiennej NExp zerowego qBitu 
///Nowa wartosc jest losowa z przedzialu 1 do 1000
///Funkcja uzywa funkcji rand() zainicjalizowanej przez srand(time(NULL))
///Funkcja nie zwraca nic (void)
void GenerateNRandExp(TqCPU **m_Cpu);


///////////////////////////////////////////////////////////////////////////
///Funkcja wypelniajaca tablice odpowednimi wartosciami pobieranymi 
///z globalnej tablicy MACHINE
///W przekazanej jako argument tablicy znajdzie sie zawartosc tablicy MACHINE
///Jako argument przyjmuje tablice do wypelnienia
///Funkcja nic nie zwraca (void)
void GetPointers( TqCPU** tab);

///////////////////////////////////////////////////////////////////////////
///Funkcja drukujaca nazwy wszystkich CPU zamieszczonych
///W przekazywanej jako argument tablicy
///Uzywa std::cout i std::endl
///Format wypisywania:
///nr_0 CPU_name
///nr_1 CPU_name
///Funckja zwraca zawsze wartosc 1
int PrintNames (TqCPU *m_MACHINE[]);

///////////////////////////////////////////////////////////////////////////
///Funkcja zamieniajaca miejscami dwa wskazniki
///Moga to byc fragmenty tablicy
///Funkcja przyjmuje dwa TqCPU
///Funkcja nic nie zwraca
void SwapCPU(TqCPU* &CPU1, TqCPU* &CPU2);

///////////////////////////////////////////////////////////////////////////
///drukowanie na ekran wartosci Name obiektu TqCPU
///Funkcja drukuje na ekran wartosc Name obiektu TqCPU
///Funkcja przyjmuje wskaznik na wypisywany obiekt TqCPU
///Funkcja jest typu void - nie zwraca nic
void PrintCPUName (TqCPU* CPU);

#endif



