#include "Zespolone.h"
#include <iostream>


CZespolone::CZespolone (CWymierne liczba)
{
	m_rzeczywista = (float)liczba.DajLicznik() / (float)liczba.DajMianownik();
	m_urojona = 0;

}

void CZespolone::Print() const
{
	std::cout<<"("<<m_rzeczywista<<","<<m_urojona<<")"<<std::endl;

}




float CZespolone::DajRzeczywista() const
{
	return m_rzeczywista;
}


float CZespolone::DajUrojona() const
{
	return m_urojona;
}

CZespolone Dodaj(const CZespolone& liczba1, const CZespolone& liczba2)
{
	return CZespolone(liczba1.DajRzeczywista()+liczba2.DajRzeczywista(), liczba1.DajUrojona() + liczba2.DajUrojona());
}








CZespoloneTab::CZespoloneTab(int wielkosc)
{
	m_tablicaZespolonych = new CZespolone [wielkosc];
	m_iloscLiczb = wielkosc;

}

CZespoloneTab::~CZespoloneTab()
{
	delete [] m_tablicaZespolonych;
	m_iloscLiczb = 0;
}

CZespolone& CZespoloneTab::operator[] (int index)
{
	return m_tablicaZespolonych[index];
}


